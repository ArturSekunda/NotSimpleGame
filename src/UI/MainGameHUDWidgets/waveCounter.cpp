#include "waveCounter.h"

void waveCounter::initializeLabel(tgui::VerticalLayout::Ptr WaveCounterLayout) {
    WaveLabel = tgui::Label::create();
    if (!WaveLabel) {
        throw std::runtime_error("Failed to create wave counter label");
    }
    WaveLabel->getRenderer()->setTextColor(tgui::Color::White);
    WaveCounterLayout->add(WaveLabel);
}

void waveCounter::UpdateWaveLabel(int currentWave, bool visible) {
        WaveLabel->setVisible(visible);
        WaveLabel->setText("Wave: " + std::to_string(currentWave));
}

void waveCounter::UpdateTextSize(float windowWidth, float windowHeight) {
    unsigned int newTextSize = static_cast<unsigned int>(windowHeight * 0.03f);
    float newWidgetWidth = windowWidth * 0.08f;
    float newWidgetHeight = windowHeight * 0.08f;

    if (newTextSize == cachedTextSize && newWidgetWidth == cachedWidgetWidth && newWidgetHeight == cachedWidgetHeight) {
        return;
    }

    if (WaveLabel) {
        WaveLabel->setSize(newWidgetWidth, newWidgetHeight);
        WaveLabel->setTextSize(newTextSize);

    }

    cachedTextSize = newTextSize;
    cachedWidgetWidth = newWidgetWidth;
    cachedWidgetHeight = newWidgetHeight;
}