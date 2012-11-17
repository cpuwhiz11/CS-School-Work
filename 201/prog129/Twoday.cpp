//Twoday.cpp
//Includes definitions for headers in overnight.h

#include "Twoday.h"

TwoDayPackage::TwoDayPackage( string firs, string las, int num, string add, string cit, string stat, int zi, double weigh, int fe ) : Package(  firs,  las,  num,  add,  cit,  stat,  zi, weigh ) {
    setFee( fe ) ;
}


void TwoDayPackage::setFee( double num ) {

    fee = num  ;

}

double TwoDayPackage::getFee() {

    return fee ;

}

double TwoDayPackage::calcCost() {

    return ( Package::calculateCost() + getFee() ) ;

}
