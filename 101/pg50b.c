/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Program 50: Non-polymorphic Linked List                     */
/*                                                             */
/* Approximate completion time: 40 minutes                     */
/***************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct node { int num ; struct node * next ; } NODE ;

void printlist ( NODE * l ) {

  if( l == NULL ) return ;

  printf( " %d", l -> num ) ;

  printlist( l -> next ) ;

 return ;

}

int main( int argc, char *argv[] ) {

  NODE *p ; 
  NODE *old ;
  NODE *first ; 

  int num, i = 1 ;

  p = NULL ;

  printf( "Please enter a number. " ) ;
  
  while( scanf( "%d", &num ) != EOF ) { 
  
    p = ( NODE * ) malloc ( sizeof( NODE ) ) ; 
    
    printf( "Please enter a number. " ) ;
    
    p -> num = num ;
    
    p -> next = NULL ;
    
    if ( i > 1 ) old -> next = p ;
    
    else first = p ; 
    
    old = p ;
    
    i++ ;
  
  }

  printf( "\n\n" ) ;
 
  printlist( first ) ;
  
  return  0 ;

}

