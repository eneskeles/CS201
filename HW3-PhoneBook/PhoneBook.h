/*
    Mehmet Enes Keles
    CS/201 - 1
    21501348
*/
#include "SortedDLL.h"

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

using namespace std ;

class PhoneBook
{
    public :
        PhoneBook( void ) ;
        ~PhoneBook( void ) ;

        void addPerson( const string firstName, const string lastName ) ;
        void deletePerson( const string firstName, const string lastName) ;

        void addPhoneNumber( const string firstName, const string lastName,
                             const int areaCode, const int number) ;

        void deletePhoneNumber( const string firstName, const string lastName,
                                const int areaCode, const int number) ;

        void showPerson( const string firstName, const string lastName ) ;
        void showPhoneNumber( const int areaCode, const int number ) ;
        void showAll( void ) ;

    private :
        SortedDLL people ;

};
#endif // PHONEBOOK_H
