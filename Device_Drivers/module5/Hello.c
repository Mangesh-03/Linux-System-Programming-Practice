#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/init.h>

#define DRIVER_AUTHOR "Mangesh Ashok Bedre"
#define DRIVER_DESC "It is Marvellous module"

MODULE_LICENSE("GPL");

// Input argument
int MarvellousNo = 21;

module_param(MarvellousNo,int,S_IRUSR | S_IWUSR | S_IRGRP |S_IROTH);

MODULE_PARM_DESC(MarvellousNo ,"Its a integer varible");

static int __init Marvellous_Init(void)
{
    printk(KERN_INFO "Marvellous module loaded5 : Jay Ganesh :%d\n",MarvellousNo);
    return 0;
}

static void __exit Marvellous_Cleanup(void)
{
    printk(KERN_INFO "Marvellous module Unloaded5 : Jay Ganesh\n");
}

module_init(Marvellous_Init);
module_exit(Marvellous_Cleanup);

MODULE_AUTHOR(DRIVER_AUTHOR);
MODULE_DESCRIPTION(DRIVER_DESC);