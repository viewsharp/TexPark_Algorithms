#include <iostream>
#include <string>
#include <cassert>
#include "stringset.h"

using namespace std;

int main() {
    StringSet hashTable;

    char command = 0;
    string key;
    while( std::cin >> command >> key ) {
        switch( command ) {
            case '?':
                std::cout << ( hashTable.has( key ) ? "OK" : "FAIL" ) << std::endl;
                break;
            case '+':
                std::cout << ( hashTable.add( key ) ? "OK" : "FAIL" ) << std::endl;
                break;
            case '-':
                std::cout << ( hashTable.remove( key ) ? "OK" : "FAIL" ) << std::endl;
                break;
            default:
                assert( false );
        }
    }

    return 0;
}