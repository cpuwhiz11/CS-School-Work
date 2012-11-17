/* 
 * File:   SalariedEmployee.h
 * Author: Paul
 *
 * Created on December 6, 2010, 8:43 PM
 */

#include "Employee.h"

#ifndef SALARIEDEMPLOYEE_H
#define	SALARIEDEMPLOYEE_H

class SalariedEmployee  :  public Employee
{

public:
    SalariedEmployee(  const string &,  const  string &, const string &,  double = 0.0 );

    void setWeeklySalary( double );  // set weekly salary
    double getWeeklySalary()  const;  // return weekly  salary 16

    // keyword virtual  signals  intent to override
    virtual  double earnings()  const;  // calculate earnings
    virtual void print()  const;  // print SalariedEmployee object

private:

    double weeklySalary;  //  salary per week
    
};  // end class SalariedEmployee

#endif	/* SALARIEDEMPLOYEE_H */

