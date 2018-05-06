#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include "Card.h"

class Deck
{
public:
	Deck();
	~Deck();
private:
	unsigned int intCurrentIndex;
	std::vector<Card> vtrDeck;
public:
	void shuffle();
	bool shouldShuffle();
	Card getCard();
	Deck(int intNumberOfDecks);
private:
	void initalizeDeck(int intNumberOfDecks);
public:
	void printDeck();
	int getPercentOfDeckDealt();
};