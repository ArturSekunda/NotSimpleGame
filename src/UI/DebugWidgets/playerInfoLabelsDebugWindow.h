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
    tgui::Label::Ptr P_Stamina = nullptr;
    tgui::Label::Ptr P_Mana = nullptr;
    tgui::Label::Ptr P_Level = nullptr;
    tgui::Label::Ptr P_Experience = nullptr;

    // Skill Stats
    tgui::Label::Ptr P_Strength = nullptr;
    tgui::Label::Ptr P_Dexterity = nullptr;
    tgui::Label::Ptr P_Intelligence = nullptr;
    tgui::Label::Ptr P_Endurance = nullptr;
    tgui::Label::Ptr P_Luck = nullptr;
    tgui::Label::Ptr P_Charisma = nullptr;
    tgui::Label::Ptr P_Vitality = nullptr;
    tgui::Label::Ptr P_Points = nullptr;

public:
    void initializePlayerInfo_Normal(tgui::VerticalLayout &Layout);
    void initializePlayerInfo_SkillStats(tgui::VerticalLayout &Layout);
    void initializePlayerInfo_SkillStats_2(tgui::VerticalLayout &Layout);

    void updatePlayerInfo_Normal(const std::string &name, bool isAlive, int health, int armor, int stamina, int mana, int level, int experience);
    void updatePlayerInfo_SkillStats(int strength, int dexterity, int intelligence, int endurance);
    void updatePlayerInfo_SkillStats_2(int luck, int charisma, int vitality, int points);

};


#endif //NOTSIMPLEGAME_PLAYERINFOLABELSDEBUGWINDOW_H