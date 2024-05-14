/*
    Copyright (C) 2021 essemi

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

#ifndef MCUCONF_H
#define MCUCONF_H

#define ES32_FS026_MCUCONF
#define ES32_ES32F0283_MCUCONF

/*
 * HAL driver system settings.
 */
#define ES32_NO_INIT   FALSE

/*system_clk select

MD_RCU_SW_SYSCLK_HRC   = HRC selected as system clock
MD_RCU_SW_SYSCLK_HOSC  = HOSC selected as system clock
MD_RCU_SW_SYSCLK_PLL0  = PLL0 selected as system clock
MD_RCU_SW_SYSCLK_HRC48 = HRC48 selected as system clock
*/
#define ES32_SYSCLK_SOURSE_SELECT   MD_RCU_SW_SYSCLK_PLL0

/*external clk config*/
#define ES32_HOSC_CLK_EN            FALSE
#define ES32_HOSC_CLK_FREQ          8

/*pll clk config

MD_RCU_PLLSRC_HRC     = HRC selected as PLL reference clock
MD_RCU_PLLSRC_HOSC    = HOSC selected as PLL reference clock
MD_RCU_PLLSRC_HRC48   = HRC48 selected as PLL reference clock

MD_RCU_PLLCLK_PASS    = 0
MD_RCU_PLLCLK_4M      = 4000000
MD_RCU_PLLCLK_8M      = 8000000
MD_RCU_PLLCLK_12M     = 12000000
MD_RCU_PLLCLK_16M     = 16000000
MD_RCU_PLLCLK_24M     = 24000000
MD_RCU_PLLCLK_32M     = 32000000
MD_RCU_PLLCLK_36M     = 36000000
MD_RCU_PLLCLK_40M     = 40000000
MD_RCU_PLLCLK_48M     = 48000000
MD_RCU_PLLCLK_64M     = 64000000
MD_RCU_PLLCLK_72M     = 72000000
*/
#define ES32_PLL_CLK_EN             TRUE
#define ES32_PLL_SOURSE_SELECT      MD_RCU_PLLSRC_HRC48
#define ES32_PLL_CLK_FREQ           MD_RCU_PLLCLK_72M

/*bus clk config

MD_RCU_HPRE_SYSCLK_DIV_1     = SYSCLK not divided
MD_RCU_HPRE_SYSCLK_DIV_2     = SYSCLK divided by 2
MD_RCU_HPRE_SYSCLK_DIV_4     = SYSCLK divided by 4
MD_RCU_HPRE_SYSCLK_DIV_8     = SYSCLK divided by 8
MD_RCU_HPRE_SYSCLK_DIV_16    = SYSCLK divided by 16
MD_RCU_HPRE_SYSCLK_DIV_64    = SYSCLK divided by 64
MD_RCU_HPRE_SYSCLK_DIV_128   = SYSCLK divided by 128
MD_RCU_HPRE_SYSCLK_DIV_256   = SYSCLK divided by 256
MD_RCU_HPRE_SYSCLK_DIV_512   = @brief SYSCLK divided by 512

MD_RCU_PPRE_HCLK_DIV_1       = HCLK not divided
MD_RCU_PPRE_HCLK_DIV_2       = HCLK divided by 2
MD_RCU_PPRE_HCLK_DIV_4       = HCLK divided by 4
MD_RCU_PPRE_HCLK_DIV_8       = HCLK divided by 8
MD_RCU_PPRE_HCLK_DIV_16      = HCLK divided by 16
*/
#define ES32_BUS_DIV_HPRE    MD_RCU_HPRE_SYSCLK_DIV_1
#define ES32_BUS_DIV_PPRE    MD_RCU_PPRE_HCLK_DIV_1

/*
 * EXTI driver system settings.
 */
#define WB32_IRQ_EXTI0_1_PRIORITY            6
#define WB32_IRQ_EXTI2_3_PRIORITY            6
#define WB32_IRQ_EXTI4_15_PRIORITY           6

/*
 * GPT driver system settings.
 */
#define ES32_GPT_USE_AD16C4T1 FALSE
#define ES32_GPT_USE_GP32C4T1 FALSE
#define ES32_GPT_USE_GP16C4T1 FALSE
#define ES32_GPT_USE_GP16C4T2 FALSE
#define ES32_GPT_USE_GP16C4T3 FALSE
#define ES32_GPT_USE_GP16C2T1 FALSE
#define ES32_GPT_USE_GP16C2T2 FALSE
#define ES32_GPT_USE_GP16C2T3 FALSE
#define ES32_GPT_USE_GP16C2T4 FALSE
#define ES32_GPT_USE_BS16T1   FALSE
#define ES32_GPT_AD16C4T1_IRQ_PRIORITY         7
#define ES32_GPT_GP32C4T1_IRQ_PRIORITY         7
#define ES32_GPT_GP16C4T1_IRQ_PRIORITY         7
#define ES32_GPT_GP16C4T2_IRQ_PRIORITY         7
#define ES32_GPT_GP16C4T3_IRQ_PRIORITY         7
#define ES32_GPT_GP16C2T1_IRQ_PRIORITY         7
#define ES32_GPT_GP16C2T2_IRQ_PRIORITY         7
#define ES32_GPT_GP16C2T3_IRQ_PRIORITY         7
#define ES32_GPT_GP16C2T4_IRQ_PRIORITY         7
#define ES32_GPT_BS16T1_IRQ_PRIORITY           7

