/*This the console executable, that makes use of the bullcow class.
This axts as the view in the MVC pattern, and is responsible for all 
user interaction. For game logic, see the FBullCowGame class.
*/

#include <iostream>
#include <string>
#include "FBullCowGame.h"

using Ftext = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
Ftext GetGuess();
bool AskToPlayAgain();
FBullCowGame BCgame; //instantiate a new game

//the entry point for our application
int main(){
	std::cout << BCgame.GetCurrentTry();
	bool bPlayAgain = false;

	do {
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} while (bPlayAgain);
	
	return 0; //exit the app
}

void PrintIntro() {
	//introduce the game
	constexpr int32 WORD_LENGTH = 5;
	std::cout << "Welcome to Bulls and Cows!" << std::endl;
	std::cout << "Can you guess the " << WORD_LENGTH;
	std::cout << " letters isogram I'm thinking of?\n" << std::endl;
	return;
}

void PlayGame()
{
	BCgame.Reset();
	int32 MaxTries = BCgame.GetMaxTries();
	//std::cout << MaxTries << std::endl;

	//loop for the number of turns asking for guesses
	constexpr int32 NUMBER_OF_TURN = 5;
	//TODO Change from FOR to WHILE loop one we are validating tries
	for (int32 i = 1; i <= MaxTries; i++) {
		Ftext guess = GetGuess(); //TODO make loop checking valid

		//Submit values guess to the game
		//Print numbers of bull and cows

		//print the guess back to them
		std::cout << "You enter : " << guess << std::endl;
		std::cout << std::endl;
	}
	//TODO summerise game
}

Ftext GetGuess() {

	int32 CurrnetTries = BCgame.GetCurrentTry();

	//Get a guess from the player
	std::cout << "Try : "  << CurrnetTries << " \nEnter your guess : ";
	Ftext guess = "";
	std::getline(std::cin, guess);
	return guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? (y/n)";
	Ftext Reponse = "";
	std::getline(std::cin, Reponse);
	return (Reponse[0] == 'y') || (Reponse[0] == 'Y');
}

