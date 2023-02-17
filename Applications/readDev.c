#include "headers.h"
#include "declarations.h"
void* readDev(void *arg)
{
	int fd, ret;
	char buff[100];  
#ifdef DEBUG
        printf("%s:Begin\n",__func__);
#endif
          
	fd = *(int *)arg;
        printf("%s: FD :- %d\n",__func__,fd);
        ret = read(fd, buff, 100);
        if(ret == -1)
	{
		perror("read");
		(*fptr[1])((void *)"Failure");
	}
        printf("%s:read %d byte successfuly by Applicatuion\n",__func__,ret);
	buff[ret] = '\0';
        printf("%s: %s\n",__func__, buff);
       
#ifdef DEBUG
        printf("%s:End\n",__func__);
#endif
	return arg;
}


