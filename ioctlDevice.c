#include "headers.h"
#include "declarations.h"
#include "ioctl.h"

long ioctlDevice(struct file *filep, unsigned int command, unsigned long arg)
{
	Dev *ldev;
        int ret;

#ifdef DEBUG
	printk(KERN_INFO "%s: Begin\n",__func__);
#endif  

	ldev = (Dev *)filep->private_data;
        if(!ldev)
	{
		printk(KERN_ERR "%s: Device Not Found\n",__func__);
	        goto OUT;
	}

	switch(command)
	{
		case DEVRESET:
			if(access_ok((Dev *)ldev, sizeof(Dev)))
                        {
                                printk(KERN_INFO "%s: Access Denied\n",__func__);
                                goto OUT;
                        }
                        else
                        {
	                        ret = trimDevice(ldev);
				if(ret == -1)
				{
					printk(KERN_INFO "%s: Failled to trim\n",__func__);
				        goto OUT;
				}
                                dataSize = ldev->dataSize = DATASIZE;
                                registerSize = ldev->registerSize = REGISTERSIZE;
                                noofRegisters = ldev->noofRegisters = NOOFREGISTER;
                                deviceSize = ldev->deviceSize = DEVICESIZE;
			}
                        break;
		case GETREGISTERSIZE:
				printk(KERN_INFO "%s: GETREGISTERSIZE Command\n",__func__);
				printk(KERN_INFO "%s: Register Size is %d\n",__func__,ldev->registerSize);
				ret = put_user(ldev->registerSize, (int __user *)arg);
				if(ret < 0)
				{
					printk(KERN_ERR "Error: put_user\n");
				        goto OUT;
				}
			break;
		case GETDEVICESIZE:
				printk(KERN_INFO "%s: GETDEVICESIZE Command\n",__func__);
				printk(KERN_INFO "%s: Device Size is %d\n",__func__,ldev->deviceSize);
				ret = put_user(ldev->deviceSize, (int __user *)arg);
				if(ret < 0)
				{
					printk(KERN_ERR "Error: put_user\n");
				        goto OUT;
				}
			break;
		case GETDATASIZE:
				printk(KERN_INFO "%s: GETDATASIZE Command\n",__func__);
				printk(KERN_INFO "%s: Data Size is %d\n",__func__,ldev->dataSize);
				ret = put_user(ldev->dataSize, (int __user *)arg);
				if(ret < 0)
				{
					printk(KERN_ERR "Error: put_user\n");
				        goto OUT;
				}
			break;
		case GETNOOFREGISTER:
				printk(KERN_INFO "%s: GETNOOFREGISTER Command\n",__func__);
				printk(KERN_INFO "%s: No of Registe %d\n",__func__,ldev->noofRegisters);
				ret = put_user(ldev->noofRegisters, (int __user *)arg);
				if(ret < 0)
				{
					printk(KERN_ERR "Error: put_user\n");
				        goto OUT;
				}
			break;
		case PUTREGISTERSIZE:
				printk(KERN_INFO "%s: PUTREGISTERSIZE Command\n",__func__);
	                        ret = trimDevice(ldev);
				if(ret == -1)
				{
					printk(KERN_INFO "%s: Failled to trim\n",__func__);
				        goto OUT;
				}
				ret = get_user(ldev->registerSize, (int __user *)arg);
				if(ret < 0)
				{
					printk(KERN_ERR "Error: get_user\n");
				        goto OUT;
				}
				registerSize = ldev->registerSize;
				printk(KERN_INFO "%s: Register Size is %d\n",__func__,ldev->registerSize);
			break;
		case PUTDEVICESIZE:
				printk(KERN_INFO "%s: PUTDEVICESIZE Command\n",__func__);
	                        ret = trimDevice(ldev);
				if(ret == -1)
				{
					printk(KERN_INFO "%s: Failled to trim\n",__func__);
				        goto OUT;
				}
				ret = get_user(ldev->deviceSize, (int __user *)arg);
				if(ret < 0)
				{ 
					printk(KERN_ERR "Error: get_user\n");
				        goto OUT;
				}
				deviceSize = ldev->deviceSize;
				printk(KERN_INFO "%s: Device Size is %d\n",__func__,ldev->deviceSize);
			break;
		case PUTDATASIZE:
				printk(KERN_INFO "%s: PUTDATASIZE Command\n",__func__);
	                /*      ret = trimDevice(ldev);
				if(ret == -1)
				{
					printk(KERN_INFO "%s: Failled to trim\n",__func__);
				        goto OUT;
				}
				ret = get_user(ldev->dataSize, (int __user *)arg);
				if(ret < 0)
				{
					printk(KERN_ERR "Error: get_user\n");
				        goto OUT;
				}
				dataSize = ldev->dataSize;            */
				printk(KERN_INFO "%s: Data Size is %d\n",__func__,ldev->dataSize);
				printk(KERN_INFO "%s: We Can't Change Data Size %s\n",__func__);
			break;
		case PUTNOOFREGISTER:
				printk(KERN_INFO "%s: PUTNOOFREGISTER Command\n",__func__);
	                        ret = trimDevice(ldev);
				if(ret == -1)
				{
					printk(KERN_INFO "%s: Failled to trim\n",__func__);
				        goto OUT;
				}
				ret = get_user(ldev->noofRegisters, (int __user *)arg);
				if(ret < 0)
				{
					printk(KERN_ERR "Error: get_user\n");
				        goto OUT;
				}
				noofRegisters = ldev->noofRegisters;
				printk(KERN_INFO "%s: No of Registe %d\n",__func__,ldev->noofRegisters);
			break;
                default:
                        printk(KERN_INFO "%s: Invalid Command\n",__func__);
                       break;
	}

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
