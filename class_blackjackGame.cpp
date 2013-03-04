#include <string>
#include <iostream>

//including local files 
#include "class_blackjackGame.h"
#include "controlTypes.h"
#include "gameTypes.h"
#include "class_blackjackState.h"
#include "class_game.h"
#include "class_gambler.h"
#include "class_deck.h"
#include "class_blackjackAction.h"
#include "class_blackjackStrategy.h"
#include "class_action.h"

using namespace casino;
cards::deck s;   //some private variables
std::vector<cards::card> dealer;
std::vector<std::vector<cards::card> > dealt;

//constructor
blackjackGame::blackjackGame(int players):game::game(blackjack, players)
{
    //making room for enough bets to remember the bets made
    blackjackGame::bets[players];
    dealt.reserve(players+1); //reserving space for enough players(vector of cards)
    if(players >7)  //simple check to get enough cards
    {
      cards::deck q(players/6); //6 players for each deck
        s = q;
    }
    for(int i = 0; i<=players; i++)
    {
        if(i<players)
	  bets[i] = 0; //making sure the bets are 0
        dealt.push_back(dealer); //creating the vector of vectors
    }
    start(); //starts the game
}

void blackjackGame::playRound()
{
  //loops through all the players cards
    for(unsigned int i = 1; i<dealt.size(); i++)
    {
      blackjackState state(dealt, i, 0); //creating a state
      gambler g = game::gamblers[i]; //getting the gambler with that hand
      std::cin.clear(); //in case of cin already having some info
      if(!g.ready())  //checking if the gambler is not ready (empty wallet)
        { 
            std::cout << g.name() << " is out of money.\nHow much do you want to set in the Blackjack Bank?";
            float money;
            std::cin >> money; //letting the player fill up his wallet
            std::cout << "\nThis round you will play with no bet\n"; //since he didn't
	    //have any money, not yet alteast
            if(!std::cin.fail()) //checking if he wrote a number
            {
	      if(money > 2000 || money < 0)
		{
		  money = 1000;
		  std::cout << "1000 money was put in your wallet";
		  std::cout << "\nPlease do not give negative numbers or above 2000";
		}
	      g.giveMoney(money); //giving the gambler that amount of money
	      gamblers[i] = g; //setting the gambler back in the vector
            }
            else //if they wrote something else than a number it will say so
	      {
		std::cout << "\nI am sorry, but that didn't make sense\n";
	      }
        }
        if(blackjackGame::checkBlackjack(i))
	  {  //checking for players that might have blackjack
            std::cout << g.name() << " got blackjack and won\n"; 
            std::cout << "Player won: " << bets[i-1]*1.5 << " money\n";
	    //It will allert you and say how much you won
        }
        else if(g.ready()) //checks if g is ready to play
	  {
	    //Calls for an action from the gambler 
            blackjackAction * action = (blackjackAction *) g.takeAction(&state);
            do
            {
	      if(action->getAtype() == 0) //checking if he said hit
                {
		  dealt[i].push_back(s.deal()); //giving him a card
		  std::cout << g.name() << " has chosen to hit\n"; //alert him on the screen
		  if(blackjackGame::checkBusted(i)) //checking if he busted
                    {
		      //alerts how many points you got if you busted
                        std::cout << "and BUSTED with a score: " << blackjackGame::getScore(i) << std::endl;
                    }
                    else
                    {
		      //recreates the state and alerts the player of the new score
                        blackjackState state(dealt, i, 0);
                        std::cout << "and got the score: " << blackjackGame::getScore(i) << std::endl;
			//getting new input from the player
                        action = (blackjackAction *) g.takeAction(&state);
                    }
                }//if he choses to hit it will loop
            }while(action->getAtype() == 0);

            if(action->getAtype() == 1) //if he chose stand it says how high score he got
            {
                std::cout << g.name() << " has chosen to stand" << std::endl;
                std::cout << "Got the score: " << blackjackGame::getScore(i) << std::endl;
            }
            else if(action->getAtype() == 2) //hasn't supported split and double yet
            {
                std::cout << "Split is not yet supported\n";
            }
            else if(action->getAtype() == 3)
            {
                std::cout << "Double is not yet supported\n";
            }
        }

    }
    //alerts the players of the cards of the dealer
    std::cout << "Dealer got the cards: ";
    blackjackGame::dealerMove(); //gives the dealer cards untill dealer reaches 17
    dealer = dealt[0];
    for(unsigned int i = 0; i<dealer.size(); i++)
    {
        cards::card c = dealer[i];
        std::cout << c.name() << " "; //basic loop to get the names of the cards
    }
    blackjackGame::winner();  //calls the function winner
}

