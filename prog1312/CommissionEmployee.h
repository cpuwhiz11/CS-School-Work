/* 
 * File:   CommissionEmployee.h
 * Author: Paul
 *
 * Created on December 6, 2010, 9:03 PM
 */

#include  "Employee.h"

#ifndef COMMISSIONEMPLOYEE_H
#define	COMMISSIONEMPLOYEE_H

// Employee class definition

class CommissionEmployee  :  public Employee
{
public:

    CommissionEmployee( const string &,  const string &, const string &,  double = 0.0,  double = 0.0 );

    void setCommissionRate( double );  // set commission  rate
    double getCommissionRate()  const;  //  return commission  rate 16

    void setGrossSales( double );  // set gross sales amount
    double getGrossSales()  const;  //  return gross  sales amount 19

// keyword virtual  signals  intent to override
    virtual  double earnings()  const;  // calculate earnings
    virtual void print()  const;  // print CommissionEmployee object

private:

    double grossSales;  // gross weekly  sales
    double commissionRate;  // commission percentage
    
};  // end class CommissionEmployee

#endif	/* COMMISSIONEMPLOYEE_H */

