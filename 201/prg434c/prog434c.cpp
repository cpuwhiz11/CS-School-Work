/*
 * File:   prog434c.cpp
 * Author: Paul
 *
 * Created on October 6, 2010, 4:44 PM
 */

#include <iostream>
#include <math.h>

using namespace std ;

float factorial( int num ) {

    float fact ;

    if ( ( num == 1 ) || ( num == 0 ) ) return 1 ;

    while( 1 ) {

        return fact = num * ( factorial( num - 1 ) ) ;
        break ;

    }

    return fact ;

}

float value_of_e( int limit, int expo ) {

    int index = 1 ;
    float temp = 1 ;

    while( limit > 0 ) {

     temp = ( pow( expo, index ) / factorial( index ) ) + temp ;
     limit-- ;
     index++ ;

    }

    return temp ;

}

int main() {

    int num, expo ;
    float value ;


    cout << "This program computes the value of e^x to a desired accuracy." << endl ;

    while( 1 ) {
        cout << "Please enter a value for the exponent :" << endl ;
        cin >> expo ;
        if( expo < 0 ) cout << "Plese eneter a positive value. " << endl ;
        else break ;

    }
    while( 1 ) {

        cout << "Please enter the accuracy :" << endl ;
        cin >> num ;
        if( num < 0 ) cout << "Please enter a positive number." ;
        else break ;
    }

    value = value_of_e( num, expo ) ;

    cout << "The value of e is: " << value << endl ;

    return 0;
}
