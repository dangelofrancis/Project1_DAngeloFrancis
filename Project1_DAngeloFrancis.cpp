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

void displayTitle();
int getPlayerChoice(bool& gameRunning);
int getComputerChoice();
void showComputerChoice(int computerChoice);
string determineWinner(int playerChoice, int computerChoice);
void displayWinner(string winner);
void updateScores(string winner, int scores[]);
void displayScores(int scores[]);

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

        if (choice < 1 || choice > 4)
            cout << "*ERROR* Invalid choice. Try again.\n\n";
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