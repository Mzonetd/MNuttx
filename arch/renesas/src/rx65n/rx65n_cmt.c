/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "rx65n_macrodriver.h"
#include "rx65n_cmt.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */


/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_CMT0_Create
* Description  : This function initializes the CMT0 channel.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_CMT0_Create(void)
{
    /* Disable CMI interrupt */
    IEN(CMT0,CMI0) = 0U;

    /* Cancel CMT stop state in LPC */
    MSTP(CMT0) = 0U;

    /* Set control registers */
    CMT0.CMCR.WORD = _0000_CMT_CMCR_CKS_PCLK8 | _0040_CMT_CMCR_CMIE_ENABLE | _0080_CMT_CMCR_DEFAULT;
    CMT0.CMCOR = _1D4B_CMT0_CMCOR_VALUE;

    /* Set CMI0 priority level */
    IPR(CMT0,CMI0) = _0A_CMT_PRIORITY_LEVEL10;
}
/***********************************************************************************************************************
* Function Name: R_CMT0_Start
* Description  : This function starts the CMT0 channel counter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_CMT0_Start(void)
{
    /* Enable CMI0 interrupt in ICU */
    IEN(CMT0,CMI0) = 1U;

    /* Start CMT0 count */
    CMT.CMSTR0.BIT.STR0 = 1U;
}
/***********************************************************************************************************************
* Function Name: R_CMT0_Stop
* Description  : This function stops the CMT0 channel counter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_CMT0_Stop(void)
{
    /* Disable CMI0 interrupt in ICU */
    IEN(CMT0,CMI0) = 0U;

    /* Stop CMT0 count */
    CMT.CMSTR0.BIT.STR0 = 0U;
}
/***********************************************************************************************************************
* Function Name: R_CMT1_Create
* Description  : This function initializes the CMT1 channel.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_CMT1_Create(void)
{
    /* Disable CMI interrupt */
    IEN(CMT1,CMI1) = 0U;

    /* Cancel CMT stop state in LPC */
    MSTP(CMT1) = 0U;

    /* Set control registers */
    CMT1.CMCR.WORD = _0001_CMT_CMCR_CKS_PCLK32 | _0040_CMT_CMCR_CMIE_ENABLE | _0080_CMT_CMCR_DEFAULT;
    CMT1.CMCOR = _927B_CMT1_CMCOR_VALUE;

    /* Set CMI1 priority level */
    IPR(CMT1,CMI1) = _0A_CMT_PRIORITY_LEVEL10;
}
/***********************************************************************************************************************
* Function Name: R_CMT1_Start
* Description  : This function starts the CMT1 channel counter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_CMT1_Start(void)
{
    /* Enable CMI1 interrupt in ICU */
    IEN(CMT1,CMI1) = 1U;

    /* Start CMT1 count */
    CMT.CMSTR0.BIT.STR1 = 1U;
}
/***********************************************************************************************************************
* Function Name: R_CMT1_Stop
* Description  : This function stops the CMT1 channel counter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_CMT1_Stop(void)
{
    /* Disable CMI1 interrupt in ICU */
    IEN(CMT1,CMI1) = 0U;

    /* Stop CMT1 count */
    CMT.CMSTR0.BIT.STR1 = 0U;
}
/***********************************************************************************************************************
* Function Name: R_CMT2_Create
* Description  : This function initializes the CMT2 channel.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_CMT2_Create(void)
{
    /* Disable CMI interrupt */
    IEN(PERIB,INTB128) = 0U;

    /* Cancel CMT stop state in LPC */
    MSTP(CMT2) = 0U;

    /* Set control registers */
    CMT2.CMCR.WORD = _0003_CMT_CMCR_CKS_PCLK512 | _0040_CMT_CMCR_CMIE_ENABLE | _0080_CMT_CMCR_DEFAULT;
    CMT2.CMCOR = _5B8D_CMT2_CMCOR_VALUE;
    ICU.SLIBXR128.BYTE = 0x01U;

    /* Set CMI2 priority level */
    IPR(PERIB,INTB128) = _0A_CMT_PRIORITY_LEVEL10;
}
/***********************************************************************************************************************
* Function Name: R_CMT2_Start
* Description  : This function starts the CMT2 channel counter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_CMT2_Start(void)
{
    /* Enable CMI2 interrupt in ICU */
    IEN(PERIB,INTB128) = 1U;

    /* Start CMT2 count */
    CMT.CMSTR1.BIT.STR2 = 1U;
}
/***********************************************************************************************************************
* Function Name: R_CMT2_Stop
* Description  : This function stops the CMT2 channel counter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_CMT2_Stop(void)
{
    /* Disable CMI2 interrupt in ICU */
    IEN(PERIB,INTB128) = 0U;

    /* Stop CMT2 count */
    CMT.CMSTR1.BIT.STR2 = 0U;
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
