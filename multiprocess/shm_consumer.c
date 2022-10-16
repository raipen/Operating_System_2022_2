#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/shm.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    const int SIZE = 4096;
    const char *name = "OS";

    int shm_fd;
    char *ptr;

    shm_fd = shm_open(name, O_RDONLY, 0666);

    ptr = mmap(0, SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);

    printf("%s", ptr);

    shm_unlink(name);

    return 0;
}