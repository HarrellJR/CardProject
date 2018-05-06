#pragma once
#include "Card.h"
#include <vector>
class DiscardPile
{
private:
	std::vector <Card> vtrDiscardPile;

public:
	DiscardPile();
	~DiscardPile();
	void clear();
	Card getTopCard();
	void addCard(Card cardDiscarded);
	bool checkValidCard(Card cardIsValid);
};

