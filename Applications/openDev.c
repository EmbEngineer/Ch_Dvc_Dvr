#include "headers.h"
#include "declarations.h"
void* openDev(void *arg)
{
	int *fd =NULL;
	int mode;
#ifdef DEBUG
        printf("%s:Begin\n",__func__);
#endif
        fd = (int *)malloc(sizeof(int));
        if(!fd)
	{
		perror("malloc");
                (*fptr[1])((void *)"Failure");
	}
       
        printf("Enter the Read mode\n");
        printf("1.Read   2.Write\n");
        scanf("%d",&mode);

	if(mode == 1)
		*fd = open("mycdd", O_RDONLY);
	else if (mode == 2)
		*fd = open("mycdd", O_WRONLY);
	else
	{
		printf("Invalid option\n");
		free(fd);
                (*fptr[1])((void *)"Failure");
	}
	if(*fd == -1)
	{
		perror("open");
		free(fd);
                (*fptr[1])((void *)"Failure");
	}
        printf("%s:Device open successfully and fd is %d\n",__func__,*fd);
#ifdef DEBUG
        printf("%s:End\n",__func__);
#endif
	return (void *)fd;
}


