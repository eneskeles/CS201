/*
    Mehmet Enes Keles
    CS/201 - 1
    21501348
*/
#include <iostream>
#include "SortedDLL.h"

using namespace std;

SortedDLL::SortedDLL()
{
    root = NULL ;
}

SortedDLL::~SortedDLL()
{
    /*
    while( !isEmpty())
    {
        Node *temp = root->next ;
        delete root ;
        root = NULL ;
        root = temp ;
    }
    */
}

bool SortedDLL::isEmpty( void ) const
{
    return root == NULL ;
}

void SortedDLL::add( const string firstName, const string lastName )
{
    if ( isEmpty() )
    {
        root = new Node ;
        root->item.setName(firstName,lastName) ;

        root->next = NULL ;
        root->prev = NULL ;
        return ;
    }

    Node *tracker = root ;
    Node *predecessor = NULL ;

    while( tracker != NULL  && tracker->item.getName().compare(firstName + " " + lastName) < 0 )
    {
        predecessor = tracker ;
        tracker = tracker->next ;
    }

    if ( tracker != NULL && tracker->item.getName().compare(firstName + " " + lastName) == 0 )
    {
        cout << firstName + " " + lastName + " already exists!" << endl ;
        return ;
    }

    Node *temp = new Node ;
    temp->item.setName(firstName, lastName) ;

    if ( tracker == root )
    {
        temp->prev = NULL ;
        temp->next = root ;
        root->prev = temp ;
        root = temp ;
    }

    else
    {
        temp->next = tracker ;
        temp->prev = predecessor ;

        predecessor->next = temp;

        if ( tracker != NULL)
            tracker->prev = temp ;
    }
}

void SortedDLL::remove( const string firstName, const string lastName)
{
    if ( isEmpty() )
    {
        cout << firstName + " " + lastName + " cannot be found!" << endl ;
        return ;
    }

    Node *tracker = root ;

    while ( tracker != NULL && tracker->item.getName() != (firstName + " " + lastName) )
        tracker = tracker->next ;

    if ( tracker == NULL )
        cout << firstName + " " + lastName + " cannot be found!" << endl ;

    if ( tracker == root )
    {
        Node *temp = root->next ;
        delete root ;
        root = temp ;
    }
    else
    {
        if ( tracker->next != NULL)
            tracker->next->prev = tracker->prev ;
        tracker->prev->next = tracker->next ;
        delete tracker ;
    }
}

void SortedDLL::addNumber( const string firstName, const string lastName,
                           const int areaCode, const int number)
{
    if ( isEmpty())
    {
        cout << firstName + " " + lastName + " cannot be found!" << endl ;
        return ;
    }

    Node *tracker = root ;

    while ( tracker != NULL && tracker->item.getName() != (firstName + " " + lastName))
        tracker = tracker->next ;

    if ( tracker == NULL )
        cout << firstName + " " + lastName + " cannot be found!" << endl ;
    else
        tracker->item.addNumber(areaCode,number) ;
}

void SortedDLL::removeNumber( const string firstName, const string lastName,
                           const int areaCode, const int number)
{
    if ( isEmpty() )
    {
        cout << firstName + " " + lastName + " cannot be found!" << endl ;
        return ;
    }

    Node *tracker = root ;

    while ( tracker != NULL && tracker->item.getName() != (firstName + " " + lastName))
        tracker = tracker->next ;

    if ( tracker == NULL )
        cout << firstName + " " + lastName + " cannot be found!" << endl ;
    else
        tracker->item.deleteNumber(areaCode,number) ;
}

void SortedDLL::showByName( const string firstName, const string lastName)
{
    if ( isEmpty() )
    {
        cout << firstName + " " + lastName + " cannot be found!" << endl ;
        return ;
    }

    Node *tracker = root ;

    while ( tracker != NULL && tracker->item.getName() != (firstName + " " + lastName))
        tracker = tracker->next ;

    if ( tracker == NULL )
        cout << firstName + " " + lastName + " cannot be found!" << endl ;
    else
    {
        cout << tracker->item.getName() << endl ;
        tracker->item.getPhoneNumbers().printAll() ;
    }
}

void SortedDLL::showByNumber( const int areaCode, const int number)
{
    if ( isEmpty() )
    {
        cout << areaCode << "-" << number << " cannot be found!" << endl ;
        return ;
    }

    Node *tracker = root ;

    while ( tracker != NULL && !tracker->item.getPhoneNumbers().find(areaCode, number))
        tracker = tracker->next ;

    if ( tracker == NULL )
        cout << areaCode << "-" << number << " cannot be found!" << endl ;
    else
    {
        cout << tracker->item.getName() << endl ;
        cout << areaCode << "-" << number << endl ;
    }
}

void SortedDLL::printAllInformation( void )
{
    if ( isEmpty() )
        return ;

    Node *tracker = root ;

    while ( tracker != NULL )
    {
        cout << tracker->item.getName() << endl ;
        tracker->item.getPhoneNumbers().printAll() ;
        cout << endl ;
        tracker = tracker->next ;
    }

}
