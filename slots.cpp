#include <iostream>
#include <string>
#include <limits>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;

int main() {
    int money = 50;
    int selection;
    int credits = 100;
    int lineNumber;
    string cont;

    cout << "--Welcome to the Ultimate Slot Game!--" << endl;
    cout << "   Try your luck with our wonderful slot machine!    " << endl;


        cout << "Options:" << endl;
        cout << "Type 1 to begin" << endl;
        cout << "Type 2 for Rules" << endl;
        cout << "Type 3 to exit" << endl;
        cin >> selection;

        if (selection == 1) {


        do{
            cout << "Type anything to continue, or 0 to close";
            cin >> cont;
            if (cont == "0") {
                break;
            }

        while (true) {

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
        }

        while(true);

        if (credits < 0)
 {


        {cout<<"Come back Again!"<<endl;}
        system("pause");
        return 0;
        }
        }
        else if (selection == 2) {

        }
        else if (selection == 3) {
            cout << "Goodbye!" << endl;
        }
        else {
            cout << "Invalid Input! Have a nice day!" << endl;
        }
}
