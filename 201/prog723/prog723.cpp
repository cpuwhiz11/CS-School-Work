/*
 * File:   prog723.cpp
 * Author: Paul
 *
 * Created on October 21, 2010, 1:54 PM
 */

#include <iostream>

int x = 0, y = 0 ;

using namespace std;

void movement( int board[][ 20 ], int distance, int pen, int direction ) ;
void printboard( int board[][ 20 ] ) ;
void init_board( int board[][ 20 ] ) ;

void multi_shapes( int board[][ 20 ] ) {

    int command ;
    
    while( 1 ) {

      x = y = 0 ;
      init_board( board ) ; 
      cout << endl ; 
      cout << "Please enter the shape you want." << endl ;
      cout << "1 = Square " << endl ;
      cout << "2 = Rectangle " << endl ;
      cout << "3 = Triangle " << endl ;

      cout << "4 = Return to main program." << endl ;

      cin >> command ;
      if( ( command > 4 ) || ( command < 0 ) ) cout << "Please enter a value from 1-4." << endl ;

      if( command == 1 ) {
          x = y = 5 ;
          movement( board, 5, 0, 0 ) ;
          movement( board, 5, 0, 3 ) ;
          movement( board, 5, 0, 2 ) ;
          movement( board, 5, 0, 1 ) ;
          printboard( board ) ;

      }

      if( command == 2 ) {
          x = y = 5 ;
          movement( board, 5, 0, 0 ) ;
          movement( board, 10, 0, 3 ) ;
          movement( board, 5, 0, 2 ) ;
          movement( board, 10, 0, 1 ) ;
          printboard( board ) ;

      }

      if( command == 3 ) {

          x = y = 10 ;
          movement( board, 1, 0, 0 ) ;
          movement( board, 1, 1, 3 ) ;
          movement( board, 3, 0, 2 ) ;
          movement( board, 1, 1, 3 ) ;
          movement( board, 5, 0, 0 ) ;
          movement( board, 1, 1, 3 ) ;
          movement( board, 7, 0, 2 ) ;
          printboard( board ) ;

      }

      if( command == 4 ) break ;

    }

    return ;

}

int error_check( int distance, int dir ) {

    if( distance > 20 ) return 0 ;
    if( distance < 0 ) return 0 ;

    if( dir == 0 ) {
        if( ( y +  distance ) > 20 ) return 0 ;
    }
    if( dir == 1 ) {
       if( ( x - distance ) < 0 ) return 0 ;
    }
    if( dir == 2 ) {
        if( ( y -  distance ) < 0 ) return 0 ;
    }
    if( dir == 3 ) {
        if( ( x + distance ) > 20 ) return 0 ;
    }

    else return -1 ;
    
}

void movement( int board[][ 20 ], int distance, int pen, int direction ) {

    int temp = 0 ;

    if( pen == 1 ) {

        if( direction == 0 ) y = y + distance ;
        if( direction == 1 ) x = x - distance ;
        if( direction == 2 ) y = y - distance ;
        if( direction == 3 ) x = x + distance ;

    }

    if( pen == 0 ) {
      if( direction == 0 ) {
	while( temp != distance ) {
	  board[ x ][ y ] = 1 ;
	  y++ ;
          temp++ ;
	}
      }
      if( direction == 1 ) {
	while( temp != distance ) {
	  board[ x ][ y ] = 1 ;
	  x-- ;
	  temp++ ;
	}
      }
      if( direction == 2 ) {
	while( temp != distance ) {
	  board[ x ][ y ] = 1 ;
	  y-- ;
	  temp++ ;
	}
      }

      if( direction == 3 ) {
	while( temp != distance ) {
	  board[ x ][ y ] = 1 ;
	  x++ ;
          temp++ ;
	}
      }

    }

    return ;

}

