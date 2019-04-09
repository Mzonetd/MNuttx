/*****************************************************************************
 * arch/renesas/src/rx65n/rx65n_vector.S
 *
 *   
 *
 *****************************************************************************/

/*****************************************************************************
 * Included Files
 *****************************************************************************/

 #include <nuttx/config.h>	 /* NuttX configuration settings */
 #include <arch/board/board.h>	/* Board-specific settings */
 #include <arch/irq.h>		/* IRQ definitons */


 #include "up_internal.h" 

/*****************************************************************************
 * Pre-processor Definitions
 *****************************************************************************/

/*****************************************************************************
 * External references
 *****************************************************************************/

/* Called functions */

	.globl	_up_doirq		/* C interrupt processing logic */
	

/*****************************************************************************
 * Macros
 *****************************************************************************/

/************************************************************************************
 * Macro: trampoline
 *
 * Description:
 *   Enter on exception with:
 *
 *   PSW -> PC
 *         PSW
 *
 *   Branch to up_vector with:
 *
 *   R4  : IRQ vector number
 *   SP -> Saved R4
 *         PC
 *         PSW
 *
 ************************************************************************************/

	.macro	trampoline, irq, label
	mov.l	r4, [-r0]		/* Save the value of R4 on the stack */
	
	mov	#1, r4		/* R4=IRQ number */
	bra	_up_vector		/* Jump to the common vector handling logic */
	nop
.L\label:
	.word	\irq
	.endm

/************************************************************************************
 * Data
 ************************************************************************************/

/************************************************************************************
 * Interrupt Vectors
 ************************************************************************************/




        
	

/*****************************************************************************
 * Text
 *****************************************************************************/
		.section .text
	

/*****************************************************************************
 * Name: _uprx65_*_handler
 *
 * Description:
 *   Trampoline entry points for each, individual IRQ
 *
 *  R4 :  Points to a the register save structure
 *
 *****************************************************************************/
#ifdef CONFIG_RX65N_SCI2
	.globl _uprx65_rxi2_handler
	.globl _uprx65_txi2_handler
_uprx65_rxi2_handler:
	trampoline 62, 30
_uprx65_txi2_handler:
	trampoline 63, 31 
#endif      
	



.globl	_uprx65_invalid_handler
_uprx65_invalid_handler:
	trampoline 16, 1



/* BUSERR Handler */

#ifdef CONFIG_BSC
	.globl	_uprx65_buserr_handler
_uprx65_buserr_handler:
	trampoline 16, 2
#endif

/* RAMERR Handler */

#ifdef CONFIG_RAM
	.globl	_uprx65_ramerr_handler
_uprx65_ramerr_handler:
	trampoline 18, 3
#endif

#ifdef CONFIG_FIFERR
	.globl  _uprx65_fiferr_handler
_uprx65_fiferr_handler:
	trampoline 21, 4
#endif

#ifdef CONFIG_FRDYI
	.globl _uprx65_frdyi_handler
_uprx65_frdyi_handler:
	trampoline 23, 5
#endif

#ifdef CONFIG_RX65N_ICU_SWITCH
	.globl _uprx65_swint2_handler
	.globl _uprx65_swint_handler
_uprx65_swint2_handler:
	trampoline 26, 6
_uprx65_swint_handler:
	trampoline 27, 7
#endif

#ifdef CONFIG_RX65N_CMT0
	.globl _uprx65_cmi0_handler
_uprx65_cmi0_handler:
	trampoline 28, 8
#endif

#ifdef CONFIG_RX65N_CMT1
	.globl _uprx65_cmi1_handler
_uprx65_cmi1_handler:
	trampoline 28, 9
#endif

#ifdef CONFIG_RX65N_CMTW0
	.globl _uprx65_cmwi0_handler
_uprx65_cmwi0_handler:
	trampoline 30, 10
#endif

#ifdef CONFIG_RX65N_CMTW1
	.globl _uprx65_cmwi1_handler
_uprx65_cmwi1_handler:
	trampoline 31, 11
#endif

#ifdef CONFIG_RX65N_USB0
	.globl _uprx65_d0fifo0_handler
	.globl _uprx65_d1fifo0_handler
