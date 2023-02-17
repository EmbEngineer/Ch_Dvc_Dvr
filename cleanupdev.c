#include "headers.h"
#include "declarations.h"

static void __exit cleanupDev(void)
{
	int idx;
	printk(KERN_INFO "Bye for Now.....We will be back!\n");
//      unregister_chrdev(MAJORNO, DEVNAME);
        for(idx =0; idx<nod ; idx++)
	{
		cdev_del(&dev[idx].c_dev);         
	}
        kfree(dev);
	unregister_chrdev_region(devid, nod);
}

module_exit(cleanupDev);

