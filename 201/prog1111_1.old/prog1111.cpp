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

    Polynomial poly1( 2, 4 ) ; //Create a polynomial 2x^4
    Polynomial copy_poly ; // empty polynomial to copy another polynomial into it

    //Make some polynomials to add together
    Polynomial add1( 3, 2 ) ;
    Polynomial add2( 4, 5 ) ;
    Polynomial result ;

    copy_poly = poly1 ;

    cout << "The value in copy_poly is: " << endl ;
    copy_poly.printPoly() ;

    cout << "The value of add1 += add2 is: " << endl ;
    add1 += add2 ;

    add1.printPoly() ;

    //Reinitialize add1 poly
    add1.setCoef( 3 ) ;
    add1.setExp( 2 ) ;

    cout << "The value of add1 -= add2 is: " << endl ;

    add1 -= add2 ;
    add1.printPoly() ;

    //Reinitialize add1 poly
    add1.setCoef( 3 ) ;
    add1.setExp( 2 ) ;

    cout << "The value of add1 + add2 is: " << endl ;
    result = add1 + add2 ;

    result.printPoly() ;

    cout << "The value of add1 - add2 is: " << endl ;
    result = add1 - add2 ;

    result.printPoly() ;

    cout << "The value of add1 *= add2 is : " << endl ;
    add1 *= add2 ;

    add1.printPoly() ;

    //Reinitialize add1 poly
    add1.setCoef( 3 ) ;
    add1.setExp( 2 ) ;

    cout << "The value of add1 * add2 is : " << endl ;
    result = add1 * add2 ;

    result.printPoly() ;

    return 0;
}

