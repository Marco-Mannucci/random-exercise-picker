
#ifndef FUNCTION_H
#define FUNCTION_H

#include <random>

// Prints the opening banner
void printBanner();

// Reads the first and last exercise number from the user
void getData( int &lowerLimit, int &upperLimit );

// Runs one session: Enter generates a random exercise, Esc ends the session
void playSession( std::mt19937 &gen, int lowerLimit, int upperLimit );

// Asks whether to start a new session, returns true for yes
bool askNewSession();

#endif