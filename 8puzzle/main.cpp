#include <fstream>
#include <iostream>

#include "board.h"
#include "solver.h"

using namespace std;

Board
read_from_file( const char* filename )
{
    ifstream file( filename, ios::in );

    int size;
    int input;

    if ( !file )
    {
        cerr << "Cant open file " << filename << endl;
        return Board( );
    }

    file >> size;

    std::vector< int > board_vector;

    while ( file >> input )
    {
        board_vector.push_back( input );
    }

    file.close( );

    return Board( board_vector, size );
}

int
main( )
{
    cout << "8 puzzle game" << endl;

    Board b = read_from_file( "testing/puzzle3x3-11.txt" );

    cout << "solving puzzle: " << endl;
    b.print( );


    Solver s;
    s.run( b );

    cout << "solution size: " << s.solution( ).size( ) << endl;

    for ( const Board& it : s.solution( ) )
    {
        it.print( );
        std::cout << std::endl;
    }

    return 0;
}
