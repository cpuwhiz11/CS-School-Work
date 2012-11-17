/* 
 * File:   Package.h
 * Author: Paul
 *
 * Created on December 1, 2010, 3:51 PM
 */

#ifndef PACKAGE_H
#define	PACKAGE_H

#include <iostream>
using namespace std ;

class Package {

public :

    Package( string = "John", string = "Doe", int = 0, string = "Nowhere", string = "Nowhere", string = "Nowhere", int = 00000, double = 0.0 ) ; // Default constructor

    void setName( string, string ) ;
    void setAddr( int, string ) ;
    void setCity( string ) ;
    void setState( string ) ;
    void setZip( int ) ;
    void setWeight( double ) ;

    double calculateCost() ;
    string getName_first() ;
    string getName_last() ;
    int getAddr_num() ;
    string getAddr() ;
    string getCity() ;
    string getState() ;
    int getZip() ;
    double getWeight() ;

    void printDetails_rec() ;
    void printDetails_send() ;

private :

    string first ;
    string last ;
    int addr_num ;
    string address ;
    string city ;
    string state ;
    int zip ;
    double weight ;
    double cost ; 


};

#endif	/* PACKAGE_H */

