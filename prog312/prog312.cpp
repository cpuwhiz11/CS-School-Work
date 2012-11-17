/*
 * File:   main.cpp
 * Author: Paul Geromini
 *
 * Created on October 1, 2010, 1:11 PM
 */

#include <iostream>
#include "Account.h"

using namespace std;

int main() {

    int bal, credit, debit ;

    while( 1 ) {

        cout << "Please enter a balance for your first account " << endl ;
        cin >> bal ;
        if( bal <= 0 ) cout << "You must enter an account balance greater than zero." << endl ;
        else break ;

    }

    Account theAccount( bal ) ;

    while( 1 ) {
        cout << "Please enter how much credit you have." << endl ;
        cin >> credit ;
        if( credit < 0 ) cout << "ERROR credit must be greater than zero." << endl ;
        else {
            theAccount.Credit( credit ) ;
            break ;
        }
    }
    while( 1 ) {
        cout << "Please enter how much debit you have." << endl ;
        cin >> debit ;
        if( debit > theAccount.getAccountBal() ) cout << "ERROR debit cannot exceed balance." << endl ;
        else if( debit < 0 ) cout << "ERROR please enter debit as a positive number." << endl ;
        else {
            theAccount.Debit( debit ) ;
            break ;
        }
        
    }
    //End for account1

        while( 1 ) {

        cout << "Please enter a balance for your second account " << endl ;
        cin >> bal ;
        if( bal <= 0 ) cout << "You must enter an account balance greater than zero." << endl ;
        else break ;

    }

    Account theAccount2( bal ) ;

    while( 1 ) {
        cout << "Please enter how much credit you have." << endl ;
        cin >> credit ;
        if( credit < 0 ) cout << "ERROR credit must be greater than zero." << endl ;
        else {
            theAccount2.Credit( credit ) ;
            break ;
        }
    }
    while( 1 ) {
        cout << "Please enter how much debit you have." << endl ;
        cin >> debit ;
        if( debit > theAccount2.getAccountBal() ) cout << "ERROR debit cannot exceed balance." << endl ;
        else if( debit < 0 ) cout << "ERROR please enter debit as a positive number." << endl ;
        else {
            theAccount2.Debit( debit ) ;
            break ;
        }

    }

    cout << "Your account balance for account 1 is: " << theAccount.getAccountBal() << endl ;
    cout << "Your account balance for account 2 is: " << theAccount2.getAccountBal() << endl ;

    return 0 ;

}


