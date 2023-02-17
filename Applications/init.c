#include "headers.h"
#include "declarations.h"

void* mainMenu(void *);
void* exitFunc(void *);
void* openDev(void *);
void* releaseDev(void *);
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

#ifdef DEBUG
	printf("%s:End\n",__func__);
#endif
	return 0;
}


