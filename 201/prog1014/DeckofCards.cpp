//Contains definitions for headers in DeckofCards.h

#include "Card.h"
#include "DeckofCards.h"
#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>

DeckofCards::DeckofCards() {

    int i, j ;

    for( i = 0 ; i < 4 ; i++ ) {
        for( j = 0 ; j < 13 ; j++ ) {
            deck.push_back( Card( j, i ) ) ;
        }
    }
    
    currentCard = -1 ;

}

void DeckofCards::printDeck() {

    int i ;
    
    for( i = 0 ; i < 52 ; i++ ) {
        cout << deck[ i ].toString() << endl ;
    }

    return ; 

}

void DeckofCards::shuffle() {

    int num1, num2, counter = 0 ;
    Card take, place ;
    currentCard = -1 ;

    srand( time( NULL ) ) ;

    while( counter != 100 ) {

        num1 = rand() % 52 ;

        take = deck[ num1 ] ;

        num2 = rand() % 52 ;
        place = deck[ num2 ] ;

        deck[ num1 ] = place ;
        deck[ num2 ] = take ;
        counter++ ; 
    
    }

    return ;

}

Card DeckofCards::dealCard() {

    currentCard++ ;
    return  deck[ currentCard ] ;

}

bool DeckofCards::moveCard() {

    bool val = false ;

    if( currentCard < 51 ) val = true ;
    
    return val ;

}