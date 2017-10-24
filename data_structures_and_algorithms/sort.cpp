#include "sort.h"

#include <cassert>

void
sort::bubble( std::vector< int >& list )
{
    assert( list.size( ) > 0 );

    bool modified = true;

    while ( modified )
    {
        for ( int i = 0; i < list.size( ) - 1; i++ )
        {
            const int current = list[ i ];
            const int next = list[ i + 1 ];

            if ( current > next )
            {
                list[ i ] = next;
                list[ i + 1 ] = current;
                modified = true;
            }
        }
    }
}
