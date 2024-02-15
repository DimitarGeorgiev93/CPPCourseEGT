#include "PlayingCard.h"

PlayingCard::PlayingCard(Type type, Suit suit)
{
	this->type = type;
	this->suit = suit;
}

void PlayingCard::showInfo() const
{
	this->showInfoSuitHelper();
	std::cout << "of";
	this->showInfoTypeHelper();
}

void PlayingCard::showInfoSuitHelper() const
{
	switch (type) {
	case 1:
		std::cout << "Ace ";
		break;
	case 2:
		std::cout << "Two ";
		break;
	case 3:
		std::cout << "Three ";
		break;
	case 4:
		std::cout << "Four ";
		break;
	case 5:
		std::cout << "Five ";
		break;
	case 6:
		std::cout << "Six ";
		break;
	case 7:
		std::cout << "Seven ";
		break;
	case 8:
		std::cout << "Eight ";
		break;
	case 9:
		std::cout << "Nine ";
		break;
	case 10:
		std::cout << "Ten ";
		break;
	case 11:
		std::cout << "Jack ";
		break;
	case 12:
		std::cout << "Queen ";
		break;
	case 13:
		std::cout << "King ";
		break;
	}
}

void PlayingCard::showInfoTypeHelper() const
{
	switch (suit) {
	case 1:
		std::cout << " Spades\n";
		break;
	case 2:
		std::cout << " Hearts\n";
		break;
	case 3:
		std::cout << " Diamonds\n";
		break;
	case 4:
		std::cout << " Clubs\n";
		break;
	}
}
