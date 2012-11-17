// Account.cpp
// Contains definitions for headers in Account.h

#include "Account.h"
#include <iostream>

using namespace std ;

float Account::annualInterestRate = 0.0 ;

Account::Account( float bal ) {

    setAccountBalance( bal ) ;
    return ;

}

void Account::setAccountBalance( float bal ) {

    if( bal < 0 ) bal = 0 ;
    savingsBalance = bal ; 
    return ;
    
}

void Account::getInterest() {

    float temp ;
    temp = ( savingsBalance * annualInterestRate ) / 12 ;
    cout << "$" << temp << endl ;
    return ;

}

void Account::calculateMonthlyInterest() {

    float temp ;

    temp = ( annualInterestRate * savingsBalance ) / 12 ;
    savingsBalance = temp + savingsBalance ;

    return ;
}

void Account::printBalance() {

    cout << "$" << savingsBalance << endl ;
    return ;

}