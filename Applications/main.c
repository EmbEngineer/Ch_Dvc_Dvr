#include "headers.h"
#include "declarations.h"


int main()
{
#ifdef DEBUG
        printf("%s:Begin\n",__func__);
#endif

        init();
	while(1)            // main Menu
		(*fptr[0])(0); 

#ifdef DEBUG
        printf("%s:End\n",__func__);
#endif
        return 0;
}


