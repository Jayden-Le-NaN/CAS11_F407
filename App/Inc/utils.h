#ifndef UTILS_H_
#define UTILS_H_

#include "headfiles.h"

typedef enum {
    UTILS_OK = 0x00,
    UTILS_ERROR = 0x01,
}UTILS_Status;

//------------------------------常用工具包------------------------------
UTILS_Status UTILS_RCC_GPIO_Enable(GPIO_TypeDef* GPIOx);

#endif
