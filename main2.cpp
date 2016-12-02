//  main.cpp
//  Black Jack


//#include "blackjack.h"
//#include <QApplication>

#include <iostream>
#include <string>
using namespace std;


void displayRules()
{
    cout<< "Your aim is to achieve a hand where all the cards add up as close as possible but do not exceed 21.";
    cout<< "\nAll face cards are worth 10 points. This includes jacks, queens and kings, regardless of suit.";
    cout<< "\nAn ace is worth either 1 or 11 depending on your strategy.";
    cout<< "\nCards 2 through 10 are their face value.";
    
    cout<< "\n\nAs the dealer gains more cards, they must draw on 16 and stand on all 17's.";
    cout<< "\nThen the player (YOU) can keep his/her hand as it is (stand) or take more cards from the";
    cout<< "\ndeck (hit), one at a time, until either the player judges that the hand is strong";
    cout<< "\nenough to go up against the dealer's hand and stands, or until it goes over 21, in";
    cout<< "\nwhich case the player immediately loses (busts).";
    
    cout<< "\n\nWhen all players have finished their actions, either decided to stand or busted, the dealer";
    cout<< "\nturns over his hidden hole card. If the dealer has a natural 21 (blackjack) with his two";
    cout<< "\ncards, he won't take any more cards. All players lose, except players who also have a";
    cout<< "\nblackjack, in which case it is a push - the bet is returned to the player.";
    cout<< "\nIf the dealer doesn't have a natural, he hits (takes more cards) or stands depending on the";
    cout<< "\nvalue of the hand. Contrary to the player, though, the dealer's action is completely dictated ";
    cout<< "\nby the rules. The dealer must hit if the value of the hand is lower than 17, otherwise the dealer ";
    cout<< "\nwill stand.";
    cout<< "In this game, the dealer will stand on a soft 17 (where there is an ace being counted for 11 points).";
    
    cout<< "\n\nIn this game, you can take as many cards as you want until you bust.";
    cout<< "This rule may not be the same in all playing environments.";
    
    //Later add insurance, surrender, splitting and doubling down if we chose to allow gambling.
    
    /*Whether or not the dealer must hit on a soft 17 (a hand of 17 containing an ace being counted as 11) differs from casino to casino. There might even be blackjack tables with different rules within the same casino.*/
}

/*
Inititalize deck returns an array of strings. Each element in the array is a string value that represents a card.
52 cards will be put into the array. This is intialized through a series of for loops that put in a card number, 2-10 or face card 
values of A,K,Q,J. Each for loop also assigns a suit to the card that is either S for spades, D for diamonds, C for clubs, and H for hearts.
*/
string* initializeDeck()
{
    //creates the deck 
    string* deck = new string [52];
    //a string will be used for the cardNum since we also need the suit to be part of the card 
    string cardNum = "";
    // based on the current value of "int i" cardNum will be set to that card
    for (int i = 0; i<=12; i++)
    {
        //when i = 9-12 we substitute a number for J,Q,K,A which is obivously Jack, Queen, King, and Ace
        if (i == 9)
        {
            cardNum = "J";
        }
        else if (i == 10)
        {
            cardNum = "Q";
        }
        else if (i == 11 )
        {
            cardNum = "K";
        }
        else if (i == 12)
        {
            cardNum = "A";
        }
        else
        {
            //if it is not a face card then simply add 2 to i since cardnum starts at 0 and the first card is "2" 
            int w = i+2;
            cardNum = "" + w;
        }
        // cardNum + S since this particular loop contributes to the "spades" of our deck 
        deck[i]= cardNum + "S";
        
    }
    // We use 3 more for loops for the 3 remianing suits, they are essentially the same as the first 
    for (int i = 0; i<=12; i++)
    {
        if (i == 9)
        {
            cardNum = "J";
        }
        else if (i == 10)
        {
            cardNum = "Q";
            
        }
        else if (i == 11 )
        {
            cardNum = "K";
            
        }
        else if (i == 12)
        {
            cardNum = "A";
        }
        else
        {
            int w = i+2;
            cardNum = "" + w;
        }
        //Since the spades makes up the first part of the deck we must go forward 13 for diamonds 
        deck[i+13]= cardNum + "D";
        
    }
    
    for (int i = 0; i<=12; i++)
    {
        if (i == 9)
        {
            cardNum = "J";
        }
        else if (i == 10)
        {
            cardNum = "Q";
            
        }
        else if (i == 11 )
        {
            cardNum = "K";
            
        }
        else if (i == 12)
        {
            cardNum = "A";
        }
        else
        {
            int w = i+2;
            cardNum = "" + w;
        }
         //move up 26 for Clubs
        deck[i+26]= cardNum + "C";
        
    }
    
    for (int i = 0; i<=12; i++)
    {
        if (i == 9)
        {
            cardNum = "J";
        }
        else if (i == 10)
        {
            cardNum = "Q";
            
        }
        else if (i == 11 )
        {
            cardNum = "K";
            
        }
        else if (i == 12)
        {
            cardNum = "A";
        }
        else
        {
            int w = i+2;
            cardNum = "" + w;
        } 
        //move up 39 for hearts
        deck[i+39]= cardNum + "H";
        
    }
    return deck;
}
//this method just displays each card in the deck array.
void displayDeck(string deck[])
{
    for (int i=0; i<=52; i++)
    {
        cout << deck[i] << endl;
    }
}
/*
this method shuffles the deck of cards. It takes in the deck array as a parameter. It uses a random generator to swap cards in the
array to different, random indexes throughout the array. 
*/
void shuffleDeck(string deck[])
{
    int r =0;
    //string hold will hold the value of deck[i] so that we may set the random spot in the deck to the value of deck[i]
    string hold;
    for (int i = 0; i <52; i++)
    {
        srand( static_cast<unsigned int>(time(NULL)));
        r = rand() % 52 ;
        hold = deck[i];
         //the deck at [i] now becomes the value of the deck at the spot of the random integer
        deck [i]= deck [r];
        //the deck at spot of the random integer becomes what the value of deck[i] used to be
        deck [r] = hold;
        //set hold back equal to nothing before we go to the next i value
        hold = "";
    }
}
//method deals cards from the deck array to a hand array (either the player or computers)
//takes in the deck and either the player or computers hand array as parameters.
void deal (string deck[], string hand[])
{
    int i=0;
    //this loop iterates through the deck until we find a spot in the deck that has a card and is not "empty" 
    while (deck[i]== "empty" && i<52)
    {
        i++;
    }
    // the first spot in the player or computer's hand is now equal to the current value of the deck which should not be empty 
    hand [0]=deck [i];
     //once we assign that card to the hand then that spot becomes "empty" since it's no longer in the virtual deck 
    deck [i]= "empty";
    //this is essentially the same as the first while loop except it gives the user/computer their second card 
    while (deck[i]== "empty" && i<52)
    {
        i++;
    }
    hand [1]=deck [i];
    deck [i]= "empty";
    
}

