/* 
 * File:   Account.h
 * Author: Paul
 *
 * Created on November 19, 2010, 2:53 PM
 */

#ifndef ACCOUNT_H
#define	ACCOUNT_H

class Account
{

public :

    Account( float = 0 ) ;

    void setAccountBalance( float ) ;
    void calculateMonthlyInterest() ;
    void modifyInterestRate( float ) ;

    void getInterest() ;
    void printBalance() ;
    static float annualInterestRate ;
    
private :

    float savingsBalance ;

};

#endif	/* ACCOUNT_H */

