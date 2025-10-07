//
// Created by Artur on 6.10.2025.
//

#ifndef NOTSIMPLEGAME_PLAYERINFOLABELSDEBUGWINDOW_H
#define NOTSIMPLEGAME_PLAYERINFOLABELSDEBUGWINDOW_H
#include "TGUI/Widgets/Label.hpp"
#include "TGUI/Widgets/VerticalLayout.hpp"


class playerInfoLabelsDebugWindow {

    tgui::Label::Ptr P_Name = nullptr;
    tgui::Label::Ptr P_IsAlive = nullptr;
    tgui::Label::Ptr P_Health = nullptr;
    tgui::Label::Ptr P_Armor = nullptr;
    tgui::Label::Ptr P_Speed = nullptr;
    tgui::Label::Ptr P_Mana = nullptr;
    tgui::Label::Ptr P_Level = nullptr;
    tgui::Label::Ptr P_Experience = nullptr;
    tgui::Label::Ptr P_EXP_MAX = nullptr;

    // Skill Stats
    tgui::Label::Ptr P_Strength = nullptr;
    tgui::Label::Ptr P_Dexterity = nullptr;
    tgui::Label::Ptr P_Intelligence = nullptr;
    tgui::Label::Ptr P_Endurance = nullptr;
    tgui::Label::Ptr P_Luck = nullptr;
    tgui::Label::Ptr P_Charisma = nullptr;
    tgui::Label::Ptr P_Vitality = nullptr;
    tgui::Label::Ptr P_Points = nullptr;

    std::vector<tgui::Label::Ptr> L_PInfo_Normal;
    std::vector<tgui::Label::Ptr> L_PInfo_SkillStats;
    std::vector<tgui::Label::Ptr> L_PInfo_SkillStats_2;
public:

    void CleanUp() {
        P_Name = nullptr;
        P_IsAlive = nullptr;
        P_Health = nullptr;
        P_Armor = nullptr;
        P_Speed = nullptr;
        P_Mana = nullptr;
        P_Level = nullptr;
        P_Experience = nullptr;

        P_Strength = nullptr;
        P_Dexterity = nullptr;
        P_Intelligence = nullptr;
        P_Endurance = nullptr;
        P_Luck = nullptr;
        P_Charisma = nullptr;
        P_Vitality = nullptr;
        P_Points = nullptr;
        L_PInfo_Normal.clear();
        L_PInfo_SkillStats.clear();
        L_PInfo_SkillStats_2.clear();
    }

    void initializePlayerInfo_Normal(tgui::VerticalLayout &Layout);
    void initializePlayerInfo_SkillStats(tgui::VerticalLayout &Layout);
    void initializePlayerInfo_SkillStats_2(tgui::VerticalLayout &Layout);

    void UpdateTextSizes(float width, float height);

    void updatePlayerInfo_Normal(const std::string &name, bool isAlive, int health, int armor, int speed, int mana, int level, float experience, float expMax);
    void updatePlayerInfo_SkillStats(int strength, int dexterity, int intelligence, int endurance);
    void updatePlayerInfo_SkillStats_2(int luck, int charisma, int vitality, int points);

};


#endif //NOTSIMPLEGAME_PLAYERINFOLABELSDEBUGWINDOW_H