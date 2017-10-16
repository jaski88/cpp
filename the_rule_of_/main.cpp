#include <iostream>

#include "rule_of_three.h"
#include "rule_of_five.h"


int
main( int argc, char* argv[] )
{
    // rule of three
    {
        std::cout << "the rule of three" << std::endl;
        rule_of_three rule_of_three_obj( "rule of three");

        rule_of_three_obj( );

        rule_of_three rule_of_three_copy( rule_of_three_obj );
        rule_of_three_copy( );

        rule_of_three rule_of_three_assing;
        rule_of_three_assing = rule_of_three_obj;
        rule_of_three_assing( );
    }

    // rule of five
    {
        std::cout << "the rule of five" << std::endl;
        rule_of_five rule_of_five_obj( "rule of five");
        rule_of_five_obj( );

        rule_of_five rule_of_five_copy( std::move( rule_of_five_obj ) );
        rule_of_five_copy( );

        rule_of_five rule_of_five_assing;
        rule_of_five_assing = std::move( rule_of_five_copy );
        rule_of_five_assing( );
    }





    return 0;
}
