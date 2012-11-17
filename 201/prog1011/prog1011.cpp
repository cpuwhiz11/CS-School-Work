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

void bubblesort(int *array, int length ) {
  //This is based on a bubblesort found online @ http://codecodex.com/wiki/Bubble_sort
  int i, j, temp ;
  int test ;

  for( i = ( length - 1 ) ; i > 0 ; i-- ) {
    test = 0 ;
    for( j = 0 ; j < i ; j++ ) {
      if( array[ j ] > array[ j + 1 ] ) {

        temp = array[ j ] ;
        array[ j ] = array[ j + 1 ] ;
        array[ j + 1 ] = temp;
        test = 1;

      }
    }

    if( test == 0 ) break ;

  } 

  return ;

}



int checkWin( Card cards[ 5 ] ) {
    
    int i, j, checker = 0, win = 0, val ;
    int faces[ 5 ] ;

    for( i = 0 ; i < 5 ; i++ ) {
        for( j = 0 ; j < 5 ; j++ ) {
            if( i != j ) if( cards[ i ].getFace() == cards[ j ].getFace() ) checker++ ;
        }
    }
    
    
    if( checker == 2 ) win = 1 ; //Found a pair
    if( checker == 4 ) win = 2 ; //Found two pair
    if( checker == 6 ) win = 3 ; //Found three of a kind
    if( checker == 12 ) win = 7 ; //Found four of a kind
    if( checker == 8 ) win = 6 ;// Found a pair and three of a kind

    //reset checker
    checker = 0 ;

    //check for flush 
    for( i = 0 ; i < 5 ; i++ ) {
        for( j = 0 ; j < 5 ; j++ ) {
            if( i != j ) if( cards[ i ].getSuit() == cards[ j ].getSuit() ) checker++ ;
        }
    }
    //cout << "checker is " << checker ;
    if( checker == 20 ) if( win != 7 || win != 6 ) win = 4 ; // Found a straight

    //Check for straigt, Get all the face values
    for( i = 0 ; i < 5 ; i++ ) faces[ i ] = cards[ i ].getFace() ;

    //Sort the values in faces
    bubblesort( faces, 5 ) ;

    for( i = 0 ; i < 5 ; i++ ) {
        val = faces[ i ] ;
        for( j = 0 ; j < 5 ; j++ ) {
            if( i != j ) if( faces[ i ] == ( 1 - faces[ j ] ) ) checker++ ;
        }
    }
    
    //cout << "checker is " << checker ;
    if( checker == 20 ) if( win != 7 || win != 6 ) win = 5 ; // Found a flush ;

    return win ; 
    
}

int main() {

    DeckofCards deck1 ;
    Card hand1[ 5 ] ;
    int counter = 0, win ;

    deck1.shuffle() ;

    //Set the hand to test wins
/*
    hand1[ 0 ].setFace( 3 ) ;
    hand1[ 0 ].setSuit( 1 ) ;

    hand1[ 1 ].setFace( 2 ) ;
    hand1[ 1 ].setSuit( 1 ) ;

    hand1[ 2 ].setFace( 3 ) ;
    hand1[ 2 ].setSuit( 1 ) ;

    hand1[ 3 ].setFace( 4 ) ;
    hand1[ 3 ].setSuit( 1 ) ;

    hand1[ 4 ].setFace( 5 ) ;
    hand1[ 4 ].setSuit( 1 ) ;
*/

    cout << "Hand 1 : " << endl ;
    while( counter != 5 ) {
        hand1[ counter ] = deck1.dealCard() ;
        cout << hand1[ counter ].toString() << endl ;
        counter++ ;
    }

    //The type of win 
    
    win = checkWin( hand1 ) ;
    if( win != 0 ) {

        cout << "The type of win is : " << endl ;

        if( win == 1 ) cout << " A Pair " << endl ;
        if( win == 2 ) cout << " Two Pair " << endl ;
        if( win == 3 ) cout << " Three of a Kind" << endl ;
        if( win == 4 ) cout << " A Straight " << endl ;
        if( win == 5 ) cout << " A Flush " << endl ;
        if( win == 6 ) cout << " Four of a Kind " << endl ;
        if( win == 7 ) cout << " Full House " << endl ;

    }

    else cout << "No win" << endl ;
    
    return 0 ;   
    
}