void printboard( int board[][ 20 ] ) {

// This funtion prints out the board
    int i, j ;

    cout << "The board appears as: " << endl ; 

    for( i = 0 ; i < 20 ; i++ ) {
        cout << endl ;
        for( j = 0 ; j < 20 ; j++ ) {

            if( board[ i ][ j ] == 0 ) cout << "-" ;
            if( board[ i ][ j ] == 1 ) cout << "*" ;

        }
    }

    return ;

}

void init_board( int board[][ 20 ] ) {

    // This function initializes the board to all false.

    int i, j ;

    for( i = 0 ; i < 20 ; i++ ) {

        for( j = 0 ; j < 20 ; j++ ) {

            board[ i ][ j ] = 0 ; // Initialized board to all false

        }
    }

    return ;

}

int main() {

    int board[ 20 ][ 20 ] ; // declare board and size
    int error = -1 ;
    int command, distance, dir = 0, pen = 1 ; // Pen will start up always

    init_board( board ) ;

    cout << "Notes : " << endl ;
    cout << "1. The turtle will start moving right." << endl ;
    cout << "2. The direction system is 0 = right move, 1 = up move, 2 = left move, 3 = down move." << endl ;
    cout << "3. This program shows and uses array location, not points on a plane." << endl ;


    // This is the menu system. 
    while( 1 ) {
        list:
        cout << endl ;
        cout << "The options are: " << endl ;
        cout << "1 = Pen Up" << endl ;
        cout << "2 = Pen Down" << endl ;
        cout << "3 = Turn Right" << endl ;
        cout << "4 = Turn Left" << endl ;
        cout << "5 = Move a distance ( input distance after selecting option )" << endl ;
        cout << "6 = Print the Board" << endl ;
        cout << "7 = Print the location of the turtle in the array" << endl ;
        cout << "8 = About this Program" << endl ;
        cout << "9 = End the Program" << endl ;
        cout << "10 = Additional Shapes ( will reset board!)"  << endl ;

        cin >> command ;
        if( ( command > 10 ) || ( command < 0 ) ) cout << "Please enter an option 1-10." << endl ;

        // Will set pen to be up - 1 or down - 0
        if( command == 1 ) {
            pen = 1 ;
            cout << "Pen has been set to the up position." << endl ;
        }

        if( command == 2 ) {
            pen = 0 ;
            cout << "Pen has been set to the down position." << endl ;
        }

        // Will set direction
        if( command == 3 ) {
            if( dir == 0 ) dir = 4 ;
            dir-- ;
            cout << "The turtle turned right." << endl ;
            cout << "The turtle is heading in the : " << dir << " direction." << endl ;
        }

        if( command == 4 ) {
            if( dir == 3 ) dir = -1 ;
            dir++ ;
            cout << "The turtle turned left." << endl ;
            cout << "The turtle is heading in the : " << dir << " direction." << endl ;
        }

        // Will get the turtle moving
        if( command == 5 ) {
            while( 1 ) {
                cout << "Please enter distance for the turtle to travel or -1 to exit this section: " << endl ;
                cin >> distance ;
                if( distance == -1 ) goto list ; // Yes I know its a goto, but it was the best way to break out of two loops I could think of. 
                error = error_check( distance, dir ) ;

                if( error != -1 ) cout << "Your distance will go outside the board please enter a smaller distance." << endl ;
                else break ;
            }

            cout << "The turtle travled: " << distance << " spaces." << endl ;
            cout << "The turtle travled in the: " << dir << " direction." << endl ;
            error = -1 ;
            movement( board, distance, pen, dir ) ;

        }

        if( command == 6 ) printboard( board ) ;

        if( command == 7 ) cout << "The turtle is in position: " << x << ", " << y << " on the array. " << endl ;

        if( command == 8 ) {

            cout << "This program was developed on Netbeans v6.9.1." << endl ;
            cout << "Developed by Paul Geromini" << endl ;
            cout << "v1.0" << endl ;
        }

        if( command == 9 ) break ;

        if( command == 10 ) {

            x = y = 0 ;
            dir = 0 ;
            multi_shapes( board ) ;

        }

    }

    return 0;

}


