#include "rule_of_zero.h"

#include <iostream>

rule_of_five_defaults::rule_of_five_defaults( const char* data )
    : m_data( data )
{
}

void
rule_of_five_defaults::operator( )( )
{
    std::cout << m_data << std::endl;
}

rule_of_zero::rule_of_zero( const char* data )
    : m_data( data )
{
}

void
rule_of_zero::operator( )( )
{
    std::cout << m_data << std::endl;
}
