#ifndef HOTEL_H
#define HOTEL_H

using namespace std;

class Hotel
{
    public :
        Hotel() ;
        Hotel( const Hotel &obj) ;
        ~Hotel() ;
        int isReserved( const int floor, const int room ) ;
        void init( const string name, const int numFloor, const int *numRooms ) ;
        void reservations( bool **p ) ;

        string hotelName ;
        int numOfFloors ;
        int *hotelRooms ;
        bool **reserved ;
};
#endif // HOTEL_H

