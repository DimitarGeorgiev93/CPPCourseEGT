
#include <iostream>
#include "DeckOfCards.h"

int main()
{

    DeckOfCards deck;
    deck.printDeck();
    std::cout << "----------------\n";
    deck.raffleShuffle();
    deck.raffleShuffle();
    deck.raffleShuffle();
    deck.raffleShuffle();
    deck.raffleShuffle();
    deck.raffleShuffle();
    deck.raffleShuffle();
    deck.raffleShuffle();
    deck.raffleShuffle();
    deck.raffleShuffle();
    deck.printDeck();
    
}

