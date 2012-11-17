
#include "Package.h"

using namespace std ;


Package::Package( string firs, string las, int num, string add, string cit, string stat, int zi, double weigh ){

    first = firs ;
    last = las ;
    addr_num = num ;
    address = add ;
    city = cit ;
    state = stat ;
    zip = zi ;
    weight = weigh ;       

}

void Package::setName( string fir, string las ) {

    first = fir ;
    last = las ;
    return ;

}

void Package::setAddr( int num, string add ) {

    addr_num = num ; 
    address = add ;
    return ;

}

void Package::setCity( string cit ) {

    city = cit ;
    return ;

}

void Package::setState( string stat ) {
    state = stat ;
    return ;

}

void Package::setZip( int zi ) {
    zip = zi ;
    return ;

}

void Package::setWeight( double weigh ) {
    weight = weigh ;
    return ;
}

double Package::calculateCost() {

    cost = weight * 2 ;
    return cost ;

}

string Package::getName_first() {

    return first ;

}

string Package::getName_last() {

    return last ;

}

int Package::getAddr_num() {

    return addr_num ; 

}

string Package::getAddr() {

    return address ;

}

string Package::getCity() {

    return city ;

}

string Package::getState() {

    return state ;

}

int Package::getZip() {

    return zip ;
}

double Package::getWeight() {

    return weight ; 

}

void Package::printDetails_send() {

    cout << "This package is being sent by : " << first << " " << last << endl ;
    cout << "This package is going from : " << addr_num << " " << address << ", " << city << ", "<< state << ", " ;
    if( zip < 9999 ) cout << "0" << zip << endl ;
    else cout << zip << endl ;
    cout << "This package weighs: " << weight << " OZ" << endl ;

}

void Package::printDetails_rec() {

    cout << "This package is addressed to: " << first << " " << last << endl ;
    cout << "This package is going to: " << addr_num << " " << address << ", " << city << ", "<< state << ", " ;
    if( zip < 9999 ) cout << "0" << zip << endl ;
    else cout << zip << endl ;
    cout << "This package weighs: " << weight << " OZ" << endl ;

}