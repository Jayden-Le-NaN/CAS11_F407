#ifndef UTILS_H_
#define UTILS_H_

// 头文件功能: 包含公共的头文件供APP中的文件使用
//           : 包含公共的宏共APP中的文件使用

//------------------------------公用宏------------------------------
#define MCU_STM32F4XX
// #define MCU_STM32L4XX

#define MCU_FREQUENCY_MHZ       168         // STM32 系统时钟主频

//------------------------------HAL库文件------------------------------
#include "stm32f4xx.h"

typedef enum {
    UTILS_OK = 0x00,
    UTILS_ERROR = 0x01,
}UTILS_Status;

//------------------------------常用工具包------------------------------
UTILS_Status UTILS_RCC_GPIO_Enable(GPIO_TypeDef* GPIOx);
void UTILS_Delay_us(uint32_t us);

#endif
