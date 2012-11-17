/* 
 * File:   Card.h
 * Author: Paul
 *
 * Created on December 2, 2010, 1:00 PM
 */

#include <iostream>
#include <string>
using namespace std ;

#ifndef CARD_H
#define	CARD_H

class Card {

public :

    Card( int = 0, int = 0 ) ; //Default constructor

    int getFace() ;
    int getSuit() ;

    void setFace( int ) ;
    void setSuit( int ) ;

    string toString() ;

    static const string faces[ 13 ] ;
    static const string suits[ 4 ] ;

private :

    int face ;
    int suit ;

};


#endif	/* CARD_H */

