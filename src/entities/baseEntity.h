//
// Created by lukas on 21.09.2025.
//

#ifndef NOTSIMPLEGAME_BASEENTITY_H
#define NOTSIMPLEGAME_BASEENTITY_H

class SFML;

class baseEntity {
    protected:
    float health;
    float maxHealth;
    float speed;
    int mana;
    int maxMana;
    bool isAlive;

public:
    explicit baseEntity(float maxHp = 100.0f, float spd = 1.0f, int maxMp = 50)
        : health(maxHp), maxHealth(maxHp), speed(spd),
          mana(maxMp), maxMana(maxMp), isAlive(true) {}

    virtual ~baseEntity() = default;

public: // Section for getters

    float getHealth() const { return health; }
    float getMaxHealth() const { return maxHealth; }
    float getSpeed() const { return speed; }
    int getMana() const { return mana; }
    int getMaxMana() const { return maxMana; }
    bool getIsAlive() const { return isAlive; }

public: // Section for setters
    void setHealth(float h) {
            health = h;
        if (health <= 0)
            isAlive = false; }
    void setMaxHealth(float mh) { maxHealth = mh; }
    void setSpeed(float s) { speed = s; }
    void setMana(int m) { mana = m; }
    void setMaxMana(int mm) { maxMana = mm; }



};


#endif //NOTSIMPLEGAME_BASEENTITY_H