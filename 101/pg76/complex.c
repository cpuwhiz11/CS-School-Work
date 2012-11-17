#include "complex.h"

complex add_complex ( complex a, complex b ) {

  complex c ;

  c.real = a.real + b.real ;
  c.im = a.im + b.im ;

  return c ;

}

complex multiply_complex ( complex a, complex b ) {

  int temp1, temp2, temp3, temp4 ;
  complex d ;

  temp1 = a.real * b.real ;
  temp2 = a.real * b.im ;
  temp3 = a.im * b.real ;
  temp4 = a.im * b.im ;

  d.im = temp2 + temp3 ;
  d.real = temp1 - temp4 ;   

  return d ; 

}
