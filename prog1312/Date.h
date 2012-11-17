/* 
 * File:   Date.h
 * Author: Paul
 *
 * Created on December 7, 2010, 6:27 PM
 */

#include <iostream>
using namespace std ;

#ifndef DATE_H
#define	DATE_H

class Date {

    friend ostream &operator <<( ostream &, const Date & ) ;

public :
    Date( int m = 1, int d = 1, int y = 1900 ) ;
    void setDate( int, int, int ) ;
    Date &operator++() ;
    Date operator++( int ) ;
    const Date &operator+=( int ) ;
    static bool leapYear( int ) ;
    bool endOfMonth( int ) const ;
    int getMonth() ;

private:
    int month ;
    int day ;
    int year ;

    static const int days[] ;
    void helpIncrement() ;

};

#endif	/* DATE_H */

