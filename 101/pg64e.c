/****************************************************/
/*  Programmer: Terrance Andrew Shepherd            */
/*                                                  */
/*  Program 64: Square Deal                         */
/*                                                  */
/*  Approximate completion time:    x minutes       */
/****************************************************/
#include <stdio.h>
#include <stdlib.h>
int x, y, value;
int IsPrime( int a ) {
  /*printf( " %d \n", a  );*/
  int state = 1;
  int i;
  int result;
  if ( a > 2 ) {
    for ( i = 2; i < a; i++ ) {
      result = (a % i);
      /*printf ( "divisior %d   result %d \n ",i, result);*/
      if ( result  == 0 ){
        state = 0;
        /*printf ("state = %d \n", state );*/
        break;
      }
    }
  }
  else if ( a == 1 ) state = 0 ;
  else if ( a == 2 ) state = 1;

  return state;
}

int move_right( int **Z, int counter) {
  int i;
  for( i=0; i < counter; i++ ) {
    value ++;
    y++;
    Z[x][y] = value;
  }
  return 0;
}
int move_up( int **Z, int counter) {
  int i;
  for( i=0; i < counter; i++ ) {
    value ++;
    x--;
    Z[x][y] = value;
  }
  return 0;
}
int move_left(int **Z, int counter){
  int i;
  for( i=0; i < counter; i++ ) {
    value ++;
    y--;
    Z[x][y] = value;
  }
  return 0;
}
int move_down( int **Z, int counter) {
  int i;
  for( i=0; i < counter; i++ ) {
    value ++;
    x++;
    Z[x][y] = value;
  }
  return 0;
}
int main( int argc, char *argv[]) {

  int size, **A, i , j, counter = 1, boolean;

  printf( "\n Please enter the size of the square:");
  scanf( "%d", &size );

  x = size / 2;
  y = size / 2;

  
  A = ( int ** ) malloc( sizeof( int ) * size ) ;
  
  for ( i = 0 ; i < size ; i++ ) {
    A[i] = ( int * ) malloc( sizeof( int ) * size ) ;
  }
  
  /*  for ( i = 0 ; i < size ; i++ ) {
    for ( j = 0 ; j < size ; j++ ) {
      A[i][j] = 0 ;
    }
    }*/

  printf( "\n\n Please enter the number in which the program shall start:");
  scanf( "%d", &value );
  A[x][y] = value;

  while ( counter < size ) {
    move_right( A, counter ) ;
    move_up( A, counter ) ;
    counter ++ ;
    move_left( A, counter ) ;
    move_down( A, counter ) ;
    counter ++;
  }
  move_right( A, ( size - 1 ) );

  for ( i = 0 ; i < size ; i++ ) {
    for ( j = 0 ; j < size ; j++ ) {
      boolean = IsPrime( A[i][j] );
      if ( boolean == 1 ) printf( " %d ", A[i][j] ) ;
      if ( boolean == 0 ) printf( " *** " );
    }
    printf( "\n" ) ;
  }
  return 0;

}
