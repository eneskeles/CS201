/*
    Mehmet Enes Keles
    CS/201 - 1
    21501348
*/
#include "Person.h"

#ifndef SORTEDDLL_H
#define SORTEDDLL_H

class SortedDLL
{
    public :
        SortedDLL( void ) ;
        ~SortedDLL( void ) ;

        bool isEmpty( void ) const ;
        void add( const string firstName, const string lastName ) ;
        void remove( const string firstName, const string lastName ) ;

        void addNumber( const string firstName, const string lastName,
                        const int areaCode, const int number) ;
        void removeNumber( const string firstName, const string lastName,
                           const int areaCode, const int number ) ;

        void showByName( const string firstName, const string lastName) ;
        void showByNumber( const int areaCode, const int number) ;

        void printAllInformation( void ) ;

    private :
        typedef struct SortedDLLItem
        {
            Person item ;
            SortedDLLItem *next ;
            SortedDLLItem *prev ;
        } Node;

        Node *root ;
};
#endif // SORTEDDLL_H

