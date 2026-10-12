
#include "function.h"

#include <iostream>
#include <random>
#include <conio.h>      // To read the Esc key

using namespace std;

// ASCII code Esc = 27
// ASCII code Enter = 13
// ASCII code Y = 89
// ASCII code y = 121
// ASCII code N = 78
// ASCII code n = 110

void printBanner() {

    cout << "----------------------------------------------" << endl;
    cout << "|  GENERATORE DI NUMERI DI ESERCIZI CASUALI  |" << endl;
    cout << "----------------------------------------------" << endl;

    cout << endl;

}

void getData( int &lowerLimit, int &upperLimit ) {

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
