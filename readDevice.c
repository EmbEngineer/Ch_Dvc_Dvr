#include "headers.h"
#include "declarations.h"

ssize_t readDevice(struct file *filep, char __user *u_buff, size_t size, loff_t * temp)
{
	 Dev *ldev;
	 int noctr, nocrd, i, ret;
	 Qset *lqset;
#ifdef DEBUG
        printk(KERN_INFO "%s: Begin\n",__func__);
#endif  
	ldev =(Dev *)filep->private_data;
        if(!ldev)
        {   
                printk(KERN_INFO "%s: ERROR: opened Device Not Found\n",__func__);
                goto OUT;
        }   
    
        if(size > ldev->dataSize)
                size= ldev->dataSize;
        else
                size = size;

	noctr = size;
	nocrd = i = 0;
	lqset = ldev->first;
	
	if(down_interruptible(&ldev->sem))         // lock
        {
                return -ERESTARTSYS;
        }

	while(size > 0)
        {
                if(noctr > ldev->registerSize)               // size of quntom
                        noctr = ldev->registerSize;
                else
                        noctr = size;

	        ret = copy_to_user(u_buff+nocrd,lqset->data[i], noctr);
                if(ret > 0)
                {
                        printk(KERN_INFO "%s: Partial Read\n",__func__);
                }
                nocrd += (noctr -ret);
               	noctr = size -= (noctr -ret);
		if( i == (ldev->noofRegisters - 1))
                {
                        i =0;
                        lqset = lqset->next;
                }
                else
                        i++;
	}

	  up(&ldev->sem);      // unlock

#ifdef DEBUG
        printk(KERN_INFO "%s: End\n",__func__);
#endif
	return nocrd;
OUT:
#ifdef DEBUG
        printk(KERN_INFO "%s: ERROR: End\n",__func__);
#endif
        return -1;
}
