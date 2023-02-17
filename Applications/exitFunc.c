#include "headers.h"
#include "declarations.h"
void* exitFunc(void *arg)
{

#ifdef DEBUG
        printf("%s:Begin\n",__func__);
#endif

        if(strncmp((char *)arg, "Success", 7) == 0)
		exit(EXIT_SUCCESS);
	else if(strncmp((char *)arg, "Failure", 7) == 0)
		exit(EXIT_FAILURE);

#ifdef DEBUG
        printf("%s:End\n",__func__);
#endif
	return 0;
}


