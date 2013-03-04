#include "class_blackjackStrategy.h"
#include "class_strategy.h"
#include "class_blackjackAction.h"

using namespace casino;

blackjackStrategy::blackjackStrategy(controlType s):strategy()
{ //Gives possibility to implement other controlTypes
    //if(s == TERMINAL) is not needed at this moment
}

action* blackjackStrategy::takeAction(gameState *g)
{
  //g is not used here, it's used earlier in the gambler to call the print
  blackjackAction action(TERMINAL); //calls the action to get input
    return &action;
}
