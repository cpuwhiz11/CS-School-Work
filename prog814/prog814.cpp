/* 
 * File:   prog814.cpp
 * Author: Paul
 *
 * Created on November 6, 2010, 5:57 PM
 */

#include <iostream>

using namespace std;

int mystery2( const char* s ) {

    int x ;
    for( x = 0 ; *s != '\0' ; s++ ) x++ ;

    return x ; 

}

int main() {

    char string1[ 80 ] ;

    cout << "Enter a strings: " << endl ;
    cin >> string1 ;
    cout << mystery2( string1 ) << endl ;


    return 0;
}

