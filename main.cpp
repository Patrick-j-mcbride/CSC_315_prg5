#include <iostream>
#include <time.h> 
#include "QuadraticProbing.h"
#include "LinearProbing.h"
#include <iomanip>
using namespace std;


void printTable(double Qprobe[], double Lprobe[] );


    // Simple main
int main(void)
{
    HashTable<int> Q;
    LinearHashTable<int>  L;
    double Qprobe[5];
    double Lprobe[5];
    int QprobeCt = 0;
    int LprobeCt = 0;
    int numGen = 100;
    int numInsert = 10;

    srand (time(NULL));

    for (int k = 0; k < 5; k++)
    {
        LprobeCt = 0;
        QprobeCt = 0;
            for( int i = 0; i < numGen; i++)
        {
            for (int j = 0; j < numInsert; j++)
            {   
                Q.insert((int)(rand() % 1000));
                L.insert((int)(rand() % 1000));
            }
            QprobeCt += Q.numProbe;
            Q.makeEmpty();
            LprobeCt += L.numProbe;
            L.linearMakeEmpty();
        }
        Lprobe[k] = (LprobeCt/(double)numGen);
        numInsert += 10;        
        Qprobe[k] = (QprobeCt/(double)numGen);
        numInsert += 10;
        numGen = numInsert * 10;
    }

    printTable(Qprobe, Lprobe);

    return 0;
}

void printTable(double Qprobe[], double Lprobe[] )
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
        cout << setfill(' ') << setw(10) << left << (Qprobe[i]);
        cout << "|";
    }
    cout << endl << setw(56) << setfill('_') << '_' << endl << endl << endl;

    cout << endl << endl << right << setfill(' ') << setw(35) << "Linear Probing";
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
        cout << setfill(' ') << setw(10) << left << (Lprobe[i]);
        cout << "|";
    }
    cout << endl << setw(56) << setfill('_') << '_' << endl << endl << endl;

}