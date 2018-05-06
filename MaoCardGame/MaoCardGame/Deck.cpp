#include "stdafx.h"
#include "Deck.h"


Deck::Deck()
{
	this->initalizeDeck(1);
}


Deck::~Deck()
{
	this->intCurrentIndex = 0;
	this->vtrDeck.clear();
}


void Deck::shuffle()
{
	this->intCurrentIndex = 0;
	std::random_shuffle(this->vtrDeck.begin(), this->vtrDeck.end());
}


bool Deck::shouldShuffle()
{
	const int intShufflePercent = 75;
	return (this->getPercentOfDeckDealt() > intShufflePercent);
}


Card Deck::getCard()
{
	if (this->intCurrentIndex >= this->vtrDeck.size() - 1) //Vector Starts at Zero
	{
		return NULL;
	}
	return this->vtrDeck.at(this->intCurrentIndex++);
}


Deck::Deck(int intNumberOfDecks)
{
	this->initalizeDeck(intNumberOfDecks);
}


void Deck::initalizeDeck(int intNumberOfDecks)
{
	this->intCurrentIndex = 0;
	this->vtrDeck.clear();
	for (int intDeck = 1; intDeck <= intNumberOfDecks; intDeck++) {
		for (int intCard = 1; intCard <= 52; intCard++) {
			this->vtrDeck.push_back(Card(intCard));
		}
	}
}


void Deck::printDeck()
{
	for (unsigned int intIndex = 0; intIndex < this->vtrDeck.size(); intIndex++) {
		std::cout << this->vtrDeck.at(intIndex).toString() << std::endl;
	}
}


int Deck::getPercentOfDeckDealt()
{
	return ((this->intCurrentIndex * 100) / this->vtrDeck.size());
}
