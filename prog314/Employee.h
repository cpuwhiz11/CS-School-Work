/* 
 * File:   Employee.h
 * Author: Paul
 *
 * Created on October 2, 2010, 8:29 PM
 */

#include <string>
using namespace std ;

//Account class definition
class Employee
{

public :

    Employee( string, string, int ) ;

    void setEmployeefirst( string ) ; // sets first name
    void setEmployeelast( string ) ; // sets last name
    string getEmployeefirst() ; // returns employee's first name
    string getEmployeelast() ; // returns employee's last name

    void setEmployeesalary( double ) ; // sets employees salary
    double getEmployeesalary() ; // returns employees salary

private :

    string first ;
    string last ;
    int salary  ;

} ; // Ends class Employee
