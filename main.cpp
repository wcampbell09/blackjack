//#include "blackjack.h"
//#include <QApplication>
#include <iostream>
#include <string>
using namespace std;


//deals a card to the user, takes in the deck as an array
void dealACard(string deck[])
{
    //the use of a static int allows us to save where we are in the deck when this method is used repeatedly 
    static int num = 0;
    cout<< deck[num];
    //the number is added to every time the deck is called in order for us to be a spot up in the deck when the method is called again 
    num++;
}
// Simply displays all the rules of blackjack 
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
//prints out each value within the deck array by simply iterating through the 52 spots of the array 
void displayDeck(string deck[])
{
    for (int i=0; i<=52; i++)
    {
        cout << deck[i] << endl;
    }
}
//emily fixed shuffle deck
//method to shuffle the deck 
void shuffleDeck(string deck[])
{
    int r =0;
    //string hold will hold the value of deck[i] so that we may set the random spot in the deck to the value of deck[i]
    string hold;
    for (int i = 0; i <52; i++)
    {
        mt19937 rng (std::random_device{}());
        uniform_int_distribution<> dist (0, 51);

        //r becomes a random integerin the range 0 to 52
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
//added by emily makes next card in deck read "empty" adds that string to an array for the player or computer's hand
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
//added by emily. called when someone decides to hit does the same thing as deal but only one card is given.
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
string getDealer (string option, string dealer)
{
    cout << "Deal Yes or No?" << endl;
    cin >> option ;
    
    if (option == "Yes")
    {
        dealer = "player";
    }
    else
    {
        dealer = "computer";
    }
    return dealer;
}
//added by emily. checks the card value by first character in card string, returns an int value.
int checkCard (string card)
{
    int cardValue;
    //for cards that are not face cards then the value of the card is simply the number on the card
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
    //if the card starts with 'A' then it is an Ace and its value is 11
    else if (card.at(0) == 'A')
    {
        cardValue = 11;
    }
    else
        //otherwise the card is a facecard and in blackjack all face cards other than the Ace have  a value of 10 
    {
        cardValue = 10;
    }
    return cardValue;
}

//initialize card hand
void initializeHand (string hand[])
{
    // initializes card hand by making each spot equal to an empty string
    for (int i=0; i<52; i++)
    {
        hand[i]="";
    }
    
}
//checks to make sure an integer the user enters to gamble is in fact an integer 
bool isInt(int n)
{
    int i = 0;
    string str = "" + n;
    for(i = 0; i <= str.length(); i++)
    {
        if((str.at(i))!=('.'))
        {
            return false;
        }
    }
    return true;
}

//added by emily. plays the game, sort of, i think??
void blackJack (string deck [], string dealer)
{
    //still need to incorporate gambling. still need to check that i did this right based off of the rules
    
    
    string playerHand[52];//array for players hand
    string compHand[52];
    
    int playerCard=0;//first player card in hand
    int playerFinal =0;//sum of cards from player
    
    
    int i = 52;//value of number of cards in deck is used to check how many cards are left in pile throughout the game
    
    int round=1;
    
    int playerValue = 1000;
    
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
        

        cout<< "How much would you like to wager?" << endl;
        cout<< "Your money: $1000" << endl;
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
        
        while (move=="Hit" && playerFinal<=21)
        {
            if (playerFinal==21)
            {
                break;
            }
            
            cout << "Hit or Stay" << endl;
            cin>> move;
            
            //STUCK IN INFINITE FOR LOOP...  This is suppose to check if it is Hit or Stay
            //while(move.compare("Hit")!=0 || move.compare("Stay")!=0)
           // {
            //    cout<< "Please enter Hit or Stay only." << endl;
           //     cout << "Hit or Stay" << endl;
            //    cin>> move;
          //  }
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
                    cout << "Would you like your ace to be worth 1 or 11?"<< endl;
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
                        cout << "Would you like your ace to be worth 1 or 11?"<< endl;
                        cin >> playerCard;
                    }
                    playerFinal=playerFinal+playerCard;
                    n++;
                }
                cout << "Your move: " << playerFinal<< endl;
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
            cout << "You win. Computer's hand is over 21"<< endl;
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
        if (playerValue==0){
            cout<< "You have no money left" << endl;
            break;
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
            cout<< "4. Roulette" << endl;
            cout<< "5. Yahtzee" << endl;
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
                    dealer = getDealer(option, dealer);
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
                cout << "2. Play Slots" << endl;
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
                    //Displays the rules for go fish
                    
                }
                else if (rouletteMenu == 2)
                {
                    //play the game
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

