//  main.cpp
//  Black Jack


//#include "blackjack.h"
//#include <QApplication>

#include <iostream>
#include <string>
using namespace std;

void dealACard(string deck[])
{
    static int num = 0;
    cout<< deck[num];
    num++;
}

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

//Emily fixed the initialize deck
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

void displayDeck(string deck[])
{
    for (int i=0; i<=52; i++)
    {
        cout << deck[i] << endl;
    }
}
//emily fixed shuffle deck
void shuffleDeck(string deck[])
{
    int r =0;
    string hold;
    for (int i = 0; i <52; i++)
    {
        srand( static_cast<unsigned int>(time(NULL)));
        r = rand() % 52 ;
        hold = deck[i];
        deck [i]= deck [r];
        deck [r] = hold;
        hold = "";
    }
}
//added by emily makes next card in deck read "empty" adds that string to an array for the player or computer's hand
void deal (string deck[], string hand[])
{
    int i=0;
    while (deck[i]== "empty" && i<52)
    {
        i++;
    }
    hand [0]=deck [i];
    deck [i]= "empty";
    while (deck[i]== "empty" && i<52)
    {
        i++;
    }
    hand [1]=deck [i];
    deck [i]= "empty";
    
}
//added by emily. called when someone decides to hit does the same thing as deal but only one card is given.
void hit (string deck[], string hand [])
{
    int i=0;
    int j=0;
    while (deck[i]== "empty" && i<=51)
    {
        i++;
    }
    while (hand[j]!= "" && j<=51)
    {
        j++;
    }
    hand [j]=deck [i];
    deck [i]= "empty";
}
//saves who the dealer is in a string, either player or computer based on if player says yes or no.
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
//added by emily. checks the card value by first character in card string, returns an int value.
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

//initialize card hand
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

