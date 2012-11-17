/* 
 * File:   Overnight.h
 * Author: Paul
 *
 * Created on December 2, 2010, 12:23 PM
 */

#include "Package.h"

#ifndef OVERNIGHT_H
#define	OVERNIGHT_H

class OvernightPackage : public Package
{

public :

   OvernightPackage( string = "John", string = "Doe", int = 0, string = "Nowhere", string = "Nowhere", string = "Nowhere", int = 00000, double = 0.0, int = 0 ) ; // Default constructor

    void setFee( double ) ;
    double getFee() ;
    double calcCost() ;

private :

    double fee ;


};

#endif	/* OVERNIGHT_H */

