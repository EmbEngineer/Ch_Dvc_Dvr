#! /bin/bash

CC=gcc
CF=-c
app: main.o init.o mainMenu.o exitFunc.o openDev.o releaseDev.o writeDev.o readDev.o ioctlDev.o
	gcc -o app main.o init.o mainMenu.o exitFunc.o openDev.o releaseDev.o writeDev.o readDev.o ioctlDev.o

main.o: main.c headers.h declarations.h
	$(CC) $(CF) main.c
init.o: init.c headers.h declarations.h
	$(CC) $(CF) init.c
mainMenu.o: mainMenu.c headers.h declarations.h
	$(CC) $(CF) mainMenu.c
exitFunc.o: exitFunc.c headers.h declarations.h
	$(CC) $(CF) exitFunc.c
openDev.o: openDev.c headers.h declarations.h
	$(CC) $(CF) openDev.c
releaseDev.o: releaseDev.c headers.h declarations.h
	$(CC) $(CF) releaseDev.c
writeDev.o: writeDev.c headers.h declarations.h
	$(CC) $(CF) writeDev.c
readDev.o: readDev.c headers.h declarations.h
	$(CC) $(CF) readDev.c
ioctlDev.o: ioctlDev.c headers.h declarations.h ../ioctl.h
	$(CC) $(CF) ioctlDev.c


clean:
	-rm *.o
