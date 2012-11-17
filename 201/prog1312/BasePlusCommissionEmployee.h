/* 
 * File:   BasePlusCommissionEmployee.h
 * Author: Paul
 *
 * Created on December 6, 2010, 9:09 PM
 */

#include "CommissionEmployee.h"

#ifndef BASEPLUSCOMMISSIONEMPLOYEE_H
#define	BASEPLUSCOMMISSIONEMPLOYEE_H

class BasePlusCommissionEmployee  :  public CommissionEmployee
{
public :
    BasePlusCommissionEmployee(  const string &,  const string &, const string &,  double = 0.0,  double = 0.0,  double = 0.0 );

    void setBaseSalary( double );  // set base salary
    double getBaseSalary()  const;  // return base salary 16

// keyword virtual  signals  intent to override
    virtual  double earnings()  const;  // calculate earnings
    virtual void print()  const;  // print BasePlusCommissionEmployee object
    
private:

    double  baseSalary;  // base salary per week

}; // end class BasePlusCommissionEmployee


#endif	/* BASEPLUSCOMMISSIONEMPLOYEE_H */

