#ifndef INTERRUPT_HANDLERS_H
#define INTERRUPT_HANDLERS_H

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/

/* Undefined */
void r_undefined_exception(void) __attribute__ ((interrupt));

/* Access Exception */
void r_access_exception(void) __attribute__ ((interrupt));

/* Privileged Instruction Exception */
void r_privileged_exception(void) __attribute__ ((interrupt));

/* Floating Point Exception */
void r_floatingpoint_exception(void) __attribute__ ((interrupt));

/* NMI */
void r_nmi_exception(void) __attribute__ ((interrupt));

/* BRK */
void r_brk_exception(void) __attribute__ ((interrupt));

/* ICU GROUPBE0 */
void r_icu_group_be0_interrupt(void) __attribute__ ((interrupt));

/* ICU GROUPBL0 */
void r_icu_group_bl0_interrupt(void) __attribute__ ((interrupt));

/* ICU GROUPBL1 */
void r_icu_group_bl1_interrupt(void) __attribute__ ((interrupt));

/* ICU GROUPBL2 */
void r_icu_group_bl2_interrupt(void) __attribute__ ((interrupt));

/* ICU GROUPAL0 */
void r_icu_group_al0_interrupt(void) __attribute__ ((interrupt));

/* ICU GROUPAL1 */
void r_icu_group_al1_interrupt(void) __attribute__ ((interrupt));

/* ICU IRQ8 */
void r_icu_irq8_interrupt(void) __attribute__ ((interrupt));

/* ICU IRQ9 */
void r_icu_irq9_interrupt(void) __attribute__ ((interrupt));

/* CMT CMI0 */
void r_cmt_cmi0_interrupt(void) __attribute__ ((interrupt));

/* CMT CMI1 */
void r_cmt_cmi1_interrupt(void) __attribute__ ((interrupt));

/* CMT CMI2 */
void r_cmt_cmi2_interrupt(void) __attribute__ ((interrupt));

/* SCI2 SCI_TXI2 */
void r_sci2_transmit_interrupt(void) __attribute__ ((interrupt));

/* SCI2 SCI_RXI2 */
void r_sci2_receive_interrupt(void) __attribute__ ((interrupt));

/* SCI7 SCI_TXI7 */
void r_sci7_transmit_interrupt(void) __attribute__ ((interrupt));

/* S12AD0 S12ADI0 */
void r_s12ad0_interrupt(void) __attribute__ ((interrupt));

/* Hardware Vectors */
void PowerON_Reset(void) __attribute__ ((interrupt));

/* Idle Vectors */
void r_undefined_exception(void) __attribute__ ((interrupt));
void r_reserved_exception(void) __attribute__ ((interrupt));

#endif
