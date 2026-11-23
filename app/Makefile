# Windows 下用 mingw32-make 调用本 Makefile
CROSS_COMPILE ?= arm-none-linux-gnueabihf-
CC      := $(CROSS_COMPILE)gcc
CFLAGS  := -Wall -Wextra -O2
LDFLAGS :=

# 所有 app/ 下的 .c 各生成一个可执行文件（输出到 ../images/）
IMAGES_DIR := ../images
TARGETS := $(patsubst %.c,%,$(wildcard *.c))
OUT := $(addprefix $(IMAGES_DIR)/,$(TARGETS))

all: $(OUT)

$(IMAGES_DIR):
	mkdir -p $(IMAGES_DIR)

$(IMAGES_DIR)/%: %.c | $(IMAGES_DIR)
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

clean:
	rm -f $(OUT)

.PHONY: all clean
