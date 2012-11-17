/* 
 * File:   prog915.cpp
 * Author: Paul
 *
 * Created on November 20, 2010, 2:46 PM
 */

#include <iostream>
#include "TicTacToe_ai.h"
#include <time.h>
#include <cstdlib>

using namespace std;

void comp_move_easy( int &x, int &y, TicTacToe board1 ) ;
int error_check( int x, int y, TicTacToe board1, int msg ) ;

int rand_num() {
    //Generate a random number from 1 - 4
    int num ;

    srand( time( NULL ) ) ; //Seed rand()
    num = rand() % 4 ;

    return num ;

}

void comp_move_hard( int &x, int &y, const TicTacToe board1, int player ) {

    TicTacToe board2 ;
    int i, j, code = 0 ;

    board2.copyBoard( board1 ) ; // Copy a board to mess up

    //Check to see if the ai can make one move and win
    for( i = 1 ; i <= 3 ; i++ ) {
        for( j = 1 ; j <= 3 ; j++ ) {
            if( board2.checkSpace( i, j ) == 0 ) {
                if( player == 1 ) { //This is when the comp is player 1
                  board2.makeMove( i, j, player ) ;
                  if( ( board2.checkWin() ) == 1  ) { //This means the move results in a win so take that move
                      x = i ;
                      y = j ;
                      return ;
                  }
                  else board2.removeMove( i, j ) ; //This means that the move wasnt a win
                }
                if( player == 2 ) { //This is when the comp is player 2
                  board2.makeMove( i, j, player ) ;
                  if( ( board2.checkWin() ) == 1 ) { //This means the move results in a win so take that move
                      x = i ;
                      y = j ;
                      return ;
                  }
                  else board2.removeMove( i, j ) ; //This means that the move wasnt a win
                }
            }
        }
    } //End checking for one move wins.
    
    //Check to see if there is a space to block the other player from winning
    for( i = 1 ; i <= 3 ; i++ ) {
        for( j = 1 ; j <= 3 ; j++ ) {
            if( board2.checkSpace( i, j ) == 0 ) { //If there is no move there...
                if( player == 1 ) { //This is when the comp is player 1
                  board2.makeMove( i, j, 2 ) ; //Check to see if the move
                  if( ( board2.checkWin() ) == 1 ) { //This means the move results in a win for the other player, if so take that move to block
                      x = i ;
                      y = j ;
                      return ;
                  }
                  else board2.removeMove( i, j ) ; //This means that the move wasnt a win
                }
                if( player == 2 ) { //This is when the comp is player 2
                  board2.makeMove( i, j, 1 ) ;
                  if( ( board2.checkWin() ) == 1 ) { //This means the move results in a win so take that move
                      x = i ;
                      y = j ;
                      return ; 
                  }
                  else board2.removeMove( i, j  ) ; //This means that the move wasnt a win in one move
                }
            } // If there is a move there iterate the loops
        }
    } //End checking for block moves
    

    //So if there are no spots that win in one or block the ai will take the middle space if it is unoccupied
    //Check to see if there is a move already there
    //If there is no move there take the middle.
    if( board2.checkSpace( 2, 2 ) == 0 ) {
        x = y = 2 ;
        return ;
    }

    //If there is a move there check to see if corners are taken
    //Call a rand() function to randomly pick one of the 4 corners 
    while( 1 ) {

        code = rand_num() ;
        //Make a move in a random coner, if random corner is filled find a corner that is not starting from top left 
        if( ( code == 1 ) || ( code == 0 ) ) {

            if( board2.checkSpace( 1, 1 ) == 0 ) {
                x = y = 1 ;
                return ;
            }
        }

        if( ( code == 2 ) || ( code == 0 ) ) {
            if( board2.checkSpace( 1, 3 ) == 0 ) {
                x = 1 ;
                y = 3 ;
                return ;
            }
        }

        if( ( code == 3 ) || ( code == 0 ) ) {
            if( board2.checkSpace( 3, 1 ) == 0 ) {
                x = 3 ;
                y = 1 ;
                return ;
            }
        }

        if( ( code == 4 ) || ( code == 0 ) ) {
            if( board2.checkSpace( 3, 3 ) == 0 ) {
                x = y = 3 ;
                return ;
            }
        }
        code = 0 ; //If the randomly selected corner is filled then set code to 0 so that it can check the other 3
    }
    // End corner checking

    //If all else fails have the easy ai take over and make a random move ( in one of the 4 possible spaces left)
    comp_move_easy( y, x, board1 ) ;

    return ;

}


