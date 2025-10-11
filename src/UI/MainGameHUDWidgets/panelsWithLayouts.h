
#ifndef NOTSIMPLEGAME_PANELSWITHLAYOUTS_H
#define NOTSIMPLEGAME_PANELSWITHLAYOUTS_H
#include "TGUI/Widgets/Panel.hpp"
#include "TGUI/Widgets/VerticalLayout.hpp"
#include "TGUI/Backend/SFML-Graphics.hpp"
#include "TGUI/Widgets/Grid.hpp"

class panelsWithLayouts {
    // Panels
    tgui::Panel::Ptr MainPanel = nullptr;
    tgui::Panel::Ptr Side_PlayerPanel = nullptr;
    tgui::Panel::Ptr Top_InfoPanel = nullptr;

    // Layouts
    tgui::VerticalLayout::Ptr PlayerNameEXPLayout = nullptr;
    tgui::VerticalLayout::Ptr StatsLayout = nullptr;
    tgui::Grid::Ptr StatsGrid = nullptr;
public:

    void CombineAll(tgui::Gui &gui);

    void initializePanels(tgui::Gui &gui);

    void initializePlayerNameEXPLayout();

    void initializeStatsLayout();

    void initializeStatsGridPanel();


    std::map<std::string, tgui::Widget::Ptr> Layouts;
};


#endif //NOTSIMPLEGAME_PANELSWITHLAYOUTS_H