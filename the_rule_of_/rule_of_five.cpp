#include "rule_of_five.h"

#include <string.h>  // strcpy, strlen
#include <iostream>

rule_of_five::rule_of_five( const char* data )
    : _data( new char[ strlen( data ) + 1 ] )
{
    strcpy( _data, data );
}

rule_of_five::rule_of_five( const rule_of_five& other )
{
    _data = new char[ strlen( other._data ) + 1 ];
    strcpy( _data, other._data );
}

rule_of_five&
rule_of_five::operator=( const rule_of_five& other )
{
    _data = new char[ strlen( other._data ) + 1 ];
    strcpy( _data, other._data );
    return *this;
}

rule_of_five::rule_of_five( rule_of_five&& other )
{
    std::cout << "move" << std::endl;

    _data = other._data;
    other._data = nullptr;
}

rule_of_five&
rule_of_five::operator=( rule_of_five&& other )
{
    std::cout << "move" << std::endl;
    _data = other._data;
    other._data = nullptr;
    return *this;
}

rule_of_five::~rule_of_five( )
{
    if ( _data != nullptr )
    {
        delete _data;
    }
}

void
rule_of_five::operator( )( )
{
    if ( _data != nullptr )
    {
        std::cout << _data << "(" << &_data << ")" << std::endl;
    }
}
