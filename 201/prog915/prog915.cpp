/* 
 * File:   prog915.cpp
 * Author: Paul
 *
 * Created on November 20, 2010, 2:46 PM
 */

#include <iostream>
#include "TicTacToe.h"
#include <time.h>
#include <cstdlib>

using namespace std;

void comp_move_easy( int &x, int &y, TicTacToe board1 ) {

    int err ;

    srand( time( NULL ) ) ;
    while( 1 ) {
        x = 1 + ( rand() % 3 ) ;
        y = 1 + ( rand() % 3 ) ;
        err = board1.checkBoundry( x, y ) ;
        if( err == 0 ) break ; 
    }
    
    return ; 

}

int error_check( int x, int y, TicTacToe board1 ) {
    
    int err = 0 ;
    
    err = board1.checkBoundry( x, y ) ;
    
    if( err ==  2 ) {
        cout << "ERROR : The X coordinate you specified is out of the board." << endl ;
        return 1 ;
    }
    if( err == 3 ) {
        cout << "ERROR : The Y coordinate you specified is out of the board." << endl ;
        return 2 ;
    }
    
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

    int x, y, player = 1, win = 0, comp, user ;
    char first ;
    TicTacToe board1 ;

    //This is mostly for debug
    cout << "This is the board before any moves:" <<endl ;
    board1.printBoard() ;

    while( 1 ) {
        cout << "Do you want to play against the computer, if so enter 1. If not enter 2 and you will play against yourself." << endl ;
        cin >> comp ;
        if( comp == 1 ) break ; 
        if( comp == 2 ) {
            comp = 0 ;
            break ; 
        }
        else cout << "ERROR : Please enter either 1 or 2." << endl ;
    }

    //Determine who will go first
    while( 1 ) {

        cout << "Please select who will go first, X's or O's. For example type X to have X go first." << endl ;
        cin >> first ;

        // debug stuff: cout << "The value in first is" << first ;

        if( ( first == 88 ) || ( first== 120 ) ) {
            player = 1 ;
            break ;
        }
        if( ( first == 79 ) || ( first == 111 ) ) {
            player = 2 ;
            break ;
        }
        
        else cout << "ERROR : Please enter either X or O." << endl ;

    }

    if( comp == 1 ) {
        while( 1 ) {
            cout << "You have selected to play with the computer, do you want it to be Player 1 ( x )  or Player 2 ( O ) ? Please enter a 1 or 2. ;" << endl ;
            cin >> user ;
            if( ( user == 1 ) || ( user == 2 ) ) break ;
            else cout << "ERROR : Please enter 1 or 2." << endl ;
        }
    }

    while( 1 ) {
        
        //This happends if it is the human's move only
        if( ( comp == 0 ) || ( user == 2 ) ) {
            cout << "It is Player " << player << "'s ( " ;
            if( player == 1 ) cout << "X" ;
            else cout << "O" ;
            cout << "'s ) move." << endl ;

            cout << "Make a move, enter the x,y coordinate of your move ( example 2,2 would be the middle space). Type -1 to exit." << endl ;

            cin >> x ;
            if( x == -1 ) break ;
            cin.ignore( 1 ) ;
            cin >> y ;
        }

        if( ( comp == 1 ) && ( user == 1 ) ) comp_move_easy( x, y, board1 ) ;

        if( ( user == 1 ) || ( error_check( x, y, board1 )  == 0 ) ) {
            
            board1.makeMove( x, y, player ) ;

            cout << "This is the board after a move:" <<endl ;
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

            //Switch players
            if( player == 1 ) {
                player = 2 ;
                if( comp == 1 ) user++ ;
            }
            else {
                player = 1 ;
                user-- ;
            }

        }

    }
    
    return 0 ;

}

