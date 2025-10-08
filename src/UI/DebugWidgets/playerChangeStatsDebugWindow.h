//
// Created by Artur on 7.10.2025.
//

#ifndef NOTSIMPLEGAME_PLAYERCHANGESTATSDEBUGWINDOW_H
#define NOTSIMPLEGAME_PLAYERCHANGESTATSDEBUGWINDOW_H

#include "TGUI/Widgets/EditBox.hpp"
#include "TGUI/Widgets/Button.hpp"
#include "TGUI/Widgets/Grid.hpp"
#include "TGUI/Widgets/Label.hpp"


struct baseStats;

class playerChangeStatsDebugWindow {
     // Stats
     int Strength = -1;
     int Dexterity = -1;
     int Intelligence = -1;
     int Endurance = -1;
     int Luck = -1;
     int Charisma = -1;
     int Vitality = -1;
     int Points = -1;
     // Labels
     tgui::Label::Ptr Label_Strength = nullptr;
     tgui::Label::Ptr Label_Dexterity = nullptr;
     tgui::Label::Ptr Label_Intelligence = nullptr;
     tgui::Label::Ptr Label_Endurance = nullptr;
     tgui::Label::Ptr Label_Luck = nullptr;
     tgui::Label::Ptr Label_Charisma = nullptr;
     tgui::Label::Ptr Label_Vitality = nullptr;
     tgui::Label::Ptr Label_Points = nullptr;

     // EditBoxes
     tgui::EditBox::Ptr EditBox_Strength = nullptr;
     tgui::EditBox::Ptr EditBox_Dexterity = nullptr;
     tgui::EditBox::Ptr EditBox_Intelligence = nullptr;
     tgui::EditBox::Ptr EditBox_Endurance = nullptr;
     tgui::EditBox::Ptr EditBox_Luck = nullptr;
     tgui::EditBox::Ptr EditBox_Charisma = nullptr;
     tgui::EditBox::Ptr EditBox_Vitality = nullptr;
     tgui::EditBox::Ptr EditBox_Points = nullptr;

     // Buttons for changing stats
     tgui::Button::Ptr Button_Strength = nullptr;
     tgui::Button::Ptr Button_Dexterity = nullptr;
     tgui::Button::Ptr Button_Intelligence = nullptr;
     tgui::Button::Ptr Button_Endurance = nullptr;;
     tgui::Button::Ptr Button_Luck = nullptr;
     tgui::Button::Ptr Button_Charisma = nullptr;
     tgui::Button::Ptr Button_Vitality = nullptr;
     tgui::Button::Ptr Button_Points = nullptr;

     // Vectors to hold labels, edit boxes, and buttons for easy management
     std::vector<tgui::Label::Ptr> Labels;
     std::vector<tgui::EditBox::Ptr> EditBoxes;
     std::vector<tgui::Button::Ptr> Buttons;
     std::vector<tgui::Widget::Ptr> AllWidgets;
public:


    void initializePlayerChangeStats(tgui::Grid &Grid);

    void initializeLabels(tgui::Grid &Grid);

    void initializeEditBoxes(tgui::Grid &Grid);

    void initializeButtons(tgui::Grid &Grid);

    void UpdateSizes(float width, float height);

    void UpdateTextInfo(const int strength, const int dexterity, const int intelligence, const int endurance, const int luck, const int charisma, const int vitality, const int points);

    void HandleButtonClicks(baseStats &playerStats);



     void CleanUp() {
         Label_Strength = nullptr;
         Label_Dexterity = nullptr;
         Label_Intelligence = nullptr;
         Label_Endurance = nullptr;
         Label_Luck = nullptr;
         Label_Charisma = nullptr;
         Label_Vitality = nullptr;
         Label_Points = nullptr;

         EditBox_Strength = nullptr;
         EditBox_Dexterity = nullptr;
         EditBox_Intelligence = nullptr;
         EditBox_Endurance = nullptr;
         EditBox_Luck = nullptr;
         EditBox_Charisma = nullptr;
         EditBox_Vitality = nullptr;
         EditBox_Points = nullptr;

         Button_Strength = nullptr;
         Button_Dexterity = nullptr;
         Button_Intelligence = nullptr;
         Button_Endurance = nullptr;
         Button_Luck = nullptr;
         Button_Charisma = nullptr;
         Button_Vitality = nullptr;
         Button_Points = nullptr;

         Labels.clear();
         EditBoxes.clear();
         Buttons.clear();
         Strength = -1;
         Dexterity = -1;
         Intelligence = -1;
         Endurance = -1;
         Luck = -1;
         Charisma = -1;
         Vitality = -1;
         Points = -1;
         AllWidgets.clear();
     }
};


#endif //NOTSIMPLEGAME_PLAYERCHANGESTATSDEBUGWINDOW_H