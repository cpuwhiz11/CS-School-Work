// Employee.cc
// Contains definitions from Employee.h

#include <iostream>
#include "Employee.h"

using namespace std ;

//Employee constructor

//Employee( string first, string last, int sal ) {

Employee :: Employee( string fname, string lname, int num ) {

    setEmployeefirst( fname ) ;
    setEmployeelast( lname ) ;
    setEmployeesalary( num ) ;

}

void Employee :: setEmployeefirst( string fname ){

    first = fname ;

    }

void Employee :: setEmployeelast( string lname ) {

    last = lname ;

}

string Employee :: getEmployeefirst() {

    return( first ) ;

}

string Employee :: getEmployeelast() {

    return( last ) ;
    
}

void Employee :: setEmployeesalary( double sal ) {

    salary = sal ;

}

double Employee :: getEmployeesalary() {

    return salary ;

}

