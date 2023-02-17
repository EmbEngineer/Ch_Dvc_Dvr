#include "headers.h"
#include "declarations.h"

Qset* createScull(size_t size)
{
	int items, idx, noq, tmp;
        Qset *first, *last;

#ifdef DEBUG
        printk(KERN_INFO "%s: Begin\n",__func__);
#endif  
	
	items = size / (noofRegisters * registerSize);       
       	if(size % (noofRegisters * registerSize))
         	items++;

        first = last = (Qset *)kmalloc(sizeof(Qset), GFP_KERNEL);
        if(!last)
	{
        	printk(KERN_ERR "%s: ERROR: Kmalloc() failure.\n",__func__);
	        goto OUT;
	}
        memset(last, '\0', sizeof(Qset));
	
	for(idx =0 ; idx < items-1 ; idx++)
	{
                last->next = (Qset *)kmalloc(sizeof(Qset), GFP_KERNEL);
	        if(!last)
		{
        		printk(KERN_ERR "%s: ERROR: Kmalloc() failure.\n",__func__);
	        	goto OUT;
		}
	        last = last->next;
        	memset(last, '\0', sizeof(Qset));
	}

	last = first;
	for(idx = 0 ; idx < items ; idx++)
        {
                last->data = (void *)kmalloc(sizeof(void *)*noofRegisters, GFP_KERNEL);
	        if(!last->data)
		{
        		printk(KERN_ERR "%s: ERROR: Kmalloc() failure.\n",__func__);
	        	goto OUT;
		}
        	memset(last->data, '\0', sizeof(void *)*noofRegisters);
	        last = last->next;
	}
	
	noq = size/registerSize;
	if(size % registerSize)
		++noq;
	
	last = first;
	for(idx = tmp = 0; tmp < noq; tmp++)
	{
		last->data[idx] = kmalloc(registerSize, GFP_KERNEL);
		if(!last->data[idx])
		{
        		printk(KERN_ERR "%s: ERROR: Kmalloc() failure.\n",__func__);
	        	goto OUT;
		}
		if(idx == noofRegisters-1)
		{
			last = last->next;
			idx =0;
		}
		else
			++idx;
	}

#ifdef DEBUG
        printk(KERN_INFO "%s: End\n",__func__);
#endif
	return first;
OUT:
#ifdef DEBUG
        printk(KERN_INFO "%s: End\n",__func__);
#endif
	return 0;
}
