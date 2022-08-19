#include <stdio.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int exec_new_program(const char *path)
{
    pid_t pid;

    pid = fork();
    if (pid < 0)
    {
        printf("failed to fork a child process!\n");
        return -1;
    }
    if (pid > 0)
    {
        return 0;
    }
    else
    {
        execl(path, path, NULL);
        printf("failed to execl a child process!\n");
        exit(-1);
    }
}

#define SHM_NAME    "STRING"
#define SHM_SIZE    (1024 * 1024 * 2)

int routine(void)
{
    int shm_fd;
    void *shm_mem;

    shm_fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);

    ftruncate(shm_fd, SHM_SIZE);

    shm_mem = mmap(0, SHM_SIZE, PROT_WRITE, MAP_SHARED, shm_fd, 0);

    sprintf((char *)shm_mem, "this is a message from parent to child by using shared memory!\n");

    wait(NULL);
    close(shm_fd);
    printf("parent exit!\n");

    return 0;
}

int main(int argc, char *argv[])
{
    int cnt = 1;
    int ret;

    if (exec_new_program("child") < 0) return -1;

    if (routine() < 0)
    {
        return -1;
    }
}
