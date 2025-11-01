#ifndef NOTSIMPLEGAME_ARMOR_H
#define NOTSIMPLEGAME_ARMOR_H
#include "itemBase.h"


class armor : public itemBase {
protected:
     ArmorType Armor = ArmorType::NONE;
     float ArmorDefense = 0.f;
     float ArmorHealth = 0.f;

     ItemBonusStats bonusStats;
     std::vector<EnchantmentArmor> enchants;

     enumConversion& EC = enumConversion::getInstance();
public:
     armor() = default;
     ~armor() override = default;

     //Generate
     static armor GenerateNewArmor(int playerLevel, int itemID);

     void GenerateArmorName(Prefix prefix,Rarity rarity, ArmorType AType, MaterialTypeOfItem material);

     void GenerateArmorStats(int playerLevel, Rarity rarity, ArmorType type, MaterialTypeOfItem material);

     void GenerateArmorEnchants(Rarity RR);

     void GenerateEnchantStruct(EnchantArmorType EType);

     void GenerateArmorDescription(Prefix WPrefix,Rarity RRT, WeaponType WType, DamageType DT);

     void GenerateEnchantDescription(EnchantArmorType EType,float EValues);

     void GenerateBonusStats(Rarity RR);

     void DisplayArmorInfo() const;

public:
     //Getters
     ArmorType GetArmorType() const { return Armor; }
     float GetArmorDefense() const { return ArmorDefense; }
     float GetArmorHealth() const { return ArmorHealth; }

     void addEnchant(const EnchantmentArmor &enchant) { enchants.push_back(enchant); }

     //Setters
     void SetArmorType(ArmorType type) { Armor = type; }
     void SetArmorDefense(float d) { ArmorDefense = d; }
     void SetArmorHealth(float h) { ArmorHealth = h; }
};


#endif //NOTSIMPLEGAME_ARMOR_H