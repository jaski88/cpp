#include "list_test.h"
#include "bst_test.h"

int
main( )
{
    bool success = true;
    success &= tests::ListTest::run_all( );
    success &= tests::BSTreeTest::run_all( );


    if ( !success )
    {
        std::cerr << "tests fail" << std::endl;
    }

    return success ? 0 : 1;
}
