
#ifndef FUNCTION_H
#define FUNCTION_H

#include <random>

// ASCII code Esc = 27
// ASCII code Enter = 13
// ASCII code Y = 89
// ASCII code y = 121
// ASCII code N = 78
// ASCII code n = 110

void getData( int &lowerLimit, int &upperLimit );

void printBanner();

void playSession( std::mt19937 &gen, int lowerLimit, int upperLimit );

bool askNewSession();

#endif