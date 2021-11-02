sudo mkdir lofsdisk/bin
sudo cp /bin/bash lofsdisk/bin/
sudo cp /bin/ls lofsdisk/bin/
sudo cp /bin/echo lofsdisk/bin/
sudo cp /bin/cat lofsdisk/bin/
sudo cp /lib/x86_64-linux-gnu/libselinux.so.1 lofsdisk/lib/x86_64-linux-gnu/libselinux.so.1
sudo cp /lib/x86_64-linux-gnu/libc.so.6 lofsdisk/lib/x86_64-linux-gnu/libc.so.6
sudo cp /lib/x86_64-linux-gnu/libpcre2-8.so.0 lofsdisk/lib/x86_64-linux-gnu/libpcre2-8.so.0
sudo cp /lib/x86_64-linux-gnu/libdl.so.2 lofsdisk/lib/x86_64-linux-gnu/libdl.so.2
sudo cp /lib/x86_64-linux-gnu/libpthread.so.0 lofsdisk/lib/x86_64-linux-gnu/libpthread.so.0
sudo cp /lib64/ld-linux-x86-64.so.2 lofsdisk/lib64/ld-linux-x86-64.so.2
sudo chroot lofsdisk/ ./ex2.out > ex2.txt
./ex2.out>ex2.txt
