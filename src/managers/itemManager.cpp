#include "itemManager.h"

#include "entities/baseEntity.h"
#include "entities/enemies/basicEnemy.h"
#include "inventory/baseEquipment.h"
#include "inventory/enemyEquipment.h"
#include "items/armor.h"
#include "items/weapon.h"

void itemManager::CreateWeaponForEnemy(basicEnemy& enemy) {
    std::shared_ptr<weapon> w = std::make_shared<weapon>(weapon::CreateNewWeapon(enemy.getLevel(), WeaponID));
    if (w) {
        AddItemToDatabase(w);
        enemy.getEquipment().EquipItem(w, enemy, 0);
        WeaponID++;
    }else {
        std::cout << "Failed to create weapon for enemy.\n";
    }
}

void itemManager::CreateArmorForEnemy(basicEnemy &enemy) {
    std::shared_ptr<armor> Helmet = std::make_shared<armor>(armor::CreateNewArmor(ArmorType::HELMET,enemy.getLevel(), ArmorID));
    ArmorID++;
    std::shared_ptr<armor> Chestplate = std::make_shared<armor>(armor::CreateNewArmor(ArmorType::CHESTPLATE,enemy.getLevel(), ArmorID));
    ArmorID++;
    std::shared_ptr<armor> Leggings = std::make_shared<armor>(armor::CreateNewArmor(ArmorType::LEGGINGS,enemy.getLevel(), ArmorID));
    ArmorID++;
    std::shared_ptr<armor> Boots = std::make_shared<armor>(armor::CreateNewArmor(ArmorType::BOOTS,enemy.getLevel(), ArmorID));
    ArmorID++;

    AddItemToDatabase(Helmet);
    AddItemToDatabase(Chestplate);
    AddItemToDatabase(Leggings);
    AddItemToDatabase(Boots);
    enemy.getEquipment().EquipItem(Helmet, enemy, 1);
    enemy.getEquipment().EquipItem(Chestplate, enemy, 2);
    enemy.getEquipment().EquipItem(Leggings, enemy, 3);
    enemy.getEquipment().EquipItem(Boots, enemy, 4);
}

void itemManager::PrintItemDatabase() {
    int i = 0;
    for (const auto& newclmap: ItemDatabase) {
        std::cout << std::to_string(i) + " ";newclmap->getUUIDString();
    }
}

