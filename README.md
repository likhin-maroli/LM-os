Here is a C based multiboot "hello world" kernel, which would be helpful for those who are interested in hobby OS development. And can be used as a starting point to your OS development journey!

# REQUIREMENTS FOR BUILDING
 1) A Linux system
 3) gcc compiler and binutils
 4) gnumake
 5) nasm 
 6) GRUB (To make bootable iso file)
 7) QEMU virtual machine

# BUILD PROCESS
1) On a terminal, cd to root directory
2) Run the  command `make iso`
3) And run `make run` or You can directly run `make run` (without first running `make iso`) which will automatically build iso file and run the kernel in qemu virtual machine

### Use it as a starting point of your OS development journey, without worrying about lower level assembly stuff!
## Happy OS Developing!

![](https://komarev.com/ghpvc/?username=likhin-maroli)
