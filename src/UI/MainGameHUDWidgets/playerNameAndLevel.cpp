#include "playerNameAndLevel.h"

void playerNameAndLevel::initializeLabels(tgui::VerticalLayout::Ptr PlayerNameAndLevelLayout) {
    PlayerNameLabel = tgui::Label::create();
    LevelLabel = tgui::Label::create();

    if (!PlayerNameLabel || !LevelLabel) {
        throw std::runtime_error("Failed to create labels");
    }

    // Player Name Label
    PlayerNameLabel->getRenderer()->setTextColor(tgui::Color::White);
    PlayerNameAndLevelLayout->add(PlayerNameLabel);

    // Level Label
    LevelLabel->getRenderer()->setTextColor(tgui::Color::White);
    PlayerNameAndLevelLayout->add(LevelLabel);
}

void playerNameAndLevel::UpdateLabels(const std::string &playerName, const int &level) {
    if (PlayerName != playerName) {
        PlayerName = playerName;
        if (PlayerNameLabel) {
            PlayerNameLabel->setText("Player: " + PlayerName);
        }
    }
    if (PlayerLevel != level) {
        PlayerLevel = level;
        if (LevelLabel) {
            LevelLabel->setText("Level: " + std::to_string(PlayerLevel));
        }
    }
}

void playerNameAndLevel::UpdateTextSizes(float width, float height) {
    unsigned int newTextSize = static_cast<unsigned int>(height * 0.03f);
    float newWidgetWidth = width * 0.05f;
    float newWidgetHeight = height * 0.05f;

    if (newTextSize == cachedTextSize && newWidgetWidth == cachedWidgetWidth && newWidgetHeight == cachedWidgetHeight) {
        return; // No changes needed
    }

    for (auto& LabelTextSize: {PlayerNameLabel, LevelLabel}) {
        //if (AllWidgetsXD) {
        LabelTextSize->setTextSize(newTextSize);
        //}
    }
    cachedTextSize = newTextSize;
    cachedWidgetWidth = newWidgetWidth;
    cachedWidgetHeight = newWidgetHeight;
}
