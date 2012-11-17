/* 
 * File:   TicTacToe.h
 * Author: Paul
 *
 * Created on November 20, 2010, 2:46 PM
 */

#ifndef TICTACTOE_H
#define	TICTACTOE_H

class TicTacToe {

public :

    TicTacToe( int = 0 ) ; // Default Constructor ;

    void makeMove( int, int, int ) ;
    void printBoard() ;
    int checkSpace( int, int ) ; //See if a move is already in that space
    int checkBoundry( int, int ) ; //Make sure the move is inbounrs
    int checkWin() ; // Check to see if the move caused a win


private :

    int board[ 3 ][ 3 ] ;

};

#endif	/* TICTACTOE_H */

