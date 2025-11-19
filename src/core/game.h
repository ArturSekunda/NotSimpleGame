
#ifndef NOTSIMPLEGAME_GAME_H
#define NOTSIMPLEGAME_GAME_H

#include "entities/player/player.h"
#include "entities/enemies/basicEnemy.h"
#include "managers/itemManager.h"
#include "entities/projectile/projectileEntity.h"
#include "TGUI/Backend/SFML-Graphics.hpp"
#include "managers/UIManager.h"



namespace sf {
    class View;
    class RenderWindow;
}

class UIManager;
class itemManager;

class game {
public:
    void Updater();

public:
    game() = default;
    ~game() = default;

public: // Initialization and Getters

    void initializeEntities();

    // Const version to only read player
    const player& getPlayerPtr() const;

    // Non-const version to modify player
    player& getPlayerPtr();

    sf::Shape &getPlayerShape();

    UIManager* getUIManager() {
        return UIManagerInstance.get();
    }


    bool DeveloperMode = true;


    // Getters for collision boxes
    sf::RectangleShape& getPlayerCollisionBox() {
        return *getPlayerPtr().getCollisionBox();
    }

    // Delta Time Setter
    void setDeltaTime(float dt) {
        this->DeltaTime = dt;
    }
public: // Enemy Management

    template<typename T>
    void addEntityIDToList(const std::shared_ptr<T>& entity) {
        entityIDList.push_back(entity->getEntityID());
    }

    void addEntity(std::unique_ptr<baseEntity> entity) {
        entityList.push_back(std::move(entity));
    }

    template<typename T>
void addEntityToList(std::unique_ptr<T> entity) {
        static_assert(std::is_base_of_v<baseEntity, T>, "T must inherit from baseEntity");

        if constexpr (std::is_same_v<T, player>) {
            static int playerID = 0;
            entity->setEntityID(EntityType::PLAYER, playerID++);
        } else if constexpr (std::is_same_v<T, basicEnemy>) {
            static int enemyID = 0;
            entity->setEntityID(EntityType::BASIC_ENEMY, enemyID++);
        }

        addEntity(std::move(entity));
    }

    void decreaseEnemyFromList(size_t index);

    size_t getEntityIDListSize() const { return entityIDList.size(); }

public: // Rendering
    void render(sf::RenderWindow &window, sf::View &view);
    void renderUI(tgui::SFML_GRAPHICS::Gui& gui);

protected: // Render Helpers

    void renderDebug(sf::RenderWindow& window);

    void renderPlayerAndEnemies(sf::RenderWindow& window) const;


protected: // Debug and instantiates

    float DeltaTime;

    std::vector<EntityID> entityIDList;

    std::vector<std::unique_ptr<baseEntity>> entityList;

    std::unique_ptr<player> playerInstance;

    std::unique_ptr<UIManager> UIManagerInstance;

    std::unique_ptr<itemManager> itemManagerInstance;

    std::vector<std::unique_ptr<projectileEntity>> projectiles;

};


#endif //NOTSIMPLEGAME_GAME_H