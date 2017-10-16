#ifndef RULE_OF_FIVE_H
#define RULE_OF_FIVE_H

class rule_of_five
{
public:
    rule_of_five( ) = default;
    rule_of_five( const char* data );

    // copy
    rule_of_five( const rule_of_five& other );
    rule_of_five& operator=( const rule_of_five& other );

    // move
    rule_of_five( rule_of_five&& other );
    rule_of_five& operator=( rule_of_five&& other );

    ~rule_of_five( );
    void operator( )( );

private:
    char* _data;
};

#endif  // RULE_OF_FIVE_H
