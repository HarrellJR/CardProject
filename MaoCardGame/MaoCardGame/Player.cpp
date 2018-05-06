#include "stdafx.h"
#include "Player.h"



Player::Player()
{
	static int intPlayerNumber = 0;
	intPlayerNumber++;
	this->intPlayerNumber = intPlayerNumber;

	this->clearHand();
	this->setBet(1);
	this->setMoney(1000);
}


Player::~Player()
{
	this->clearHand();
	this->intBet = 0;
}

void Player::clearHand()
{
	this->vtrHand.clear();
}


int Player::getNumberOfCards()
{
	return this->vtrHand.size();
}


Card Player::removeCardFromHand(int intCardIndex)
{
	Card cardReturn = this->vtrHand.at(intCardIndex);
	this->vtrHand.erase(this->vtrHand.begin() + intCardIndex);
	return cardReturn;
}


void Player::addCardToHand(Card cardAdding)
{
	this->vtrHand.push_back(cardAdding);
}


int Player::getBet()
{
	return this->intBet;
}


void Player::inputBet()
{
	int intBet = 0;
	do {
		std::cout << "Please enter your bet (1 - " << this->getMoney() << "): " << std::endl;
	} while (intBet <= 0 || intBet > this->getMoney());
	this->setBet(intBet);
}


void Player::setBet(int intBet)
{
	if (intBet <= 0) { //Min $1 bet
		intBet = 1;
	}
	if (intBet > this->getMoney()) { //Max bet
		intBet = this->getMoney();
	}
	this->intBet = intBet;
}


void Player::printHand()
{
	std::cout << "Player " << this->intPlayerNumber << ": # Cards "
		<< this->getNumberOfCards() << ", Money $"
		<< this->getMoney() << ", Bet $"
		<< this->getBet() << std::endl;
	for (unsigned int intIndex = 0; intIndex < this->vtrHand.size(); intIndex++) {
		std::cout << intIndex + 1 << ") " << this->vtrHand.at(intIndex).toString() << std::endl;
	}
}


void Player::wonBet()
{
	this->setMoney(this->getMoney() + this->getBet());
	//this->setBet(1);
}


void Player::lostBet()
{
	this->setMoney(this->getMoney() - this->getBet());
	//this->setBet(1);
}


void Player::setMoney(int intMoney)
{
	if (intMoney < 0)
	{
		intMoney = 2000;
	}
	this->intMoney = intMoney;
}


int Player::getMoney()
{
	return this->intMoney;
}