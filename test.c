#include <stdio.h>
#include <sys/stat.h>

int main ()
{
    struct inodetablebuffer_ buff = {0};
    struct stat statbuff, *stat_buff_ptr;
//    buff.magic_number = 9999;

//    inodewalker(&buff);
    stat_buff_ptr = &statbuff;
    printf("statbuff pointer in program %p",stat_buff_ptr);

    lstat(NULL, &statbuff);

    printf("inodewalker returned %d \n", buff.magic_number);
}
