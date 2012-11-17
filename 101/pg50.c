/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Program 50: Non-polymorphic Linked List                     */
/*                                                             */
/* Approximate completion time: 30 minutes                     */
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
  NODE *temp ;
  int n, i, num ;

  printf( "Please enter the number of nodes you would like." ) ;
  scanf( "%d", &n ) ;

  p = NULL ;

  for( i = 1 ; i <= n ; i++ ) {
    
    temp = ( NODE * ) malloc ( sizeof( NODE ) ) ; 
    printf( "Please enter a number." ) ;
    scanf( "%d", &num ) ; 
    if( num == -1 ) break ;   
    temp -> num = num ;
    temp -> next = p ;
    p = temp ;
    
  }

  printf( "\n\n" ) ;
  printlist( p ) ;
  
  return  0 ;

}

