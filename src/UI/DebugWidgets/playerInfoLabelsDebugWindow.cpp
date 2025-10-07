//
// Created by Artur on 6.10.2025.
//

#include "playerInfoLabelsDebugWindow.h"

// Initialize the labels for player information
void playerInfoLabelsDebugWindow::initializePlayerInfo_Normal(tgui::VerticalLayout &Layout) {

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
        Layout.add(label);
    }
}

// Initialize the labels for player skill stats
void playerInfoLabelsDebugWindow::initializePlayerInfo_SkillStats(tgui::VerticalLayout &Layout) {

    // Create labels directly
    P_Strength = tgui::Label::create();
    P_Dexterity = tgui::Label::create();
    P_Intelligence = tgui::Label::create();
    P_Endurance = tgui::Label::create();

    if (!P_Strength || !P_Dexterity || !P_Intelligence || !P_Endurance) {
        throw std::runtime_error("Failed to create player info labels skillstats");
    }

    L_PInfo_SkillStats = {
        P_Strength, P_Dexterity, P_Intelligence, P_Endurance
    };

    // Set common properties for all labels
    for (const auto& label: L_PInfo_SkillStats) {
        label->getRenderer()->setTextColor(tgui::Color::White);
        Layout.add(label);
    }


}

void playerInfoLabelsDebugWindow::initializePlayerInfo_SkillStats_2(tgui::VerticalLayout &Layout) {

    // Create labels directly
    P_Luck = tgui::Label::create();
    P_Charisma = tgui::Label::create();
    P_Vitality = tgui::Label::create();
    P_Points = tgui::Label::create();

    if (!P_Luck || !P_Charisma || !P_Vitality || !P_Points) {
        throw std::runtime_error("Failed to create player info labels skillstats 2");
    }

    L_PInfo_SkillStats_2 = {
        P_Luck, P_Charisma, P_Vitality, P_Points
    };

    // Set common properties for all labels
    for (const auto& label: L_PInfo_SkillStats_2) {
        label->getRenderer()->setTextColor(tgui::Color::White);
        Layout.add(label);
    }

}

void playerInfoLabelsDebugWindow::UpdateTextSizes(float width, float height) {

     std::vector<tgui::Label::Ptr> All_PInfo_Normal = L_PInfo_Normal;

    All_PInfo_Normal.insert(All_PInfo_Normal.end(), L_PInfo_SkillStats.begin(), L_PInfo_SkillStats.end());
    All_PInfo_Normal.insert(All_PInfo_Normal.end(), L_PInfo_SkillStats_2.begin(), L_PInfo_SkillStats_2.end());

    // Somehow it works XD

    for (const auto& Labels: All_PInfo_Normal) {
        if (Labels) {
            Labels->setTextSize(static_cast<unsigned int>(height * 0.03f));
        }
    }
}

// Update the labels with player information
void playerInfoLabelsDebugWindow::updatePlayerInfo_Normal(const std::string &name, bool isAlive, int health, int armor,
    int speed, int mana, int level, float experience, float expMax) {

    // Update label texts with player information
    P_Name->setText("Name: " + name);
    P_IsAlive->setText("Is Alive: " + std::string(isAlive ? "Yes" : "No"));
    P_Health->setText("Health: " + std::to_string(health));
    P_Armor->setText("Armor: " + std::to_string(armor));
    P_Speed->setText("Speed: " + std::to_string(speed));
    P_Mana->setText("Mana: " + std::to_string(mana));
    P_Level->setText("Level: " + std::to_string(level));
    P_Experience->setText("Experience: " + std::to_string(experience));
    P_EXP_MAX->setText("EXP MAX: " + std::to_string(expMax));
}

// Update the labels with player skill stats
void playerInfoLabelsDebugWindow::updatePlayerInfo_SkillStats(int strength, int dexterity, int intelligence,
    int endurance) {
    P_Strength->setText("Strength: " + std::to_string(strength));
    P_Dexterity->setText("Dexterity: " + std::to_string(dexterity));
    P_Intelligence->setText("Intelligence: " + std::to_string(intelligence));
    P_Endurance->setText("Endurance: " + std::to_string(endurance));
}

void playerInfoLabelsDebugWindow::updatePlayerInfo_SkillStats_2(int luck, int charisma, int vitality, int points) {
    P_Luck->setText("Luck: " + std::to_string(luck));
    P_Charisma->setText("Charisma: " + std::to_string(charisma));
    P_Vitality->setText("Vitality: " + std::to_string(vitality));
    P_Points->setText("Points: " + std::to_string(points));
}
