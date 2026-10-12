
// Random exercise generator for the CLI (handy for picking random exercises while studying)
// Enter the exercise range and any exercises to skip
// Remembers the exercises already proposed and does not propose them again
// Press Esc to start over with a new range

#include "function.h"

#include <random>

using namespace std;

int main(){

    // Get a random seed from the hardware
    random_device rd;

    // Initialize the Mersenne Twister engine with the seed
    mt19937 gen( rd() );

    printBanner();

    int lowerLimit, upperLimit;             // Limits
    ArrayEs_t *arrayEx = newArray();
    bool run = true;                        // Main loop

    while ( run ) {

        getData( lowerLimit, upperLimit );

        playSession( gen, arrayEx, lowerLimit, upperLimit );

        // Y = new session, N = exit the program
        run = askNewSession();

        // Remove all the elements from the array
        if ( !run ) {
            deleteAllElements( arrayEx );
        }

    }

    return 0;
}