#include <iostream>
#include <string>
using namespace std;

void menu(){
    cout << "Hit or Stay" << endl;
}

string ShuffleDeck(){
    return 0;
}

string* initializeDeck(){
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

void displayDeck(string deck[]){
    for (int i=0; i<=52; i++){
        cout << deck[i] << endl;
    }
}

int main(int argc, const char * argv[]) {
    int option;
    cout<< "1. View Rules "<<endl <<"2. Tutorial"<<endl<<"3.Play Game"<<endl;
    cin >> option;
    if (option ==1 ){
        //display rules
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
}

