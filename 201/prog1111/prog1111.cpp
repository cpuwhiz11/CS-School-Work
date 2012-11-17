/* 
 * File:   prog1111.cpp
 * Author: Paul
 *
 * Created on November 23, 2010, 6:13 PM
 */

#include <iostream>
#include "Polynomial.h"
using namespace std;


int main() {

    Polynomial poly1, poly2, poly3, poly4 ;

    poly1.enterTerms() ;
    poly2.enterTerms() ;

    poly4 = poly1 ;

    cout << "The first polynomial is: " << endl ;
    poly1.printPoly() ;
    cout << endl ;

    cout << "The second polynomial is : " << endl ;
    poly2.printPoly() ;
    cout << endl ;

    cout << "poly1 + poly2 = : " << endl ;

    poly3 = poly1 + poly2 ;
    poly3.printPoly() ;
    cout << endl ;

    cout << "poly1 += poly2 = " << endl ;
    poly1 += poly2 ;
    poly1.printPoly() ;
    cout << endl ;

    //Reset poly1 value
    poly1 = poly4 ;

    cout << "poly1 - poly2 = : " << endl ;
    poly3 = poly1 - poly2 ;
    poly3.printPoly() ;
    cout << endl ;

    cout << "poly1 -= poly2 = " << endl ;
    poly1 -= poly2 ;
    poly1.printPoly() ;
    cout << endl ;

    //Reset poly1 value
    poly1 = poly4 ;

    cout << "poly1 * poly2 = " << endl ;
    poly3 = poly1 * poly2 ;
    poly3.printPoly() ;
    cout << endl ;

    cout << " poly1 *= poly2 = " << endl ;
    poly1 *= poly2 ;
    poly1.printPoly() ;
    cout << endl ;

    return 0 ; 
}

