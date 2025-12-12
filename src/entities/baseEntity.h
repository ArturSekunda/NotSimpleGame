

#ifndef NOTSIMPLEGAME_BASEENTITY_H
#define NOTSIMPLEGAME_BASEENTITY_H
#include <memory>
#include "helpers/entityStructs.h"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/Shape.hpp"

struct baseStats;
class SFML;

class baseEntity {
    protected: // Section for attributes

    baseStats Stats;

    EntityID entityID;

    float health;
    float maxHealth;
    float mana;
    float maxMana;
    float defense;
    float speed;
    bool isAlive;

    float chanceToDodge;

    float baseHP;
    float baseSpeed;
    float baseDefense;

    float cachedArmorDefense = 0.0f;
    float cachedArmorHealth = 0.0f;
    float cachedArmorMana = 0.0f;

    float equippedArmorDefense = 0.0f;
    float equippedArmorHealth = 0.0f;
    float equippedArmorMana = 0.0f;

    int level;

    std::shared_ptr<sf::Shape> entityShape; // Pointer to a SFML shape representing the entity
    std::shared_ptr<sf::RectangleShape> collisionBox; // Pointer to a SFML rectangle shape for collision detection


public: // Section for constructor and destructor
     explicit baseEntity(int localID);

    virtual ~baseEntity() = default;

    // Method to update the entity's state
    virtual void Update(float deltaTime);

    // Method to get the global bounds of the entity's shape for collision detection
    sf::FloatRect getEntityBounds() const;

    sf::RectangleShape createCollisionBox() const;



public: // Section for getters

    int getLevel() const { return level; }
    float getHealth() const { return health; }
    float getMaxHealth() const { return maxHealth; }
    float getSpeed() const { return speed; }
    int getMana() const { return mana; }
    int getMaxMana() const { return maxMana; }
    bool getIsAlive() const { return isAlive; }
    sf::Vector2f getPosition() const { return getEntityShape()->getPosition(); }
    std::shared_ptr<sf::Shape> getEntityShape() const { return entityShape; }
    std::shared_ptr<sf::RectangleShape> getCollisionBox() const { return collisionBox; }
    EntityID setEntityID(EntityType type, int localID) {
        entityID.type = type;
        entityID.localID = localID;
        return entityID;
    }
    baseStats &getStats() {
        return Stats;
    }
    const baseStats &getStats() const {
        return Stats;
    }

    // Getters for stats
    float getDefense() const { return defense; }
    EntityID getEntityID() const { return entityID; }


public: // Section for setters

    void setLevel(int lvl) { level = lvl; }
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

    void setStats(baseStats& stats) {
        Stats = stats;
    }

    // Setters for stats
    void setDefense(float d) { defense = d; }

public: // Combat

    void takeDamage(float dmg);

public: // Utility

    void setEquippedArmorDefense(float def) { equippedArmorDefense = def; }
    void setEquippedArmorHealth(float hp) { equippedArmorHealth = hp; }
    void setEquippedArmorMana(float mp) { equippedArmorMana = mp; }

    void addEquippedArmorDefense(float def) { equippedArmorDefense += def; }
    void addEquippedArmorHealth(float hp) { equippedArmorHealth += hp; }
    void addEquippedArmorMana(float mp) { equippedArmorMana += mp; }

    void removeEquippedArmorDefense(float def) { equippedArmorDefense -= def; }
    void removeEquippedArmorHealth(float hp) { equippedArmorHealth -= hp; }
    void removeEquippedArmorMana(float mp) { equippedArmorMana -= mp; }
};


#endif //NOTSIMPLEGAME_BASEENTITY_H