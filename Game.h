#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "Character.h"

class Game
{
private:
    /* Private functions */
    void initVariables();
    void initWindow();
    /* Window */
    sf::RenderWindow *window;
    sf::Event ev;
    sf::VideoMode videoMode;
    // Game objects //
    Character *character;
    // Mouse positions //
    sf::Vector2i mousePosWindow;

public:
    Game(/* args */);
    ~Game();
    void render();
    void update();
    void pollEvents();
    void updateMousePositions();
    const bool running() const;
    void initCharacter();
};

Game::Game(/* args */)
{
    this->initVariables();
    this->initWindow();
    this->initCharacter();
}

Game::~Game()
{
    delete this->window;
}

const bool Game::running() const
{
    return this->window->isOpen();
}

void Game::initCharacter()
{
    this->character = new Character();
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

void Game::updateMousePositions()
{
    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
}

void Game::update()
{
    this->pollEvents();

    this->character->characterMovement();
    // Update mouse position
    this->updateMousePositions();
}

void Game::render()
{
    this->window->clear();
    // Draw game objects
    this->character->render(*this->window);
    // Draw game
    this->window->display();
}