void blackjackGame::start()  //function to start the game
{
    char round;
    std::cout << "Want to play a round of blackjack? Y for yes, N for no\n";
    std::cin >> round; //gets input from player
    while(round == 'Y' || round == 'y')
    {
      //loops through the gamblers skips the dealer
        for(unsigned int i = 1; i<game::gamblers.size(); i++)
        {
            gambler g = game::gamblers[i];
            bets[i-1] = g.placeBet(); //getting the bets and alerts how much they betted
            std::cout << g.name() << " betted: " << bets[i-1] << std::endl;
            game::gamblers[i] = g; 
        }
        deal(dealt.size()); //calling the deal function
        playRound();//starts playRound()
        std::cout << "\nWant to play another round of blackjack? Y for yes, N for no\n";
	std::cin.clear();
        while( std::cin.get() != '\n' ) std::cin.clear();
        std::cin >> round; //checks if it shall continue looping the game
    }
}

void blackjackGame::print()
{
  //empty function for later use
}

void blackjackGame::clearCards() //function to reset the gamblers cards
{
    for(unsigned int i = 0; i<dealt.size(); i++)
    {
        std::vector<cards::card> q;
        q = dealt[i];
        q.clear();  //clears the cards
        dealt[i] = q;
    }
    cards::deck q(s.size()/52); //creates a new deck
    s = q;
}

void blackjackGame::deal(int players) //deals out the cards
{
    blackjackGame::clearCards();
    for(int i = 0; i<players; i++)
    {
      dealt[i].push_back(s.deal()); //pushes a card to each player and dealer
    }
    for(int i = 0; i<players; i++)
    {
      dealt[i].push_back(s.deal()); //pushes a second card to each player and dealer
    }
}

bool blackjackGame::checkBusted(int player) //checks if a player has busted
{
  if(blackjackGame::getScore(player) > 21) //calls getScore 
        return true;
    return false;
}

bool blackjackGame::checkBlackjack(int player)
{
    //code to check if a player has scored a blackjack
    dealer = dealt[player];
    if(dealer.size() != 2) //checks if the player has more than 2 cards
        return false;
    char h, g; //ranks are chars
    cards::card q = dealer[0]; 
    h = q.getRank();  //gets the rank
    q = dealer[1];
    g = q.getRank();  //gets second cards rank and checks the chars
    if((h=='T' || h=='J' || h=='Q' || h=='K') && g=='A')
        return true;
    if((g=='T' || g=='J' || g=='Q' || g=='K') && h=='A')
        return true;

    return false;
}

int blackjackGame::getScore(int player)
{
  //returns the score the player has 
    dealer = dealt[player];
    int score = 0; //variable to hold the score
    bool ace = false;
    for(unsigned int i = 0; i < dealer.size(); i++)
    {
        cards::card q = dealer[i];
        int helper = blackjackGame::getValue(q.getRank()); 
        score += helper; //adds the helper int to the score
        if(helper > 10) //checking if it was an ace
        {
	  if(ace) //if it already had an ace reduce it's score by 10
                score -= 10;
	  ace = true; //setting the bool to true
        }
    }
    if(score > 21 && ace) //if it busts and has han ace score is reduced by 10
    {
        score -= 10;
    }
    return score; //returns the score of the player
}

int blackjackGame::getValue(char c)
{
  //a function to get value of a card from a char
    if(c == 'T' || c=='J' || c=='Q' || c=='K')
        return 10;
    //could have used a switch case the whole way, wouldn't matter
    //but chose to have the 10s outside to get a clean switch case
    switch(c)
    {
        case '2' : return 2;
        case '3' : return 3;
        case '4' : return 4;
        case '5' : return 5;
        case '6' : return 6;
        case '7' : return 7;
        case '8' : return 8;
        case '9' : return 9;
        case 'A' : return 11;
    }

    return 0; //in case you tried to get the value of something else
}

void blackjackGame::dealerMove() //the dealer takes a card if the score is under 17
{
    while(getScore(0) < 17)
    {
        dealt[0].push_back(s.deal());
    }
}

void blackjackGame::winner() //checks who won
{
  int dealerScore = getScore(0); //the score of the dealer
  for(unsigned int i = 1; i<game::gamblers.size(); i++) //loops through the gamblers
    {
        gambler g = gamblers[i];
        int playerScore = getScore(i); //gets the players score
        if(blackjackGame::checkBlackjack(i))
        {
	  g.giveMoney(bets[i-1] * 2.5); //if blackjack you get 1.5 times your bet
	  gamblers[i]=g;//but the placebet removes the amount you bet from the wallet
        }
        else if(playerScore < 22 && (playerScore > dealerScore || dealerScore>21))
        {
            g.giveMoney(bets[i-1]*2);
            gamblers[i] = g; 
	    //gives the gambler money and say how much he won
            std::cout << "\n" << g.name() << " has beaten the dealer and won: ";
            std::cout << bets[i-1] << " money.\n";
        }
        else if(playerScore < 22 && playerScore == dealerScore)
        {
            g.giveMoney(bets[i-1]);
            gamblers[i] = g;
	    //if they tied the money that the gambler betted are returned
            std::cout << "\n" << g.name() << " are tied with the dealer\n";
        }
        else
        {
	  //alerts if he lost
            std::cout << "\n" << g.name() << " lost against the dealer\n";
        }
    }
}