_uprx65_d0fifo0_handler:
	trampoline 34, 12
_uprx65_d1fifo0_handler:
	trampoline 35, 13
#endif

#ifdef CONFIG_RX65N_RSPI0
	.globl  _uprx65_spri0_handler
	.globl  _uprx65_spti0_handler
_uprx65_spri0_handler:
	trampoline 38, 14
_uprx65_spti0_handler:
	trampoline 39, 15
#endif

#ifdef CONFIG_RX65N_RSPI1
	.globl  _uprx65_spri1_handler
	.globl  _uprx65_spti1_handler
_uprx65_spri1_handler:
	trampoline 40, 16
_uprx65_spti1_handler:
	trampoline 41, 17
#endif

#ifdef CONFIG_RX65N_QSPI
	.globl  _uprx65_spri_handler
	.globl  _uprx65_spti_handler
_uprx65_spri_handler:
	trampoline 42, 18
_uprx65_spti_handler:
	trampoline 43, 19
#endif

#ifdef CONFIG_RX65N_SDHI
	.globl _uprx65_sbfai_handler
_uprx65_sbfai_handler:
	trampoline 44, 20
#endif

#ifdef CONFIG_RX65N_MMCIF
	.globl _uprx65_mbfai_handler
_uprx65_mbfai_handler:
	trampoline 45, 21
#endif

#ifdef CONFIG_RX65N_RIIC0
	.globl _uprx65_rxii0_handler
	.globl _uprx65_txii0_handler
_uprx65_rxii0_handler:
	trampoline 52, 22
_uprx65_txii0_handler:
	trampoline 53, 23
#endif

#ifdef CONFIG_RX65N_RIIC2
	.globl _uprx65_rxii2_handler
	.globl _uprx65_txii2_handler
_uprx65_rxii2_handler:
	trampoline 54, 24
_uprx65_txii2_handler:
	trampoline 55, 25
#endif

#ifdef CONFIG_RX65N_SCI0
	.globl _uprx65_rxi0_handler
	.globl _uprx65_txi0_handler
_uprx65_rxi0_handler:
	trampoline 58, 26
_uprx65_txi0_handler:
	trampoline 59, 27
#endif

#ifdef CONFIG_RX65N_SCI1
	.globl _uprx65_rxi1_handler
	.globl _uprx65_txi1_handler
_uprx65_rxi1_handler:
	trampoline 60, 28
_uprx65_txi1_handler:
	trampoline 61, 29
#endif



