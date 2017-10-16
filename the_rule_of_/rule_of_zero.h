#ifndef RULE_OF_ZERO_H
#define RULE_OF_ZERO_H

#include <string>

/*
 * According to rule of zero no special members should be created
 * as managing resources should be done automaticly.
 * As in Cpp03 was not possible in Cpp11 standard containers should be used.
 *
 */
class rule_of_zero
{
    rule_of_zero( const char* data );

    void operator( )( );

private:
    std::string m_data;  // using stl provides resource managing
};

/*
 * According to rule of five defaults all special members should be declared explicitly.
 * When in rule of zero custom destructor is provided, than moving constuctor will be removed
 * which can cause existing code to use copy constructor and lead to different behaviour.
 */

class rule_of_five_defaults
{
    rule_of_five_defaults( const char* data );

    rule_of_five_defaults( ) = default;
    ~rule_of_five_defaults( ) = default;

    rule_of_five_defaults( const rule_of_five_defaults& ) = default;
    rule_of_five_defaults& operator=( const rule_of_five_defaults& ) = default;

    rule_of_five_defaults( rule_of_five_defaults&& ) = default;
    rule_of_five_defaults& operator=( rule_of_five_defaults&& ) = default;

    void operator( )( );

private:
    std::string m_data;
};

#endif  // RULE_OF_ZERO_H
