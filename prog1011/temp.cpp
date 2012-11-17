    int faces[ 5 ] ;

    //Put all the face values in an array
    while( i != 5 ) {
        faces[ i ] = cards[ i ].getFace() ;
        i++ ;
    }

    for( i = 0 ; i < 5 ; i++ ) {
        for( j = 0 ; j < 5 ; j++ ) {
           if( faces[ i ] == faces[ j ] ) checker++ ;
        }
    }
