// Rational.cpp file
// Contains functions for headers in rational.h

#include "rational.h"
#include <iostream>
using namespace std ;

Rational::Rational( int num, int denom ) {

    numerator = num ;
    if( denom == 0 ) {
        cout << "Zero cannot be in the denominator, denominator has been set to 1" << endl ;
        denominator = 1 ;
    }
    denominator = denom ;
    Reduction() ;

}

Rational Rational::addRational( const Rational &n ) {

    Rational num ;
    num.numerator = n.numerator * denominator ;
    num.numerator = ( n.denominator * numerator ) + num.numerator ;
    num.denominator = n.denominator * denominator ;

    num.Reduction() ;

    return num ;
}

Rational Rational::subRational( const Rational &n ){

    Rational num ;

    num.numerator = n.denominator * numerator ; 
    num.numerator = num.numerator - ( denominator * n.numerator ) ;
    num.denominator = n.denominator * denominator ;

    num.Reduction() ;

    return num ;
}

Rational Rational::multiRational( const Rational &n ) {

    Rational num ;

    num.numerator = numerator * n.numerator ;
    num.denominator = denominator * n.denominator ;

    num.Reduction() ;

    return num ;
           
}

Rational Rational::dividRational( const Rational &n ) {

    Rational num ;

    num.numerator = n.denominator * numerator ;
    num.denominator = denominator * n.numerator ;

    num.Reduction() ;

    return num ;

}

void Rational::printabRational() {

    cout << numerator << " / " << denominator ;

    return ;

}

void Rational::printfloatRational() {

    double temp ;
    temp = ( double ) numerator / denominator ;

    cout << temp << endl ;

    return ;

}

void Rational::Reduction() {

    int large, gcd = 0, i ;
    //Find largest num
    if( numerator > denominator ) large = numerator ;
    else large = denominator ;

    for( i = 2 ; i <= large ; i++ ) {
        if( ( numerator % i == 0 ) && ( denominator % i == 0 ) ) gcd = i ;
    }

    if( gcd != 0 ) {

        numerator = numerator / gcd ;
        denominator = denominator / gcd ;
    }

    return ;

}