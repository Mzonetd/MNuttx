/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "rx65n_macrodriver.h"
#include "rx65n_tmr.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
//#include "rx65n_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_TMR_Create
* Description  : This function initializes the TMR module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TMR_Create(void)
{
    /* Cancel TMR module stop state */
    MSTP(TMR01) = 0U;
    MSTP(TMR23) = 0U;

    /* Set counter clear and interrupt */
    TMR0.TCR.BYTE = _00_TMR_CMIB_INT_DISABLE | _00_TMR_CMIA_INT_DISABLE | _00_TMR_OVI_INT_DISABLE | 
                    _08_TMR_CNT_CLR_COMP_MATCH_A;

    /* Set A/D trigger and output */
    TMR0.TCSR.BYTE = _00_TMR_AD_TRIGGER_DISABLE | _E0_TMR02_TCSR_DEFAULT;

    /* Set compare match value */
    TMR0.TCORA = _EF_TMR0_COMP_MATCH_VALUE_A;
    TMR0.TCORB = _BF_TMR0_COMP_MATCH_VALUE_B;

    R_TMR0_Start();
    //R_TMR0_Stop();
    /* Set counter clear and interrupt */
    TMR1.TCR.BYTE = _00_TMR_CMIB_INT_DISABLE | _00_TMR_CMIA_INT_DISABLE | _00_TMR_OVI_INT_DISABLE | 
                    _00_TMR_CNT_CLR_DISABLE;

    /* Set compare match value */
    TMR1.TCORA = _BF_TMR1_COMP_MATCH_VALUE_A;
    TMR1.TCORB = _BF_TMR1_COMP_MATCH_VALUE_B;

    /* Set counter clear and interrupt */
    TMR2.TCR.BYTE = _00_TMR_CMIB_INT_DISABLE | _00_TMR_CMIA_INT_DISABLE | _00_TMR_OVI_INT_DISABLE | 
                    _00_TMR_CNT_CLR_DISABLE;

    /* Set A/D trigger and output */
    TMR2.TCSR.BYTE = _00_TMR_AD_TRIGGER_DISABLE | _E0_TMR02_TCSR_DEFAULT;

    /* Set compare match value */
    TMR2.TCORA = _EF_TMR2_COMP_MATCH_VALUE_A;
    TMR2.TCORB = _BF_TMR2_COMP_MATCH_VALUE_B;

    /* Set counter clear and interrupt */
    TMR3.TCR.BYTE = _00_TMR_CMIB_INT_DISABLE | _00_TMR_CMIA_INT_DISABLE | _00_TMR_OVI_INT_DISABLE | 
                    _00_TMR_CNT_CLR_DISABLE;

    /* Set compare match value */
    TMR3.TCORA = _EF_TMR3_COMP_MATCH_VALUE_A;
    TMR3.TCORB = _BF_TMR3_COMP_MATCH_VALUE_B;
}
/***********************************************************************************************************************
* Function Name: R_TMR0_Start
* Description  : This function starts TMR0 channel.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TMR0_Start(void)
{
    /* Start counting */
    TMR0.TCCR.BYTE = _08_TMR_CLK_SRC_PCLK | _00_TMR_PCLK_DIV_1;
}
/***********************************************************************************************************************
* Function Name: R_TMR0_Stop
* Description  : This function stops TMR0 channel.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TMR0_Stop(void)
{
    /* Stop counting */
    TMR0.TCCR.BYTE = _00_TMR_CLK_DISABLED;
}
/***********************************************************************************************************************
* Function Name: R_TMR1_Start
* Description  : This function starts TMR1 channel.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TMR1_Start(void)
{
    /* Start counting */
    TMR1.TCCR.BYTE = _08_TMR_CLK_SRC_PCLK | _00_TMR_PCLK_DIV_1;
}
/***********************************************************************************************************************
* Function Name: R_TMR1_Stop
* Description  : This function stops TMR1 channel.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TMR1_Stop(void)
{
    /* Stop counting */
    TMR1.TCCR.BYTE = _00_TMR_CLK_DISABLED;
}
/***********************************************************************************************************************
* Function Name: R_TMR2_Start
* Description  : This function starts TMR2 channel.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TMR2_Start(void)
{
    /* Start counting */
    TMR2.TCCR.BYTE = _08_TMR_CLK_SRC_PCLK | _00_TMR_PCLK_DIV_1;
}
/***********************************************************************************************************************
* Function Name: R_TMR2_Stop
* Description  : This function stops TMR2 channel.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TMR2_Stop(void)
{
    /* Stop counting */
    TMR2.TCCR.BYTE = _00_TMR_CLK_DISABLED;
}
/***********************************************************************************************************************
* Function Name: R_TMR3_Start
* Description  : This function starts TMR3 channel.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TMR3_Start(void)
{
    /* Start counting */
    TMR3.TCCR.BYTE = _08_TMR_CLK_SRC_PCLK | _00_TMR_PCLK_DIV_1;
}
/***********************************************************************************************************************
* Function Name: R_TMR3_Stop
* Description  : This function stops TMR3 channel.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TMR3_Stop(void)
{
    /* Stop counting */
    TMR3.TCCR.BYTE = _00_TMR_CLK_DISABLED;
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
