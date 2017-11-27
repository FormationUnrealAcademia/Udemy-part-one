#include "FBullCowGame.h"
#include <map>
#define TMap std::map

using int32 = int;


void FBullCowGame::Reset() 
{
	constexpr int MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;
	
	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	bGameIsWon = false;
	return;
}


FBullCowGame::FBullCowGame(){ Reset(); }

int32 FBullCowGame::GetMaxTries() const {return MyMaxTries;}

int32 FBullCowGame::GetCurrentTry() const {return MyCurrentTry;}

int32 FBullCowGame::GetHiddenWordLength() const {return MyHiddenWord.length();}

bool FBullCowGame::IsGameWon() const { return bGameIsWon; }


EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (!IsIsogram(Guess)) // if the guest isn't an isogram
	{ 
		return EGuessStatus::Not_Isogram;
	} 
	else if (false) // if the guess isn't all lowercase 
	{
		return EGuessStatus::Not_LowerCase; // TODO write function
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

// recives a VALID guess, increments turn, and return count
FBullCowcount FBullCowGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowcount Bullcowcount;

	// loop through all letters in the hiiden word
	int32 wordLenght = MyHiddenWord.length(); //assuming same lenght as guess
	for (int32 MHWChar = 0; MHWChar < wordLenght; MHWChar++) 
	{
		// compare letters against the guess
		for (int32 GChar = 0; GChar < wordLenght; GChar++) 
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
	if (Bullcowcount.Bulls == wordLenght) 
	{
		bGameIsWon = true;
	}
	else 
	{
		bGameIsWon = false;
	}
	return Bullcowcount;
}

bool FBullCowGame::IsIsogram(FString Word) const
{
	// treat 0 and 1 letter words as isograms
	if (Word.length() <= 1) { return true; }

	// setup our map
	TMap<char, bool> LetterSeen;
	
	for (auto Letter : Word) // for all letters of the word
	{
		Letter = tolower(Letter); //handle mixed case
			// if the letter is in the map
		if (LetterSeen[Letter]) // if the letter is in map
		{
			return false; // we do NOT have an isogram
		}
		else 
		{
			// add the letter to the map as seen
			LetterSeen[Letter] = true;
		}
				
	}


	return true; // for example in cases where /0 is entered
}


