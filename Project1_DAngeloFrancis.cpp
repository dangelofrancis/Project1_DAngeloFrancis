//************************************************
// TITLE: Rock Paper Scissors                    *
// FILE NAME: Project1_DAngeloFrancis.cpp        *
// PROGRAMMER: D'Angelo Francis                  *
// DATE: February 10, 2025                       *
// REQUIREMENTS:Create a game of rock, paper,    *
// scissors vs the computer                      *
//************************************************

#include <iostream>
#include <random>
using namespace std;

//************************************************
// Description of the function displayTitle      *
// This function displays the title of the Rock  *
// Paper Scissors game                           *
//************************************************

void displayTitle();

//************************************************
// Description of the function getPlayerChoice   *
// This function asks the user to select Rock,   *
// Paper, Scissors, or Quit by entering a number *
//************************************************

int getPlayerChoice(bool& gameRunning);

//************************************************
// Description of the function getComputerChoice *
// This function randomly generates a number 1-3 *
// Each of the numbers corresponds to Rock, Paper*
// or Scissors, and whichever is generated will  *
// serve as the computer's choice                *
//************************************************

int getComputerChoice();

//************************************************
// Description of the function showComputerChoice*
// This function takes the randomly generated    *
// number from getComputerChoice, determines     *
// whether it will be Rock, Paper, Or Scissors,  *
// and displays the computer's choice on screen  *
//************************************************

void showComputerChoice(int computerChoice);

//************************************************
// Description of the function determineWinner   *
// This function compares the player's choice    *
// with the computer's choice, and figures out   *
// which one will win                            *
//************************************************

string determineWinner(int playerChoice, int computerChoice);

//************************************************
// Description of the function displayWinner     *
// This function displays a short message of who *
// won the round                                 *
//************************************************

void displayWinner(string winner);

//************************************************
// Description of the function updateScores      *
// This function updates the scoreboard if ther  *
// was a winner for the round                    *
//************************************************

void updateScores(string winner, int scores[]);

//************************************************
// Description of the function displayScores     *
// This fucntion displays a scoreboard after the *
// round ends                                    *
//************************************************

void displayScores(int scores[]);

//************************************************
// The main function                             *
//************************************************

int main() {
    bool gameRunning = true;
    int scores[2] = { 0,0 };

    while (gameRunning) {
        displayTitle();
        int playerChoice = getPlayerChoice(gameRunning);

        if (!gameRunning) { 
            cout << "\nExiting game.\n";
            break;
        }

        int computerChoice = getComputerChoice();
        showComputerChoice(computerChoice);
        string winner = determineWinner(playerChoice, computerChoice);
        displayWinner(winner);
        updateScores(winner, scores);
        displayScores(scores);
        cout << "*******************************\n\n";
    }
    return 0;
}
void displayTitle() {
    cout << "ROCK PAPER SCISSORS TOURNAMENT \n\n";
    cout << "******************************* \n\n";
}
int getPlayerChoice(bool& gameRunning) {
    int choice;

    do {
        cout << "MAKE YOUR SELECTION:\n\n";
        cout << "1. ROCK\n";
        cout << "2. PAPER\n";
        cout << "3. SCISSORS\n";
        cout << "4. QUIT\n\n";

        cout << "(Enter a number 1-4 to make your choice): ";
        cin >> choice;

        if (choice < 1 || choice > 4 || cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "*ERROR* Invalid choice. Try again.\n\n";
        }
    } while (choice < 1 || choice > 4);

    if (choice == 4) {
        gameRunning = false;
    }

    return choice;
}
int getComputerChoice() {
    random_device numberEngine;
    uniform_int_distribution<int> randomInt(1, 3);
    return randomInt(numberEngine);
}
void showComputerChoice(int computerChoice) {
    if (computerChoice == 1)
        cout << "\nComputer chose Rock!\n";
    else if (computerChoice == 2)
        cout << "\nComputer chose Paper!\n";
    else if (computerChoice == 3)
        cout << "\nComputer chose Scissors!\n";
}
string determineWinner(int playerChoice, int computerChoice) {
    if (playerChoice == computerChoice) {
        return "draw";
    }

    if (playerChoice == 1 && computerChoice == 3) {
        cout << "Rock smashes scissors.\n";
        return "player";
    }
    else if (playerChoice == 2 && computerChoice == 1) {
        cout << "Paper covers rock.\n";
        return "player";
    }
    else if (playerChoice == 3 && computerChoice == 2) {
        cout << "Scissors cuts up paper.";
        return "player";
    }

    return "computer";
}
void displayWinner(string winner) {
    if (winner == "player")
        cout << "You won!\n\n";
    else if (winner == "computer")
        cout << "The computer won!\n\n";
    else if (winner == "draw")
        cout << "It was a draw!\n\n";
}
void updateScores(string winner, int scores[]) {
    if (winner == "player")
        scores[0]++;
    if (winner == "computer")
        scores[1]++;
}
void displayScores(int scores[]) {
    cout << "SCOREBOARD: ";
    cout << "Player: " << scores[0];
    cout << " | Computer: " << scores[1] << endl << endl;
}