struct file_operations fops =
{
open:	openDevice,
release:releaseDevice,
write:  writeDevice,
read:   readDevice,
unlocked_ioctl:ioctlDevice
};