/*
#ifdef CONFIG_RX65N_DMAC0I
	.globl	_uprx65_dmac0i_handler
_uprx65_dmac0i_handler:
	trampoline RX65N_DMAC0I_IRQ, 4 DMAC0I 
 #endif

#ifdef CONFIG_RX65N_DMAC1I
	.globl	_uprx65_dmac01_handler
_uprx65_dmac01_handler:
	trampoline RX65N_DMAC1I_IRQ, 5  DMAC1I 
 #endif

#ifdef CONFIG_RX65N_DMAC2I
	.globl	_uprx65_dmac02_handler
_uprx65_dmac02_handler:
	trampoline RX65N_DMAC2I_IRQ, 6  DMAC2I 
 #endif




#ifdef CONFIG_RX65N_SCI0
	.globl	_uprx65_rxi0_handler
	.globl	_uprx65_txi0_handler
_uprx65_rxi0_handler:
	trampoline RX65N_RXI0_IRQ, 58  RxI0 
 _uprx65_txi0_handler:
	trampoline RX65N_TXI0_IRQ, 59   TxI0 
 #endif

#ifdef CONFIG_RX65N_SCI1
	.globl	_uprx65_rxi1_handler
	.globl	_uprx65_txi1_handler
_uprx65_rxi1_handler:
	trampoline RX65N_RXI1_IRQ, 60   RxI1 
_uprx65_txi1_handler:
	trampoline RX65N_TXI1_IRQ, 61   TxI1 
 #endif 

#ifdef CONFIG_RX65N_SCI2
	.globl	_uprx65_rxi2_handler
	.globl	_uprx65_txi2_handler
_uprx65_rxi2_handler:
	trampoline 0, 62   RxI2 
_uprx65_txi2_handler:
	trampoline 1, 63   TxI2 
#endif

#ifdef CONFIG_RX65N_ICU
	.globl	_uprx65_rxi2_handler
	.globl	_uprx65_txi2_handler
_uprx65_rxi2_handler:
	trampoline RX65N_RXI2_IRQ, 62 
_uprx65_txi2_handler:
	trampoline RX65N_TXI2_IRQ, 63 
#endif 

 #ifdef CONFIG_RX65N_ICU
	.globl	_uprx65_IRQ0_handler
	.globl	_uprx65_IRQ1_handler
	.globl	_uprx65_IRQ2_handler
	.globl	_uprx65_IRQ3_handler
	.globl	_uprx65_IRQ4_handler
	.globl	_uprx65_IRQ5_handler
	.globl	_uprx65_IRQ6_handler
	.globl	_uprx65_IRQ7_handler
	.globl	_uprx65_IRQ8_handler
	.globl	_uprx65_IRQ9_handler
	.globl	_uprx65_IRQ10_handler
	.globl	_uprx65_IRQ11_handler
	.globl	_uprx65_IRQ12_handler
	.globl	_uprx65_IRQ13_handler
	.globl	_uprx65_IRQ14_handler
	.globl	_uprx65_IRQ15_handler

_uprx65_IRQ0_handler:
	trampoline RX65N_IRQ0_IRQ, 64  IRQ0 
 _uprx65_IRQ1_handler:
	trampoline RX65N_IRQ1_IRQ, 65  IRQ1 
_uprx65_IRQ2_handler:
	trampoline RX65N_IRQ2_IRQ, 66   IRQ2 
_uprx65_IRQ03_handler:
	trampoline RX65N_IRQ3_IRQ, 67   IRQ3 
_uprx65_IRQ4_handler:
	trampoline RX65N_IRQ4_IRQ, 68  IRQ4 
_uprx65_IRQ5_handler:
	trampoline RX65N_IRQ5_IRQ, 69   IRQ5 
_uprx65_IRQ6_handler:
	trampoline RX65N_IRQ6_IRQ, 70   IRQ6 
_uprx65_IRQ7_handler:
	trampoline RX65N_IRQ7_IRQ, 71   IRQ7 
_uprx65_IRQ8_handler:
	trampoline RX65N_IRQ8_IRQ, 72   IRQ8 
_uprx65_IRQ9_handler:
	trampoline RX65N_IRQ9_IRQ, 73   IRQ9 
_uprx65_IRQ10_handler:
	trampoline RX65N_IRQ10_IRQ, 74   IRQ10 
_uprx65_IRQ11_handler:
	trampoline RX65N_IRQ11_IRQ, 75   IRQ11 
_uprx65_IRQ12_handler:
	trampoline RX65N_IRQ12_IRQ, 76   IRQ12 
_uprx65_IRQ13_handler:
	trampoline RX65N_IRQ13_IRQ, 77   IRQ13 
_uprx65_IRQ14_handler:
	trampoline RX65N_IRQ14_IRQ, 78   IRQ14 
_uprx65_IRQ15_handler:
	trampoline RX65N_IRQ15_IRQ, 79   IRQ15 
#endif

These handler not implemented in rx65n*/

/*****************************************************************************
 * Name: _up_vector
 *
 * Description:
 *   Execption entry point.  Upon entry:
 *
 *  R4 :  Holds IRQ number
 *  SP -> Saved R4		(REG_R4=19)	See irq.h
 *        PC			(REG_PC=20)
 *        PSW			(REG_PSW=21)
 *
 *****************************************************************************/

	.global _up_vector
	.type	_up_vector, #function

