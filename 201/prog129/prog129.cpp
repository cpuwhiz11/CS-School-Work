/* 
 * File:   prog129.cpp
 * Author: Paul
 *
 * Created on December 1, 2010, 3:50 PM
 */

#include <iostream>
#include "Package.h"
#include "Twoday.h"
#include "Overnight.h"

using namespace std;

int main() {

    
    string first, last ;
    string addr, city, state ;
    int zip, addr_num ;
    double weight ;
    double cost ;

    Package pack0( "Alexander", "Melinski", 1337, "Awesome", "Bryn", "PA", 3214 , 5 ) ; 
    TwoDayPackage pack1( "Adam", "Cander", 37, "Elm", "Waltham", "MA", 4562 , 10, 2 ) ;
    OvernightPackage pack2( "Paul", "Geromini", 5, "Beatrice", "Franklin", "MA", 2038 , 20, 5 ) ;

    //It will cost 2 dollars per oz to send a package
    //Its costs an extra 2 dollars to send it by TwoDay
    //It costs an extra 5 dollars to send it overnight

    cout << "A regular Package : " << endl << endl ;
    pack0.printDetails_rec() ;
    cout << "It will cost: $ " << pack0.calculateCost() << " To send this package." << endl ;

    cout << "The Two Day Package : " << endl << endl ;
    pack1.printDetails_rec() ;
    cout << "It will cost: $ " << pack1.calcCost() << " To send this package." << endl ;

    cout << "The Overnight Package : " << endl << endl ;
    pack2.printDetails_rec() ;
    cout << "It will cost: $ " << pack2.calcCost() << " To send this package." << endl ;

    //Implementation of User entered data
/*
    //pack1.printDetails() ;
    cout << "Plese enter the name of the sender (first then last): " << endl ;
    cin >> first >> last ;

    pack1.setName( first, last ) ;

    cout << "Plese enter the street address (number then street, ignore postfixes such as street, road, etc ):" << endl ;
    cin >> addr_num >> addr ;
    pack1.setAddr( addr_num, addr ) ;

    cout << "Please enter the senders city: " << endl ;
    cin >> city ;

    pack1.setCity( city ) ;

    cout << "Please enter the sender's state (two letter abbreviation)" << endl ;
    cin >> state ;

    pack1.setState( state ) ;

    while( 1 ) {

        cout << "Please enter the sender's state zip code : " << endl ;
        cin >> zip ;

        pack1.setZip( zip ) ;
        if( zip < 999 ) cout << "Please enter a real zip code." << endl ;
        else break ;

    }

    pack1.printDetails_send() ; 

    //Recipeient
    cout << "Plese enter the name of the person to send the package to (first then last): " << endl ;
    cin >> first >> last ;

    pack2.setName( first, last ) ;

    cout << "Plese enter the recipient's street address (number then street, ignore postfixes such as street, road, etc ):" << endl ;
    cin >> addr_num >> addr ;
    pack2.setAddr( addr_num, addr ) ;

    cout << "Please enter the recipient's destination city: " << endl ;
    cin >> city ;

    pack2.setCity( city ) ;

    cout << "Please enter the recipient's destination state (two letter abbreviation)" << endl ;
    cin >> state ;

    pack2.setState( state ) ;

    cout << "Please enter the recipient's state's zip code : " << endl ;
    cin >> zip ;

    pack2.setZip( zip ) ;

    cout << "Please enter the weight of the package : " << endl ;
    cin >> weight ;

    pack2.setWeight( weight ) ;
*/
  

    return 0;

}

