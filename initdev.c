#include "headers.h"
#include "declarations.h"
#include "fileopr.h"

int majorNo, minorNo, nod;
int deviceSize, dataSize, registerSize, noofRegisters;
dev_t devid, devno;
Dev *dev;

module_param(nod, int, S_IRUGO);
module_param(registerSize, int, S_IRUGO);
module_param(noofRegisters, int, S_IRUGO);
module_param(deviceSize, int, S_IRUGO);

static int __init initDev(void)
{

	int ret,idx;
	printk(KERN_INFO "Hellow Kernal.....I am Aman\n");
        
        majorNo = MAJORNO;
        minorNo = MINORNO;
//	nod = NOD;
//      deviceSize = DEVICESIZE;
       	dataSize = DATASIZE;
//      registerSize = REGISTERSIZE;
//      noofRegisters = NOOFREGISTER;

	//1. Register Device Driver into the Kernel
	//majorNo = register_chrdev(MAJORNO , DEVNAME , &fops);
	if(majorNo >0 )                //  used all ready loadded kernel
	{
		ret = register_chrdev_region(devno, 1, DEVNAME);
	}
	else                          // load driver to kernel 
		ret = alloc_chrdev_region(&devid, minorNo, nod, DEVNAME); 
        if(ret == -1)
	{
           printk(KERN_ERR "ERROR: Device Registration Failled. \n");
	   goto OUT;
	}	
	majorNo = MAJOR(devid);
	minorNo = MINOR(devid);
	printk(KERN_INFO "Device Driver registration successful...MajorNo:%d and MinorNo:%d\n",majorNo, minorNo);
	
	dev = (Dev *)kmalloc(sizeof(Dev)*nod , GFP_KERNEL);        // alocate spaces for nod devices
	if(!dev)
	{
		printk(KERN_ERR "ERROR: kmalloc() Failled. \n");
		goto OUT;
	}
        memset(dev, '\0', sizeof(Dev)*nod);

	for(idx = 0; idx<nod ; ++idx)
	{
        	cdev_init(&dev[idx].c_dev, &fops);                // initialize cdev
        	dev[idx].c_dev.ops = &fops;
        	dev[idx].deviceSize = deviceSize;
        	dev[idx].dataSize = dataSize;
        	dev[idx].registerSize = registerSize;
		dev[idx].noofRegisters = noofRegisters;
		devno = MKDEV(majorNo, idx);
//        	sema_init(&dev[idx].sem, 1);                         //  initialize shemaphore
                init_completion(&dev[idx].cmplsn);
		ret = cdev_add(&dev[idx].c_dev, devno, nod);        //  added cdev to device table
        	if(ret == -1)
        	{
           		printk(KERN_ERR "ERROR: cdev_add() Failled. \n");
           		goto OUT;
        	}
		majorNo = MAJOR(dev[idx].c_dev.dev);
		minorNo = MINOR(dev[idx].c_dev.dev);
		printk(KERN_INFO "Device Driver registration successful...MajorNo:%d and MinorNo:%d\n",majorNo, minorNo);
        }
	return 0;
OUT:
	return -1;
}

module_init(initDev);

