#include "class_deck.h"
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <algorithm>

#define DECK_SIZE 52

using namespace cards;


deck::deck()
{//creates a deck with 52 cards
    cards.reserve(DECK_SIZE);
    for(int i=0; i<DECK_SIZE; i++)
      {//creates cards with different ranks and suits
        cards.push_back(card((cards::t_suit)(i/13), cards::ranks[(i%13)]));
    }
    shuffle(); //calls shuffle
}

deck::deck(int deckCount)
{ //creates deckCount + 1 number of decks
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
    shuffle(); //calls shuffle
}

void deck::shuffle() //using the random shuffle function existing in algorithm
{  //since it's already created and shuffling is just use of rand() and swapping items
    srand(time(NULL));
    std::random_shuffle(cards.begin(), cards.end());
}

//Return one card - remove the card from the deck.
card deck::deal()
{
    card card1 = (card)cards.back();
    cards.erase(cards.end()-1);//removes the card from the deck
    return card1; //returns the card
}

//Return number of cards left
int deck::size()
{ //returns the deck size()
    return cards.size();
}




