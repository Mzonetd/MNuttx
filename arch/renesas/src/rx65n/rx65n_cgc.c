/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "rx65n_macrodriver.h"
#include "rx65n_cgc.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_CGC_Create
* Description  : This function initializes the clock generator.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_CGC_Create(void)
{
    /* Set main clock control registers */
    SYSTEM.MOFCR.BYTE = _00_CGC_MAINOSC_RESONATOR | _00_CGC_MAINOSC_UNDER24M;
    SYSTEM.MOSCWTCR.BYTE = _5C_CGC_MOSCWTCR_VALUE;

    /* Set main clock operation */
    SYSTEM.MOSCCR.BIT.MOSTP = 0U;

    /* Wait for main clock oscillator wait counter overflow */
    while (1U != SYSTEM.OSCOVFSR.BIT.MOOVF)
    {
        /* Do nothing */
    }

    /* Set system clock */
    SYSTEM.SCKCR.LONG = _00000002_CGC_PCLKD_DIV_4 | _00000020_CGC_PCLKC_DIV_4 | _00000200_CGC_PCLKB_DIV_4 | 
                        _00001000_CGC_PCLKA_DIV_2 | _00010000_CGC_BCLK_DIV_2 | _01000000_CGC_ICLK_DIV_2 | 
                        _20000000_CGC_FCLK_DIV_4;

    /* Set PLL circuit */
    SYSTEM.PLLCR.WORD = _0000_CGC_PLL_FREQ_DIV_1 | _0000_CGC_PLL_SOURCE_MAIN | _1300_CGC_PLL_FREQ_MUL_10_0;
    SYSTEM.PLLCR2.BIT.PLLEN = 0U;

    /* Wait for PLL wait counter overflow */
    while (1U != SYSTEM.OSCOVFSR.BIT.PLOVF)
    {
        /* Do nothing */
    }

    /* Stop sub-clock */
    RTC.RCR3.BIT.RTCEN = 0U;

    /* Wait for the register modification to complete */
    while (0U != RTC.RCR3.BIT.RTCEN)
    {
        /* Do nothing */
    }

    /* Stop sub-clock */
    SYSTEM.SOSCCR.BIT.SOSTP = 1U;

    /* Wait for the register modification to complete */
    while (1U != SYSTEM.SOSCCR.BIT.SOSTP)
    {
        /* Do nothing */
    }

    /* Wait for sub-clock oscillation stopping */
    while (0U != SYSTEM.OSCOVFSR.BIT.SOOVF)
    {
        /* Do nothing */
    }

    /* Set UCLK */
    SYSTEM.SCKCR2.WORD = _0040_CGC_UCLK_DIV_5 | _0001_SCKCR2_BIT0;

    /* Set ROM wait cycle */
    SYSTEM.ROMWT.BYTE = _02_CGC_ROMWT_CYCLE_2;

    /* Set SDCLK */
    SYSTEM.SCKCR.BIT.PSTOP0 = 1U;

    /* Set clock source */
    SYSTEM.SCKCR3.WORD = _0400_CGC_CLOCKSOURCE_PLL;

    /* Set LOCO */
    SYSTEM.LOCOCR.BIT.LCSTP = 1U;
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
