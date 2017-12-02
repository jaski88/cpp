#include "../list.h"

#include <boost/test/unit_test.hpp>

namespace list_tests
{
BOOST_AUTO_TEST_SUITE( list_test_suite )

BOOST_AUTO_TEST_CASE( push_pop )
{
    List< int > list;
    list.push_front( 0 );
    list.push_front( 1 );
    list.push_front( 2 );

    BOOST_CHECK_EQUAL( list.count( ), 3 );

    BOOST_CHECK_EQUAL( 2, list.pop_front( ) );
    BOOST_CHECK_EQUAL( 1, list.pop_front( ) );
    BOOST_CHECK_EQUAL( 0, list.pop_front( ) );

    BOOST_CHECK( list.empty( ) );
    BOOST_CHECK_EQUAL( list.count( ), 0 );

    list.push_back( 0 );
    list.push_back( 1 );
    list.push_back( 2 );

    BOOST_CHECK_EQUAL( list.count( ), 3 );

    BOOST_CHECK_EQUAL( 2, list.pop_back( ) );
    BOOST_CHECK_EQUAL( 1, list.pop_back( ) );
    BOOST_CHECK_EQUAL( 0, list.pop_back( ) );

    BOOST_CHECK( list.empty( ) );
    BOOST_CHECK_EQUAL( list.count( ), 0 );
}

BOOST_AUTO_TEST_CASE( insert_remove )
{
    const size_t LIST_SIZE = 10;

    List< int > list;

    for ( size_t i = 0; i < LIST_SIZE; i++ )
    {
        list.insert( i, i );
    }

    BOOST_CHECK( !list.insert( 50, 0 ) );
    BOOST_CHECK( list.remove( 9 ) );
    BOOST_CHECK( list.remove( 5 ) );
    BOOST_CHECK( list.remove( 0 ) );
    BOOST_CHECK( !list.remove( 50 ) );

    BOOST_CHECK_EQUAL( list.count( ), 7 );
}

BOOST_AUTO_TEST_CASE( interate_loop )
{
    const size_t LIST_SIZE = 10;

    List< int > list;

    for ( size_t i = 0; i < LIST_SIZE; i++ )
    {
        list.push_back( std::rand( ) );
    }

    size_t i = 0;
    for ( auto it = list.begin( ); it != list.end( ); it++ )
    {
        i++;
    }

    BOOST_CHECK( i == LIST_SIZE );
}

BOOST_AUTO_TEST_CASE( for_loop )
{
    const size_t LIST_SIZE = 10;

    List< int > list;

    for ( size_t i = 0; i < LIST_SIZE; i++ )
    {
        list.push_back( std::rand( ) );
    }

    size_t i = 0;
    for ( const auto& item : list )
    {
        i++;
    }

    BOOST_CHECK( i == LIST_SIZE );
}

BOOST_AUTO_TEST_SUITE_END( )
}
