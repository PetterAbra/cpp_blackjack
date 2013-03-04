#include "class_blackjackState.h"
#include "class_gameState.h"
#include <iostream>

using namespace casino;

std::vector<std::vector<cards::card> > cardsDealt;
blackjackState::blackjackState(std::vector<std::vector<cards::card> >
 cardv, int iHero, int iDealer):gameState::gameState()
{
  //Sets the vector and ints 
    ourHero = iHero;
    dealer = iDealer;
    cardsDealt = cardv;
}


void blackjackState::print() //prints everyones cards
{
    std::vector<cards::card> cdealer = cardsDealt[dealer];
    cards::card card = cdealer[0]; //starts with the dealer
    std::cout << "\nDealers card: " << card.name();
    std::cout << " and **** ";
    for(unsigned int i = 1; i<cardsDealt.size(); i++)
      { //loops through all the players cards and prints them
        std::cout << "\nPlayer " << i << " cards: ";
        cdealer = cardsDealt[i];
        for(unsigned int s = 0; s < cdealer.size(); s++)
        {
            card = cdealer[s];
            std::cout << card.name() << " ";
        }
    }
}

std::vector<cards::card> blackjackState::dealersCards()
{  //returns the dealers cards
    return cardsDealt[dealer];
}

std::vector<cards::card> blackjackState::myCards()
{
  //returns the gamblers cards
    return cardsDealt[ourHero];
}

std::vector<cards::card> blackjackState::cardsI(int i)
{ // returns the vector at place i
    return cardsDealt[i];
}

int blackjackState::getOurHero()
{
  //get the int used for this player
    return ourHero;
}

int blackjackState::getDealer()
{ //returns the int used for the dealer
    return dealer;
}
