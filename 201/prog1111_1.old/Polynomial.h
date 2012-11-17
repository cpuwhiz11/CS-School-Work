/* 
 * File:   Polynomial.h
 * Author: Paul
 *
 * Created on November 23, 2010, 6:14 PM
 */

#ifndef POLYNOMIAL_H
#define	POLYNOMIAL_H

/*
struct poly {

    int coef ;
    int exp ;
    int *p_next ;

};
*/

class Polynomial {

public :

    Polynomial( int = 0, int = 0 ) ; //Default constructor

    Polynomial &operator =( const Polynomial &equi ) ; //Overload = operator
    Polynomial &operator +=( const Polynomial &add ) ; //Overload the += operator
    Polynomial &operator -=( const Polynomial &sub ) ; //Overload the -= operator
    Polynomial &operator *=( const Polynomial &multi ) ; //Overload the *= operator 
    Polynomial operator +( const Polynomial &other ) ; //Overload + operator
    Polynomial operator -( const Polynomial &other ) ; //Overload - operator
    Polynomial operator *( const Polynomial &other ) ; //Overload * operator

    void setCoef( int ) ; //Set coefficent  
    void setExp( int ) ; //Set exponet
    void printPoly() ; //Print out the polynomial
    int getCoef() ; 
    int getExp() ;


private :

    int coef ;
    int exp ;

};

#endif	/* POLYNOMIAL_H */

