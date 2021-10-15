#include <iostream>
#include <time.h> 
#include "QuadraticProbing.h"
#include <iomanip>
using namespace std;

struct otp
{
    double Qprobe[5];
    int insers[5];
    double Lprobe[5];
};

void printTable(otp ot);


    // Simple main
int main(void)
{
    otp ot;
    HashTable<int> H;
    int probeCt = 0;
    int numGen = 100;
    int numInsert = 10;

    srand (time(NULL));

    for (int k = 0; k < 5; k++)
    {
        probeCt = 0;
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
        ot.insers[k] = numInsert;
        ot.Qprobe[k] = (probeCt/(double)numGen);
        numInsert += 10;
        numGen = numInsert * 10;
    }

    printTable(ot);

    return 0;
}

void printTable(otp ot)
{
    cout << endl << endl << setw(35) << "Quadratic Probing";
    cout << endl << setw(56) << setfill('_') << "_" << endl;
    cout << "|";
    for (int i = 0; i < 5; i++ )
    {
        cout << setfill(' ') << setw(10) << left << ((1+i)*10);
        cout << "|";
    }
    cout << endl;
    cout << setw(56) << setfill('-') << "-" << endl;
    cout << "|";
    for (int i = 0; i < 5; i++ )
    {
        cout << setfill(' ') << setw(10) << left << (ot.Qprobe[i]);
        cout << "|";
    }
    cout << endl << setw(56) << setfill('_') << '_' << endl << endl << endl;
}