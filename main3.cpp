//  main.cpp
//  Black Jack


//#include "blackjack.h"
//#include <QApplication>

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

//This method displays the Dice Face Numbers.
void displaydice(int array[])
{
    cout << endl<< "Dice Face Numbers: " << endl;
    for (int k=0; k<5; k++)
    {
        cout << array[k] << " ";
    }
    cout<<endl <<endl;
}

//This method sorts the dice in order from largest at index 0 and smallest at index 4.
int* sortarray(int array[])
{
    int temp=0;
    for (int j=0; j<6; j++)
    {
        for (int i=0; i<4; i++)
        {
            //Checks if the value after the current index is larger. If it is the value is switched with the current index.
            if (array[i]<array[i+1])
            {
                temp = array[i+1];
                array[i+1]=array[i];
                array[i] = temp;
            }
        }
    }
    return array;
}

//This method removes a dice from the roll and so that those dice can be re-rolled in the next round.
int* RemoveDice(int array[], int facenum, int num)
{
    int counter = 0;
    for (int i=0; i<5; i++)
    {
        //Checks if the dicenumber is in the array, if it is and has not already been removed then the dicenumber is removed from the array.
        if(array[i]==facenum && counter!=num)
        {
            array[i]=0;
            counter++;
        }
    }
    sortarray(array);
    return array;
}

//This is the method for the game.  It allows the player to roll 3 times and generate random rolls.
int* game(int randarray[])
{
    string Roll="";
    string choice = "";
    srand((unsigned)time(NULL));
    
    int diceToRoll = 0;
    int rerollnum = 0;
    int counter = 5;
    int Rerollnum = 0;
    
    //This is the loop for the three rounds in order to be able to re-roll twice.
    for (int i=0; i<=2; i++)
    {
        cout << endl << "Would you like to roll the dice? Please enter Yes or No?" << endl;
        cin >> Roll;
        if (Roll=="No")
        {
            break;
        }
        
        //This loop generates 5 random number from 1-6.
        //These numbers are then stored in randarray.
        for (int j=(diceToRoll); j<=4; j++)
        {
            int randomnum;
            randomnum = (rand() % 6 + 1);
            randarray[j] = randomnum;
        }
        
        //Displays the dice
        displaydice(randarray);
        
        //counter is to keep track of how many dice are taken out of the roll to be re-rolled.
        counter=5;
        //This loop checks if any dice need to be re-rolled.  If dice do need to be re-rolled, the number and frequency the die are asked.
        while (counter>0)
        {
            if (i==2)
            {
                break;
                break;
            }
            cout << "Are there any dice you would like to re-roll? Please enter Yes or No?" <<endl;
            cin >> choice;
            if (choice=="No")
            {
                //Adjusts counter if no.
                for (int k=0; k<5; k++)
                {
                    if (randarray[k]==0)
                    {
                        counter--;
                    }
                }
                
                diceToRoll=counter;
                break;
                
            }
            cout << endl <<"Enter the number that is on the dice face for one of the die you want to get rid of." <<endl;
            cin >> rerollnum;
            cout << "How many die of that dice face number would you like to re-roll?" <<endl;
            cin >> Rerollnum;
            //Removes the dice from randarray
            RemoveDice(randarray,rerollnum,Rerollnum);
            
            displaydice(randarray);
        }
        
    }
    //The array is sorted so that when the ScoreTracker is run the dice values will be organized and easier to handle.
    sortarray(randarray);
    return randarray;
}

//This method calculates the sum of the dice.
int Chance(int array[])
{
    int sum = 0;
    for (int i=0; i<5; i++)
    {
        sum = sum + array[i];
    }
    return sum;
}

//This method adds all the aces in the dice.  Then returns the sum of the aces.
int AddingAce(int array[])
{
    int sum = 0;
    for ( int i=0; i<5; i++)
    {
        if (array[i]==1){
            sum = sum+1;
        }
    }
    return sum;
}

//This method adds all the twos in the dice.  Then returns the sum of the twos.
int AddingTwos(int array[])
{
    int sum = 0;
    for ( int i=0; i<5; i++)
    {
        if (array[i]==2)
        {
            sum = sum+2;
        }
    }
    return sum;
}

//This method adds all the threes in the dice.  Then returns the sum of the threes.
int AddingThrees(int array[])
{
    int sum = 0;
    for ( int i=0; i<5; i++)
    {
        if (array[i]==3)
        {
            sum = sum+3;
        }
    }
    return sum;
}

//This method adds all the fours in the dice.  Then returns the sum of the fours.
int AddingFours(int array[])
{
    int sum = 0;
    for ( int i=0; i<5; i++)
    {
        if (array[i]==4)
        {
            sum = sum+4;
        }
    }
    return sum;
}

//This method adds all the fives in the dice.  Then returns the sum of the fives.
int AddingFives(int array[])
{
    int sum = 0;
    for ( int i=0; i<5; i++)
    {
        if (array[i]==5)
        {
            sum = sum+5;
        }
    }
    return sum;
}

//This method adds all the sixes in the dice.  Then returns the sum of the sixes.
int AddingSixes(int array[])
{
    int sum = 0;
    for ( int i=0; i<5; i++)
    {
        if (array[i]==6)
        {
            sum = sum+6;
        }
    }
    return sum;
}

//This method checks for a three of a kind.
int ThreeOfAKind(int array[])
{
    int value=0;
    for (int i=0; i<3;i++)
    {
        //checks the values in the next two indexes with the current index to see if they are equal.
        if (array[i]==array[i+1] && array[i+1]==array[i+2])
        {
            value = array[i];
            //returns the sum if found.
            return Chance(array);
        }
        
    }
    return value;
}

//This method checks for a fourth of a kind.
int FourOfAKind(int array[])
{
    int value=0;
    for (int i=0; i<2;i++)
    {
        //Checks if 4 die are the same.
        if (array[i]==array[i+1] && array[i+1]==array[i+2] && array[i+2]==array[i+3])
        {
            value = array[i];
            //returns the sum if found.
            return Chance(array);
        }
        
    }
    return value;
}

//This method checks for a Full house which is a three of a kind and a two of a kind.
int FullHouse(int array[])
{
    if (array[0]==array[1] && array[1]==array[2] && array[3]==array[4])
    {
        return 25;
    }
    if (array[0]==array[1] && array[2]==array[3] && array[3]==array[4])
    {
        return 25;
    }
    return 0;
}

//This method checks for a small straight which is 4 numbers in a sequential sequence.
int SmallStraight(int array[])
{
    if ((array[0]==6  && array[1]==5 && array[2]==4 && array[3]==3) || (array[1]==6  && array[2]==5 && array[3]==4 && array[4]==3))
    {
        return 30;
    }
    if ((array[0]==5  && array[1]==4 && array[2]==3 && array[3]==2) || (array[1]==5  && array[2]==4 && array[3]==3 && array[4]==2))
    {
        return 30;
    }
    if ((array[0]==4  && array[1]==3 && array[2]==2 && array[3]==1) || (array[1]==4  && array[2]==3 && array[3]==2 && array[4]==1))
    {
        return 30;
    }
    return 0;
}

//This method checks for a large straight which is 5 numbers in a sequential sequence.
int LargeStraight(int array[])
{
    if ((array[0]==5  && array[1]==4  && array[2]==3  && array[3]==2  && array[4]==1) || (array[0]==6  && array[1]==5  && array[2]==4  && array[3]==3  && array[4]==2))
    {
        return 40;
    }
    return 0;
}

//This method checks for a Yahtzee which is when all 5 die are the same number.
int Yahtzee(int array[])
{
    if (array[0]==array[1] && array[1]==array[2] && array[2]==array[3] && array[3]==array[4] )
    {
        return 50;
    }
    return 0;
}

//Displays the score of the player or current turn.
void displayScore(int array[])
{
    cout << "1. Aces: " << array[0] << endl;
    cout << "2. Twos: " << array[1] << endl;
    cout << "3. Threes: " << array[2] << endl;
    cout << "4. Fours: " << array[3] << endl;
    cout << "5. Fives: " << array[4] << endl;
    cout << "6. Sixes: " << array[5] << endl;
    cout << "7. Three of a Kind: " << array[6] << endl;
    cout << "8. Four of A Kind: " << array[7] << endl;
    cout << "9. Full House: " << array[8] << endl;
    cout << "10. Small Straight: " << array[9] << endl;
    cout << "11. Large Straight: " << array[10] << endl;
    cout << "12. Yahtzee: " << array[11] << endl;
    cout << "13. Chance: " << array[12] << endl<<endl;
}

//Calculates the score and puts each into a score array.
int * ScoreCalculator(int array[], int scorearray[])
{
    scorearray[0] = AddingAce(array);
    scorearray[1] = AddingTwos(array);
    scorearray[2] = AddingThrees(array);
    scorearray[3] = AddingFours(array);
    scorearray[4] = AddingFives(array);
    scorearray[5] = AddingSixes(array);
    scorearray[6] = ThreeOfAKind(array);
    scorearray[7] = FourOfAKind(array);
    scorearray[8] = FullHouse(array);
    scorearray[9] = SmallStraight(array);
    scorearray[10] = LargeStraight(array);
    scorearray[11] = Yahtzee(array);
    scorearray[12] = Chance(array);
    
    displayScore(scorearray);
    return scorearray;
}

//This method calculates the player's current score.
int *CurrentPlayerScore(int array[], int scoretracker[])
{
    int score=0;
    int count=0;
    int counter=0;
    
    //This loop checks if there are any possible places to put in a score.
    for (int i=0; i<13; i++)
    {
        if ((array[i]==0 && scoretracker[i]==0) || (array[i]!=0))
        {
            counter++;
        }
    }
    
    //If the value of the previous loop is found to be 13 then a zero must be inputed into the player score.
    if (counter==13)
    {
        while(true)
        {
            cout << "Which score would you like to assign a value to? (1,2,3,4,5,6,7,8,9,10,11,12,13?). A zero must be inputed for a score.";
            cin>>score;
            if (array[score-1]==0)
            {
                break;
            }
            
            if (array[score-1]!=0)
            {
                cout << "Invalid Score Assignment. Please choose a score that has a value of zero." <<endl<<endl;
            }
        }
        
        //Assigns 1111 to the current player score which in this case is a placeholder for zero.
        array[score]=1111;
        return array;
    }
    
    
    while(true)
    {
        cout << "Which score would you like to assign a value to? (1,2,3,4,5,6,7,8,9,10,11,12,13?)";
        cin>>score;
        if (array[score-1]==0 && scoretracker[score-1]!=0)
        {
            break;
        }
        //checks if there is a non-zero value in the current location.
        if (array[score-1]!=0 || scoretracker[score-1]==0)
        {
            cout << "Invalid Score Assignment. Please choose a score that does not have a value." <<endl<<endl;
        }
    }
    //replaces the zero in the playerscore with the score found in the turn.
    array[score-1]=scoretracker[score-1];
    //checks to see if all values in the player score are filled.
    for (int i=0; i<13; i++)
    {
        if (array[i]!=0)
        {
            count++;
        }
    }
    
    //if counter is 13, the player scoreboard has been filled and the game is complete.
    if (count==13)
    {
        cout << "The game is complete." <<endl;
        displayScore(array);
    }
    return array;
}

//This method displays the rules of Yahtzee.
void YahtzeeRules()
{
    cout << "RULES OF YAHTZEE" << endl <<  endl;
    cout << "During the game, the player will have five dice to roll in a round" << endl;
    cout << "Each round the player will have the option to remove die from the current roll to re-roll in the next round" << endl;
    cout << "There are a total of three rolls in one run.  So you have the option to re-roll twice to get a better set of die." << endl;
    cout << "After the round is over a score tab will be displayed and then the player can choose which score to keep out of the inital 13 possible scores"<< endl;
    cout << "Please keep in mind that once a score has been recorded that score may not be altered in later turns" << endl;
    cout << "If no score can be changed, then the player must elect to put a zero in one of the remaining spots" << endl;
    cout << "Once all the spots have been filled, the game is over and a total score is calculated." << endl << endl;
    cout << "Scoring in Yahtzee" << endl;
    cout << "1111 Denotes that a score for that value is taken away and not caluculated in the total score"<< endl;
    cout << "Ace score is computed by adding all the ones in the set of die." << endl;
    cout << "Twos score is computed by adding all the twos in the set of die." << endl;
    cout << "Threes score is computed by adding all the threes in the set of die." << endl;
    cout << "Fours score is computed by adding all the fours in the set of die." << endl;
    cout << "Fives score is computed by adding all the fives in the set of die." << endl;
    cout << "Sixes score is computed by adding all the sixes in the set of die." << endl;
    cout << "Three of a Kind is when 3 of the die in the set are all the same face number.  The score given to a three of a kind is the sum of all the die." << endl;
    cout << "Four of a Kind is when 4 of the die in the set are all the same face number.  The score given to a four of a kind is the sum of all the die." << endl;
    cout << "A Small Straight is found when 4 of the die are in chronological order.  For example: '1234'.  The score given to a small straight is 30."<< endl;
    cout << "A Large Straight is found when 5 of the die are in chronological order.  For example: '12345'.  The score given to a large straight is 40." << endl;
    cout << "Yahtzee is when all the die are the same face number.  The score is given to a yahtzee is 50." << endl;
    cout << "Chance is just the sum of all the die." << endl << endl;
}

