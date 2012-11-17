// time.cpp
// Contains functions from headers in time.h

#include <iostream>
#include "time.h"
#include <iomanip>

using namespace std ;


//This is the constructor
Time::Time( int hr, int min, int sec ) {

    setTime( hr, min, sec ) ;

    return ;

}

void Time::setTime( int hr, int min, int sec ) {

    setHour( hr ) ;
    setMinute( min ) ;
    setSecond( sec ) ;

    return ;
    
}

void Time::setHour( int hr ) {

    if( ( hr > 23 ) || ( hr <= 0 ) ) hr = 0 ;
    hour = hr ;
    return ;

}

void Time::setMinute( int min ) {

    if( ( min > 60 ) || ( min < 0 ) ) min = 0 ;
    minute = min ;
    return ;

}

void Time::setSecond( int sec ) {

    if( ( sec > 60 ) || ( sec < 0 ) ) sec = 0 ;
    second = sec ;
    return ;

}

void Time::setTick() {

    if( second < 59 ) second++ ;
    else {
        second = 0 ;
        if( minute < 59 ) minute++ ;
        else {
            minute = 0 ;
            setHour( ++hour ) ;
        }
    }

    return ;

}

int Time::getHour(){

    return hour ;

}

int Time::getMinute() {

    return minute ;

}

int Time::getSecond() {

    return second ;
    
}

void Time::printUniversal() {

    cout << setfill( '0' ) << setw( 2 ) << getHour() << ":" << setw( 2 ) << getMinute() << ":" << setw( 2 ) << getSecond() ;
    return ;

}

void Time::printStandard() {

    cout << ( ( getHour() == 0 ) || ( getHour() == 12 ) ? 12 : getHour() % 12 ) ; 

    cout << ":" << setfill( '0' ) << setw( 2 ) << getMinute() << ":" << setw( 2 ) << getSecond() ;
    if( hour >= 12 ) cout << " PM" ;
    else cout << " AM" ;
    
    return ;

}