/* 
 * File:   prog915.cpp
 * Author: Paul
 *
 * Created on November 20, 2010, 2:46 PM
 */

#include <iostream>
#include "TicTacToe_pvp.h"
#include <cstdlib>

using namespace std;


int error_check( int x, int y, TicTacToe board1 ) ;

int error_check( int x, int y, TicTacToe board1 ) {
    
    int err = 0 ;
    
    err = board1.checkBoundry( x, y ) ;

    //Check to see if move is off the board
    if( err == 2 ) {
        cout << "ERROR : The X coordinate you specified is out of the board." << endl ;
        return 1 ;
    }
    if( err == 3 ) {
            cout << "ERROR : The Y coordinate you specified is out of the board." << endl ;
            return 2 ;
        }

    //Check to see if there is a move already there
    else {
        err = board1.checkSpace( x, y ) ; //Check to see if a move is already there
        if( err == 1 ) {
            cout << "ERROR : There is already a move there." ;
            return 3 ;
        }
    }
    
    return 0 ; 
    
}

int main() {

    int x, y, player = 1, win = 0, fir ;
    char first ;
    TicTacToe board1 ;

    //This is mostly for debug
    cout << "This is the board before any moves:" <<endl ;
    board1.printBoard() ;

    //Determine who will go first
    while( 1 ) {

        cout << "Please select who will go first, X's or O's. For example type X to have X's go first." << endl ;
        cin >> first ;

        // debug stuff: cout << "The value in first is" << first ;

        if( ( first == 88 ) || ( first == 120 ) ) {
            player = 1 ;
            fir = 1 ;
            break ;
        }
        if( ( first == 79 ) || ( first == 111 ) ) {
            player = 2 ;
            fir = 2 ;
            break ;
        }
        
        else cout << "ERROR : Please enter either X or O." << endl ;

    }


    while( 1 ) {
 
        while( 1 ) {
            cout << "It is Player " << player << "'s ( " ;
            if( player == 1 ) cout << "X" ;
            else cout << "O" ;
            cout << "'s ) move." << endl ;

            cout << "Make a move, enter the x,y coordinate of your move ( example 2,2 would be the middle space ). Type -1 to exit." << endl ;

            //if you type a letter here it breaks
            cin >> x ;
            if( x == -1 ) exit( 0 );
            cin.ignore( 1 ) ;
            cin >> y ;

            if( error_check( x, y, board1 ) == 0 ) break ;

            //cout << "The value of temp is" << temp ; //for debug purpuses
            //cout << x << "   " << y ; // more debug stuff
        }
            

        // cout << "Player is: " << player ; //debug stuff
        board1.makeMove( x, y, player ) ;

        cout << "This is the board after a move:" << endl ;
        board1.printBoard() ;

        //Check to see if there is a win
        win = board1.checkWin() ;

        //If there is a win print out who wins
        if( win == 1 ) {
            if( player == 1 ) {
                cout << "Player 1, X's WINS!" ;
                break ;
            }
            if( player == 2 ) {
                cout << "Player 2, O's WINS!" ;
                break ;
            }
        }

        //Check and see if there is a tie / draw.
        if ( board1.checkTie() == 1 ) {
            cout << "There are no available moves left, thus it is a tie / draw." << endl ; 
            break ;
        }

        //Switch players
        if( player == 1 ) player = 2 ;
        else player = 1 ;

    }
    
    return 0 ;

}

