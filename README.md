# Unikraft Application Tests

Add tests of various applications and libraries running on top of Unikraft.

## Use an Application Test

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

## Add a New Application Test

New application tests will get their own directories, similar to the [helloworld C](https://github.com/unikraft/app-testing/tree/master/lang/c/helloworld) or [helloworld C++](https://github.com/unikraft/app-testing/tree/master/lang/cpp/helloworld) applications.

Steps to be done are:

1. Create the new application directory.

1. Inside the new application directory, add source code files and the `Makefile.uk` file that uses the source code files for the build.

1. Fill the `libs.txt` with the [depending Unikraft libraries](https://github.com/unikraft/TODO).
   Add one library per-line, **without** the `lib-` prefix for the repository name.
   That is, for the [`lib-libcxx` repository](https://github.com/unikraft/lib-libcxx), add `libcxx`;
   for the [`lib-musl` repository](https://github.com/unikraft/lib-musl) add `musl`;
   for the [`lib-openssl` repository](https://github.com/unikraft/lib-openssl) add `openssl`.

This is it, you can now commit your changes to the [`app-testing` repository](https://github.com/unikraft/app-testing).

Now, to test it, follow the steps also mentioned above:

1. Inside the app directory, run the `scripts/setup.sh` script.
   Be sure to provide the proper path to the script;
   depending on your app directory, this may be something like `../../../scripts/setup.sh` or `../../scripts/setup.sh` or `../scripts/setup.sh`.

   The `scripts/setup.sh` script will create the `workdir/` directory with all the repository clones (the [`unikraft` repository](https://github.com/unikraft/unikraft) and [required library repositories](https://github.com/unikraft/)).
   It will also create the `Makefile` file used for configuring and building the application.

1. Configure the application with `make menuconfig`.

1. Build the application with `make prepare` and `make -j $(nproc)`.

1. Run the application with the corresponding run command.