void comp_move_easy( int &x, int &y, const TicTacToe board1 ) {

    //Generate random move, and see if there is a move already there, if so take if not generate another
    srand( time( NULL ) ) ;
    while( 1 ) {
        x = 1 + ( rand() % 3 ) ;
        y = 1 + ( rand() % 3 ) ;
        if( error_check( x, y, board1, 0 ) == 0 ) break ;    
    }
    
    return ; 

}

int error_check( int x, int y, TicTacToe board1, int msg ) {
    
    int err = 0 ;
    
    err = board1.checkBoundry( x, y ) ;

    //Check to see if move is off the board
    if( err == 2 ) {
        if( msg == 1 ) cout << "ERROR : The X coordinate you specified is out of the board." << endl ;
        return 1 ;
    }
    if( err == 3 ) {
            if( msg == 1 ) cout << "ERROR : The Y coordinate you specified is out of the board." << endl ;
            return 2 ;
        }

    //Check to see if there is a move already there
    else {
        if( board1.checkSpace( x, y ) == 1 ) { //Check to see if a move is already there
            if( msg == 1 ) cout << "ERROR : There is already a move there." ;
            return 3 ;
        }
    }
    
    return 0 ; 
    
}

int main() {

    int x, y, player = 1, win = 0 ;
    int user, difi, comp_move = 0, fir ;
    char first ;
    TicTacToe board1 ;

    //This is mostly for debug
    cout << "This is the board before any moves:" <<endl ;
    board1.printBoard() ;

    //Determine which AI the comp will use
    while( 1 ) {

        cout << "Do you want to play against the easy computer ( enter 1 ) or the hard computer ( enter 2 )." << endl ;
        cin >> difi ;
        if( ( difi == 1 ) ||  ( difi == 2 ) ) break ;
        else cout << "ERROR : Please enter either 1 or 2." << endl ;

    }

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

    //Determine which player the computer will be.

    while( 1 ) {
        cout << "Do you want the computer to be Player 1 ( X )  or Player 2 ( O ) ? Please enter a 1 or 2. ;" << endl ;
        cin >> user ;
        if( ( user == 1 ) || ( user == 2 ) ) break ;

        else cout << "ERROR : Please enter 1 or 2." << endl ;
    }
    

    while( 1 ) {

        //Determine if the computer is going first or the player
        if( ( fir == 1 ) && ( user == 1 ) ) comp_move = 1 ; // X is going first and the computer is player 1
        if( ( fir == 2 ) && ( user == 2 ) ) comp_move = 1 ; // O is going first and the computer is player 1.

        //This happends if it is the human's move only
        if( ( comp_move == 0 ) ) {
            while( 1 ) {
                cout << "It is Player " << player << "'s ( " ;
                if( player == 1 ) cout << "X" ;
                else cout << "O" ;
                cout << "'s ) move." << endl ;

                cout << "Make a move, enter the x,y coordinate of your move ( example 2,2 would be the middle space ). Type -1 to exit." << endl ;

                //if you type a letter here it breaks
                cin >> x ;
                if( x == -1 ) exit( 0 );
                //if( ( x != 1 ) && ( x != 2 ) && ( x != 3 ) ) cout << "Please enter a value from 1 - 3 for X" << endl ;
                cin.ignore( 1 ) ;
                cin >> y ;
                //if( ( y != 1 ) && (  y != 2 ) && ( y != 3 ) ) cout << "Please enter a value from 1 - 3 for Y" << endl ;

                //cout << x << "   " << y ; // more debug stuff
                if( error_check( x, y, board1, 1 ) == 0 ) break ;
            }
            
        }

        //This only happens if its the computers move, user is not very descriptive
        //This is the easy ai
        if( ( difi == 1 ) && ( comp_move == 1 ) ) comp_move_easy( x, y, board1 ) ;

        //This is the hard ai
        if( ( difi == 2 ) && ( comp_move == 1 ) ) comp_move_hard( x, y, board1, player ) ;

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

        //Switch Computers
        
        if( comp_move == 1 ) comp_move = 0 ;
        else comp_move = 1 ;
        

        fir = 3 ; // This prevents things from being messed up at the start of the loop.

    }
    
    return 0 ;

}

