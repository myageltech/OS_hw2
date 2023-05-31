#!/bin/bash

rm ~/linux-4.15.18-custom/arch/x86/entry/syscalls/syscall_64.tbl
cp arch/x86/entry/syscalls/syscall_64.tbl ~/linux-4.15.18-custom/arch/x86/entry/syscalls/syscall_64.tbl

rm ~/linux-4.15.18-custom/include/linux/syscalls.h 
cp include/linux/syscalls.h ~/linux-4.15.18-custom/include/linux/syscalls.h
rm ~/linux-4.15.18-custom/include/linux/sched.h
cp include/linux/sched.h ~/linux-4.15.18-custom/include/linux/sched.h
rm ~/linux-4.15.18-custom/include/linux/init_task.h
cp include/linux/init_task.h ~/linux-4.15.18-custom/include/linux/init_task.h

rm ~/linux-4.15.18-custom/init/main.o ~/linux-4.15.18-custom/init/main.c
cp init/main.c ~/linux-4.15.18-custom/init/main.c

rm ~/linux-4.15.18-custom/kernel/hw2.c
rm ~/linux-4.15.18-custom/kernel/hw2.o
cp kernel/hw2.c ~/linux-4.15.18-custom/kernel/hw2.c
rm ~/linux-4.15.18-custom/kernel/Makefile
cp kernel/Makefile ~/linux-4.15.18-custom/kernel/Makefile

cd ~/linux-4.15.18-custom
make -j $(nproc)
sudo cp -f arch/x86/boot/bzImage /boot/vmlinuz-4.15.18-custom




