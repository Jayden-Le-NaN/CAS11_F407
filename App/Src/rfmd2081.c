#include "rfmd2081.h"


/*
 * @brief               rfmd2081初始化
 * @return              无
 * @author              Chosifew && JaydenLe
 */
void RFMD2081_Init(void) {
    
    //------------------------------时钟使能------------------------------
    UTILS_RCC_GPIO_Enable(RFMD2081_ENX_GPIO_TYPE);
    UTILS_RCC_GPIO_Enable(RFMD2081_CLK_GPIO_TYPE);

#if RFMD2081_THREE_WIRE_BUS                             // 三线模式
    UTILS_RCC_GPIO_Enable(RFMD2081_DATA_GPIO_TYPE);
#elif RFMD2081_FOUR_WIRE_BUS                            // 四线模式
    UTILS_RCC_GPIO_Enable(RFMD2081_DI_GPIO_TYPE);
    UTILS_RCC_GPIO_Enable(RFMD2081_DO_GPIO_TYPE);
#endif

    //------------------------------引脚默认值设置------------------------------
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    HAL_GPIO_WritePin(RFMD2081_ENX_GPIO_TYPE, RFMD2081_ENX_GPIO_PIN, GPIO_PIN_SET);
    HAL_GPIO_WritePin(RFMD2081_CLK_GPIO_TYPE, RFMD2081_CLK_GPIO_PIN, GPIO_PIN_SET);

#if RFMD2081_THREE_WIRE_BUS                             // 三线模式
    HAL_GPIO_WritePin(RFMD2081_DATA_GPIO_TYPE, RFMD2081_DATA_GPIO_PIN, GPIO_PIN_SET);
#elif RFMD2081_FOUR_WIRE_BUS                            // 四线模式
    HAL_GPIO_WritePin(RFMD2081_DI_GPIO_TYPE, RFMD2081_DI_GPIO_PIN, GPIO_PIN_SET);
    HAL_GPIO_WritePin(RFMD2081_DO_GPIO_TYPE, RFMD2081_DO_GPIO_PIN, GPIO_PIN_SET);
#endif

    //------------------------------引脚GPIO设置------------------------------
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;

    GPIO_InitStruct.Pin = RFMD2081_ENX_GPIO_PIN;
    HAL_GPIO_Init(RFMD2081_ENX_GPIO_TYPE, &GPIO_InitStruct);
    GPIO_InitStruct.Pin = RFMD2081_CLK_GPIO_PIN;
    HAL_GPIO_Init(RFMD2081_CLK_GPIO_TYPE, &GPIO_InitStruct);
    
#if RFMD2081_THREE_WIRE_BUS                             // 三线模式
    GPIO_InitStruct.Pin = RFMD2081_DATA_GPIO_PIN;
    HAL_GPIO_Init(RFMD2081_DATA_GPIO_TYPE, &GPIO_InitStruct);
#elif RFMD2081_FOUR_WIRE_BUS                            // 四线模式
    GPIO_InitStruct.Pin = RFMD2081_DATA_GPIO_PIN;
    HAL_GPIO_Init(RFMD2081_DATA_GPIO_TYPE, &GPIO_InitStruct);
    GPIO_InitStruct.Pin = RFMD2081_DATA_GPIO_PIN;
    HAL_GPIO_Init(RFMD2081_DATA_GPIO_TYPE, &GPIO_InitStruct);
#endif
}


