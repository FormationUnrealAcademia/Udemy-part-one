#include <iostream>
#include <string>
#include "FBullCowGame.h"

void PrintIntro();
void PlayGame();
std::string GetGuess();
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
	constexpr int WORLD_LENGTH = 5;
	std::cout << "Welcome to Bulls and Cows!" << std::endl;
	std::cout << "Can you guess the " << WORLD_LENGTH;
	std::cout << " letters isogram I'm thinking of?\n" << std::endl;
	return;
}

void PlayGame()
{
	BCgame.Reset();
	int MaxTries = BCgame.GetMaxTries();
	//std::cout << MaxTries << std::endl;

	//loop for the number of turns asking for guesses
	constexpr int NUMBER_OF_TURN = 5;
	for (int i = 1; i <= MaxTries; i++) {
		std::string guess = GetGuess();
		//print the guess back to them
		std::cout << "You enter : " << guess << std::endl;
		std::cout << std::endl;
	}
}

std::string GetGuess() {

	int CurrnetTries = BCgame.GetCurrentTry();

	//Get a guess from the player
	std::cout << "Try : "  << CurrnetTries << " \nEnter your guess : ";
	std::string guess = "";
	std::getline(std::cin, guess);
	return guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? (y/n)";
	std::string Reponse = "";
	std::getline(std::cin, Reponse);
	return (Reponse[0] == 'y') || (Reponse[0] == 'Y');
}

