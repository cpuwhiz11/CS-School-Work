/* 
 * File:   Account.h
 * Author: Paul
 *
 * Created on October 1, 2010, 1:13 PM
 */

#include <string>
using namespace std ;

//Account class definition
class Account
{

public :

    Account( int ) ;

    void setAccountBal( int ) ; // sets balance of the account ;
    int getAccountBal() ; // Gets balance
 
    void Credit( int ) ; // Amount of Credit (add to balance)
    void Debit( int ) ; // Amount of Debit (subtract from balance)

private :

    int AccountBal  ;

} ; // Ends class Account



