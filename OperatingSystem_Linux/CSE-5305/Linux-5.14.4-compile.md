### download the source code
```shell
# 切换到您的源码目录
cd /usr/src

# 使用 wget 下载 Linux 5.14.4 源码
sudo wget https://cdn.kernel.org/pub/linux/kernel/v5.x/linux-5.14.4.tar.xz

# 解压下载的内核源码
sudo tar -xf linux-5.14.4.tar.xz

# 进入解压后的源码目录
cd linux-5.14.4
```

### install the required tools
```shell
sudo apt update
sudo apt install build-essential libncurses-dev bison flex libssl-dev libelf-dev
```

### 配置内核
- 这里我使用的是ubuntu-lts-2020版本，直接copy原本的内核
```shell
sudo cp /boot/config-$(uname -f) .config

# 保持default配置, 一直敲enter键
sudo make oldconfig
```

### compile
```shell
sudo make -j16

# sudo make modules
```
##### 遇到的问题
- Problem: No rule to make target 'debian/canonical-certs.pem', needed by 'certs/x509_certificate_list'. Stop
    - Solutions:
        - Solution: change the config
        ```shell
        sudo vim .config

        # let
        CONFIG_SYSTEM_TRUSTED_KEYS=""
        CONFIG_SYSTEM_REVOCATION_KEYS=""
        ```
- Problem: BTF: .tmp_vmlinux.btf: pahole(pahole) is not available, Failed to generate BTF for vmlinux; Try to disable CONFIG_DEBUG_INFO_BTF
    - Solutions:
    ```shell
    sudo vim .config

    let
    CONFIG_DEBUG_INFO_BTF=n
    ```


### install kernel
```shell
sudo make modules_install

sudo make install

# 更新引导程序
sudo update-grub

# 重启
sudo reboot
# 需要再GRUB菜单中选择新编译的内核
```

### 查看新内核是否成功
```shell
uname -r
```