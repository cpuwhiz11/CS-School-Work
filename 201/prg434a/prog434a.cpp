/* 
 * File:   prog434a.cpp
 * Author: Paul
 *
 * Created on October 6, 2010, 4:44 PM
 */

#include <iostream>

using namespace std;

int factorial( int num ) {

    int fact ;

    if ( ( num == 1 ) || ( num == 0 ) ) return 1 ;

    while( 1 ) {

        return fact = num * ( factorial( num - 1 ) ) ;
        break ;

    }
    
    return fact ;

}

int main() {

    int num, value ;

    while( 1 ) {
        cout << "Please enter a number to compute its factorial :" << endl ;
        cin >> num ;
        if( num < 0 ) cout << "Please enter a positive number." ;
        break ; 
    }

    value = factorial( num ) ;

    cout << "The value of the factorial is: " << value << endl ;

    return 0;
}

