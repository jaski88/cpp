#include <iostream>
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>
#include <future>
#include  <signal.h>

#include "common.h"

using namespace std;

int
main( int argc, char* argv[] )
{
    cout << "Client reading data..." << endl;

    // open shared memory
    int handle = shm_open( SHM_NAME, O_CREAT | O_RDWR, 0777 );
    ftruncate( handle, sizeof( CommonData ) );
    CommonData* memory = (CommonData*)mmap( 0, sizeof( CommonData ), PROT_READ | PROT_WRITE,
                                            MAP_SHARED, handle, 0 );

    // Reading shared data
    pid_t server_pid = memory->server_pid;

    if ( server_pid != 0 )
    {
        std::cout << "Shared data: " << " " << memory->message << std::endl;
        // send close signal to server
        std::cout << "Closing server: " << server_pid << std::endl;
        kill(server_pid, SIGUSR1);
    }
    else
    {
        std::cout << "Server not running" << std::endl;
    }

    // close shard memory
    munmap( memory, sizeof( CommonData ) );
    shm_unlink( SHM_NAME );

    return 0;
}
