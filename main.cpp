#include <iostream>
#include <time.h> 
#include <iomanip>
#include "QuadraticProbing.h"
#include "LinearProbing.h"

using namespace std;


void printTable(double Qprobe[], double Lprobe[] );

/** ************************************************
Team:   Patrick McBride and Zoe Millage

Compile with and run with:

    g++ -c LinearProbing.cpp
    g++ -c QuadraticProbing.cpp
    g++ main.cpp QuadraticProbing.o LinearProbing.o -o run
    ./run

************************************************ **/
int main(void)
{
    HashTable<int> Q;
    LinearHashTable<int> L;

    double Qprobe[5];
    double Lprobe[5];

    int QprobeCt, LprobeCt, insertMe;
    
    int numInsert = 10;

    srand (time(NULL));

    for (int k = 0; k < 5; k++)
    {
        LprobeCt = 0;
        QprobeCt = 0;
        
        for( int i = 0; i < 100; i++)
        {
            for (int j = 0; j < numInsert; j++)
            {   
                // the same set of random numbers is inserted into both lists
                insertMe = (rand() % 1000); 
                Q.insert(insertMe);
                L.insert(insertMe);
            }

            QprobeCt += Q.numProbe;
            LprobeCt += L.numProbe;
            Q.makeEmpty();
            L.linearMakeEmpty();
        }

        Lprobe[k] = (LprobeCt/100.0);      
        Qprobe[k] = (QprobeCt/100.0);
        
        numInsert += 10;
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