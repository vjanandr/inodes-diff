#include <stdio.h>
#include <sys/stat.h>

int main ()
{
    struct inodetablebuffer_ buff = {0};
    struct stat statbuff;

    buff.magic_number = 9999;

    inodewalker(&buff);

    lstat(NULL, &statbuff);

    printf("inodewalker returned %d \n", buff.magic_number);
}
