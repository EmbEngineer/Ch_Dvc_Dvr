#include "headers.h"
#include "declarations.h"
void* writeDev(void *arg)
{
	int fd, len, ret;
	char buff[] = "I want to learn Device Driver Development";  
#ifdef DEBUG
        printf("%s:Begin\n",__func__);
#endif
          
	fd = *(int *)arg;
	len = strlen(buff);
       
       	ret = write(fd, buff, len);
       	if(ret == -1)
	{
		perror("write");
		(*fptr[1])((void *)"Failure");
	}
        printf("%s:Wrote %d byte successfuly fron Applicatuion\n",__func__,ret);
       
#ifdef DEBUG
        printf("%s:End\n",__func__);
#endif
	return arg;
}


