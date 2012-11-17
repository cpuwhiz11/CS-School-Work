/* 
 * File:   main.cpp
 * Author: Paul
 *
 * Created on October 8, 2010, 8:27 PM
 */

#include <iostream>

using namespace std;

void pietime() {
    
    int count = 1 ;
    long double odd = 3.0, val = 4.0 ;

    while( count <= 1000 ) {

        cout << "Calculation number " << count << ": " << val << endl ;
        if( ( int(odd) % 4 ) == 3 ) val = val - ( 4.0 / odd ) ;
        else if( ( int(odd) % 4 ) == 1 ) val = val + (4.0 / odd ) ;
        else cout << "Something wrong has happened." << endl ;
      
        odd = odd + 2 ;
        count++ ;
        
     }
    
    return ; 
    
}

int main() {

    pietime() ;

    return 0 ;

}

