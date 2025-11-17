#ifndef NOTSIMPLEGAME_PLAYEREQUIPMENTWIDGET_H
#define NOTSIMPLEGAME_PLAYEREQUIPMENTWIDGET_H
#include "TGUI/Widgets/Panel.hpp"
#include "TGUI/Widgets/Picture.hpp"


class weapon;
class armor;

class playerEquipmentWidget {
    // Equipment Icons
    tgui::Picture::Ptr weaponIcon = nullptr;
    tgui::Picture::Ptr HelmetIcon = nullptr;
    tgui::Picture::Ptr ChestplateIcon = nullptr;
    tgui::Picture::Ptr LeggingsIcon = nullptr;
    tgui::Picture::Ptr BootsIcon = nullptr;

    std::vector <tgui::Picture::Ptr> EquipmentIcons;

public:
    void initializeIcons(const tgui::Panel::Ptr& parentPanel);

    void UpdateEquipment(const std::shared_ptr<weapon>& weap,
                         const std::shared_ptr<armor>& helmet,
                         const std::shared_ptr<armor>& chestplate,
                         const std::shared_ptr<armor>& leggings,
                         const std::shared_ptr<armor>& boots);

};


#endif //NOTSIMPLEGAME_PLAYEREQUIPMENTWIDGET_H
