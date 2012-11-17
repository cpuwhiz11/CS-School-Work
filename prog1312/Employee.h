/* 
 * File:   Employee.h
 * Author: Paul
 *
 * Created on December 6, 2010, 8:34 PM
 */

#include <string>
#include "Date.h"
using namespace std ;

#ifndef EMPLOYEE_H
#define	EMPLOYEE_H

class Employee {

public :

    Employee( const string &, const string &, const string & ) ;

    void setFirstName( const string & ) ;
    string getFirstName() const ;

    void setLastName( const string & ) ;
    string getLastName() const ;

    void setSocialSecurityNumber( const string & ) ;
    string getSocialSecurityNumber() const ;

    void setBirthdate( int, int, int ) ;
    Date getBirth() ; 

    // pure virtual  function makes Employee abstract base class
     virtual double earnings() const = 0;  // pure virtual
     virtual void print() const ;  // virtual

private:
     string firstName;
     string lastName;
     string socialSecurityNumber;
     Date birthdate ;

};

#endif	/* EMPLOYEE_H */

