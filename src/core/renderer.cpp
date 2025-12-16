#include "core/renderer.h"

#include "entities/player/player.h"
#include "entities/projectile/projectileEntity.h"
#include "handlers/collisionHandler.h"
#include <memory>

#include "entities/enemies/basicEnemy.h"

renderer::renderer() {
    UIManagerInstance = std::make_unique<UIManager>();
}

void renderer::render(sf::RenderWindow &window, sf::View &view, player &playerInstance, bool DeveloperMode, std::vector<std::unique_ptr<
                      projectileEntity>> &projectiles, std::vector<std::unique_ptr<basicEnemy>> &entityList) {

    currentView = &view;

    // Camera Follow Player
    view.setCenter(playerInstance.getPosition());
    window.setView(view);

    renderPlayerAndEnemies(window, playerInstance, entityList);

    projectileEntity::drawProjectiles(window, projectiles);

    if (DeveloperMode) {
        renderDebug(window, *playerInstance.getCollisionBox(), *playerInstance.getEntityShape(), entityList, projectiles);
    }


}

void renderer::renderDebug(sf::RenderWindow &window, sf::RectangleShape &playerCollisionBox, sf::Shape &playerShape, const std::vector<std::
                           unique_ptr<basicEnemy>>& entityList, std::vector<std::unique_ptr<projectileEntity>> &projectiles) {

    if (UIManagerInstance->getDebugWindow() != nullptr){
        if (UIManagerInstance->getWantToShowCollisionBoxes()) {
            collisionHandler::getInstance().render(window, playerCollisionBox, entityList, playerShape);
            collisionHandler::getInstance().renderProjectileCollisionBox(window, projectiles);
        }
    }


}

void renderer::renderPlayerAndEnemies(sf::RenderWindow& window, player& playerInstance, std::vector<std::unique_ptr<basicEnemy>>& entityList) const {
    // Render player
    if (playerInstance.getEntityShape()) {
        window.draw(*playerInstance.getEntityShape());
    }

    // Render enemies
    for (const auto& entity : entityList) {
        if (entity && entity->getEntityShape()) {
            window.draw(*entity->getEntityShape());
        }
    }
}

void renderer::renderUI(tgui::Gui &gui, bool& DeveloperMode, player& playerPointer) {
    UIManagerInstance->RenderMainGameHUD(gui, playerPointer, DeveloperMode);

}