
#ifndef NOTSIMPLEGAME_PLAYERCHANGENORMALSTATSDEBUGWINDOW_H
#define NOTSIMPLEGAME_PLAYERCHANGENORMALSTATSDEBUGWINDOW_H
#include "TGUI/Widgets/Button.hpp"
#include "TGUI/Widgets/Label.hpp"
#include "TGUI/Widgets/EditBox.hpp"
#include "TGUI/Widgets/Grid.hpp"


class debugHandler;
struct baseStats;

class playerChangeNormalStatsDebugWindow {

    // Cached values to detect changes
    bool cachedIsAlive = false;
    float cachedHealth = -1;
    float cachedDefense = -1;
    float cachedSpeed = -1;
    int cachedMana = -1;
    int cachedLevel = -1;
    float cachedEXP = -1.f;
    unsigned int cachedTextSize = 0;
    float cachedWidgetWidth = 0.f;
    float cachedWidgetHeight = 0.f;

    // Labels for normal stats
    tgui::Label::Ptr P_IsAlive = nullptr;
    tgui::Label::Ptr P_Health = nullptr;
    tgui::Label::Ptr P_Defense = nullptr;
    tgui::Label::Ptr P_Speed = nullptr;
    tgui::Label::Ptr P_Mana = nullptr;
    tgui::Label::Ptr P_Level = nullptr;
    tgui::Label::Ptr P_EXP = nullptr;

    // EditBoxes
    tgui::EditBox::Ptr EditBox_SetHealth = nullptr;
    tgui::EditBox::Ptr EditBox_SetMana = nullptr;
    tgui::EditBox::Ptr EditBox_SetDefense = nullptr;
    tgui::EditBox::Ptr EditBox_SetSpeed = nullptr;
    tgui::EditBox::Ptr EditBox_SetLevel = nullptr;
    tgui::EditBox::Ptr EditBox_SetEXP = nullptr;
    tgui::EditBox::Ptr EditBox_SetIsAlive = nullptr;

    // Buttons
    tgui::Button::Ptr Button_SetHealth = nullptr;
    tgui::Button::Ptr Button_SetMana = nullptr;
    tgui::Button::Ptr Button_SetDefense = nullptr;
    tgui::Button::Ptr Button_SetSpeed = nullptr;
    tgui::Button::Ptr Button_SetLevel = nullptr;
    tgui::Button::Ptr Button_SetEXP = nullptr;
    tgui::Button::Ptr Button_SetIsAlive = nullptr;

    // Vectors to hold widgets for easy management
    std::vector<tgui::Widget::Ptr> AllWidgets;
    std::vector<tgui::Label::Ptr> Labels;
    std::vector<tgui::EditBox::Ptr> EditBoxes;
    std::vector<tgui::Button::Ptr> Buttons;
public:


    void CleanUp();

    void initializePlayerChangeNormalStats(tgui::Grid::Ptr Grid);

    void initializeLabels(tgui::Grid::Ptr Grid);

    void initializeEditBoxes(tgui::Grid::Ptr Grid);

    void initializeButtons(tgui::Grid::Ptr Grid);

    void UpdateSizes(float width, float height);

    void UpdateTextInfo(bool IsAlive, float Health, float Defense, float Speed, int Mana, int Level, float EXP);

    void HandleButtonClicks(debugHandler &debugHandlerInstance);









};


#endif //NOTSIMPLEGAME_PLAYERCHANGENORMALSTATSDEBUGWINDOW_H