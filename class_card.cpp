#include "class_card.h"


using namespace cards;

card::card(t_suit s,t_rank r)
{
    suit = s;
    rank = r;
}

t_suit card::getSuit(){
    return suit;
}

t_rank card::getRank()
{
    return rank;
}

std::string card::name()
{
    std::string cardname;
    cardname.push_back(rank);
    cardname += " of " + suit_name[suit];
    return cardname;
}
