#include <iostream>
#include <future>
#include <vector>

using namespace std;

template < typename... _Args >
class RAIIThread
{
public:
    RAIIThread( _Args&&... args )
        : m_t( std::forward< _Args >( args )... )
    {
    }

    ~RAIIThread( )
    {
        m_t.join( );
    }

private:
    std::thread m_t;
};

struct Fib
{
    int operator( )( int i )
    {
        return run_and_print( i );
    }

    static int
    fib( int i )
    {
        switch ( i )
        {
        case 1:
            return 1;
        case 2:
            return 1;
        default:
            return fib( i - 1 ) + fib( i - 2 );
        }
    }

    static int
    run_and_print( int i )
    {
        const int value = fib( i );
        std::cout << "fib( " << i << " ) " << value << std::endl;
        return value;
    }
};

int
main( int argc, char* argv[] )
{
    // threads creation
    std::vector< std::reference_wrapper< thread > > threads;

    // #1 lambda exp
    std::thread t1( []
                    {
                        Fib::run_and_print( 10 );
                    } );

    threads.push_back( t1 );

    // #2 class
    std::thread t2( Fib( ), 11 );
    threads.push_back( t2 );

    // #3 function
    std::thread t3( Fib::run_and_print, 12 );
    threads.push_back( t3 );

    // #4 RAII Thread
    {
        auto run_raii = []
        {
            const int value = Fib::fib( 13 );
            std::cout << "RAIIThread: fib( 23 ) = " << value << std::endl;
        };

        RAIIThread< decltype( run_raii ) > t( std::move( run_raii ) );
        std::cout << "wating for raii..." << std::endl;
    }

    // #5 Other RAII Thread
    {
        auto run_raii = std::bind( Fib::run_and_print, 14 );
        RAIIThread< decltype( run_raii ) > t( std::move( run_raii ) );
    }

    // future & promise

    std::future< int > future = std::async( std::launch::async, []
                                            {
                                                return Fib::fib( 15 );
                                            } );
    std::cout << "fib( 15 ) = " << future.get( ) << std::endl;

    std::promise< int > promise;

    std::thread th( [&promise]
                    {
                        // value is printed after sleep
                        promise.set_value_at_thread_exit( Fib::fib( 16 ) );
                        std::this_thread::sleep_for( std::chrono::milliseconds( 1000 ) );
                        std::cout << __PRETTY_FUNCTION__ << std::endl;
                    } );

    threads.push_back( th );

    std::cout << "fib( 16 ) = " << promise.get_future( ).get( ) << std::endl;

    std::cout << __PRETTY_FUNCTION__ << std::endl;

    for ( std::thread& th : threads )
    {
        th.join( );
    }

    return 0;
}
