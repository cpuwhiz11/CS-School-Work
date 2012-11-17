/* 
 * File:   prog711.cpp
 * Author: Paul GEromini
 *
 * Created on October 20, 2010, 7:15 PM
 */

#include <iostream>

using namespace std;


void bubblesort( int A[], int n ) {

  int i, temp, j ;

  for ( i = 0 ; i < ( n - 1 ); i++ ) {

    for ( j = 0 ; j < ( n - 1 ) - i ; j++ ) {

      if ( A [ j ] > A [ j + 1 ] ) {

        temp = A [ j ] ;

        A [ j ] = A [ j + 1 ] ;

        A [ j + 1 ] = temp ;

      }

    }

  }

  return ;

}

int main() {

    int orig[ 10 ] = { 3, 6, 12, 1, 3, 5, 34, 5, 7, 10} ;
    int i ; 

    cout << "The original 10 integer array is: " ;
    for( i = 0 ; i < 10 ; i++ ) cout << " " << orig[ i ] ;
    cout << endl ;

    bubblesort( orig, 10 ) ;

    cout << "The sorted 10 integer array is: " ;
    for( i = 0 ; i < 10 ; i++ ) cout << " " << orig[ i ] ;
    cout << endl ;


    return 0;
}

