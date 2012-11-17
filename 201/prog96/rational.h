/* 
 * File:   rational.h
 * Author: Paul
 *
 * Created on November 17, 2010, 3:38 PM
 */

#ifndef RATIONAL_H
#define RATIONAL_H

class Rational
{

public :

    Rational( int = 1 , int = 1 ) ; // This will set the rational number's default
   
    Rational addRational( const Rational & ) ; // Will add to rational numbers
    Rational subRational( const Rational & ) ; // Will subtract the rational numbers
    Rational multiRational(const Rational & ) ; // Will multiply the rational numbers
    Rational dividRational( const Rational & ) ; // Will divide the rational numbers
    void printabRational() ; //Will print rational in a/b form
    void printfloatRational() ; //Will print rational in floating point

private :

    int numerator ;
    int denominator ;
    void Reduction() ; //Utility program

};

#endif
