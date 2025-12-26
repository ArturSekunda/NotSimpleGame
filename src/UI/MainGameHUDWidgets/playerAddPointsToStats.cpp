#include "playerAddPointsToStats.h"

#include "entities/helpers/entityStructs.h"

void playerAddPointsToStats::initializeWindow(tgui::Gui& gui, player& player) {

    Stats_Window = tgui::ChildWindow::create("Player's statistics");

    if (!Stats_Window) {
        throw std::runtime_error("Failed to create player stats window");
    }

    Stats_Window->setSize("30%", "40%");
    Stats_Window->setPosition("35%", "30%");
    Stats_Window->setVisible(false);
    Stats_Window->setResizable(false);
    Stats_Window->getRenderer()->setBackgroundColor(tgui::Color(70, 70, 70, 220));
    Stats_Window->getRenderer()->setBorderColor(tgui::Color(0, 0, 0, 200));
    Stats_Window->getRenderer()->setBorders(2);
    Stats_Window->onClosing([this](bool* abort) {
        Stats_Window->setVisible(false);
        *abort = true;
    });

    initializePanel();
    initializeSegregator();
    initializeLabels();
    initializeButtons();

    int i = 0;
    for (auto& AddLabelsToSegregator: Labels) {
        Segregator->setWidgetCell(AddLabelsToSegregator,i,0);
        i++;
    }
    i = 0;
    for (auto& AddButtonsToSegregator: Buttons) {
        Segregator->setWidgetCell(AddButtonsToSegregator,i,1);
        i++;
    }



    gui.add(Stats_Window);


}

void playerAddPointsToStats::initializeOpenerButton(const tgui::Panel::Ptr& parentPanel) {
    Opener_button = tgui::Button::create("Stats");
    if (!Opener_button) {
        throw std::runtime_error("Failed to create player stats opener button");
    }

    Opener_button->setSize("30%", "20%");
    Opener_button->setPosition("5%", "80%");
    Opener_button->getRenderer()->setTextColor(tgui::Color::White);
    Opener_button->getRenderer()->setBackgroundColor(tgui::Color(70, 70, 70, 220));
    Opener_button->getRenderer()->setBorders(2);
    Opener_button->getRenderer()->setBorderColor(tgui::Color(0, 0, 0, 200));

    parentPanel->add(Opener_button);

    Opener_button->onClick([this]() {
        if (Stats_Window) {
            bool isVisible = Stats_Window->isVisible();
            Stats_Window->setVisible(!isVisible);
        }
    });
}

void playerAddPointsToStats::initializeSegregator() {
    Segregator = tgui::Grid::create();
    if (!Segregator) {
        throw std::runtime_error("Failed to create player stats segregator grid");
    }
    Segregator->setSize("100%", "100%");
    Segregator->setPosition("0%", "0%");
    Stats_Panel->add(Segregator);
}

void playerAddPointsToStats::initializePanel() {
    Stats_Panel = tgui::Panel::create();
    if (!Stats_Panel) {
        throw std::runtime_error("Failed to create player stats panel");
    }
    Stats_Panel->setSize("100%", "100%");
    Stats_Panel->setPosition("0%", "0%");
    Stats_Panel->getRenderer()->setBackgroundColor(tgui::Color(50, 50, 50, 200));
    Stats_Window->add(Stats_Panel);
}

void playerAddPointsToStats::initializeLabels() {
    Label_Strength = tgui::Label::create();
    Label_Dexterity = tgui::Label::create();
    Label_Intelligence = tgui::Label::create();
    Label_Endurance = tgui::Label::create();
    Label_Luck = tgui::Label::create();
    Label_Charisma = tgui::Label::create();
    Label_Vitality = tgui::Label::create();
    if (!Label_Strength || !Label_Dexterity || !Label_Intelligence || !Label_Endurance || !Label_Luck || !Label_Charisma || !Label_Vitality) {
        throw std::runtime_error("Failed to create labels for player stats");
    }

    Label_Strength->setText("Strength: " + std::to_string(Strength));
    Label_Dexterity->setText("Dexterity: " + std::to_string(Dexterity));
    Label_Intelligence->setText("Intelligence: " + std::to_string(Intelligence));
    Label_Endurance->setText("Endurance: " + std::to_string(Endurance));
    Label_Luck->setText("Luck: " + std::to_string(Luck));
    Label_Charisma->setText("Charisma: " + std::to_string(Charisma));
    Label_Vitality->setText("Vitality: " + std::to_string(Vitality));

    Labels = {
        Label_Strength,
        Label_Dexterity,
        Label_Intelligence,
        Label_Endurance,
        Label_Luck,
        Label_Charisma,
        Label_Vitality
    };

    for (auto& newclmap: Labels) {
        newclmap->getRenderer()->setTextColor(tgui::Color::White);
        Segregator->add(newclmap);
    }
}

