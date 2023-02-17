#ifndef DEBUG
#define DEBUG
#endif

#ifndef MAJORNO
#define MAJORNO 0
#endif

#ifndef MINORNO
#define MINORNO 0
#endif

#ifndef NOD
#define NOD 20
#endif

#ifndef DEVICESIZE
#define DEVICESIZE  256
#endif

#ifndef DATASIZE
#define DATASIZE 0
#endif

#ifndef REGISTERSIZE
#define REGISTERSIZE  4
#endif

#ifndef NOOFREGISTER
#define NOOFREGISTER  4
#endif

#ifndef DEVNAME
#define DEVNAME  "AmanDev-cdd"
#endif


extern int majorNo;
extern int minorNo;
extern int nod;
extern int deviceSize;
extern int dataSize;
extern int registerSize;
extern int noofRegisters;
extern dev_t devid;
extern dev_t devno;

typedef struct QSET
{
       struct QSET *next;
       void **data;	
}Qset;

typedef struct DEV
{
	Qset *first;
        struct cdev c_dev;
	int deviceSize;
	int dataSize;
	int registerSize;
	int noofRegisters;
	struct semaphore sem;
}Dev;

extern Dev *dev;
int openDevice(struct inode *,struct file *);
int releaseDevice(struct inode *,struct file *);
int trimDevice(Dev *);
ssize_t writeDevice(struct file *, const char __user *, size_t , loff_t *);
ssize_t readDevice(struct file *, char __user *, size_t , loff_t *);
Qset * createScull(size_t);

