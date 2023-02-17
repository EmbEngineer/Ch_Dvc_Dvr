#include "headers.h"
#include "declarations.h"

void* mainMenu(void *);
void* exitFunc(void *);
void* openDev(void *);
void* releaseDev(void *);
void* writeDev(void *arg);
void* readeDev(void *arg);
void* ioctlDev(void *arg);

void* (*fptr[NOF])(void *);
int init(void )
{
#ifdef DEBUG
        printf("%s:Begin\n",__func__);
#endif
	fptr[0] = mainMenu;
        fptr[1] = exitFunc;
        fptr[2] = openDev;
        fptr[3] = releaseDev;
        fptr[4] = writeDev;
        fptr[5] = readDev;
        fptr[6] = ioctlDev;

#ifdef DEBUG
	printf("%s:End\n",__func__);
#endif
	return 0;
}