//added by emily. plays the game, sort of, i think??
void blackJack (string deck [], string &dealer)
{
    //still need to incorporate gambling. still need to check that i did this right based off of the rules
    
    
    string playerHand[52];//array for players hand
    string compHand[52];
    
    int playerCard=0;//first player card in hand
    int playerFinal =0;//sum of cards from player
    
    
    int i = 52;//value of number of cards in deck is used to check how many cards are left in pile throughout the game
    
    int round=1;
    
    int playerValue = 1000;
    
    
    while ((i > 3) && playerValue > 0)
    {
        string move="Hit";//determines whether player wants to hit or stay
        initializeHand(playerHand);
        initializeHand(compHand);
       
        playerFinal=0;
        int compFinal=0;
        
        cout<< "Round "<<round++ <<endl;
        //plays the game until the deck runs out
        deal (deck, playerHand);
        deal (deck, compHand);
        i -= 4;//subtracts 4 from card pile because 2 cards are dealt to each player
        
        //gambling portion:
        int n = 0;
        
        //
        //
        //
        //
        //DOES NOT WORK FOR AN INVALID INPUT... NEED TO FIX
        cout<< "How much would you like to wager?" << endl;
        cout<< "Your money: $" << playerValue << endl;
        cin >> n;
        cin.clear();
        cin.ignore(1000,'\n');
        while(true)
        {
            if(n==0)
            {
                cout<< "Please enter an integer value." << endl;
                cin >> n;
                cin.clear();
                cin.ignore(1000,'\n');
            }

            else if(n <= playerValue)
            {
                playerValue -= n;
                break;
            }
            else
            {
                cout<< "You cannot wager more than you have." << endl;
                cout<< "Please enter a smaller value." << endl;
                cin >> n;
                cin.clear();
                cin.ignore(1000,'\n');
            }
        }
        
        if (dealer == "player")
        {
            cout<< "Computer's hand is: " << compHand[0] << " " << compHand[1]<<endl;
        }
        else
        {
            cout<< "Computer's hand is: " << compHand[0]<<endl;
        }
        cout << "Your hand: "<< playerHand [0] << " "<< playerHand [1]<< endl;//shows player their hand
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
        }
        cout << "Your hand value: " << playerFinal<< endl;
       
            if (playerFinal==21)
            {
                cout << "Your hand value: " << playerFinal<< endl;
                
            }
            else {
            cout << "Hit or Stay" << endl;
            cin>> move;
            }
            //STUCK IN INFINITE FOR LOOP...  This is suppose to check if it is Hit or Stay
            //while(move.compare("Hit")!=0 || move.compare("Stay")!=0)
            // {
            //    cout<< "Please enter Hit or Stay only." << endl;
            //     cout << "Hit or Stay" << endl;
            //    cin>> move;
            //  }
            //if player wants to hit, subtracts from i (the card pile) checks values of cards and sums them.
            //if any cards are an ace the player is asked what value they would like it to hold.
            if (move == "Stay" || move == "stay"){
            }
            else if (move == "Hit" || "hit" )
            {
                while (move == "Hit" || "hit"){
                    hit (deck, playerHand);
                    i --;
                    int j=0;
                
                    while (playerHand[j]!= "" && j<=51)
                    {
                        j++;
                    }
                    cout << playerHand [j-1]<< endl ;
                
                    playerCard=checkCard(playerHand[j-1]);
                    
                    if (playerCard==11)
                    {
                        cout << "Would you like your ace to be worth 1 or 11?"<< endl;
                        cin >> playerCard;
                    }
                
                    playerFinal=playerFinal+playerCard;
                    j++;
                    if(playerFinal > 21)
                    {
                        cout << "You went over 21" << endl;
                        break;
                    }
                    cout << "Your hand value: " << playerFinal<< endl;
                    cout << "Hit or Stay?"<<endl;
                    cin>> move;
                    if (move == "Stay" || move == "stay")
                    {
                        cout << "Your hand value: " << playerFinal<< endl;
                        break;
                    }
                }
            }
            //if player wants to stay, card values are checked (if any are A then they are asked 1 or 11). card values are summed.
        


        //the following is for the computer. checks the card values dealt. if any are A's then decides to make 1 or 11 based on
        //value of other card. if the sum of cards is less than 17, then the computer will hit. if it is more than it will stay.
        
        int compCard;
        int count=0;
        j=0;
        int m;
        while (compHand[j]!= "" && j<=51)
        {
            compCard=checkCard(compHand[j]);
            if (compCard!=11)
            {
                compFinal=compFinal+ compCard;
                
            }
            else
            {
                count=count+1;
            }
            j++;
        }
        if (count>0)
        {
            for (int k = 1; k<=count; k++)
            {
                if (compFinal <= 10 )
                {
                    compFinal = compFinal+11;
                }
                else
                {
                    compFinal = compFinal+11;
                }
            }
            
        }
        cout << "Computer hand: "<< compHand [0] << " "<< compHand[1]<< endl;//shows player their hand
        cout << "Computer move: " << compFinal<< endl;
        m=2;
        
        while (compFinal<17)
        {
            if (playerFinal>21){
                break;
            }
            hit (deck, compHand);
            
            compCard = checkCard (compHand [m]);
            
            if (compCard == 11 && compFinal <= 10)
            {
                
                compCard = 11;
                
            }
            
            else if (compCard == 11 && compFinal > 10)
            {
                
                compCard = 1;
                
            }
            
            compFinal += compCard;
            
            cout<< compHand[m]<< endl;
            
            m++;
            
            cout << "Computer move: "<< compFinal<< endl;
            
        }
        
        //checks to see if comp or player won the round
        if (playerFinal > 21)
        {
            cout << "You lose, your hand is over 21"<<endl;
            //Gambling portion:
            cout<< "You have $"  << playerValue << endl;
        }
        else if (compFinal > playerFinal && compFinal <=21)
        {
            cout << "You lose, computer wins"<< endl;
            //Gambling portion:
            cout<< "You have $"  << playerValue << endl;
        }
        else if (compFinal > 21 && playerFinal <= 21)
        {
            cout << "You win. Computer hand is over 21"<< endl;
            playerValue += 2*n;
            cout<< "You have $"  << playerValue << endl;
        }
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

