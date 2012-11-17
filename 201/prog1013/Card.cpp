//Define headers from card.h 

#include "Card.h"
using namespace std ;

const string Card::faces[ 13 ] = { "Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" } ;
const string Card::suits[ 4 ] = { "Hearts", "Spades", "Diamonds", "Clubs" } ;

Card::Card( int fac, int sui, int win ) {

    face = fac ;
    suit = sui ;
    win_card = win ; 

}

int Card::getFace() {

    return face ;

}

int Card::getSuit() {

    return suit ;

}

void Card::setFace( int fac ) {

    face = fac ;

}

void Card::setSuit( int sui ) {

    suit = sui ;
    
}

string Card::toString() {

    return( faces[ face ] + " of " + suits[ suit ] ) ;

}

int Card::getWincard() {

    return win_card ;

}

void Card::setWincard( int val ) {

    win_card = val ;
    return ; 

}