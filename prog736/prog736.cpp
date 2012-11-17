/* 
 * File:   prog736.cpp
 * Author: Paul
 *
 * Created on October 24, 2010, 3:14 PM
 */

#include <iostream>
#include <string>

using namespace std;

void string_reverse( string &str) {

    int n = str.size() ;

    if( n == 1 ) cout << str << endl ;

    else {

        cout << str[ n - 1 ] ;
        string temp_str = str.substr( 0, ( n - 1 ) ) ;
        string_reverse( temp_str ) ;

    }

}

int main() {

    string str ;

    cout << "Please enter a string." << endl ;
    cin >> str ;

    cout << "The string you entered is: " << str << endl ;
    cout << "The string reversed is: " ;
    string_reverse( str ) ;

    return 0 ;
    
}

