//Overnight.cpp
//Includes definitions for headers in overnight.h


#include "Overnight.h"

OvernightPackage::OvernightPackage( string firs, string las, int num, string add, string cit, string stat, int zi, double weigh, int fe ) : Package(  firs,  las,  num,  add,  cit,  stat,  zi, weigh ) {

    setFee( fe ) ; 

}

void OvernightPackage::setFee( double num ) {

    fee = num  ;

}

double OvernightPackage::getFee() {

    return fee ;

}

double OvernightPackage::calcCost() {

    return Package::calculateCost() + getFee() ;

}




