/*
Jeremy Harrell
ITSE 1301
Card project 
Making a program that does mao
Making a project that will be able to allow the player to partake in mao 
*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Card.h"
#include "Deck.h"
#include "DiscardPile.h"
#include "Player.h"
using namespace std;

//function for card
void testCard() {
	Card objCard(1);
	cout << "Card Testing" << endl;
	cout << objCard.getValue() << endl
		<< objCard.getFaceValue() << endl
		<< objCard.getFaceString() << endl
		<< objCard.getSuiteValue() << endl
		<< objCard.getSuiteString() << endl
		<< objCard.toString() << endl;
	objCard.setValue(45);
}

//Test for decks
void testDeck() {
	Deck objDeck = Deck();
	cout << "Deck Testing" << endl;
	objDeck.printDeck();
	//Get cards until we reach the shuffle point you can also get cards until you reach NULL
	do {
		objDeck.getCard();
		cout << "Percentage: " << objDeck.getPercentOfDeckDealt() << endl;
	} while (!objDeck.shouldShuffle());
	if (objDeck.shouldShuffle()) {
		objDeck.shuffle();
	}
	objDeck.printDeck();
}

//Function for Discard Pile
void testDiscardPile() {
	Deck objDeck = Deck(4);
	objDeck.shuffle();
	DiscardPile objDiscard = DiscardPile();
	Card objCardToDiscard = objDeck.getCard();
	cout << objCardToDiscard.toString() << endl;
	objDiscard.addCard(objCardToDiscard);
	cout << objDiscard.getTopCard().toString() << endl;
}

//Function for Player 
void testPlayer() {
	Player objPlayerOne = Player();
	Player objPlayerTwo = Player();
	Deck objDeck = Deck(4);
	DiscardPile objDiscard = DiscardPile();
	objDeck.shuffle();
	objPlayerOne.setBet(5);
	objPlayerTwo.setMoney(300);
	objPlayerTwo.setBet(400);
	for (int intCards = 0; intCards < 7; intCards++) {
		objPlayerOne.addCardToHand(objDeck.getCard());
		objPlayerTwo.addCardToHand(objDeck.getCard());
	}
	objPlayerOne.printHand();
	objPlayerOne.clearHand();
	objPlayerOne.printHand();
	cout << "-----" << endl;
	objPlayerTwo.printHand();
	//HINT: Logic for checking if player card can be added to discard.
	Card cardPlayerDiscard = objPlayerTwo.removeCardFromHand(0); //Remove card 1 NOTE: it's the index, index starts at zero
	if (objDiscard.checkValidCard(cardPlayerDiscard)) { //Check if it can be added to discard
		objDiscard.addCard(cardPlayerDiscard); //Add to discard
	}
	else { //Nope
		objPlayerTwo.addCardToHand(cardPlayerDiscard); //Add back to players hand.
	}
	objPlayerTwo.printHand();
	cout << "-----" << endl;
	objPlayerOne.wonBet();
	objPlayerOne.printHand();
	objPlayerTwo.lostBet();
	objPlayerTwo.printHand();
}


int main()
{
	srand(time(0)); //Setup the randomness at the beginning of the program
	const int INTNUMBEROFDECKS = 3;
	const int INTPLAYERHANDSIZE = 7;
	const int INTMAXPLAYERS = 6;
	int intNumberOfPlayers = 2;

	cout << "Thanks for playing" << endl;

	return 0;
}
