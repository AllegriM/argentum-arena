#include "Framerate.h"

Framerate::Framerate() {}

Framerate::~Framerate() {}

void Framerate::initFramerate()
{
    if (!this->font.loadFromFile("./assets/fonts/dogica.ttf"))
    {
        std::cout << "ERROR::GAME::INITFONT::Failed to load font dogica.ttf" << std::endl;
    }
    else
    {
        std::cout << "Font dogica.ttf sucessfully loaded!" << std::endl;
    }
    this->FPSCounter.setFont(this->font);
    this->FPSCounter.setCharacterSize(10);
}

void Framerate::update()
{
    sf::Time deltaTimeTimer = clock.restart();
    double deltaTime = deltaTimeTimer.asMilliseconds();
    this->FPSCounter.setString(std::to_string((int)(1000.0f / deltaTime)));
}

void Framerate::render(sf::RenderTarget *target)
{
    target->draw(this->FPSCounter);
}