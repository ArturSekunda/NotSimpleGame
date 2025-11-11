#include "playerEquipmentWidget.h"


void playerEquipmentWidget::initializeIcons(const tgui::Panel::Ptr& parentPanel) {
    weaponIcon = tgui::Picture::create("../src/core/assets/equipment/empty_slot.png");
    HelmetIcon = tgui::Picture::create("../src/core/assets/equipment/empty_slot.png");
    ChestplateIcon = tgui::Picture::create("../src/core/assets/equipment/empty_slot.png");
    LeggingsIcon = tgui::Picture::create("../src/core/assets/equipment/empty_slot.png");
    BootsIcon = tgui::Picture::create("../src/core/assets/equipment/empty_slot.png");

    if (!weaponIcon || !HelmetIcon || !ChestplateIcon || !LeggingsIcon || !BootsIcon) {
        throw std::runtime_error("Failed to create equipment icons");
    }

    EquipmentIcons = {
        weaponIcon,
        HelmetIcon,
        ChestplateIcon,
        LeggingsIcon,
        BootsIcon
    };


    int i = 0;
    for (auto& newclmap: EquipmentIcons) {
        newclmap->setSize("20%","20%");
        newclmap->onClick([i](){
            std::cout << i << std::endl;
        });
        i++;
    }

    weaponIcon->setPosition("5%", "1%");
    HelmetIcon->setPosition("75%", "1%");
    ChestplateIcon->setPosition("75%", "22%");
    LeggingsIcon->setPosition("75%", "43%");
    BootsIcon->setPosition("75%", "64%");

    for (auto& newclmap: EquipmentIcons) {

        parentPanel->add(newclmap);
    }
}

void playerEquipmentWidget::UpdateEquipment(const std::shared_ptr<weapon> &weap, const std::shared_ptr<armor> &helmet,
    const std::shared_ptr<armor> &chestplate, const std::shared_ptr<armor> &leggings,
    const std::shared_ptr<armor> &boots) {



}
