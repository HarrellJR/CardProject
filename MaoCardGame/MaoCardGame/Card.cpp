#include "stdafx.h"
#include "Card.h"


Card::Card()
{
	srand(time(NULL));
	this->setValue(rand() % 52 + 1);
}

Card::Card(int intCard)
{
	this->setValue(intCard);
}


Card::~Card()
{
	this->intCardValue = 0;
}


int Card::getFaceValue()
{
	return 1 + ((this->getValue() - 1) % 13);;
}


int Card::getSuiteValue()
{
	return (this->getValue() - 1) / 13;
}


std::string Card::getFaceString()
{
	//Function to get the face as a string of a card
	std::string strFace = "";
	switch (this->getFaceValue()) {
	case 1:
		strFace = "Ace";
		break;
	case 11:
		strFace = "Jack";
		break;
	case 12:
		strFace = "Queen";
		break;
	case 13:
		strFace = "King";
		break;
	default:
		strFace += std::to_string(this->getFaceValue());
	}
	return strFace;
}

std::string Card::getSuiteString()
{
	std::string strSuite = "";
	switch (this->getSuiteValue()) {
	case CLUBS:
		strSuite = "Clubs";
		break;
	case DIAMONDS:
		strSuite = "Diamonds";
		break;
	case HEARTS:
		strSuite = "Hearts";
		break;
	default:
		strSuite = "Spades";
		break;
	}
	return strSuite;
}


int Card::getValue()
{
	return this->intCardValue;
}


int Card::setValue(int intCard)
{
	if (intCard < 1) {
		this->intCardValue = 1;
	}
	else if (intCard > 52) {
		this->intCardValue = 52;
	}
	else {
		this->intCardValue = intCard;
	}
	return this->intCardValue;
}


std::string Card::toString()
{
	return this->getFaceString() + " of " + this->getSuiteString();
}