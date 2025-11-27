#include <stdio.h>
#include <stdbool.h>

bool lemonadeChange( int* bills, int billsSize ) {
    int c5 = 0, c10 = 0;
    for ( int i = 0; i < billsSize; i++ ) {
        if ( bills[i] == 5 ) {
            c5++;
        } else if ( bills[i] == 10 ) {
            if ( c5 == NULL ) {
                return false;
            }
            c5--;
            c10++;
        } else {
            if ( c10 && c5 ) {
                c10--;
                c5--;
            } else if ( c5 >= 3 ) {
                c5 -= 3;
            }
            else {
                return false;
            }
        }
    }
    return true;
}