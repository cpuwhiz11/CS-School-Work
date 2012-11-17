/* 
 * File:   HourlyEmployee.h
 * Author: Paul
 *
 * Created on December 6, 2010, 8:51 PM

*/

#include  "Employee.h"


#ifndef HOURLYEMPLOYEE_H
#define	HOURLYEMPLOYEE_H

class HourlyEmployee  :  public  Employee
{

public:

    static  const  int hoursPerWeek = 168 ;  // hours in one week

    HourlyEmployee( const string &, const string &, const string &, double = 0.0, double = 0.0 ) ;

    void setWage( double ) ;  // set hourly wage
    double getWage()  const ;  //  return hourly wage 18

    void setHours( double ) ; // set hours worked
    double getHours()  const ;  // return hours worked 21

// keyword virtual  signals  intent to override
    virtual  double earnings()  const ;  // calculate earnings
    virtual  void print()  const ;  // print HourlyEmployee object

private:
    double wage ;  // wage per hour
    double hours ;  // hours worked for week

} ;  // end class HourlyEmployee

#endif	/* HOURLYEMPLOYEE_H */

