//************************************************
// TITLE: Rock Paper Scissors                    *
// FILE NAME: Project1_DAngeloFrancis.cpp        *
// PROGRAMMER: D'Angelo Francis                  *
// DATE: February 10, 2025                       *
// REQUIREMENTS:Create a game of rock, paper,    *
// scissors vs the computer                      *
//************************************************

#include <iostream>
using namespace std;

//************************************************
// Definition of function gameRunning            *
// This function uses a boolean to determine     * 
// whether the game is running or not.           *
//************************************************

bool gameRunning();

int playerChoice();

int main() {
	gameRunning();
	while (bool gameRunning = true) {
		cout << "ROCK PAPER SCISSORS TOURNAMENT \n";
		cout << "******************************* \n\n";

		playerChoice();

		cout << "Player selected " << playerChoice << ".\n\n";
	}
}

bool gameRunning() {
	bool gameRunning = true;
	return gameRunning;
}

int playerChoice() {
	int playerChoice;

	do {
		cout << "MAKE YOUR SELECTION:\n\n";
		cout << "1. ROCK\n";
		cout << "2. PAPER\n";
		cout << "3. SCISSORS\n";
		cout << "4. QUIT\n\n";
		
		cout << "(Enter a number 1-4 to make your choice): ";
		cin >> playerChoice;

		if (playerChoice < 1 || playerChoice > 4)
			cout << "*ERROR* Invalid choice. Try again.\n\n";
	} while (playerChoice < 1 || playerChoice > 4);

	return playerChoice;
}