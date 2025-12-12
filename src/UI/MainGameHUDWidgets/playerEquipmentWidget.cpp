#include "playerEquipmentWidget.h"

#include "entities/baseEntity.h"
#include "inventory/playerEquipment.h"


void playerEquipmentWidget::initializeIcons(const tgui::Panel::Ptr& parentPanel) {
    for (int i = 0; i < 5; ++i) {
        equipmentUISlots[i].Initialize(parentPanel, i);
        equipmentUISlots[i].icon->setSize("20%", "20%");
    }
    equipmentUISlots[0].icon->setPosition("5%", "1%");
    equipmentUISlots[1].icon->setPosition("75%", "1%");
    equipmentUISlots[2].icon->setPosition("75%", "22%");
    equipmentUISlots[3].icon->setPosition("75%", "43%");
    equipmentUISlots[4].icon->setPosition("75%", "64%");

}

void playerEquipmentWidget::UIEquipment(playerEquipment &E_Player,baseEntity& entity, MouseContainer &mouse_container) {
        for (auto& UISlot: equipmentUISlots) {
            UISlot.icon->onClick([&mouse_container, &UISlot, &entity, &E_Player]() {

                auto index = UISlot.slotIndex;
                if (mouse_container.itemPointer == nullptr && E_Player.getItemFromSlot(index) != nullptr) {
                    mouse_container.holdItem(E_Player.getItemFromSlot(index));
                    E_Player.RemoveItemStats(index,entity.getStats(), entity);
                    E_Player.RemoveItem(index);
                    return;
                }
                if (mouse_container.itemPointer != nullptr && E_Player.getItemFromSlot(index) == nullptr) {
                    if (E_Player.EquipItem(mouse_container.itemPointer,entity, index)) {

                        mouse_container.Clear();
                    }else {
                        std::cout << "Failed to equip item to slot " << index << std::endl;
                    }
                    return;
                }
            });
        }
}

void playerEquipmentWidget::UpdateUISlots(std::map<ArmorType, std::shared_ptr<armor>>& armorSlots,const std::shared_ptr<weapon>& weap) {
    for (auto& newclmap: equipmentUISlots) {
        newclmap.Update(armorSlots, weap);
    }
}
