/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "rx65n_macrodriver.h"
#include "rx65n_cmt.h"
/* Start user code for include. Do not edit comment generated here */
/* Defines switch callback functions required by interrupt handlers */
//#include "rx65n_switch.h"
/* End user code. Do not edit comment generated here */
//#include "rx65n_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
static volatile uint8_t one_ms_delay_complete = FALSE;
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: r_cmt_cmi0_interrupt
* Description  : This function is CMI0 interrupt service routine.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void r_cmt_cmi0_interrupt(void)
{
    /* Start user code. Do not edit comment generated here */
	one_ms_delay_complete = TRUE;
    /* End user code. Do not edit comment generated here */
}
/***********************************************************************************************************************
* Function Name: r_cmt_cmi1_interrupt
* Description  : This function is CMI1 interrupt service routine.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void r_cmt_cmi1_interrupt(void)
{
    /* Start user code. Do not edit comment generated here */
	/* Stop this timer - we start it again in the de-bounce routines */
	R_CMT1_Stop();
	/* Call the de-bounce call back routine */
//	R_SWITCH_DebounceIsrCallback();
    /* End user code. Do not edit comment generated here */
}
/***********************************************************************************************************************
* Function Name: r_cmt_cmi2_interrupt
* Description  : This function is CMI2 interrupt service routine.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void r_cmt_cmi2_interrupt(void)
{
    /* Start user code. Do not edit comment generated here */
	/* Stop this timer - we start it again in the de-bounce routines */
	R_CMT2_Stop();
	/* Call the de-bounce call back routine */
//	R_SWITCH_DebounceIsrCallback();
    /* End user code. Do not edit comment generated here */
}

/* Start user code for adding. Do not edit comment generated here */
/*******************************************************************************
* Function Name: R_CMT_MsDelay
* Description : Uses CMT0 to wait for a specified number of milliseconds
* Arguments : uint16_t millisecs, number of milliseconds to wait
* Return Value : None
*******************************************************************************/
void R_CMT_MsDelay (const uint16_t millisec)
{
uint16_t ms_count = 0;
do
{
R_CMT0_Start();
while (FALSE == one_ms_delay_complete)
{
/* Wait */
}
R_CMT0_Stop();
one_ms_delay_complete = FALSE;
ms_count++;
} while (ms_count < millisec);
}
/*******************************************************************************
End of function R_CMT_MsDelay
*******************************************************************************/
/* End user code. Do not edit comment generated here */
