                 --------struct stat--------
struct stat {
    dev_t     st_dev;      /* ID of device containing file */
    ino_t     st_ino;      /* Inode number */
    mode_t    st_mode;     /* File type and mode (permissions) */
    nlink_t   st_nlink;    /* Number of hard links */
    uid_t     st_uid;      /* User ID of owner */
    gid_t     st_gid;      /* Group ID of owner */
    dev_t     st_rdev;     /* Device ID (if special file) */
    off_t     st_size;     /* Total size, in bytes */
    blksize_t st_blksize;  /* Block size for filesystem I/O */
    blkcnt_t  st_blocks;   /* Number of 512B blocks allocated */

    /* Timestamps */
    struct timespec st_atim;  /* Time of last access */
    struct timespec st_mtim;  /* Time of last modification */
    struct timespec st_ctim;  /* Time of last status change */

    /* Macros for backward compatibility */
#define st_atime st_atim.tv_sec  /* Access time (seconds) */
#define st_mtime st_mtim.tv_sec  /* Modification time (seconds) */
#define st_ctime st_ctim.tv_sec  /* Status change time (seconds) */
};


                --------API & FUNCTION--------

struct stat filestat: API from lib sys/stat.h

st.mode: storage type of file
S_ISREG(filestat.st_mode) 
    - check file is regular file
    - if that true return 0 and print Regular file , another return 1
S_ISDIR(filestat.st_mode): 
    - check file is directory file
    - if that true return 0 and print directory file , another return 1
S_ISLNK(filestat.st_mode): 
    - check file is Symbolic link
    - if that true return 0 and print Symbolic file , another return 1

filestat.st_size: storage size of file (byte)

st_mtime: last time modify

system call open: 
int open(const char *path, int flags, ... /* mode_t mode */ );
- *path = argv[1]
- flag: 
    - O_CREAT: create if file not exist
    - O_RDONLY: only read file


                      --------Makefile--------
build:
	gcc filestat.c -o filestat

clean:
	rm -rf filestat *.txt
