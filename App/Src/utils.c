#include "utils.h"

UTILS_Status UTILS_RCC_GPIO_Enable(GPIO_TypeDef* GPIOx) {
    UTILS_Status status = UTILS_OK;

    if (GPIOx == GPIOA)     
        __HAL_RCC_GPIOA_CLK_ENABLE();
    else if (GPIOx == GPIOB)
        __HAL_RCC_GPIOB_CLK_ENABLE();
    else if (GPIOx == GPIOC)
        __HAL_RCC_GPIOC_CLK_ENABLE();
    else if (GPIOx == GPIOD)
        __HAL_RCC_GPIOD_CLK_ENABLE();
    else if (GPIOx == GPIOE)
        __HAL_RCC_GPIOE_CLK_ENABLE();
    else if (GPIOx == GPIOF)
        __HAL_RCC_GPIOF_CLK_ENABLE();
    else if (GPIOx == GPIOH)
        __HAL_RCC_GPIOH_CLK_ENABLE();
    else
        status = UTILS_ERROR;


    return status;
}
