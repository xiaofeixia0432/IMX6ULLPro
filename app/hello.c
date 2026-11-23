/**
 * hello.c - 板卡首个交叉编译验证程序
 * 用法: ./hello [名字]
 */
#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc > 1)
        printf("Hello %s! IMX6ULL cross-compile OK.\n", argv[1]);
    else
        printf("Hello IMX6ULL! cross-compile OK.\n");
    return 0;
}
