#pragma once
#include <string>

using FString = std::string;
using int32 = int;

// All values initilised to zero
struct FBullCowcount {
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus 
{
	Invalid_Status,
	OK,
	Not_Isogram,
	Wromg_lenght,
	Not_LowerCase
};



class FBullCowGame{
public:
	FBullCowGame(); //constructor

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;

	bool IsGameWon() const;
	EGuessStatus CheckGuessValidity(FString) const; 

	void Reset(); //TODO make a more rich return value
	FBullCowcount SubmitValidGuess(FString);

private:
	//see constructor for initilisation 
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
	bool bGameIsWon;
};