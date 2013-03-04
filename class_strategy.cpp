#include "class_action.h"
#include "class_gameState.h"
#include "class_strategy.h"

using namespace casino;

gameType strategy::getGameType()
{
    return t;
}

action* takeAction(gameState* g)
{
  //no use of the gamestate since this is called from gambler
    action* p;
    return p;
}
