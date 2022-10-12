#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    pid_t pid;
    pid = fork();
    if (pid == 0)
    {
        execv("/bin/ls", argv);
        printf("error\n");
        exit(1);
    }
    else
    {
        wait(0);
    }
    exit(0);
}