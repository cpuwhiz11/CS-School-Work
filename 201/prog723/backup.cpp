/*
 * File:   prog723.cpp
 * Author: Paul
 *
 * Created on October 21, 2010, 1:54 PM
 */

#include <iostream>



using namespace std;

void movement( int board[][ 20 ], int distance, int pen, int direction, int *x, int *y ) {

    int i, j ;

    j = distance ;
    if( pen == 1 ) {
        if( direction = 0 ) *y = *y + distance ;
        if( direction = 1 ) *x = *x + distance ;
        if( direction = 2 ) *y = *y - distance ;
        if( direction = 3 ) *x = *x - distance ;
    }

    if( pen == 0 ) {

        if( direction = 0 ) {
            for( i = *y ; j > 0 ; j-- ) {
                board[ i ][ *x ] = 1 ;
                i++ ;
            }

            *y = *y + distance ;
        }

        if( direction = 1 ) {
            for( i = *x ; j > 0 ; j-- ) {
                board[ *y ][ i ] = 1 ;
                i++ ;
            }

            *x = *x + distance ;
        }

        if( direction = 2 ) {
            for( i = *y ; j > 0 ; j-- ) {
                board[ i ][ *x ] = 1 ;
                i-- ;
            }

            *y = *y - distance  ;
        }

        if( direction = 3 ) {
            for( i = *y ; j > 0 ; j-- ) {
                board[ *y ][ i ] = 1 ;
               i-- ;
            }
            *x = *x - distance ;
        }

    }

    return ;

}

void printboard( int board[][ 20 ] ) {
// This funtion prints out the board
    int i, j ;

    for( i = 0 ; i < 20 ; i++ ) {
        cout << endl ;
        for( j = 0 ; j < 20 ; j++ ) {

            if( board[ i ][ j ] == 0 ) cout << "-" ;
            if( board[ i ][ j ] == 1 ) cout << "*" ;

        }
    }

    return ;

}

int main() {

    int board[ 20 ][ 20 ] ; // declare board and size
    int i, j, temp, error = -1 ;
    int command, distance, dir = 0, pen = 1 ; // Pen will start up always
    int  *x,  *y ;

    *x = 0 ;
    *y = 0 ;

    for( i = 0 ; i < 20 ; i++ ) {

        for( j = 0 ; j < 20 ; j++ ) {

            board[ i ][ j ] = 0 ; // Initialized board to all false

        }
    }

    while( 1 ) {
        cout << endl ;
        cout << "The options are: " << endl ;
        cout << "1 = Pen Up" << endl ;
        cout << "2 = Pen Down" << endl ;
        cout << "3 = Turn Right" << endl ;
        cout << "4 = Turn Left" << endl ;
        cout << "5 = Move a distance (input distance after selecting option )" << endl ;
        cout << "6 = Print the Board" << endl ;
        cout << "9 = End the Program" << endl ;

        cin >> command ;
        if( ( command > 9 ) || ( command < 1 ) ) cout << "Please enter command from 1 to 9. " << endl ;

        // Will set pen to be up - 1 or down - 0
        if( command == 1 ) {
            pen = 1 ;
            cout << "Pen has been set to the up position." << endl ;
        }

        if( command == 2 ) {
            pen = 0 ;
            cout << "Pen has been set to the down position." << endl ;
        }

        // Will set direction to left - 0 or right - 1
        if( command == 3 ) {
            if( dir == 3 ) dir = -1 ;
            dir++ ;
            cout << "The direction of the turtle is right." << endl ;
        }

        if( command == 4 ) {
            if( dir == 0 ) dir = 3 ;
            dir-- ;
            cout << "The direction of the turtle is left." << endl ;
        }

        // Will get the turtle moving
        if( command == 5 ) {

            while( 1 ) {
                cout << "Please enter distance for the turtle to travel" << endl ;
                cin >> distance ;
                if( distance > 20 ) cout << "This distance will be outside the board." << endl ;
                if( distance < 0 ) cout << "Please enter a positive disatnce." << endl ;
                else break ;


            // Check to see if path will go outside board
                if( dir = 0 ) {
                    temp = *x + distance ;
                    if( ( temp > 20 ) || ( temp < 0 ) ) error = 0 ;
                }
                if( dir = 1 ) {
                    temp = *y + distance ;
                    if( ( temp > 20 ) || ( temp < 0 ) ) error = 1 ;
                }
                if( dir = 2 ) {
                    temp = *y - distance ;
                    if( ( temp > 20 ) || ( temp < 0 ) ) error = 2 ;
                }
                if( dir = 3 ) {
                    temp = *x - distance ;
                    if( ( temp > 20 ) || ( temp < 0 ) ) error = 3 ;
                }

                if( error != -1 ) cout << "Your distance will go outside the board please enter a smaller distance." << endl ;

            }

            error = -1 ;
            movement( board, distance, pen, dir, x, y ) ;

        }

        if( command == 6 ) printboard( board ) ;

        if( command == 9 ) break ;

    }

    return 0;

}



