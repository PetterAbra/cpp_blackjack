#include "class_card.h"


using namespace cards;

card::card(t_suit s,t_rank r)
{//creates a card with suit and rank
    suit = s;
    rank = r;
}

t_suit card::getSuit()
{ //returns the suit
    return suit;
}

t_rank card::getRank()
{//returns the rank
    return rank;
}

std::string card::name()
{//returns the rank and suit in a string
    std::string cardname;
    cardname.push_back(rank);
    cardname += " of " + suit_name[suit];
    return cardname;
}
