
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


void playSession( std::mt19937 &gen, int lowerLimit, int upperLimit ) {

    // Random number range
    uniform_int_distribution<int> distrib( lowerLimit, upperLimit );

    bool session = true;        // Session loop
    int key;                    // To read Enter or Esc

    cout << "Press \"Enter\" to generate the random exercise number or \"Esc\"to exit." << endl;

    while ( session ) {

        key = _getch();

        // Enter = print the random number
        if ( key == 13 ) {
            cout << distrib( gen ) << endl;
        }
        // Esc = leave this session
        else if ( key == 27 ) {
            session = false;
        }
        // Invalid key
        else {
            cout << "Incorrect key, please re-enter!" << endl;
        }
    }
}

bool askNewSession() {

    int key;

    cout << "Start a new session? [Y/N]" << endl;

    while ( true ) {

        key = _getch();

        // Y
        if ( key == 89 || key == 121 ) {
            return true;
        }
        // N
        else if ( key == 78 || key == 110 ) {
            return false;
        }
        else {
            cout << "You can only enter \"Y\" or \"N\"; please try again!" << endl;
        }
    }
}

ArrayEs_t *newArray( int maxCapacity ) {

    // Struct
    ArrayEs_t *array = new ArrayEs_t;

    // Array
    array->maxCapacity = maxCapacity;
    array->numberElement = 0;
    array->array = new ArrayEs_t[maxCapacity];
}

void removeElement( ArrayEs_t *array ) {

    delete[] array->array;
    array->array = nullptr;

    array->maxCapacity = 0;
    array->numberElement = 0;

    delete array;
}

void expandArray( ArrayEs_t *array ) {
    
    int newCapacity = array->maxCapacity + 1;

    // New array with new capacity
    ArrayEs_t *newArray = new ArrayEs_t[newCapacity];

    // Paste the elements
    for ( int i = 0; i < array->maxCapacity; i++ ) {
        newArray[i] = array->array[i];
    }

    // Delete old array e refresh pointer
    delete[] array->array;
	array->array = newArray;
	array->maxCapacity = newCapacity;
}