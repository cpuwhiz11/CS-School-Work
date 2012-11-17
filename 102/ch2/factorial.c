#include "factorial.h"

int factorial( n ) {

  int n ;

  if( n == 0 ) return 1 ;

  else return ( n * factorial( n - 1 ) ) ;

} 
