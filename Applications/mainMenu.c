#include "headers.h"
#include "declarations.h"

void* mainMenu(void * arg)
{       
       int i;
       void *ret;

#ifdef DEBUG
       printf("%s: Begin\n",__func__);
#endif

       printf("%s: __Application: Main_Menu__\n",__func__);
       printf("%s: 1: Open The Device \n",__func__);
       printf("%s: 2: Close The Device \n",__func__);
       printf("%s: 3: Write into the Device \n",__func__);
       printf("%s: 4: Read from the Device \n",__func__);
       printf("%s: 5: IO Crontrol the Device \n",__func__);
       printf("%s: 0: Exit Program \n",__func__);
       printf("%s: Please Enter your Choise: \n",__func__);
       scanf("%d", &i);

       if(i == 0)             			// exitcall
	       (*fptr[i+1])((void *)"Success");
       else if(i ==1 )      			// open function
       {			     
	      ret = (*fptr[i+1])(NULL); 
       }
       else if((i>=1) && (i<=4))    		  // other function
       {
		(*fptr[i+1])(ret); 
       }
#ifdef DEBUG
       printf("%s: End\n",__func__);
#endif  
       return 0;
}