_up_vector:
	/* Save r0-r3, r5-r7 on the stack so that we have a registers to work with.
	 * After this, the stack will look like:
	 *
	 *  SP -> r0		(REG_R0=12)	See irq.h
	 *        r1		(REG_R1=13)
	 *        r2		(REG_R2=14)
	 *        r3		(REG_R3=15)
	 *        r5		(REG_R5=16)
	 *        r6		(REG_R6=17)
	 *        r7		(REG_R7=18)
	 *        R4		(REG_R4=19)
	 *        ...
	 */
	/* Set immediate value to register */
	pushm r6-r7
	
	/* changed opcode from stc to mvfc as per RX family instruction set */
	/* Set Carry Flag */
				/* Mask all interrupts */
	mvfc    psw, r6
	mov.l	#0x00010000, r7  /*Change needed for the lable Review */
	or	r7, r6
	/*ldc     r6, sr */
	/*  changed opcode from ldc to mvtc as per RX family instruction set  */
	mvtc     r6, psw
        pushm r1-r5
	/*mov.l	r5, [-r0]
	mov.l	r3, [-r0]
	mov.l	r2, [-r0]
	mov.l	r1, [-r0]
	mov.l	r15, [-r0] */
	/* Store Direct to data space(SRAM) */
	/* Need to check the Use case of the mach and macl  Review */
	/* Multiply and accumulate register high (MACH)
	   Multiply and accumulate register low (MACL) */
	/* These registers are not available in rx65n */
	/* sts.l	mach, @-r15 */
	/* sts.l	macl, @-r15 */

	/* Then save the value of the SP *before* the interrupt ocurred
	 *
	 * SP -> SP		(REG_SP=9) See irq.h
	 *       ...
	 */

	mov	r0, r5		/* R5 = current SP */
	/* The below operation need to be corrected Review */
	
	add	#(10*4), r5	/* Account for psw, pc, r0-r7 */
	push r5
	
	/* Save the remaining registers on the stack:
	 *
	 * SP -> r8		(REG_R8=0) See irq.h
	 *       r9		(REG_R9=1)
	 *       r10		(REG_R10=2)
	 *       r11		(REG_R11=3)
	 *       r12		(REG_R12=4)
	 *       r13		(REG_R13=5)
	 *       r14		(REG_R14=6)
	 *       r15		(REG_R15= ?) 
	 *       SP		(REG_SP=9)   Need to change this comment accordingly Review R0 is SP but Not R15
	 *       ...
	 */
	 
	/* GBR(Global base register)control register,
	 * PR(Procedure register) system register
	 * Not available in rx65n
	 */
	 /* Need to impliment this two operations for RX65N to save the context Review */
	
        pushm r8-r14
	/*mov.l	r14, [-r0]
	mov.l	r13, [-r0]
	mov.l	r12, [-r0]
	mov.l	r11, [-r0]
	mov.l	r10, [-r0]
	mov.l	r9, [-r0]
	mov.l	r8, [-r0]

	 Setup parameters: R4=IRQ number, R5=base of saved state */

	mov	r0, r5

	/* Switch to the interrupt stack */
    /* Review Please Enable PSW bit to Enable Interrupt Stack Flag to Enable R0 as Interrupt Stack pointer */
	/* PSW need to be set for all below context Review */
#if CONFIG_ARCH_INTERRUPTSTACK > 3  
	mov.l	#0x00010000, r0		/* SP = interrupt stack base */
	push r5		/* Save the user stack pointer (pre-decremented) */

	/* Dispatch the interrupt */
        push r10
        mov.l #0,r10
        mov.l   #_up_doirq, r15
    /* Jump to a subroutine */
        jsr     r15
        nop

	/* Recover the user stack point */
    /* Please check the below source value Review */
	mov.l	#15, r15
#else
	/* Dispatch the interrupt */

        mov.l   #.Ldoirq, r0
        jsr     r0
        nop
#endif
	/* On return, R0 holds the address of the base of the XCPTCONTEXT
	 * structure to use for the return -- may not be the same as the
	 * one that we passed in via r5.  If the value is different, then
	 * we cannot assume that the values lie on the stack and we will
	 * need to execute some more complete logic.
	 */
    /* Review Please check the below context */
	
cmp	r15, r0
	bne	.Lcontextswitch
	mov	r15, r0

	/* Restore registers from the stack. NOTE: We coudl improve interrupt
     * performance by skipping the restore of r8-r14.  These will not
     * be modified by the called C code
     */

#if 1
	/* Skip over static registers -- these will not be modified by the
	 * called C code (r8-r14)
         */
    /* Review Please check the below context */
	add	#(7*4), r15	/* 0-6: Skip over r8-r14 */
