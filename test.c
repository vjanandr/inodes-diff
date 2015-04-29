#include <stdio.h>
#include <sys/stat.h>

int main ()
{
    struct inodetablebuffer_ buff = {0};
    struct inodetablebuffer_ *buff_ptr = &buff;
//    struct stat statbuff, *stat_buff_ptr;
    buff.magic_number = 777;

    printf("[main] walker pointer in program %p magic %d\n", buff_ptr,
            buff_ptr->magic_number);
    inodewalker(&buff);
//    stat_buff_ptr = &statbuff;
 //   printf("statbuff pointer in program %p\n",stat_buff_ptr);

 //   lstat("test.c", &statbuff);

    printf("[main] inodewalker returned %d \n", buff.magic_number);
}
