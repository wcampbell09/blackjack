#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "casino.h"
using namespace std;

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
            // Starts five-card poker menu
            else if (gameOption == 2)
            {
                int pokerMenu = 0;
                cout << "Lets play some five-card poker!" << endl;
                cout << "1. View rules" << endl;
                cout << "2. Play five-card poker" << endl;
                cout << "3. Go to main menu" << endl;
                cin >> pokerMenu;
                // Displays the rules
                if(pokerMenu == 1)
                {
                    cout << "You're given 5 cards and you swap your selected cards." << endl;
                    cout << "Points are rewarded based on poker rules." << endl;
                }
                // Starts slots
                else if (pokerMenu == 2)
                {
                    poker();
                }
                // Goes to main menu
                else if (pokerMenu == 3)
                {
                    option = 1;
                }
                
            }
            // Starts slots menu
            else if (gameOption == 3)
            {
                int slotsMenu = 0;
                cout << "--Welcome to the Ultimate Slot Game!--" << endl;
                cout << "   Try your luck with our wonderful slot machine!  " << endl;
                cout << "1. View rules" << endl;
                cout << "2. Play Slots" << endl;
                cout << "3. Go to main menu" << endl;
                cin >> slotsMenu;
                // Displays the rules
                if(slotsMenu == 1)
                {
                    cout << "Every player begins with 100 credits. For this slot machine, you can bet on either 1, 3, 5 or 7 lines. The cost of each bet depends on how many lines the player is betting on (i.e. 3 lines = 3 credits, 5 lines = 5 credits, etc). The amount of credits won depends on how many winnings lines the player spins. The more winning lines in the same spin, the more credits accumulated. Once a player runs out of credits, the game ends." << endl;
                }
                // Starts slots
                else if (slotsMenu == 2)
                {
                    slots();
                }
                // Goes to main menu
                else if (slotsMenu == 3)
                {
                    option = 1;
                }
            }
            // Starts Yahtzee menu
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
                    // Starts Yahtzee
                    MasterYahtzee();
                }
                    // Goes to main menu
                else if (yahtzeeMenu == 3)
                {
                    option = 1;
                }
            }
            // Starts menu for playing roulette
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
                // Displays the rules for roulette
                    printRulesRoulette();
                }
                // Starts roulette
                else if (rouletteMenu == 2)
                {
                    roulette();
                }
                // Goes back to main menu
                else if (rouletteMenu == 3)
                {
                    option = 1;
                }
                
            }
            // Starts menu for playing old maid
            else if (gameOption == 6)
            {
                int oldMaidMenu = 0;
                cout << "Lets play some Old Maid!" << endl;
                cout << "1. View rules" << endl;
                cout << "2. Play Old Maid" << endl;
                cout << "3. Go to main menu" << endl;
                cin >> oldMaidMenu;
                // Displays rules for Old Maid
                if(oldMaidMenu == 1)
                {
                    oldMaidRules();
                    
                }
                // Starts Old Maid
                else if (oldMaidMenu == 2)
                {
                    oldMaid();
                }
                // Goes back to main menu
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
        // Prints out information about the casino
        else if (option == 2)
        {
            cout<<"This game is a collection of casino related games, in some games" <<endl;
            cout<<"you'll be able to bet (fake) money until your money runs out. In" <<endl;
            cout<<"other games your goal is to acquire the most points or beat the" <<endl;
            cout<<"computer. The games in this collection are: blackjack, five-card" <<endl;
            cout<<"draw poker, slots, yahtzee, roulette and Old maid." << endl;
            
        }
        // Exits the entire project
        else if (option == 3)
        {
            cout << "Thanks for playing!" << endl;
            exit(0);
        }
    }
}