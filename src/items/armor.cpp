#include "armor.h"
#include "core/darkMath.h"

armor armor::CreateNewArmor(int playerLevel, int itemID) {
    armor newArmor;

    auto& EC = enumConversion::getInstance();

    int HowMuchRare = darkMath::getInstance().generateDistanceDistribution({55,20,15,10,5}) + 1;
    int APrefix = darkMath::getInstance().UniformIntDistribution(0, static_cast<int>(EC.GetPrefix().size() - 1));
    int Type = darkMath::getInstance().UniformIntDistribution(1, static_cast<int>(EC.GetArmorType().size() - 1));
    int Material = darkMath::getInstance().generateDistanceDistribution({55,20,15,10,5,1}) + 1;

    newArmor.GenerateArmorName(static_cast<Prefix>(APrefix),static_cast<Rarity>(HowMuchRare),static_cast<ArmorType>(Type), static_cast<MaterialTypeOfItem>(Material));

    newArmor.GenerateArmorStats(playerLevel,static_cast<Rarity>(HowMuchRare),static_cast<ArmorType>(Type), static_cast<MaterialTypeOfItem>(Material));

    newArmor.GenerateBonusStats(static_cast<Rarity>(HowMuchRare));

    auto probs = newArmor.GetArmorEnchantProbabilities(static_cast<Rarity>(HowMuchRare));
    newArmor.GenerateArmorEnchants(static_cast<Rarity>(HowMuchRare), probs);

    newArmor.ApplyArmorEnchants();


    newArmor.setGenItemType(ItemType::ARMOR);
    newArmor.setId(itemID);

    return newArmor;
}


std::vector<int> armor::GetArmorEnchantProbabilities(Rarity RR) {
    switch (RR) {
        case Rarity::COMMON: return {55,30,30,20};
        case Rarity::UNCOMMON: return {50,44,35,25};
        case Rarity::RARE: return {35,45,40,40};
        case Rarity::EPIC: return {20,55,50,50};
        case Rarity::LEGENDARY: return {10,60,65,65};
        default: return {};
    }
}

void armor::GenerateArmorEnchants(Rarity RR, std::vector<int> chanceDistance) {
    int enchantCount = GenerateBonusStatsByRarity(RR);

    for (int i = 0; i < enchantCount; i++) {
        int idx = darkMath::getInstance().generateDistanceDistribution(chanceDistance);
        auto type = static_cast<EnchantArmorType>(idx);
        GenerateEnchantStruct(type);
    }
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
    float baseArmorMana =
        (5 + (ArmorLevel * 2.0f)) *
        rarityMultiplier *
        typeMultiplier *
        materialMultiplier;

    setArmorDefense(baseArmorDefense);
    setArmorHealth(baseArmorHealth);
    setArmorMana(baseArmorMana);
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

void armor::ApplyArmorEnchants() {
    auto EnchantValuesMap = EC.GetEnchantArmorValues();

    float TotalHealthToAdd = 0.f;
    float TotalArmorToAdd = 0.f;
    float TotalManaToAdd = 0.f;


    for (const auto& enchant : enchants) {
        switch (enchant.type) {
            case EnchantArmorType::ADDITIONAL_HEALTH: {
                TotalHealthToAdd += EnchantValuesMap.at(EnchantArmorType::ADDITIONAL_HEALTH);
            } break;
            case EnchantArmorType::ADDITIONAL_DEFENSE: {
                TotalArmorToAdd += EnchantValuesMap.at(EnchantArmorType::ADDITIONAL_DEFENSE);
            } break;
            case EnchantArmorType::ADDITIONAL_MANA: {
                TotalManaToAdd += EnchantValuesMap.at(EnchantArmorType::ADDITIONAL_MANA);
            } break;
            default:
                break;
        }
    }

    // Apply all enchantment
    float currentArmor = getArmorDefense();
    float currentHealth = getArmorHealth();
    float currentMana = getArmorMana();
    setArmorDefense(currentArmor + TotalArmorToAdd);
    setArmorHealth(currentHealth + TotalHealthToAdd);
    setArmorMana(currentMana + TotalManaToAdd);

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
    std::cout << "Defense: " << getArmorDefense() << "\n";
    std::cout << "Health: " << getArmorHealth() << "\n";
    std::cout << "Mana: " << getArmorMana() << "\n";
    std::cout << "====================\n";
    std::cout << "Enchantments:\n";
    for (const auto& enchant : enchants) {
        if (enchants.empty()) {
            break;
        }
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