void playerAddPointsToStats::initializeButtons() {
    Button_Dexterity = tgui::Button::create();
    Button_Strength = tgui::Button::create();
    Button_Intelligence = tgui::Button::create();
    Button_Endurance = tgui::Button::create();
    Button_Luck = tgui::Button::create();
    Button_Charisma = tgui::Button::create();
    Button_Vitality = tgui::Button::create();

    if (!Button_Strength || !Button_Dexterity || !Button_Intelligence || !Button_Endurance || !Button_Luck || !Button_Charisma || !Button_Vitality) {
        throw std::runtime_error("Failed to create buttons for player stats");
    }

    Buttons = {
        Button_Strength,
        Button_Dexterity,
        Button_Intelligence,
        Button_Endurance,
        Button_Luck,
        Button_Charisma,
        Button_Vitality
    };

    for (auto& newclmap: Buttons) {
        newclmap->setText("Add Point");
        newclmap->getRenderer()->setTextColor(tgui::Color(tgui::Color::Black));
        Segregator->add(newclmap);
    }
}

void playerAddPointsToStats::UpdateSizes(float width, float height) {
    unsigned int newTextSize = static_cast<unsigned int>(height * 0.02f);
    float newWidgetWidth = width * 0.05f;
    float newWidgetHeight = height * 0.05f;

    for (auto& AllLabels: Labels) {
        AllLabels->setTextSize(newTextSize);
    }

    for (auto& AllButtons: Buttons) {
        AllButtons->setTextSize(newTextSize);
        AllButtons->setSize(newWidgetWidth, newWidgetHeight);
    }

    cachedTextSize = newTextSize;
    cachedWidgetWidth = newWidgetWidth;
    cachedWidgetHeight = newWidgetHeight;
}

void playerAddPointsToStats::UpdateTextInfo(const baseStats &stats) {

    if (stats.strength != Strength) {
        Strength = stats.strength;
        Label_Strength->setText("Strength: " + std::to_string(Strength));
    }
    if (stats.dexterity != Dexterity) {
        Dexterity = stats.dexterity;
        Label_Dexterity->setText("Dexterity: " + std::to_string(Dexterity));
    }
    if (stats.intelligence != Intelligence) {
        Intelligence = stats.intelligence;
        Label_Intelligence->setText("Intelligence: " + std::to_string(Intelligence));
    }
    if (stats.endurance != Endurance) {
        Endurance = stats.endurance;
        Label_Endurance->setText("Endurance: " + std::to_string(Endurance));
    }
    if (stats.luck != Luck) {
        Luck = stats.luck;
        Label_Luck->setText("Luck: " + std::to_string(Luck));
    }
    if (stats.charisma != Charisma) {
        Charisma = stats.charisma;
        Label_Charisma->setText("Charisma: " + std::to_string(Charisma));
    }
    if (stats.vitality != Vitality) {
        Vitality = stats.vitality;
        Label_Vitality->setText("Vitality: " + std::to_string(Vitality));
    }
}

void playerAddPointsToStats::HandleButtonClicks(baseStats &playerStats) {
    Button_Strength->onClick([&playerStats]() {
         playerStats.addStrength(1);
    });
    Button_Dexterity->onClick([&playerStats]() {
         playerStats.addDexterity(1);
    });
    Button_Intelligence->onClick([&playerStats]() {
         playerStats.addIntelligence(1);
    });
    Button_Endurance->onClick([&playerStats]() {
         playerStats.addEndurance(1);
    });
    Button_Luck->onClick([&playerStats]() {
         playerStats.addLuck(1);
    });
    Button_Charisma->onClick([&playerStats]() {
         playerStats.addCharisma(1);
    });
    Button_Vitality->onClick([&playerStats]() {
         playerStats.addVitality(1);
    });
}