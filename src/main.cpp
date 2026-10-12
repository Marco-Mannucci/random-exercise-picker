
// Random exercise generator for the CLI (handy for picking random exercises while studying)
// Enter the exercise range and any exercises to skip
// Remembers the exercises already proposed and does not propose them again
// Press Esc to start over with a new range

#include <random>

#include "function.h"

using namespace std;

int main(){

    // Get a random seed from the hardware
    random_device rd;

    // Initialize the Mersenne Twister engine with the seed
    mt19937 gen( rd() );

    printBanner();

    int lowerLimit, upperLimit;             // Limits
    bool run = true;                        // Main loop

    while ( run ) {

        getData( lowerLimit, upperLimit );

        eseguiSessione( gen, lowerLimit, upperLimit );

        // Y = new session, N = exit the program
        run = askNewSession();

    }

    return 0;
}