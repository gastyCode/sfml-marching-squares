#include <iostream>
#include "Game.h"

int main()
{
    Game game(sf::Vector2<int>(800, 600), "Marching Squares");

    while (game.running())
    {
        game.update();
        game.render();
    }

    return 0;
}