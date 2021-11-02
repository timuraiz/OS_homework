cd week11
fallocate -l 50M lofs.img
losetup -a
losetup -f 
sudo losetup -f lofs.img
sudo mkfs.
sudo mkfs
sudo mkfs.
sudo mkfs.ext4 /dev/loop0
losetup -a | grep 'lofs.img'
mkdir lofsdisk
sudo mount /dev/loop0 lofsdisk/