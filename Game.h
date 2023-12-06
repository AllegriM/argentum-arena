#pragma once

#include <iostream>
#include <sstream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "Framerate.h"
#include "Character.h"
#include "Map.h"
class Game
{
private:
    /* Private functions */
    void initVariables();
    void initFont();
    void initText();
    void initWindow();
    void initCharacter();
    void initMap();
    void initFramerate();

    /* Window */
    sf::RenderWindow *window;
    sf::Event ev;
    sf::VideoMode videoMode;
    Framerate *framerate;

    // GUI //
    sf::Font font;
    sf::Text text;

    // Game objects //
    Character *character;
    Map *map;

    // Mouse positions //
    sf::Vector2i mousePosWindow;

public:
    Game();
    ~Game();
    void pollEvents();
    const bool running() const;

    // Update //
    void update();
    void updateMousePositions();
    void updateText();

    // Render //
    void render();
    void renderText(sf::RenderTarget *target);
};

Game::Game()
{
    this->initVariables();
    this->initWindow();
    this->initCharacter();
    this->initMap();
    this->initFont();
    this->initText();
    this->initFramerate();
}

Game::~Game()
{
    delete this->window;
    delete this->character;
    delete this->map;
}

const bool Game::running() const
{
    return this->window->isOpen();
}

//============= Initiators =============//

void Game::initCharacter()
{
    this->character = new Character();
}

void Game::initMap()
{
    this->map = new Map();
    this->map->initMap(*this->window);
}

void Game::initVariables()
{
    this->window = nullptr;
}

void Game::initWindow()
{
    this->videoMode.height = 600;
    this->videoMode.width = 800;
    this->window = new sf::RenderWindow(this->videoMode, "AO", sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(60);
}

void Game::initFont()
{
    if (!this->font.loadFromFile("./assets/fonts/dogica.ttf"))
    {
        std::cout << "ERROR::GAME::INITFONT::Failed to load font dogica.ttf" << std::endl;
    }
    else
    {
        std::cout << "Font sucessfully loaded!" << std::endl;
    }
}

void Game::initText()
{
    this->text.setFont(this->font);
    this->text.setCharacterSize(8);
    this->text.setPosition(this->window->getSize().x - 150, this->window->getSize().y - 70);
}

void Game::initFramerate()
{
    this->framerate = new Framerate();
    this->framerate->initFramerate();
}

//============= Poll Events =============//

void Game::pollEvents()
{
    while (this->window->pollEvent(this->ev))
    {
        switch (this->ev.type)
        {
        case sf::Event::Closed:
            this->window->close();
            break;
        case sf::Event::KeyPressed:
            if (this->ev.key.code == sf::Keyboard::Escape)
                this->window->close();
            break;
        }
    }
}

//============= Updates =============//

void Game::updateMousePositions()
{
    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
}

void Game::updateText()
{
    std::stringstream ss;

    // ss << "Mouse Position: " << this->mousePosWindow.x << " " << this->mousePosWindow.y << "\n";
    ss << "Health: " << this->character->getMaxHealth() << "/" << this->character->getMaxHealth() << "\n\n";
    ss << "Mana: " << this->character->getMaxMana() << "/" << this->character->getMaxMana() << "\n\n";
    ss << "Stamina: " << this->character->getMaxStamina() << "/" << this->character->getMaxStamina() << "\n\n";
    ss << "Strength: " << this->character->getMaxStrength() << "/" << this->character->getMaxStrength() << "\n\n";
    ss << "Agility: " << this->character->getMaxAgility() << "/" << this->character->getMaxAgility() << "\n\n";

    this->text.setString(ss.str());
}

void Game::update()
{
    this->framerate->update();

    this->pollEvents();

    this->character->characterMovement(this->window);
    // Update mouse position
    this->updateMousePositions();

    this->updateText();
}

//============= Renders =============//

void Game::renderText(sf::RenderTarget *target)
{
    target->draw(this->text);
}

void Game::render()
{
    this->window->clear();

    // Draw game objects
    this->map->drawMap(*this->window);
    this->character->render(*this->window);
    this->renderText(this->window);
    this->framerate->render(this->window);

    // Draw game
    this->window->display();
}