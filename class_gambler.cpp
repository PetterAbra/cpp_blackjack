#include "class_gambler.h"
#include <vector>
#include <iostream>

//Local includes
#include "class_strategy.h"
#include "class_action.h"
#include "class_game.h"
#include "controlTypes.h"
#include "class_blackjackStrategy.h"

using namespace casino;

int gambler::gamblerNr=1;
cash wallet;

gambler::gambler(std::string fname, std::string lname)
{ //creates a gambler
    firstName = fname;
    lastName = lname;
    gamblerId = gamblerNr++;
    strategies.reserve(5);
    readyToPlay = true;
}

gambler::gambler(controlType s)
{ //creates a gambler from input
    if(s == TERMINAL)
    {
        std::cout << "Firstname: ";
        std::cin >> firstName;
        std::cout << "Lastname: ";
        std::cin >> lastName;
    }
    strategies.reserve(5);
    gambler::wallet = 200; //Sets a default amount of "money" every gambler has
    readyToPlay = true;
}

void gambler::giveMoney(cash amount)
{ //gives the gambler more money to have in his wallet
    if(amount>0)
    {
        gambler::wallet += amount;
        readyToPlay = true;
    }
}

cash gambler::placeBet()
{//places a bet and removes that amount of money from the wallet
    float tall;
    std::cout << "Place your bet: ";
    bool input = std::cin >> tall;

    if(!input)
    {
        std::cin.clear();
        std::cin.clear(); //just to clear bugs with infinte loops
        std::cout << "\nYour bet is now 2\n";
        tall = 2.0;
        while( std::cin.get() != '\n' ); //clearing cin
    }
    else if(tall > wallet || tall < 0) //sets the bet to 2 if too large or to small
        tall = 2.0;
    if(wallet <= 0 || tall>wallet) //testing if wallet is 1 or 0 and sets the bet to that amount
        tall = wallet;
    if(wallet == 0) //testing if wallet is 0
        readyToPlay = false;
    else //removes the amount betted from wallet
        gambler::wallet -= tall;
    return tall;

}

std::string gambler::name()
{ //method to return the gamblers name as a string
    std::string name= firstName + " " + lastName;
    return name;
}

bool gambler::ready()
{ //returns readyToPlay / if the gambler is ready
    return readyToPlay;
}

action* gambler::takeAction(gameState *g)
{
    blackjackStrategy t(TERMINAL);
    strategies.push_back(&t);
    g->print(); //prints the gamestate and calls for an action
    std::cout << "\n" << name() << ": ";
    action * s = t.takeAction(g);
    return s;
}
