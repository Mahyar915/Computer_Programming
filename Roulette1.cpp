//
//  Roulette Simulation
//  Mohammad Mahyar Pourabdollah khadar

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <ctime>

using namespace std;
int initialChips = 1000;
int Wager = 0;
int exactWinning = 0;
int winningGuess = 0;
string winningGuessStr;
int wagerType;
char countinueTheGame;
string wagerTypeStr;
int currentBalance = 0;
const int HIGH = 37;
const int LOW = 0;
bool guessInRange = false;
bool wantToRedoRoullete = true;
char DoYouWantToPlayAgain = 'Y';



int main() {


    currentBalance = initialChips;

    while (wantToRedoRoullete == true) {




        cout << " Your current balance is: " << currentBalance << "Chip(s)." << endl;

        cout << "-------------------------------------------------------------------" << endl;
        cout << "|  Input  |  Wager                                    |  Payout   |" << endl;
        cout << "-------------------------------------------------------------------" << endl;
        cout << "|    1    |  Even numbers ( 2,   4,   6,  ...,  36)   |  1 to  1  |" << endl;
        cout << "|    2    |  Odd  numbers ( 1,   3,   5,  ...,  35)   |  1 to  1  |" << endl;
        cout << "|    3    |  1st half     ( 1,   2,   3,  ...,  18)   |  1 to  1  |" << endl;
        cout << "|    4    |  2nd half     ( 19, 20,  21,  ...,  36)   |  1 to  1  |" << endl;
        cout << "|    5    |  Exact guess  ( 1 to 36,  0, and  00  )   |  35 to 1  |" << endl;
        cout << "-------------------------------------------------------------------" << endl;


        // ******  Generating Random Number    *****

        srand((unsigned int)time(0));
        exactWinning = rand() % (HIGH - LOW + 1) + LOW;


        // ****** For testing winning Number   ******
        cout << "the exact Wining Number is: " << exactWinning << endl;



        // ***** Different Options for betting ******


        do {
            cout << "Please enter a number between 1 to 5: " << endl;
            cin >> wagerType;

        } while (wagerType > 5 || wagerType < 1);

        if (wagerType == 1) wagerTypeStr = "Even Numbers";
        if (wagerType == 2) wagerTypeStr = "Odd Numbers";
        if (wagerType == 3) wagerTypeStr = "1st half";
        if (wagerType == 4) wagerTypeStr = "2nd half";
        if (wagerType == 5) {
            wagerTypeStr = "Exact guess";


            // *******  Range of winingGuess  ********

            do {
                cout << "Please Enter the Exact Guess in between 0 to 36 including 00!" << endl;
                cin >> winningGuessStr;

                if (winningGuessStr != "00" && stoi(winningGuessStr) >= 0 && stoi(winningGuessStr) <= 36) {

                    winningGuess = stoi(winningGuessStr);
                    guessInRange = true;

                }
                if (winningGuessStr == "00") {
                    winningGuess = 37;
                    guessInRange = true;
                }
            } while (!guessInRange);

        }
        // ******* The amount for bet     ********


        do {
            cout << "Please enter your wager: " << endl;
            cout << "Your Wager should be less than " << currentBalance << " chip(s) or not to be Zero!" << endl;
            cin >> Wager;
            cout << " Your wager is " << Wager << " chip(s)" << "on " << wagerTypeStr << endl;

        } while (Wager > currentBalance || Wager == 0);

        currentBalance = currentBalance - Wager;


        // Spin the Roulette

        cout << "Let's spin the Roulette" << endl;

        // *****  calculating the amount for winning or losing of User ***********


        switch (wagerType) {
        case 1:
            if (exactWinning % 2 == 0 && exactWinning != 0) {
                currentBalance = currentBalance + 2 * Wager;
                cout << "Well done! you won and your current balance is : " << currentBalance << endl;
            }
            else {
                cout << "You Game Over, Sorry! " << endl;

            }

            break;
        case 2:
            if (exactWinning % 2 == 1 && exactWinning != 37) {
                currentBalance = currentBalance + 2 * Wager;
                cout << "Well done! you won and your current balance is : " << currentBalance << endl;
            }
            else {
                cout << "You Game Over, Sorry! " << endl;

            }
            break;
        case 3:
            if (exactWinning <= 18 && exactWinning >= 1) {
                currentBalance = currentBalance + 2 * Wager;
                cout << "Well done! you won and your current balance is : " << currentBalance << endl;
            }
            else {
                cout << "You Game Over, Sorry! " << endl;

            }
            break;
        case 4:
            if (exactWinning <= 36 && exactWinning >= 19) {
                currentBalance = currentBalance + 2 * Wager;
                cout << "Well done! you won and your current balance is : " << currentBalance << endl;
            }
            else {
                cout << "You Game Over, Sorry! " << endl;

            }
            break;
        case 5:
            if (winningGuess == exactWinning) {
                currentBalance = currentBalance + 36 * Wager;

                cout << "You Made it!! Perfect, you won and your current balance is : " << currentBalance << endl;
            }
            else {
                cout << "You Game Over, Sorry! " << endl;

            }
            break;


        default:
            break;
        }

        // *******   Redo Condition   *************


        if (currentBalance <= 0) {
            wantToRedoRoullete = false;
            cout << "You are Done! Hope see you next time!" << endl;
        }
        if (currentBalance > 0) {
            cout << "Do you want to play again (Y/N) ?" << endl;

            cin >> DoYouWantToPlayAgain;

            if (toupper(DoYouWantToPlayAgain) == 'Y')
                wantToRedoRoullete = true;


            else {
                cout << "You are Done! Hope see you next time !" << endl;
                wantToRedoRoullete = false;
            }

        }

    }
    return 0;

}
