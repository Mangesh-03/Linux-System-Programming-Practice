#include<linux/module.h>
#include<linux/init.h>
#include<linux/kernel.h>

static int __init marvellous_init(void)
{
    printk(KERN_INFO "Marvellous module gets inserted : Jay Ganesh...\n");
    return 0;
}

static void __exit marvellous_exit(void)
{
    printk(KERN_INFO "Marvellous module gets removed \n");
}

module__init(marvellous_init);

module__exit(marvellous_exit);


MODULE_LICENCE("GPL");
MODULE_AUTHOR("Marvellous Infosystems");
MODULE_DESCRIPTION("Demo kernel module");