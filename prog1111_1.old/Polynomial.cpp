//Polynomial.cpp

#include "Polynomial.h"
#include <iostream>

using namespace std ;
//Constains definitions for function headers from Polynomia.h

Polynomial::Polynomial( int c, int p ) {

    coef = c ;
    exp = p ;
    return ; 

}

Polynomial& Polynomial::operator =( const Polynomial& equi ) {

    if( this == &equi ) return *this ;

    coef = equi.coef ;
    exp = equi.exp ;

    return *this ;

}

Polynomial& Polynomial::operator +=( const Polynomial& add ){

    coef = add.coef + coef ;
    exp = add.exp + exp ;

    return *this ;

}

Polynomial& Polynomial::operator -=( const Polynomial& sub ){

    coef = coef - sub.coef ;
    exp = exp - sub.exp ;

    return *this ;

}

Polynomial& Polynomial::operator *=( const Polynomial& multi ) {

    coef = coef * multi.coef ;
    exp = exp + multi.exp ;
    return *this ; 

}

Polynomial Polynomial::operator +( const Polynomial& other ) {

    Polynomial result ;
    result = *this ;
    result += other ;
    return result ;

}

Polynomial Polynomial::operator -( const Polynomial& other ) {

    Polynomial result ;
    result = *this ;
    result -= other ;
    return result ;

}

Polynomial Polynomial::operator *( const Polynomial& other ) {

    Polynomial result ;
    result = *this ;
    result *= other ;
    return result ;

}

void Polynomial::setCoef( int c ) {

    coef = c ;
    return ;

}

void Polynomial::setExp( int e ) {

    exp = e ;
    return ;

}

int Polynomial::getCoef() {

    return coef ;

}

int Polynomial::getExp() {

    return exp ;

}

void Polynomial::printPoly() {

    cout << coef <<"X^" << exp << endl ;
    return ;

}