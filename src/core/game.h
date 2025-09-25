
#ifndef NOTSIMPLEGAME_GAME_H
#define NOTSIMPLEGAME_GAME_H

#include "entities/player/player.h"
#include "entities/enemies/basicEnemy.h"
#include <SFML/Graphics.hpp>


class game {
public:
    void Updater();

public:
    game() = default;
    ~game() = default;

    static game& getInstance() {
        static game instance;
        return instance;
    }
public: // Initialization and Getters

    void initializeEntities();

    std::shared_ptr<player> getPlayerPtr();


    sf::Shape &getPlayerShape();

    // Getters for collision boxes
    sf::RectangleShape& getPlayerCollisionBox() {
        return *getPlayerPtr()->getCollisionBox();
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

    void addEntity(const std::shared_ptr<baseEntity>& entity) {
        entityList.push_back(entity);
    }

    template<typename T>
    void addEntityToList(const std::shared_ptr<T>& entity) {
        static_assert(std::is_base_of_v<baseEntity, T>, "T must inherit from baseEntity");

        if constexpr (std::is_same_v<T, player>) {
            static int playerID = 0;
            entity->setEntityID(EntityType::PLAYER, playerID++);
        } else if constexpr (std::is_same_v<T, basicEnemy>) {
            static int enemyID = 0;
            entity->setEntityID(EntityType::BASIC_ENEMY, enemyID++);
        }

        addEntity(entity);
    }

    void decreaseEnemyFromList(size_t index);

    size_t getEntityIDListSize() const { return entityIDList.size(); }

public: // Rendering
    void render(sf::RenderWindow &window, sf::View view);

protected: // Render Helpers
    void renderDebug(sf::RenderWindow& window);

    void renderPlayerAndEnemies(sf::RenderWindow& window) const;

protected: // Debug and instantiates

    void DebugBoxes(sf::RenderWindow& window);

    float DeltaTime;

    std::vector<EntityID> entityIDList;

    std::vector<std::shared_ptr<baseEntity>> entityList;

    std::shared_ptr<player> playerInstance;

};


#endif //NOTSIMPLEGAME_GAME_H