lenovo_p700i_kernel
===================

Modifyded sources from http://mobilesupport.lenovo.com/us/en/products/p700i_smartphone

export PATH=~/Your_Toolchain_PATH/
for example /alps/prebuilt/linux-x86/toolchain/arm-linux-androideabi-4.4.x/bin
Build Command:

kernel
======
cd kernel directory
TARGET_PRODUCT=lenovo77_cu_ics2 MTK_ROOT_CUSTOM=../mediatek/custom/ make



