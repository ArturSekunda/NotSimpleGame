

#include "playerChangeNormalStatsDebugWindow.h"

#include "handlers/debugHandler.h"

void playerChangeNormalStatsDebugWindow::CleanUp() {
    P_IsAlive = nullptr;
    P_Health = nullptr;
    P_Defense = nullptr;
    P_Speed = nullptr;
    P_Mana = nullptr;
    P_Level = nullptr;
    P_EXP = nullptr;

    EditBox_SetHealth = nullptr;
    EditBox_SetMana = nullptr;
    EditBox_SetLevel = nullptr;
    EditBox_SetEXP = nullptr;
    EditBox_SetIsAlive = nullptr;

    Button_SetHealth = nullptr;
    Button_SetMana = nullptr;
    Button_SetLevel = nullptr;
    Button_SetEXP = nullptr;
    Button_SetIsAlive = nullptr;

    AllWidgets.clear();
    Labels.clear();
    EditBoxes.clear();
    Buttons.clear();
}

void playerChangeNormalStatsDebugWindow::initializePlayerChangeNormalStats(tgui::Grid::Ptr Grid) {

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

void playerChangeNormalStatsDebugWindow::initializeLabels(tgui::Grid::Ptr Grid) {

    P_IsAlive = tgui::Label::create();
    P_Health = tgui::Label::create();
    P_Mana = tgui::Label::create();
    P_Level = tgui::Label::create();
    P_EXP = tgui::Label::create();
    P_Defense = tgui::Label::create();
    P_Speed = tgui::Label::create();

    if (!P_IsAlive || !P_Health || !P_Defense || !P_Speed || !P_Mana || !P_Level || !P_EXP) {
        throw std::runtime_error("Failed to create labels for player change normal stats");
    }

    Labels = {
        P_Health,
        P_Mana,
        P_Level,
        P_EXP,
        P_IsAlive,
        P_Defense,
        P_Speed,
    };

    for (auto& newclmap: Labels) {
        newclmap->getRenderer()->setTextColor(tgui::Color::White);
        Grid->add(newclmap);
    }
}

void playerChangeNormalStatsDebugWindow::initializeEditBoxes(tgui::Grid::Ptr Grid) {

    EditBox_SetHealth = tgui::EditBox::create();
    EditBox_SetMana = tgui::EditBox::create();
    EditBox_SetLevel = tgui::EditBox::create();
    EditBox_SetEXP = tgui::EditBox::create();
    EditBox_SetDefense = tgui::EditBox::create();
    EditBox_SetSpeed = tgui::EditBox::create();
    EditBox_SetIsAlive = tgui::EditBox::create();

    if (!EditBox_SetHealth || !EditBox_SetMana || !EditBox_SetLevel || !EditBox_SetEXP || !EditBox_SetIsAlive || !EditBox_SetDefense || !EditBox_SetSpeed) {
        throw std::runtime_error("Failed to create edit boxes for player change normal stats");
    }

    EditBoxes = {
        EditBox_SetHealth,
        EditBox_SetMana,
        EditBox_SetLevel,
        EditBox_SetEXP,
        EditBox_SetIsAlive,
        EditBox_SetDefense,
        EditBox_SetSpeed
    };

    for (auto& newclmap: EditBoxes) {
        newclmap->setInputValidator(tgui::EditBox::Validator::Int);
        newclmap->getRenderer()->setTextColor(tgui::Color::White);
        newclmap->getRenderer()->setBackgroundColor(tgui::Color(50, 50, 50, 200));
        Grid->add(newclmap);
    }
}

void playerChangeNormalStatsDebugWindow::initializeButtons(tgui::Grid::Ptr Grid) {

    Button_SetHealth = tgui::Button::create();
    Button_SetMana = tgui::Button::create();
    Button_SetLevel = tgui::Button::create();
    Button_SetEXP = tgui::Button::create();
    Button_SetIsAlive = tgui::Button::create();
    Button_SetDefense = tgui::Button::create();
    Button_SetSpeed = tgui::Button::create();

    if (!Button_SetHealth || !Button_SetMana || !Button_SetLevel || !Button_SetEXP || !Button_SetIsAlive || !Button_SetDefense || !Button_SetSpeed) {
        throw std::runtime_error("Failed to create buttons for player change normal stats");
    }

    Buttons = {
        Button_SetHealth,
        Button_SetMana,
        Button_SetLevel,
        Button_SetEXP,
        Button_SetIsAlive,
        Button_SetDefense,
        Button_SetSpeed
    };

    for (auto& newclmap: Buttons) {
        newclmap->setText("Set");
        newclmap->getRenderer()->setTextColor(tgui::Color::White);
        newclmap->getRenderer()->setBackgroundColor(tgui::Color(50, 50, 50, 200));
        Grid->add(newclmap);
    }

}

void playerChangeNormalStatsDebugWindow::UpdateSizes(float width, float height) {
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

void playerChangeNormalStatsDebugWindow::UpdateTextInfo(bool IsAlive, float Health, float Defense, float Speed, int Mana, int Level, float EXP) {

    if (P_IsAlive && IsAlive != cachedIsAlive) {
        cachedIsAlive = IsAlive;
        P_IsAlive->setText("Is Alive: " + std::string(IsAlive ? "True" : "False"));
    }
    if (P_Health && Health != cachedHealth) {
        cachedHealth = Health;
        P_Health->setText("Health: " + std::to_string(static_cast<int>(Health)));
    }
    if (P_Defense && Defense != cachedDefense) {
        cachedDefense = Defense;
        P_Defense->setText("Defense: " + std::to_string(static_cast<int>(Defense)));
    }
    if (P_Speed && Speed != cachedSpeed) {
        cachedSpeed = Speed;
        P_Speed->setText("Speed: " + std::to_string(static_cast<int>(Speed)));
    }
    if (P_Mana && Mana != cachedMana) {
        cachedMana = Mana;
        P_Mana->setText("Mana: " + std::to_string(Mana));
    }
    if (P_Level && Level != cachedLevel) {
        cachedLevel = Level;
        P_Level->setText("Level: " + std::to_string(Level));
    }
    if (P_EXP && EXP != cachedEXP) {
        cachedEXP = EXP;
        P_EXP->setText("EXP: " + std::to_string(EXP));
    }
}

void playerChangeNormalStatsDebugWindow::HandleButtonClicks(debugHandler &debugHandlerInstance) {
    Button_SetHealth->onClick([this, &debugHandlerInstance] {
       if (EditBox_SetHealth->getText().empty()) {
           return;
       }

        debugHandlerInstance.setPlayerHealth(EditBox_SetHealth->getText().toFloat());
    });
    Button_SetMana->onClick([this, &debugHandlerInstance] {
       if (EditBox_SetMana->getText().empty()) {
           return;
       }

        debugHandlerInstance.setPlayerMana(EditBox_SetMana->getText().toInt());
    });
    Button_SetLevel->onClick([this, &debugHandlerInstance] {
        if (EditBox_SetLevel->getText().empty()) {
            return;
        }

        debugHandlerInstance.setPlayerLevel(EditBox_SetLevel->getText().toInt());
    });
    Button_SetEXP->onClick([this, &debugHandlerInstance] {
        if (EditBox_SetEXP->getText().empty()) {
            return;
        }

        debugHandlerInstance.setPlayerEXP(EditBox_SetEXP->getText().toFloat());
    });
    Button_SetIsAlive->onClick([this, &debugHandlerInstance] {
        if (EditBox_SetIsAlive->getText().empty()) {
            return;
        }

        int num = EditBox_SetIsAlive->getText().toInt();

        switch (num) {
            case 0:
                debugHandlerInstance.setIsPlayerAlive(false);
                break;
            case 1:
                debugHandlerInstance.setIsPlayerAlive(true);
                break;
            default:
                EditBox_SetIsAlive->setText("ERROR");
                break;
        }
    });
    Button_SetDefense->onClick([this, &debugHandlerInstance] {
        if (EditBox_SetDefense->getText().empty()) {
            return;
        }

        debugHandlerInstance.setPlayerDefense(EditBox_SetDefense->getText().toFloat());
    });
    Button_SetSpeed->onClick([this, &debugHandlerInstance] {
        if (EditBox_SetSpeed->getText().empty()) {
            return;
        }
        debugHandlerInstance.setPlayerSpeed(EditBox_SetSpeed->getText().toFloat());
    });
}