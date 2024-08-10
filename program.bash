cd ./build
make -j8
openocd -f ~/ChipCode/stm32/openocd_cfg/cmsis-dap.cfg -f ~/ChipCode/stm32/openocd_cfg/stm32f4x.cfg -c "program ./071502_Modulatoin.elf verify reset exit"
cd ..
