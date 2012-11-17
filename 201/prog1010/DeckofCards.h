/* 
 * File:   DeckofCards.h
 * Author: Paul
 *
 * Created on December 2, 2010, 1:00 PM
 */

#include <iostream>
#include "Card.h"
#include <vector>

using namespace std ;

#ifndef DECKOFCARDS_H
#define	DECKOFCARDS_H

class DeckofCards {

public :

    DeckofCards() ; //Default constructor
    void shuffle() ;

    Card dealCard() ; // Returns next card object from dext 
    bool moveCard() ; //Indicate if there are more cards to deal

    void printDeck() ; 

private :

    vector<Card> deck ;
    int currentCard ; //Next card to deal


};

#endif	/* DECKOFCARDS_H */

