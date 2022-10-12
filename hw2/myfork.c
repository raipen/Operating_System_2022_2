#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    pid_t pid;
    pid = fork();
    if (pid == 0)
        printf("I am child\n");
    else
    {   
        wait(0);
        printf("I’m your father\n");
    }
    sleep(10);
    exit(0);
}