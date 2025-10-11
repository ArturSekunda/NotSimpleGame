
#include "playerInfoLabelsDebugWindow.h"

#include "TGUI/Widgets/Grid.hpp"

// Initialize the labels for player information
void playerInfoLabelsDebugWindow::initializePlayerInfo_Normal(tgui::VerticalLayout::Ptr Layout) {

    // Create labels directly
    P_Name = tgui::Label::create();
    P_IsAlive = tgui::Label::create();
    P_Health = tgui::Label::create();
    P_Armor = tgui::Label::create();
    P_Speed = tgui::Label::create();
    P_Mana = tgui::Label::create();
    P_Level = tgui::Label::create();
    P_Experience = tgui::Label::create();
    P_EXP_MAX = tgui::Label::create();

    // Check if all labels were created successfully
    if (!P_Name || !P_IsAlive || !P_Health || !P_Armor || !P_Speed || !P_Mana || !P_Level || !P_Experience || !P_EXP_MAX) {
        throw std::runtime_error("Failed to create player info labels normal");
    }


    L_PInfo_Normal = {
        P_Name, P_IsAlive, P_Health, P_Armor, P_Speed, P_Mana, P_Level, P_Experience, P_EXP_MAX
    };


    // Set common properties for all labels
    for (const auto& label: L_PInfo_Normal) {
        label->getRenderer()->setTextColor(tgui::Color::White);
        Layout->add(label);
    }
}

// Initialize the labels for player skill stats
void playerInfoLabelsDebugWindow::initializePlayerInfo_SkillStats(tgui::Grid::Ptr Layout) {
    // Create labels directly
    P_Strength = tgui::Label::create();
    P_Dexterity = tgui::Label::create();
    P_Intelligence = tgui::Label::create();
    P_Endurance = tgui::Label::create();
    P_Luck = tgui::Label::create();
    P_Charisma = tgui::Label::create();
    P_Vitality = tgui::Label::create();
    P_Points = tgui::Label::create();

    if (!P_Strength || !P_Dexterity || !P_Intelligence || !P_Endurance || !P_Luck || !P_Charisma || !P_Vitality || !P_Points) {
        throw std::runtime_error("Failed to create player info labels skillstats");
    }

    L_PInfo_SkillStats = {
        P_Strength, P_Dexterity, P_Intelligence, P_Endurance
    };
    L_PInfo_SkillStats_2 = {
        P_Luck, P_Charisma, P_Vitality, P_Points
    };

    // Set common properties for all label
    int i = 0;
    int j = 0;
    for (const auto& label: L_PInfo_SkillStats) {
        label->getRenderer()->setTextColor(tgui::Color::White);
        Layout->add(label);
        Layout->setWidgetCell(label, i , 0);
        i++;
    }

    for (const auto& label: L_PInfo_SkillStats_2) {
        label->getRenderer()->setTextColor(tgui::Color::White);
        Layout->add(label);
        Layout->setWidgetCell(label, j , 1);
        j++;
    }


}

void playerInfoLabelsDebugWindow::UpdateTextSizes_SkillStats(float width, float height) {
    unsigned int newTextSize = static_cast<unsigned int>(height * 0.05f);

    if (newTextSize == cachedTextSize) {
        return;
    }

    for (const auto& label : All_PInfo_SkillStats) {
        if (label) {
            label->setTextSize(newTextSize);
        }
    }

    cachedTextSize = newTextSize;
}

void playerInfoLabelsDebugWindow::UpdateTextSizes_Normal(float width, float height) {
    unsigned int newTextSize = static_cast<unsigned int>(height * 0.05f);

    if (newTextSize == cachedTextSize) {
        return;
    }
    for (const auto& label : L_PInfo_Normal) {
        if (label) {
            label->setTextSize(newTextSize);
        }
    }
    cachedTextSize_Normal = newTextSize;
}

// Update the labels with player information
void playerInfoLabelsDebugWindow::updatePlayerInfo_Normal(const std::string &name, bool isAlive, int health, int armor,
    int speed, int mana, int level, float experience, float expMax) {

    // Update label texts with player information
    if (name.empty()) {
        P_Name->setText("Name: N/A");
    } else if (name != PlayerName) {
        PlayerName = name;
        P_Name->setText("Name: " + name);
    }
    if (isAlive != PlayerIsAlive) {
        PlayerIsAlive = isAlive;
        P_IsAlive->setText("Is Alive: " + std::string(isAlive ? "True" : "False"));
    }
    if (health != PlayerHealth) {
        PlayerHealth = health;
        P_Health->setText("Health: " + std::to_string(health));
    }
    if (armor != PlayerArmor) {
        PlayerArmor = armor;
        P_Armor->setText("Armor: " + std::to_string(armor));
    }
    if (speed != PlayerSpeed) {
        PlayerSpeed = speed;
        P_Speed->setText("Speed: " + std::to_string(speed));
    }
    if (mana != PlayerMana) {
        PlayerMana = mana;
        P_Mana->setText("Mana: " + std::to_string(mana));
    }
    if (level != PlayerLevel) {
        PlayerLevel = level;
        P_Level->setText("Level: " + std::to_string(level));
    }
    if (experience != PlayerExperience) {
        PlayerExperience = experience;
        P_Experience->setText("Experience: " + std::to_string(experience));
    }
    if (expMax != PlayerEXP_MAX) {
        PlayerEXP_MAX = expMax;
        P_EXP_MAX->setText("EXP MAX: " + std::to_string(expMax));
    }
}

// Update the labels with player skill stats
void playerInfoLabelsDebugWindow::updatePlayerInfo_SkillStats(int strength, int dexterity, int intelligence,
    int endurance, int luck, int charisma, int vitality, int points) {
    if (strength != PlayerStrength) {
        PlayerStrength = strength;
        P_Strength->setText("Strength: " + std::to_string(strength));
    }
    if (dexterity != PlayerDexterity) {
        PlayerDexterity = dexterity;
        P_Dexterity->setText("Dexterity: " + std::to_string(dexterity));
    }
    if (intelligence != PlayerIntelligence) {
        PlayerIntelligence = intelligence;
        P_Intelligence->setText("Intelligence: " + std::to_string(intelligence));
    }
    if (endurance != PlayerEndurance) {
        PlayerEndurance = endurance;
        P_Endurance->setText("Endurance: " + std::to_string(endurance));
    }
    if (luck != PlayerLuck) {
        PlayerLuck = luck;
        P_Luck->setText("Luck: " + std::to_string(luck));
    }
    if (charisma != PlayerCharisma) {
        PlayerCharisma = charisma;
        P_Charisma->setText("Charisma: " + std::to_string(charisma));
    }
    if (vitality != PlayerVitality) {
        PlayerVitality = vitality;
        P_Vitality->setText("Vitality: " + std::to_string(vitality));
    }
    if (points != PlayerPoints) {
        PlayerPoints = points;
        P_Points->setText("Points: " + std::to_string(points));
    }

}