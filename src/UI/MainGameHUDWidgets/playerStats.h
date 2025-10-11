#ifndef NOTSIMPLEGAME_PLAYERSTATS_H
#define NOTSIMPLEGAME_PLAYERSTATS_H
#include "vector"
#include <TGUI/Backend/SFML-Graphics.hpp>
#include "TGUI/Widgets/Grid.hpp"
#include "TGUI/Widgets/Label.hpp"


struct baseStats;

class playerStats {
    // Cache
    unsigned int cachedTextSize = 0;
    float cachedWidgetWidth = 0.f;
    float cachedWidgetHeight = 0.f;

    int PlayerStrength = -1;
    int PlayerDexterity = -1;
    int PlayerIntelligence = -1;
    int PlayerEndurance = -1;
    int PlayerLuck = -1;
    int PlayerCharisma = -1;
    int PlayerVitality = -1;
    int PlayerPointsToSpend = -1;

    // Labels
    tgui::Label::Ptr P_Strength = nullptr;
    tgui::Label::Ptr P_Dexterity = nullptr;
    tgui::Label::Ptr P_Intelligence = nullptr;
    tgui::Label::Ptr P_Endurance = nullptr;
    tgui::Label::Ptr P_Luck = nullptr;
    tgui::Label::Ptr P_Charisma = nullptr;
    tgui::Label::Ptr P_Vitality = nullptr;
    tgui::Label::Ptr P_PointsToSpend = nullptr;

    // Vector
    std::vector<tgui::Label::Ptr> Labels_1;
    std::vector<tgui::Label::Ptr> Labels_2;
    std::vector<tgui::Label::Ptr> Labels_All;
public:
    void initializeLabels(tgui::Grid::Ptr StatsLayout);

    void UpdateLabels(const baseStats &stats);

    void UpdateTextSizes(float width, float height);


};


#endif //NOTSIMPLEGAME_PLAYERSTATS_H