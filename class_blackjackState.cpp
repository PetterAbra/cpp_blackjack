#include "class_blackjackState.h"
#include "class_gameState.h"
#include <iostream>

using namespace casino;
//Rett opp alle konstruktørene når du skjønner hva som er feil
std::vector<std::vector<cards::card> > cardsDealt;
blackjackState::blackjackState(std::vector<std::vector<cards::card> >
 cardv, int iHero, int iDealer):gameState::gameState()
{
    ourHero = iHero;
    dealer = iDealer;
    cardsDealt = cardv;
}


void blackjackState::print()
{
    std::vector<cards::card> cdealer = cardsDealt[dealer];
    cards::card card = cdealer[0];
    std::cout << "\nDealers card: " << card.name();
    std::cout << " and **** ";
    for(unsigned int i = 1; i<cardsDealt.size(); i++)
    {
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
{
    return cardsDealt[dealer];
}

std::vector<cards::card> blackjackState::myCards()
{
    return cardsDealt[ourHero];
}

std::vector<cards::card> blackjackState::cardsI(int i)
{
    return cardsDealt[i];
}

int blackjackState::getOurHero()
{
    return ourHero;
}

int blackjackState::getDealer()
{
    return dealer;
}
