
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

// ---- Program flow ----

void printBanner() {

    cout << "----------------------------------------------" << endl;
    cout << "|      RANDOM EXERCISE NUMBER GENERATOR      |" << endl;
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

        if ( lowerLimit >= upperLimit ) {
            cout << "Enter the limits correctly!" << endl;

            input = false;
        }

    } while ( !input );
}

void playSession( std::mt19937 &gen, ArrayEs_t *arrayEx, int lowerLimit, int upperLimit ) {

    // Random number range
    uniform_int_distribution<int> distrib( lowerLimit, upperLimit );

    // How many exercises there are in the range
    long long totalExercises = static_cast<long long>( upperLimit ) - lowerLimit + 1;

    bool session = true;        // Session loop
    int key;                    // To read Enter or Esc
    int element;                // The exercise number shown to the user

    cout << "Press \"Enter\" to generate the random exercise number or \"Esc\" to exit." << endl;

    while ( session ) {

        key = _getch();

        // Enter = generate and print a random number
        if ( key == 13 ) {
            // All the exercises of the range were already given
            if ( arrayEx->numberElement >= totalExercises ) {
                cout << "All the exercises in this range have been given!" << endl;
                session = false;
            }
            else {
                // Draw again until the exercise has not been given yet
                do {
                    element = distrib( gen );
                } while ( checkExercise( arrayEx, element ) );

                addElements( arrayEx, element );

                cout << element << endl;
            }
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

        // Y or y
        if ( key == 89 || key == 121 ) {
            return true;
        }
        // N or n
        else if ( key == 78 || key == 110 ) {
            return false;
        }
        else {
            cout << "You can only enter \"Y\" or \"N\"; please try again!" << endl;
        }
    }
}

// ---- Dynamic array management ----

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

    // Check that the array exists
    if ( arrayEx == nullptr ) {
        return;
    }

    // If the array is full, expand it
    if ( ( arrayEx->numberElement + 1 ) >= arrayEx->maxCapacity ) {
        expandArray( arrayEx );
    }

    arrayEx->array[arrayEx->numberElement] = element;

    // Update the number of elements
    arrayEx->numberElement++;
}

void expandArray( ArrayEs_t *arrayEx ) {

    // Double the capacity (an empty array starts from 1)
    int newCapacity;

    if ( arrayEx->maxCapacity == 0 ) {
        newCapacity = 1;
    }
    else {
        newCapacity = arrayEx->maxCapacity * 2;
    }

    // New array with the new capacity
    int *newArray = new int[newCapacity];

    // Copy the elements
    for ( int i = 0; i < arrayEx->numberElement; i++ ) {
        newArray[i] = arrayEx->array[i];
    }

    // Delete the old array and update the pointer
    delete[] arrayEx->array;
    arrayEx->array = newArray;
    arrayEx->maxCapacity = newCapacity;
}

bool checkExercise( ArrayEs_t *arrayEx, int element ) {

    // Check that the array exists
    if ( arrayEx == nullptr ) {
        return false;
    }

    for ( int i = 0; i < arrayEx->numberElement; i++ ) {
        if ( arrayEx->array[i] == element ) {
            return true;
        }
    }

    return false;
}

void deleteAllElements( ArrayEs_t *arrayEx ) {

    // Check that the array exists
    if ( arrayEx == nullptr ) {
        return;
    }

    // Only reset the counter, the memory is kept for the next session
    arrayEx->numberElement = 0;
}

void destroyArray( ArrayEs_t *arrayEx ) {

    // Check that the array exists
    if ( arrayEx == nullptr ) {
        return;
    }

    // First the inner array, then the struct
    delete[] arrayEx->array;
    delete arrayEx;
}