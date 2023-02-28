#include <iostream>
#include "Game.h"

int main()
{
    srand(time(NULL));
    Game game(sf::Vector2<int>(1600, 900), "Marching Squares");

    while (game.running())
    {
        game.update();
        game.render();
    }

    return 0;
}