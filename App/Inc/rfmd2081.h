#ifndef RFMD2081_H_
#define RFMD2081_H_

/*
 * @create time : 2024.07.21
 * @author      : Jayden Le
 * @email       : jayden_nan@qq.com
 */

#include "utils.h"
//------------------------------通信模式定义------------------------------
#define RFMD2081_THREE_WIRE_BUS     (1)                 // 你需要选择一种通信方式,且只能选择一种
#define RFMD2081_FOUR_WIRE_BUS      (0)

//------------------------------通信线定义------------------------------
#define RFMD2081_ENX_GPIO_PIN                   GPIO_PIN_1          // 使能引脚
#define RFMD2081_ENX_GPIO_TYPE                  GPIOA

#define RFMD2081_CLK_GPIO_PIN                   GPIO_PIN_1          // 时钟引脚
#define RFMD2081_CLK_GPIO_TYPE                  GPIOA

#if RFMD2081_THREE_WIRE_BUS                                         // 三线模式

#define RFMD2081_DATA_GPIO_PIN                  GPIO_PIN_1          // 数据引脚
#define RFMD2081_DATA_GPIO_TYPE                 GPIOA

#elif RFMD2081_FOUR_WIRE_BUS                            // 四线模式

#define RFMD2081_DI_GPIO_PIN                    GPIO_PIN_1          // 数据入
#define RFMD2081_DI_GPIO_TYPE                   GPIOA

#define RFMD2081_DO_GPIO_PIN                    GPIO_PIN_1          // 数据出
#define RFMD2081_DO_GPIO_TYPE                   GPIOA

#endif

//------------------------------地址表------------------------------
#define RFMD2081_REG_LF                         0x00
#define RFMD2081_REG_XO                         0x01
#define RFMD2081_REG_CAL_TIME                   0x02
#define RFMD2081_REG_VCO_CTRL                   0x03
#define RFMD2081_REG_CT_CAL1                    0x04
#define RFMD2081_REG_CT_CAL2                    0x05
#define RFMD2081_REG_PLL_CLA1                   0x06
#define RFMD2081_REG_PLL_CAL2                   0x07
#define RFMD2081_REG_VCO_AUTO                   0x08
#define RFMD2081_REG_PLL_CTRL                   0x09
#define RFMD2081_REG_PLL_BIAS                   0x0A
#define RFMD2081_REG_MIX_COUNT                  0x0B
#define RFMD2081_REG_P1_FREQ1                   0x0C
#define RFMD2081_REG_P1_FREQ2                   0x0D
#define RFMD2081_REG_P1_FREQ3                   0x0E
#define RFMD2081_REG_P2_FREQ1                   0x0F
#define RFMD2081_REG_P2_FREQ2                   0x10
#define RFMD2081_REG_P2_FREQ3                   0x11
#define RFMD2081_REG_FN_CTRL                    0x12
#define RFMD2081_REG_EXT_MOD                    0x13
#define RFMD2081_REG_FMOD                       0x14
#define RFMD2081_REG_SDI_CTRL                   0x15
#define RFMD2081_REG_GPO                        0x16
#define RFMD2081_REG_T_VCO                      0x17
#define RFMD2081_REG_IQMOD1                     0x18
#define RFMD2081_REG_IQMOD2                     0x19
#define RFMD2081_REG_IQMOD3                     0x1A
#define RFMD2081_REG_IQMOD4                     0x1B
#define RFMD2081_REG_T_CTRL                     0x1C
#define RFMD2081_REG_DEV_CTRL                   0x1D
#define RFMD2081_REG_TEST                       0x1E

//------------------------------默认值表------------------------------
#define RFMD2081_REG_DEF_VAL_LF                 0xBEFA
#define RFMD2081_REG_DEF_VAL_XO                 0x4064
#define RFMD2081_REG_DEF_VAL_CAL_TIME           0x9055
#define RFMD2081_REG_DEF_VAL_VCO_CTRL           0x2D02
#define RFMD2081_REG_DEF_VAL_CT_CAL1            0xB0BF
#define RFMD2081_REG_DEF_VAL_CT_CAL2            0xB0BF
#define RFMD2081_REG_DEF_VAL_PLL_CAL1           0x0028
#define RFMD2081_REG_DEF_VAL_PLL_CAL2           0x0028
#define RFMD2081_REG_DEF_VAL_VCO_AUTO           0xFC06
#define RFMD2081_REG_DEF_VAL_PLL_CTRL           0x8220
#define RFMD2081_REG_DEF_VAL_PLL_BIAS           0x0202
#define RFMD2081_REG_DEF_VAL_MIX_CONT           0x4800
#define RFMD2081_REG_DEF_VAL_P1_FREQ1           0x2324
#define RFMD2081_REG_DEF_VAL_P1_FREQ2           0x6276
#define RFMD2081_REG_DEF_VAL_P1_FREQ3           0x2700
#define RFMD2081_REG_DEF_VAL_P2_FREQ1           0x2F16
#define RFMD2081_REG_DEF_VAL_P2_FREQ2           0x3B13
#define RFMD2081_REG_DEF_VAL_P2_FREQ3           0xB100
#define RFMD2081_REG_DEF_VAL_FN_CTRL            0x2A80
#define RFMD2081_REG_DEF_VAL_EXT_MOD            0x0000
#define RFMD2081_REG_DEF_VAL_FMOD               0x0000
#define RFMD2081_REG_DEF_VAL_SDI_CTRL           0x0000
#define RFMD2081_REG_DEF_VAL_GPO                0x0000
#define RFMD2081_REG_DEF_VAL_T_VCO              0x0000
#define RFMD2081_REG_DEF_VAL_IQMOD1             0x0283
#define RFMD2081_REG_DEF_VAL_IQMOD2             0xF00F
#define RFMD2081_REG_DEF_VAL_IQMOD3             0x0000
#define RFMD2081_REG_DEF_VAL_IQMOD4             0x000F
#define RFMD2081_REG_DEF_VAL_T_CTRL             0x0000
#define RFMD2081_REG_DEF_VAL_DEV_CTRL           0x1000
#define RFMD2081_REG_DEF_VAL_TEST               0x0001


//------------------------------外接参数------------------------------
void RFMD2081_Init(void);

#endif
