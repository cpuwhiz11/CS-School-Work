/* 
 * File:   prog638.cpp
 * Author: Paul
 *
 * Created on October 14, 2010, 6:20 PM
 */

#include <iostream>

using namespace std;

void hanoi( char from, char to, char other, char num ){

    if( num == 1 ) cout << "Move disc from " << from << " to " << to << endl ;

    else {

        hanoi( from, other, to, ( num-1 ) ) ;
        hanoi( from, to, other, ( 1 ) ) ;
        hanoi( other, to, from, ( num-1 ) ) ;

    }

}

int main() {

    int discs ;

    while( 1 ) {

        cout << "Please enter the number of discs you want to use. " << endl ;
        cin >> discs ;
        if( discs < 0 ) cout << "Please enter a number greater than 0." << endl;
        else break ;

    }

    hanoi( 'a', 'c', 'b', discs ) ;

    return 0;
}

