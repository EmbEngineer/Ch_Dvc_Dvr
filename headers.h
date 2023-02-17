#include<linux/init.h>
#include<linux/module.h>
#include<linux/fs.h>
#include<linux/slab.h>
#include<linux/cdev.h>
#include<linux/kernel.h>
#include<linux/moduleparam.h>
//#include<linux/semaphore.h>
//#include<linux/completion.h>
#include<linux/wait.h>
#include<linux/sched.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Aman and Puja");
MODULE_DESCRIPTION("Char Device Driver Development");
