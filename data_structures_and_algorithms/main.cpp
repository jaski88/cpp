#include <iostream>

#include "array.h"

#include <array>


using namespace std;

int
main( int argc, char* argv[] )
{
    const std::array< int, 7 > data = {1, 4, 8, 5, 2,3, 2};
    Array::print_pairs( data, 7 );

    const std::array<int, 10 > find_0_subarray = { 3, 4, -7, 3, 1, 3, 1, -4, -2, -2 };
    Array::print_subarray( find_0_subarray, 0 );

    std::array< int, 7 > binary_array = { 0 , 1 , 0 , 1, 0, 1, 0 };
    Array::sort_binary_array( binary_array );
    std::cout << "binary array: " << Array::to_str( binary_array ) << std::endl;

    return 0;
}
