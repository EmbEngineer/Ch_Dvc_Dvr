#include "headers.h"
#include "declarations.h"

int trimDevice(Dev *devp)
{
	int i;
	Qset *last, *slast;
#ifdef DEBUG
        printk(KERN_INFO "%s: Begin\n",__func__);
#endif  
        if(!devp)
	{
        	printk(KERN_ERR "%s:Device Not found for opening \n",__func__);
	        goto OUT;
	}
        if(!devp->first)
	{
        	printk(KERN_INFO "%s:Nothing to Trim \n",__func__);
	        goto RET;
	}

/*	if(down_interruptible(&devp->sem))         // lock
	{
		return -ERESTARTSYS;
	}*/
	while(devp->first)  // trim start from here 
	{
		slast = last = devp->first;

        	while(last->next)
		{
		        slast = last;
			last = last->next;
	        }
		if(last->data)
		{
			for(i= devp->noofRegisters-1; i>=0 ; i--)
   			{
				if(last->data[i])
				{
					kfree(last->data[i]);
					last->data[i] = NULL;
				}
			}
			kfree(last->data);
			last->data = NULL;
		}
		kfree(last);
		if(last == slast)
			devp->first = NULL;
		else
			slast->next = NULL;
	}
//	up(&devp->sem);      // unlock
RET:
#ifdef DEBUG
        printk(KERN_INFO "%s: End\n",__func__);
#endif
	return 0;
OUT:
#ifdef DEBUG
        printk(KERN_ERR "%s: ERROR\n",__func__);
#endif
	return -1;
}
