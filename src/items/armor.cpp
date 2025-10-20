#include "armor.h"
#include "core/darkMath.h"

armor armor::GenerateNewArmor(int playerLevel, int itemID) {
    armor newArmor;

    auto& EC = enumConversion::getInstance();

    int HowMuchRare = darkMath::getInstance().generateDistanceDistribution({55,20,15,10,5}) + 1;
    int APrefix = darkMath::getInstance().UniformIntDistribution(0, static_cast<int>(EC.GetPrefix().size() - 1));
    int Type = darkMath::getInstance().UniformIntDistribution(1, static_cast<int>(EC.GetArmorType().size() - 1));
    int Material = darkMath::getInstance().generateDistanceDistribution({55,20,15,10,5,1}) + 1;

    newArmor.GenerateArmorName(static_cast<Prefix>(APrefix),static_cast<Rarity>(HowMuchRare),static_cast<ArmorType>(Type), static_cast<MaterialTypeOfItem>(Material));

    newArmor.GenerateArmorStats(playerLevel,static_cast<Rarity>(HowMuchRare),static_cast<ArmorType>(Type), static_cast<MaterialTypeOfItem>(Material));


    newArmor.setGenItemType(ItemType::ARMOR);
    newArmor.setId(itemID);

    return newArmor;
}

void armor::GenerateArmorName(Prefix prefix, Rarity rarity, ArmorType AType, MaterialTypeOfItem material) {

    ItemUUID.ItemName =
        EC.GetRarityNames().at(rarity) + " " +
            EC.GetPrefixNames().at(prefix) + " " +
                EC.GetMaterialNames().at(material) + " " +
                    EC.GetArmorTypeName().at(AType);
}

void armor::GenerateArmorStats(int playerLevel, Rarity rarity, ArmorType type, MaterialTypeOfItem material) {

    auto ArmorLevel = darkMath::getInstance().generateIntNumber(std::clamp(playerLevel - 2, 1, playerLevel), playerLevel + 1);

    setLevel(ArmorLevel);

    float rarityMultiplier = EC.GetRarityValues().at(rarity);
    float typeMultiplier = EC.GetArmorTypeValues().at(type);
    float materialMultiplier = EC.GetMaterialValues().at(material);

    float baseArmorDefense =
        (5 + (ArmorLevel * 2.0f)) *
        rarityMultiplier *
        typeMultiplier *
        materialMultiplier;

    float baseArmorHealth =
        (5 + (ArmorLevel * 2.0f)) *
        rarityMultiplier *
        typeMultiplier *
        materialMultiplier;

    SetArmorDefense(baseArmorDefense);
    SetArmorHealth(baseArmorHealth);
}

void armor::DisplayArmorInfo() const {
    std::cout << "====================\n";
    ItemUUID.DisplayUUID();
    std::cout << "Level: " << getLevel() << "\n";
    std::cout << "Defense: " << GetArmorDefense() << "\n";
    std::cout << "Health: " << GetArmorHealth() << "\n";
    std::cout << "====================\n";
}
