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

    newArmor.GenerateBonusStats(static_cast<Rarity>(HowMuchRare));


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

void armor::GenerateArmorEnchants(Rarity RR) {
    auto EnchantValuesMap = EC.GetEValues();
    switch (RR) {
        case Rarity::COMMON: {

            for (int i = 0; i < 1; i++) {
                auto Enchant = static_cast<EnchantArmorType>(darkMath::getInstance().generateDistanceDistribution({45,25,15,10,5}));

                GenerateEnchantStruct(Enchant);
            }

        }break;
        case Rarity::UNCOMMON: {

            int enchantCount = darkMath::getInstance().generateIntNumber(1, 2);
            for (int i = 0; i < enchantCount; i++) {
                auto Enchant = static_cast<EnchantArmorType>(darkMath::getInstance().generateDistanceDistribution({35,30,20,10,5}));

                GenerateEnchantStruct(Enchant);
            }

        }break;
        case Rarity::RARE: {

            int enchantCount = darkMath::getInstance().generateIntNumber(1, 3);
            for (int i = 0; i < enchantCount; i++) {
                auto Enchant = static_cast<EnchantArmorType>(darkMath::getInstance().generateDistanceDistribution({25,30,20,15,10}));

                GenerateEnchantStruct(Enchant);
            }

        }break;
        case Rarity::EPIC: {

            int enchantCount = darkMath::getInstance().generateIntNumber(1, 4);
            for (int i = 0; i < enchantCount; i++) {
                auto Enchant = static_cast<EnchantArmorType>(darkMath::getInstance().generateDistanceDistribution({10,20,30,25,15}));

                GenerateEnchantStruct(Enchant);
            }

        }break;
        case Rarity::LEGENDARY: {

            int enchantCount = darkMath::getInstance().generateIntNumber(1, 5);
            for (int i = 0; i < enchantCount; i++) {
                auto Enchant = static_cast<EnchantArmorType>(darkMath::getInstance().generateDistanceDistribution({5,15,20,25,35}));

                GenerateEnchantStruct(Enchant);
            }

        }break;
        default:
            std::cout << "No enchants for this rarity" << "\n";
            break;
    }
}

void armor::GenerateEnchantStruct(EnchantArmorType EType) {
    if (EType == EnchantArmorType::NONE) {
        return;
    }

    auto EnchantMap = EC.GetEnchantArmorNames();

    EnchantmentArmor newEnchant;
    newEnchant.name = EnchantMap[EType];
    newEnchant.type = EType;
    newEnchant.description = "NULL";

    addEnchant(newEnchant);
}

// TODO: Write descriptions after implementing language system support
void armor::GenerateArmorDescription(Prefix WPrefix, Rarity RRT, WeaponType WType, DamageType DT) {
}

// TODO: Write descriptions after implementing language system support
void armor::GenerateEnchantDescription(EnchantArmorType EType, float EValues) {
}

void armor::GenerateBonusStats(Rarity RR) {
    itemBase::GenerateBonusStats(itemBase::GenerateBonusStatsByRarity(RR), bonusStats);
}

void armor::DisplayArmorInfo() const {
    std::cout << "====================\n";
    ItemUUID.DisplayUUID();
    std::cout << "Level: " << getLevel() << "\n";
    std::cout << "Defense: " << GetArmorDefense() << "\n";
    std::cout << "Health: " << GetArmorHealth() << "\n";
    std::cout << "====================\n";
    std::cout << "Enchantments:\n";
    for (const auto& enchant : enchants) {
        std::cout << "- " << enchant.name << "\n";
    }
    std::cout << "====================\n";
    std::cout << "Bonus Stats:\n";
    std::cout << "Strength: " << bonusStats.strength << "\n";
    std::cout << "Dexterity: " << bonusStats.dexterity << "\n";
    std::cout << "Intelligence: " << bonusStats.intelligence << "\n";
    std::cout << "Endurance: " << bonusStats.endurance << "\n";
    std::cout << "Luck: " << bonusStats.luck << "\n";
    std::cout << "Charisma: " << bonusStats.charisma << "\n";
    std::cout << "Vitality: " << bonusStats.vitality << "\n";
    std::cout << "=======================\n";
}
