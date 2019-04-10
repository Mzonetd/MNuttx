/*****************************************************************************
 * arch/renesas/src/rx65n/rx65_head.S
 *
 *   Copyright (C) 2008-2009, 2012 Gregory Nutt. All rights reserved.
 *   Author: Gregory Nutt <gnutt@nuttx.org>
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
 *****************************************************************************/

/*****************************************************************************
 * Included Files
 *****************************************************************************/

#include <nuttx/config.h>	/* NuttX configuration settings */
#include <arch/board/board.h>	/* Board-specific settings */
#include <arch/irq.h>		/* IRQ definitons */

#include "chip.h"		/* Chip-specific settings */
#include "up_internal.h"
#include "up_arch.h"

/*****************************************************************************
 * Pre-processor Definitions
 *****************************************************************************/

/* This file holds the NuttX start logic that runs when the SH-1/US7032EVB1
 * is reset.  This logic must be located in SRAM at 0x0a00:2000.  On that
 * platform, the entire PROM and the first 8Kb of SRAM are reserved for CMON.
 */

/*****************************************************************************
 * External references
 *****************************************************************************/

/* Called functions */

	.globl	_up_lowsetup				/* Early initialization of UART */

#ifdef USE_EARLYSERIALINIT
	.globl	_up_earlyconsoleinit		/* Early initialization of console driver */
#endif
#ifdef CONFIG_ARCH_LEDS
	.globl	_board_autoled_initialize	/* Boot LED setup */
#endif
#ifdef CONFIG_DEBUG_FEATURES
	.globl	_up_lowputc					/* Low-level debug output */
#endif
	.globl	_nx_start					/* NuttX entry point */

/* Variables set up by the linker script */

     
     

    .globl _HardwareSetup  /*external Sub-routine to initialise Hardware */
    .globl _up_lowsetup
    .globl _data
    .globl _mdata
    .globl _ebss
    .globl _bss
    .globl _edata
    .globl _ustack
    .globl _istack
    
    

/* Interrupt handlers */
	.globl	_up_invalid_handler
#ifdef CONFIG_BSC
	.globl   _uprx65_buserr_handler
#endif
#ifdef CONFIG_RAM
	.globl   _uprx65_ramerr_handler
#endif
#ifdef CONFIG_FIFERR
	.globl   _uprx65_fiferr_handler
#endif
#ifdef CONFIG_FRDYI
	.globl   _uprx65_frdyi_handler
#endif
#ifdef CONFIG_RX65N_ICU_SWITCH
	.globl   _uprx65_swint2_handler
        .globl   _uprx65_swint_handler
#endif
#ifdef CONFIG_RX65N_CMT0
	.globl   _uprx65_cmi0_handler
#endif
#ifdef CONFIG_RX65N_CMT1
	.globl   _uprx65_cmi1_handler
#endif
#ifdef CONFIG_RX65N_CMTW0
	.globl   _uprx65_cmwi0_handler
#endif
#ifdef CONFIG_RX65N_CMTW1
	.globl   _uprx65_cmwi1_handler
#endif
#ifdef CONFIG_RX65N_USB0
	.globl  _uprx65_d0fifo0_handler
	.globl  _uprx65_d1fifo0_handler
#endif
#ifdef CONFIG_RX65N_RSPI0
	.globl  _uprx65_spri0_handler
	.globl  _uprx65_spti0_handler
#endif
#ifdef CONFIG_RX65N_RSPI1
	.globl  _uprx65_spri1_handler
	.globl  _uprx65_spti1_handler
#endif
#ifdef CONFIG_RX65N_QSPI
	.globl  _uprx65_spri_handler
	.globl  _uprx65_spti_handler
#endif
#ifdef CONFIG_RX65N_SDHI
	.globl  _uprx65_sbfai_handler
#endif
#ifdef CONFIG_RX65N_MMCIF
	.globl  _uprx65_mbfai_handler
#endif
#ifdef CONFIG_RX65N_RIIC0
	.globl  _uprx65_rxii0_handler
	.globl  _uprx65_txii0_handler
#endif
#ifdef CONFIG_RX65N_RIIC2
	.globl  _uprx65_rxii2_handler
	.globl  _uprx65_txii2_handler
#endif
#ifdef CONFIG_RX65N_SCI0
	.globl	_uprx65_rxi0_handler			
	.globl	_uprx65_txi0_handler
#endif
#ifdef CONFIG_RX65N_SCI1
	.globl	_uprx65_rxi1_handler			
	.globl	_uprx65_txi1_handler
#endif
#ifdef CONFIG_RX65N_SCI2
	
	.globl	_uprx65_rxi2_handler			
	.globl	_uprx65_txi2_handler
#endif





/*****************************************************************************
 * Macros
 *****************************************************************************/

/*****************************************************************************
 * Name: showprogress
 *
 * Description:
 *   Print a character on the UART to show boot status. This macro will
 *   modify r0, r1, r2 and r14
 *
 *****************************************************************************/

	.macro	showprogress, code
