# CAS11

## 1. 工具

> cmake
> 
> make
> 
> gcc-arm
> 
> openocd

## 2. 编译与下载

```bash
# 编译
mkdir build
cd build
cmake ..
make -j8
```

```bash
# 下载
./program.bash
```



```bash
# 你需要更改下program.bash中的路径
openocd -f ~/ChipCode/stm32/openocd_cfg/cmsis-dap.cfg -f ~/ChipCode/stm32/openocd_cfg/stm32f4x.cfg -c "program ./build/071502_Modulatoin.elf verify reset exit"

# 把两个.cfg文件更改为自己路径下的.cfg文件
```
