#ifndef NOTSIMPLEGAME_WAVECOUNTER_H
#define NOTSIMPLEGAME_WAVECOUNTER_H

#include "TGUI/Widgets/Label.hpp"
#include "TGUI/Widgets/VerticalLayout.hpp"

class waveCounter {

    unsigned int cachedTextSize = 0;
    float cachedWidgetWidth = 0.0f;
    float cachedWidgetHeight = 0.0f;

    tgui::Label::Ptr WaveLabel = nullptr;
public:
    void initializeLabel(tgui::VerticalLayout::Ptr  WaveCounterLayout);

    void UpdateWaveLabel(int currentWave, bool visible);

    void UpdateTextSize(float windowWidth, float windowHeight);
};


#endif //NOTSIMPLEGAME_WAVECOUNTER_H