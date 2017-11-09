#include "list_test.h"

#include "../list.h"

namespace tests
{
bool
ListTest::push_pop( )
{
    List< int > list;
    list.push_front( 0 );
    list.push_front( 1 );
    list.push_front( 2 );

    bool success = true;

    success &= ( list.count( ) == 3 );

    success &= 2 == list.pop_front( );
    success &= 1 == list.pop_front( );
    success &= 0 == list.pop_front( );

    success &= ( list.count( ) == 0 && list.empty( ) );

    list.push_back( 0 );
    list.push_back( 1 );
    list.push_back( 2 );

    success &= ( list.count( ) == 3 );

    success &= 2 == list.pop_back( );
    success &= 1 == list.pop_back( );
    success &= 0 == list.pop_back( );

    success &= ( list.count( ) == 0 && list.empty( ) );

    return success;
}

bool
ListTest::insert_remove( )
{
    const size_t LIST_SIZE = 10;

    List< int > list;

    for ( size_t i = 0; i < LIST_SIZE; i++ )
    {
        list.insert( i, i );
    }

    bool success = true;

    success &= !list.insert( 50, 0 );
    success &= list.remove( 9 );
    success &= list.remove( 5 );
    success &= list.remove( 0 );
    success &= !list.remove( 50 );

    return success && ( list.count( ) == 7 );
}

bool
ListTest::interate_loop( )
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

    return i == LIST_SIZE;
}

bool
ListTest::for_loop( )
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

    return i == LIST_SIZE;
}

bool
ListTest::run_all( )
{
    return push_pop( ) && insert_remove( ) && interate_loop( ) && for_loop( );
}
}