//This is the master method for Yahtzee that executes the entire game.
void MasterYahtzee()
{
    int randarray[5];
    int ScoreTracker[14];
    int PlayerScore[14];
    int TotalScore = 0;
    string exitop;
    
    //This loop assigns zero values to all the scores in player score.
    for (int i=0; i<14; i++)
    {
        PlayerScore[i]=0;
    }
    //This loop assigns zero values to all the scores in the turn score.
    for (int i=0; i<14; i++)
    {
        ScoreTracker[i]=0;
    }
    //This loop runs thirteen times in order to fill up the entire score board for the player.
    for (int i=0; i<13; i++)
    {
        //Option to exit the game.
        cout << "Would you like to return to the main menu? Please type Yes or No." << endl;
        cin>>exitop;
        if (exitop=="Yes")
        {
            break;
        }
        game(randarray);
        cout << endl << "Possible Scores for Player Score: "<<endl;
        ScoreCalculator(randarray,ScoreTracker);
        CurrentPlayerScore(PlayerScore, ScoreTracker);
        cout <<endl<< "Current Player Score is: "<<endl<< endl;
        displayScore(PlayerScore);
        
        //This is the total score that is calculated after every turn.
        TotalScore=0;
        for (int i=0; i<13;i++)
        {
            //If playerscore is 1111 we know that that value is zero so zero is added to total score.
            if (PlayerScore[i]==1111)
            {
                TotalScore = TotalScore+0;
            }
            else{
                TotalScore = TotalScore + PlayerScore[i];
            }
            
        }
        cout << "Total Score is: " << TotalScore << endl << endl;
    }
}

