/************************************************************************************
 * configs/stm32f0discovery/include/board.h
 *
 *   Copyright (C) 2017 Gregory Nutt. All rights reserved.
 *   Author: Gregory Nutt <gnutt@nuttx.org>
 *           Alan Carvalho de Assis <acassis@gmail.com>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name NuttX nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ************************************************************************************/

#ifndef __CONFIG_STM32F0DISCOVERY_INCLUDE_BOARD_H
#define __CONFIG_STM32F0DISCOVERY_INCLUDE_BOARD_H

/************************************************************************************
 * Included Files
 ************************************************************************************/

#include <nuttx/config.h>

#ifndef __ASSEMBLY__
# include <stdint.h>
#endif

/************************************************************************************
 * Pre-processor Definitions
 ************************************************************************************/

/* Clocking *************************************************************************/
/* Four different clock sources can be used to drive the system clock (SYSCLK):
 *
 * - HSI high-speed internal oscillator clock
 *   Generated from an internal 8 MHz RC oscillator
 * - HSE high-speed external oscillator clock
 *   Normally driven by an external crystal (X3).  However, this crystal is not
 *   fitted on the STM32F0-Discovery board.
 * - PLL clock
 * - MSI multispeed internal oscillator clock
 *   The MSI clock signal is generated from an internal RC oscillator. Seven frequency
 *   ranges are available: 65.536 kHz, 131.072 kHz, 262.144 kHz, 524.288 kHz, 1.048 MHz,
 *   2.097 MHz (default value) and 4.194 MHz.
 *
 * The devices have the following two secondary clock sources
 * - LSI low-speed internal RC clock
 *   Drives the watchdog and RTC.  Approximately 37KHz
 * - LSE low-speed external oscillator clock
 *   Driven by 32.768KHz crystal (X2) on the OSC32_IN and OSC32_OUT pins.
 */

#define STM32F0_BOARD_XTAL         8000000ul        /* X3 on board (not fitted)*/

#define STM32F0_HSI_FREQUENCY      8000000ul        /* Approximately 8MHz */
#define STM32F0_HSE_FREQUENCY      STM32F0_BOARD_XTAL
#define STM32F0_MSI_FREQUENCY      2097000          /* Default is approximately 2.097Mhz */
#define STM32F0_LSI_FREQUENCY      37000            /* Approximately 37KHz */
#define STM32F0_LSE_FREQUENCY      32768            /* X2 on board */

/* This is the clock setup we configure for:
 *
 *   SYSCLK  = BOARD_OSCCLK_FREQUENCY = 12MHz -> Select Main oscillator for source
 *   PLL0CLK = (2 * 20 * SYSCLK) / 1 = 480MHz -> PLL0 multipler=20, pre-divider=1
 *   MCLK    = 480MHz / 6 = 80MHz             -> MCLK divider = 6
 */

#define STM32F0_MCLK               48000000         /* 48Mhz */

/* PLL Configuration
 *
 *   - PLL source is HSI        -> 8MHz input (nominal)
 *   - PLL source pre-divider 2 -> 4MHz divided down PLL VCO clock output
 *   - PLL multipler is 6       -> 24MHz PLL VCO clock output (for USB)
 *
 * Resulting SYSCLK frequency is 8MHz x 6 / 2 = 24MHz
 *
 * USB/SDIO:
 *   If the USB or SDIO interface is used in the application, the PLL VCO
 *   clock (defined by STM32F0_CFGR_PLLMUL) must be programmed to output a 96
 *   MHz frequency. This is required to provide a 48 MHz clock to the USB or
 *   SDIO (SDIOCLK or USBCLK = PLLVCO/2).
 * SYSCLK
 *   The system clock is derived from the PLL VCO divided by the output division factor.
 * Limitations:
 *   96 MHz as PLLVCO when the product is in range 1 (1.8V),
 *   48 MHz as PLLVCO when the product is in range 2 (1.5V),
 *   24 MHz when the product is in range 3 (1.2V).
 *   Output division to avoid exceeding 32 MHz as SYSCLK.
 *   The minimum input clock frequency for PLL is 2 MHz (when using HSE as PLL source).
 */

#define STM32F0_CFGR_PLLSRC        RCC_CFGR_PLLSRC_HSId2        /* Source is HSI/2 */
#define STM32F0_PLLSRC_FREQUENCY   (STM32F0_HSI_FREQUENCY/2)
#ifdef CONFIG_STM32F0_USB
#  undef  STM32F0_CFGR2_PREDIV                                  /* Not used with source HSI/2 */
#  define STM32F0_CFGR_PLLMUL      RCC_CFGR_PLLMUL_CLKx6        /* PLLMUL = 6 */
#  define STM32F0_PLL_FREQUENCY    (6*STM32F0_PLLSRC_FREQUENCY) /* PLL VCO Frequency is 24MHz */
#else
#  undef  STM32F0_CFGR2_PREDIV                                  /* Not used with source HSI/2 */
#  define STM32F0_CFGR_PLLMUL      RCC_CFGR_PLLMUL_CLKx6        /* PLLMUL = 6 */
#  define STM32F0_PLL_FREQUENCY    (6*STM32F0_PLLSRC_FREQUENCY) /* PLL VCO Frequency is 24MHz */
#endif

/* Use the PLL and set the SYSCLK source to be the divided down PLL VCO output
 * frequency (STM32F0_PLL_FREQUENCY divided by the PLLDIV value).
 */

