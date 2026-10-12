
#ifndef FUNCTION_H
#define FUNCTION_H

#include "types.h"
#include <random>

// Function to manage Dynamic arrays
ArrayEs_t *newArray( int maxCapacity );
void removeElement( ArrayEs_t *array );
void expandArray( ArrayEs_t *array );
void addElements( ArrayEs_t *array, int element );

// Prints the opening banner
void printBanner();

// Reads the first and last exercise number from the user
void getData( int &lowerLimit, int &upperLimit );

// Runs one session: Enter generates a random exercise, Esc ends the session
void playSession( std::mt19937 &gen, int lowerLimit, int upperLimit );

// Asks whether to start a new session, returns true for yes
bool askNewSession();

// Check if the exercise was already given
bool checkExercise( ArrayEs_t *array, int element );

#endif