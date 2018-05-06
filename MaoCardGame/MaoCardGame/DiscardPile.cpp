#include "stdafx.h"
#include "DiscardPile.h"


DiscardPile::DiscardPile()
{
	this->clear();
}


DiscardPile::~DiscardPile()
{
	this->vtrDiscardPile.clear();
}


void DiscardPile::clear()
{
	this->vtrDiscardPile.clear();
}


Card DiscardPile::getTopCard()
{
	if (this->vtrDiscardPile.size() <= 0)
	{
		return NULL;
	}
	Card cardTop = this->vtrDiscardPile.back();
	return cardTop;
}


void DiscardPile::addCard(Card cardDiscarded)
{
	if (this->checkValidCard(cardDiscarded)) {
		this->vtrDiscardPile.push_back(cardDiscarded);
	}
}


bool DiscardPile::checkValidCard(Card cardIsValid)
{
	if (this->vtrDiscardPile.size() <= 0) {
		return false;
	}
	bool boolFace = this->getTopCard().getFaceValue() == cardIsValid.getFaceValue();
	bool boolSuite = this->getTopCard().getSuiteValue() == cardIsValid.getSuiteValue();
	return (boolFace || boolSuite);
}