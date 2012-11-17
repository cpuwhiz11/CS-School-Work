/* 
 * File:   prog512.cpp
 * Author: Paul
 *
 * Created on October 8, 2010, 7:56 PM
 */

#include <iostream>

using namespace std;

void pattern( int choice ) ;

int main() {

    int choice ;

    while( 1 ) {

        cout << "Please enter which pattern you would like ( 1 - 4 ) or 5 for all of them : " << endl ;
        cin >> choice ;
        if( ( choice > 5 ) || ( choice < 1 ) ) cout << "Please enter a value between 1 and 5." << endl ;
        else break ;

    }

    cout << endl ; 
    pattern( choice ) ;

    return 0;
}

void pattern( int choice ) {

    int i, j, sw ;

    if( choice == 1 ) {

        for( i = 1 ; i <= 10 ; i++ ) {

            for( j = i ; j > 0 ; j-- ) {
               cout << '*' ;   
            }
          
            cout << endl ; 
        }
    }

    if( choice == 3 ) {

        for( i = 10 ; i >= 0 ; i-- ) {
            sw = i ;
            for( j = i ; j > 0 ; j-- ) {
               
               while( sw != 10 ) {
                   cout << " " ;
                   sw++ ;
               }
               cout << '*' ;
            }

            cout << endl ;
        }
    }

    if( choice == 4 ) {

        for( i = 1 ; i <= 10 ; i++ ) {
            sw = i ;
            for( j = i ; j > 0 ; j-- ) {

               while( sw != 10 ) {
                   cout << " " ;
                   sw++ ;
               }
               cout << '*' ;
            }

            cout << endl ;
        }
    }
/*
    if( choice == 5 ) {
        
        for( i = 1 ; i <= 10 ; i++ ) {

            for( j = i ; j > 0 ; j-- ) {
               cout << '*' ;
            }

            cout << endl ;
        }
    }
*/
    return ; 

}
