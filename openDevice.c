#include "headers.h"
#include "declarations.h"

int openDevice(struct inode *inodep,struct file *filep)
{
	Dev *ldev;
	int ret;
#ifdef DEBUG
	printk(KERN_INFO "%s: Begin\n",__func__);
#endif      
	ldev = container_of(inodep->i_cdev, Dev, c_dev);
	if(!ldev)
	{
		printk(KERN_ERR "%s: ERROR: conttainer_of() failure.\n",__func__);
		goto OUT;
	}

	if((filep->f_flags & O_ACCMODE) == O_WRONLY)    // check mode of device read or write
	{
                ret = trimDevice(ldev);
	        if(ret == -1)
	        {
			printk(KERN_ERR "%s: ERROR: Trim Device failure.\n",__func__);
			goto OUT;
		}
	}
       
        filep->private_data = ldev;

#ifdef DEBUG
	printk(KERN_INFO "%s: End\n",__func__);
#endif      
	return 0;
OUT:
#ifdef DEBUG
	printk(KERN_INFO "%s: ERROR: Error with End\n",__func__);
#endif      
	return -1;
}
