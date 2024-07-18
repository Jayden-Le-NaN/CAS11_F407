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

/*
 * @brief               以微秒级延时
 * @param delay         延时的时间
 * @return              无
 */
void UTILS_Delay_us(__IO uint32_t delay) {
    // 系统嘀嗒定时器计完一次数是1ms
    int32_t last, curr, val;
    int32_t tmp;
    while (delay != 0) {
        tmp = delay > 900 ? 900 : delay;
        last = SysTick->VAL;
        curr = last - MCU_FREQUENCY_MHZ * tmp;
        if (curr >= 0) {
            do {
                val = SysTick->VAL;
            }while((val < last) && (val >= curr));
        }
        else {
            curr += MCU_FREQUENCY_MHZ * 1000;
            do {
                val = SysTick->VAL;
            }while((val <= last) || (val) > curr);
        }
        delay -= tmp;
    }
}
