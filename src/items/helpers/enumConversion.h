#ifndef NOTSIMPLEGAME_ENUMSTOVECTORLIST_H
#define NOTSIMPLEGAME_ENUMSTOVECTORLIST_H
#include <map>
#include <vector>
#include "items/helpers/itemEnums.h"

class enumConversion {

    std::vector<Rarity> rarity;

    std::vector<WeaponPrefix> prefix;

    std::vector<WeaponType> type;

    std::vector<DamageType> modifier;

    std::map<EnchantType, float> EnchantmentValues;
public:

    void EnumsToVectorList();

    void EnumsToValues();

    // Getters
    std::vector<Rarity> GetRarity();
    std::vector<WeaponPrefix> GetPrefix();
    std::vector<WeaponType> GetType();
    std::vector<DamageType> GetModifier();

    std::map<EnchantType,float> GetEValues();


};


#endif //NOTSIMPLEGAME_ENUMSTOVECTORLIST_H