//called when someone decides to hit does the same thing as deal but only one card is given.
void hit (string deck[], string hand [])
{
    int i=0;
    int j=0;
    while (deck[i]== "empty" && i<=51)
    {
        i++;
    }
    //iterates through the hand until we find an empty spot to put the card that the user has "hit"
    while (hand[j]!= "" && j<=51)
    {
        j++;
    }
    hand [j]=deck [i];
    deck [i]= "empty";
}

//saves who the dealer is in a string, either player or computer based on if player says yes or no.
//used in blackjack because the dealer wins the tie of a round. 
void getDealer (string option, string &dealer)
{
    cout << "Do you want to play as dealer: Yes or No?" << endl;
    cin >> option ;
    
    if (option == "yes")
    {
        dealer = "player";
    }
    else
    {
        dealer = "computer";
    }
}
//Checks the card value by first character in card string, returns an int value.
int checkCard (string card)
{
    int cardValue;
    
    if (card.at(0) == '2')
    {
        cardValue = 2;
    }
    else if (card.at(0) == '3')
    {
        cardValue = 3;
    }
    else if (card.at(0) == '4')
    {
        cardValue = 4;
    }
    else if (card.at(0) == '5')
    {
        cardValue = 5;
    }
    else if (card.at(0) == '6')
    {
        cardValue = 6;
    }
    else if (card.at(0) == '7')
    {
        cardValue = 7;
    }
    else if (card.at(0) == '8')
    {
        cardValue = 8;
    }
    else if (card.at(0) == '9')
    {
        cardValue = 9;
    }
    else if (card.at(0) == 'A')
    {
        cardValue = 11;
    }
    else
    {
        cardValue = 10;
    }
    return cardValue;
}

//initialize card hand, sets the hands to null to start the game.
void initializeHand (string hand[])
{
    
    for (int i=0; i<52; i++)
    {
        hand[i]="";
    }
    
}

