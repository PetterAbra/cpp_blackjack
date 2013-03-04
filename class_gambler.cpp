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
{
    firstName = fname;
    lastName = lname;
    gamblerId = gamblerNr++;
    strategies.reserve(5);
    readyToPlay = true;
}

gambler::gambler(controlType s)
{
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
{
    if(amount>0)
    {
        gambler::wallet += amount;
        readyToPlay = true;
    }
}

cash gambler::placeBet()
{
    float tall;
    std::cout << "Place your bet: ";
    bool input = std::cin >> tall;

    if(!input)
    {
        std::cin.clear();
        std::cin.clear();
        std::cout << "\nYour bet is now 2\n";
        tall = 2.0;
        while( std::cin.get() != '\n' );
    }
    else if(tall > wallet || tall < 0)
        tall = 2.0;
    if(wallet <= 0 || tall>wallet)
        tall = wallet;
    if(wallet == 0)
        readyToPlay = false;
    else
        gambler::wallet -= tall;
    return tall;

}

std::string gambler::name()
{
    std::string name= firstName + " " + lastName;
    return name;
}

bool gambler::ready()
{
    return readyToPlay;
}

action* gambler::takeAction(gameState *g)
{
    blackjackStrategy t(TERMINAL);
    strategies.push_back(&t);
    g->print();
    std::cout << "\n" << name() << ": ";
    action * s = t.takeAction(g);
    return s;
}
