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

    static const int maxterms = 100 ; // Maximum number of terms

    Polynomial() ; //Default constructor

    //Operator Overloaders
    Polynomial &operator =( const Polynomial &equi ) ; //Overload = operator
    Polynomial &operator +=( const Polynomial &add ) ; //Overload the += operator
    Polynomial &operator -=( const Polynomial &sub ) ; //Overload the -= operator
    Polynomial &operator *=( const Polynomial &multi ) ; //Overload the *= operator 
    Polynomial operator +( const Polynomial &other ) ; //Overload + operator
    Polynomial operator -( const Polynomial &other ) ; //Overload - operator
    Polynomial operator *( const Polynomial &other ) ; //Overload * operator

    void enterTerms() ;

    //Getters
    int getNumberofTerms() const ;
    int getCoef( int ) const ;
    int getExp( int ) const ;

    void setCoef( int, int ) ; //Set coefficent
    
    void printPoly() ; //Print out the polynomial

    ~Polynomial() ; //Destructor
    

private :

    int numberofterms ;
    int exp[ maxterms ] ;
    int coef[ maxterms ] ;

    static void polyComb( Polynomial& ) ;

};

#endif	/* POLYNOMIAL_H */

