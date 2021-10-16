/******************************************************************************
The only difference between the linear and Quadratic Probing functions are
the names and the findPos( hashedObj x ) functions
******************************************************************************/


#ifndef LINEAR_PROBING_H
#define LINEAR_PROBING_H

#include <vector>
#include <string>
#include <iostream>
using namespace std;

int linearNextPrime ( int n );

// QuadraticProbing Hash table class
//
// CONSTRUCTION: an approximate initial size or default of 101
//
// ******************PUBLIC OPERATIONS*********************
// bool insert( x )       --> Insert x
// bool remove( x )       --> Remove x
// bool contains( x )     --> Return true if x is present
// void makeEmpty( )      --> Remove all items
// int hash( string str ) --> Global method to hash strings

template <typename HashedObj>
class LinearHashTable
{
public:

    int numProbe;

    explicit LinearHashTable ( int size = 101 ) : array ( linearNextPrime ( size ) )
    {
        linearMakeEmpty ( );
    }

    bool linearContains ( const HashedObj& x ) const
    {
        return isActive ( linearFindPos ( x ) );
    }

    void linearMakeEmpty ( )
    {
        currentSize = 0;
        for ( int i = 0; i < array.size ( ); i++ )
            array[ i ].info = EMPTY;
    }

    bool insert ( HashedObj x )
    {
        // Insert x as active
        int currentPos = linearFindPos ( x );
        if ( linearIsActive ( currentPos ) )
            return false;

        array[ currentPos ] = LinearHashEntry ( x , ACTIVE );

        // Rehash; see Section 5.5
        if ( ++currentSize > array.size ( ) / 2 )
            linearRehash ( );

        return true;
    }

    bool linearRemove ( const HashedObj& x )
    {
        int currentPos = linearFindPos ( x );
        if ( !linearIsActive ( currentPos ) )
            return false;

        array[ currentPos ].info = DELETED;
        return true;
    }


    enum EntryType { ACTIVE , EMPTY , DELETED };

private:
    struct LinearHashEntry
    {
        HashedObj element;
        EntryType info;
        LinearHashEntry ( const HashedObj& e = HashedObj ( ) , EntryType i = EMPTY )
            : element ( e ) , info ( i )
        {
        }
    };

    vector<LinearHashEntry> array;
    int currentSize;


    bool linearIsActive ( int currentPos ) const
    {
        return array[ currentPos ].info == ACTIVE;
    }


    // this is the modified findPos
    int linearFindPos ( HashedObj x )
    {
        int offset = 1;
        int currentPos = linearMyhash ( x );
        int probeCount = 1;

        /* This just iterates currentPos until a valid value is found
           currentPos will wrap around if it hits the end of the array */
        while ( ( array[ currentPos ].info != EMPTY ) && ( array[ currentPos ].element != x ) )
        {
            currentPos++;     // increment currentPos
            probeCount++;     // increment probCount

            if ( currentPos >= array.size ( ) )
                currentPos = 0;

        }

        numProbe = probeCount;

        return currentPos;
    }

    void linearRehash ( )
    {
        vector<LinearHashEntry> oldArray = array;

        // Create new double-sized, empty table
        array.resize ( linearNextPrime ( 2 * oldArray.size ( ) ) );
        for ( int j = 0; j < array.size ( ); j++ )
            array[ j ].info = EMPTY;

        // Copy table over
        currentSize = 0;
        for ( int i = 0; i < oldArray.size ( ); i++ )
            if ( oldArray[ i ].info == ACTIVE )
                insert ( oldArray[ i ].element );
    }
    int linearMyhash ( const HashedObj& x ) const
    {
        int hashVal = x;

        hashVal %= array.size ( );
        if ( hashVal < 0 )
            hashVal += array.size ( );

        return hashVal;
    }
};

int linearHash ( const string& key );
int linearHash ( int key );

#endif
