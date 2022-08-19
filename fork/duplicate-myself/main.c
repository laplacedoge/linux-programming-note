#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    pid_t pid;
    int cnt = 1;

    pid = fork();
    if (pid < 0)
    {
        printf("failed to fork a child process!\n");
        return -1;
    }
    if (pid > 0)
    {
        while (1)
        {
            sleep(1);
            printf("[%d] this is parent process!\n", cnt++);
        }
    }
    else
    {
        while (1)
        {
            sleep(1);
            printf("[%d] this is child process!\n", cnt++);
        }
    }
}
