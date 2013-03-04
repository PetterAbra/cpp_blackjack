#include "class_deck.h"
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <algorithm>

#define DECK_SIZE 52

using namespace cards;


deck::deck()
{
    cards.reserve(DECK_SIZE);
    for(int i=0; i<DECK_SIZE; i++)
    {
        cards.push_back(card((cards::t_suit)(i/13), cards::ranks[(i%13)]));
    }
    shuffle();
}

deck::deck(int deckCount)
{
    //Only allowing whole decks to get added;
    int h = deckCount + 1;
    cards.reserve(deckCount*DECK_SIZE);
    for(int s = 0; s<h; s++)
    {
        for(int i=0; i<DECK_SIZE; i++)
        {
            cards.push_back(card((cards::t_suit)(i/13), cards::ranks[(i%13)]));
        }
    }
    shuffle();
}

void deck::shuffle()
{
    srand(time(NULL));
    std::random_shuffle(cards.begin(), cards.end());
}

//Return one card - remove the card from the deck.
card deck::deal()
{
    card card1 = (card)cards.back();
    cards.erase(cards.end()-1);
    return card1;
}

//Return number of cards left
int deck::size()
{
    return cards.size();
}




