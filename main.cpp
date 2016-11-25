#include "blackjack.h"
#include <QApplication>
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    blackjack w;
    w.show();

    int option;
    cout<< "1. View Rules "<<endl <<"2. Tutorial"<<endl<<"3.Play Game"<<endl;
    cin >> option;
    if (option ==1 ){
        displayRules();
    }
    else if (option == 2){
        //tutorial
    }
    else if (option == 3){
        //play the game
        string option="";
        cout << "Deal Yes or No?" << endl;
        menu();
        cin >> option ;
        cout << "Starting Deal" << endl;
        string* deck = initializeDeck();
        displayDeck(deck);

    }

    return a.exec();
}

void menu(){
    cout << "Hit or Stay" << endl;
}

void shuffleDeck(string deck[])
{
    int r;
    string hold;
    for (int i = 0; i <52; i++){
        r = rand() % 53 ;
        hold = deck[i];
        deck [i]= deck [r];
        deck [r] = hold;
    }
}

void dealACard(string deck[])
{
    static num = 0;
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

Whether or not the dealer must hit on a soft 17 (a hand of 17 containing an ace being counted as 11) differs from casino to casino. There might even be blackjack tables with different rules within the same casino.
}

string* initializeDeck()
{
    string* deck = new string [52];
    for (int i = 1; i<14; i++){
        string cardNum; to_string(i +1);
        if (i == 10){
            cardNum = "J";
        }
        else if (i == 11){
            cardNum = "Q";

        }
        else if (i == 12 ){
            cardNum = "K";

        }
        else if (i == 13){
            cardNum = "A";
        }
        else {
            cardNum = to_string(i +1);
        }
        deck[i]= cardNum + "S";
    }
    for (int i = 1; i<14; i++){
        string cardNum; to_string(i +1);
        if (i == 10){
            cardNum = "J";
        }
        else if (i == 11){
            cardNum = "Q";

        }
        else if (i == 12 ){
            cardNum = "K";

        }
        else if (i == 13){
            cardNum = "A";
        }
        else {
            cardNum = to_string(i +1);
        }
        deck[i+13]= cardNum + "D";

    }
    for (int i = 1; i<14; i++){
        string cardNum; to_string(i +1);
        if (i == 10){
            cardNum = "J";
        }
        else if (i == 11){
            cardNum = "Q";

        }
        else if (i == 12 ){
            cardNum = "K";

        }
        else if (i == 13){
            cardNum = "A";
        }
        else {
            cardNum = to_string(i +1);
        }
        deck[i+26]= cardNum + "C";

    }
    for (int i = 1; i<14; i++){
        string cardNum; to_string(i +1);
        if (i == 10){
            cardNum = "J";
        }
        else if (i == 11){
            cardNum = "Q";

        }
        else if (i == 12 ){
            cardNum = "K";

        }
        else if (i == 13){
            cardNum = "A";
        }
        else {
            cardNum = to_string(i +1);
        }
        deck[i+39]= cardNum + "H";

    }
    return deck;
}

void displayDeck(string deck[])
{
    for (int i=0; i<=52; i++){
        cout << deck[i] << endl;
    }
}


