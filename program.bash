openocd -f ~/ChipCode/stm32/openocd_cfg/cmsis-dap.cfg -f ~/ChipCode/stm32/openocd_cfg/stm32f4x.cfg -c "program ./build/071502_Modulatoin.elf verify reset exit"
