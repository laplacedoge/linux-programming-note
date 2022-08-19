#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

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

int main(int argc, char *argv[])
{
    int cnt = 1;
    int ret;

    if (exec_new_program("child1") < 0) return -1;
    if (exec_new_program("child2") < 0) return -1;
    if (exec_new_program("child3") < 0) return -1;
    while (1)
    {
        sleep(1);
        printf("[%d] this is parent process!\n", cnt++);
    }
}
