#include "fs.h"
#include <fcntl.h>
#include <assert.h>
#include <unistd.h>
#include <string.h>
#include <minix/callnr.h>
#include <minix/safecopies.h>
#include <minix/endpoint.h>
#include <minix/com.h>
#include <minix/sysinfo.h>
#include <minix/u64.h>
#include <sys/ptrace.h>
#include <sys/svrctl.h>
#include <sys/resource.h>
#include "file.h"
#include "scratchpad.h"
#include <minix/vfsif.h>
#include "vnode.h"
#include "vmnt.h"

int do_inodewalker (void)
{
    int r;
    struct vnode *vp;
    struct vmnt *vmp;
    char fullpath[PATH_MAX];
    struct lookup resolve;
    inodetablebuffer *buff;

    if (copy_path(fullpath, sizeof(fullpath)) != OK)
        return(err_code);

    buff = job_m_in.mess_vfs_fs_inodes.buff;
    lookup_init(&resolve, fullpath, PATH_NOFLAGS, &vmp, &vp);
    resolve.l_vmnt_lock = VMNT_READ;
    resolve.l_vnode_lock = VNODE_READ;
    if ((vp = eat_path(&resolve, fp)) == NULL) return(err_code);

    r = req_inodes(vp->v_fs_e, who_e, buff);

    unlock_vnode(vp);
    unlock_vmnt(vmp);
    put_vnode(vp);
    return r;
}
