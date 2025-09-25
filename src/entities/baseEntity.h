//
// Created by lukas on 21.09.2025.
//

#ifndef NOTSIMPLEGAME_BASEENTITY_H
#define NOTSIMPLEGAME_BASEENTITY_H
#include <memory>

#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/Shape.hpp"

class SFML;

enum class EntityType {
    PLAYER,
    BASIC_ENEMY
};

struct EntityID {
    EntityType type;  // PLAYER, BASIC_ENEMY, GOBLIN, NPC...
    int localID;      // 0, 1, 2... dla tego konkretnego typu

    std::string toString() const {
        return typeToString(type) + "_" + std::to_string(localID);
    }

    static std::string typeToString(EntityType type) {
        switch (type) {
            case EntityType::PLAYER: return "player";
            case EntityType::BASIC_ENEMY: return "basic_enemy";
            default:
                return "unknown";

        }
    }
};

class baseEntity {
    protected: // Section for attributes

    EntityID entityID;

    float health;
    float maxHealth;
    float mana;
    float maxMana;
    float defense;
    float speed;
    bool isAlive;

    std::shared_ptr<sf::Shape> entityShape; // Pointer to a SFML shape representing the entity
    std::shared_ptr<sf::RectangleShape> collisionBox; // Pointer to a SFML rectangle shape for collision detection

protected: //  Section for stats

    int strength;
    int dexterity;
    int intelligence;
    int endurance;
    int luck;
    int charisma;


public: // Section for constructor and destructor
     explicit baseEntity(int localID);

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
    EntityID setEntityID(EntityType type, int localID) {
        entityID.type = type;
        entityID.localID = localID;
        return entityID;
    }

    // Getters for stats
    int getStrength() const { return strength; }
    int getDexterity() const { return dexterity; }
    int getIntelligence() const { return intelligence; }
    int getEndurance() const { return endurance; }
    int getLuck() const { return luck; }
    int getCharisma() const { return charisma; }
    float getDefense() const { return defense; }
    EntityID getEntityID() const { return entityID; }


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

    // Setters for stats
    void setStrength(int s) { strength = s; }
    void setDexterity(int d) { dexterity = d; }
    void setIntelligence(int i) { intelligence = i; }
    void setEndurance(int e) { endurance = e; }
    void setLuck(int l) { luck = l; }
    void setCharisma(int c) { charisma = c; }
    void setDefense(float d) { defense = d; }

public: // Combat

    void takeDamage(float dmg) {
        if (dmg < 0) return; // Ignore negative damage
        health -= dmg;
        if (health <= 0) {
            health = 0;
            isAlive = false;
        }
    }

    void heal(float amount) {
        if (amount < 0) return; // Ignore negative healing
        health += amount;
        if (health > maxHealth) {
            health = maxHealth;
        }
    }
};


#endif //NOTSIMPLEGAME_BASEENTITY_H