bool isInt(int n)
{
    int i = 0;
    string str = to_string(n);
    for(i = 0; i < str.length(); i++)
    {
        if((str.at(i))!=('.'))
        {
            return false;
        }
    }
    return true;
}
//plays the game of blackjack
void blackJack (string deck [], string &dealer)
{
    //creates an array of strings with 52 elements for each the player and the computer
    string playerHand[52];//array for players hand
    string compHand[52];//array for the computers hand
    
    int playerCard=0;//first player card in hand
    int playerFinal =0;//sum of cards from player
    
    int i = 52;//value of number of cards in deck is used to check how many cards are left in pile throughout the game
                //i is decremented each time a card is dealt, when i reaches 20, the deck will reset and shuffle for
                //the game to continue. 
    
    int round=1;//the round for the game starts at one and increments for each new round. is displayed throughout the game.
 
    int playerValue = 1000;//amount of "money" the player is given to start gambling with 
    
    
    while ((i > 3) && playerValue > 0)
    {
        string move="Hit";    //determines whether player wants to hit or stay
        //below initializes each hand to null strings
        initializeHand(playerHand);
        initializeHand(compHand);
       
        playerFinal=0;
        int compFinal=0;//sum of cards from the computer
        
        cout<< "Round "<<round++ <<endl;
        //plays the game until the deck runs out
        deal (deck, playerHand);
        deal (deck, compHand);
        i -= 4;//subtracts 4 from card pile because 2 cards are dealt to each player
        
        //gambling portion: displays the money that the player has to gamble and asks them how much they would like to wager for that
        //specifice round
        int n = 0;
        cout<< "How much would you like to wager?" << endl;
        cout<< "Your money: $" << playerValue << endl;
        cin >> n;
        cin.clear();//error handling
        cin.ignore(1000,'\n');//error handling for bad input
        while(true)
        {
            if(n==0)
            {
                cout<< "Please enter an integer value." << endl;//asked if player doesn't enter an integer
                cin >> n;
                cin.clear();
                cin.ignore(1000,'\n');
            }

            else if(n <= playerValue)//if the player wagers a proper amount, the amount is subtracted from the pot of money they have to gamble
            {
                playerValue -= n;
                break;
            }
            else//runs if the player enters an integer value that exceeds how much money they actually have to gamble
            {
                cout<< "You cannot wager more than you have." << endl;
                cout<< "Please enter a smaller value." << endl;
                cin >> n;
                cin.clear();
                cin.ignore(1000,'\n');
            }
        }
        //if the computer is the dealer than only one of the computers cards in its hand is displayed.
        //otherwise if the player is the dealer then both of the computers cards in its hand are displayed to the player
        if (dealer == "player")
        {
            cout<< "Computer's hand is: " << compHand[0] << " " << compHand[1]<<endl;
        }
        else
        {
            cout<< "Computer's hand is: " << compHand[0]<<endl;
        }
        
        cout << "Your hand: "<< playerHand [0] << " "<< playerHand [1]<< endl;//shows player their hand
        //the following increments through the players hand and check each element in the array that has a card.
        //if the card is an Ace the player is asked if they would like that ace to be worth 1 or 11. then the playerFinal
        //value is updated for each card which keeps track of what the players hand adds up to with each card. 
        int j=0;
        while (playerHand[j]!= "" && j<=51)
        {
            
            playerCard=checkCard(playerHand[j]);
            
            if (playerCard==11)
            {
                cout << "Would you like your ace to be worth 1 or 11?"<< endl;
                cin >> playerCard;
            }
            
            playerFinal=playerFinal+playerCard;
            j++;
        }//ends the while loop
        //displays to the player what their cards add up to 
        cout << "Your hand value: " << playerFinal<< endl;
            //if the hand adds to 21 then the player is finished playing and is not asked to hit or stay because 21 is a winnning hand
            if (playerFinal==21)
            {
                cout << "Your hand value: " << playerFinal<< endl;
                
            }
            //if the players hand doesnt sum to 21 then the player is asked if they would like to hit or stay.  
            else {
            cout << "Hit or Stay" << endl;
            cin>> move;
            }
            
            //if player wants to hit, subtracts 1 from i (the card pile) checks values of cards and sums them.
            //if any cards are an ace the player is asked what value they would like it to hold (1 or 11).
        
        //if move is stay then nothing is done because the player is choosing to leave their hand the way it is
            if (move == "Stay" || move == "stay"){
            }
        //if the move is hit the player enters this while loop which allows them to keeo hitting until they choose to stop or the player
        //hits or goes over 21. 
            else if (move == "Hit" || "hit" )
            {
                
                while (move == "Hit" || "hit"){
                    hit (deck, playerHand);
                    i --;//like before a card is subtracted from the deck for every hit the player chooses
                    int j=0;
                  //after a hit the card value is checked and playerfinal is updated to see what the players hand adds up to.
                    while (playerHand[j]!= "" && j<=51)
                    {
                        j++;
                    }
                    
                    cout << playerHand [j-1]<< endl ;// card that was hit is displayed to the player
                
                    playerCard=checkCard(playerHand[j-1]);
                    
                    if (playerCard==11)// if the card is an ace the player is asked how much they want it to be worth
                    {
                        cout << "Would you like your ace to be worth 1 or 11?"<< endl;
                        cin >> playerCard;
                    }
                
                    playerFinal=playerFinal+playerCard;//playerFinal is updated 
                    j++;
                    //if playerFinal is over 21 the player is notified and the program leaves the hit while loop because the player
                    //is not allowed to continue playing after they have gone over 21( they lost, unless the computer also goes over)
                    if(playerFinal > 21)
                    {
                        cout << "You went over 21" << endl;
                        break;
                    }
                    //The over all hand value is displayed the player
                    cout << "Your hand value: " << playerFinal<< endl;
                    //the player is again asked if the want to hit or stay
                    cout << "Hit or Stay?"<<endl;
                    cin>> move;
                    //if they stay then the program exits the hit while loop and playerFinal remains where it is
                    //if player chooses to hit then the program runs through the while loop again. 
                    if (move == "Stay" || move == "stay")
                    {
                        cout << "Your hand value: " << playerFinal<< endl;
                        break;
                    }
                }
            }
           
        //the following is for the computer. checks the card values dealt. if any are A's then decides to make 1 or 11 based on
        //value of other card. if the sum of cards is less than 17, then the computer will hit. if it is more than it will stay.
        
        int compCard;
        int count=0;
        j=0;
        int m;
        while (compHand[j]!= "" && j<=51)//runs through comps hand while there are card values in it
        {
            compCard=checkCard(compHand[j]);//checks the value of the computers card
            // if the card isnt an Ace then the card is added to the computer's final hand value
            if (compCard!=11)
            {
                compFinal=compFinal+ compCard;
                
            }
            //if it is an ace then the Aces are kept track of through the count value;
            else
            {
                count=count+1;
            }
            j++;
        }//ends the while loop
        
        //this runs through to make a decision on what value any Ace should be assigned (1 or 11) if the computer is 
        //drawn one of those 
        if (count>0)
        {
            for (int k = 1; k<=count; k++)
            {
                //these run to check so that the computers hand doesnt go over 21 based on the ace values
                if (compFinal <= 10 )
                {
                    compFinal = compFinal+11;
                }
                else
                {
                    compFinal = compFinal+1;//makes the ace value 1 if the hand is worth something greater then 10.
                }
            }
            
        }
        cout << "Computer hand: "<< compHand [0] << " "<< compHand[1]<< endl;//shows player the computers hand 
        cout << "Computer move: " << compFinal<< endl;//shows how much the move was worth
        m=2;
        
        //computer will hit if their hand is worth less than 17
        while (compFinal<17)
        {
            if (playerFinal>21){//if the player final is over 21 then the computer doesnt have to make a move because it already won
                break;
            }
            hit (deck, compHand);//hit move for the computer
            i--;
            
            compCard = checkCard (compHand [m]);//checks the card that was hit
            
            //checks to see if the card is an ace again and decides what value to assign it based off of what the 
            //computers hand is worth
            if (compCard == 11 && compFinal <= 10)
            {
                
                compCard = 11;
                
            }
            
            else if (compCard == 11 && compFinal > 10)
            {
                
                compCard = 1;
                
            }
            
            
            compFinal += compCard;//updates the value of comps hand based off the hit move
            
            cout<< compHand[m]<< endl;//shows to the player the card that the computer got after the hit
            
            m++;
            
            cout << "Computer move: "<< compFinal<< endl;//displays the computers hand value
            
        }//end of while loop
        
        //checks to see if comp or player won the round
        
        //if the player is over 21 then the player looses and is displayed how much money they lost
        if (playerFinal > 21)
        {
            cout << "You lose, your hand is over 21"<<endl;
            //Gambling portion:
            cout<< "You have $"  << playerValue << endl;
        }
        //if the the computers hand is greater than the players hand and they are each under 21, then the computer wins
        //and player looses the money they had gambled
        else if (compFinal > playerFinal && compFinal <=21)
        {
            cout << "You lose, computer wins"<< endl;
            //Gambling portion:
            cout<< "You have $"  << playerValue << endl;
        }
        //if the computers hand went over 21 and the players didnt then the player wins the round and the money they gambled is added 
        //to their pot of money 
        else if (compFinal > 21 && playerFinal <= 21)
        {
            cout << "You win. Computer hand is over 21"<< endl;
            playerValue += 2*n;
            cout<< "You have $"  << playerValue << endl;
        }
        //if the players hand is greater than the computers hand and they didnt go over 21, then the player wins the round 
        //and the player gets the money that they gambled.
        else if (playerFinal > compFinal && playerFinal <=21)
        {
            cout << "You win."<< endl;
            playerValue += 2*n;
            cout<< "You have $"  << playerValue << endl;
        }
        //this is in case of tie, checks to see who dealer was and gives them the win.
        else {
            if (dealer == "player" )
            {
                cout << "You win the tie"<< endl;
                playerValue += 2*n;
                cout<< "You have $"  << playerValue << endl;
            }
            else
            {
                cout << "Computer wins the tie"<< endl;
                cout<< "You have $"  << playerValue << endl;
            }
        }
        cout << endl;
        //this only runs if the deck has less than 20 cards in it. if it does then the deck is re-initialized and shuffled so that 
        //the game can continue to run. 
        if(i< 20)
        {
            i=52;
            deck = initializeDeck();
            shuffleDeck(deck);
        }
    }
}

