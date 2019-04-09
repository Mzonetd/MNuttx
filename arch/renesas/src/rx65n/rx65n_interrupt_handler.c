#include "iodefine.h"
#include "stdint.h"
void r_sci2_transmit_interrupt(void)
{
    uint32_t regsa;
up_doirq(3,regsa);
}
/***********************************************************************************************************************
* Function Name: r_sci2_receive_interrupt
* Description  : None
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void r_sci2_receive_interrupt(void)
{
//SCI2.SSR.BIT.RDRF = 1;
    uint32_t regsa;
up_doirq(2,regsa);
}
