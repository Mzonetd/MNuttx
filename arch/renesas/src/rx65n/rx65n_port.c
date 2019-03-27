/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "rx65n_macrodriver.h"
#include "rx65n_port.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_PORT_Create
* Description  : This function initializes the Port I/O.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_PORT_Create(void)
{
    PORT0.PODR.BYTE = _04_Pm2_OUTPUT_1 | _08_Pm3_OUTPUT_1 | _20_Pm5_OUTPUT_1;
    PORT5.PODR.BYTE = _40_Pm6_OUTPUT_1;
    PORT7.PODR.BYTE = _08_Pm3_OUTPUT_1;
    PORT9.PODR.BYTE = _08_Pm3_OUTPUT_1;
    PORTJ.PODR.BYTE = _20_Pm5_OUTPUT_1;
    PORT0.DSCR.BYTE = _00_Pm2_HIDRV_OFF;
    PORT0.DSCR2.BYTE = _00_Pm2_HISPEED_OFF;
    PORT5.DSCR.BYTE = _20_Pm5_HIDRV_ON | _00_Pm6_HIDRV_OFF;
    PORT5.DSCR2.BYTE = _00_Pm5_HISPEED_OFF | _00_Pm6_HISPEED_OFF;
    PORT7.DSCR2.BYTE = _00_Pm3_HISPEED_OFF;
    PORT9.DSCR.BYTE = _00_Pm3_HIDRV_OFF;
    PORT9.DSCR2.BYTE = _00_Pm3_HISPEED_OFF;
    PORT0.PMR.BYTE = 0x00U;
    PORT0.PDR.BYTE = _04_Pm2_MODE_OUTPUT | _08_Pm3_MODE_OUTPUT | _20_Pm5_MODE_OUTPUT | _50_PDR0_DEFAULT;
    PORT5.PMR.BYTE = 0x00U;
    PORT5.PDR.BYTE = _20_Pm5_MODE_OUTPUT | _40_Pm6_MODE_OUTPUT | _80_PDR5_DEFAULT;
    PORT7.PMR.BYTE = 0x00U;
    PORT7.PDR.BYTE = _08_Pm3_MODE_OUTPUT;
    PORT9.PMR.BYTE = 0x00U;
    PORT9.PDR.BYTE = _08_Pm3_MODE_OUTPUT | _F0_PDR9_DEFAULT;
    PORTJ.PMR.BYTE = 0x00U;
    PORTJ.PDR.BYTE = _20_Pm5_MODE_OUTPUT | _D7_PDRJ_DEFAULT;
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
