/*
    Mehmet Enes Keles
    CS/201 - 1
    21501348
*/
#include "CircularLL.h"
#include <iostream>

#ifndef PERSON_H
#define PERSON_H

using namespace std;

class Person
{
    public :
        Person( void ) ;
        ~Person( void ) ;

        void setName( const string firstName, const string lastName ) ;
        void addNumber( const int areaCode, const int number ) ;
        void deleteNumber( const int areaCode, const int number ) ;

        CircularLL getPhoneNumbers( void ) ;
        string getName() ;

        string firstName ;
        string lastName ;

    private :
        CircularLL phoneNumbers ;

};
#endif // PERSON_H

