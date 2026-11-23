#!/bin/sh
# deploy.sh - 把编译产物推到板卡并运行
# 用法: ./deploy.sh <可执行文件> [板卡IP]
#   ./deploy.sh hello 192.168.5.9

FILE="$1"
BOARD="${2:-192.168.5.9}"

if [ -z "$FILE" ] || [ ! -f "$FILE" ]; then
    echo "用法: $0 <可执行文件> [板卡IP，默认 $BOARD]"
    exit 1
fi

echo "==> 传输 $FILE 到 root@$BOARD:/root/"
scp "$FILE" "root@$BOARD:/root/" || exit 1

echo "==> 板卡上执行"
ssh "root@$BOARD" "chmod +x /root/$(basename "$FILE") && /root/$(basename "$FILE")"

# 串口终端（无网络时）: putty 115200 8N1 无流控, D:\tools\putty.exe
