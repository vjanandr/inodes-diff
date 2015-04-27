#include <unistd.h>

int inodeWalker (inodetablebuffer *buffer)
{
    int error;
    message m

    m.m_type = 1;
    m.mess_vfs_fs_inode.buff = buffer;
    error = _syscall(PM_PROC_NR, INODEWALK, &m);
    return error;
}
