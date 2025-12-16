#ifndef NOTSIMPLEGAME_RENDERER_H
#define NOTSIMPLEGAME_RENDERER_H

#include <SFML/Graphics/RenderWindow.hpp>

#include "entities/projectile/projectileEntity.h"
#include "TGUI/Backend/SFML-Graphics.hpp"
#include "managers/UIManager.h"

class basicEnemy;
class UIManager;

class renderer {
    sf::View* currentView = nullptr;

    std::unique_ptr<UIManager> UIManagerInstance;

public:
    renderer();
    ~renderer() = default;

    void renderDebug(sf::RenderWindow &window, sf::RectangleShape &playerCollisionBox, sf::Shape &playerShape, const std::vector<std::
                     unique_ptr<basicEnemy>> &entityList, std::vector<std::unique_ptr<projectileEntity>> &projectiles);

    void renderPlayerAndEnemies(sf::RenderWindow &window, player &playerInstance, std::vector<std::unique_ptr<basicEnemy>>& entityList) const;

    void render(sf::RenderWindow &window, sf::View &view, player &playerInstance, bool DeveloperMode, std::vector<std::unique_ptr<
                projectileEntity>> &projectiles, std::vector<std::unique_ptr<basicEnemy>> &entityList);

    void renderUI(tgui::SFML_GRAPHICS::Gui &gui, bool &DeveloperMode, player &playerPointer);

    UIManager& getUIManager() {
        return *UIManagerInstance;
    }

    bool hasView() const {
        if (currentView) {
            return true;
        }
        return false;
    }

    sf::View& getView() {
        return *currentView;
    }



};


#endif //NOTSIMPLEGAME_RENDERER_H