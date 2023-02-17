#include "headers.h"
#include "declarations.h"

int releaseDevice(struct inode *,struct file *)
{
#ifdef DEBUG
        printk(KERN_INFO "%s: Begin\n",__func__);
#endif  


#ifdef DEBUG
        printk(KERN_INFO "%s: End\n",__func__);
#endif
	return 0;
}
