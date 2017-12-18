#include <iostream>
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>
#include <future>
#include <cstring>
#include <signal.h>

#include "common.h"

using namespace std;

namespace {
    const std::chrono::milliseconds TIMEOUT( 30000 );
}

void
signal_callback_handler( int signum )
{
    std::cout << "Received signal (" << signum << ") from client. Closing..." << std::endl;
    exit( signum );
}

int
main( int argc, char* argv[] )
{
    cout << "Server waiting for client..." << endl;

    // register signal handler
    signal( SIGUSR1, signal_callback_handler );

    // open shared memory
    int handle = shm_open( SHM_NAME, O_CREAT | O_RDWR, 0777 );
    ftruncate( handle, sizeof( CommonData ) );
    CommonData* memory = (CommonData*)mmap( 0, sizeof( CommonData ), PROT_READ | PROT_WRITE,
                                            MAP_SHARED, handle, 0 );

    // wriiting to shm
    memory->server_pid = getpid( );
    const char message[] = "Hello shared memory";
    std::memcpy( memory->message, message, sizeof( message ) );

    // waiting for client signal
    std::this_thread::sleep_for( TIMEOUT );

    munmap( memory, sizeof( CommonData ) );
    shm_unlink( SHM_NAME );

    return 0;
}
