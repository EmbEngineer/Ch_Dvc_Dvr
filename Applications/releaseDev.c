#include "headers.h"
#include "declarations.h"
void* releaseDev(void *arg)
{
	int ret;
#ifdef DEBUG
        printf("%s:Begin\n",__func__);
#endif
	
	ret = close(*(int *)arg);
        if(ret == -1)
	{
		perror("close");
                (*fptr[1])((void *)"Failure");
	}
        printf("%s:Device close successfully\n",__func__);
#ifdef DEBUG
        printf("%s:End\n",__func__);
#endif
	return arg;
}


