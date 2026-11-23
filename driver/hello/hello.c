/**
 * hello.c - 最简内核模块示例（内核态 Hello World）
 *
 * 编译要求：
 *   1. 必须在 Linux 环境（或 WSL / 虚拟机）执行，Windows 上无法编内核模块
 *   2. 需要与板卡运行内核版本一致的内核源码树
 *   3. make ARCH=arm CROSS_COMPILE=arm-none-linux-gnueabihf-
 *
 * 板卡上加载：
 *   insmod hello.ko      加载
 *   rmmod hello          卸载
 *   dmesg | tail         查看 printk 输出
 */
#include <linux/init.h>
#include <linux/module.h>

static int __init hello_init(void)
{
    printk(KERN_INFO "hello: module loaded\n");
    return 0;
}

static void __exit hello_exit(void)
{
    printk(KERN_INFO "hello: module unloaded\n");
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("xiaofeixia0432");
MODULE_DESCRIPTION("IMX6ULL first kernel module");
