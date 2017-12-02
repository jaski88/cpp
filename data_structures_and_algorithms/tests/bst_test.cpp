#include "../bstree.h"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

namespace bst_tests
{
BOOST_AUTO_TEST_SUITE( bst_test_suite )

BOOST_AUTO_TEST_CASE( insert_remove )
{
    BSTree< int > tree;

    BOOST_CHECK( tree.insert( 10 ) );
    BOOST_CHECK( tree.insert( 5 ) );
    BOOST_CHECK( tree.insert( 8 ) );
    BOOST_CHECK( tree.insert( 9 ) );
    BOOST_CHECK( tree.insert( 7 ) );
    BOOST_CHECK( tree.insert( 3 ) );
    BOOST_CHECK( tree.insert( 1 ) );
    BOOST_CHECK( tree.insert( 4 ) );
    BOOST_CHECK( tree.insert( 2 ) );
    BOOST_CHECK( tree.insert( 6 ) );

    BOOST_CHECK_EQUAL( tree.count( ), 10 );
}

BOOST_AUTO_TEST_SUITE_END( )
}
