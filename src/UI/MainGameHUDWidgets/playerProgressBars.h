
#ifndef NOTSIMPLEGAME_PLAYERPROGRESSBARS_H
#define NOTSIMPLEGAME_PLAYERPROGRESSBARS_H
#include "vector"
#include <TGUI/Backend/SFML-Graphics.hpp>
#include "TGUI/Widgets/ProgressBar.hpp"
#include "TGUI/Widgets/VerticalLayout.hpp"

class player;

class playerProgressBars {

    // Cache

    float PlayerHealth = 0.f;
    float PlayerMaxHealth = 0.f;
    int PlayerMana = 0;
    int PlayerMaxMana = 0;
    float PlayerEXP = 0.f;
    float PlayerEXP_MAX = 0.f;

    unsigned int cachedTextSize = 0;
    float cachedWidgetWidth = 0.f;
    float cachedWidgetHeight = 0.f;

    // Bars
    tgui::ProgressBar::Ptr HealthBar = nullptr;
    tgui::ProgressBar::Ptr ManaBar = nullptr;
    tgui::ProgressBar::Ptr XPBar = nullptr;

    // Vector List
    std::vector<tgui::ProgressBar::Ptr> BarsVec;
public:

    void initializeBars(tgui::VerticalLayout::Ptr StatsLayout);

    void UpdateBars(const player &p);

    void UpdateTextSize(float windowWidth, float windowHeight);


    void setBarStyle(tgui::ProgressBar::Ptr& bar, const tgui::Color& fillColor, const tgui::Color& backgroundColor) {
        bar->setSize("20%", "20%");
        bar->setMinimum(0);
        bar->getRenderer()->setBorderColor(tgui::Color(0, 0, 0, 200));
        bar->getRenderer()->setBorders(2);
        bar->getRenderer()->setFillColor(fillColor);
        bar->getRenderer()->setBackgroundColor(backgroundColor);
    }
};


#endif //NOTSIMPLEGAME_PLAYERPROGRESSBARS_H