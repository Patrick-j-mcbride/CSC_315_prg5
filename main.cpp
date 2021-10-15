#include <iostream>
#include <time.h> 
#include "QuadraticProbing.h"
using namespace std;

    // Simple main
int main(void)
{
    HashTable<int> H;
    int probeCt = 0;
    int numGen = 100;
    int numInsert = 10;

    srand (time(NULL));

    for (int k = 0; k < 5; k++)
    {
            for( int i = 0; i < numGen; i++)
        {
            for (int j = 0; j < numInsert; j++)
            {   
                H.insert((int)(rand() % 1000));
            }
            probeCt += H.numProbe;
            H.makeEmpty();
        }
        cout << "Average number of probes for " << numInsert << ":   " << (probeCt/(double)numGen) << endl;
        numInsert += 10;
        numGen = numInsert * 10;
    }

    return 0;
}
