
#ifndef FUNCTION_H
#define FUNCTION_H

#include "types.h"
#include <random>

// ---- Program flow ----

// Prints the opening banner
void printBanner();

// Reads the first and last exercise number from the user
void getData( int &lowerLimit, int &upperLimit );

// Runs one session: Enter generates a random exercise, Esc ends the session
void playSession( std::mt19937 &gen, ArrayEs_t *arrayEx, int lowerLimit, int upperLimit );

// Asks whether to start a new session, returns true for yes
bool askNewSession();

// ---- Dynamic array management ----

// Creates the array of the exercises already given
ArrayEs_t *newArray( int maxCapacity = 0 );

// Adds an exercise to the array, expanding it when needed
void addElements( ArrayEs_t *arrayEx, int element );

// Doubles the capacity of the array
void expandArray( ArrayEs_t *arrayEx );

// Checks if the exercise was already given
bool checkExercise( ArrayEs_t *arrayEx, int element );

// Empties the array but keeps its memory, ready for a new session
void deleteAllElements( ArrayEs_t *arrayEx );

// Frees the array and the struct, to be called once at the end of the program
void destroyArray( ArrayEs_t *arrayEx );

#endif