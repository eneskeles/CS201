/*
    Mehmet Enes Keles
    CS/201 - 1
    21501348
*/
#include <iostream>
#include "CircularLL.h"

using namespace std;

CircularLL::CircularLL( void )
{
    root = NULL ;
}

CircularLL::~CircularLL( void )
{
 /*   while ( !isEmpty())
        remove(root->value1, root->value2) ;
*/
}
bool CircularLL::isEmpty( void ) const
{
    return root == NULL ;
}

void CircularLL::add( const int areaCode, const int number)
{
    if ( find(areaCode, number) )
    {
        cout << areaCode << "-" << number <<" already exists!"<<endl ;
        return ;
    }

    ListItem *temp = new ListItem ;
    temp->value1 = areaCode ;
    temp->value2 = number ;

    if ( isEmpty())
    {
        root = temp ;
        root->next = root ;
        return ;
    }

    ListItem *tracker = root ;

    while ( tracker->next != root )
        tracker = tracker->next ;

    temp->next = root ;
    tracker->next = temp ;
}

void CircularLL::remove(const int areaCode, const int number)
{
    if ( !find(areaCode, number))
    {
        cout << areaCode << "-" << number << " cannot be found!"<<endl ;
        return ;
    }

    ListItem *tracker = root->next ;
    ListItem *predecessor = root ;

    do
    {
        if ( tracker->value1 == areaCode && tracker->value2 == number)
        {
            if ( root->value1 == root->next->value1 && root->value2 == root->next->value2)
            {
                delete root ;
                root = NULL ;
                return ;
            }

            else
            {
                if ( tracker->value1 == root->value1 && tracker->value2 == root->value2)
                    root = root->next ;


                predecessor->next = tracker->next ;
                delete tracker ;

                return ;
            }
        }

        predecessor = predecessor->next ;
        tracker = tracker->next ;

    }while ( predecessor != root) ;

}

void CircularLL::printAll()
{
    ListItem *tracker = root;

    if ( isEmpty() )
        return ;

    do
    {
        cout << tracker->value1 << "-" << tracker->value2 << endl;
        tracker = tracker->next ;
    }while ( tracker != root ) ;
}

bool CircularLL::find( const int areaCode, const int number)
{
    ListItem *tracker = root;

    if ( isEmpty() )
        return 0 ;

    do
    {
       /* if ( tracker->value1 == areaCode && tracker->value2 == number)
            return 1 ;
        */if ( tracker->value1 == tracker->next->value1 && tracker->value2 == tracker->next->value2)
            return 0 ;
        tracker = tracker->next ;
    }while ( tracker != root ) ;
    return 0 ;
}
