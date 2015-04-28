#include <unistd.h>
#include <sys/cdefs.h>
#include "namespace.h"
#include <lib.h>  
#include <string.h>
#include <sys/stat.h> 
#include <stdio.h>

int inodewalker (struct inodetablebuffer_ *buffer)
{
    int error;
    message m;

    m.m_type = 1;
    m.m_fs_inodes_req.buff = (vir_bytes *)buffer;
    printf("\n In inode walker user space ");
    error = _syscall(VFS_PROC_NR, VFS_INODEWALKER, &m);
    return error;
}
