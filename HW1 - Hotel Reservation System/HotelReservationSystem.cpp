#include <iostream>
#include <string>

#include "HotelReservationSystem.h"

using namespace std;

// creates an empty system
HotelReservationSystem::HotelReservationSystem()
{
    numHotels = 0 ;
}

// destructor for hotel reservation system
HotelReservationSystem::~HotelReservationSystem()
{
    if ( numHotels)
        delete [] hotels ;
    numHotels = 0 ;
}

// adds a new hotel to the system
void HotelReservationSystem::addHotel( const string name, const int numFloors, const int *numRooms )
{
    // checks if hotel with the given name already exits
    int index = -1 ;
    for ( int i = 0 ; i < numHotels; ++i)
        if ( name == hotels[i].hotelName)
            index = i ;

    if ( index != -1)
    {
        cout << "Hotel " << name << " already exists" << endl;
        return ;
    }

    // substitutes the old system
    Hotel *sub = hotels ;

    // takes new place from the heap for adding the new hotel
    hotels = new Hotel[numHotels + 1] ;

    // takes old system back
    for ( int i = 0; i < numHotels ; ++i)
    {
        hotels[i].init(sub[i].hotelName, sub[i].numOfFloors, sub[i].hotelRooms ) ;
        hotels[i].reservations(sub[i].reserved) ;
    }

    // adds the given hotel to end
    hotels[numHotels].init(name, numFloors, numRooms) ;

    numHotels ++ ;

    // deletes substitute array
    if ( numHotels != 1)
        delete []sub ;

    cout<< "Hotel " << name << " is added" << endl ;
}

void HotelReservationSystem::deleteHotel( const string name )
{
    // checks if hotel with the given name already exits
    int index = -1 ;
    for ( int i = 0 ; i < numHotels; ++i)
        if ( hotels[i].hotelName == name)
            index = i ;

    if ( index == -1)
        cout<< "\nHotel "<< name << " does not exist for deletion"<< endl ;

    else
    {
        // takes every hotel except the one deleted to the substitute array
        Hotel *sub = new Hotel[numHotels - 1] ;
        for ( int k = 0, i = 0; i < numHotels; ++i)
            if( i != index)
            {
                sub[k].init(hotels[i].hotelName, hotels[i].numOfFloors, hotels[i].hotelRooms) ;
                sub[k++].reservations(hotels[i].reserved) ;
            }
        // deletes the old system
        delete [] hotels ;

        // refreshes the hotel list
        hotels = sub ;
        numHotels -- ;
        cout<< "\nHotel " << name << " is deleted" << endl;
    }
}

// arranges a reservation at the given hotel room
void HotelReservationSystem::makeReservation( const string name, const int floor, const int room )
{
    // checks if hotel with the given name already exits
    int index = -1;
    for ( int i = 0 ; i < numHotels; ++i)
        if ( hotels[i].hotelName == name)
            index = i ;

    if ( index == -1)
        cout<< "Hotel " << name << " does not exist for reservation"<< endl;

    // uses isReserved function to determine if it is possible to reserve the given place
    else
    {
        int ctrl = hotels[index].isReserved(floor - 1, room - 1);

        if ( ctrl == 0)
        {
            hotels[index].reserved[floor - 1][room - 1] = 1;
            cout << "Room "<< room << " on floor "<< floor << " is reserved at hotel "<< name <<endl;
        }
        else if ( ctrl == 1)
            cout << "Room "<< room << " on floor "<< floor << " is not available at hotel "<< name <<endl;
        else
            cout << "Room "<< room << " on floor "<< floor << " does not exist at hotel "<< name <<endl;
    }
}

// cancels the reservation at the given hotel room
void HotelReservationSystem::cancelReservation( const string name, const int floor, const int room )
{
    // checks if hotel with the given name already exits
    int index = -1;
    for ( int i = 0 ; i < numHotels; ++i)
        if ( hotels[i].hotelName == name)
            index = i ;

    if ( index == -1)
        cout<< "Hotel " << name << " does not exist for reservation"<< endl;

    // uses isReserved function to determine if it is possible to cancel the reservation at the given place
    else
    {
        int ctrl = hotels[index].isReserved(floor - 1, room - 1);

        if ( ctrl == 1)
        {
            hotels[index].reserved[floor - 1][room - 1] = 0;
            cout << "Reservation for room "<< room << " on floor "<< floor << " is cancelled at hotel "<< name <<endl;
        }
        else if ( ctrl == 0)
            cout << "Reservation for room "<< room << " on floor "<< floor << " does not exist at hotel "<< name <<endl;
        else
            cout << "Room "<< room << " on floor "<< floor << " does not exist at hotel "<< name <<endl;
    }
}

// prints out the hotels
void HotelReservationSystem::showHotels()
{

    cout << "\nName #Floors #Rooms" << endl;


    for ( int i = 0 ; i < numHotels; ++i)
    {
        int sum = 0;
        for ( int j = 0; j < hotels[i].numOfFloors; ++j)
            sum += hotels[i].hotelRooms[j] ;
        cout.width(6);
        cout << left << hotels[i].hotelName;
        cout.width(6);
        cout << left << hotels[i].numOfFloors;
        cout.width(6);
        cout << left << sum<<endl;
    }
}

// prints out the rooms in the given hotel
void HotelReservationSystem::showRooms(const string name)
{
    // checks if hotel with the given name already exits
    int index = -1;
    for ( int i = 0 ; i < numHotels; ++i)
        if ( hotels[i].hotelName == name)
            index = i ;

    if ( index == -1)
        cout<< "\nHotel "<< name << " does not exist to show rooms"<< endl;

    else
    {
        cout << "\nHotel " << hotels[index].hotelName << " rooms:" << endl;
        for ( int i = 0; i < hotels[index].numOfFloors; ++i)
        {
            cout << (i+1) << ": " ;
            for ( int j = 0; j < hotels[index].hotelRooms[i]; ++j)
                cout<< (hotels[index].reserved[i][j] ? 'x' : 'o');
            cout <<endl;
        }
        cout << endl;
    }
}

// prints out the reservations in the given hotel
void HotelReservationSystem::showReservations( const string name)
{
    // checks if hotel with the given name already exits
    int index = -1;
    for ( int i = 0; i < numHotels; ++i)
        if ( hotels[i].hotelName == name)
            index = i;

    if ( index == -1)
    {
        cout <<"\nHotel " << name <<" does not exist for showing reservations"<<endl;
        return ;
    }

    cout << "\nHotel "<< name <<" reservations:" <<endl;
    cout << "Floor  Room"<<endl;

    for ( int j = 0; j < hotels[index].numOfFloors; ++j)
        for( int k = 0; k < hotels[index].hotelRooms[j]; ++k)
            if ( hotels[index].isReserved(j,k) == 1)
            {
                cout.width(6);
                cout<< left << j+1 ;
                cout.width(6);
                cout<< left << k+1 << endl;
            }
}
