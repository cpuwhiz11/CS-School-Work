/* 
 * File:   time.h
 * Author: Paul
 *
 * Created on November 18, 2010, 4:13 PM
 */

#ifndef TIME_H
#define	TIME_H

class Time {

public :
    Time( int = 0, int = 0, int = 0 ) ; //Default constructer

    //Set instructions
    void setTime( int, int, int ) ;
    void setHour( int ) ;
    void setMinute( int ) ;
    void setSecond( int ) ;
    void setTick() ;

    //Get Functions
    int getHour() ;
    int getMinute() ;
    int getSecond() ;

    //Print functions
    void printUniversal() ;
    void printStandard() ;


private :

    int hour ;
    int minute ;
    int second ;

};

#endif	/* TIME_H */

