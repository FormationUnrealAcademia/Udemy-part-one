#pragma once
#include <string>

using FString = std::string;
using int32 = int;

// All values initilised to zero
struct BullCowcount {
	int32 Bulls = 0;
	int32 Cows = 0;
};


class FBullCowGame{
public:
	FBullCowGame(); //constructor

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset(); //TODO make a more rich return value
	bool CheckGuessValidity(FString); //TODO make a more rich return value.
	BullCowcount SubmitGuess(FString);

private:
	//see constructor for initilisation 
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
};