// Displays the rules for
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
    string* deck = new string [52];
    string cardNum = "";
    
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
            cardNum = to_string(i+2);
        }
        deck[i]= cardNum + "S";
        
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
            cardNum = to_string(i+2);
        }
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
            cardNum = to_string(i+2);
        }
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
            cardNum = to_string(i+2);
        }
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
    //random_shuffle(deck->begin(), deck->end());
    
    
    //string hold will hold the value of deck[i] so that we may set the random spot in the deck to the value of deck[i]
    string hold;
    srand( static_cast<unsigned int>(time(NULL)));
    for (int i = 0; i <52; i++)
    {
        for (int i=0; i<52; i++) {
            int r = rand() % 52;  // generate a random position
            string temp = deck[i];
            //the deck at [i] now becomes the value of the deck at the spot of the random integer
            deck[i] = deck[r];
            deck[r] = temp;
        }
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
            move = "stay";
            
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
                else if (playerFinal == 21)
                {
                    move = "stay";
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
// Starts the slot game
void slots()
{
    int credits = 100;
    int lineNumber;
    string cont;
    while (true) {
        if(credits>=0)
        {
            cout << "How many lines would you like to bet? (1, 3, 5, or 7)";
            cin >> lineNumber;
            
            if (lineNumber != 1 && lineNumber != 3 && lineNumber != 5 && lineNumber != 7) {
                
                while (lineNumber != 1 && lineNumber != 3 && lineNumber != 5 && lineNumber != 7) {
                    
                    cout << "Invalid input, try again! How many lines would you like to bet? (1, 3, 5, or 7)";
                    cin >> lineNumber;
                    
                }
            }
            
            
            int oneOne = rand() % 3 + 1;
            int oneTwo = rand() % 3 + 1;
            int oneThree = rand() % 3 + 1;
            int oneFour = rand() % 3 + 1;
            int oneFive = rand() % 3 + 1;
            int twoOne = rand() % 3 + 1;
            int twoTwo = rand() % 3 + 1;
            int twoThree = rand() % 3 + 1;
            int twoFour = rand() % 3 + 1;
            int twoFive = rand() % 3 + 1;
            int threeOne = rand() % 3 + 1;
            int threeTwo = rand() % 3 + 1;
            int threeThree = rand() % 3 + 1;
            int threeFour = rand() % 3 + 1;
            int threeFive = rand() % 3 + 1;
            
            
            if (lineNumber == 1) {
                int cost = 1;
                credits = credits - cost;
                
                cout << oneOne << " | " << oneTwo << " | " << oneThree << " | " << oneFour << " | " << oneFive << endl;
                cout << twoOne << " | " << twoTwo << " | " << twoThree << " | " << twoFour << " | " << twoFive << endl;
                cout << threeOne << " | " << threeTwo << " | " << threeThree << " | " << threeFour << " | " << threeFive << endl;
                
                if (twoOne == twoTwo == twoThree == twoFour == twoFive) {
                    cout << "You won!" << endl;
                    cout << "Credits won: 10" << endl;
                    credits += 10;
                    
                }
                else {
                    cout << "You lost! Try again?" << endl;
                    cout << "Current Credits: " << credits << endl;
                }
            }
            
            else if (lineNumber == 3) {
                int cost = 3;
                
                credits = credits - cost;
                
                cout << oneOne << " | " << oneTwo << " | " << oneThree << " | " << oneFour << " | " << oneFive << endl;
                cout << twoOne << " | " << twoTwo << " | " << twoThree << " | " << twoFour << " | " << twoFive << endl;
                cout << threeOne << " | " << threeTwo << " | " << threeThree << " | " << threeFour << " | " << threeFive << endl;
                
                if (oneOne == oneTwo == oneThree == oneFour == oneFive && twoOne == twoTwo == twoThree == twoFour == twoFive && threeOne == threeTwo == threeThree == threeFour == threeFive) {
                    cout << "You got all 3?! That's insane!" << endl;
                    cout << "Credits won: 75" << endl;
                    credits += 75;
                }
                else if (oneOne == oneTwo == oneThree == oneFour == oneFive && twoOne == twoTwo == twoThree == twoFour == twoFive) {
                    cout << "You got 2 lines to match! Well done!" << endl;
                    cout << "Credits won: 25" << endl;
                    credits += 25;
                }
                else if (oneOne == oneTwo == oneThree == oneFour == oneFive && threeOne == threeTwo == threeThree == threeFour == threeFive) {
                    cout << "You got 2 lines to match! Well done!" << endl;
                    cout << "Credits won: 25" << endl;
                    credits += 25;
                    
                }
                else if (twoOne == twoTwo == twoThree == twoFour == twoFive && threeOne == threeTwo == threeThree == threeFour == threeFive) {
                    cout << "You got 2 lines to match! Well done!" << endl;
                    cout << "Credits won: 25" << endl;
                    credits += 25;
                    
                }
                else if (twoOne == twoTwo == twoThree == twoFour == twoFive) {
                    cout << "You got 1 line to match! Nice spin!" << endl;
                    cout << "Credits won: 10" << endl;
                    credits += 10;
                    
                }
                else if (oneOne == oneTwo == oneThree == oneFour == oneFive) {
                    cout << "You got 1 line to match! Nice spin!" << endl;
                    cout << "Credits won: 10" << endl;
                    credits += 10;
                    
                }
                else if (threeOne == threeTwo == threeThree == threeFour == threeFive) {
                    cout << "You got 1 line to match! Nice spin!" << endl;
                    cout << "Credits won: 10" << endl;
                    credits += 10;
                    
                }
                else {
                    cout << "You lost! Try again?" << endl;
                    cout << "Current Credits: " << credits << endl;
                }
            }
            else if (lineNumber == 5) {
                int cost = 5;
                credits = credits - cost;
                
                cout << oneOne << " | " << oneTwo << " | " << oneThree << " | " << oneFour << " | " << oneFive << endl;
                cout << twoOne << " | " << twoTwo << " | " << twoThree << " | " << twoFour << " | " << twoFive << endl;
                cout << threeOne << " | " << threeTwo << " | " << threeThree << " | " << threeFour << " | " << threeFive << endl;
                
                
                if (oneOne == oneTwo == oneThree == oneFour == oneFive == twoOne == twoTwo == twoThree == twoFour == twoFive == threeOne == threeTwo == threeThree == threeFour == threeFive) {
                    cout << "Do my eyes deceive me? Did you really just get all 5??!?" << endl;
                    cout << "Credits won: 500" << endl;
                    credits += 500;
                    
                }
                else if (oneOne == oneTwo == oneThree == oneFour == oneFive && twoOne == twoTwo == twoThree == twoFour == twoFive && threeOne == threeTwo == threeThree == threeFour == threeFive && oneOne == twoTwo == threeThree == twoFour == oneFive) {
                    cout << "You got 4 lines to match! Holy cow!" << endl;
                    cout << "Credits won: 200" << endl;
                    credits += 200;
                }
                else if (oneOne == oneTwo == oneThree == oneFour == oneFive && twoOne == twoTwo == twoThree == twoFour == twoFive && threeOne == threeTwo == threeThree == threeFour == threeFive && threeOne == twoTwo == oneThree == twoFour == threeFive) {
                    cout << "You got 4 lines to match! Holy cow!" << endl;
                    cout << "Credits won: 200" << endl;
                    credits += 200;
                }
                else if (oneOne == oneTwo == oneThree == oneFour == oneFive && twoOne == twoTwo == twoThree == twoFour == twoFive && oneOne == twoTwo == threeThree == twoFour == oneFive && threeOne == twoTwo == oneThree == twoFour == threeFive) {
                    cout << "You got 4 lines to match! Holy cow!" << endl;
                    cout << "Credits won: 200" << endl;
                    credits += 200;
                }
                else if (oneOne == oneTwo == oneThree == oneFour == oneFive && oneOne == twoTwo == threeThree == twoFour == oneFive && threeOne == threeTwo == threeThree == threeFour == threeFive && threeOne == twoTwo == oneThree == twoFour == threeFive) {
                    cout << "You got 4 lines to match! Holy cow!" << endl;
                    cout << "Credits won: 200" << endl;
                    credits += 200;
                }
                else if (oneOne == twoTwo == threeThree == twoFour == oneFive && twoOne == twoTwo == twoThree == twoFour == twoFive && threeOne == threeTwo == threeThree == threeFour == threeFive && threeOne == twoTwo == oneThree == twoFour == threeFive) {
                    cout << "You got 4 lines to match! Holy cow!" << endl;
                    cout << "Credits won: 200" << endl;
                    credits += 200;
                }
                else if (oneOne == oneTwo == oneThree == oneFour == oneFive && twoOne == twoTwo == twoThree == twoFour == twoFive && threeOne == threeTwo == threeThree == threeFour == threeFive) {
                    cout << "You got 3 lines to match! Well done!" << endl;
                    cout << "Credits won: 75" << endl;
                    credits += 75;
                }
                else if (oneOne == twoTwo == threeThree == twoFour == oneFive && twoOne == twoTwo == twoThree == twoFour == twoFive && threeOne == threeTwo == threeThree == threeFour == threeFive) {
                    cout << "You got 3 lines to match! Well done!" << endl;
                    cout << "Credits won: 75" << endl;
                    credits += 75;
                }
                else if (oneOne == twoTwo == threeThree == twoFour == oneFive && twoOne == twoTwo == twoThree == twoFour == twoFive && oneOne == oneTwo == oneThree == oneFour == oneFive) {
                    cout << "You got 3 lines to match! Well done!" << endl;
                    cout << "Credits won: 75" << endl;
                    credits += 75; //YES
                }
                else if (oneOne == oneTwo == oneThree == oneFour == oneFive && oneOne == twoTwo == threeThree == twoFour == oneFive && threeOne == threeTwo == threeThree == threeFour == threeFive) {
                    cout << "You got 3 lines to match! Well done!" << endl;
                    cout << "Credits won: 75" << endl;
                    credits += 75;
                }
                else if (oneOne == oneTwo == oneThree == oneFour == oneFive && oneOne == twoTwo == threeThree == twoFour == oneFive && threeOne == twoTwo == oneThree == twoFour == threeFive) {
                    cout << "You got 3 lines to match! Well done!" << endl;
                    cout << "Credits won: 75" << endl;
                    credits += 75;
                }
                else if (oneOne == oneTwo == oneThree == oneFour == oneFive && twoOne == twoTwo == twoThree == twoFour == twoFive && threeOne == twoTwo == oneThree == twoFour == threeFive) {
                    cout << "You got 3 lines to match! Well done!" << endl;
                    cout << "Credits won: 75" << endl;
                    credits += 75;
                }
                else if (threeOne == threeTwo == threeThree == threeFour == threeFive && twoOne == twoTwo == twoThree == twoFour == twoFive && threeOne == twoTwo == oneThree == twoFour == threeFive) {
                    cout << "You got 3 lines to match! Well done!" << endl;
                    cout << "Credits won: 75" << endl;
                    credits += 75;
                }
                else if (threeOne == threeTwo == threeThree == threeFour == threeFive && oneOne == oneTwo == oneThree == oneFour == oneFive && threeOne == twoTwo == oneThree == twoFour == threeFive) {
                    cout << "You got 3 lines to match! Well done!" << endl;
                    cout << "Credits won: 75" << endl;
                    credits += 75;
                }
                else if (threeOne == twoTwo == oneThree == twoFour == threeFive && twoOne == twoTwo == twoThree == twoFour == twoFive && oneOne == twoTwo == threeThree == twoFour == oneFive) {
                    cout << "You got 3 lines to match! Well done!" << endl;
                    cout << "Credits won: 75" << endl;
                    credits += 75;
                }
                else if (threeOne == twoTwo == oneThree == twoFour == threeFive && oneOne == twoTwo == threeThree == twoFour == oneFive && threeOne == threeTwo == threeThree == threeFour == threeFive) {
                    cout << "You got 3 lines to match! Well done!" << endl;
                    cout << "Credits won: 75" << endl;
                    credits += 75;
                }
                else if (oneOne == oneTwo == oneThree == oneFour == oneFive && twoOne == twoTwo == twoThree == twoFour == twoFive) {
                    cout << "You got 2 lines to match! Well done!" << endl;
                    cout << "Credits won: 25" << endl;
                    credits += 25;
                }
                else if (oneOne == oneTwo == oneThree == oneFour == oneFive && threeOne == threeTwo == threeThree == threeFour == threeFive) {
                    cout << "You got 2 lines to match! Well done!" << endl;
                    cout << "Credits won: 25" << endl;
                    credits += 25;
                    
                }
                else if (twoOne == twoTwo == twoThree == twoFour == twoFive && threeOne == threeTwo == threeThree == threeFour == threeFive) {
                    cout << "You got 2 lines to match! Well done!" << endl;
                    cout << "Credits won: 25" << endl;
                    credits += 25;
                    
                }
                else if (oneOne == oneTwo == oneThree == oneFour == oneFive && threeOne == twoTwo == oneThree == twoFour == threeFive) {
                    cout << "You got 2 lines to match! Well done!" << endl;
                    cout << "Credits won: 25" << endl;
                    credits += 25;
                }
                else if (twoOne == twoTwo == twoThree == twoFour == twoFive && threeOne == twoTwo == oneThree == twoFour == threeFive) {
                    cout << "You got 2 lines to match! Well done!" << endl;
                    cout << "Credits won: 25" << endl;
                    credits += 25;
                }
                else if (threeOne == threeTwo == threeThree == threeFour == threeFive && threeOne == twoTwo == oneThree == twoFour == threeFive) {
                    cout << "You got 2 lines to match! Well done!" << endl;
                    cout << "Credits won: 25" << endl;
                    credits += 25;
                }
                else if (oneOne == twoTwo == threeThree == twoFour == oneFive && oneOne == oneTwo == oneThree == oneFour == oneFive) {
                    cout << "You got 2 lines to match! Well done!" << endl;
                    cout << "Credits won: 25" << endl;
                    credits += 25;
                }
                else if (oneOne == twoTwo == threeThree == twoFour == oneFive && twoOne == twoTwo == twoThree == twoFour == twoFive) {
                    cout << "You got 2 lines to match! Well done!" << endl;
                    cout << "Credits won: 25" << endl;
                    credits += 25;
                }
                else if (oneOne == twoTwo == threeThree == twoFour == oneFive && threeOne == threeTwo == threeThree == threeFour == threeFive) {
                    cout << "You got 2 lines to match! Well done!" << endl;
                    cout << "Credits won: 25" << endl;
                    credits += 25;
                }
                else if (oneOne == twoTwo == threeThree == twoFour == oneFive && threeOne == twoTwo == oneThree == twoFour == threeFive) {
                    cout << "You got 2 lines to match! Well done!" << endl;
                    cout << "Credits won: 25" << endl;
                    credits += 25;
                }
                else if (twoOne == twoTwo == twoThree == twoFour == twoFive) {
                    cout << "You got 1 line to match! Nice spin!" << endl;
                    cout << "Credits won: 10" << endl;
                    credits += 10;
                    
                }
                else if (oneOne == oneTwo == oneThree == oneFour == oneFive) {
                    cout << "You got 1 line to match! Nice spin!" << endl;
                    cout << "Credits won: 10" << endl;
                    credits += 10;
                    
                }
                else if (threeOne == threeTwo == threeThree == threeFour == threeFive) {
                    cout << "You got 1 line to match! Nice spin!" << endl;
                    cout << "Credits won: 10" << endl;
                    credits += 10;
                }
                else if (threeOne == twoTwo == oneThree == twoFour == threeFive) {
                    cout << "You got 1 line to match! Nice spin!" << endl;
                    cout << "Credits won: 10" << endl;
                    credits += 10;
                }
                else if (oneOne == twoTwo == threeThree == twoFour == oneFive) {
                    cout << "You got 1 line to match! Nice spin!" << endl;
                    cout << "Credits won: 10" << endl;
                    credits += 10;
                }
                
                
                else {
                    cout << "You lost! Try again?" << endl;
                    cout << "Current Credits: " << credits << endl;
                }
                
            }
            else if (lineNumber == 7) {
                int cost = 7;
                
                credits = credits - cost;
                
                cout << oneOne << " | " << oneTwo << " | " << oneThree << " | " << oneFour << " | " << oneFive << endl;
                cout << twoOne << " | " << twoTwo << " | " << twoThree << " | " << twoFour << " | " << twoFive << endl;
                cout << threeOne << " | " << threeTwo << " | " << threeThree << " | " << threeFour << " | " << threeFive << endl;
                
                if (oneOne == oneTwo == oneThree == oneFour == oneFive == twoOne == twoTwo == twoThree == twoFour == twoFive == threeOne == threeTwo == threeThree == threeFour == threeFive) {
                    cout << "This shouldn't even be possible. You shouldn't be reading this" << endl;
                    cout << "Credits won: 2500" << endl;
                    credits += 2500;
                    
                }
                else if (oneOne == oneTwo == oneThree == oneFour == oneFive && twoOne == twoTwo == twoThree == twoFour == twoFive && threeOne == threeTwo == threeThree == threeFour == threeFive && oneOne == oneTwo == twoThree == threeFour == threeFive && oneOne == twoTwo == threeThree == twoFour == oneFive && threeOne == twoTwo == oneThree == twoFour == threeFive) {
                    cout << "You just got 6 winning lines! Do you know how lucky that is!?!" << endl;
                    cout << "Credits won: 1000" << endl;
                    credits += 1000; //CHECK
                    
                }
                else if (oneOne == oneTwo == oneThree == oneFour == oneFive && twoOne == twoTwo == twoThree == twoFour == twoFive && threeOne == threeTwo == threeThree == threeFour == threeFive && threeOne == threeTwo == twoThree == oneFour == oneFive && oneOne == twoTwo == threeThree == twoFour == oneFive && threeOne == twoTwo == oneThree == twoFour == threeFive) {
                    cout << "You just got 6 winning lines! Do you know how lucky that is!?!" << endl;
                    cout << "Credits won: 1000" << endl;
                    credits += 1000; //GOOD
                    
                }
                else if (oneOne == oneTwo == oneThree == oneFour == oneFive && twoOne == twoTwo == twoThree == twoFour == twoFive && threeOne == threeTwo == twoThree == oneFour == oneFive && oneOne == oneTwo == twoThree == threeFour == threeFive && oneOne == twoTwo == threeThree == twoFour == oneFive && threeOne == twoTwo == oneThree == twoFour == threeFive) {
                    cout << "You just got 6 winning lines! Do you know how lucky that is!?!" << endl;
                    cout << "Credits won: 1000" << endl;
                    credits += 1000; //GOOD
                    
                }
                else if (oneOne == oneTwo == oneThree == oneFour == oneFive && threeOne == threeTwo == twoThree == oneFour == oneFive && threeOne == threeTwo == threeThree == threeFour == threeFive && oneOne == oneTwo == twoThree == threeFour == threeFive && oneOne == twoTwo == threeThree == twoFour == oneFive && threeOne == twoTwo == oneThree == twoFour == threeFive) {
                    cout << "You just got 6 winning lines! Do you know how lucky that is!?!" << endl;
                    cout << "Credits won: 1000" << endl;
                    credits += 1000; //GOOD
                    
                }
                else if (threeOne == threeTwo == twoThree == oneFour == oneFive && twoOne == twoTwo == twoThree == twoFour == twoFive && threeOne == threeTwo == threeThree == threeFour == threeFive && oneOne == oneTwo == twoThree == threeFour == threeFive && oneOne == twoTwo == threeThree == twoFour == oneFive && threeOne == twoTwo == oneThree == twoFour == threeFive) {
                    cout << "You just got 6 winning lines! Do you know how lucky that is!?!" << endl;
                    cout << "Credits won: 1000" << endl;
                    credits += 1000; //GOOD
                    
                }
                else if (oneOne == oneTwo == oneThree == oneFour == oneFive && twoOne == twoTwo == twoThree == twoFour == twoFive && threeOne == threeTwo == threeThree == threeFour == threeFive && oneOne == oneTwo == twoThree == threeFour == threeFive && threeOne == threeTwo == twoThree == oneFour == oneFive && threeOne == twoTwo == oneThree == twoFour == threeFive) {
                    cout << "You just got 6 winning lines! Do you know how lucky that is!?!" << endl;
                    cout << "Credits won: 1000" << endl;
                    credits += 1000;
                    
                }
                else if (oneOne == oneTwo == oneThree == oneFour == oneFive && twoOne == twoTwo == twoThree == twoFour == twoFive && threeOne == threeTwo == threeThree == threeFour == threeFive && oneOne == oneTwo == twoThree == threeFour == threeFive && oneOne == twoTwo == threeThree == twoFour == oneFive && threeOne == threeTwo == twoThree == oneFour == oneFive) {
                    cout << "You just got 6 winning lines! Do you know how lucky that is!?!" << endl;
                    cout << "Credits won: 1000" << endl;
                    credits += 1000;
                    
                }
                else if (oneOne == oneTwo == oneThree == oneFour == oneFive && twoOne == twoTwo == twoThree == twoFour == twoFive && threeOne == threeTwo == threeThree == threeFour == threeFive && oneOne == twoTwo == threeThree == twoFour == oneFive && threeOne == twoTwo == oneThree == twoFour == threeFive) {
                    cout << "You just got 5 winning lines! Today if your lucky day!" << endl;
                    cout << "Credits won: 500" << endl;
                    credits += 500;
                }
                else if (oneOne == oneTwo == oneThree == oneFour == oneFive && oneOne == oneTwo == twoThree == threeFour == threeFive && threeOne == threeTwo == twoThree == oneFour == oneFive && oneOne == twoTwo == threeThree == twoFour == oneFive && threeOne == twoTwo == oneThree == twoFour == threeFive) {
                    cout << "You just got 5 winning lines! Today if your lucky day!" << endl;
                    cout << "Credits won: 500" << endl;
                    credits += 500;
                }
                else if (oneOne == oneTwo == twoThree == threeFour == threeFive && twoOne == twoTwo == twoThree == twoFour == twoFive && oneOne == oneTwo == twoThree == threeFour == threeFive && oneOne == twoTwo == threeThree == twoFour == oneFive && threeOne == twoTwo == oneThree == twoFour == threeFive) {
                    cout << "You just got 5 winning lines! Today if your lucky day!" << endl;
                    cout << "Credits won: 500" << endl;
                    credits += 500;
                }
                else if (oneOne == oneTwo == twoThree == threeFour == threeFive && threeOne == threeTwo == twoThree == oneFour == oneFive && threeOne == threeTwo == threeThree == threeFour == threeFive && oneOne == twoTwo == threeThree == twoFour == oneFive && threeOne == twoTwo == oneThree == twoFour == threeFive) {
                    cout << "You just got 5 winning lines! Today if your lucky day!" << endl;
                    cout << "Credits won: 500" << endl;
                    credits += 500;
                }
                else if (oneOne == oneTwo == oneThree == oneFour == oneFive && twoOne == twoTwo == twoThree == twoFour == twoFive && threeOne == threeTwo == threeThree == threeFour == threeFive && oneOne == oneTwo == twoThree == threeFour == threeFive && threeOne == threeTwo == twoThree == oneFour == oneFive) {
                    cout << "You just got 5 winning lines! Today if your lucky day!" << endl;
                    cout << "Credits won: 500" << endl;
                    credits += 500;
                }
                else if (oneOne == oneTwo == oneThree == oneFour == oneFive && twoOne == twoTwo == twoThree == twoFour == twoFive && oneOne == oneTwo == twoThree == threeFour == threeFive && threeOne == threeTwo == twoThree == oneFour == oneFive && threeOne == twoTwo == oneThree == twoFour == threeFive) {
                    cout << "You just got 5 winning lines! Today if your lucky day!" << endl;
                    cout << "Credits won: 500" << endl;
                    credits += 500;
                }
                else if (oneOne == oneTwo == oneThree == oneFour == oneFive && oneOne == oneTwo == twoThree == threeFour == threeFive && threeOne == threeTwo == threeThree == threeFour == threeFive && threeOne == threeTwo == twoThree == oneFour == oneFive && threeOne == twoTwo == oneThree == twoFour == threeFive) {
                    cout << "You just got 5 winning lines! Today if your lucky day!" << endl;
                    cout << "Credits won: 500" << endl;
                    credits += 500;
                }
                else if (oneOne == oneTwo == twoThree == threeFour == threeFive && twoOne == twoTwo == twoThree == twoFour == twoFive && threeOne == threeTwo == threeThree == threeFour == threeFive && threeOne == threeTwo == twoThree == oneFour == oneFive && threeOne == twoTwo == oneThree == twoFour == threeFive) {
                    cout << "You just got 5 winning lines! Today if your lucky day!" << endl;
                    cout << "Credits won: 500" << endl;
                    credits += 500;
                }
                else if (oneOne == oneTwo == oneThree == oneFour == oneFive && twoOne == twoTwo == twoThree == twoFour == twoFive && oneOne == oneTwo == twoThree == threeFour == threeFive && oneOne == twoTwo == threeThree == twoFour == oneFive && threeOne == threeTwo == twoThree == oneFour == oneFive) {
                    cout << "You just got 5 winning lines! Today if your lucky day!" << endl;
                    cout << "Credits won: 500" << endl;
                    credits += 500;
                }
                else if (oneOne == oneTwo == oneThree == oneFour == oneFive && oneOne == oneTwo == twoThree == threeFour == threeFive && threeOne == threeTwo == threeThree == threeFour == threeFive && oneOne == twoTwo == threeThree == twoFour == oneFive && threeOne == threeTwo == twoThree == oneFour == oneFive) {
                    cout << "You just got 5 winning lines! Today if your lucky day!" << endl;
                    cout << "Credits won: 500" << endl;
                    credits += 500;
                }
                else if (oneOne == oneTwo == twoThree == threeFour == threeFive && twoOne == twoTwo == twoThree == twoFour == twoFive && threeOne == threeTwo == threeThree == threeFour == threeFive && oneOne == twoTwo == threeThree == twoFour == oneFive && threeOne == threeTwo == twoThree == oneFour == oneFive) {
                    cout << "You just got 5 winning lines! Today if your lucky day!" << endl;
                    cout << "Credits won: 500" << endl;
                    credits += 500;
                }
                else if (oneOne == oneTwo == oneThree == oneFour == oneFive && twoOne == twoTwo == twoThree == twoFour == twoFive && threeOne == threeTwo == threeThree == threeFour == threeFive && oneOne == twoTwo == threeThree == twoFour == oneFive && oneOne == oneTwo == twoThree == threeFour == threeFive) {
                    cout << "You just got 5 winning lines! Today if your lucky day!" << endl;
                    cout << "Credits won: 500" << endl;
                    credits += 500;
                }
                else if (oneOne == oneTwo == oneThree == oneFour == oneFive && twoOne == twoTwo == twoThree == twoFour == twoFive && threeOne == threeTwo == threeThree == threeFour == threeFive && oneOne == oneTwo == twoThree == threeFour == threeFive && threeOne == twoTwo == oneThree == twoFour == threeFive) {
                    cout << "You just got 5 winning lines! Today if your lucky day!" << endl;
                    cout << "Credits won: 500" << endl;
                    credits += 500;
                }
                else if (oneOne == oneTwo == oneThree == oneFour == oneFive && twoOne == twoTwo == twoThree == twoFour == twoFive && oneOne == oneTwo == twoThree == threeFour == threeFive && oneOne == twoTwo == threeThree == twoFour == oneFive && threeOne == twoTwo == oneThree == twoFour == threeFive) {
                    cout << "You just got 5 winning lines! Today if your lucky day!" << endl;
                    cout << "Credits won: 500" << endl;
                    credits += 500;
                }
                else if (oneOne == oneTwo == twoThree == threeFour == threeFive && twoOne == twoTwo == twoThree == twoFour == twoFive && threeOne == threeTwo == threeThree == threeFour == threeFive && oneOne == twoTwo == threeThree == twoFour == oneFive && threeOne == twoTwo == oneThree == twoFour == threeFive) {
                    cout << "You just got 5 winning lines! Today if your lucky day!" << endl;
                    cout << "Credits won: 500" << endl;
                    credits += 500;
                }
                else if (oneOne == oneTwo == oneThree == oneFour == oneFive && oneOne == oneTwo == twoThree == threeFour == threeFive && threeOne == threeTwo == threeThree == threeFour == threeFive && oneOne == twoTwo == threeThree == twoFour == oneFive && threeOne == twoTwo == oneThree == twoFour == threeFive) {
                    cout << "You just got 5 winning lines! Today if your lucky day!" << endl;
                    cout << "Credits won: 500" << endl;
                    credits += 500;
                }
                else if (oneOne == oneTwo == oneThree == oneFour == oneFive && twoOne == twoTwo == twoThree == twoFour == twoFive && threeOne == threeTwo == threeThree == threeFour == threeFive && oneOne == twoTwo == threeThree == twoFour == oneFive && threeOne == threeTwo == twoThree == oneFour == oneFive) {
                    cout << "You just got 5 winning lines! Today if your lucky day!" << endl;
                    cout << "Credits won: 500" << endl;
                    credits += 500;
                }
                else if (oneOne == oneTwo == oneThree == oneFour == oneFive && twoOne == twoTwo == twoThree == twoFour == twoFive && threeOne == threeTwo == threeThree == threeFour == threeFive && threeOne == threeTwo == twoThree == oneFour == oneFive && threeOne == twoTwo == oneThree == twoFour == threeFive) {
                    cout << "You just got 5 winning lines! Today if your lucky day!" << endl;
                    cout << "Credits won: 500" << endl;
                    credits += 500;
                }
                else if (oneOne == oneTwo == oneThree == oneFour == oneFive && twoOne == twoTwo == twoThree == twoFour == twoFive && threeOne == threeTwo == twoThree == oneFour == oneFive && oneOne == twoTwo == threeThree == twoFour == oneFive && threeOne == twoTwo == oneThree == twoFour == threeFive) {
                    cout << "You just got 5 winning lines! Today if your lucky day!" << endl;
                    cout << "Credits won: 500" << endl;
                    credits += 500;
                }
                else if (threeOne == threeTwo == twoThree == oneFour == oneFive && twoOne == twoTwo == twoThree == twoFour == twoFive && threeOne == threeTwo == threeThree == threeFour == threeFive && oneOne == twoTwo == threeThree == twoFour == oneFive && threeOne == twoTwo == oneThree == twoFour == threeFive) {
                    cout << "You just got 5 winning lines! Today if your lucky day!" << endl;
                    cout << "Credits won: 500" << endl;
                    credits += 500;
                }
                else if (oneOne == oneTwo == oneThree == oneFour == oneFive && threeOne == threeTwo == twoThree == oneFour == oneFive && threeOne == threeTwo == threeThree == threeFour == threeFive && oneOne == twoTwo == threeThree == twoFour == oneFive && threeOne == twoTwo == oneThree == twoFour == threeFive) {
                    cout << "You just got 5 winning lines! Today if your lucky day!" << endl;
                    cout << "Credits won: 500" << endl;
                    credits += 500;
                }
                else if (oneOne == oneTwo == oneThree == oneFour == oneFive && twoOne == twoTwo == twoThree == twoFour == twoFive && threeOne == threeTwo == threeThree == threeFour == threeFive && oneOne == twoTwo == threeThree == twoFour == oneFive) {
                    cout << "You got 4 lines to match! Holy cow!" << endl;
                    cout << "Credits won: 200" << endl;
                    credits += 200;
                }
                else if (oneOne == oneTwo == oneThree == oneFour == oneFive && twoOne == twoTwo == twoThree == twoFour == twoFive && threeOne == threeTwo == threeThree == threeFour == threeFive && threeOne == twoTwo == oneThree == twoFour == threeFive) {
                    cout << "You got 4 lines to match! Holy cow!" << endl;
                    cout << "Credits won: 200" << endl;
                    credits += 200;
                }
                else if (oneOne == oneTwo == oneThree == oneFour == oneFive && twoOne == twoTwo == twoThree == twoFour == twoFive && oneOne == twoTwo == threeThree == twoFour == oneFive && threeOne == twoTwo == oneThree == twoFour == threeFive) {
                    cout << "You got 4 lines to match! Holy cow!" << endl;
                    cout << "Credits won: 200" << endl;
                    credits += 200;
                    //oneOne == twoTwo == threeThree == twoFour == oneFive
                }
                else if (oneOne == oneTwo == oneThree == oneFour == oneFive && oneOne == twoTwo == threeThree == twoFour == oneFive && threeOne == threeTwo == threeThree == threeFour == threeFive && threeOne == twoTwo == oneThree == twoFour == threeFive) {
                    cout << "You got 4 lines to match! Holy cow!" << endl;
                    cout << "Credits won: 200" << endl;
                    credits += 200;
                }
                else if (oneOne == twoTwo == threeThree == twoFour == oneFive && twoOne == twoTwo == twoThree == twoFour == twoFive && threeOne == threeTwo == threeThree == threeFour == threeFive && threeOne == twoTwo == oneThree == twoFour == threeFive) {
                    cout << "You got 4 lines to match! Holy cow!" << endl;
                    cout << "Credits won: 200" << endl;
                    credits += 200; //END OF OLD ONES
                }
                else if (oneOne == oneTwo == oneThree == oneFour == oneFive && oneOne == oneTwo == twoThree == threeFour == threeFive && oneOne == twoTwo == threeThree == twoFour == oneFive && threeOne == twoTwo == oneThree == twoFour == threeFive) {
                    cout << "You got 4 lines to match! Holy cow!" << endl;
                    cout << "Credits won: 200" << endl;
                    credits += 200;
                }
                else if (twoOne == twoTwo == twoThree == twoFour == twoFive && oneOne == oneTwo == twoThree == threeFour == threeFive && oneOne == twoTwo == threeThree == twoFour == oneFive && threeOne == twoTwo == oneThree == twoFour == threeFive) {
                    cout << "You got 4 lines to match! Holy cow!" << endl;
                    cout << "Credits won: 200" << endl;
                    credits += 200;
                }
                else if (threeOne == threeTwo == threeThree == threeFour == threeFive && oneOne == oneTwo == twoThree == threeFour == threeFive && oneOne == twoTwo == threeThree == twoFour == oneFive && threeOne == twoTwo == oneThree == twoFour == threeFive) {
                    cout << "You got 4 lines to match! Holy cow!" << endl;
                    cout << "Credits won: 200" << endl;
                    credits += 200;
                }
                else if (threeOne == threeTwo == threeThree == threeFour == threeFive && oneOne == oneTwo == twoThree == threeFour == threeFive && oneOne == oneTwo == oneThree == oneFour == oneFive && twoOne == twoTwo == twoThree == twoFour == twoFive) {
                    cout << "You got 4 lines to match! Holy cow!" << endl;
                    cout << "Credits won: 200" << endl;
                    credits += 200;
                }
                else if (oneOne == oneTwo == oneThree == oneFour == oneFive && oneOne == oneTwo == twoThree == threeFour == threeFive && twoOne == twoTwo == twoThree == twoFour == twoFive && threeOne == twoTwo == oneThree == twoFour == threeFive) {
                    cout << "You got 4 lines to match! Holy cow!" << endl;
                    cout << "Credits won: 200" << endl;
                    credits += 200;
                }
                else if (oneOne == oneTwo == oneThree == oneFour == oneFive && oneOne == oneTwo == twoThree == threeFour == threeFive && threeOne == threeTwo == threeThree == threeFour == threeFive && threeOne == twoTwo == oneThree == twoFour == threeFive) {
                    cout << "You got 4 lines to match! Holy cow!" << endl;
                    cout << "Credits won: 200" << endl;
                    credits += 200;
                }
                else if (threeOne == threeTwo == threeThree == threeFour == threeFive && oneOne == oneTwo == twoThree == threeFour == threeFive && twoOne == twoTwo == twoThree == twoFour == twoFive && threeOne == twoTwo == oneThree == twoFour == threeFive) {
                    cout << "You got 4 lines to match! Holy cow!" << endl;
                    cout << "Credits won: 200" << endl;
                    credits += 200;
                }
                else if (oneOne == oneTwo == oneThree == oneFour == oneFive && oneOne == oneTwo == twoThree == threeFour == threeFive && twoOne == twoTwo == twoThree == twoFour == twoFive && oneOne == twoTwo == threeThree == twoFour == oneFive) {
                    cout << "You got 4 lines to match! Holy cow!" << endl;
                    cout << "Credits won: 200" << endl;
                    credits += 200;
                }
                else if (oneOne == oneTwo == oneThree == oneFour == oneFive && oneOne == oneTwo == twoThree == threeFour == threeFive && threeOne == threeTwo == threeThree == threeFour == threeFive && oneOne == twoTwo == threeThree == twoFour == oneFive) {
                    cout << "You got 4 lines to match! Holy cow!" << endl;
                    cout << "Credits won: 200" << endl;
                    credits += 200;
                }
                else if (twoOne == twoTwo == twoThree == twoFour == twoFive && oneOne == oneTwo == twoThree == threeFour == threeFive && threeOne == threeTwo == threeThree == threeFour == threeFive && oneOne == twoTwo == threeThree == twoFour == oneFive) {
                    cout << "You got 4 lines to match! Holy cow!" << endl;
                    cout << "Credits won: 200" << endl;
                    credits += 200;
                }
                else if (oneOne == oneTwo == oneThree == oneFour == oneFive && threeOne == threeTwo == twoThree == oneFour == oneFive && threeOne == twoTwo == oneThree == twoFour == threeFive && oneOne == twoTwo == threeThree == twoFour == oneFive) {
                    cout << "You got 4 lines to match! Holy cow!" << endl;
                    cout << "Credits won: 200" << endl;
                    credits += 200;
                }
                else if (twoOne == twoTwo == twoThree == twoFour == twoFive && threeOne == threeTwo == twoThree == oneFour == oneFive && threeOne == twoTwo == oneThree == twoFour == threeFive && oneOne == twoTwo == threeThree == twoFour == oneFive) {
                    cout << "You got 4 lines to match! Holy cow!" << endl;
                    cout << "Credits won: 200" << endl;
                    credits += 200;
                }
                else if (threeOne == threeTwo == threeThree == threeFour == threeFive && threeOne == threeTwo == twoThree == oneFour == oneFive && threeOne == twoTwo == oneThree == twoFour == threeFive && oneOne == twoTwo == threeThree == twoFour == oneFive) {
                    cout << "You got 4 lines to match! Holy cow!" << endl;
                    cout << "Credits won: 200" << endl;
                    credits += 200;
                }
                else if (oneOne == oneTwo == oneThree == oneFour == oneFive && threeOne == threeTwo == twoThree == oneFour == oneFive && threeOne == threeTwo == threeThree == threeFour == threeFive && twoOne == twoTwo == twoThree == twoFour == twoFive) {
                    cout << "You got 4 lines to match! Holy cow!" << endl;
                    cout << "Credits won: 200" << endl;
                    credits += 200;
                }
                else if (oneOne == oneTwo == oneThree == oneFour == oneFive && threeOne == threeTwo == twoThree == oneFour == oneFive && threeOne == twoTwo == oneThree == twoFour == threeFive && twoOne == twoTwo == twoThree == twoFour == twoFive) {
                    cout << "You got 4 lines to match! Holy cow!" << endl;
                    cout << "Credits won: 200" << endl;
                    credits += 200;
                }
                else if (oneOne == oneTwo == oneThree == oneFour == oneFive && threeOne == threeTwo == twoThree == oneFour == oneFive && threeOne == twoTwo == oneThree == twoFour == threeFive && threeOne == threeTwo == threeThree == threeFour == threeFive) {
                    cout << "You got 4 lines to match! Holy cow!" << endl;
                    cout << "Credits won: 200" << endl;
                    credits += 200;
                }
                else if (twoOne == twoTwo == twoThree == twoFour == twoFive && threeOne == threeTwo == twoThree == oneFour == oneFive && threeOne == twoTwo == oneThree == twoFour == threeFive && threeOne == threeTwo == threeThree == threeFour == threeFive) {
                    cout << "You got 4 lines to match! Holy cow!" << endl;
                    cout << "Credits won: 200" << endl;
                    credits += 200;
                }
                else if (oneOne == oneTwo == oneThree == oneFour == oneFive && threeOne == threeTwo == twoThree == oneFour == oneFive && oneOne == twoTwo == threeThree == twoFour == oneFive && twoOne == twoTwo == twoThree == twoFour == twoFive) {
                    cout << "You got 4 lines to match! Holy cow!" << endl;
                    cout << "Credits won: 200" << endl;
                    credits += 200;
                }
                else if (oneOne == oneTwo == oneThree == oneFour == oneFive && threeOne == threeTwo == twoThree == oneFour == oneFive && oneOne == twoTwo == threeThree == twoFour == oneFive && threeOne == threeTwo == threeThree == threeFour == threeFive) {
                    cout << "You got 4 lines to match! Holy cow!" << endl;
                    cout << "Credits won: 200" << endl;
                    credits += 200;
                }
                else if (twoOne == twoTwo == twoThree == twoFour == twoFive && threeOne == threeTwo == twoThree == oneFour == oneFive && oneOne == twoTwo == threeThree == twoFour == oneFive && threeOne == threeTwo == threeThree == threeFour == threeFive) {
                    cout << "You got 4 lines to match! Holy cow!" << endl;
                    cout << "Credits won: 200" << endl;
                    credits += 200;
                }
                else if (oneOne == oneTwo == twoThree == threeFour == threeFive && threeOne == threeTwo == twoThree == oneFour == oneFive && oneOne == twoTwo == threeThree == twoFour == oneFive && threeOne == twoTwo == oneThree == twoFour == threeFive) {
                    cout << "You got 4 lines to match! Holy cow!" << endl;
                    cout << "Credits won: 200" << endl;
                    credits += 200;
                }
                else if (oneOne == oneTwo == twoThree == threeFour == threeFive && threeOne == threeTwo == twoThree == oneFour == oneFive && oneOne == oneTwo == oneThree == oneFour == oneFive && threeOne == twoTwo == oneThree == twoFour == threeFive) {
                    cout << "You got 4 lines to match! Holy cow!" << endl;
                    cout << "Credits won: 200" << endl;
                    credits += 200;
                }
                else if (oneOne == oneTwo == twoThree == threeFour == threeFive && threeOne == threeTwo == twoThree == oneFour == oneFive && twoOne == twoTwo == twoThree == twoFour == twoFive && threeOne == twoTwo == oneThree == twoFour == threeFive) {
                    cout << "You got 4 lines to match! Holy cow!" << endl;
                    cout << "Credits won: 200" << endl;
                    credits += 200;
                }
                else if (oneOne == oneTwo == twoThree == threeFour == threeFive && threeOne == threeTwo == twoThree == oneFour == oneFive && threeOne == threeTwo == threeThree == threeFour == threeFive && threeOne == twoTwo == oneThree == twoFour == threeFive) {
                    cout << "You got 4 lines to match! Holy cow!" << endl;
                    cout << "Credits won: 200" << endl;
                    credits += 200;
                }
                else if (oneOne == oneTwo == twoThree == threeFour == threeFive && threeOne == threeTwo == twoThree == oneFour == oneFive && oneOne == oneTwo == oneThree == oneFour == oneFive && oneOne == twoTwo == threeThree == twoFour == oneFive) {
                    cout << "You got 4 lines to match! Holy cow!" << endl;
                    cout << "Credits won: 200" << endl;
                    credits += 200;
                }
                else if (oneOne == oneTwo == twoThree == threeFour == threeFive && threeOne == threeTwo == twoThree == oneFour == oneFive && twoOne == twoTwo == twoThree == twoFour == twoFive && oneOne == twoTwo == threeThree == twoFour == oneFive) {
                    cout << "You got 4 lines to match! Holy cow!" << endl;
                    cout << "Credits won: 200" << endl;
                    credits += 200;
                }
                else if (oneOne == oneTwo == twoThree == threeFour == threeFive && threeOne == threeTwo == twoThree == oneFour == oneFive && threeOne == threeTwo == threeThree == threeFour == threeFive && oneOne == twoTwo == threeThree == twoFour == oneFive) {
                    cout << "You got 4 lines to match! Holy cow!" << endl;
                    cout << "Credits won: 200" << endl;
                    credits += 200;
                }
                else if (oneOne == oneTwo == oneThree == oneFour == oneFive && twoOne == twoTwo == twoThree == twoFour == twoFive && threeOne == threeTwo == threeThree == threeFour == threeFive) {
                    cout << "You got 3 lines to match! Well done!" << endl;
                    cout << "Credits won: 75" << endl;
                    credits += 75;
                }
                else if (oneOne == twoTwo == threeThree == twoFour == oneFive && twoOne == twoTwo == twoThree == twoFour == twoFive && threeOne == threeTwo == threeThree == threeFour == threeFive) {
                    cout << "You got 3 lines to match! Well done!" << endl;
                    cout << "Credits won: 75" << endl;
                    credits += 75;
                }
                else if (oneOne == twoTwo == threeThree == twoFour == oneFive && twoOne == twoTwo == twoThree == twoFour == twoFive && oneOne == oneTwo == oneThree == oneFour == oneFive) {
                    cout << "You got 3 lines to match! Well done!" << endl;
                    cout << "Credits won: 75" << endl;
                    credits += 75; //YES
                }
                else if (oneOne == oneTwo == oneThree == oneFour == oneFive && oneOne == twoTwo == threeThree == twoFour == oneFive && threeOne == threeTwo == threeThree == threeFour == threeFive) {
                    cout << "You got 3 lines to match! Well done!" << endl;
                    cout << "Credits won: 75" << endl;
                    credits += 75;
                }
                else if (oneOne == oneTwo == oneThree == oneFour == oneFive && oneOne == twoTwo == threeThree == twoFour == oneFive && threeOne == twoTwo == oneThree == twoFour == threeFive) {
                    cout << "You got 3 lines to match! Well done!" << endl;
                    cout << "Credits won: 75" << endl;
                    credits += 75;
                }
                else if (oneOne == oneTwo == oneThree == oneFour == oneFive && twoOne == twoTwo == twoThree == twoFour == twoFive && threeOne == twoTwo == oneThree == twoFour == threeFive) {
                    cout << "You got 3 lines to match! Well done!" << endl;
                    cout << "Credits won: 75" << endl;
                    credits += 75;
                }
                else if (threeOne == threeTwo == threeThree == threeFour == threeFive && twoOne == twoTwo == twoThree == twoFour == twoFive && threeOne == twoTwo == oneThree == twoFour == threeFive) {
                    cout << "You got 3 lines to match! Well done!" << endl;
                    cout << "Credits won: 75" << endl;
                    credits += 75;
                }
                else if (threeOne == threeTwo == threeThree == threeFour == threeFive && oneOne == oneTwo == oneThree == oneFour == oneFive && threeOne == twoTwo == oneThree == twoFour == threeFive) {
                    cout << "You got 3 lines to match! Well done!" << endl;
                    cout << "Credits won: 75" << endl;
                    credits += 75;
                }
                else if (threeOne == twoTwo == oneThree == twoFour == threeFive && twoOne == twoTwo == twoThree == twoFour == twoFive && oneOne == twoTwo == threeThree == twoFour == oneFive) {
                    cout << "You got 3 lines to match! Well done!" << endl;
                    cout << "Credits won: 75" << endl;
                    credits += 75;
                }
                else if (threeOne == twoTwo == oneThree == twoFour == threeFive && oneOne == twoTwo == threeThree == twoFour == oneFive && threeOne == threeTwo == threeThree == threeFour == threeFive) {
                    cout << "You got 3 lines to match! Well done!" << endl;
                    cout << "Credits won: 75" << endl;
                    credits += 75;
                }
                else if (oneOne == oneTwo == twoThree == threeFour == threeFive && threeOne == threeTwo == twoThree == oneFour == oneFive && threeOne == twoTwo == oneThree == twoFour == threeFive) {
                    cout << "You got 3 lines to match! Well done!" << endl;
                    cout << "Credits won: 75" << endl;
                    credits += 75;
                }
                else if (oneOne == oneTwo == twoThree == threeFour == threeFive && threeOne == threeTwo == twoThree == oneFour == oneFive && oneOne == twoTwo == threeThree == twoFour == oneFive) {
                    cout << "You got 3 lines to match! Well done!" << endl;
                    cout << "Credits won: 75" << endl;
                    credits += 75;
                }
                else if (oneOne == oneTwo == twoThree == threeFour == threeFive && threeOne == threeTwo == twoThree == oneFour == oneFive && oneOne == oneTwo == oneThree == oneFour == oneFive) {
                    cout << "You got 3 lines to match! Well done!" << endl;
                    cout << "Credits won: 75" << endl;
                    credits += 75;
                }
                else if (oneOne == oneTwo == twoThree == threeFour == threeFive && threeOne == threeTwo == twoThree == oneFour == oneFive && twoOne == twoTwo == twoThree == twoFour == twoFive) {
                    cout << "You got 3 lines to match! Well done!" << endl;
                    cout << "Credits won: 75" << endl;
                    credits += 75;
                }
                else if (oneOne == oneTwo == twoThree == threeFour == threeFive && threeOne == threeTwo == twoThree == oneFour == oneFive && threeOne == threeTwo == threeThree == threeFour == threeFive) {
                    cout << "You got 3 lines to match! Well done!" << endl;
                    cout << "Credits won: 75" << endl;
                    credits += 75;
                }
                else if (oneOne == oneTwo == twoThree == threeFour == threeFive && threeOne == twoTwo == oneThree == twoFour == threeFive && oneOne == twoTwo == threeThree == twoFour == oneFive) {
                    cout << "You got 3 lines to match! Well done!" << endl;
                    cout << "Credits won: 75" << endl;
                    credits += 75;
                }
                else if (oneOne == oneTwo == twoThree == threeFour == threeFive && threeOne == twoTwo == oneThree == twoFour == threeFive && oneOne == oneTwo == oneThree == oneFour == oneFive) {
                    cout << "You got 3 lines to match! Well done!" << endl;
                    cout << "Credits won: 75" << endl;
                    credits += 75;
                }
                else if (oneOne == oneTwo == twoThree == threeFour == threeFive && threeOne == twoTwo == oneThree == twoFour == threeFive && twoOne == twoTwo == twoThree == twoFour == twoFive) {
                    cout << "You got 3 lines to match! Well done!" << endl;
                    cout << "Credits won: 75" << endl;
                    credits += 75;
                }
                else if (oneOne == oneTwo == twoThree == threeFour == threeFive && threeOne == twoTwo == oneThree == twoFour == threeFive && threeOne == threeTwo == threeThree == threeFour == threeFive) {
                    cout << "You got 3 lines to match! Well done!" << endl;
                    cout << "Credits won: 75" << endl;
                    credits += 75;
                }
                else if (oneOne == oneTwo == twoThree == threeFour == threeFive && oneOne == twoTwo == threeThree == twoFour == oneFive && oneOne == oneTwo == oneThree == oneFour == oneFive) {
                    cout << "You got 3 lines to match! Well done!" << endl;
                    cout << "Credits won: 75" << endl;
                    credits += 75;
                }
                else if (oneOne == oneTwo == twoThree == threeFour == threeFive && oneOne == twoTwo == threeThree == twoFour == oneFive && twoOne == twoTwo == twoThree == twoFour == twoFive) {
                    cout << "You got 3 lines to match! Well done!" << endl;
                    cout << "Credits won: 75" << endl;
                    credits += 75;
                }
                else if (oneOne == oneTwo == twoThree == threeFour == threeFive && oneOne == twoTwo == threeThree == twoFour == oneFive && threeOne == threeTwo == threeThree == threeFour == threeFive) {
                    cout << "You got 3 lines to match! Well done!" << endl;
                    cout << "Credits won: 75" << endl;
                    credits += 75;
                }
                else if (oneOne == oneTwo == twoThree == threeFour == threeFive && oneOne == oneTwo == oneThree == oneFour == oneFive && twoOne == twoTwo == twoThree == twoFour == twoFive) {
                    cout << "You got 3 lines to match! Well done!" << endl;
                    cout << "Credits won: 75" << endl;
                    credits += 75;
                }
                else if (oneOne == oneTwo == twoThree == threeFour == threeFive && oneOne == oneTwo == oneThree == oneFour == oneFive && threeOne == threeTwo == threeThree == threeFour == threeFive) {
                    cout << "You got 3 lines to match! Well done!" << endl;
                    cout << "Credits won: 75" << endl;
                    credits += 75;
                }
                else if (oneOne == oneTwo == twoThree == threeFour == threeFive && twoOne == twoTwo == twoThree == twoFour == twoFive && threeOne == threeTwo == threeThree == threeFour == threeFive) {
                    cout << "You got 3 lines to match! Well done!" << endl;
                    cout << "Credits won: 75" << endl;
                    credits += 75;
                }
                else if (threeOne == threeTwo == twoThree == oneFour == oneFive && oneOne == twoTwo == threeThree == twoFour == oneFive && threeOne == twoTwo == oneThree == twoFour == threeFive) {
                    cout << "You got 3 lines to match! Well done!" << endl;
                    cout << "Credits won: 75" << endl;
                    credits += 75;
                }
                else if (threeOne == threeTwo == twoThree == oneFour == oneFive && oneOne == oneTwo == oneThree == oneFour == oneFive && threeOne == twoTwo == oneThree == twoFour == threeFive) {
                    cout << "You got 3 lines to match! Well done!" << endl;
                    cout << "Credits won: 75" << endl;
                    credits += 75;
                }
                else if (threeOne == threeTwo == twoThree == oneFour == oneFive && twoOne == twoTwo == twoThree == twoFour == twoFive && threeOne == twoTwo == oneThree == twoFour == threeFive) {
                    cout << "You got 3 lines to match! Well done!" << endl;
                    cout << "Credits won: 75" << endl;
                    credits += 75;
                }
                else if (threeOne == threeTwo == twoThree == oneFour == oneFive && threeOne == threeTwo == threeThree == threeFour == threeFive && threeOne == twoTwo == oneThree == twoFour == threeFive) {
                    cout << "You got 3 lines to match! Well done!" << endl;
                    cout << "Credits won: 75" << endl;
                    credits += 75;
                }
                else if (threeOne == threeTwo == twoThree == oneFour == oneFive && oneOne == oneTwo == oneThree == oneFour == oneFive && oneOne == twoTwo == threeThree == twoFour == oneFive) {
                    cout << "You got 3 lines to match! Well done!" << endl;
                    cout << "Credits won: 75" << endl;
                    credits += 75;
                }
                else if (threeOne == threeTwo == twoThree == oneFour == oneFive && twoOne == twoTwo == twoThree == twoFour == twoFive && oneOne == twoTwo == threeThree == twoFour == oneFive) {
                    cout << "You got 3 lines to match! Well done!" << endl;
                    cout << "Credits won: 75" << endl;
                    credits += 75;
                }
                else if (threeOne == threeTwo == twoThree == oneFour == oneFive && threeOne == threeTwo == threeThree == threeFour == threeFive && oneOne == twoTwo == threeThree == twoFour == oneFive) {
                    cout << "You got 3 lines to match! Well done!" << endl;
                    cout << "Credits won: 75" << endl;
                    credits += 75;
                }
                else if (threeOne == threeTwo == twoThree == oneFour == oneFive && oneOne == oneTwo == oneThree == oneFour == oneFive && twoOne == twoTwo == twoThree == twoFour == twoFive) {
                    cout << "You got 3 lines to match! Well done!" << endl;
                    cout << "Credits won: 75" << endl;
                    credits += 75;
                }
                else if (threeOne == threeTwo == twoThree == oneFour == oneFive && oneOne == oneTwo == oneThree == oneFour == oneFive && threeOne == threeTwo == threeThree == threeFour == threeFive) {
                    cout << "You got 3 lines to match! Well done!" << endl;
                    cout << "Credits won: 75" << endl;
                    credits += 75;
                }
                else if (threeOne == threeTwo == twoThree == oneFour == oneFive && twoOne == twoTwo == twoThree == twoFour == twoFive && threeOne == threeTwo == threeThree == threeFour == threeFive) {
                    cout << "You got 3 lines to match! Well done!" << endl;
                    cout << "Credits won: 75" << endl;
                    credits += 75;
                }
                else if (oneOne == oneTwo == oneThree == oneFour == oneFive && twoOne == twoTwo == twoThree == twoFour == twoFive) {
                    cout << "You got 2 lines to match! Well done!" << endl;
                    cout << "Credits won: 25" << endl;
                    credits += 25;
                }
                else if (oneOne == oneTwo == oneThree == oneFour == oneFive && threeOne == threeTwo == threeThree == threeFour == threeFive) {
                    cout << "You got 2 lines to match! Well done!" << endl;
                    cout << "Credits won: 25" << endl;
                    credits += 25;
                    
                }
                else if (twoOne == twoTwo == twoThree == twoFour == twoFive && threeOne == threeTwo == threeThree == threeFour == threeFive) {
                    cout << "You got 2 lines to match! Well done!" << endl;
                    cout << "Credits won: 25" << endl;
                    credits += 25;
                    
                }
                else if (oneOne == oneTwo == oneThree == oneFour == oneFive && threeOne == twoTwo == oneThree == twoFour == threeFive) {
                    cout << "You got 2 lines to match! Well done!" << endl;
                    cout << "Credits won: 25" << endl;
                    credits += 25;
                }
                else if (twoOne == twoTwo == twoThree == twoFour == twoFive && threeOne == twoTwo == oneThree == twoFour == threeFive) {
                    cout << "You got 2 lines to match! Well done!" << endl;
                    cout << "Credits won: 25" << endl;
                    credits += 25;
                }
                else if (threeOne == threeTwo == threeThree == threeFour == threeFive && threeOne == twoTwo == oneThree == twoFour == threeFive) {
                    cout << "You got 2 lines to match! Well done!" << endl;
                    cout << "Credits won: 25" << endl;
                    credits += 25;
                }
                else if (oneOne == twoTwo == threeThree == twoFour == oneFive && oneOne == oneTwo == oneThree == oneFour == oneFive) {
                    cout << "You got 2 lines to match! Well done!" << endl;
                    cout << "Credits won: 25" << endl;
                    credits += 25;
                }
                else if (oneOne == twoTwo == threeThree == twoFour == oneFive && twoOne == twoTwo == twoThree == twoFour == twoFive) {
                    cout << "You got 2 lines to match! Well done!" << endl;
                    cout << "Credits won: 25" << endl;
                    credits += 25;
                }
                else if (oneOne == twoTwo == threeThree == twoFour == oneFive && threeOne == threeTwo == threeThree == threeFour == threeFive) {
                    cout << "You got 2 lines to match! Well done!" << endl;
                    cout << "Credits won: 25" << endl;
                    credits += 25;
                }
                else if (oneOne == twoTwo == threeThree == twoFour == oneFive && threeOne == twoTwo == oneThree == twoFour == threeFive) {
                    cout << "You got 2 lines to match! Well done!" << endl;
                    cout << "Credits won: 25" << endl;
                    credits += 25;
                }
                else if (oneOne == oneTwo == twoThree == threeFour == threeFive && threeOne == threeTwo == twoThree == oneFour == oneFive) {
                    cout << "You got 2 lines to match! Well done!" << endl;
                    cout << "Credits won: 25" << endl;
                    credits += 25;
                }
                else if (oneOne == oneTwo == twoThree == threeFour == threeFive && threeOne == twoTwo == oneThree == twoFour == threeFive) {
                    cout << "You got 2 lines to match! Well done!" << endl;
                    cout << "Credits won: 25" << endl;
                    credits += 25;
                }
                else if (oneOne == oneTwo == twoThree == threeFour == threeFive && oneOne == twoTwo == threeThree == twoFour == oneFive) {
                    cout << "You got 2 lines to match! Well done!" << endl;
                    cout << "Credits won: 25" << endl;
                    credits += 25;
                }
                else if (oneOne == oneTwo == twoThree == threeFour == threeFive && oneOne == oneTwo == oneThree == oneFour == oneFive) {
                    cout << "You got 2 lines to match! Well done!" << endl;
                    cout << "Credits won: 25" << endl;
                    credits += 25;
                }
                else if (oneOne == oneTwo == twoThree == threeFour == threeFive && twoOne == twoTwo == twoThree == twoFour == twoFive) {
                    cout << "You got 2 lines to match! Well done!" << endl;
                    cout << "Credits won: 25" << endl;
                    credits += 25;
                }
                else if (oneOne == oneTwo == twoThree == threeFour == threeFive && threeOne == threeTwo == threeThree == threeFour == threeFive) {
                    cout << "You got 2 lines to match! Well done!" << endl;
                    cout << "Credits won: 25" << endl;
                    credits += 25;
                }
                else if (threeOne == threeTwo == twoThree == oneFour == oneFive && oneOne == oneTwo == oneThree == oneFour == oneFive) {
                    cout << "You got 2 lines to match! Well done!" << endl;
                    cout << "Credits won: 25" << endl;
                    credits += 25;
                }
                else if (threeOne == threeTwo == twoThree == oneFour == oneFive && twoOne == twoTwo == twoThree == twoFour == twoFive) {
                    cout << "You got 2 lines to match! Well done!" << endl;
                    cout << "Credits won: 25" << endl;
                    credits += 25;
                }
                else if (threeOne == threeTwo == twoThree == oneFour == oneFive && threeOne == threeTwo == threeThree == threeFour == threeFive) {
                    cout << "You got 2 lines to match! Well done!" << endl;
                    cout << "Credits won: 25" << endl;
                    credits += 25;
                }
                else if (threeOne == threeTwo == twoThree == oneFour == oneFive && threeOne == twoTwo == oneThree == twoFour == threeFive) {
                    cout << "You got 2 lines to match! Well done!" << endl;
                    cout << "Credits won: 25" << endl;
                    credits += 25;
                }
                else if (threeOne == threeTwo == twoThree == oneFour == oneFive && oneOne == twoTwo == threeThree == twoFour == oneFive) {
                    cout << "You got 2 lines to match! Well done!" << endl;
                    cout << "Credits won: 25" << endl;
                    credits += 25;
                }
                else if (twoOne == twoTwo == twoThree == twoFour == twoFive) {
                    cout << "You got 1 line to match! Nice spin!" << endl;
                    cout << "Credits won: 10" << endl;
                    credits += 10;
                    
                }
                else if (oneOne == oneTwo == oneThree == oneFour == oneFive) {
                    cout << "You got 1 line to match! Nice spin!" << endl;
                    cout << "Credits won: 10" << endl;
                    credits += 10;
                    
                }
                else if (threeOne == threeTwo == threeThree == threeFour == threeFive) {
                    cout << "You got 1 line to match! Nice spin!" << endl;
                    cout << "Credits won: 10" << endl;
                    credits += 10;
                }
                else if (threeOne == twoTwo == oneThree == twoFour == threeFive) {
                    cout << "You got 1 line to match! Nice spin!" << endl;
                    cout << "Credits won: 10" << endl;
                    credits += 10;
                }
                else if (oneOne == twoTwo == threeThree == twoFour == oneFive) {
                    cout << "You got 1 line to match! Nice spin!" << endl;
                    cout << "Credits won: 10" << endl;
                    credits += 10;
                }
                else if (oneOne == oneTwo == twoThree == threeFour == threeFive) {
                    cout << "You got 1 line to match! Nice spin!" << endl;
                    cout << "Credits won: 10" << endl;
                    credits += 10;
                }
                else if (threeOne == threeTwo == twoThree == oneFour == oneFive) {
                    cout << "You got 1 line to match! Nice spin!" << endl;
                    cout << "Credits won: 10" << endl;
                    credits += 10;
                }
                else {
                    cout << "You lost! Try again?" << endl;
                    cout << "Current Credits: " << credits << endl;
                }
            }
        }
        else if (credits <= 0){
            cout << "You ran out of credits. Game Over!" << endl;
            exit(0);
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

string* initializeDeckOM()
{
    string* deck = new string [53];
    string cardNum = "";
    for(int j = 0; j < 2; j++)
    {
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
                cardNum = to_string(i+2);
            }
            deck[i + j*13]= cardNum + "BLACK";
        }
    }
    
    for(int j = 0; j < 2; j++)
    {
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
                cardNum = to_string(i+2);
            }
            deck[i+26 + j*13]= cardNum + "RED";
        }
    }
    deck[52] = "JOKER";
    return deck;
}

void shuffleDeckOM(string deck[], int length)
{
    int r =0;
    string hold;
    for (int i = 0; i<length; i++)
    {
        r = rand() % length;
        hold = deck[i];
        deck [i] = deck [r];
        deck [r] = hold;
        hold = "";
    }
}

class PlayerOM   //Create Node Class
{
public:
    //instance variables
    string *hand;
    int length;		//length of hand array
    int cards;		//non-empty cards
    
    //constructor
    PlayerOM(string* a, int totalCards);
    
    //methods
    void numCardsOM();
    void checkDuplicatesOM();
    void displayDeckOM();
    int indexFinderOM(int index);
};

//This is a constructor
PlayerOM::PlayerOM(string* a, int totalCards)
{
    hand = a;
    length = totalCards;		//length of hand array
    cards = 0;
    checkDuplicatesOM();
}

void PlayerOM::displayDeckOM()
{
    for(int i=0; i<length; i++)
    {
        cout << hand[i] << endl;
    }
}

//This will count the number of cards in the player's hand that are not empty.
void PlayerOM::numCardsOM()
{
    cards = 0;
    int i;
    for(i = 0; i < length; i++)
    {
        if(hand[i] != "empty")
        {
            cards++;
        }
    }
}

void PlayerOM::checkDuplicatesOM()
{
    //If a pair is found, they will both be set to empty and i will decrease by 2.
    int num = 0;
    int counter;
    while(num < length)
    {
        if(hand[num].compare("empty") != 0)
        {
            counter = num+1;
            while(counter < length)
            {
                if((hand[num]).compare(hand[counter]) == 0)
                {
                    hand[num] = "empty";
                    hand[counter] = "empty";
                    break;
                }
                counter++;
            }
        }
        num++;
    }
    numCardsOM();
}

int PlayerOM::indexFinderOM(int index)
{
    int j = 0;		//j is the value that should be greater than index
    int i;
    for(i = 0; i < length; i++)		//loops through the hand array
    {
        if(!(hand[i].compare("empty") == 0))
        {
            j++;
            if(j==index)
            {
                return i;
            }
        }
    }
    return length;
}

int potentialWinnerOM(PlayerOM** a, int length)	//true is there is a winner. False otherwise
{
    for(int i = 0; i < length; i++)
    {
        if(a[i]->cards == 0)
        {
            return i;
        }
    }
    return -1;
}
//This will display the rules of Old Maid.
void oldMaidRules()
{
    cout<< "In this game, one joker has been added in addition to the normal 52" << endl;
    cout<< "cards in a normal deck. Your objective is to not have that joker as" << endl;
    cout<< "a part of your hand. If you do have the joker, attempt to get rid of" << endl;
    cout<< "it as soon as you can! Whenever you have a pair, you can get rid of" << endl;
    cout<< "those two cards. A pair is made when you have 2 cards that have the " << endl;
    cout<< "same color and the same number. Suits do not matter. If you are the " << endl;
    cout<< "first player to make pairs of all of the cards in your hand, you win!" << endl;
    cout<< "You will gain a card each turn by choosing a card from the hand of" << endl;
    cout<< "another player." << endl << endl;
    cout<< "There is a minimum of 2 players in this game, and a maximum of 5. It" << endl;
    cout<< "will last approximately 5-10 minutes, depending on the number of players." << endl << endl;
    cout<< "Have fun and do not catch the Old Maid!" << endl;
}

void oldMaid()
{
    string * deck = initializeDeckOM();
    //There are 53 cards instead of 52, because the 53rd card is the joker
    //making the arrays for each player by splitting the deck array
    shuffleDeckOM(deck, 53);
    
    int players = 0;
    while(players < 2 || players > 6)		//only playing with 2, 3, 4 or 5 players
    {
        cout<< "How many people would you like to be in this game?" << endl;
        cin>> players;
        
        if(players < 2)
        {
            cout<< "You cannot play with only 1 person." << endl;
        }
        else if(players > 6)
        {
            cout<< "You cannot have more than 5 people." << endl;
        }
    }
    
    int cards = 53/players;
    int extra = 53%players;
    int num = 0; //If this goes over 52, things will get bad. Index of deck.
    PlayerOM** people = new PlayerOM* [players];
    for(int i = 0; i < players; i++)
    {
        if(i < extra)
        {
            //creates the array for this player
            string* a = new string[cards+1];
            for(int j = 0; j < cards+1; j++)
            {
                a[j] = deck[num];
                num++;
            }
            people[i] = new PlayerOM(a, cards + 1);
        }
        else
        {
            //creates the array for this player
            string* a = new string[cards];
            for(int j = 0; j < cards; j++)
            {
                a[j] = deck[num];
                num++;
            }
            people[i] = new PlayerOM(a, cards);
        }
    }
    
    //This is where the actual game starts.
    int i = 0;
    while(potentialWinnerOM(people, players) == -1)
    {
        cout<< "\nPlayer " << i + 1 << ": It is your turn." << endl;
        cout<< "Choose a number between 1 and " << people[(i+1)%players]->cards << endl;
        int choice = -1;
        cin>> choice;
        while(choice < 1 || choice > people[(i+1)%players]->cards)
        {
            cout<< "Please choose a number within the valid range." << endl;
            cin>> choice;
        }
        
        choice = people[(i+1)%players]->indexFinderOM(choice);
        //Now that we have the index, put that item into people[i]'s hand.
        
        string a = people[(i+1)%players]->hand[choice];
        people[(i+1)%players]->hand[choice] = "empty";
        //recalculate numCards
        people[(i+1)%players]->numCardsOM();
        
        //find an empty spot in people[i]'s hand and place it there
        int u = 0;
        while(people[i]->hand[u] != "empty")
        {
            u++;
        }
        people[i]->hand[u] = a;
        if(a == "JOKER")
        {
            cout<< "Player " << i +1 << ": You have the JOKER!" << endl;
        }
        people[i]->checkDuplicatesOM();
        shuffleDeckOM(people[i]->hand, people[i]->length);
        i++;
        i = i%players;
    }
    cout<< "Player " << potentialWinnerOM(people, players) + 1 << " is the winner!";
}

//this function takes in the overall deck and either the computer or user's hand
void dealPoker(string deck[], string hand[])
{
    int i = 0;
    //as long as the deck is not empty add to i until we find a spot where we can give the player a card
    while (deck[i] == "empty" && i<52)
    {
        i++;
    }
    //once we find a non empty spot then we can simply give the user or computer 5 cards
    //the first open spot in the hand becomes the first open spot in the deck and that part of the deck becomes "empty"
    hand[0] = deck[i];
    deck[i] = "empty";
    hand[1] = deck[i + 1];
    deck[i + 1] = "empty";
    hand[2] = deck[i + 2];
    deck[i + 2] = "empty";
    hand[3] = deck[i + 3];
    deck[i + 3] = "empty";
    hand[4] = deck[i + 4];
    deck[i + 4] = "empty";
    
}
//simply a for loop to print each value of the deck
void displayDeckPoker(string deck[])
{
    for (int i = 0; i < 52; i++)
    {
        cout << deck[i] << endl;
    }
}
//simply a for loop to print each value of the hand
void displayHand(string hand[])
{
    for (int i = 0; i < 5; i++)
    {
        cout << hand[i] << endl;
    }
}
// As part of five-card draw poker you can swap up to 3 cards before the "showdown"
//This method takes in the deck, the player's hand, and the card they want to swap
void swapCards(string deck[], string hand[], string card)
{
    int i = 0;
    int k = 0;
    string n = "";
    //find the top of the deck that is not "empty"
    while (deck[i] == "empty" && i<52)
    {
        i++;
    }
    //find the spot in the hand that is meant to be swapped
    for (int i = 0; i < 5; i++) {
        if (hand[i] == card) {
            //k equals that spot
            k = i;
        }
    }
    //that spot in the hand now becomes the card that was on top of the deck
    hand[k] = deck[i];
    //that part of the deck is now empty
    deck[i] = "empty";
    
}

//When as user wishes to swap a card I must first check for its existence in their hand via this method
bool cardExist(string hand[], string card)
{
    bool boo = false;
    //boo must be true to swap the card so this sets boo equal to true if it finds the desired card in the user's hand
    for (int i = 0; i < 5; i++)
    {
        if (hand[i] == card)
        {
            boo = true;
        }
    }
    return boo;
}

//for simplicity a made each rank of hand a "score" this method gets the score for the computer and the user
int getScore(string hand[])
{
    int matches = 0;
    int score = 0;
    bool flush = false;
    // bool fullHouse = false;
    //bool fourKind = false;
    
    //checks the suit of the card to see if the hand is a flsuh
    if (hand[0].substr(1, 1) == hand[1].substr(1, 1) && hand[0].substr(1, 1) == hand[2].substr(1, 1) && hand[0].substr(1, 1) == hand[3].substr(1, 1) && hand[0].substr(1, 1) == hand[4].substr(1, 1)) {
        flush = true;
        score += 4;
    }
    
    //this is for checking pairs or three of a kinds, when two cards have the same value I increment "matches"
    for (int i = 0; i < 5; i++)
    {
        string str1 = hand[i];
        for (int j = 0; j<5; j++)
        {
            string str2 = hand[j];
            //substr(0,1) gets the first element of the string which gives it value and disregards the suit
            if (str1.substr(0, 1) == str2.substr(0, 1)) {
                ++matches;
            }
        }
    }
    //2 of a kind
    //I make sure flush is set to false because if there is already a flush it must override rank of hands lower than it
    //I figured out how many matches was equivalent to each rank so that is the reason why the matches seem so random
    if (matches == 7 && flush == false) {
        score += 1;
    }
    //2 pair
    else if (matches == 9 && flush == false) {
        score += 2;
    }
    //3 of a kind
    else if (matches == 11 && flush == false) {
        score += 3;
    }
    //full house
    //for full house and four of a kind I must check if score has already been incremented from there being a flush
    //since these hands rank higher than flush I simply increment the score 1 or 2 points if there is already a flush
    else if (matches == 13 && flush == true) {
        score += 1;
    }
    else if (matches == 13 && flush == false) {
        score += 5;
    }
    // 4 of a kind
    else if (matches == 17 && flush == true) {
        score += 2;
    }
    else if (matches == 17 && flush == false) {
        score += 6;
    }
    return score;
}




//if neither player has a pair or any hand then we must check to see who has the "high card"
int highCard(string hand[]) {
    int high = 0;
    bool ace = false;
    bool king = false;
    bool queen = false;
    bool jack = false;
    //check if the hand contains a face card
    for (int i = 0; i < 5; i++) {
        string str = hand[i];
        cout << str.substr(0, 1) << endl;
        if (str.substr(0, 1) == "A") {
            ace = true;
        }
        else if (str.substr(0, 1) == "K") {
            king = true;
        }
        else if (str.substr(0, 1) == "Q") {
            queen = true;
        }
        else if (str.substr(0, 1) == "J") {
            jack = true;
        }
    }
    int value = 0;
    string str = "";
    //if there are no face cards then we simply find the card with the greatest value
    if (ace == false && king == false && queen == false && jack == false) {
        for (int i = 0; i < 5; i++) {
            str = hand[i].substr(0, 1);
            value = atoi(str.c_str());
            if (value > high) {
                high = value;
            }
        }
    }
    //scores now become much larger
    if (ace == true) {
        return 14;
    }
    else if (king == true && ace == false) {
        return 13;
    }
    else if (queen == true && king == false && ace == false) {
        return 12;
    }
    else if (jack == true && queen == false && king == false && ace == false) {
        return 11;
    }
    else {
        return high;
    }
}


// Starts the game
void roulette()
{
    printMenuRoulette();
    int rouletteOption = 0;
    cin >> rouletteOption;
    if(rouletteOption == 1)
    {
        int playerMoney = 1000;
        string playerColor = "";
        int randomNumber = 0;
        int moneyWagered = 0;
        // Continues asking for red or black until they input "red" or "black" nothing else
        while(true){
            cout << "What color do you want to bet on: red or black?" << endl;
            cin >> playerColor;
            if(playerColor!= "black" && playerColor != "red")
            {
                cout << "What color do you want to bet on: red or black?" << endl;
                cin >> playerColor;
            }
            cout << "How much would you like to bet?" << endl;
            cout << "Your money: $"<< playerMoney << endl;
            cin >> moneyWagered;
            playerMoney = playerMoney-moneyWagered;
            // Checks if the playermoney is more than $0
            if(playerMoney > 0)
            {
                srand(static_cast<unsigned int>(time(NULL)));
                randomNumber = rand() % 35 + 1;
                if(randomNumber == 1 || randomNumber == 3 || randomNumber == 5 || randomNumber == 7 || randomNumber == 9 || randomNumber == 12 || randomNumber == 14 || randomNumber == 16 || randomNumber == 18 || randomNumber == 3 || randomNumber == 19 || randomNumber == 21 || randomNumber == 23 || randomNumber == 25 || randomNumber == 27 || randomNumber == 30 || randomNumber == 32 || randomNumber == 34 || randomNumber == 36)
                {
                    if(playerColor == "red")
                    {
                        playerMoney = playerMoney+moneyWagered*2+ moneyWagered;
                        cout << "Number is: " << randomNumber << " it's red" << endl;
                        cout << "Your Color: " << playerColor << endl;
                        cout<< "You won: $" << moneyWagered << endl;
                    }
                    else if (playerColor == "black"){
                        cout << "Number is: " << randomNumber << " it's red" << endl;
                        cout << "Your Color: " << playerColor << endl;
                        cout<< "You lose: $" << moneyWagered << endl;
                    }
                }
                else
                {
                    if(playerColor == "black")
                    {
                        playerMoney = playerMoney+moneyWagered*2+ moneyWagered;
                        cout << "Number is: " << randomNumber << " it's black" << endl;
                        cout << "Your Color: " << playerColor << endl;
                        cout<< "You won: $" << moneyWagered << endl;
                    }
                    else if (playerColor == "red"){
                        cout << "Number is: " << randomNumber << " it's black" << endl;
                        cout << "Your Color: " << playerColor << endl;
                        cout<< "You lose: $" << moneyWagered << endl;
                    }
                }
            }
            else {
                cout<< "You lost all money" << endl;
                break;
            }
            
        }
    }
    
    else if(rouletteOption == 2)
    {
        int playerMoney = 1000;
        string playerEvenOdd = "";
        int randomNumber = 0;
        int moneyWagered = 0;
        while(true){
            cout << "Do you want to bet on even or odd?" << endl;
            cin >> playerEvenOdd;
            if(playerEvenOdd != "even" && playerEvenOdd != "odd")
            {
                cout << "Do you want to bet on even or odd?" << endl;
                cin >> playerEvenOdd;
            }
            cout << "How much would you like to bet?" << endl;
            cout << "Your money: $"<< playerMoney << endl;
            cin >> moneyWagered;
            playerMoney = playerMoney-moneyWagered;
            if(playerMoney > 0)
            {
                srand( static_cast<unsigned int>(time(NULL)));
                randomNumber = rand() % 35 + 1;
                if (randomNumber % 2 == 0)
                {
                    if(playerEvenOdd == "even")
                    {
                        playerMoney = playerMoney+moneyWagered*2+ moneyWagered;
                        cout << "Number is: " << randomNumber << " it's even" << endl;
                        cout << "Your number: " << playerEvenOdd << endl;
                        cout<< "You won: $" << moneyWagered << endl;
                    }
                    else if(playerEvenOdd == "odd") {
                        cout << "Number is: " << randomNumber << " it's even" << endl;
                        cout << "Your number: " << playerEvenOdd << endl;
                        cout<< "You lost: $" << moneyWagered << endl;
                    }
                }
                else
                {
                    if(playerEvenOdd == "odd")
                    {
                        playerMoney = playerMoney+moneyWagered*2+ moneyWagered;
                        cout << "Number is: " << randomNumber << " it's odd" << endl;
                        cout << "Your number: " << playerEvenOdd << endl;
                        cout<< "You won: $" << moneyWagered << endl;
                    }
                    else if(playerEvenOdd == "even")
                    {
                        cout << "Number is: " << randomNumber << " it's odd" << endl;
                        cout << "Your number: " << playerEvenOdd << endl;
                        cout<< "You lost: $" << moneyWagered << endl;
                    }
                }
            }
            else{
                cout<< "You lost all money" << endl;
                break;
            }
        }
    }
    else if(rouletteOption == 3)
    {
        int playerMoney = 1000;
        string playerChoiceNumber = "";
        int randomNumber = 0;
        int moneyWagered = 0;
        while(true)
        {
            srand( static_cast<unsigned int>(time(NULL)));
            randomNumber = rand() % 37;
            cout << "What number would you like to bet on between 00 and 37?" << endl;
            cin >> playerChoiceNumber;
            if(playerChoiceNumber != "0" && playerChoiceNumber != "1" && playerChoiceNumber != "2" && playerChoiceNumber != "3" && playerChoiceNumber != "4" && playerChoiceNumber != "5" && playerChoiceNumber != "6" && playerChoiceNumber != "7" && playerChoiceNumber != "8" && playerChoiceNumber != "9" && playerChoiceNumber != "10" && playerChoiceNumber != "11" && playerChoiceNumber != "12" && playerChoiceNumber != "13" && playerChoiceNumber != "14" && playerChoiceNumber != "15" && playerChoiceNumber != "16" && playerChoiceNumber != "17" && playerChoiceNumber != "18" && playerChoiceNumber != "19" && playerChoiceNumber != "20" && playerChoiceNumber != "21" && playerChoiceNumber != "22" && playerChoiceNumber != "23" && playerChoiceNumber != "24" && playerChoiceNumber != "25" && playerChoiceNumber != "26" && playerChoiceNumber != "27" && playerChoiceNumber != "28" && playerChoiceNumber != "29"
               && playerChoiceNumber != "30" && playerChoiceNumber != "31" && playerChoiceNumber != "32"
               && playerChoiceNumber != "33" && playerChoiceNumber != "34" && playerChoiceNumber != "35"
               && playerChoiceNumber != "36" && playerChoiceNumber != "37")
            {
                cout << "What number would you like to bet on between 00 and 37?" << endl;
                cin >> playerChoiceNumber;
            }
            cout << "How much would you like to bet?" << endl;
            cout << "Your money: $"<< playerMoney << endl;
            cin >> moneyWagered;
            playerMoney = playerMoney - moneyWagered;
            if(playerMoney > 0)
            {
                if((stoi(playerChoiceNumber) >= 0 && stoi(playerChoiceNumber) <= 36) || playerChoiceNumber == "00")
                {
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
            else
            {
                cout<< "You've run out of money" << endl;
                break;
            }
        }
    }
    
}

// Main contains the menu and methods used
int main(int argc, const char * argv[]) {
    int option = 1;
    cout << "Welcome to the Casino!"<< endl;
    // Continues asking for menu until right input is put in
    while (option != option <=0 && option != option >=4)
    {
        // Menu for playing a game, looking at about, and exiting
        cout<<"1. Play a game" << endl;
        cout<<"2. About Casino" << endl;
        cout<<"3. Exit"<<endl;
        cin >> option;
        // Menu for selection of games
        if (option ==1 ){
            int gameOption = 0;
            
            cout<< "What game would you like to play?" << endl;
            cout<< "1. Blackjack" << endl;
            cout<< "2. Five-card Draw Poker" << endl;
            cout<< "3. Slots" << endl;
            cout<< "4. Yahtzee" << endl;
            cout<< "5. Roulette " << endl;
            cout<< "6. Old maid" << endl;
            cout<< "7. Main menu" << endl;
            cin >> gameOption;
            // First game is blackjack, has it's own menu for rules, playing and heading to main menu
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
                    //Play the game
                    string option="";
                    string dealer = "";
                    getDealer(option, dealer);
                    string* deck = initializeDeck();
                    shuffleDeck (deck);
                    blackJack (deck, dealer);
                }
                // Goes to main menu
                else if (blackjackMenu == 3)
                {
                    option = 1;
                }
            }
            // Second game is roulette, has it's own menu for rules, playing and heading to menu
            else if (gameOption == 2)
            {
                int rounds = 0;
                cout<< "How many rounds would you like to play?" << endl;
                cin >> rounds;
                // Continues for however many rounds user wants to play
                while(rounds > 0)
                {
                    string* deck = initializeDeck();
                    shuffleDeck(deck);
                    string compHand[5];
                    string userHand[5];
                    string cardSwap = "";
                    int number = 0;
                    dealPoker(deck, userHand);
                    dealPoker(deck, compHand);
                    displayHand(userHand);
                    cout << endl;
                    cout << "How many Cards would you like to swap? (can be 0-3 cards) " << endl;
                    cin >> number;
                    while (number != 0 && number != 1 && number != 2 && number != 3) {
                        cout << endl << "Invalid! Must be an integer between 0 and 3 " << endl;
                        cin >> number;
                    }
                    // Swaps cards unless invalid
                    for (int i = 1; i < number + 1; i++) {
                        cout << "What is the next card?" << endl;
                        cin >> cardSwap;
                        while (cardExist(userHand, cardSwap) == false) {
                            cout << endl << "Invalid! must be a card that is in your hand! What is the card? " << endl;
                            cin >> cardSwap;
                        }
                        
                        swapCards(deck, userHand, cardSwap);
                        cardSwap = "";
                    }
                    cout << endl << "Here is your new hand" << endl;
                    displayHand(userHand);
                    cout << endl;
                    
                    int userScore = getScore(userHand);
                    int compScore = getScore(compHand);
                    
                    if (userScore == 0 && compScore == 0) {
                        userScore = highCard(userHand);
                        compScore = highCard(compHand);
                    }
                    // Displays who won and the computers hand
                    cout << "This was the computer's hand " << endl;
                    displayHand(compHand);
                    cout << endl << endl << endl;
                    
                    cout << endl << "Possible Scores" << endl;
                    cout << "Two of a kind: 1 point" << endl << "Two pair: two points " << endl << "Three of a kind: 3 points" << endl << "Flush: 4 points" << endl;
                    cout << "Full House: 5 points" << endl << "4 of a Kind: 6 points" << endl;
                    
                    cout << endl << "User score: " << userScore << endl;
                    cout << endl << "Comp score: " << compScore << endl;
                    
                    if (compScore > userScore) {
                        cout << "Computer wins!"<<endl<<endl;
                        rounds--;
                    }
                    else if (userScore > compScore) {
                        cout << "You win!" << endl<<endl;
                        rounds--;
                    }
                    else {
                        cout << endl << "Tie!" << endl<<endl;
                        rounds--;
                    }
                }
            }
            
            else if (gameOption == 3)
            {
                int slotsMenu = 0;
                cout << "--Welcome to the Ultimate Slot Game!--" << endl;
                cout << "   Try your luck with our wonderful slot machine!  " << endl;
                cout << "1. View rules" << endl;
                cout << "2. Play Slots" << endl;
                cout << "3. Go to main menu" << endl;
                cin >> slotsMenu;
                if(slotsMenu == 1)
                {
                    option = 1;
                }
                else if (slotsMenu == 2)
                {
                    //play the game
                    slots();
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
                    //Displays the rules for yahtzee
                    YahtzeeRules();
                }
                else if (yahtzeeMenu == 2)
                {
                    //plays the yahtzee game.
                    MasterYahtzee();
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
                    roulette();
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
                    oldMaidRules();
                    
                }
                else if (oldMaidMenu == 2)
                {
                    oldMaid();
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
        else if (option == 2)
        {
            //
            cout<<"This game is a collection of casino related games, in some games" <<endl;
            cout<<"you'll be able to bet (fake) money until your money runs out. In" <<endl;
            cout<<"other games your goal is to acquire the most points or beat the" <<endl;
            cout<<"computer. The games in this collection are: blackjack, five-card" <<endl;
            cout<<"draw poker, slots, yahtzee, roulette and Old maid." << endl;
            
        }
        else if (option == 3)
        {
            cout << "Thanks for playing!" << endl;
            exit(0);
        }
    }
}
