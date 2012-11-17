/* 
 * File:   prog1010.cpp
 * Author: Paul
 *
 * Created on December 2, 2010, 12:59 PM
 */

#include <iostream>
#include "Card.h"
#include "DeckofCards.h"

using namespace std;


int main() {

    Card card1( 12, 3 ) ; //This is a card, King of Clubs
    Card card2( 3, 2 ) ; //This is the 3 of Diamonds
    DeckofCards deck1 ;

    //cout << card1.toString() << endl ;
    //cout << card2.toString() << endl ;

    //cout << "The deck befor shuffling:" << endl ;
    //deck1.printDeck() ;

    //deck1.shuffle() ;
/*
    cout << endl ;
    cout << "The deck after shuffling: " << endl ;
    deck1.printDeck() ;

    cout << endl ;
    cout << "The next four cards are: " << endl ;

    cout << deck1.dealCard().toString() << endl ;
    cout << deck1.dealCard().toString() << endl ;
    cout << deck1.dealCard().toString() << endl ;
    cout << deck1.dealCard().toString() << endl ;
*/

    cout << "Keep printing out cards untill the end is reached " << endl;

    while( 1 ) {
        if( deck1.moveCard() == true ) cout << deck1.dealCard().toString() << endl ;
        else break ;
    }
    
    return 0;
}