#define STM32F0_SYSCLK_SW          RCC_CFGR_SW_PLL         /* Use the PLL as the SYSCLK */
#define STM32F0_SYSCLK_SWS         RCC_CFGR_SWS_PLL
#ifdef CONFIG_STM32F0_USB
#  define STM32F0_SYSCLK_FREQUENCY STM32F0_PLL_FREQUENCY /* SYSCLK frequency is PLL VCO = 24MHz */
#else
#  define STM32F0_SYSCLK_FREQUENCY STM32F0_PLL_FREQUENCY /* SYSCLK frequency is PLL VCO = 24MHz */
#endif

/* AHB clock (HCLK) is SYSCLK (24MHz) */

#define STM32F0_RCC_CFGR_HPRE      RCC_CFGR_HPRE_SYSCLK
#define STM32F0_HCLK_FREQUENCY     STM32F0_SYSCLK_FREQUENCY
#define STM32F0_BOARD_HCLK         STM32F0_HCLK_FREQUENCY    /* Same as above, to satisfy compiler */

/* APB1 clock (PCLK1) is HCLK (24MHz) */

#define STM32F0_RCC_CFGR_PPRE1     RCC_CFGR_PPRE1_HCLK
#define STM32F0_PCLK1_FREQUENCY    (STM32F0_HCLK_FREQUENCY)

/* APB2 clock (PCLK2) is HCLK (24MHz) */

#define STM32F0_RCC_CFGR_PPRE2     RCC_CFGR_PPRE2_HCLK
#define STM32F0_PCLK2_FREQUENCY    STM32F0_HCLK_FREQUENCY
#define STM32F0_APB2_CLKIN         (STM32F0_PCLK2_FREQUENCY)

/* APB1 timers 1-3, 6-7, and 14-17 will receive PCLK1 */

#define STM32F0_APB1_TIM1_CLKIN    (STM32F0_PCLK1_FREQUENCY)
#define STM32F0_APB1_TIM2_CLKIN    (STM32F0_PCLK1_FREQUENCY)
#define STM32F0_APB1_TIM3_CLKIN    (STM32F0_PCLK1_FREQUENCY)

#define STM32F0_APB1_TIM6_CLKIN    (STM32F0_PCLK1_FREQUENCY)
#define STM32F0_APB1_TIM7_CLKIN    (STM32F0_PCLK1_FREQUENCY)

#define STM32F0_APB1_TIM14_CLKIN   (STM32F0_PCLK1_FREQUENCY)
#define STM32F0_APB1_TIM15_CLKIN   (STM32F0_PCLK1_FREQUENCY)
#define STM32F0_APB1_TIM16_CLKIN   (STM32F0_PCLK1_FREQUENCY)
#define STM32F0_APB1_TIM17_CLKIN   (STM32F0_PCLK1_FREQUENCY)

/* LED definitions ******************************************************************/
/* The STM32F0-Discovery board has four LEDs.  Two of these are controlled by
 * logic on the board and are not available for software control:
 *
 * LD1 COM:   LD2 default status is red. LD2 turns to green to indicate that
 *            communications are in progress between the PC and the ST-LINK/V2.
 * LD2 PWR:   Red LED indicates that the board is powered.
 *
 * And two LEDs can be controlled by software:
 *
 * User LD3:  Green LED is a user LED connected to the I/O PB7 of the STM32F051R8
 *            MCU.
 * User LD4:  Blue LED is a user LED connected to the I/O PB6 of the STM32F051R8
 *            MCU.
 *
 * If CONFIG_ARCH_LEDS is not defined, then the user can control the LEDs in any
 * way.  The following definitions are used to access individual LEDs.
 */

/* LED index values for use with board_userled() */

#define BOARD_LED1               0 /* User LD3 */
#define BOARD_LED2               1 /* User LD4 */
#define BOARD_NLEDS              2

/* LED bits for use with board_userled_all() */

#define BOARD_LED1_BIT           (1 << BOARD_LED1)
#define BOARD_LED2_BIT           (1 << BOARD_LED2)

/* If CONFIG_ARCH_LEDs is defined, then NuttX will control the 8 LEDs on board the
 * STM32F0-Discovery.  The following definitions describe how NuttX controls the LEDs:
 *
 *   SYMBOL                Meaning                 LED state
 *                                                   LED1     LED2
 *   -------------------  -----------------------  -------- --------
 *   LED_STARTED          NuttX has been started     OFF      OFF
 *   LED_HEAPALLOCATE     Heap has been allocated    OFF      OFF
 *   LED_IRQSENABLED      Interrupts enabled         OFF      OFF
 *   LED_STACKCREATED     Idle stack created         ON       OFF
 *   LED_INIRQ            In an interrupt              No change
 *   LED_SIGNAL           In a signal handler          No change
 *   LED_ASSERTION        An assertion failed          No change
 *   LED_PANIC            The system has crashed     OFF      Blinking
 *   LED_IDLE             STM32 is is sleep mode       Not used
 */

#define LED_STARTED              0
#define LED_HEAPALLOCATE         0
#define LED_IRQSENABLED          0
#define LED_STACKCREATED         1
#define LED_INIRQ                2
#define LED_SIGNAL               2
#define LED_ASSERTION            2
#define LED_PANIC                3

/* Button definitions ***************************************************************/
/* The STM32F0-Discovery supports two buttons; only one button is controllable by
 * software:
 *
 *   B1 USER: user and wake-up button connected to the I/O PA0 of the STM32F051R8.
 *   B2 RESET: pushbutton connected to NRST is used to RESET the STM32F051R8.
 */

#define BUTTON_USER              0
#define NUM_BUTTONS              1

#define BUTTON_USER_BIT          (1 << BUTTON_USER)

/* Alternate Pin Functions **********************************************************/

#endif  /* __CONFIG_STM32F0DISCOVERY_INCLUDE_BOARD_H */