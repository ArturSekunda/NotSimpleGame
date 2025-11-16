#ifndef NOTSIMPLEGAME_ARMOR_H
#define NOTSIMPLEGAME_ARMOR_H
#include "itemBase.h"


class armor : public itemBase {
protected:
     ArmorType Armor = ArmorType::NONE;
     float ArmorDefense = 0.f;
     float ArmorHealth = 0.f;
     float ArmorMana = 0.f;

     ItemBonusStats bonusStats;
     std::vector<EnchantmentArmor> enchants;

public:
     armor() = default;
     ~armor() override = default;

     //Generate
     static armor CreateNewArmor(int playerLevel, int itemID);

     static armor CreateNewArmor(ArmorType AType,int playerLevel, int itemID);

     std::vector<int> GetArmorEnchantProbabilities(Rarity RR);

     void GenerateArmorEnchants(Rarity RR, std::vector<int> chanceDistance);

     void GenerateArmorName(Prefix prefix,Rarity rarity, ArmorType AType, MaterialTypeOfItem material);

     void GenerateArmorStats(int playerLevel, Rarity rarity, ArmorType type, MaterialTypeOfItem material);

     void GenerateEnchantStruct(EnchantArmorType EType);

     void ApplyArmorEnchants();

     void GenerateArmorDescription(Prefix WPrefix,Rarity RRT, WeaponType WType, DamageType DT);

     void GenerateEnchantDescription(EnchantArmorType EType,float EValues);

     void GenerateBonusStats(Rarity RR);

     void DisplayArmorInfo() const;

public:
     //Getters
     ArmorType getArmorType() const { return Armor; }
     float getArmorDefense() const { return ArmorDefense; }
     float getArmorHealth() const { return ArmorHealth; }
     float getArmorMana() const { return ArmorMana; }
     ItemBonusStats getBonusStats() const { return bonusStats; }

     void addEnchant(const EnchantmentArmor &enchant) { enchants.push_back(enchant); }

     //Setters
     void setArmorType(ArmorType type) { Armor = type; }
     void setArmorDefense(float d) { ArmorDefense = d; }
     void setArmorHealth(float h) { ArmorHealth = h; }
     void setArmorMana(float m) { ArmorMana = m; }
};


#endif //NOTSIMPLEGAME_ARMOR_H