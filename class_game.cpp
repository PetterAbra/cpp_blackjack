#include <vector>
#include <iostream>

#include "class_gambler.h"
#include "gameTypes.h"
#include "class_game.h"

using namespace casino;

std::vector<gambler> gamblers;

game::game(gameType s, int players)
{ //creates the gamblers with House as dealer
    t = s;
    gambler d("House", "");
    gamblers.push_back(d);
    for(int i = 0; i<players; i++)
    {
        gambler g( TERMINAL );
        gamblers.push_back(g);
    }
}

gameType game::getType()
{ //returns the gametype
    return t;
}

