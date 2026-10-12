
// Random exercise generator for the CLI (handy for picking random exercises while studying)
// Enter the exercise range and any exercises to skip
// Remembers the exercises already proposed and does not propose them again
// Press Esc to start over with a new range

#include "function.h"
#include <iostream>
#include <random>
#include <string>
#include <conio.h>      // To read the Esc key

using namespace std;

int main() {

    // Get a random seed from the hardware
    random_device rd;

    // Initialize the Mersenne Twister engine with the seed
    mt19937 gen( rd() );

    // Opening banner
    cout << "---------------------------------------------" << endl;
    cout << "|      RANDOM EXERCISE NUMBER GENERATOR      |" << endl;
    cout << "---------------------------------------------" << endl;

    cout << endl;

    // Loop flags
    bool run = true;                // Main loop
    bool session = true;           // Session loop

    // Variables used inside the loops
    int lowerLimit, upperLimit;             // Limits
    int key;                              // To read Enter or Esc
    bool input;                             // Checks whether the user input is valid
    string line;
}