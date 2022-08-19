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

#define SHM_NAME    "STRING"
#define SHM_SIZE    (1024 * 1024 * 2)

int main(int argc, char *argv[])
{
    int shm_fd;
    void *shm_mem;

    shm_fd = shm_open(SHM_NAME, O_RDONLY, 0666);
    shm_mem = mmap(0, SHM_SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);

    printf("%s", (char *)shm_mem);
    close(shm_fd);
    printf("child exit!\n");
    return 0;
}
