//
// Created by Artur on 7.10.2025.
//

#include "playerChangeStatsDebugWindow.h"

#include "managers/statsManager.h"

void playerChangeStatsDebugWindow::initializePlayerChangeStats(tgui::Grid::Ptr Grid) {
    initializeLabels(Grid);
    initializeEditBoxes(Grid);
    initializeButtons(Grid);

    // Set up the grid layout
    int i = 0;
    for (auto& newclmap: Labels) {
        Grid->setWidgetCell(newclmap, i++, 0);
    }
    i = 0;
    for (auto& newclmap: EditBoxes) {
        Grid->setWidgetCell(newclmap, i++, 1);
    }
    i = 0;
    for (auto& newclmap: Buttons) {
        Grid->setWidgetCell(newclmap, i++, 2);
    }

    AllWidgets.insert(AllWidgets.end(), Labels.begin(), Labels.end());
    AllWidgets.insert(AllWidgets.end(), Buttons.begin(), Buttons.end());


}

void playerChangeStatsDebugWindow::initializeLabels(tgui::Grid::Ptr Grid) {
    Label_Strength = tgui::Label::create();
    Label_Dexterity = tgui::Label::create();
    Label_Intelligence = tgui::Label::create();
    Label_Endurance = tgui::Label::create();
    Label_Luck = tgui::Label::create();
    Label_Charisma = tgui::Label::create();
    Label_Vitality = tgui::Label::create();
    Label_Points = tgui::Label::create();

    if (!Label_Strength || !Label_Dexterity || !Label_Intelligence || !Label_Endurance || !Label_Luck || !Label_Charisma || !Label_Vitality || !Label_Points) {
        throw std::runtime_error("Failed to create labels for player change stats");
    }
    Labels = {
        Label_Strength,
        Label_Dexterity,
        Label_Intelligence,
        Label_Endurance,
        Label_Luck,
        Label_Charisma,
        Label_Vitality,
        Label_Points
    };

    for (auto& newclmap: Labels) {
        newclmap->getRenderer()->setTextColor(tgui::Color::White);
        Grid->add(newclmap);
    }
}

void playerChangeStatsDebugWindow::initializeEditBoxes(tgui::Grid::Ptr Grid) {
    EditBox_Dexterity = tgui::EditBox::create();
    EditBox_Strength = tgui::EditBox::create();
    EditBox_Intelligence = tgui::EditBox::create();
    EditBox_Endurance = tgui::EditBox::create();
    EditBox_Luck = tgui::EditBox::create();
    EditBox_Charisma = tgui::EditBox::create();
    EditBox_Vitality = tgui::EditBox::create();
    EditBox_Points = tgui::EditBox::create();

    if (!EditBox_Strength || !EditBox_Dexterity || !EditBox_Intelligence || !EditBox_Endurance || !EditBox_Luck || !EditBox_Charisma || !EditBox_Vitality || !EditBox_Points) {
        throw std::runtime_error("Failed to create edit boxes for player change stats");
    }
    EditBoxes = {
        EditBox_Strength,
        EditBox_Dexterity,
        EditBox_Intelligence,
        EditBox_Endurance,
        EditBox_Luck,
        EditBox_Charisma,
        EditBox_Vitality,
        EditBox_Points
    };
    for (auto& newclmap: EditBoxes) {
        newclmap->setInputValidator(tgui::EditBox::Validator::Int);
        newclmap->getRenderer()->setTextColor(tgui::Color::White);
        newclmap->getRenderer()->setBackgroundColor(tgui::Color(50, 50, 50, 200));
        Grid->add(newclmap);
    }
}

void playerChangeStatsDebugWindow::initializeButtons(tgui::Grid::Ptr Grid) {

    Button_Dexterity = tgui::Button::create();
    Button_Strength = tgui::Button::create();
    Button_Intelligence = tgui::Button::create();
    Button_Endurance = tgui::Button::create();
    Button_Luck = tgui::Button::create();
    Button_Charisma = tgui::Button::create();
    Button_Vitality = tgui::Button::create();
    Button_Points = tgui::Button::create();

    if (!Button_Strength || !Button_Dexterity || !Button_Intelligence || !Button_Endurance || !Button_Luck || !Button_Charisma || !Button_Vitality || !Button_Points) {
        throw std::runtime_error("Failed to create buttons for player change stats");
    }

    Buttons = {
        Button_Strength,
        Button_Dexterity,
        Button_Intelligence,
        Button_Endurance,
        Button_Luck,
        Button_Charisma,
        Button_Vitality,
        Button_Points
    };


    for (auto& newclmap: Buttons) {
        newclmap->setText("Set");
        newclmap->getRenderer()->setTextColor(tgui::Color::White);
        newclmap->getRenderer()->setBackgroundColor(tgui::Color(50, 50, 50, 200));
        Grid->add(newclmap);
    }
}

