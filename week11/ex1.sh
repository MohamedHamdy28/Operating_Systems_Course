fallocate -l $((50*1024*1024)) lofs.img
sudo losetup -f lofs.img
sudo mkfs.ext4 /dev/loop15
mkdir lofsdisk
sudo mount /dev/loop15 lofsdisk

