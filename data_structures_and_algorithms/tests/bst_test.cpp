#include "bst_test.h"
#include "../bstree.h"

namespace tests
{
bool
BSTreeTest::run_all( )
{
    return insert_remove( );
}

bool
BSTreeTest::insert_remove( )
{
    BSTree< int > tree;

    bool success = true;

    success &= tree.insert( 10 );
    success &= tree.insert( 5 );
    success &= tree.insert( 8 );
    success &= tree.insert( 9 );
    success &= tree.insert( 7 );
    success &= tree.insert( 3 );
    success &= tree.insert( 1 );
    success &= tree.insert( 4 );
    success &= tree.insert( 2 );
    success &= tree.insert( 6 );

    return success;
}
}
