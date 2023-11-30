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
    sf::Text CharacterName;

    int bodyFrameWidth = 25;
    int bodyFrameHeight = 45;
    int headFrameWidth = 17;
    int headFrameHeight = 20;

public:
    Character(/* args */);
    ~Character();
    void characterMovement();
    void createBody();
    void render(sf::RenderWindow &window);
};