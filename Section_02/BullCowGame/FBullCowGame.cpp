#include "FBullCowGame.h"

using int32 = int;


void FBullCowGame::Reset() 
{
	constexpr int MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;
	
	const FString HIDDEN_WORD = "ets";
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	return;
}

FBullCowGame::FBullCowGame(){ Reset(); }

int32 FBullCowGame::GetMaxTries() const {return MyMaxTries;}

int32 FBullCowGame::GetCurrentTry() const {return MyCurrentTry;}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(FString) 
{
	return false;
}

FBullCowcount FBullCowGame::SubmitGuess(FString Guess)
{
	//Increment the turn number
	MyCurrentTry++;

	//setup a return variable
	FBullCowcount Bullcowcount;

	// loop through all letters in the guess
	int32 HiddenWordLenght = MyHiddenWord.length();
	for (int32 i = 0; i < HiddenWordLenght; i++) {
		// compare letters against the hidden word
		for (int32 j = 0; j < HiddenWordLenght; j++) {
			// If they match then
			if (Guess[i] == MyHiddenWord[i]) {
			//if they're in the same place
				if (i == j) {
					Bullcowcount.Bulls++; // Incriment bulls 
				}else{
					Bullcowcount.Cows++; // must be a cow
				}
			}
		}
	}
	return Bullcowcount;
}