#ifdef CONFIG_DEBUG_FEATURES
	mov.l	#_up_lowputc, r15				/* Address of up_earlyconsoleinit */
	jsr		r15							/* Call it */
	mov		#\code, r4					/* Delay slot */
#endif
	.endm


.macro	irqhandle, irq, label
	mov.l	r4, [-r0]		/* Save the value of R4 on the stack */
	
	mov	#1, r4		/* R4=IRQ number */
        mov.l   #_up_doirq, r15
	jsr	r15		/* Jump to the common vector handling logic */
	nop
.L\label:
	.word	\irq
	.endm
/*loop1:
  cmp #0,r4
  bne loop1 */

/*****************************************************************************
 * Vectors
 *****************************************************************************/

	.section	.rvectors

/*****************************************************************************
 * Name: __vector_table
 *
 * Description:
 *   Interrupt vector table.  The actual vectors are managed by CMON.  For
 *   any non-zero settings in the following table, CMON will redirect interrupt
 *   handling to that function.
 *
 *****************************************************************************/

	.globl		__vector_table
	.type		__vector_table, %object
__vector_table:

	.long   _uprx65_invalid_handler
	.long   _uprx65_invalid_handler
	.long   _uprx65_invalid_handler
	.long   _uprx65_invalid_handler
	.long   _uprx65_invalid_handler
	.long   _uprx65_invalid_handler
	.long   _uprx65_invalid_handler
	.long   _uprx65_invalid_handler
	.long   _uprx65_invalid_handler
	.long   _uprx65_invalid_handler
	.long   _uprx65_invalid_handler
	.long   _uprx65_invalid_handler
	.long   _uprx65_invalid_handler
	.long   _uprx65_invalid_handler
	.long   _uprx65_invalid_handler
	.long   _uprx65_invalid_handler

       
#ifdef CONFIG_BSC
	.long   _uprx65_buserr_handler
#else
	.long   _uprx65_invalid_handler
#endif
	.long   _uprx65_invalid_handler
#ifdef CONFIG_RAM
	.long   _uprx65_ramerr_handler
#else
	.long   _uprx65_invalid_handler
#endif
	.long   _uprx65_invalid_handler
	.long   _uprx65_invalid_handler

#ifdef CONFIG_FIFERR
	.long   _uprx65_fiferr_handler
#else
	.long   _uprx65_invalid_handler
#endif
	.long   _uprx65_invalid_handler
#ifdef CONFIG_FRDYI
	.long   _uprx65_frdyi_handler
#else
	.long   _uprx65_invalid_handler
#endif
        .long   _uprx65_invalid_handler
	.long   _uprx65_invalid_handler
#ifdef CONFIG_RX65N_ICU_SWITCH
	.long   _uprx65_swint2_handler
        .long   _uprx65_swint_handler
#else
	.long   _uprx65_invalid_handler
	.long   _uprx65_invalid_handler
#endif
#ifdef CONFIG_RX65N_CMT0
	.long   _uprx65_cmi0_handler
#else
	.long   _uprx65_invalid_handler
#endif
#ifdef CONFIG_RX65N_CMT1
	.long   _uprx65_cmi1_handler
#else
	.long   _uprx65_invalid_handler
#endif
#ifdef CONFIG_RX65N_CMTW0
	.long   _uprx65_cmwi0_handler
#else
	.long   _uprx65_invalid_handler
#endif
#ifdef CONFIG_RX65N_CMTW1
	.long   _uprx65_cmwi1_handler
#else
	.long   _uprx65_invalid_handler
#endif
	.long   _uprx65_invalid_handler
	.long   _uprx65_invalid_handler
#ifdef CONFIG_RX65N_USB0
	.long  _uprx65_d0fifo0_handler
	.long  _uprx65_d1fifo0_handler
#else
	.long   _uprx65_invalid_handler
	.long   _uprx65_invalid_handler
#endif
	.long   _uprx65_invalid_handler
	.long   _uprx65_invalid_handler
#ifdef CONFIG_RX65N_RSPI0
	.long  _uprx65_spri0_handler
	.long  _uprx65_spti0_handler
#else
	.long   _uprx65_invalid_handler
	.long   _uprx65_invalid_handler
#endif
#ifdef CONFIG_RX65N_RSPI1
	.long  _uprx65_spri1_handler
	.long  _uprx65_spti1_handler
#else
	.long   _uprx65_invalid_handler
	.long   _uprx65_invalid_handler
#endif
#ifdef CONFIG_RX65N_QSPI
	.long  _uprx65_spri_handler
	.long  _uprx65_spti_handler
#else
	.long   _uprx65_invalid_handler
	.long   _uprx65_invalid_handler
#endif
#ifdef CONFIG_RX65N_SDHI
	.long  _uprx65_sbfai_handler
#else
	.long   _uprx65_invalid_handler
#endif
#ifdef CONFIG_RX65N_MMCIF
	.long  _uprx65_mbfai_handler
#else
	.long   _uprx65_invalid_handler
#endif	
	.long   _uprx65_invalid_handler
	.long   _uprx65_invalid_handler
	.long   _uprx65_invalid_handler
	.long   _uprx65_invalid_handler
	.long   _uprx65_invalid_handler
	.long   _uprx65_invalid_handler
