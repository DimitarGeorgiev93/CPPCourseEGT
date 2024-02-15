#pragma once

#include "PlayingCard.h"
#include <vector>
class DeckOfCards
{
public:
	DeckOfCards();
	void printDeck() const;;
	void raffleShuffle();
	~DeckOfCards();
private:
	std::vector<PlayingCard*> deck;
};

