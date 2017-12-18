

const char* SHM_NAME = "/shm";

struct CommonData
{
    char message[100];
    pid_t server_pid;
};