void printRulesRoulette()
{
    cout << "In roulette the player will choose to place bets on single number," << endl;
    cout << "red or black, and odd or even. There are numbers 0, 00, and 1 to 36." << endl;
    cout << "Numbers from 1 to 10 and 19 to 28, odd numbers are red and even are black." << endl;
    cout << "Numbers in the range of 11 to 18 and 29 to 36, odd numbers are black" << endl;
    cout << "In this specific version you'll start with $1000 and keep" << endl;
    cout << "wagering until you run out of money. This is American Roulette" << endl;
    cout << "Good luck and have fun!" << endl;
}

void printMenuRoulette()
{
    cout<< "1. Bet on red or black" << endl;
    cout<< "2. Bet on even or odd numbers" << endl;
    cout<< "3. Bet on a single number" << endl;
}

int main(int argc, const char * argv[]) {
    // QApplication a(argc, argv);
    // blackjack w;
    // w.show();
    
    
    int option;
    
    cout << "Welcome to the Casino!"<< endl;
    while (option !=3)
    {
        cout<<"1. Play a game" << endl;
        cout<<"2. About Casino" << endl;
        cout<<"3. Exit"<<endl;
        cin >> option;
        
        if (option ==1 ){
            int gameOption = 0;
            cout<< "What game would you like to play?" << endl;
            cout<< "1. Blackjack" << endl;
            cout<< "2. Go fish" << endl;
            cout<< "3. Slots" << endl;
            cout<< "4. Yahtzee" << endl;
            cout<< "5. Roulette " << endl;
            cout<< "6. Old maid" << endl;
            cout<< "7. Main menu" << endl;
            cin >> gameOption;
            
            if (gameOption == 1)
            {
                int blackjackMenu = 0;
                cout << "Lets play some Blackjack!" << endl;
                cout << "1. View rules" << endl;
                cout << "2. Play Blackjack" << endl;
                cout << "3. Go to main menu" << endl;
                cin >>blackjackMenu;
                if(blackjackMenu == 1)
                {
                    //Displays the rules for blackjack
                    displayRules();
                }
                else if (blackjackMenu == 2)
                {
                    //play the game
                    string option="";
                    string dealer = "";
                    getDealer(option, dealer);
                    string* deck = initializeDeck();
                    shuffleDeck (deck);
                    blackJack (deck, dealer);
                }
                else if (blackjackMenu == 3)
                {
                    option = 1;
                }
            }
            else if (gameOption == 2)
            {
                int goFishMenu = 0;
                cout << "Lets play some Go Fish!" << endl;
                cout << "1. View rules" << endl;
                cout << "2. Play Go Fish" << endl;
                cout << "3. Go to main menu" << endl;
                cin >> goFishMenu;
                if(goFishMenu == 1)
                {
                    //Displays the rules for go fish
                    
                }
                else if (goFishMenu == 2)
                {
                    //play the game
                }
                else if (goFishMenu == 3)
                {
                    option = 1;
                }
            }
            
            else if (gameOption == 3)
            {
                int slotsMenu = 0;
                cout << "Lets play some Slots!" << endl;
                cout << "1. View rules" << endl;
                cout << "2. Play Slots" << endl;
                cout << "3. Go to main menu" << endl;
                cin >> slotsMenu;
                if(slotsMenu == 1)
                {
                    //Displays the rules for go fish
                    
                }
                else if (slotsMenu == 2)
                {
                    //play the game
                }
                else if (slotsMenu == 3)
                {
                    option = 1;
                }
            }
            
            else if (gameOption == 4)
            {
                int yahtzeeMenu = 0;
                cout << "Lets play some Yahtzee!" << endl;
                cout << "1. View rules" << endl;
                cout << "2. Play Yahtzee" << endl;
                cout << "3. Go to main menu" << endl;
                cin >> yahtzeeMenu;
                if(yahtzeeMenu == 1)
                {
                    //Displays the rules for go fish
                    
                }
                else if (yahtzeeMenu == 2)
                {
                    //play the game
                }
                else if (yahtzeeMenu == 3)
                {
                    option = 1;
                }
            }
            else if (gameOption == 5)
            {
                int rouletteMenu = 0;
                cout << "Lets play some Roulette!" << endl;
                cout << "1. View rules" << endl;
                cout << "2. Play Roulette" << endl;
                cout << "3. Go to main menu" << endl;
                cin >> rouletteMenu;
                if(rouletteMenu == 1)
                {
                    //Displays the rules for roulette
                    printRulesRoulette();
                }
                else if (rouletteMenu == 2)
                {
                    //play the game
                    
                    printMenuRoulette();
                    int rouletteOption = 0;
                    cin >> rouletteOption;
                    if(rouletteOption == 1)
                    {
                        int playerMoney = 1000;
                        string playerColor = "";
                        int randomNumber = 0;
                        int moneyWagered = 0;
                        cout << "What color do you want to bet on: red or black?" << endl;
                        cin >> playerColor;
                        while(playerMoney > 0)
                        {
                            srand( static_cast<unsigned int>(time(NULL)));
                            randomNumber = rand() % 37;
                            cout << "How much would you like to bet?" << endl;
                            cout << "Your money: $"<< playerMoney << endl;
                            cin >> moneyWagered;
                            playerMoney = playerMoney-moneyWagered;
                            if(playerColor == "red" && (randomNumber == 1 || randomNumber == 3 || randomNumber == 5 || randomNumber == 7 || randomNumber == 9 || randomNumber == 12 || randomNumber == 14 || randomNumber == 16 || randomNumber == 18 || randomNumber == 3 || randomNumber == 19 || randomNumber == 21 || randomNumber == 23 || randomNumber == 25 || randomNumber == 27 || randomNumber == 30 ))
                                {
                                    playerMoney = playerMoney+moneyWagered*2+ moneyWagered;
                                    cout << "Number is: " << randomNumber << " it's red" << endl;
                                    cout << "Your Color: " << playerColor << endl;
                                    cout<< "You won: $" << moneyWagered << endl;
                                }
                                else if (playerColor == "black")
                                {
                                    
                                }
                        }
                        cout<< "You lost all money" << endl;
                    }
                    else if(rouletteOption == 2)
                    {
                        
                    }
                    else if(rouletteOption == 3)
                    {
                        int playerMoney = 1000;
                        string playerChoiceNumber = "";
                        int randomNumber = 0;
                        int moneyWagered = 0;
                        while(playerMoney > 0)
                        {
                            srand( static_cast<unsigned int>(time(NULL)));
                            randomNumber = rand() % 37;
                            cout << "What number would you like to bet on?" << endl;
                            cin >> playerChoiceNumber;
                            if((stoi(playerChoiceNumber) >= 0 && stoi(playerChoiceNumber) <= 36) || playerChoiceNumber == "00")
                            {
                                cout << "How much would you like to bet?" << endl;
                                cout << "Your money: $"<< playerMoney << endl;
                                cin >> moneyWagered;
                                playerMoney = playerMoney - moneyWagered;
                                if(randomNumber == 0)
                                {
                                    cout << "The number is: 0" << endl;
                                    if (playerChoiceNumber == "0")
                                    {
                                        moneyWagered = moneyWagered*35 + moneyWagered;
                                        playerMoney = playerMoney + moneyWagered;
                                        cout << "Your number: " << playerChoiceNumber << endl;
                                        cout << "You won: $" << moneyWagered << endl;
                                    }
                                    else
                                    {
                                        cout << "Your number: " << playerChoiceNumber << endl;
                                        cout << "You lost: $" << moneyWagered << endl;
                                    }
                                }
                                else if(randomNumber == 1)
                                {
                                    cout << "The number is: " << randomNumber << endl;
                                    if (playerChoiceNumber == "1")
                                    {
                                        moneyWagered = moneyWagered*35 + moneyWagered;
                                        playerMoney = playerMoney + moneyWagered;
                                        cout << "Your number: " << playerChoiceNumber << endl;
                                        cout << "You won: $" << moneyWagered << endl;
                                    }
                                    else
                                    {
                                        cout << "Your number: " << playerChoiceNumber << endl;
                                        cout << "You lost: $" << moneyWagered << endl;
                                    }
                                }
                                else if(randomNumber == 2)
                                {
                                    cout << "The number is: " << randomNumber << endl;
                                    if (playerChoiceNumber == "2")
                                    {
                                        moneyWagered = moneyWagered*35 + moneyWagered;
                                        playerMoney = playerMoney + moneyWagered;
                                        cout << "Your number: " << playerChoiceNumber << endl;
                                        cout << "You won: $" << moneyWagered << endl;
                                    }
                                    else
                                    {
                                        cout << "Your number: " << playerChoiceNumber << endl;
                                        cout << "You lost: $" << moneyWagered << endl;
                                    }
                                }
                                else if(randomNumber == 3)
                                {
                                    cout << "The number is: " << randomNumber << endl;
                                    if (playerChoiceNumber == "3")
                                    {
                                        moneyWagered = moneyWagered*35 + moneyWagered;
                                        playerMoney = playerMoney + moneyWagered;
                                        cout << "Your number: " << playerChoiceNumber << endl;
                                        cout << "You won: $" << moneyWagered << endl;
                                    }
                                    else
                                    {
                                        cout << "Your number: " << playerChoiceNumber << endl;
                                        cout << "You lost: $" << moneyWagered << endl;
                                    }
                                }
                                else if(randomNumber == 4)
                                {
                                    cout << "The number is: " << randomNumber << endl;
                                    if (playerChoiceNumber == "4")
                                    {
                                        moneyWagered = moneyWagered*35 + moneyWagered;
                                        playerMoney = playerMoney + moneyWagered;
                                        cout << "Your number: " << playerChoiceNumber << endl;
                                        cout << "You won: $" << moneyWagered << endl;
                                    }
                                    else
                                    {
                                        cout << "Your number: " << playerChoiceNumber << endl;
                                        cout << "You lost: $" << moneyWagered << endl;
                                    }
                                }
                                else if(randomNumber == 5)
                                {
                                    cout << "The number is: " << randomNumber << endl;
                                    if (playerChoiceNumber == "5")
                                    {
                                        moneyWagered = moneyWagered*35 + moneyWagered;
                                        playerMoney = playerMoney + moneyWagered;
                                        cout << "Your number: " << playerChoiceNumber << endl;
                                        cout << "You won: $" << moneyWagered << endl;
                                    }
                                    else
                                    {
                                        cout << "Your number: " << playerChoiceNumber << endl;
                                        cout << "You lost: $" << moneyWagered << endl;
                                    }
                                }
                                else if(randomNumber == 6)
                                {
                                    cout << "The number is: " << randomNumber << endl;
                                    if (playerChoiceNumber == "6")
                                    {
                                        moneyWagered = moneyWagered*35 + moneyWagered;
                                        playerMoney = playerMoney + moneyWagered;
                                        cout << "Your number: " << playerChoiceNumber << endl;
                                        cout << "You won: $" << moneyWagered << endl;
                                    }
                                    else
                                    {
                                        cout << "Your number: " << playerChoiceNumber << endl;
                                        cout << "You lost: $" << moneyWagered << endl;
                                    }
                                }
                                else if(randomNumber == 7)
                                {
                                    cout << "The number is: " << randomNumber << endl;
                                    if (playerChoiceNumber == "7")
                                    {
                                        moneyWagered = moneyWagered*35 + moneyWagered;
                                        playerMoney = playerMoney + moneyWagered;
                                        cout << "Your number: " << playerChoiceNumber << endl;
                                        cout << "You won: $" << moneyWagered << endl;
                                    }
                                    else
                                    {
                                        cout << "Your number: " << playerChoiceNumber << endl;
                                        cout << "You lost: $" << moneyWagered << endl;
                                    }
                                }
                                else if(randomNumber == 8)
                                {
                                    cout << "The number is: " << randomNumber << endl;
                                    if (playerChoiceNumber == "8")
                                    {
                                        moneyWagered = moneyWagered*35 + moneyWagered;
                                        playerMoney = playerMoney + moneyWagered;
                                        cout << "Your number: " << playerChoiceNumber << endl;
                                        cout << "You won: $" << moneyWagered << endl;
                                    }
                                    else
                                    {
                                        cout << "Your number: " << playerChoiceNumber << endl;
                                        cout << "You lost: $" << moneyWagered << endl;
                                    }
                                }
                                else if(randomNumber == 9)
                                {
                                    cout << "The number is: " << randomNumber << endl;
                                    if (playerChoiceNumber == "9")
                                    {
                                        moneyWagered = moneyWagered*35 + moneyWagered;
                                        playerMoney = playerMoney + moneyWagered;
                                        cout << "Your number: " << playerChoiceNumber << endl;
                                        cout << "You won: $" << moneyWagered << endl;
                                    }
                                    else
                                    {
                                        cout << "Your number: " << playerChoiceNumber << endl;
                                        cout << "You lost: $" << moneyWagered << endl;
                                    }
                                }
                                else if(randomNumber == 10)
                                {
                                    cout << "The number is: " << randomNumber << endl;
                                    if (playerChoiceNumber == "10")
                                    {
                                        moneyWagered = moneyWagered*35 + moneyWagered;
                                        playerMoney = playerMoney + moneyWagered;
                                        cout << "Your number: " << playerChoiceNumber << endl;
                                        cout << "You won: $" << moneyWagered << endl;
                                    }
                                    else
                                    {
                                        cout << "Your number: " << playerChoiceNumber << endl;
                                        cout << "You lost: $" << moneyWagered << endl;
                                    }
                                }
                                else if(randomNumber == 11)
                                {
                                    cout << "The number is: " << randomNumber << endl;
                                    if (playerChoiceNumber == "11")
                                    {
                                        moneyWagered = moneyWagered*35 + moneyWagered;
                                        playerMoney = playerMoney + moneyWagered;
                                        cout << "Your number: " << playerChoiceNumber << endl;
                                        cout << "You won: $" << moneyWagered << endl;
                                    }
                                    else
                                    {
                                        cout << "Your number: " << playerChoiceNumber << endl;
                                        cout << "You lost: $" << moneyWagered << endl;
                                    }
                                }
                                else if(randomNumber == 12)
                                {
                                    cout << "The number is: " << randomNumber << endl;
                                    if (playerChoiceNumber == "12")
                                    {
                                        moneyWagered = moneyWagered*35 + moneyWagered;
                                        playerMoney = playerMoney + moneyWagered;
                                        cout << "Your number: " << playerChoiceNumber << endl;
                                        cout << "You won: $" << moneyWagered << endl;
                                    }
                                    else
                                    {
                                        cout << "Your number: " << playerChoiceNumber << endl;
                                        cout << "You lost: $" << moneyWagered << endl;
                                    }
                                }
                                else if(randomNumber == 13)
                                {
                                    cout << "The number is: " << randomNumber << endl;
                                    if (playerChoiceNumber == "13")
                                    {
                                        moneyWagered = moneyWagered*35 + moneyWagered;
                                        playerMoney = playerMoney + moneyWagered;
                                        cout << "Your number: " << playerChoiceNumber << endl;
                                        cout << "You won: $" << moneyWagered << endl;
                                    }
                                    else
                                    {
                                        cout << "Your number: " << playerChoiceNumber << endl;
                                        cout << "You lost: $" << moneyWagered << endl;
                                    }
                                }
                                else if(randomNumber == 14)
                                {
                                    cout << "The number is: " << randomNumber << endl;
                                    if (playerChoiceNumber == "14")
                                    {
                                        moneyWagered = moneyWagered*35 + moneyWagered;
                                        playerMoney = playerMoney + moneyWagered;
                                        cout << "Your number: " << playerChoiceNumber << endl;
                                        cout << "You won: $" << moneyWagered << endl;
                                    }
                                    else
                                    {
                                        cout << "Your number: " << playerChoiceNumber << endl;
                                        cout << "You lost: $" << moneyWagered << endl;
                                    }
                                }
                                else if(randomNumber == 15)
                                {
                                    cout << "The number is: " << randomNumber << endl;
                                    if (playerChoiceNumber == "15")
                                    {
                                        moneyWagered = moneyWagered*35 + moneyWagered;
                                        playerMoney = playerMoney + moneyWagered;
                                        cout << "Your number: " << playerChoiceNumber << endl;
                                        cout << "You won: $" << moneyWagered << endl;
                                    }
                                    else
                                    {
                                        cout << "Your number: " << playerChoiceNumber << endl;
                                        cout << "You lost: $" << moneyWagered << endl;
                                    }
                                }
                                else if(randomNumber == 16)
                                {
                                    cout << "The number is: " << randomNumber << endl;
                                    if (playerChoiceNumber == "16")
                                    {
                                        moneyWagered = moneyWagered*35 + moneyWagered;
                                        playerMoney = playerMoney + moneyWagered;
                                        cout << "Your number: " << playerChoiceNumber << endl;
                                        cout << "You won: $" << moneyWagered << endl;
                                    }
                                    else
                                    {
                                        cout << "Your number: " << playerChoiceNumber << endl;
                                        cout << "You lost: $" << moneyWagered << endl;
                                    }
                                }
                                else if(randomNumber == 17)
                                {
                                    cout << "The number is: " << randomNumber << endl;
                                    if (playerChoiceNumber == "17")
                                    {
                                        moneyWagered = moneyWagered*35 + moneyWagered;
                                        playerMoney = playerMoney + moneyWagered;
                                        cout << "Your number: " << playerChoiceNumber << endl;
                                        cout << "You won: $" << moneyWagered << endl;
                                    }
                                    else
                                    {
                                        cout << "Your number: " << playerChoiceNumber << endl;
                                        cout << "You lost: $" << moneyWagered << endl;
                                    }
                                }
                                else if(randomNumber == 18)
                                {
                                    cout << "The number is: " << randomNumber << endl;
                                    if (playerChoiceNumber == "18")
                                    {
                                        moneyWagered = moneyWagered*35 + moneyWagered;
                                        playerMoney = playerMoney + moneyWagered;
                                        cout << "Your number: " << playerChoiceNumber << endl;
                                        cout << "You won: $" << moneyWagered << endl;
                                    }
                                    else
                                    {
                                        cout << "Your number: " << playerChoiceNumber << endl;
                                        cout << "You lost: $" << moneyWagered << endl;
                                    }
                                }
                                else if(randomNumber == 19)
                                {
                                    cout << "The number is: " << randomNumber << endl;
                                    if (playerChoiceNumber == "19")
                                    {
                                        moneyWagered = moneyWagered*35 + moneyWagered;
                                        playerMoney = playerMoney + moneyWagered;
                                        cout << "Your number: " << playerChoiceNumber << endl;
                                        cout << "You won: $" << moneyWagered << endl;
                                    }
                                    else
                                    {
                                        cout << "Your number: " << playerChoiceNumber << endl;
                                        cout << "You lost: $" << moneyWagered << endl;
                                    }
                                }
                                else if(randomNumber == 20)
                                {
                                    cout << "The number is: " << randomNumber << endl;
                                    if (playerChoiceNumber == "20")
                                    {
                                        moneyWagered = moneyWagered*35 + moneyWagered;
                                        playerMoney = playerMoney + moneyWagered;
                                        cout << "Your number: " << playerChoiceNumber << endl;
                                        cout << "You won: $" << moneyWagered << endl;
                                    }
                                    else
                                    {
                                        cout << "Your number: " << playerChoiceNumber << endl;
                                        cout << "You lost: $" << moneyWagered << endl;
                                    }
                                }
                                else if(randomNumber == 21)
                                {
                                    cout << "The number is: " << randomNumber << endl;
                                    if (playerChoiceNumber == "21")
                                    {
                                        moneyWagered = moneyWagered*35 + moneyWagered;
                                        playerMoney = playerMoney + moneyWagered;
                                        cout << "Your number: " << playerChoiceNumber << endl;
                                        cout << "You won: $" << moneyWagered << endl;
                                    }
                                    else
                                    {
                                        cout << "Your number: " << playerChoiceNumber << endl;
                                        cout << "You lost: $" << moneyWagered << endl;
                                    }
                                }
                                else if(randomNumber == 22)
                                {
                                    cout << "The number is: " << randomNumber << endl;
                                    if (playerChoiceNumber == "22")
                                    {
                                        moneyWagered = moneyWagered*35 + moneyWagered;
                                        playerMoney = playerMoney + moneyWagered;
                                        cout << "Your number: " << playerChoiceNumber << endl;
                                        cout << "You won: $" << moneyWagered << endl;
                                    }
                                    else
                                    {
                                        cout << "Your number: " << playerChoiceNumber << endl;
                                        cout << "You lost: $" << moneyWagered << endl;
                                    }
                                }
                                else if(randomNumber == 23)
                                {
                                    cout << "The number is: " << randomNumber << endl;
                                    if (playerChoiceNumber == "23")
                                    {
                                        moneyWagered = moneyWagered*35 + moneyWagered;
                                        playerMoney = playerMoney + moneyWagered;
                                        cout << "Your number: " << playerChoiceNumber << endl;
                                        cout << "You won: $" << moneyWagered << endl;
                                    }
                                    else
                                    {
                                        cout << "Your number: " << playerChoiceNumber << endl;
                                        cout << "You lost: $" << moneyWagered << endl;
                                    }
                                }
                                else if(randomNumber == 24)
                                {
                                    cout << "The number is: " << randomNumber << endl;
                                    if (playerChoiceNumber == "24")
                                    {
                                        moneyWagered = moneyWagered*35 + moneyWagered;
                                        playerMoney = playerMoney + moneyWagered;
                                        cout << "Your number: " << playerChoiceNumber << endl;
                                        cout << "You won: $" << moneyWagered << endl;
                                    }
                                    else
                                    {
                                        cout << "Your number: " << playerChoiceNumber << endl;
                                        cout << "You lost: $" << moneyWagered << endl;
                                    }
                                }
                                else if(randomNumber == 25)
                                {
                                    cout << "The number is: " << randomNumber << endl;
                                    if (playerChoiceNumber == "25")
                                    {
                                        moneyWagered = moneyWagered*35 + moneyWagered;
                                        playerMoney = playerMoney + moneyWagered;
                                        cout << "Your number: " << playerChoiceNumber << endl;
                                        cout << "You won: $" << moneyWagered << endl;
                                    }
                                    else
                                    {
                                        cout << "Your number: " << playerChoiceNumber << endl;
                                        cout << "You lost: $" << moneyWagered << endl;
                                    }
                                }
                                else if(randomNumber == 26)
                                {
                                    cout << "The number is: " << randomNumber << endl;
                                    if (playerChoiceNumber == "26")
                                    {
                                        moneyWagered = moneyWagered*35 + moneyWagered;
                                        playerMoney = playerMoney + moneyWagered;
                                        cout << "Your number: " << playerChoiceNumber << endl;
                                        cout << "You won: $" << moneyWagered << endl;
                                    }
                                    else
                                    {
                                        cout << "Your number: " << playerChoiceNumber << endl;
                                        cout << "You lost: $" << moneyWagered << endl;
                                    }
                                }
                                else if(randomNumber == 27)
                                {
                                    cout << "The number is: " << randomNumber << endl;
                                    if (playerChoiceNumber == "27")
                                    {
                                        moneyWagered = moneyWagered*35 + moneyWagered;
                                        playerMoney = playerMoney + moneyWagered;
                                        cout << "Your number: " << playerChoiceNumber << endl;
                                        cout << "You won: $" << moneyWagered << endl;
                                    }
                                    else
                                    {
                                        cout << "Your number: " << playerChoiceNumber << endl;
                                        cout << "You lost: $" << moneyWagered << endl;
                                    }
                                }
                                else if(randomNumber == 28)
                                {
                                    cout << "The number is: " << randomNumber << endl;
                                    if (playerChoiceNumber == "28")
                                    {
                                        moneyWagered = moneyWagered*35 + moneyWagered;
                                        playerMoney = playerMoney + moneyWagered;
                                        cout << "Your number: " << playerChoiceNumber << endl;
                                        cout << "You won: $" << moneyWagered << endl;
                                    }
                                    else
                                    {
                                        cout << "Your number: " << playerChoiceNumber << endl;
                                        cout << "You lost: $" << moneyWagered << endl;
                                    }
                                }
                                else if(randomNumber == 29)
                                {
                                    cout << "The number is: " << randomNumber << endl;
                                    if (playerChoiceNumber == "29")
                                    {
                                        moneyWagered = moneyWagered*35 + moneyWagered;
                                        playerMoney = playerMoney + moneyWagered;
                                        cout << "Your number: " << playerChoiceNumber << endl;
                                        cout << "You won: $" << moneyWagered << endl;
                                    }
                                    else
                                    {
                                        cout << "Your number: " << playerChoiceNumber << endl;
                                        cout << "You lost: $" << moneyWagered << endl;
                                    }
                                }
                                else if(randomNumber == 30)
                                {
                                    cout << "The number is: " << randomNumber << endl;
                                    if (playerChoiceNumber == "30")
                                    {
                                        moneyWagered = moneyWagered*35 + moneyWagered;
                                        playerMoney = playerMoney + moneyWagered;
                                        cout << "Your number: " << playerChoiceNumber << endl;
                                        cout << "You won: $" << moneyWagered << endl;
                                    }
                                    else
                                    {
                                        cout << "Your number: " << playerChoiceNumber << endl;
                                        cout << "You lost: $" << moneyWagered << endl;
                                    }
                                }
                                else if(randomNumber == 31)
                                {
                                    cout << "The number is: " << randomNumber << endl;
                                    if (playerChoiceNumber == "31")
                                    {
                                        moneyWagered = moneyWagered*35 + moneyWagered;
                                        playerMoney = playerMoney + moneyWagered;
                                        cout << "Your number: " << playerChoiceNumber << endl;
                                        cout << "You won: $" << moneyWagered << endl;
                                    }
                                    else
                                    {
                                        cout << "Your number: " << playerChoiceNumber << endl;
                                        cout << "You lost: $" << moneyWagered << endl;
                                    }
                                }
                                else if(randomNumber == 32)
                                {
                                    cout << "The number is: " << randomNumber << endl;
                                    if (playerChoiceNumber == "32")
                                    {
                                        moneyWagered = moneyWagered*35 + moneyWagered;
                                        playerMoney = playerMoney + moneyWagered;
                                        cout << "Your number: " << playerChoiceNumber << endl;
                                        cout << "You won: $" << moneyWagered << endl;
                                    }
                                    else
                                    {
                                        cout << "Your number: " << playerChoiceNumber << endl;
                                        cout << "You lost: $" << moneyWagered << endl;
                                    }
                                }
                                else if(randomNumber == 33)
                                {
                                    cout << "The number is: " << randomNumber << endl;
                                    if (playerChoiceNumber == "33")
                                    {
                                        moneyWagered = moneyWagered*35 + moneyWagered;
                                        playerMoney = playerMoney + moneyWagered;
                                        cout << "Your number: " << playerChoiceNumber << endl;
                                        cout << "You won: $" << moneyWagered << endl;
                                    }
                                    else
                                    {
                                        cout << "Your number: " << playerChoiceNumber << endl;
                                        cout << "You lost: $" << moneyWagered << endl;
                                    }
                                }
                                else if(randomNumber == 34)
                                {
                                    cout << "The number is: " << randomNumber << endl;
                                    if (playerChoiceNumber == "34")
                                    {
                                        moneyWagered = moneyWagered*35 + moneyWagered;
                                        playerMoney = playerMoney + moneyWagered;
                                        cout << "Your number: " << playerChoiceNumber << endl;
                                        cout << "You won: $" << moneyWagered << endl;
                                    }
                                    else
                                    {
                                        cout << "Your number: " << playerChoiceNumber << endl;
                                        cout << "You lost: $" << moneyWagered << endl;
                                    }
                                }
                                else if(randomNumber == 35)
                                {
                                    cout << "The number is: " << randomNumber << endl;
                                    if (playerChoiceNumber == "35")
                                    {
                                        moneyWagered = moneyWagered*35 + moneyWagered;
                                        playerMoney = playerMoney + moneyWagered;
                                        cout << "Your number: " << playerChoiceNumber << endl;
                                        cout << "You won: $" << moneyWagered << endl;
                                    }
                                    else
                                    {
                                        cout << "Your number: " << playerChoiceNumber << endl;
                                        cout << "You lost: $" << moneyWagered << endl;
                                    }
                                }
                                else if(randomNumber == 36)
                                {
                                    cout << "The number is: " << randomNumber << endl;
                                    if (playerChoiceNumber == "36")
                                    {
                                        moneyWagered = moneyWagered*35 + moneyWagered;
                                        playerMoney = playerMoney + moneyWagered;
                                        cout << "Your number: " << playerChoiceNumber << endl;
                                        cout << "You won: $" << moneyWagered << endl;
                                    }
                                    else
                                    {
                                        cout << "Your number: " << playerChoiceNumber << endl;
                                        cout << "You lost: $" << moneyWagered << endl;
                                    }
                                }
                                else if(randomNumber == 37)
                                {
                                    cout << "The number is: 00" << endl;
                                    if (playerChoiceNumber == "00")
                                    {
                                        moneyWagered = moneyWagered*35 + moneyWagered;
                                        playerMoney = playerMoney + moneyWagered;
                                        cout << "Your number: " << playerChoiceNumber << endl;
                                        cout << "You won: $" << moneyWagered << endl;
                                    }
                                    else
                                    {
                                        cout << "Your number: " << playerChoiceNumber << endl;
                                        cout << "You lost: $" << moneyWagered << endl;
                                    }
                                }
                            }
                        }
                    }
                else if (rouletteMenu == 3)
                {
                    option = 1;
                }
            }
            else if (gameOption == 6)
            {
                int oldMaidMenu = 0;
                cout << "Lets play some Old Maid!" << endl;
                cout << "1. View rules" << endl;
                cout << "2. Play Old Maid" << endl;
                cout << "3. Go to main menu" << endl;
                cin >> oldMaidMenu;
                if(oldMaidMenu == 1)
                {
                    //Displays the rules for go fish
                    
                }
                else if (oldMaidMenu == 2)
                {
                    //play the game
                }
                else if (oldMaidMenu == 3)
                {
                    option = 1;
                }
            }
            else if (gameOption == 7)
            {
                option = 1;
            }
        }
        
        
        else if (option == 2){
            //Who made the games, about betting casino stuff
            
        }
        
        else if (option == 3){
            
            cout << "Thanks for playing!" << endl;
            exit(0);
        }
    }
  }
}

