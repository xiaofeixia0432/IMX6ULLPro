obj-m := hello.o

# 配套内核源码树路径（须与板卡运行内核版本一致），按实际位置修改或传参：
#   make KDIR=/path/to/linux-imx
KDIR ?= $(HOME)/kernel/linux-imx

# 交叉编译工具链前缀
CROSS_COMPILE ?= arm-none-linux-gnueabihf-

all:
	$(MAKE) -C $(KDIR) M=$(PWD) ARCH=arm CROSS_COMPILE=$(CROSS_COMPILE) modules

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean

.PHONY: all clean
