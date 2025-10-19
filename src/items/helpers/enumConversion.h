#ifndef NOTSIMPLEGAME_ENUMSTOVECTORLIST_H
#define NOTSIMPLEGAME_ENUMSTOVECTORLIST_H
#include <map>
#include <string>
#include <vector>
#include "items/helpers/itemEnums.h"

class enumConversion {

    std::vector<Rarity> rarity;

    std::vector<WeaponPrefix> prefix;

    std::vector<WeaponType> type;

    std::vector<DamageType> modifier;

    std::vector<ItemType> itemTypeList;

    std::map<EnchantType,float> EnchantmentValues;

    std::map<Rarity,float> RarityValues;

    std::map<WeaponType,float> WTypeValues;

    std::map<DamageType,float> DamageValues;

    std::map<WeaponType,float> BaseRange;

    std::map<EnchantType,std::string> EnchantmentName;

    std::map<Rarity, std::string> RarityName;

    std::map<WeaponPrefix, std::string> PrefixName;

    std::map<WeaponType, std::string> WeaponTName;

    std::map<DamageType, std::string> ModifierName;

    std::map<ItemType, std::string> ItemTypeName;

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

    const std::vector<ItemType>& GetItemType();

    const std::vector<Rarity>& GetRarity();

    const std::vector<WeaponPrefix>& GetPrefix();

    const std::vector<WeaponType>& GetType();

    const std::vector<DamageType>& GetModifier();

    const std::map<EnchantType,float>& GetEValues();

    const std::map<Rarity,float>& GetRarityValues();

    const std::map<WeaponType,float>& GetWTypeValues();

    const std::map<DamageType,float>& GetDamageValues();

    const std::map<WeaponType,float>& GetBaseRange();

    const std::map<EnchantType, std::string>& GetEnchantmentNames();

    const std::map<Rarity, std::string>& GetRarityNames();

    const std::map<WeaponPrefix, std::string>& GetPrefixNames();

    const std::map<WeaponType, std::string>& GetWeaponTypeNames();

    const std::map<DamageType, std::string>& GetDamageTypeNames();

    const std::map<ItemType, std::string>& GetItemTypeNames();

};


#endif //NOTSIMPLEGAME_ENUMSTOVECTORLIST_H