Oblig 1, C++, Spring 2013, Petter Abrahamsen s169962
--------------------------------------------------------------------

#Blackjack C++ Report
1. The blackjack game is implemented with the possibilty to add more players, this you can do with just adding how many players you want in the blackjack.cpp file. I have tested it and it should work just fine. An issue with more players is that you need more cards or else you'll run out of cards in your deck. I have security checks that should take care of the extra cards needed and a new shuffled deck is given every time you start a new round. I tried to implement every function and code even those that wasn't used or not supported.
2. I did not use the gamestate in the strategy class, since in my code I chose to call the print function to gamestate in gambler wich would let me call the gamblers name before the blackjackAction class was created and demanded input. So in a case with a lot of players it says the name of the player who is calling hit or stand. Other than that I would have tried to get more of the functions spread out in the classes and not alot of them stacked up in blackjackGame as it is now. 
3. For me I had some issues compiling until I used the emacs compile tool, then I realised that it was not my code that was wrong but the compile sentence. I used Qt on windows until the code was almost finished then moved it to studssh and tested it. 
4. Not really sure what I would have done differently since I had the headers to follow. I would probably skipped storing all the strategies in gambler to save some space. Since it holds no information that I can use later other than gameType, but then again we could just store the last 3 instead of all. I could have implemented this, but I didn't want to screw up my code this late in the process. 
5. I have not created any alternative implementation.


- Norwegian letters is not supported in studssh, so I wrote the report in english instead. It might be just mine, but I atleast get some wierd chars when I write special letters. 