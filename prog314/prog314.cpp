/* 
 * File:   main.cpp
 * Author: Paul
 *
 * Created on October 2, 2010, 8:29 PM
 */

#include <iostream>
#include "Employee.h"

using namespace std ;

int main() {

    string fname, lname ;
    double sal ;
  //  Employee Emp1( void ), Emp2( void ) ;

    while( 1 ) {

        cout << "Please enter the first name of the employee." << endl ;
        cin >> fname ;
        break ;

    }
    while( 1 ) {

        cout << "Please enter the last name of the employee." << endl ;
        cin >> lname ;
        break ; 

    }
    while( 1 ) {

        cout << "Please enter the salary for: " << fname << " " << lname << " Do not use commas." << endl ;
        cin >> sal ;
        if( sal < 0 ) cout << "You must enter a positive number or zero for a salary." << endl ;
        else break ;
    }

    Employee Emp1( fname, lname, sal ) ;

    // Finish for Employee 1

        while( 1 ) {

        cout << "Please enter the first name of the employee." << endl ;
        cin >> fname ;

        break ;

    }
    while( 1 ) {

        cout << "Please enter the last name of the employee." << endl ;
        cin >> lname ;
        break ;

    }
    while( 1 ) {

        cout << "Please enter the salary for: " << fname << " " << lname << " Do not use commas." << endl ;
        cin >> sal ;
        if( sal < 0 ) cout << "You must enter a positive number or zero for a salary." << endl ;
        else break ;
    }

    Employee Emp2( fname, lname, sal ) ;
    
    // Display Salary of both Employees
    cout << "The salary of " << Emp1.getEmployeefirst() << " " << Emp1.getEmployeelast() << " is: " << Emp1.getEmployeesalary() << endl ;
    cout << "The salary of " << Emp2.getEmployeefirst() << " " << Emp2.getEmployeelast() << " is: " << Emp2.getEmployeesalary() << endl ;

    //Give both employees a 10% raise.

    sal = Emp1.getEmployeesalary() + ( .10 * Emp1.getEmployeesalary() ) ;
    Emp1.setEmployeesalary( sal ) ;

    sal = Emp2.getEmployeesalary() + ( .10 * Emp2.getEmployeesalary() ) ;
    Emp2.setEmployeesalary( sal ) ;

    //Display salaries again
    cout << "The salary of " << Emp1.getEmployeefirst() << " " << Emp1.getEmployeelast() << " after the raise is: " << Emp1.getEmployeesalary() << endl ;
    cout << "The salary of " << Emp2.getEmployeefirst() << " " << Emp2.getEmployeelast() << " after the raise is: " << Emp2.getEmployeesalary() << endl ;


    return 0;
}

