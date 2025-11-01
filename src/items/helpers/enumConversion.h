#ifndef NOTSIMPLEGAME_ENUMSTOVECTORLIST_H
#define NOTSIMPLEGAME_ENUMSTOVECTORLIST_H
#include <map>
#include <string>
#include <vector>
#include "items/helpers/itemEnums.h"

class enumConversion {

    std::vector<Rarity> rarity;

    std::vector<Prefix> prefix;

    std::vector<WeaponType> type;

    std::vector<DamageType> modifier;

    std::vector<ItemType> itemTypeList;

    std::vector<ArmorType> armorList;

    std::vector<MaterialTypeOfItem> materialList;

    std::map<EnchantWeaponType,float> EnchantmentValues;

    std::map<EnchantArmorType,float> EnchantArmorValues;

    std::map<Rarity,float> RarityValues;

    std::map<WeaponType,float> WTypeValues;

    std::map<DamageType,float> DamageValues;

    std::map<WeaponType,float> BaseRange;

    std::map<ArmorType,float> ArmorTypeValues;

    std::map<MaterialTypeOfItem,float> MaterialValues;

    std::map<EnchantWeaponType,std::string> EnchantmentName;

    std::map<EnchantArmorType,std::string> EnchantArmorName;

    std::map<Rarity, std::string> RarityName;

    std::map<Prefix, std::string> PrefixName;

    std::map<WeaponType, std::string> WeaponTName;

    std::map<DamageType, std::string> ModifierName;

    std::map<ItemType, std::string> ItemTypeName;

    std::map<ArmorType, std::string> ArmorTypeName;

    std::map<MaterialTypeOfItem,std::string> MaterialName;

private:
    enumConversion() {
        // Initialize everything automatically
        EnumsToVectorList();
        EnumsToString();
        EnumsToValues();
    }
public:

    // Singletone
    static enumConversion& getInstance() {
        static enumConversion instance;
        return instance;
    }
    

    void EnumsToVectorList();

    void EnumsToValues();

    void EnumsToString();

    // Getters

    const std::vector<ArmorType>& GetArmorType();

    const std::vector<ItemType>& GetItemType();

    const std::vector<Rarity>& GetRarity();

    const std::vector<Prefix>& GetPrefix();

    const std::vector<WeaponType>& GetType();

    const std::vector<DamageType>& GetModifier();

    const std::vector<MaterialTypeOfItem>& GetMaterial();

    const std::map<EnchantWeaponType,float>& GetEValues();

    const std::map<Rarity,float>& GetRarityValues();

    const std::map<WeaponType,float>& GetWTypeValues();

    const std::map<DamageType,float>& GetDamageValues();

    const std::map<WeaponType,float>& GetBaseRange();

    const std::map<ArmorType,float>& GetArmorTypeValues();

    const std::map<MaterialTypeOfItem,float>& GetMaterialValues();

    const std::map<EnchantArmorType, float>& GetEnchantArmorValues();

    const std::map<EnchantWeaponType, std::string>& GetEnchantmentNames();

    const std::map<EnchantArmorType, std::string>& GetEnchantArmorNames();

    const std::map<Rarity, std::string>& GetRarityNames();

    const std::map<Prefix, std::string>& GetPrefixNames();

    const std::map<WeaponType, std::string>& GetWeaponTypeNames();

    const std::map<DamageType, std::string>& GetDamageTypeNames();

    const std::map<ItemType, std::string>& GetItemTypeNames();

    const std::map<ArmorType,std::string>& GetArmorTypeName();

    const std::map<MaterialTypeOfItem, std::string>& GetMaterialNames();

};


#endif //NOTSIMPLEGAME_ENUMSTOVECTORLIST_H