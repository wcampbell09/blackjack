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
void getDealer (string option, string dealer)
{
    cout << "Deal Yes or No?" << endl;
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

//added by emily. plays the game, sort of, i think??
void game (string deck [], string dealer)
{
    //still need to incorporate gambling. still need to check that i did this right based off of the rules
    
    
    string playerHand[52];//array for players hand
    string compHand[52];
    
    int playerCard=0;//first player card in hand
    int playerFinal =0;//sum of cards from player
    
    
    int i = 52;//value of number of cards in deck is used to check how many cards are left in pile throughout the game
    
    int round=1;
    int n;
    
    while (i > 3)
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
        int playerValue = 0;
        cout<< "How much would you like to wager? 1, 5, 10, 50, or 100?" << endl;
        cin>> n;
        playerValue += n;
        
        cout << "Your hand: "<< playerHand [0] << " "<< playerHand [1]<< endl;//shows player their hand
        int j=0;
        while (playerHand[j]!= "" && j<=51)
        {
            
            playerCard=checkCard(playerHand[j]);
            
            if (playerCard==11)
            {
                cout << "would you like your ace to be worth 1 or 11?"<< endl;
                cin >> playerCard;
            }
            
            playerFinal=playerFinal+playerCard;
            j++;
        }
        cout << "your move: " << playerFinal<< endl;
        
        while (move=="Hit" && playerFinal<=21)
        {
            if (playerFinal==21){
                
                break;
            }
            cout << "Hit or Stay" << endl;
            cin>> move;
            cout << endl;
            //if player wants to hit, subtracts from i (the card pile) checks values of cards and sums them.
            //if any cards are an ace the player is asked what value they would like it to hold.
            if (move == "Stay"){
                break;
            }
            if (move == "Hit" )
            {
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
                    cout << "would you like your ace to be worth 1 or 11?"<< endl;
                    cin >> playerCard;
                }
                
                playerFinal=playerFinal+playerCard;
                j++;
                
                cout << "your move: " << playerFinal<< endl;
            }
            //if player wants to stay, card values are checked (if any are A then they are asked 1 or 11). card values are summed.
            else if (move == "Stay")
            {
                n=0;
                int playerFinal=0;
                while (playerHand[n]!= "" && n<=51)
                {
                    playerCard=checkCard(playerHand[n]);
                    if (playerCard==11)
                    {
                        cout << "would you like your ace to be worth 1 or 11?"<< endl;
                        cin >> playerCard;
                    }
                    playerFinal=playerFinal+playerCard;
                    n++;
                }
                cout << "your move: " << playerFinal<< endl;
            }
        }
        
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
        cout << "computer move: " << compFinal<< endl;
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
            
            cout << "computer move: "<< compFinal<< endl;
            
        }
        
        //checks to see if comp or player won the round
         if (playerFinal > 21)
        {
            cout << "you loose, over 21\n"<<endl;
            //Gambling portion:
            playerValue -= n;
            cout<< "You have $"  << playerValue << endl;
        }
        else if (compFinal > playerFinal && compFinal <=21 )
        {
            cout << "you loose, computer wins\n"<< endl;
            //Gambling portion:
            playerValue -= n;
            cout<< "You have $"  << playerValue << endl;
        }
        else if (compFinal > 21 && playerFinal <= 21)
        {
            cout << "You win. Computer over 21 \n"<< endl;
            playerValue += n;
            cout<< "You have $"  << playerValue << endl;
        }
        else if (playerFinal > compFinal && playerFinal <=21)
        {
            cout << "You win.\n "<< endl;
            playerValue += n;
            cout<< "You have $"  << playerValue << endl;
        }
        //this is in case of tie, checks to see who dealer was and gives them the win.
        else {
            if (dealer == "player")
            {
                cout << "you win the tie"<< endl;
            }
            else
            {
                cout << "computer wins the tie"<< endl;
                playerValue -= n;
                cout<< "You have $"  << playerValue << endl;
            }
        }
        cout << endl;
    }
    cout << "out of cards";
}

int main(int argc, const char * argv[]) {
    // QApplication a(argc, argv);
    // blackjack w;
    // w.show();
    
    
    int option;
    
    cout << "Welcome to blackjack!!"<< endl;
    while (option !=4)
    {
        cout<< "\n1. View Rules "<<endl <<"2. Tutorial"<<endl<<"3. Play Game"<<endl<<"4. Exit"<<endl;
        cin >> option;
        
        if (option ==1 ){
            //display rules
            displayRules();
            
        }
        
        else if (option == 2){
            //tutorial
        }
        
        else if (option == 3){
            //play the game
            string option="";
            string dealer;
            getDealer (option, dealer);
            string* deck = initializeDeck();
            shuffleDeck (deck);
            game (deck, dealer);
            
        }
        else
        {
            exit(0);
            
        }
    }
}
