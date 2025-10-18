#ifndef NOTSIMPLEGAME_ENUMSTOVECTORLIST_H
#define NOTSIMPLEGAME_ENUMSTOVECTORLIST_H
#include <vector>
#include "items/helpers/itemEnums.h"

class enumsToVectorList {

    std::vector<Rarity> rarityValues;

    std::vector<WeaponPrefix> prefixValues;

    std::vector<WeaponType> typeValues;

    std::vector<DamageType> modifierValues;
public:

    void EnumsToVectorList();

    // Getters
    std::vector<Rarity> GetRarityValues();
    std::vector<WeaponPrefix> GetPrefixValues();
    std::vector<WeaponType> GetTypeValues();
    std::vector<DamageType> GetModifierValues();


};


#endif //NOTSIMPLEGAME_ENUMSTOVECTORLIST_H