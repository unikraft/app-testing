
### Quick Setup (aka TLDR)

For a quick setup, run the commands below.
Note that you still need to install the [requirements](#requirements).

For building and running everything for `x86_64`, follow the steps below:

```console
git clone https://github.com/unikraft/app-helloworld-cpp helloworld-cpp
cd helloworld-cpp/
git clone https://github.com/unikraft/unikraft .unikraft/unikraft
git clone https://github.com/unikraft/lib-libcxxabi .unikraft/libs/libcxxabi
git clone https://github.com/unikraft/lib-libcxx .unikraft/libs/libcxx
git clone https://github.com/unikraft/lib-compiler-rt .unikraft/libs/compiler-rt
git clone https://github.com/unikraft/lib-libunwind .unikraft/libs/libunwind
git clone https://github.com/unikraft/lib-musl .unikraft/libs/musl
git clone https://github.com/kallui/lib-gemmlowp .unikraft/libs/gemmlowp
UK_DEFCONFIG=$(pwd)/.config.helloworld-cpp-qemu-x86_64 make defconfig
```

run make menuconfig and enable gemmlowp


```
make -j $(nproc)
/usr/bin/qemu-system-x86_64 -kernel build/helloworld-cpp_qemu-x86_64 -nographic
```