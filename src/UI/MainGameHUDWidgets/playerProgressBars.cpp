#include "playerProgressBars.h"

#include "entities/player/player.h"

void playerProgressBars::initializeBars(tgui::VerticalLayout::Ptr StatsLayout) {
    HealthBar = tgui::ProgressBar::create();
    ManaBar = tgui::ProgressBar::create();
    XPBar = tgui::ProgressBar::create();

    if (!HealthBar || !ManaBar || !XPBar) {
        throw std::runtime_error("Failed to create progress bars");
    }

    setBarStyle(HealthBar, tgui::Color(255, 50, 50, 200), tgui::Color(255, 50, 50, 255));
    setBarStyle(ManaBar, tgui::Color(50, 50, 255, 200), tgui::Color(50, 50, 255, 255));
    setBarStyle(XPBar, tgui::Color(0, 160, 16, 200), tgui::Color(50, 255, 50, 255));

    StatsLayout->add(HealthBar);

    StatsLayout->add(ManaBar);

    StatsLayout->add(XPBar);

    BarsVec = {HealthBar, ManaBar, XPBar};
}

void playerProgressBars::UpdateBars(const player &p) {

    if (PlayerHealth != p.getHealth() || PlayerMaxHealth != p.getMaxHealth()) {
        PlayerHealth = p.getHealth();
        PlayerMaxHealth = p.getMaxHealth();
        HealthBar->setMaximum(static_cast<unsigned int>(PlayerMaxHealth));
        HealthBar->setValue(static_cast<unsigned int>(PlayerHealth));
        HealthBar->setText("Health: " + std::to_string(HealthBar->getValue() ) + " / " + std::to_string(HealthBar->getMaximum()));
    }

    if (PlayerMana != p.getMana() || PlayerMaxMana != p.getMaxMana()) {
        PlayerMana = p.getMana();
        PlayerMaxMana = p.getMaxMana();
        ManaBar->setMaximum(static_cast<unsigned int>(PlayerMaxMana));
        ManaBar->setValue(static_cast<unsigned int>(PlayerMana));
        ManaBar->setText("Mana: " + std::to_string(ManaBar->getValue()) + " / " + std::to_string(ManaBar->getMaximum()));
    }

    if (PlayerEXP != p.getEXP() || PlayerEXP_MAX != p.getEXP_MAX()) {
        PlayerEXP = p.getEXP();
        PlayerEXP_MAX = p.getEXP_MAX();
        XPBar->setMaximum(static_cast<unsigned int>(PlayerEXP_MAX));
        XPBar->setValue(static_cast<unsigned int>(PlayerEXP));
        XPBar->setText("EXP: " + std::to_string(XPBar->getValue()) + " / " + std::to_string(XPBar->getMaximum()));
    }

}

void playerProgressBars::UpdateTextSize(float windowWidth, float windowHeight) {
    unsigned int newTextSize = static_cast<unsigned int>(windowHeight * 0.02f);
    float newWidgetWidth = windowWidth * 0.05f;
    float newWidgetHeight = windowHeight * 0.05f;

    if (newTextSize == cachedTextSize && newWidgetWidth == cachedWidgetWidth && newWidgetHeight == cachedWidgetHeight) {
        return; // No changes needed
    }

    for (auto& BarTextSize: BarsVec) {
        //if (AllWidgetsXD) {
        BarTextSize->setTextSize(newTextSize);
        //}
    }
    cachedTextSize = newTextSize;
    cachedWidgetWidth = newWidgetWidth;
    cachedWidgetHeight = newWidgetHeight;
}
