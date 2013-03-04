#include "class_blackjackAction.h"
#include "class_action.h"
#include <iostream>
#include <string>

using namespace casino;

blackjackAction::blackjackAction(controlType d)
{
  if(d == TERMINAL) //printing in the terminal 
  { 
    std::string move = "";
    std::cout << "Hit, halt, stand, split or double\n(lower case words please): ";
    std::cin >> move; //gets input from player

    if(move == "hit")  //sets the actionType based on the input
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
    //if something else is written you will just choose stand
        
  }
    else if(d == NETWORK){}//currently not implemented
    else if(d == GUI){}//currently not implemented
    else {}//currently not implemented
}


blackjackAction::atype blackjackAction::getAtype()//returns the actionType
{
    return actionType;
}

void blackjackAction::print() //the function that prints to terminal
{

}
