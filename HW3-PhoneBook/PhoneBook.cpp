/*
    Mehmet Enes Keles
    CS/201 - 1
    21501348
*/
#include <iostream>
#include "PhoneBook.h"

using namespace std ;

// CONSTRUCTOR AND DESTRUCTOR IS EMPTY BECAUSE PHONEBOOK CLASS USES
// A SORTEDDLL INSTANCE WHICH WILL AUTOMATICALLY BE CREATED AND DELETED
// YOU CAN CHECK OUT CONSTRUCTOR AND DESTRUCTOR OF SORTEDDLL CLASS

PhoneBook::PhoneBook( void ){}

PhoneBook::~PhoneBook( void ){}

void PhoneBook::addPerson( const string firstName, const string lastName )
{
    people.add(firstName, lastName) ;
}

void PhoneBook::deletePerson( const string firstName, const string lastName )
{
    people.remove( firstName, lastName) ;
}

void PhoneBook::addPhoneNumber( const string firstName, const string lastName,
                                const int areaCode, const int number)
{
    people.addNumber(firstName, lastName, areaCode, number ) ;
}

void PhoneBook::deletePhoneNumber( const string firstName, const string lastName,
                                   const int areaCode, const int number)
{
    people.removeNumber(firstName, lastName, areaCode, number ) ;
}

void PhoneBook::showPerson( const string firstName, const string lastName)
{
    people.showByName(firstName, lastName) ;
}

void PhoneBook::showPhoneNumber( const int areaCode, const int number )
{
    people.showByNumber(areaCode, number );
}

void PhoneBook::showAll( void )
{
    people.printAllInformation() ;
}
