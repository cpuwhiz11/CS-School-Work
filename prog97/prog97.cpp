/* 
 * File:   prog97.cpp
 * Author: Paul
 *
 * Created on November 18, 2010, 4:13 PM
 */

#include <iostream>
#include "time.h"

using namespace std;

int main() {

    int temp = 0 ;
    Time t1 ;
    Time t2( 2 ) ;
    Time t3( 21, 34 ) ;
    Time t4( 12, 25, 42) ;
    Time t5( 27, 74, 99 ) ; // bad numbers
    Time t6( 23, 0, 0 ) ;

    cout << "Constructed with:\n\nt1: all arguments defaulted\n" ;
    t1.printUniversal() ;
    cout << endl ;
    t1.printStandard() ;
    cout << endl ;

    
    cout << "Hour specified, the rest default." << endl ;
    t2.printUniversal() ;
    cout << endl ;
    t2.printStandard() ;
    cout << endl ;

    cout << "Hour and minute specified, the seconds default." << endl ;
    t3.printUniversal() ;
    cout << endl ;
    t3.printStandard() ;
    cout << endl ;

    cout << "All specified." << endl ;
    t4.printUniversal() ;
    cout << endl ;
    t4.printStandard() ;
    cout << endl ;

    cout << "All invalid values." << endl ;
    t5.printUniversal() ;
    cout << endl ;
    t5.printStandard() ;
    cout << endl ;

    cout << "Test the tick member function." << endl ;
    while( temp != 3600 ) {
        t6.setTick() ;
        //t6.printUniversal() ;
        t6.printStandard() ;
        cout << endl ; 
        temp++ ; 
    }
    
    
    return 0;
}

