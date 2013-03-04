#include "class_blackjackAction.h"
#include "class_action.h"
#include <iostream>
#include <string>

using namespace casino;

blackjackAction::blackjackAction(controlType d)
{
    if(d == TERMINAL)
    {
        blackjackAction::print();
    }
    else if(d == NETWORK){}//currently not implemented
    else if(d == GUI){}//currently not implemented
    else {}//currently not implemented
}


blackjackAction::atype blackjackAction::getAtype()
{
    return actionType;
}

void blackjackAction::print()
{
    std::string move = "";
    std::cout << "Hit, halt, stand, split or double\n(lower case words please): ";
    std::cin >> move;

    if(move == "hit")
    {
        actionType = HIT;
    }
    else if(move == "stand")
    {
        actionType = STAND;
    }
    else if(move == "double")
    {
        actionType = DOUBLE;
    }
    else if(move == "split")
    {
        actionType = SPLIT;
    }

}
