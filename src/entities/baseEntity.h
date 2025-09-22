//
// Created by lukas on 21.09.2025.
//

#ifndef NOTSIMPLEGAME_BASEENTITY_H
#define NOTSIMPLEGAME_BASEENTITY_H
#include <memory>

#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/Shape.hpp"

class SFML;

class baseEntity {
    protected: // Section for attributes
    float health;
    float maxHealth;
    float speed;
    int mana;
    int maxMana;
    bool isAlive;


    std::shared_ptr<sf::Shape> entityShape; // Pointer to a SFML shape representing the entity
    std::shared_ptr<sf::RectangleShape> collisionBox; // Pointer to a SFML rectangle shape for collision detection

public: // Section for constructor and destructor
    explicit baseEntity(float maxHp = 100.0f, float spd = 1.0f, int maxMp = 50)
        : health(maxHp), maxHealth(maxHp), speed(spd),
          mana(maxMp), maxMana(maxMp), isAlive(true), entityShape(nullptr) {
    }

    virtual ~baseEntity() = default;

    // Method to update the entity's state
    virtual void Update(float deltaTime);

    // Method to get the global bounds of the entity's shape for collision detection
    sf::FloatRect getEntityBounds() const;

    sf::RectangleShape createCollisionBox() const;




public: // Section for getters

    float getHealth() const { return health; }
    float getMaxHealth() const { return maxHealth; }
    float getSpeed() const { return speed; }
    int getMana() const { return mana; }
    int getMaxMana() const { return maxMana; }
    bool getIsAlive() const { return isAlive; }
    sf::Vector2f getPosition() const { return getEntityShape()->getPosition(); }
    std::shared_ptr<sf::Shape> getEntityShape() const { return entityShape; }
    std::shared_ptr<sf::RectangleShape> getCollisionBox() const { return collisionBox; }


public: // Section for setters

    void setHealth(float h) {
            health = h;
        if (health <= 0)
            isAlive = false; }
    void setMaxHealth(float mh) { maxHealth = mh; }
    void setSpeed(float s) { speed = s; }
    void setMana(int m) { mana = m; }
    void setMaxMana(int mm) { maxMana = mm; }
    void setIsAlive(bool alive) { isAlive = alive; }
    void setEntityShape(std::shared_ptr<sf::Shape> shape) {
        entityShape = shape;
    }
    void setCollisionBox(std::shared_ptr<sf::RectangleShape> box) { collisionBox = box; }
};


#endif //NOTSIMPLEGAME_BASEENTITY_H