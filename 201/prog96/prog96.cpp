
#include "rational.h"
#include <iostream>

using namespace std ;

int main() {

    //Make some fractions
    Rational num1( 3, 5 ) ;
    //Rational num2( 2, 4 ) ; // Fraction will be reduced
    Rational num2( 6,5 ) ;
    Rational num3 ;

    //Print out those fractions in a/b form
    cout << "This program will use these two fractions." << endl ; 
    num1.printabRational() ;
    cout << endl ;
    num2.printabRational() ;
    cout << endl ; 
    //num3.printabRational() ;

    //Print them out in float form
    //num1.printfloatRational() ;
    //num2.printfloatRational() ;
    //num3.printfloatRational() ;

    cout << endl ;

    num1.printabRational() ;
    cout << " + " ;
    num2.printabRational() ; 
    cout << " = " ;

    //Add the rationals
    num3 = num1.addRational( num2 ) ;
    num3.printfloatRational() ;

    cout << endl ; 

    num1.printabRational() ;
    cout << " - " ;
    num2.printabRational() ;
    cout << " = " ;    
    
     //Subtract the rationals
    num3 = num1.subRational( num2 ) ;
    num3.printfloatRational() ;

    cout << endl ;

    num1.printabRational() ;
    cout << " * " ;
    num2.printabRational() ;
    cout << " = " ;

    //Multiple the rationals
    num3 = num1.multiRational( num2 ) ;
    num3.printfloatRational() ;

    cout << endl ;

    num1.printabRational() ;
    cout << " / " ;
    num2.printabRational() ;
    cout << " = " ;

    //Divide the rationals
    num3 = num1.dividRational( num2 ) ;
    num3.printfloatRational() ;

    return 0 ;
    
}
