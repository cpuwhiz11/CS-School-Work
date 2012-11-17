/* 
 * File:   prog813.cpp
 * Author: Paul
 *
 * Created on November 6, 2010, 5:56 PM
 */

#include <iostream>

using namespace std;

void mystery1( char *s1, const char *s2 ) {

    while( *s1 != '\0' ) s1++ ;
    for( ; *s1 = *s2 ; s1++, s2++ ) ; 

}

int main() {

    char string1[ 80 ] ;
    char string2[ 80 ] ;

    cout << "Enter two strings: " << endl ;
    cin >> string1 >> string2 ;
    mystery1( string1, string2 ) ;
    cout << string1 ;

    return 0;
}

