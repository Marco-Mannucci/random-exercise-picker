
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


void playSession( std::mt19937 &gen, ArrayEs_t *arrayEx, int lowerLimit, int upperLimit ) {

    // Random number range
    uniform_int_distribution<int> distrib( lowerLimit, upperLimit );

    bool session = true;        // Session loop
    int key;                    // To read Enter or Esc
    int element;                // The element that i'm going to show to the user

    cout << "Press \"Enter\" to generate the random exercise number or \"Esc\"to exit." << endl;

    while ( session ) {

        key = _getch();

        // Enter = print the random number
        if ( key == 13 ) {
            do {
                element = distrib(gen);
            } while ( checkExercise( arrayEx, element ) );

            addElements( arrayEx, element );

            cout << element << endl;

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
    ArrayEs_t *arrayEx = new ArrayEs_t;

    // Array
    arrayEx->maxCapacity = maxCapacity;
    arrayEx->numberElement = 0;
    arrayEx->array = new int[maxCapacity];

    return arrayEx;
}

void addElements( ArrayEs_t *arrayEx, int element ) {

    // Check if the array exist
    if ( arrayEx == nullptr ) {
        return;
    }

    // If the array + the new element is full i expand it
    if ( ( arrayEx->numberElement + 1 ) >= arrayEx->maxCapacity ) {
        expandArray( arrayEx );
    }

    arrayEx->array[arrayEx->numberElement] = element;

    // Refresh number of elements
    arrayEx->numberElement++;

}

void expandArray( ArrayEs_t *arrayEx ) {
    
    int newCapacity = arrayEx->maxCapacity + 1;

    // New array with new capacity
    int *newArray = new int[newCapacity];

    // Paste the elements
    for ( int i = 0; i < arrayEx->numberElement; i++ ) {
        newArray[i] = arrayEx->array[i];
    }

    // Delete old array and refresh pointer
    delete[] arrayEx->array;
    arrayEx->array = newArray;
    arrayEx->maxCapacity = newCapacity;
}

void deleteAllElements( ArrayEs_t *arrayEx ) {

    // Check if the array exist
    if ( arrayEx == nullptr ) {
        return;
    }

    arrayEx->numberElement = 0;
}

bool checkExercise( ArrayEs_t *arrayEx, int element ) {

    for ( int i = 0; i < arrayEx->numberElement; i++ ) {
        if ( arrayEx->array[i] == element ) {
            return true;
        }
    }

    return false;
}

void removeElement( ArrayEs_t *arrayEx ) {

    delete[] arrayEx->array;
    arrayEx->array = nullptr;

    arrayEx->maxCapacity = 0;
    arrayEx->numberElement = 0;

    delete arrayEx;
}