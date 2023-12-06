#include <iostream>
#include "Character.h"

Character::Character()
    : currentHealth(350), currentMana(2000), currentStamina(200), currentStrength(200), currentAgility(200),
      maxHealth(350), maxMana(2000), maxStamina(200), maxStrength(200), maxAgility(200)
{
    this->head.setPosition(13.5, 4);
    this->body.setPosition(10, 12);
    this->createBody();
}

Character::~Character()
{
}

void Character::render(sf::RenderWindow &window)
{
    window.draw(this->head);
    window.draw(this->body);
}

void Character::createBody()
{
    this->skinhead.loadFromFile("./assets/images//head.png");
    this->skinbody.loadFromFile("./assets/images//body.png");
    this->head.setTexture(this->skinhead);
    this->head.setTextureRect(sf::IntRect(0, 0, this->headFrameWidth, this->headFrameHeight));
    this->body.setTextureRect(sf::IntRect(0, 0, this->bodyFrameWidth, this->bodyFrameHeight));
    this->body.setTexture(this->skinbody);
}

void Character::characterMovement(sf::RenderWindow *window)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        int yTexture = 0;
        yTexture = (int)this->body.getPosition().y / 3 % 6;
        yTexture = yTexture * this->bodyFrameWidth;
        this->body.setTextureRect(sf::IntRect(yTexture, this->bodyFrameHeight, this->bodyFrameWidth, this->bodyFrameHeight));
        this->head.setTextureRect(sf::IntRect(this->headFrameWidth * 3, 0, this->headFrameWidth, this->headFrameHeight));
        if (this->head.getPosition().y < 0 || this->body.getPosition().y < 0)
        {
            this->head.setPosition(this->head.getPosition().x, this->head.getPosition().y + 2);
            this->body.setPosition(this->body.getPosition().x, this->body.getPosition().y + 2);
        }
        this->head.setPosition(this->head.getPosition().x, this->head.getPosition().y - 2);
        this->body.setPosition(this->body.getPosition().x, this->body.getPosition().y - 2);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        int yTexture = 0;
        yTexture = (int)this->body.getPosition().y / 3 % 6;
        yTexture = yTexture * this->bodyFrameWidth;
        this->body.setTextureRect(sf::IntRect(yTexture, 0, this->bodyFrameWidth, this->bodyFrameHeight));
        this->head.setTextureRect(sf::IntRect(0, 0, this->headFrameWidth, this->headFrameHeight));
        if (this->body.getPosition().y > window->getSize().y)
        {
            this->head.setPosition(this->head.getPosition().x, this->head.getPosition().y - 2);
            this->body.setPosition(this->body.getPosition().x, this->body.getPosition().y - 2);
        }
        this->head.setPosition(this->head.getPosition().x, this->head.getPosition().y + 2);
        this->body.setPosition(this->body.getPosition().x, this->body.getPosition().y + 2);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        int xTexture = 0;
        xTexture = (int)this->body.getPosition().x / 3 % 5;
        xTexture = xTexture * this->bodyFrameWidth;
        this->body.setTextureRect(sf::IntRect(xTexture, this->bodyFrameHeight * 2, this->bodyFrameWidth, this->bodyFrameHeight));
        this->head.setTextureRect(sf::IntRect(this->headFrameWidth * 2, 0, this->headFrameWidth, this->headFrameHeight));
        if (this->head.getPosition().x < 0 || this->body.getPosition().x < 0)
        {
            this->head.setPosition(this->head.getPosition().x + 2, this->head.getPosition().y);
            this->body.setPosition(this->body.getPosition().x + 2, this->body.getPosition().y);
        }
        this->head.setPosition(this->head.getPosition().x - 2, this->head.getPosition().y);
        this->body.setPosition(this->body.getPosition().x - 2, this->body.getPosition().y);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        int xTexture = 0;
        xTexture = (int)this->body.getPosition().x / 3 % 5;
        xTexture = xTexture * this->bodyFrameWidth;
        this->body.setTextureRect(sf::IntRect(xTexture, this->bodyFrameHeight * 3, this->bodyFrameWidth, this->bodyFrameHeight));
        this->head.setTextureRect(sf::IntRect(this->headFrameWidth, 0, this->headFrameWidth, this->headFrameHeight));
        if (this->head.getPosition().x > window->getSize().x || this->body.getPosition().x > window->getSize().x)
        {
            this->head.setPosition(this->head.getPosition().x - 2, this->head.getPosition().y);
            this->body.setPosition(this->body.getPosition().x - 2, this->body.getPosition().y);
        }
        this->head.setPosition(this->head.getPosition().x + 2, this->head.getPosition().y);
        this->body.setPosition(this->body.getPosition().x + 2, this->body.getPosition().y);
    }
}