void playerChangeStatsDebugWindow::UpdateSizes(float width, float height) {
    unsigned int newTextSize = static_cast<unsigned int>(height * 0.05f);
    float newWidgetWidth = width * 0.05f;
    float newWidgetHeight = height * 0.05f;

    if (newTextSize == cachedTextSize && newWidgetWidth == cachedWidgetWidth && newWidgetHeight == cachedWidgetHeight) {
        return; // No changes needed
    }

    for (auto& AllWidgetsXD: AllWidgets) {
        //if (AllWidgetsXD) {
            AllWidgetsXD->setTextSize(static_cast<unsigned int>(height * 0.05f));
        //}
    }
    for (auto& EditBoxesXD: EditBoxes) {
        //if (EditBoxesXD) {
            EditBoxesXD->setSize(width * 0.05f, height * 0.05f);
        //}
    }
    cachedTextSize = newTextSize;
    cachedWidgetWidth = newWidgetWidth;
    cachedWidgetHeight = newWidgetHeight;
}

void playerChangeStatsDebugWindow::UpdateTextInfo(const baseStats& stats) {

    if (Label_Strength && stats.strength != Strength) {
        Strength = stats.strength;
        Label_Strength->setText("Strength: " + std::to_string(Strength));
    }
    if (Label_Dexterity && stats.dexterity != Dexterity) {
        Dexterity = stats.dexterity;
        Label_Dexterity->setText("Dexterity: " + std::to_string(Dexterity));
    }
    if (Label_Intelligence && stats.intelligence != Intelligence) {
        Intelligence = stats.intelligence;
        Label_Intelligence->setText("Intelligence: " + std::to_string(Intelligence));
    }
    if (Label_Endurance && stats.endurance != Endurance) {
        Endurance = stats.endurance;
        Label_Endurance->setText("Endurance: " + std::to_string(Endurance));
    }
    if (Label_Luck && stats.luck != Luck) {
        Luck = stats.luck;
        Label_Luck->setText("Luck: " + std::to_string(Luck));
    }
    if (Label_Charisma && stats.charisma != Charisma) {
        Charisma = stats.charisma;
        Label_Charisma->setText("Charisma: " + std::to_string(Charisma));
    }
    if (Label_Vitality && stats.vitality != Vitality) {
        Vitality = stats.vitality;
        Label_Vitality->setText("Vitality: " + std::to_string(Vitality));
    }
    if (Label_Points && stats.points != Points) {
        Points = stats.points;
        Label_Points->setText("Points: " + std::to_string(Points));
    }
}

void playerChangeStatsDebugWindow::HandleButtonClicks(baseStats& playerStats) {
    Button_Strength->onClick([&playerStats, this] {
        if (EditBox_Strength->getText().empty()) {
            EditBox_Strength->setText("ERROR");
            return;
        }

        playerStats.setStrength(EditBox_Strength->getText().toInt());
    });
    Button_Dexterity->onClick([&playerStats, this] {
        if (EditBox_Dexterity->getText().empty()) {
            EditBox_Dexterity->setText("ERROR");
            return;
        }

        playerStats.setDexterity(EditBox_Dexterity->getText().toInt());
    });
    Button_Intelligence->onClick([&playerStats, this] {
        if (EditBox_Intelligence->getText().empty()) {
            EditBox_Intelligence->setText("ERROR");
            return;
        }
        playerStats.setIntelligence(EditBox_Intelligence->getText().toInt());
        });
    Button_Endurance->onClick([&playerStats, this] {
        if (EditBox_Endurance->getText().empty()) {
            EditBox_Endurance->setText("ERROR");
            return;
        }
        playerStats.setEndurance(EditBox_Endurance->getText().toInt());
    });
    Button_Luck->onClick([&playerStats, this] {
        if (EditBox_Luck->getText().empty()) {
            EditBox_Luck->setText("ERROR");
            return;
        }
        playerStats.setLuck(EditBox_Luck->getText().toInt());
    });
    Button_Charisma->onClick([&playerStats, this] {
        if (EditBox_Charisma->getText().empty()) {
            EditBox_Charisma->setText("ERROR");
            return;
        }
        playerStats.setCharisma(EditBox_Charisma->getText().toInt());
    });
    Button_Vitality->onClick([&playerStats, this] {
        if (EditBox_Vitality->getText().empty()) {
            EditBox_Vitality->setText("ERROR");
            return;
        }
        playerStats.setVitality(EditBox_Vitality->getText().toInt());
    });
    Button_Points->onClick([&playerStats, this] {
        if (EditBox_Points->getText().empty()) {
            EditBox_Points->setText("ERROR");
            return;
        }
        playerStats.addPoints(EditBox_Points->getText().toInt());
    });
}