/*
 * ICU driver system settings.
 */
#define ES32_ICU_USE_AD16C4T1 FALSE
#define ES32_ICU_USE_GP32C4T1 FALSE
#define ES32_ICU_USE_GP16C4T1 FALSE
#define ES32_ICU_USE_GP16C4T2 FALSE
#define ES32_ICU_USE_GP16C4T3 FALSE
#define ES32_ICU_USE_GP16C2T1 FALSE
#define ES32_ICU_USE_GP16C2T2 FALSE
#define ES32_ICU_USE_GP16C2T3 FALSE
#define ES32_ICU_USE_GP16C2T4 FALSE
#define ES32_ICU_AD16C4T1_IRQ_PRIORITY 7
#define ES32_ICU_GP32C4T1_IRQ_PRIORITY 7
#define ES32_ICU_GP16C4T1_IRQ_PRIORITY 7
#define ES32_ICU_GP16C4T2_IRQ_PRIORITY 7
#define ES32_ICU_GP16C4T3_IRQ_PRIORITY 7
#define ES32_ICU_GP16C2T1_IRQ_PRIORITY 7
#define ES32_ICU_GP16C2T2_IRQ_PRIORITY 7
#define ES32_ICU_GP16C2T3_IRQ_PRIORITY 7
#define ES32_ICU_GP16C2T4_IRQ_PRIORITY 7

/*
 * I2C driver system settings.
 */
#define ES32_I2C_USE_I2C1                  FALSE
#define ES32_I2C_USE_I2C2                  FALSE
#define ES32_I2C_BUSY_TIMEOUT              50
#define ES32_I2C_I2C1_IRQ_PRIORITY         5
#define ES32_I2C_I2C2_IRQ_PRIORITY         5

/*
 * SERIAL driver system settings.
 */
#define ES32_SERIAL_USE_UART1              FALSE
#define ES32_SERIAL_USE_UART2              FALSE
#define ES32_SERIAL_USE_UART3              FALSE
#define ES32_SERIAL_USE_UART4              FALSE
#define ES32_SERIAL_UART1_PRIORITY        7
#define ES32_SERIAL_UART2_PRIORITY        7
#define ES32_SERIAL_UART3_PRIORITY        7
#define ES32_SERIAL_UART4_PRIORITY        7

/*
 * SPI driver system settings.
 */
#define ES32_SPI_USE_SPI1                  FALSE
#define ES32_SPI_USE_SPI2                  FALSE
#define ES32_SPI_USE_SPI3                  FALSE
#define WB32_SPI_SPI1_IRQ_PRIORITY         10
#define WB32_SPI_SPI2_IRQ_PRIORITY         10
#define WB32_SPI_SPI3_IRQ_PRIORITY         10

/*
 * ST driver system settings.
 */
#define ES32_ST_IRQ_PRIORITY                8
#define ES32_ST_USE_TIMER                   2

/*
 * UART driver system settings.
 */
#define ES32_UART_USE_UART1                 FALSE
#define ES32_UART_USE_UART2                 FALSE
#define ES32_UART_USE_UART3                 FALSE
#define ES32_UART_USE_UART4                 FALSE
#define ES32_UART_UART1_IRQ_PRIORITY        12
#define ES32_UART_UART2_IRQ_PRIORITY        12
#define ES32_UART_UART3_IRQ_PRIORITY        12
#define ES32_UART_UART4_IRQ_PRIORITY        12

/*
 * PWM driver system settings.
 */
#define ES32_PWM_USE_AD16C4T1 FALSE
#define ES32_PWM_USE_GP32C4T1 FALSE
#define ES32_PWM_USE_GP16C4T1 FALSE
#define ES32_PWM_USE_GP16C4T2 TRUE
#define ES32_PWM_USE_GP16C4T3 FALSE
#define ES32_PWM_USE_GP16C2T1 FALSE
#define ES32_PWM_USE_GP16C2T2 FALSE
#define ES32_PWM_USE_GP16C2T3 FALSE
#define ES32_PWM_USE_GP16C2T4 FALSE
#define ES32_PWM_AD16C4T1_IRQ_PRIORITY 7
#define ES32_PWM_GP32C4T1_IRQ_PRIORITY 7
#define ES32_PWM_GP16C4T1_IRQ_PRIORITY 7
#define ES32_PWM_GP16C4T2_IRQ_PRIORITY 7
#define ES32_PWM_GP16C4T3_IRQ_PRIORITY 7
#define ES32_PWM_GP16C2T1_IRQ_PRIORITY 7
#define ES32_PWM_GP16C2T2_IRQ_PRIORITY 7
#define ES32_PWM_GP16C2T3_IRQ_PRIORITY 7
#define ES32_PWM_GP16C2T4_IRQ_PRIORITY 7

/*
 * USB driver system settings.
 */
#define ES32_USB_USE_USB1                   TRUE
#define ES32_USB_USB1_IRQ_PRIORITY          13
#define ES32_USE_USB_SOF_TRIM_HRC48         TRUE

#endif /* MCUCONF_H */
