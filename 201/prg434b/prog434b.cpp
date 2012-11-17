/* 
 * File:   prog434b.cpp
 * Author: Paul
 *
 * Created on October 6, 2010, 4:44 PM
 */

#include <iostream>

using namespace std;

float factorial( int num ) {

    float fact ;

    if ( ( num == 1 ) || ( num == 0 ) ) return 1 ;

    while( 1 ) {

        return fact = num * ( factorial( num - 1 ) ) ;
        break ;

    }
    
    return fact ;

}

float value_of_e( float limit ) {

    int index = 1 ;
    float temp = 0 ;

    while( limit > 0 ) {

     temp = ( 1 / factorial( index ) ) + temp ;
     limit-- ;
     index++ ;

    }

    temp = temp + 1 ;

    return temp ;

}

int main() {

    int num ;
    float value ;


    cout << "This program computes the value of e to a desired accuracy." << endl ;

    while( 1 ) {

        cout << "Please enter the accuracy :" << endl ;
        cin >> num ;
        if( num < 0 ) cout << "Please enter a positive number." ;
        break ;
    }

    value = value_of_e( num ) ;

    cout << "The value of e is: " << value << endl ;

    return 0;
}
