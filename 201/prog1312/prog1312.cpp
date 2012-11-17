//  Fig.  13.23:  figl3_23.cpp
//  Processing Employee derived-class objects  individually
// and polymorphically using dynamic binding.
#include <iostream>
#include <iomanip>
#include <vector>
#include "Employee.h"
#include "SalariedEmployee.h"
#include "HourlyEmployee.h"
#include "Date.h"

#include "CommissionEmployee.h"
#include "BasePlusCommissionEmployee.h"
using namespace std ;

void virtualViaPointer( const Employee * const ) ; // prototype
void virtualViaReference( const  Employee & ) ;  // prototype 

int main() 
{
    int i ;
    Date payday( 11, 11, 2010) ; //Day the pay calculation takes place
    
    // set floating-point output formatting
    cout << fixed << setprecision( 2 ) ;
    vector < Employee * > p_empl( 4 ) ;

    // create derived-class objects
    SalariedEmployee salariedEmployee( "John",  "Smith",  "111-11-1111",  800 ) ;
    salariedEmployee.setBirthdate( 11, 11, 1990 ) ;
    HourlyEmployee hourlyEmployee( "Karen", "Price", "222-22-2222", 16.75, 40 ) ;
    hourlyEmployee.setBirthdate( 12, 12, 1980 ) ;
    CommissionEmployee commissionEmployee( "Sue",  "Jones",  "333-33-3333",  10000,   .06 ) ;
    commissionEmployee.setBirthdate( 1, 1, 1970 ) ;
    BasePlusCommissionEmployee basePlusCommissionEmployee( "Bob",  "Lewis",  "444-44-4444",   5000,   .04,   300 ) ;
    basePlusCommissionEmployee.setBirthdate( 2, 2, 1960 ) ;

    cout << "Employees processed individually using static binding:\n\n" ;

    p_empl[ 0 ]  = &salariedEmployee;
    p_empl[ 1 ]  = &hourlyEmployee;
    p_empl[ 2 ]  = &commissionEmployee;
    p_empl[ 3 ]  = &basePlusCommissionEmployee;

    for( i = 0 ; i < 4 ; i++ ) {
        Date bday = p_empl[ i ] -> getBirth() ;
        if( bday.getMonth() == payday.getMonth() ) {
            p_empl[ i ]->print() ;
            cout << "\nEarned: $" << p_empl[ i ]->earnings() + 100 << endl ;
            cout << "Happy Birthday" << endl ;
        }
        else {
            p_empl[ i ]->print() ;
            cout << "\nEarned: $" << p_empl[ i ]->earnings() << endl ;
        }
        cout << endl ; 
    }
    
/*
    // output each Employee's information and earnings using static binding
    salariedEmployee.print() ;
    cout << "\nearned $"  << salariedEmployee.earnings() << "\n\n";
    hourlyEmployee.print();
    cout << "\nearned $"  << hourlyEmployee.earnings()  << "\n\n";
    commissionEmployee.print();
    cout << "\nearned  $"  <<  commissionEmployee.earnings()  << "\n\n";
    basePlusCommissionEmployee.print();

    cout << "\nearned $"  << basePlusCommissionEmployee.earnings() << "\n\n";
 
// create vector of four base-class pointers
    vector < Employee *  > employees( 4 ) ;

// initialize vector with Employees
    employees[ 0 ]  = &salariedEmployee;
    employees[ 1 ]  = &hourlyEmployee;
    employees[ 2 ]  = &commissionEmployee;
    employees[ 3 ]  = &basePlusCommissionEmployee;
    cout << "Employees processed polymorphically via dynamic  binding:\n\n" ;

// call  virtualViaPointer to print each Employee's information
// and earnings using dynamic binding
    cout << "Virtual  function calls made off base-class pointers:\n\n" ;
    for  ( size_t i = 0;  i < employees.size();  i++ ) virtualViaPointer( employees[ i  ]  ) ;

// call  virtualViaReference to print each Employee's  information
// and earnings using dynamic binding
    cout << "Virtual  function calls made off base-class  references:\n\n" ;
    for  ( size_t i = 0;  i   < employees.size();  i++ ) virtualViaReference(  *employees[ i  ]  ) ;  // note dereferencing


 */
}  // end main

// call  Employee virtual  functions print and earnings off a
// base-class pointer using dynamic binding

void virtualViaPointer( const Employee  * const baseClassPtr )
{

    baseClassPtr->print();
    cout << "\nearned $" << baseClassPtr->earnings()  << "\n\n";
}  // end function virtualViaPointer

// call  Employee virtual  functions print and earnings off a
// base-class  reference using dynamic  binding
void virtualViaReference( const Employee &baseClassRef )
{
    baseClassRef.print() ;
    cout << "\nearned $" << baseClassRef.earnings()  << "\n\n";
}  // end function virtualViaReference