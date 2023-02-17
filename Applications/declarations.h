#ifndef DEBUG
#define DEBUG 1
#endif

#ifndef NOF
#define NOF 7
#endif


int init(void );

extern void* mainMenu(void *);
extern void* exitFunc(void *);
extern void* openDev(void *);
extern void* releaseDev(void *);
extern void* writeDev(void *);
extern void* readDev(void *);
extern void* ioctlDev(void *);
extern void* (*fptr[NOF])(void *);                     
