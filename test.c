#include <stdio.h>
#include <sys/stat.h>

int main ()
{
    struct inodetablebuffer_ buff = {0};

    buff.magic_number = 9999;

    __inodewalker50(&buff);

    printf("inodewalker returned %d \n", buff.magic_number);
}
