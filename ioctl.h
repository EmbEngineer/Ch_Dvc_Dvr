#ifndef MAGIC
#define MAGIC 'K'
#endif


#ifndef DEVRESET
#define DEVRESET   _IO(MAGIC,0)
#endif

#ifndef GETREGISTERSIZE
#define GETREGISTERSIZE   _IOR(MAGIC, 1, int)
#endif

#ifndef GETDEVICESIZE
#define GETDEVICESIZE   _IOR(MAGIC, 2, int)
#endif

#ifndef GETDATASIZE
#define GETDATASIZE   _IOR(MAGIC, 3, int)
#endif

#ifndef GETNOOFREGISTER
#define GETNOOFREGISTER   _IOR(MAGIC, 4, int)
#endif

#ifndef PUTREGISTERSIZE
#define PUTREGISTERSIZE   _IOW(MAGIC, 5, int)
#endif

#ifndef PUTDEVICESIZE
#define PUTDEVICESIZE   _IOW(MAGIC, 6, int)
#endif

#ifndef PUTDATASIZE
#define PUTDATASIZE   _IOW(MAGIC, 7, int)
#endif

#ifndef PUTNOOFREGISTER
#define PUTNOOFREGISTER   _IOW(MAGIC, 8, int)
#endif

