#ifndef CLASS_BLACKJACKGAME_H
#define CLASS_BLACKJACKGAME_H

#include "class_game.h"
#include "class_deck.h"
#include "class_blackjackState.h"

namespace casino{
  
  class blackjackGame : public game 
  {
    
    //Overridden from game
    virtual void playRound();
    cards::deck s;
    std::vector<cards::card> dealer;
    std::vector<std::vector<cards::card> > dealt;
    blackjackState state();
    int bets[];

  public:
    
    //Constructor
    blackjackGame(int players=1);
    void deal(int players);
    void getMove();
    bool checkBusted(int player);
    bool checkBlackjack(int player);
    int getScore(int player);
    int getValue(char c);
    void dealerMove();
    void winner();
    void clearCards();

    //Overridden from game
    virtual void start();
    virtual void print();
    
  };

}

#endif
