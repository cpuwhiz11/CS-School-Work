// Account.cc
// Contains definitions in Account.h

#include <iostream>
#include "Account.h"
using namespace std ;


Account :: Account( int Amount ) {

    setAccountBal( Amount ) ;

}

void Account :: setAccountBal( int Amount )
{

    AccountBal = Amount ;

}

void Account :: Credit( int Amount ) {

    AccountBal = AccountBal + Amount ;

    }


void Account :: Debit( int Amount ) {

    AccountBal = AccountBal - Amount ;

}

int Account :: getAccountBal() {

    return AccountBal ; 

}



