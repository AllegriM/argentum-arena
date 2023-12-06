#pragma once
#include <SFML/Graphics.hpp>

class Character
{
private:
    /* data */
    sf::Sprite body;
    sf::Sprite head;
    sf::Texture skinhead;
    sf::Texture skinbody;
    sf::Text name;

    // Character Stats
    int maxHealth;
    int maxMana;
    int maxStamina;
    int maxStrength;
    int maxAgility;

    int currentHealth;
    int currentMana;
    int currentStamina;
    int currentStrength;
    int currentAgility;

    int bodyFrameWidth = 25;
    int bodyFrameHeight = 45;
    int headFrameWidth = 17;
    int headFrameHeight = 20;

public:
    Character();
    ~Character();
    void characterMovement(sf::RenderWindow *window);
    void createBody();
    void render(sf::RenderWindow &window);

    // GETTERS
    const int getCurrentHealth() const { return this->currentHealth; };
    const int getCurrentMana() const { return this->currentMana; };
    const int getCurrentStamina() const { return this->currentStamina; };
    const int getCurrentStrength() const { return this->currentStrength; };
    const int getCurrentAgility() const { return this->currentAgility; };

    const int getMaxHealth() const { return this->maxHealth; };
    const int getMaxMana() const { return this->maxMana; };
    const int getMaxStamina() const { return this->maxStamina; };
    const int getMaxStrength() const { return this->maxStrength; };
    const int getMaxAgility() const { return this->maxAgility; };
    // SETTERS
};