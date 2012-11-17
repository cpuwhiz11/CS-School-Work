/*
 * File:   prog625.cpp
 * Author: Paul
 *
 * Created on October 14, 2010, 3:43 PM
 */

#include <iostream>
#include <math.h>

using namespace std;

int timeinsec( int hour, int min, int sec ) {

    int ans ; 

    hour = hour * 3600 ;
    min = min * 60 ;

    ans = hour + min + sec ; 

    return ans ;

}

int main() {

    int hour_a, min_a, sec_a ;
    int hour_b, min_b, sec_b ;
    int ans ;

    while( 1 ) {

        cout << "Please enter the first time, enter the hours the minutes and the seconds. Example: 2 34 25 would be 2:34.25." << endl ;
        cin >> hour_a >> min_a >> sec_a ;
        if( ( hour_a > 12 ) || ( hour_a < 1 ) )cout << "Please enter an hour between 1 and 12." << endl ;
        else if( ( min_a > 59 ) || ( min_a < 0 ) )cout << "Please enter the minutes between 0 and 59." << endl ;
        else if(( sec_a > 59 ) || ( sec_a < 0 ) )cout << "Please enter the seconds between 0 and 59." << endl ;
        else break ;

    }

    while( 1 ) {

        cout << "Please enter the second time, enter the hours the minutes and the seconds. Example: 2 34 25 would be 2:34.25." << endl ;
        cin >> hour_b >> min_b >> sec_b ;
        if( ( hour_b > 12 ) || ( hour_b < 1 ) )cout << "Please enter an hour between 1 and 12." << endl ;
        else if( ( min_b > 59 ) || ( min_b < 0 ) )cout << "Please enter the minutes between 0 and 59." << endl ;
        else if(( sec_b > 59 ) || ( sec_b < 0 ) )cout << "Please enter the seconds between 0 and 59." << endl ;
        else break ;

    }

    ans = timeinsec( hour_b, min_b, sec_b ) - timeinsec( hour_a, min_a, sec_a ) ;
    ans = fabs( ans ) ;

    cout << " The two times are: " << ans << " seconds apart. " << endl ;

    return 0;
}

