
#include "list_test.h"

int
main( )
{
    bool success = tests::ListTest::run_all( );


    if ( !success )
    {
        std::cerr << "tests fail" << std::endl;
    }

    return success ? 0 : 1;
}
