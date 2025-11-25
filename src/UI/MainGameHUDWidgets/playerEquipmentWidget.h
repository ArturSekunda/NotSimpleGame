#ifndef NOTSIMPLEGAME_PLAYEREQUIPMENTWIDGET_H
#define NOTSIMPLEGAME_PLAYEREQUIPMENTWIDGET_H
#include "entities/baseEntity.h"
#include "items/armor.h"
#include "items/weapon.h"
#include "TGUI/Widgets/Panel.hpp"
#include "TGUI/Widgets/Picture.hpp"
#include "UI/helpers/mouseContainer.h"


class playerEquipment;
class weapon;
class armor;

struct UIEquipmentSlot {
    tgui::Picture::Ptr icon;
    int slotIndex;
    std::string cachedTexturePath;

    void Update(const std::map<ArmorType, std::shared_ptr<armor>>& armorSlots,
        const std::shared_ptr<weapon>& weaponSlot) {
        std::string newPath;
            if (slotIndex == 0) {
                newPath = weaponSlot ? weaponSlot->getTexturePath() : "../src/core/assets/equipment/empty_slot.png";
            } else {
                ArmorType type;
                switch (slotIndex) {
                    case 1:
                        type = ArmorType::HELMET;
                        break;
                    case 2:
                        type = ArmorType::CHESTPLATE;
                        break;
                    case 3:
                        type = ArmorType::LEGGINGS;
                        break;
                    case 4:
                        type = ArmorType::BOOTS;
                        break;
                    default:
                        newPath = "../src/core/assets/equipment/empty_slot.png";
                        break;
                }
                auto it = armorSlots.find(type);
                if (it != armorSlots.end() && it->second) {
                    newPath = it->second->getTexturePath();
                } else {
                    newPath = "../src/core/assets/equipment/empty_slot.png";
                }
            }

        if (cachedTexturePath != newPath) {
            cachedTexturePath = newPath;
            icon->getRenderer()->setTexture(tgui::Texture(newPath));
        }
    }
    void Initialize(const tgui::Panel::Ptr& parentPanel, int index) {
        slotIndex = index;
        icon = tgui::Picture::create("../src/core/assets/equipment/empty_slot.png");
        if (!icon) {
            throw std::runtime_error("Failed to create inventory slot icon");
        }

        parentPanel->add(icon);
        cachedTexturePath = "../src/core/assets/equipment/empty_slot.png";
    }
};

class playerEquipmentWidget {

    std::array<UIEquipmentSlot,5> equipmentUISlots;

public:
    void initializeIcons(const tgui::Panel::Ptr& parentPanel);

    void UIEquipment(playerEquipment &E_Player, baseEntity &entity, MouseContainer &mouse_container);

    void UpdateUISlots(std::map<ArmorType, std::shared_ptr<armor>> &armorSlots, const std::shared_ptr<weapon> &weap);

};


#endif //NOTSIMPLEGAME_PLAYEREQUIPMENTWIDGET_H
