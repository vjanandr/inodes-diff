#include "inc.h"
#include <sys/stat.h>
#include <sys/statvfs.h>

int fs_stat(ino_t ino_nr, struct stat *statbuf)
{
	struct inode *rip;

	if ((rip = find_inode(ino_nr)) == NULL)
		return EINVAL;

	*statbuf = rip->i_stat;

	return OK;
}

int fs_statvfs(struct statvfs *st)
{
	st->f_flag = ST_NOTRUNC;
	st->f_bsize =  v_pri.logical_block_size_l;
	st->f_frsize = st->f_bsize;
	st->f_iosize = st->f_bsize;
	st->f_blocks = v_pri.volume_space_size_l;
	st->f_namemax = NAME_MAX;

	return OK;
}

void fs_blockstats(u64_t *blocks, u64_t *free, u64_t *used)
{
	*used = *blocks = v_pri.volume_space_size_l;
	*free = 0;
}

int isofs_inodes (struct inodetablebuffer_ *buf)
{
    printf("\n in isofs_inodes ");
    return (OK);
}
