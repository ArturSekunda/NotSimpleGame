

#include "baseEntity.h"

#include "core/darkMath.h"


baseEntity::baseEntity(int localID):
health(100.0f),
maxHealth(100.0f),
mana(50),
maxMana(50),
defense(5.0f),
speed(200.0f),
baseHP(maxHealth),
baseSpeed(speed),
baseDefense(defense),
chanceToDodge(0.0f),
isAlive(true),
entityShape(nullptr),
collisionBox(nullptr),
level(0)

{
    entityID.localID = localID;
}

// Update method to update the entity's state
void baseEntity::Update(float deltaTime) {
    // Update entity logic here (e.g., regeneration, status effects)
    if (health <= 0) {
        isAlive = false;
    }

    bool vitalityChanged = (Stats.CachedVitality != Stats.vitality);
    bool armorHealthChanged = (cachedArmorHealth != equippedArmorHealth);

    if (vitalityChanged || armorHealthChanged) {
        int vit = Stats.vitality;

        float baseMaxHealth = baseHP * (1.0f + vit * 0.05f);

        float newMaxHealth = baseMaxHealth + equippedArmorHealth;

        if (health > newMaxHealth) {
            health = newMaxHealth;
        }

        maxHealth = newMaxHealth;

        Stats.CachedVitality = Stats.vitality;
        cachedArmorHealth = equippedArmorHealth;
    }

    if (Stats. CachedStrength != Stats. strength) {
        Stats.CachedStrength = Stats.strength;
    }

    if (Stats. CachedDexterity != Stats.dexterity) {
        int dex = Stats. dexterity;
        float newSpeed = baseSpeed * (1.0f + dex * 0.03f);
        speed = newSpeed;
        Stats. CachedDexterity = Stats.dexterity;
    }

    bool enduranceChanged = (Stats. CachedEndurance != Stats. endurance);
    bool armorDefenseChanged = (cachedArmorDefense != equippedArmorDefense);

    if (enduranceChanged || armorDefenseChanged) {
        int end = Stats.endurance;

        float baseDefenseFromEnd = baseDefense * (1.0f + end * 0.04f);

        defense = baseDefenseFromEnd + equippedArmorDefense;

        Stats.CachedEndurance = Stats.endurance;
        cachedArmorDefense = equippedArmorDefense;
    }

    bool armorManaChanged = (cachedArmorMana != equippedArmorMana);

    if (armorManaChanged) {
        float baseMaxMana = 50.0f;
        float newMaxMana = baseMaxMana + equippedArmorMana;

        if (mana > static_cast<int>(newMaxMana)) {
            mana = static_cast<int>(newMaxMana);
        }

        maxMana = static_cast<int>(newMaxMana);

        cachedArmorMana = equippedArmorMana;
    }

    if (Stats.CachedIntelligence != Stats.intelligence) {
        Stats.CachedIntelligence = Stats.intelligence;
    }

    if (Stats.CachedLuck != Stats.luck) {
        Stats.CachedLuck = Stats.luck;
    }

    if (Stats.CachedCharisma != Stats.charisma) {
        Stats.CachedCharisma = Stats. charisma;
    }

}

// Method to get the global bounds of the entity's shape for collision detection
sf::FloatRect baseEntity::getEntityBounds() const {
    if (entityShape == nullptr) {
        // Return bounds based on position with default size
        return sf::FloatRect(entityShape->getPosition().x, entityShape->getPosition().y, 32.0f, 32.0f);
    }
    return entityShape->getGlobalBounds();
}

// Method to create a collision box based on the entity's shape
sf::RectangleShape baseEntity::createCollisionBox() const {
    sf::RectangleShape Box;
    if (!entityShape) {
        return Box;
    }

    sf::FloatRect bounds = entityShape->getGlobalBounds();

    Box.setSize(sf::Vector2f(bounds.width, bounds.height));
    Box.setFillColor(sf::Color::Transparent);
    Box.setOutlineColor(sf::Color::White);
    Box.setOutlineThickness(2);

    Box.setOrigin(bounds.width / 2.0f, bounds.height / 2.0f);

    return Box;
}

void baseEntity::takeDamage(float dmg) {
    if ((dmg - (defense * 0.05f)) < 0) return;
    float dodgeRoll = darkMath::getInstance().generateFloatNumber(0.0f, 1.0f);
    if (dodgeRoll < chanceToDodge) {
        // Dodged the attack
        return;
    }
    health -= (dmg - (defense * 0.05f));
    if (health <= 0) {
        health = 0;
        isAlive = false;
    }
}
