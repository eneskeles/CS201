/*
    Mehmet Enes Keles
    CS/201 - 1
    21501348
*/
#include <iostream>
#include <vector>
#include <string>

#include "Person.h"

using namespace std;

Person::Person( void )
{
    firstName = "" ;
    lastName = "" ;
}

Person::~Person( void )
{
    firstName = "" ;
    lastName = "" ;
}

void Person::setName( const string firstName, const string lastName)
{
    this->firstName = firstName ;
    this->lastName = lastName ;
}

void Person::addNumber( const int areaCode, const int number)
{
    phoneNumbers.add( areaCode, number) ;
}

void Person::deleteNumber( const int areaCode, const int number)
{
    phoneNumbers.remove( areaCode, number) ;
}

CircularLL Person::getPhoneNumbers( void )
{
    return phoneNumbers ;
}

string Person::getName()
{
    return firstName + " " + lastName ;
}
