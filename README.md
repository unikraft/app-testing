# Unikraft Application Tests

Add tests of various applications and libraries running on top of Unikraft.

Enter the application directory and then run the `scripts/setup.sh` script.
For example, for C helloworld, run the commands:

```console
cd lang/c/helloworld/
../../../scripts/setup.sh
```

The setup script clones required repositories and generates the `Makefile` file.

Configure the application:

```console
make menuconfig
```

Build the application:

```console
make prepare
make -j $(nproc)
```

Run the application using the corresponding command, depending on your hypervisor and VMM (i.e. `qemu-system-x86_64`, `firecracker`).
