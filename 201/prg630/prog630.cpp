/* 
 * File:   prog630.cpp
 * Author: Paul
 *
 * Created on October 14, 2010, 3:43 PM
 */

#include <iostream>

using namespace std;

/*
 * This is a method I was using until I wised up. It is preserved here for posterity.
 * 
int howbig( int num ) {

    int counter ;

    while( num != 0 ) {
        num = num / 10 ;
        counter++ ;
    }

    return counter ; 

}

int reversemagic( int num ) {

    int ans = 0, temp = 0, i, j ;

    i = howbig( num ) ;
  
    
    while( num != 0 ) {

        i-- ; 
        j = i ;

        temp = num % 10 ;
        num = num / 10 ;
        
        while( j > 0 ) {

            temp = temp * 10 ;
            j-- ;
       
        }

        
        ans = ans + temp ;

    }

    return ans ;

}
*/



int main() {

    int num, ans ;

    cout << "Please enter an integer value." << endl ;
    cin >> num ;

    cout << "The reverse of " << num << " is : " ;
    
    while( num != 0 ) {

        ans = num % 10 ;
        cout << ans ;
        num = num / 10 ;
        
    }
    
    return 0 ;

}