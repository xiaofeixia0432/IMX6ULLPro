# IMX6ULLPro

IMX6ULL 开发板（Linux 应用/驱动路线）工程仓库。开发环境为 Windows 原生交叉编译。

## 环境

| 组件 | 位置/命令 | 说明 |
|---|---|---|
| 交叉工具链 | `arm-none-linux-gnueabihf-gcc` | Arm 官方 GCC 10.3（mingw-w64 版），已加入 PATH |
| make | `mingw32-make` | mingw-w64 自带 |
| 串口终端 | `D:\tools\putty.exe` | 115200 8N1 无流控 |
| 文件传输 | `pscp` / `scp` | 板卡 IP 默认假设 `192.168.5.9`，按实际改 |

工具链源包备份：`D:\downloads\gcc-arm-10.3-2021.07-mingw-w64-i686-arm-none-linux-gnueabihf.tar.xz`
（重装系统可直接解压复用，官方直链：`https://developer.arm.com/-/media/Files/downloads/gnu-a/10.3-2021.07/binrel/gcc-arm-10.3-2021.07-mingw-w64-i686-arm-none-linux-gnueabihf.tar.xz`）

## 目录结构

```
app/           板卡用户态程序（每个 .c 编译为一个可执行文件，输出到 images/）
driver/hello/  第一个内核模块示例
images/        编译产物
scripts/       部署脚本
```

## 构建与部署

```bash
# 1. 编译所有用户态程序（产物在 images/）
cd app && mingw32-make

# 2. 验证产物架构
arm-none-linux-gnueabihf-readelf -h ../images/hello | grep -E "Machine|Class"

# 3. 传输到板卡并运行
./scripts/deploy.sh images/hello <板卡IP>
#   或手动: pscp images/hello root@<板卡IP>:/root/
```

## 内核模块（driver/）

内核模块**不能在 Windows 上编译**，需要 Linux 环境（WSL/虚拟机）+ 与板卡内核版本一致的源码树：

```bash
cd driver/hello
make KDIR=/path/to/linux-imx   # 在 Linux 环境执行
# 板卡上: insmod hello.ko && dmesg | tail
```

## 注意

- GitHub 直连不通时用镜像：`https://ghfast.top/https://github.com/xiaofeixia0432/IMX6ULLPro.git`（clone 用）；push 需配置 SSH key 或走代理
- 板卡默认 root 登录，串口/网络二选一部署
