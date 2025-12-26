#ifndef NOTSIMPLEGAME_PLAYERADDPOINTSTOSTATS_H
#define NOTSIMPLEGAME_PLAYERADDPOINTSTOSTATS_H
#include "TGUI/Widgets/ChildWindow.hpp"
#include "TGUI/Widgets/Button.hpp"
#include "TGUI/Backend/SFML-Graphics.hpp"
#include "TGUI/Widgets/Grid.hpp"
#include "TGUI/Widgets/Label.hpp"
#include "TGUI/Widgets/Panel.hpp"

struct baseStats;
class player;

class playerAddPointsToStats {

    unsigned int cachedTextSize = 0;
    float cachedWidgetWidth = 0.f;
    float cachedWidgetHeight = 0.f;

    int Strength = -1;
    int Dexterity = -1;
    int Intelligence = -1;
    int Endurance = -1;
    int Luck = -1;
    int Charisma = -1;
    int Vitality = -1;

    tgui::Label::Ptr Label_Strength = nullptr;
    tgui::Label::Ptr Label_Dexterity = nullptr;
    tgui::Label::Ptr Label_Intelligence = nullptr;
    tgui::Label::Ptr Label_Endurance = nullptr;
    tgui::Label::Ptr Label_Luck = nullptr;
    tgui::Label::Ptr Label_Charisma = nullptr;
    tgui::Label::Ptr Label_Vitality = nullptr;

    tgui::Button::Ptr Button_Strength = nullptr;
    tgui::Button::Ptr Button_Dexterity = nullptr;
    tgui::Button::Ptr Button_Intelligence = nullptr;
    tgui::Button::Ptr Button_Endurance = nullptr;;
    tgui::Button::Ptr Button_Luck = nullptr;
    tgui::Button::Ptr Button_Charisma = nullptr;
    tgui::Button::Ptr Button_Vitality = nullptr;

    tgui::ChildWindow::Ptr Stats_Window = nullptr;

    tgui::Panel::Ptr Stats_Panel = nullptr;

    tgui::Grid::Ptr Segregator = nullptr;

    tgui::Button::Ptr Opener_button = nullptr;

    std::vector<tgui::Label::Ptr> Labels;
    std::vector<tgui::Button::Ptr> Buttons;



public:

    void initializeWindow(tgui::Gui& gui, player& player);

    void initializeOpenerButton(const tgui::Panel::Ptr& parentPanel);

    void initializeSegregator();

    void initializePanel();

    void initializeLabels();

    void initializeButtons();

    void UpdateSizes(float width, float height);

    void UpdateTextInfo(const baseStats& stats);

    void HandleButtonClicks(baseStats &playerStats);

    bool getIsWindowOpen() const {
        return Stats_Window->isVisible();
    }

    void setIsWindowOpen(bool isOpen) {
        Stats_Window->setVisible(isOpen);
    }
};


#endif //NOTSIMPLEGAME_PLAYERADDPOINTSTOSTATS_H