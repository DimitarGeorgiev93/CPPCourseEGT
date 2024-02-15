#pragma once
#include <iostream>
enum Type { ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, last};
enum Suit {SPADES = 1,HEARTS,DIAMONDS,CLUBS, last2};

class PlayingCard
{
public:
	PlayingCard(Type, Suit);
	void showInfo() const;
private:
	void showInfoSuitHelper() const;
	void showInfoTypeHelper() const;
	Suit suit;
	Type type;
};

