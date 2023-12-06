#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Map
{
private:
    /* Map Tile */
    sf::Sprite tile;
    sf::Texture tileTexture;
    int textureWidth = 126;
    int textureHeight = 126;
    // WINDOW HEIGHT == 600
    // WINDOW WIDTH == 800
    int mapArray[5][8] = {0};
    bool mapRendered = false;

public:
    Map();
    ~Map();
    void initMap(sf::RenderWindow &window);
    void render(sf::RenderWindow &window);
    void drawMap(sf::RenderWindow &window);
};

Map::Map()
{
    if (this->tileTexture.loadFromFile("./assets/images//ground.png"))
    {
        std::cout << "Ground texture loaded successfully!" << std::endl;
        this->tile.setTexture(this->tileTexture);
        this->mapRendered = true;
    }
    else
    {
        std::cout << "ERROR::GAME::INITMAP::Failed to load background texture" << std::endl;
    }
}

Map::~Map()
{
}

void Map::initMap(sf::RenderWindow &window)
{
    if (this->tileTexture.loadFromFile("./assets/images//ground.png"))
    {
        std::cout << "Ground texture loaded successfully!" << std::endl;
        this->tile.setTexture(this->tileTexture);
    }
    else
    {
        std::cout << "ERROR::GAME::INITMAP::Failed to load background texture" << std::endl;
    }

    this->mapRendered = true;
}

void Map::render(sf::RenderWindow &window)
{
    if (!this->mapRendered)
    {
        this->initMap(window);

        this->tile.setTexture(this->tileTexture);
    }
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            this->tile.setPosition(i * this->textureWidth, j * this->textureHeight);
            window.draw(this->tile);
        }
    }
    // std::cout << "WINDOW SIZE Y: " << window.getSize().y << std::endl;
}

void Map::drawMap(sf::RenderWindow &window)
{
    if (!this->mapRendered)
    {
        std::cerr << "ERROR::GAME::DRAWMAP::Map not initialized!" << std::endl;
        return;
    }

    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            this->tile.setPosition(i * this->textureWidth, j * this->textureHeight);
            window.draw(this->tile);
        }
    }
}