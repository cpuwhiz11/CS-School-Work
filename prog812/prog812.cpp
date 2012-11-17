/* 
 * File:   prog812.cpp
 * Author: Paul
 *
 * Created on November 3, 2010, 3:32 PM
 */

#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

/*
 * This program simulate a race between the tortoise and a hare.
 */

int random_num() {
    // Function returns a random number from 1 - 10
  
    return( rand() % 10 + 1 ) ;
}

int move_type_tort(){

    int temp ;

    temp = random_num() ;
    if( ( temp == 1 ) || ( temp == 2 ) || ( temp == 3 ) || ( temp == 4 ) || ( temp == 5 ) ) return 1 ;
    //if( ( temp > 0 ) || ( temp < 6 ) ) return 1 ; // Fast plod
    if( ( temp == 6 )||( temp == 7 ) ) return 2 ; // Slip
    //if( ( temp > 7 ) || ( temp < 11 ) ) return 3 ; // Slow pod
    if( ( temp == 8 ) || ( temp == 9 ) || ( temp == 10 ) ) return 3 ;

}

int move_type_hare(){

    int temp ;

    temp = random_num() ;
    if( ( temp == 1 ) || ( temp == 2 ) ) return 1 ; // Sleep
    if( ( temp == 3 ) || ( temp == 4 ) ) return 2 ; // Big hop
    if( ( temp == 5 ) ) return 3 ; // Big slip ;
    if( ( temp == 6 ) || ( temp == 7 ) || ( temp == 8 ) ) return 4 ; // Small hop
    if( ( temp == 9 ) || ( temp == 10 ) ) return 5 ; // Small slip 

}

void moveTortoise( int *tort ) {

    int code ;

    code = move_type_tort() ;

    if( code == 1 ) {
        *tort = *tort + 3 ;
        return ;
    }
    if( code == 2) {
        if( *tort < 6 ) {
            *tort = 1 ;
            return ;
        }
        *tort = *tort - 6 ;
        return ;
    }
    if( code == 3 ) {
        *tort = *tort + 1 ;
        return ;
    }

}

void moveHare( int *hare ) {

    int code ;

    code = move_type_hare() ;

    if( code == 1 ) return ;
    if( code == 2 ) {
        *hare = *hare + 9 ;
        return ;
    }
    if( code == 3 ) {
        if( *hare < 12 ) {
            *hare = 1 ;
            return ;
        }

        *hare = *hare - 12 ;
        return ;
    }
    if( code == 4 ) {
        *hare = *hare + 1 ;
        return ;
    }

    if( code == 5 ) {
        if( *hare < 2 ) {
            *hare = 1 ;
            return ;
        }

        *hare = *hare - 2 ;
        return ;
    }

}

void print_positions( int hare, int tort ) {
// Will print out the positions of hare and tort
    int i ;

    cout << endl ;
    for( i = 1 ; i <= 70 ; i++ ) {
        if( i == hare ) cout << "H" ;
        if( i != hare ) cout << "-" ;
    }
    cout << endl ;
    for( i = 1 ; i <= 70 ; i++ ) {
        if( i == tort ) cout << "T" ;
        if( i != tort ) cout << "-" ;
    }
    
    cout << endl ;

}

int main() {

    int hare , tort , clock ;
    hare = tort = 1 ;
    clock = 1 ;

    srand( time( NULL ) ) ; // Seed the random num generator

    cout << "BANG !!!!!" << endl ;
    cout << "AND THEY'RE OFF !!!!!" << endl ;

    while( 1 ) {

        cout << endl ;
        cout << "The time is: " << clock << endl ;

        moveHare( &hare ) ;
        moveTortoise( &tort ) ;

        if( hare != 1 ) {
            if( hare == tort ) {
                cout << "OUCH!!!" << endl ;
            }
        }

        print_positions( hare, tort ) ;

        if( ( hare >= 70 ) && ( tort >= 70 ) ) {
            cout << endl ;
            cout << "The race ends in a tie, but it is decided that the tortoise wins." << endl ;
            break ;
        }

        if( hare >= 70 ) {
            cout << endl ;
            cout << "Hare wins. Yuch." << endl ;
            break ;
        }

        if( tort >= 70 ) {
            cout << endl ;
            cout << "TORTOISE WINS!!!" << endl ;
            break ;
        }

        clock++ ;

    }

    return 0;
}

