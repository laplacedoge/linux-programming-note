#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int cnt = 1;

    while (1)
    {
        sleep(1);
        printf("[%d]\tthis is child process 1!\n", cnt++);
    }
}