#ifdef CONFIG_RX65N_RIIC0
	.long  _uprx65_rxii0_handler
	.long  _uprx65_txii0_handler
#else
        .long   _uprx65_invalid_handler
	.long   _uprx65_invalid_handler
#endif
#ifdef CONFIG_RX65N_RIIC2
	.long  _uprx65_rxii2_handler
	.long  _uprx65_txii2_handler
#else
        .long   _uprx65_invalid_handler
	.long   _uprx65_invalid_handler
#endif
	.long   _uprx65_invalid_handler
	.long   _uprx65_invalid_handler
#ifdef CONFIG_RX65N_SCI0
	.long	_uprx65_rxi0_handler			
	.long	_uprx65_txi0_handler			
#else
	.long	_uprx65_invalid_handler			
	.long	_uprx65_invalid_handler			
#endif
#ifdef CONFIG_RX65N_SCI1
	.long	_uprx65_rxi1_handler			
	.long	_uprx65_txi1_handler			
#else
	.long	_uprx65_invalid_handler			
	.long	_uprx65_invalid_handler			
#endif
#ifdef CONFIG_RX65N_SCI2
	
	.long	_uprx65_rxi2_handler			
	.long	_uprx65_txi2_handler			
	
#else
	.long	_uprx65_invalid_handler			
	.long	_uprx65_invalid_handler			
#endif
	.size	__vector_table, . - __vector_table

/************************************************************************************
 * Code
 ************************************************************************************/
		.section	.text
/************************************************************************************
 * Name: __start
 *
 * Description:
 *   After reset, program execution starts here.
 *
 ************************************************************************************/
        .text
        .global _PowerON_Reset
	.type	 _PowerON_Reset, #function

_PowerON_Reset:
     
/*initialise user stack pointer */
    mvtc    #_ustack,USP

/*initialise interrupt stack pointer */
    mvtc    #_istack,ISP

#ifdef __RXv2__
/* setup exception vector */
    mvtc    #_ExceptVectors, extb     /*EXCEPTION VECTOR ADDRESS */
    
#endif
/*setup intb */
    mvtc    #_rvectors_start, intb    /*INTERRUPT VECTOR ADDRESS  definition*/
    
/*setup FPSW */
    mvtc    #100h, fpsw

/*load data section from ROM to RAM */

    mov     #_mdata,r2      /*src ROM address of data section in R2 */
    mov     #_data,r1       /*dest start RAM address of data section in R1 */
    mov     #_edata,r3      /*end RAM address of data section in R3 */
    sub     r1,r3           /*size of data section in R3 (R3=R3-R1) */
    smovf                   /*block copy R3 bytes from R2 to R1 */

/*bss initialisation : zero out bss */

    mov    #00h,r2          /*load R2 reg with zero*/
    mov    #_ebss, r3       /*store the end address of bss in R3*/
    mov    #_bss, r1        /*store the start address of bss in R1*/
    sub    r1,r3            /*size of bss section in R3 (R3=R3-R1)*/
    sstr.b
/*call the hardware initialiser */
    bsr.a    _HardwareSetup
    nop

/*setup PSW */
         mvtc    #20000h, psw   /*Set Ubit & Ibit for PSW */
    
        mov.l	#_up_lowsetup, r15				/* Address of up_lowsetup */
	jsr		r15							/* Call it */
	or		r15, r15						/* Delay slot */
        

#ifdef USE_EARLYSERIALINIT
	mov.l	#_up_earlyconsoleinit, r15			/* Address of up_earlyconsoleinit */
	jsr		r15							/* Call it */
	or		r15, r15						/* Delay slot */
#endif

	

#ifdef CONFIG_CPLUSPLUS
#  warning "No C++ support yet"
	
#endif
	

	bsr.a	_nx_start
	

/*change PSW PM to user-mode */
/*MVFC   PSW,R1
OR     #00100000h,R1
PUSH.L R1
MVFC   PC,R1
ADD    #10,R1
PUSH.L R1
RTE
NOP
NOP */
#ifdef CPPAPP
    /*bsr.a    __rx_init */
#endif
/*#ifdef CONFIG_RX65N_SCI2
	.globl _uprx65_rxi2_handler
	.globl _uprx65_txi2_handler
_uprx65_rxi2_handler:
	irqhandle 62, 30
_uprx65_txi2_handler:
	irqhandle 63, 31
#endif*/

/*start user program */
	
    
    
    


	.section	.data
	.data
	.align	4
        .global	_g_idle_topstack
	.type	_g_idle_topstack, @object
_g_idle_topstack:
	.long	_ebss+1024
	.size	_g_idle_topstack, .-_g_idle_topstack

/*call to exit */
_exit:
    bra  _loop_here
_loop_here:
    bra _loop_here

    .text
    .end





#ifdef USE_EARLYSERIALINIT
.Learlyconsole:
	.long	_up_earlyconsoleinit
#endif
.Llowsetup:
	.long	_up_lowsetup
#ifdef CONFIG_DEBUG_FEATURES
.Llowputc:
	.long	_up_lowputc
#endif
