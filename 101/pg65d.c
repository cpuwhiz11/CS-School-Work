 void crawl( int *x , int *y , int *z , int spaces , int l , char c ) {  

  int diff ; 

  if( c == 'x' ) { 

    diff = *x + spaces ;   

    if( ( diff > 0 ) && ( ( l + spaces ) < ( 2 * l ) ) ) *x = l + spaces ; 

    if( diff < 0 ) { 

      *y = *y + diff ;  

      *x = 0 ;

    } 

    if( diff > ( 2 * 1 ) ) { 

      *x = 2 * l ; 

      *y = ( 2 * l ) + diff ; 

    } 

  } 

  if( c == 'y' ) {  

  } 

  if( c == 'z' ) { 

  } 

}
