#include "headers.h"
#include "declarations.h"

ssize_t writeDevice(struct file *filep, const char __user *u_buff, size_t size, loff_t *temp )
{
	Dev *ldev;
        size_t lsize;
        int i = 0, noctw, nocwn, ret;
        Qset *lqsetp;

#ifdef DEBUG
        printk(KERN_INFO "%s: Begin\n",__func__);
#endif  

        ldev =(Dev *)filep->private_data;
	if(!ldev)
	{
        	printk(KERN_INFO "%s: ERROR: opened Device Not Found\n",__func__);
	        goto OUT;
	}
        
	if(size > ldev->deviceSize)
		lsize= ldev->deviceSize;
	else
		lsize = size;

/*	if(down_interruptible(&ldev->sem))         // lock
        {
                return -ERESTARTSYS;
        }*/

	ldev->first = createScull(lsize);

        i= nocwn =0;
        noctw = lsize;
	lqsetp = ldev->first;
        while(lsize > 0)
	{
		if(noctw > ldev->registerSize)               // size of quntom
			noctw = ldev->registerSize;
		else
			noctw = lsize;

		ret = copy_from_user(lqsetp->data[i], (const void __user *)u_buff+nocwn, noctw);
	   	if(ret > 0)
		{
        		printk(KERN_INFO "%s: Partial write\n",__func__);
		}
		
		nocwn += noctw - ret;
		noctw = lsize -= (noctw - ret);
                if( i == (ldev->noofRegisters - 1))
                {
			i =0;
			lqsetp = lqsetp->next;
		}
		else
			i++;
	}	

       ldev->dataSize = nocwn;

       
       filep->f_pos = *temp;
       wake_up_interruptible(&ldev->myqueue);
//     complete(&ldev->cmplsn);
//     up(&ldev->sem);      // unlock

#ifdef DEBUG
        printk(KERN_INFO "%s: End\n",__func__);
#endif
	return nocwn;
OUT:
#ifdef DEBUG
        printk(KERN_INFO "%s: ERROR: End\n",__func__);
#endif
	return -1;
}
