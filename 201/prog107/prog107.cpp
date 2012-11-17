/* 
 * File:   prog107.cpp
 * Author: Paul
 *
 * Created on November 19, 2010, 2:52 PM
 */

#include <iostream>
#include "Account.h"

using namespace std;

int main() {

    Account saver1( 2000 ) ;
    Account saver2( 3000 ) ;

    Account::annualInterestRate = 0.03 ;
    //saver1.modifyInterestRate( 0.03 ) ;
    //saver2.modifyInterestRate( 0.03 ) ;

    cout << "The accounts earn the following interest in one month:" << endl ;
    saver1.getInterest() ;
    saver2.getInterest() ;

    saver1.calculateMonthlyInterest() ;
    saver2.calculateMonthlyInterest() ;

    cout << "The account balances are:" << endl ;
    cout << "Saver1 : " << endl ;
    saver1.printBalance() ;
    cout << "Saver2 : " << endl ;
    saver2.printBalance() ;

    Account::annualInterestRate = 0.04 ;
    //saver1.modifyInterestRate( 0.04 ) ;
    //saver2.modifyInterestRate( 0.04 ) ;

    cout << "The accounts earn the following interest in one month:" << endl ;
    saver1.getInterest() ;
    saver2.getInterest() ;

    saver1.calculateMonthlyInterest() ;
    saver2.calculateMonthlyInterest() ;

    cout << "The account balances are:" << endl ;
    cout << "Saver1 : " << endl ;
    saver1.printBalance() ;
    cout << "Saver2 : " << endl ;
    saver2.printBalance() ;

    return 0;
}

