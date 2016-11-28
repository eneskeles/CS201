#include <iostream>
#include <string>

#include "Hotel.h"


using namespace std;

// simple hotel constructor
Hotel::Hotel()
{
    hotelName = "" ;
    int numOfFloors = 0 ;
}

// hotel copy constructor
Hotel::Hotel(const Hotel &obj)
{
    hotelName = obj.hotelName ;
    numOfFloors = obj.numOfFloors ;
    hotelRooms = new int[numOfFloors] ;

    for ( int i = 0; i < numOfFloors; ++i)
        hotelRooms[i] = obj.hotelRooms[i] ;

    reserved = new bool*[numOfFloors] ;

    for ( int i = 0 ; i < numOfFloors; ++i)
    {
        reserved[i] = new bool[hotelRooms[i]] ;

        for( int j = 0 ; j < hotelRooms[i]; ++j)
            reserved[i][j] = obj.reserved[i][j] ;
    }
}
// hotel destructor
Hotel::~Hotel()
{
    if ( hotelName != "" )
        delete [] hotelRooms ;

    if ( hotelName != "" )
    {
        for ( int i = 0 ; i < numOfFloors; ++i)
            delete [] reserved[i] ;

        delete [] reserved ;
    }
}

// initializes the hotel
void Hotel::init( const string name, const int numFloor, const int *numRooms)
{
    hotelName = name ;
    numOfFloors = numFloor ;

    hotelRooms = new int[numOfFloors] ;

    for ( int i = 0; i < numOfFloors; ++i)
        hotelRooms[i] = numRooms[i] ;

    reserved = new bool*[numOfFloors] ;

    for ( int i = 0 ; i < numOfFloors; ++i)
    {
        reserved[i] = new bool[hotelRooms[i]] ;

        for( int j = 0 ; j < hotelRooms[i]; ++j)
                reserved[i][j] = 0 ;

    }
}

// copies given reservation array to the this hotel's reservation array
void Hotel::reservations( bool **p )
{
    for ( int i = 0 ; i < numOfFloors; ++i)
        for( int j = 0 ; j < hotelRooms[i]; ++j)
                reserved[i][j] = p[i][j] ;

}

// checks if the given room is available or reserved
int Hotel::isReserved( const int floor, const int room )
{
    if ( floor < 0 || floor >= numOfFloors)
        return 2 ;

    if ( room < 0 || room >= hotelRooms[floor] )
        return 3 ;

    return reserved[floor][room] ;
}


