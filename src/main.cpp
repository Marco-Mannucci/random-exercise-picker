
// Random exercise generator for the CLI (handy for picking random exercises while studying)
// Enter the exercise range, then press Enter to get a random exercise number
// Remembers the exercises already given in the session and does not propose them again
// Press Esc to end the session and, if you want, start a new one with a new range

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

        // Every session starts with an empty array
        deleteAllElements( arrayEx );

        playSession( gen, arrayEx, lowerLimit, upperLimit );

        // Y = new session, N = exit the program
        run = askNewSession();

    }

    // Free the memory before leaving
    destroyArray( arrayEx );
    arrayEx = nullptr;

    return 0;
}