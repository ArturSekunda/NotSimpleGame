#ifndef NOTSIMPLEGAME_PLAYERNAMEANDLEVEL_H
#define NOTSIMPLEGAME_PLAYERNAMEANDLEVEL_H
#include "TGUI/Widgets/Label.hpp"
#include "TGUI/Widgets/VerticalLayout.hpp"
#include "TGUI/Backend/SFML-Graphics.hpp"

class playerNameAndLevel {
    // Cache
    float windowWidth = 0.f;
    float windowHeight = 0.f;

    unsigned int cachedTextSize = 0;
    float cachedWidgetWidth = 0.f;
    float cachedWidgetHeight = 0.f;

    int PlayerLevel = -1;
    std::string PlayerName = "NONE";

    // Labels
    tgui::Label::Ptr PlayerNameLabel = nullptr;
    tgui::Label::Ptr LevelLabel = nullptr;
public:

    void initializeLabels(tgui::VerticalLayout::Ptr PlayerNameAndLevelLayout);

    void UpdateLabels(const std::string& playerName,const int& level);

    void UpdateTextSizes(float width, float height);


    void CleanUp() {
        PlayerNameLabel = nullptr;
        LevelLabel = nullptr;
        windowWidth = 0.f;
        windowHeight = 0.f;
        PlayerLevel = -1;
        PlayerName = "NONE";
        cachedTextSize = 0;
        cachedWidgetWidth = 0.f;
        cachedWidgetHeight = 0.f;
    }


};


#endif //NOTSIMPLEGAME_PLAYERNAMEANDLEVEL_H