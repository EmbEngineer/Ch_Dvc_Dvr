#include "headers.h"
#include "declarations.h"
#include "../ioctl.h"
void* ioctlDev(void *arg)
{
	int fd, ret, command, res;
#ifdef DEBUG
        printf("%s:  Begin\n",__func__);
#endif
          
	fd = *(int *)arg;
        
        while(1)
	{
		printf("%s:__IOCTL_CMD_MENU__\n",__func__);
        	printf("%s: 1: Device ReSet\n",__func__);
        	printf("%s: 2: Get Register Size\n",__func__);
        	printf("%s: 3: Get Device Size\n",__func__);
        	printf("%s: 4: Get Data Size\n",__func__);
        	printf("%s: 5: Get No of Register\n",__func__);
        	printf("%s: 6: Put Register Size\n",__func__);
        	printf("%s: 7: Put Device Size\n",__func__);
        	printf("%s: 8: Put Data Size\n",__func__);
        	printf("%s: 9: Put No of Register\n",__func__);
      		printf("%s: 0: Exit\n",__func__);
    		printf("%s: Enter your Choise\n",__func__);
        	scanf("%d",&command);
   		switch(command)
		{
			case 0:
        			printf("%s: Thanks for using IOCTL command\n",__func__);
			        goto OUT;
				break;
			case 1:
       				ret = ioctl(fd, DEVRESET);
       				if(ret == -1)
				{
					perror("ioctl");
					(*fptr[1])((void *)"Failure");
				}
        			printf("%s: Device is Reset By using  IOCTL command\n\n",__func__);
				break;
			case 2:
				ret = ioctl(fd,GETREGISTERSIZE, &res);
       				if(ret == -1)
				{
					perror("ioctl");
					(*fptr[1])((void *)"Failure");
				}
        			printf("%s: Register Size %d\n",__func__,res);
				break;
			case 3:
				ret = ioctl(fd, GETDEVICESIZE, &res);
       				if(ret == -1)
				{
					perror("ioctl");
					(*fptr[1])((void *)"Failure");
				}
        			printf("%s: Device Size %d\n",__func__,res);
				break;
			case 4:
				ret = ioctl(fd, GETDATASIZE , &res);
       				if(ret == -1)
				{
					perror("ioctl");
					(*fptr[1])((void *)"Failure");
				}
        			printf("%s: Data Size %d\n",__func__,res);
				break;
			case 5:
				ret = ioctl(fd, GETNOOFREGISTER , &res);
       				if(ret == -1)
				{
					perror("ioctl");
					(*fptr[1])((void *)"Failure");
				}
        			printf("%s:No of Register %d\n",__func__,res);
				break;
			case 6:
        			printf("%s: Enter Register Size\n",__func__);
				scanf("%d",&res);
				ret = ioctl(fd,PUTREGISTERSIZE, &res);
       				if(ret == -1)
				{
					perror("ioctl");
					(*fptr[1])((void *)"Failure");
				}
				break;
			case 7:
        			printf("%s: Enter Device Size\n",__func__);
				scanf("%d",&res);
				ret = ioctl(fd, PUTDEVICESIZE, &res);
       				if(ret == -1)
				{
					perror("ioctl");
					(*fptr[1])((void *)"Failure");
				}
				break;
			case 8:
        			printf("%s: Enter Data Size\n",__func__);
				scanf("%d",&res);
				ret = ioctl(fd, PUTDATASIZE , &res);
       				if(ret == -1)
				{
					perror("ioctl");
					(*fptr[1])((void *)"Failure");
				}
				break;
			case 9:
        			printf("%s: Enter No of Register\n",__func__);
				scanf("%d",&res);
				ret = ioctl(fd, PUTNOOFREGISTER , &res);
       				if(ret == -1)
				{
					perror("ioctl");
					(*fptr[1])((void *)"Failure");
				}
			default:
        			printf("%s:Invalid command\n",__func__);
                                goto OUT;
       				break;
		}
	}
OUT:
#ifdef DEBUG
        printf("%s:End\n\n",__func__);
#endif
	return arg;
}

 
