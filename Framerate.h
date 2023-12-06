#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Framerate
{
private:
    sf::Clock clock;
    sf::Text FPSCounter;
    sf::Font font;

public:
    Framerate();
    ~Framerate();

    void initFramerate();
    void update();
    void render(sf::RenderTarget *target);
};
