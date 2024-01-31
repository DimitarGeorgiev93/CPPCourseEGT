#include "DeckOfCards.h"

DeckOfCards::DeckOfCards()
{
	for (int i = 1; i != Suit::last2; i++) {
		for (int j = 1; j != Type::last; j++) {
			deck.push_back(new PlayingCard((Type)j, (Suit)i));
		}
	}
}

void DeckOfCards::printDeck() const
{
	for (PlayingCard* card : deck) {
		card->showInfo();
	}
}

void DeckOfCards::raffleShuffle()
{
	std::vector<PlayingCard*> leftDeck;
	std::vector<PlayingCard*> rightDeck;
	for (int i = 0; i < deck.size(); i++) {
		if (i < 26) {
			leftDeck.push_back(deck.at(i));
		}
		else rightDeck.push_back(deck.at(i));
	}
	deck.clear();
	int leftCounter = 0;
	int rightCounter = 0;
	for (int i = 0; i < leftDeck.size() + rightDeck.size() ; i++) {
		if (i == 0 || i%2==0) {
			deck.push_back(leftDeck.at(leftCounter++));

		}
		else deck.push_back(rightDeck.at(rightCounter++));
	}
}

DeckOfCards::~DeckOfCards()
{
	for (PlayingCard* card : deck) {
		delete card;
	}
}

