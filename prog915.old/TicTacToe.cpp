//TicTacToe.
//Contains definitions for headers in TicTacToe.h

#include "TicTacToe.h"
#include <iostream>

using namespace std ; 

TicTacToe::TicTacToe( int def ) {

    int i, j ;
    for( i = 0 ; i < 3 ; i++ ) {
        for( j = 0 ; j < 3 ; j++ ) {
            board[ i ][ j ] = def ; 
        }
    }
}

void TicTacToe::makeMove( int x, int y, int player ) {

    x--;
    y--;

    if( player == 1 ) board[ x ][ y ] = 1 ;
    if( player == 2 ) board[ x ][ y ] = 2 ;
    
    return ;

}

void TicTacToe::printBoard() {

    int i, j ;
    for( i = 0 ; i < 3 ; i++ ) {
        cout << endl ;
        for( j = 0 ; j < 3 ; j++ ) {
            if( board[ i ][ j ] == 1 ) cout << "X" ;
            if( board[ i ][ j ] == 2 ) cout << "O" ;
            if( board[ i ][ j ] == 0 ) cout << "-" ;
        }
    }
    cout << endl ;
    return ;
}

int TicTacToe::checkWin() {

    int win = 0 ;

    //Check for wins by X

    //Check for wins by row - vertically
    if( ( board[ 0 ][ 0 ] == 1 && + board[ 0 ][ 1 ] == 1 && + board[ 0 ][ 2 ] == 1 ) ) win = 1 ;
    if( ( board[ 1 ][ 0 ] == 1 && + board[ 1 ][ 1 ] == 1 && + board[ 1 ][ 2 ] == 1 ) ) win = 1 ;
    if( ( board[ 2 ][ 0 ] == 1 && + board[ 2 ][ 1 ] == 1 && + board[ 2 ][ 2 ] == 1 ) ) win = 1 ;

    //Check for wins by row - horizantally
    if( ( board[ 0 ][ 0 ] == 1 && board[ 1 ][ 0 ] == 1 && board[ 2 ][ 0 ] == 1 ) ) win = 1 ;
    if( ( board[ 0 ][ 1 ] == 1 && board[ 1 ][ 1 ] == 1 && board[ 2 ][ 1 ] == 1 ) ) win = 1 ;
    if( ( board[ 0 ][ 2 ] == 1 && board[ 1 ][ 2 ] == 1 && board[ 2 ][ 2 ] == 1 ) ) win = 1 ;

    //Check for diaganol wins
    if( ( board[ 0 ][ 0 ] == 1 && board[ 1 ][ 1 ] == 1 && board[ 2 ][ 2 ] == 1 ) ) win = 1 ;
    if( ( board[ 2 ][ 0 ] == 1 && board[ 1 ][ 1 ] == 1 && board[ 0 ][ 2 ] == 1 ) ) win = 1 ;

    //Check for wins by O

    //Check for wins by row - vertically
    if( ( board[ 0 ][ 0 ] == 2 && + board[ 0 ][ 1 ] == 2 && + board[ 0 ][ 2 ] == 2 ) ) win = 1 ;
    if( ( board[ 1 ][ 0 ] == 2 && + board[ 1 ][ 1 ] == 2 && + board[ 1 ][ 2 ] == 2 ) ) win = 1 ;
    if( ( board[ 2 ][ 0 ] == 2 && + board[ 2 ][ 1 ] == 2 && + board[ 2 ][ 2 ] == 2 ) ) win = 1 ;

    //Check for wins by row - horizantally
    if( ( board[ 0 ][ 0 ] == 2 && board[ 1 ][ 0 ] == 2 && board[ 2 ][ 0 ] == 2 ) ) win = 1 ;
    if( ( board[ 0 ][ 1 ] == 2 && board[ 1 ][ 1 ] == 2 && board[ 2 ][ 1 ] == 2 ) ) win = 1 ;
    if( ( board[ 0 ][ 2 ] == 2 && board[ 1 ][ 2 ] == 2 && board[ 2 ][ 2 ] == 2 ) ) win = 1 ;

    //Check for diaganol wins
    if( ( board[ 0 ][ 0 ] == 2 && board[ 1 ][ 1 ] == 2 && board[ 2 ][ 2 ] == 2 ) ) win = 1 ;
    if( ( board[ 2 ][ 0 ] == 2 && board[ 1 ][ 1 ] == 2 && board[ 0 ][ 2 ] == 2 ) ) win = 1 ;

    return win ;
}

int TicTacToe::checkSpace( int x, int y ) {

    x-- ;
    y-- ;

    if( ( board[ x ][ y ] == 1 ) || ( board[ x ][ y ] == 2 )  ) return 1 ;
    return 0 ;

}

int TicTacToe::checkBoundry( int x, int y ) {

    x-- ;
    y-- ;

    if( x > 2 ) return 2 ;
    if( y > 2 ) return 3 ;
    
    else return 0 ;

}

void TicTacToe::copyBoard( TicTacToe board1 ) {

    //TicTacToe board2 ;
    int i, j ;

    for( i = 0 ; i < 3 ; i++ ) {
        for( j = 0 ; j < 3 ; j++ ) {
            board[ i ][ j ] = board1.board[ i ][ j ] ;
        }

    }

    return ;

}

void TicTacToe::removeMove( int x, int y ) {
    
    board[ x ][ y ] = 0 ;
    return ;

}

int TicTacToe::checkTie() {

 int i, j, count = 0 ;

 for( i = 0 ; i < 3 ; i++ ) {
     for( j = 0 ; j < 3 ; j++ ) {
         if( board[ i ][ j ] == 0 ) count++ ;
     }
 }
 
 if( count == 0 ) return 1 ;

 else return 0 ;

}