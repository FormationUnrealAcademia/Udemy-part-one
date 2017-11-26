#include "FBullCowGame.h"

using int32 = int;


void FBullCowGame::Reset() 
{
	constexpr int MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;
	
	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	return;
}

FBullCowGame::FBullCowGame(){ Reset(); }

int32 FBullCowGame::GetMaxTries() const {return MyMaxTries;}

int32 FBullCowGame::GetCurrentTry() const {return MyCurrentTry;}

int32 FBullCowGame::GetHiddenWordLength() const {return MyHiddenWord.length();}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (false) // if the guest isn't an isogram
	{ 
		return EGuessStatus::Not_Isogram;
	} 
	else if (false) // if the guess isn't all lowercase
	{
		return EGuessStatus::Not_LowerCase;
	}
	else if (Guess.length() != GetHiddenWordLength()) // if the guess lenght is wrong
	{
		return EGuessStatus::Wromg_lenght;
	}
	else // otherwise
	{
		return EGuessStatus::OK;
	}
}

FBullCowcount FBullCowGame::SubmitGuess(FString Guess)
{
	//Increment the turn number
	MyCurrentTry++;

	//setup a return variable
	FBullCowcount Bullcowcount;

	// loop through all letters in the guess
	int32 HiddenWordLenght = MyHiddenWord.length();
	for (int32 MHWChar = 0; MHWChar < HiddenWordLenght; MHWChar++) 
	{
		// compare letters against the hidden word
		for (int32 GChar = 0; GChar < HiddenWordLenght; GChar++) 
		{
			// If they match then
			if (Guess[GChar] == MyHiddenWord[MHWChar]) 
			{
			//if they're in the same place
				if (MHWChar == GChar) 
				{
					Bullcowcount.Bulls++; // Incriment bulls 
				}
				else
				{
					Bullcowcount.Cows++; // must be a cow
				}
			}
		}
	}
	return Bullcowcount;
}


