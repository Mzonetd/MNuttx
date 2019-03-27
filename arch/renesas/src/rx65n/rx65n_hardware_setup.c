/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "rx65n_macrodriver.h"
#include "rx65n_cgc.h"
#include "rx65n_icu.h"
#include "rx65n_port.h"
#include "rx65n_cmt.h"
#include "rx65n_sci.h"


/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/

int HardwareSetup(void);
static void R_Systeminit(void);

/***********************************************************************************************************************
* Function Name: R_Systeminit
* Description  : This function initializes every macro.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Systeminit(void)
{
    /* Enable writing to registers related to operating modes, LPC, CGC and software reset */
    SYSTEM.PRCR.WORD = 0xA50BU; 

    /* Enable writing to MPC pin function control registers */
    MPC.PWPR.BIT.B0WI = 0U;
    MPC.PWPR.BIT.PFSWE = 1U;

    /* Initialize non-existent pins */
    PORT0.PDR.BYTE = 0x50U;
    PORT1.PDR.BYTE = 0x03U;
    PORT5.PDR.BYTE = 0x80U;
    PORT8.PDR.BYTE = 0x30U;
    PORT9.PDR.BYTE = 0xF0U;
    PORTF.PDR.BYTE = 0xDFU;
    PORTJ.PDR.BYTE = 0xD7U;

    /* Set peripheral settings */
    R_CGC_Create();
    R_ICU_Create();
    R_PORT_Create();
    R_CMT0_Create();
    R_CMT1_Create();
    R_CMT2_Create();
    R_SCI2_Create();


    /* Disable writing to MPC pin function control registers */
    MPC.PWPR.BIT.PFSWE = 0U;    
    MPC.PWPR.BIT.B0WI = 1U;     

    /* Enable protection */
    SYSTEM.PRCR.WORD = 0xA500U;
}
/***********************************************************************************************************************
* Function Name: HardwareSetup
* Description  : This function initializes hardware setting.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
int HardwareSetup(void)
{
    R_Systeminit();

    return (1U);
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
