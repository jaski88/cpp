#include "rule_of_three.h"

#include <string.h>  // strcpy, strlen
#include <iostream>

rule_of_three::rule_of_three( const char* data )
    : _data( new char[ strlen( data ) + 1 ] )
{
    strcpy( _data, data );
}

rule_of_three::rule_of_three( const rule_of_three& other )
{
    _data = new char[ strlen( other._data ) + 1 ];
    strcpy( _data, other._data );
}

rule_of_three&
rule_of_three::operator=( const rule_of_three& other )
{
    _data = new char[ strlen( other._data ) + 1 ];
    strcpy( _data, other._data );
    return *this;
}

rule_of_three::~rule_of_three( )
{
    if ( _data != nullptr )
    {
        delete _data;
    }
}

void
rule_of_three::operator( )( )
{
    if ( _data != nullptr )
    {
        std::cout << _data << "(" << &_data << ")" << std::endl;
    }
}