#else
	mov.l	[r0+], r8	/* 0-6: r8-r14 */
	mov.l	[r0+], r9
	mov.l	[r0+], r10
	mov.l	[r0+], r11
	mov.l	[r0+], r12
	mov.l	[r0+], r13
	mov.l	[r0+], r14
#endif
    /* Review Please check the below context */
	

	add	#4, r0		/* 9: Skip SP restore */
    /* Review Please check the below context */
	

	/* Review Please check first operation R0 -> R15 the below context */
	mov.l	[r0+], r0	/* 12-18: r0-r3, r5-r7 */
	mov.l	[r0+], r1
	mov.l	[r0+], r2
	mov.l	[r0+], r3
	mov.l	[r0+], r5
	mov.l	[r0+], r6
	mov.l	[r0+], r7

	mov.l	[r0+], r4	/* 19: r4 */
	rte			/* 20-21: pc and psw */
	nop
	.align	2

#if CONFIG_ARCH_INTERRUPTSTACK > 3
.Lintstack:
	.long	_g_intstackbase
#endif
.Ldoirq:
        .long   _up_doirq
        .size   _up_vector, .-_up_vector	
/*****************************************************************************
 * Name: _up_fullcontextrestore
 *
 * Description:
 *   restore context from a set of save registers
 *
 *  R4 :  Points to a the register save structure
 *
 *****************************************************************************/

	.global _up_fullcontextrestore
	.type	_up_fullcontextrestore, #function

_up_fullcontextrestore:
	/* Mask all interrupts */
/* opcode changed from stc to mvfc */
	
	/* mvfc     psw, r8
	mov.l	#0x00010000, r9
	or	r9, r8
	/* opcode changed from ldc to mvtc */
	
	/* mvtc    r8, psw

	/* Replace stack pointer with the context save */

	/* mov	r4, r0 */

	/* Restore registers from a context structure */

.Lcontextswitch:
        
	mov.l	[r4+], r8	/* 0-8: r8-r14*/
	mov.l	[r4+], r9
	mov.l	[r4+], r10
	mov.l	[r4+], r11
	mov.l	[r4+], r12
	mov.l	[r4+], r13
	mov.l	[r4+], r14
        mov.l	[r4+], r15	/* r4: Saved SP */
        mov.l	[r4+], r1
	mov.l	[r4+], r2
	mov.l	[r4+], r3
	mov.l	[r4+], r5
	mov.l	[r4+], r6 
        mov.l	[r4+], r7
	/* Copy the remainder of the stack context to the target stack.
	 * At this point r15 points to offset REG_R6.
	 */

	/* add	#-16, r4	 R4 points to offset REG_R7 in the new stack 
	mov.l	[r4+], r7	 R7=Saved R7 value */
	/* mov.l	r7, [r4]		/* Save at offset REG_R7 in the new stack 
	mov.l	[r4+], r7	 R7=Save PC value 
	add     #4, r4
	mov.l	r7, [r4]	 Save at offset REG_PC in the new stack 
	mov.l	[r4], r7	 R7=Save PSW value 
	add     #8, r4
	mov.l	r7, [r4]	Save at offset REG_PSW in the new stack 
	 Set the new stack pointer 

	 mov	r4, r0 

	/* Then recover the final register values from the new stack */

	/* mov.l	[r0+], r7
	mov.l	[r0+], r4 */

	/* And return from interrupt */
       
	rte
	nop
	.align	2

.Lintmask:
	.long	0x00010000
	.size	_up_fullcontextrestore, .-_up_fullcontextrestore

/************************************************************************************
 *  Name: g_intstackalloc/g_intstackbase
 *
 * Description:
 *   Shouldn't happen
 *
 ************************************************************************************/

#if CONFIG_ARCH_INTERRUPTSTACK > 3
	.bss
	.align	2
	.globl	_g_intstackalloc
	.type	_g_intstackalloc, object
	.globl	_g_intstackbase
	.type	_g_intstackbase, object
_g_intstackalloc:
	.skip	4
_g_intstackbase:
	.skip	2
	.size	_g_intstackbase, 4
	.size	_g_intstackalloc, 4
#endif
	.end

        



