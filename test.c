#include <stdio.h>
#include <sys/stat.h>

int main ()
{
    struct inodetablebuffer_ buff = {0};

    buff.magic_number = 0;

    inodewalker(&buff);

    printf("inodewalker returned %d \n", buff.magic_number);
}
