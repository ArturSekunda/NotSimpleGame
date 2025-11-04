#include "playerStats.h"

#include "entities/helpers/entityStructs.h"


void playerStats::initializeLabels(tgui::Grid::Ptr StatsLayout) {
    P_Strength = tgui::Label::create();
    P_Dexterity = tgui::Label::create();
    P_Intelligence = tgui::Label::create();
    P_Endurance = tgui::Label::create();
    P_Luck = tgui::Label::create();
    P_Charisma = tgui::Label::create();
    P_Vitality = tgui::Label::create();
    P_PointsToSpend = tgui::Label::create();

    if (!P_Strength || !P_Dexterity || !P_Intelligence || !P_Endurance || !P_Luck || !P_Charisma || !P_Vitality || !P_PointsToSpend) {
        throw std::runtime_error("Failed to create stats labels");
    }

    Labels_1 = {P_Strength, P_Dexterity, P_Intelligence, P_Endurance};
    Labels_2 = {P_Luck, P_Charisma, P_Vitality, P_PointsToSpend};

    Labels_All = {P_Strength, P_Dexterity, P_Intelligence, P_Endurance, P_Luck, P_Charisma, P_Vitality, P_PointsToSpend};

    int i = 0;
    for (auto& Labels: Labels_All) {
        Labels->getRenderer()->setTextColor(tgui::Color::White);
        StatsLayout->add(Labels);
    }
    for (auto& AddLabelsToRows: Labels_1) {
        StatsLayout->setWidgetCell(AddLabelsToRows, i, 0);
        i++;
    }
    i = 0;
    for (auto& AddLabelsToRows: Labels_2) {
        StatsLayout->setWidgetCell(AddLabelsToRows, i, 1);
        i++;
    }
}

void playerStats::UpdateLabels(const baseStats &stats) {
    if (PlayerStrength != stats.strength) {
        PlayerStrength = stats.strength;
        if (P_Strength) {
            P_Strength->setText("Strength: " + std::to_string(PlayerStrength));
        }
    }
    if (PlayerDexterity != stats.dexterity) {
        PlayerDexterity = stats.dexterity;
        if (P_Dexterity) {
            P_Dexterity->setText("Dexterity: " + std::to_string(PlayerDexterity));
        }
    }
    if (PlayerIntelligence != stats.intelligence) {
        PlayerIntelligence = stats.intelligence;
        if (P_Intelligence) {
            P_Intelligence->setText("Intelligence: " + std::to_string(PlayerIntelligence));
        }
    }
    if (PlayerEndurance != stats.endurance) {
        PlayerEndurance = stats.endurance;
        if (P_Endurance) {
            P_Endurance->setText("Endurance: " + std::to_string(PlayerEndurance));
        }
    }
    if (PlayerLuck != stats.luck) {
        PlayerLuck = stats.luck;
        if (P_Luck) {
            P_Luck->setText("Luck: " + std::to_string(PlayerLuck));
        }
    }
    if (PlayerCharisma != stats.charisma) {
        PlayerCharisma = stats.charisma;
        if (P_Charisma) {
            P_Charisma->setText("Charisma: " + std::to_string(PlayerCharisma));
        }
    }
    if (PlayerVitality != stats.vitality) {
        PlayerVitality = stats.vitality;
        if (P_Vitality) {
            P_Vitality->setText("Vitality: " + std::to_string(PlayerVitality));
        }
    }
    if (PlayerPointsToSpend != stats.points) {
        PlayerPointsToSpend = stats.points;
        if (P_PointsToSpend) {
            P_PointsToSpend->setText("Points to Spend: " + std::to_string(PlayerPointsToSpend));
        }
    }
}

void playerStats::UpdateTextSizes(float width, float height) {
    unsigned int newTextSize = static_cast<unsigned int>(height * 0.03f);
    float newWidgetWidth = width * 0.05f;
    float newWidgetHeight = height * 0.05f;

    if (newTextSize == cachedTextSize && newWidgetWidth == cachedWidgetWidth && newWidgetHeight == cachedWidgetHeight) {
        return; // No changes needed
    }

    for (auto& LabelsTextSize: Labels_All) {
        //if (AllWidgetsXD) {
        LabelsTextSize->setTextSize(newTextSize);
        //}
    }
    cachedTextSize = newTextSize;
    cachedWidgetWidth = newWidgetWidth;
    cachedWidgetHeight = newWidgetHeight;
}
