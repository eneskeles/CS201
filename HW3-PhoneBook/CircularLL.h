
#ifndef CIRCULARLL_H
#define CIRCULARLL_H

class CircularLL
{
    public :
        CircularLL( void ) ;
        ~CircularLL( void ) ;
        bool isEmpty( void ) const ;
        void add( const int areaCode, const int number) ;
        void remove( const int areaCode, const int number) ;
        bool find( const int areaCode, const int number) ;
        void printAll( void ) ;

    private :
        struct ListItem
        {
            int value1, value2 ;
            ListItem *next ;
        };

        ListItem *root ;

};
#endif // CIRCULARLL_H

