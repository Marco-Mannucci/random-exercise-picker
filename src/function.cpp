
#include "function.h"
#include <iostream>

using namespace std;

void raccogliDati( int &limiteInferiore, int &limiteMaggiore ){

    bool input = true;

    do {
        input = true;

        // Lower limit
        cout << "Inserisci il numero del primo esercizio dell'intervallo: " << endl;
        cin >> limiteInferiore;

        // Upper limit
        cout << "Inserisci il numero dell'ultimo esercizio dell'intervallo: " << endl;
        cin >> limiteMaggiore;

        if ( limiteMaggiore <= limiteInferiore ) {
            cout << "Inserisci correttamente i limiti!" << endl;

            input = false;
        }

    } while ( !input );

}