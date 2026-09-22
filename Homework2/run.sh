rm -rf user/*.d kernel/*.d user/usys\ *.S user/_*\ * kernel/kernel\ * 
make clean
make
make CPUS=1 qemu
