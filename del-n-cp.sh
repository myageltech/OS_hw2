#!/bin/bash

sudo rm ~/linux-4.15.18-custom/arch/x86/entry/syscalls/syscall_64.tbl
sudo cp arch/x86/entry/syscalls/syscall_64.tbl ~/linux-4.15.18-custom/arch/x86/entry/syscalls/syscall_64.tbl

sudo rm ~/linux-4.15.18-custom/include/linux/syscalls.h 
sudo cp include/linux/syscalls.h ~/linux-4.15.18-custom/include/linux/syscalls.h
sudo rm ~/linux-4.15.18-custom/include/linux/sched.h
sudo cp include/linux/sched.h ~/linux-4.15.18-custom/include/linux/sched.h
sudo rm ~/linux-4.15.18-custom/include/linux/init_task.h
sudo cp include/linux/init_task.h ~/linux-4.15.18-custom/include/linux/init_task.h

sudo rm ~/linux-4.15.18-custom/init/main.o ~/linux-4.15.18-custom/init/main.c
sudo cp init/main.c ~/linux-4.15.18-custom/init/main.c

sudo rm ~/linux-4.15.18-custom/kernel/hw2.c
sudo rm ~/linux-4.15.18-custom/kernel/hw2.o
sudo cp kernel/hw2.c ~/linux-4.15.18-custom/kernel/hw2.c
sudo rm ~/linux-4.15.18-custom/kernel/Makefile
sudo cp kernel/Makefile ~/linux-4.15.18-custom/kernel/Makefile

rm test_hello.exe test1.exe

cd ~/linux-4.15.18-custom
make -j $(nproc)
sudo sudo cp -f arch/x86/boot/bzImage /boot/vmlinuz-4.15.18-custom
sudo reboot