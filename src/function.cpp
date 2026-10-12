
#include "function.h"
#include <iostream>

using namespace std;

void takeData( int &lowerLimit, int &upperLimit ){

    bool input = true;

    do {
        input = true;

        // Lower limit
        cout << "Enter the number of the first exercise in the range:" << endl;
        cin >> lowerLimit;

        // Upper limit
        cout << "Enter the number of the last exercise in the range:" << endl;
        cin >> upperLimit;

        if ( lowerLimit <= upperLimit ) {
            cout << "Enter the limits correctly!" << endl;

            input = false;
        }

    } while ( !input );

}