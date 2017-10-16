#ifndef RULE_OF_THREE_H
#define RULE_OF_THREE_H

/*
 * If one of following is explicitly declared
 * - copy constructor
 * - assigment constructor
 * - destructor
 * the other ones must be declared as well.
 * Rule of three is valid for Cpp03 as in Cpp11 rule of five should apply.
 */

class rule_of_three
{
public:
    rule_of_three( ) = default;
    rule_of_three( const char* data );

    // copy
    rule_of_three( const rule_of_three& other );
    rule_of_three& operator=( const rule_of_three& other );

    ~rule_of_three( );
    void operator( )( );

private:
    char* _data;
};

#endif  // RULE_OF_THREE_H
