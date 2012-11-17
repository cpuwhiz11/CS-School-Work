//Polynomial.cpp

#include "Polynomial.h"
#include <iostream>

using namespace std ;
//Constains definitions for function headers from Polynomia.h

Polynomial::Polynomial() {

    int i ;
    for( i = 0 ; i < maxterms ; i++ ) {
        coef[ i ] = 0 ;
        exp[ i ] = 0 ;
    }

    numberofterms = 0 ;

}

Polynomial& Polynomial::operator =( const Polynomial& equi ) {

    int i ;

    exp[ 0 ] = equi.exp[ 0 ] ;
    coef[ 0 ] = equi.coef[ 0 ] ;

    for( i = 1 ; i < maxterms ; i++ ) {
        if( equi.exp[ i ] != 0 ) {
            exp[ i ] = equi.exp[ i ] ;
            coef[ i ] = equi.coef[ i ] ;
        }
        else {
            if( exp[ i ] == 0 ) break ;
            exp[ i ] = 0 ;
            coef[ i ] = 0 ;
        }
    }

    return *this ;

}

Polynomial& Polynomial::operator +=( const Polynomial& add ){

    *this = *this + add ;
    return *this ;

}

Polynomial& Polynomial::operator -=( const Polynomial& sub ){

    *this = *this - sub ;
    return *this ;
}

Polynomial& Polynomial::operator *=( const Polynomial& multi ) {

    *this = *this * multi ;
    return *this ;

}

Polynomial Polynomial::operator +( const Polynomial& other ) {

    Polynomial temp ;
    bool real ;
    int i, j, k ;

    temp.coef[ 0 ] = coef[ 0 ] + other.coef[ 0 ] ;

    for( k = 0 ; ( k < maxterms ) && ( other.exp[ k ] != 0 ) ; k++ ) {
        temp.coef[ k ] = other.coef[ k ] ;
        temp.exp[ k ] = other.exp[ k ] ;
    }

    for( i = 1 ; i < maxterms ; i++ ) {
        real = 0 ;
        for( j = 1 ; ( ( j < maxterms ) && ( real != 1 ) ) ; j++ ) {
            if( exp[ i ] == temp.exp[ i ] ) {
                temp.coef[ j ] += coef[ i ] ;
                real = 1 ;
            }
        }
        if( real != 0 ) {
            temp.exp[ k ] = exp[ i ] ;
            temp.coef[ k ] += coef[ i ] ;
            k++ ;
        }
    }

    return temp ;
}

Polynomial Polynomial::operator -( const Polynomial& other ) {

    Polynomial temp ;
    bool real ;
    int i, j, k ;
    
    temp.coef[ 0 ] = coef[ 0 ] - other.coef[ 0 ] ;
    
    for( i = 1 ; ( ( i < maxterms ) && ( exp[ i ] != 0 ) ) ; i++ ) {
        temp.coef[ i ] = coef[ i ] ;
        temp.exp[ i ] = exp[ i ] ; 
    }

    for( j = 1 ; i < maxterms ; i++ ) {
        real = 0 ;
        for( k = 1 ; ( ( k < maxterms ) && ( true != 0 ) ) ; k++ ) {
            if( other.exp[ j ] == temp.exp[ k ] ) {
                temp.coef[ j ] -= other.coef[ j ] ;
                real = 1 ;
            }
        }
        if( real != 0 ) {
            temp.exp[ i ] = other.exp[ j ] ;
            temp.coef[ i ] -= other.coef[ j ] ;
            i++ ;
        }
    }
    return temp ;
}

Polynomial Polynomial::operator *( const Polynomial& other ) {

    Polynomial temp ;
    int i = 1, x, y  ;

    for( x = 0 ; ( ( x < maxterms ) && ( x == 0  || other.coef[ x ] != 0 ) ) ; x++ ) {
         for( y = 0 ; ( ( y < maxterms ) && ( y == 0  || other.coef[ y ] != 0 ) ) ; y++ ) {
             if( coef[ x ] * other.coef[ y ] ) {
                 if( ( exp[ x ] == 0 ) && ( other.exp[ y ] == 0 ) ) {
                     temp.coef[ 0 ] += coef[ x ] * other.coef[ y ] ;
                 }
                 else {
                     temp.coef[ i ] = coef[ x ] * other.coef[ y ] ;
                     temp.exp[ i ] = exp[ x ] + other.exp[ y ] ;
                     i++ ;
                 }
             }
         }
    }
    polyComb( temp ) ;
    return temp ;
}

void Polynomial::setCoef( int term, int c ) {

    if( coef[ term ] == 0 ) cout << "No term here, look elsewhere padawan" << endl ;
    else coef[ term ] = c ;
    return ;
}


int Polynomial::getCoef( int term ) const {

    return coef[ term ] ;

}

int Polynomial::getExp( int term ) const {

    return exp[ term ] ;

}

void Polynomial::printPoly() {

    int start, i ;
    bool zero = 0 ;

    if( coef[ 0 ] ) {
        cout << coef[ 0 ] ;
        start = 1 ;
        zero = 1 ;
    }
    else {
        if( coef[ 1 ] ) {
            cout << coef[ 1 ] << "X" ;
            if( ( exp[ 1 ] != 0 ) && ( exp[ 1 ] ) != 1 ) cout << "^" << exp[ 1 ] ;
            zero = 1 ;
        }

        start = 2 ;

    }

    for( i = start ; i < maxterms ; i++ ) {
        if( coef[ i ] != 0 ) {
            cout << showpos << coef[ i ] << noshowpos << "X" ;
            if( ( exp[ i ] != 0 ) && ( exp[ i ] != 1 ) ) cout << "^" << exp[ i ] ;
            zero = 1 ;
        }
    }
    if( zero != 1 ) cout << "0" << endl ;
    return ;
}

void Polynomial::polyComb( Polynomial &comb ) {

    Polynomial temp = comb ;
    int i, j ;

    for( i = 0 ; i < maxterms ; i++ ) {
        comb.coef[ i ] = 0 ;
        comb.exp[ i ] = 0 ;
    }

    for( i = 1 ; i < maxterms ; i++ ) {
        for( j = i + 1 ; j < maxterms ; j++ ) {
            if( temp.exp[ i ] == temp.exp[ j ] ) {
                temp.coef[ i ] += temp.coef[ j ] ;
                temp.exp[ j ] = 0 ;
                temp.coef[ j ] = 0 ;
            }
        }
    }
    comb = temp ;
    return ;
}

void Polynomial::enterTerms() {

    bool find = 0 ;
    int co, ex, term ;
    int i ;

    cout << "Please enter the number of polynomial terms: " << endl ;
    cin >> numberofterms ;

    for( i = 0 ; ( i < maxterms && i < numberofterms ) ; i++  ) {
        cout << "Please enter the coefficent : " << endl ;
        cin >> co ;
        cout << "Please enter the exponet : " << endl ;
        cin >> ex ;

        if( co != 0 ) {
            if( ex == 0 ) {
                coef[ 0 ] += co ;
                continue ;
            }

            for( term = 1 ; ( ( term < maxterms ) && ( coef[ term ] != 0 ) ) ; term++ ) {
                if( ex == exp[ term ] ) {
                    coef[ term ] += co ;
                    exp[ term ] = ex ;
                    find = 1 ;
                }
            }
            if( !find ) {
                coef[ term ] += co ;
                exp[ term ] = ex ;
            }
        }
    }
    return ; 
}

int Polynomial::getNumberofTerms() const {
    return numberofterms ;
}

Polynomial::~Polynomial() {
}