#include <iostream>
#include "Game.h"

int main()
{
    Game game;
    while (game.running())
    {
        // Update
        game.update();
        // Draw game
        game.render();
    }
    return 0;
}
