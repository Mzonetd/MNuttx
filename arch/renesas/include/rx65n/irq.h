#ifndef __ARCH_RENESAS_INCLUDE_RX65N_IRQ_H
#define __ARCH_RENESAS_INCLUDE_RX65N_IRQ_H
#define XCPTCONTEXT_REGS    (22)
#define XCPTCONTEXT_SIZE      22
#  define NR_IRQS             (16)

/* SCI */

#define RX_ERI_IRQ_OFFSET (0)                                   /* ERI0 */
#define RX_RXI_IRQ_OFFSET (1)                                   /* RxI0 */
#define RX_TXI_IRQ_OFFSET (2)                                   /* TxI0 */
#define RX_TEI_IRQ_OFFSET (3)                                   /* TEI0 */

#if 0
# define RX65N_TRAP_IRQBASE  (0)
# define RX65N_TRAP0_IRQ     (RX65N_TRAP_IRQBASE)
# define RX65N_TRAP1_IRQ     (RX65N_TRAP_IRQBASE+1)
# define RX65N_TRAP2_IRQ     (RX65N_TRAP_IRQBASE+2)
# define RX65N_TRAP3_IRQ     (RX65N_TRAP_IRQBASE+3)
# define RX65N_TRAP4_IRQ     (RX65N_TRAP_IRQBASE+4)
# define RX65N_TRAP5_IRQ     (RX65N_TRAP_IRQBASE+5)
# define RX65N_TRAP6_IRQ     (RX65N_TRAP_IRQBASE+6)
# define RX65N_TRAP7_IRQ     (RX65N_TRAP_IRQBASE+7)
# define RX65N_TRAP8_IRQ     (RX65N_TRAP_IRQBASE+8)
# define RX65N_TRAP9_IRQ     (RX65N_TRAP_IRQBASE+9)
# define RX65N_TRAP10_IRQ    (RX65N_TRAP_IRQBASE+10)
# define RX65N_TRAP11_IRQ    (RX65N_TRAP_IRQBASE+11)
# define RX65N_TRAP12_IRQ    (RX65N_TRAP_IRQBASE+12)
# define RX65N_TRAP13_IRQ    (RX65N_TRAP_IRQBASE+13)
# define RX65N_TRAP14_IRQ    (RX65N_TRAP_IRQBASE+14)
# define RX65N_TRAP15_IRQ    (RX65N_TRAP_IRQBASE+15)
# define RX65N_BUSERR_IRQBASE (RX65N_TRAP_IRQBASE+16)
#else
# define RX65N_BUSERR_IRQBASE    0
#endif

#ifdef CONFIG_BSC
# define RX65N_BUSERR_IRQ     (RX65N_BUSERR_IRQBASE)
# define RX65N_RAMERR_IRQBASE (RX65N_BUSERR_IRQBASE+1)
#else
# define RX65N_BUSERR_IRQ     0
# define RX65N_RAMERR_IRQBASE (RX65N_BUSERR_IRQBASE)
#endif

#ifdef CONFIG_RAM
# define RX65N_RAMERR_IRQ     (RX65N_RAMERR_IRQBASE)
# define RX65N_FIFERR_IRQBASE (RX65N_RAMERR_IRQBASE+1)
#else
# define RX65N_FIFERR_IRQBASE (RX65N_RAMERR_IRQBASE)
#endif

#ifdef CONFIG_FRDYI
# define RX65N_FRDYI_IRQ           (RX65N_FIFERR_IRQBASE)
# define RX65N_ICU_SWITCH_IRQBASE  (RX65N_FIFERR_IRQBASE+1)
#else
# define RX65N_ICU_SWITCH_IRQBASE  (RX65N_FIFERR_IRQBASE)
#endif

#define RX_SCI_NIRQS      (4)
#ifdef CONFIG_ARCH_CHIP_R5F565NEDDFC

#ifdef CONFIG_RX65N_ICU_SWITCH
#  define RX65N_SWINT2_IRQ    (RX65N_ICU_SWITCH_IRQBASE)
#  define RX65N_SWINT_IRQ     (RX65N_ICU_SWITCH_IRQBASE + 1)
#  define RX65N_CMT0_IRQBASE  (RX65N_ICU_SWITCH_IRQBASE + 2)
#else
#  define RX65N_CMT0_IRQBASE  (RX65N_ICU_SWITCH_IRQBASE)
#endif

#ifdef CONFIG_RX65N_CMT0
#  define RX65N_CMI0_IRQ      RX65N_CMT0_IRQBASE
#  define RX65N_CMT1_IRQBASE  (RX65N_CMT0_IRQBASE + 1)
#else
#  define RX65N_CMT1_IRQBASE  RX65N_CMT0_IRQBASE
#endif

#ifdef CONFIG_RX65N_CMT1
#  define RX65N_CMI1_IRQ       RX65N_CMT1_IRQBASE
#  define RX65N_CMTW0_IRQBASE  (RX65N_CMT1_IRQBASE + 1)
#else
#  define RX65N_CMTW0_IRQBASE  RX65N_CMT1_IRQBASE
#endif

#ifdef CONFIG_RX65N_CMTW0
#  define RX65N_CMWI0_IRQ      RX65N_CMTW0_IRQBASE
#  define RX65N_CMTW1_IRQBASE  (RX65N_CMTW0_IRQBASE + 1)
#else
#  define RX65N_CMTW1_IRQBASE  RX65N_CMTW0_IRQBASE
#endif
  
#ifdef CONFIG_RX65N_CMTW1
#  define RX65N_CMWI1_IRQ       RX65N_CMTW1_IRQBASE
#  define RX65N_USB0_IRQBASE   (RX65N_CMTW1_IRQBASE + 1)
#else
#  define RX65N_USB0_IRQBASE RX65N_CMTW1_IRQBASE
#endif
  
#ifdef CONFIG_RX65N_USB0
#  define RX65N_D0FIFO0_IRQ    RX65N_USB0_IRQBASE
#  define RX65N_D1FIFO0_IRQ    (RX65N_USB0_IRQBASE + 1)
#  define RX65N_RSPI0_IRQBASE  (RX65N_USB0_IRQBASE + 2)
#else
#  define RX65N_RSPI0_IRQBASE   RX65N_USB0_IRQBASE
#endif
#ifdef CONFIG_RX65N_RSPI0
#  define RX65N_SPRI0_IRQ      RX65N_RSPI0_IRQBASE
#  define RX65N_SPTI0_IRQ      (RX65N_RSPI0_IRQBASE + 1)
#  define RX65N_RSPI1_IRQBASE  (RX65N_RSPI0_IRQBASE + 2)
#else
#  define RX65N_RSPI1_IRQBASE   RX65N_RSPI0_IRQBASE
#endif
  
#ifdef CONFIG_RX65N_RSPI1
#  define RX65N_SPRI1_IRQ       RX65N_RSPI1_IRQBASE
#  define RX65N_SPTI1_IRQ       (RX65N_RSPI1_IRQBASE + 1)
#  define RX65N_QSPI_IRQBASE    (RX65N_RSPI1_IRQBASE + 2)
#else
#  define RX65N_QSPI_IRQBASE    RX65N_RSPI1_IRQBASE
#endif
  
#ifdef CONFIG_RX65N_QSPI
#  define RX65N_SPRI_IRQ        RX65N_QSPI_IRQBASE
#  define RX65N_SPTI_IRQ        (RX65N_QSPI_IRQBASE + 1)
#  define RX65N_SDHI_IRQBASE    (RX65N_QSPI_IRQBASE + 2)
#else
#  define RX65N_SDHI_IRQBASE    RX65N_QSPI_IRQBASE
#endif
  
#ifdef CONFIG_RX65N_SDHI
#  define RX65N_SBFAI_IRQ        RX65N_SDHI_IRQBASE
#  define RX65N_MMCIF_IRQBASE    (RX65N_SDHI_IRQBASE + 1)
#else
#  define RX65N_MMCIF_IRQBASE    RX65N_SDHI_IRQBASE
#endif
  
#ifdef CONFIG_RX65N_MMCIF
#  define RX65N_MBFAI_IRQ        RX65N_MMCIF_IRQBASE
#  define RX65N_RIIC1_IRQBASE    (RX65N_MMCIF_IRQBASE + 1)
#else
#  define RX65N_RIIC1_IRQBASE    RX65N_MMCIF_IRQBASE
#endif

#ifdef CONFIG_RX65N_RIIC1
#  define RX65N_RXI1_IRQ        (RX65N_RIIC1_IRQBASE + RX_RXI_IRQ_OFFSET)
#  define RX65N_TXI1_IRQ        (RX65N_RIIC1_IRQBASE + RX_TXI_IRQ_OFFSET)
#  define RX65N_RIIC0_IRQBASE   (RX65N_RIIC1_IRQBASE + RX_SCI_NIRQS)
#else
#  define RX65N_RIIC0_IRQBASE    RX65N_RIIC1_IRQBASE
#endif
  
#ifdef CONFIG_RX65N_RIIC0
#  define RX65N_RXI0_IRQ        (RX65N_RIIC0_IRQBASE + RX_RXI_IRQ_OFFSET)
#  define RX65N_TXI0_IRQ        (RX65N_RIIC0_IRQBASE + RX_TXI_IRQ_OFFSET)
#  define RX65N_RIIC2_IRQBASE   (RX65N_RIIC0_IRQBASE + RX_SCI_NIRQS)
#else
#  define RX65N_RIIC2_IRQBASE    RX65N_RIIC0_IRQBASE
#endif
  
#ifdef CONFIG_RX65N_RIIC2
#  define RX65N_RXI2_IRQ        (RX65N_RIIC2_IRQBASE + RX_RXI_IRQ_OFFSET)
#  define RX65N_TXI2_IRQ        (RX65N_RIIC2_IRQBASE + RX_TXI_IRQ_OFFSET)
#  define RX65N_SCI0_IRQBASE    (RX65N_RIIC2_IRQBASE + RX_SCI_NIRQS)
#else
#  define RX65N_SCI0_IRQBASE    RX65N_RIIC2_IRQBASE
#endif

#ifdef CONFIG_RX65N_SCI0
#  define RX65N_RXI0_IRQ        (RX65N_SCI0_IRQBASE + RX_RXI_IRQ_OFFSET)
#  define RX65N_TXI0_IRQ        (RX65N_SCI0_IRQBASE + RX_TXI_IRQ_OFFSET)
#  define RX65N_SCI1_IRQBASE    (RX65N_SCI0_IRQBASE + RX_SCI_NIRQS)
#else
#  define RX65N_SCI1_IRQBASE    RX65N_SCI0_IRQBASE
#endif
  
#ifdef CONFIG_RX65N_SCI1
#  define RX65N_RXI1_IRQ        (RX65N_SCI1_IRQBASE + RX_RXI_IRQ_OFFSET)
#  define RX65N_TXI1_IRQ        (RX65N_SCI1_IRQBASE + RX_TXI_IRQ_OFFSET)
#  define RX65N_SCI2_IRQBASE    (RX65N_SCI1_IRQBASE + RX_SCI_NIRQS)
#else
#  define RX_SCI2_IRQBASE    RX65N_SCI1_IRQBASE
#endif

//#define RX_SCI2_IRQBASE (0)
#ifdef CONFIG_RX65N_SCI2                                           /* SCI0 */
#  define RX_ERI2_IRQ     (RX_SCI2_IRQBASE+0) /*  ERI0 */
#  define RX_RXI2_IRQ     (RX_SCI2_IRQBASE+1) /*  RxI0 */
#  define RX_TXI2_IRQ     (RX_SCI2_IRQBASE+2) /*  TxI0 */
#  define RX_TEI2_IRQ     (RX_SCI2_IRQBASE+3) /*  TEI0 */
#  define RX65N_ICU_IRQ_IRQBASE (RX_SCI2_IRQBASE+2)
#else
#  define RX65N_ICU_IRQ_IRQBASE  RX_SCI2_IRQBASE
#endif


/*#ifdef CONFIG_RX65N_SCI2
#  define RX65N_RXI2_IRQ              (RX65N_SCI2_IRQBASE + RX_RXI_IRQ_OFFSET)
#  define RX65N_TXI2_IRQ              (RX65N_SCI2_IRQBASE + RX_TXI_IRQ_OFFSET)
#  define RX65N_ICU_IRQ_IRQBASE    (RX65N_SCI2_IRQBASE + RX_SCI_NIRQS)
#else
#  define RX65N_ICU_IRQ_IRQBASE    RX65N_SCI2_IRQBASE
#endif*/

#ifdef CONFIG_RX65N_ICU_IRQ
#  define RX65N_IRQ0_IRQ      (RX65N_ICU_SWITCH_IRQBASE)      
#  define RX65N_IRQ1_IRQ      (RX65N_ICU_SWITCH_IRQBASE+1)  
#  define RX65N_IRQ2_IRQ      (RX65N_ICU_SWITCH_IRQBASE+2)  
#  define RX65N_IRQ3_IRQ      (RX65N_ICU_SWITCH_IRQBASE+3)  
#  define RX65N_IRQ4_IRQ      (RX65N_ICU_SWITCH_IRQBASE+4)  
#  define RX65N_IRQ5_IRQ      (RX65N_ICU_SWITCH_IRQBASE+5)  
#  define RX65N_IRQ6_IRQ      (RX65N_ICU_SWITCH_IRQBASE+6)  
#  define RX65N_IRQ7_IRQ      (RX65N_ICU_SWITCH_IRQBASE+7)  
#  define RX65N_IRQ8_IRQ      (RX65N_ICU_SWITCH_IRQBASE+8)
#  define RX65N_IRQ9_IRQ      (RX65N_ICU_SWITCH_IRQBASE+9)
#  define RX65N_IRQ10_IRQ     (RX65N_ICU_SWITCH_IRQBASE+10)
#  define RX65N_IRQ11_IRQ     (RX65N_ICU_SWITCH_IRQBASE+11)
#  define RX65N_IRQ12_IRQ     (RX65N_ICU_SWITCH_IRQBASE+12)
#  define RX65N_IRQ13_IRQ     (RX65N_ICU_SWITCH_IRQBASE+13)
#  define RX65N_IRQ14_IRQ     (RX65N_ICU_SWITCH_IRQBASE+14)
#  define RX65N_IRQ15_IRQ     (RX65N_ICU_SWITCH_IRQBASE+15)
#  define RX65N_SCI3_IRQBASE  (RX65N_ICU_SWITCH_IRQBASE+16)
#else
#  define RX65N_SCI3_IRQBASE  (RX65N_ICU_SWITCH_IRQBASE)
#endif

#ifdef CONFIG_RX65N_SCI3
#  define RX65N_RXI3_IRQ        (RX65N_SCI3_IRQBASE + RX_RXI_IRQ_OFFSET)
#  define RX65N_TXI3_IRQ        (RX65N_SCI3_IRQBASE + RX_TXI_IRQ_OFFSET)
#  define RX65N_SCI4_IRQBASE    (RX65N_SCI3_IRQBASE + RX_SCI_NIRQS)
#else
#  define RX65N_SCI4_IRQBASE    RX65N_SCI3_IRQBASE
#endif
  
#ifdef CONFIG_RX65N_SCI4
#  define RX65N_RXI4_IRQ        (RX65N_SCI4_IRQBASE + RX_RXI_IRQ_OFFSET)
#  define RX65N_TXI4_IRQ        (RX65N_SCI4_IRQBASE + RX_TXI_IRQ_OFFSET)
#  define RX65N_SCI5_IRQBASE    (RX65N_SCI4_IRQBASE + RX_SCI_NIRQS)
#else
#  define RX65N_SCI5_IRQBASE    RX65N_SCI4_IRQBASE
#endif
  
#ifdef CONFIG_RX65N_SCI5
#  define RX65N_RXI5_IRQ        (RX65N_SCI5_IRQBASE + RX_RXI_IRQ_OFFSET)
#  define RX65N_TXI5_IRQ        (RX65N_SCI5_IRQBASE + RX_TXI_IRQ_OFFSET)
#  define RX65N_SCI6_IRQBASE    (RX65N_SCI5_IRQBASE + RX_SCI_NIRQS)
#else
#  define RX65N_SCI6_IRQBASE    RX65N_SCI5_IRQBASE
#endif
  
#ifdef CONFIG_RX65N_SCI6
#  define RX65N_RXI6_IRQ        (RX65N_SCI6_IRQBASE + RX_RXI_IRQ_OFFSET)
#  define RX65N_TXI6_IRQ        (RX65N_SCI6_IRQBASE + RX_TXI_IRQ_OFFSET)
#  define RX65N_LVD1_IRQBASE    (RX65N_SCI6_IRQBASE + RX_SCI_NIRQS)
#else
#  define RX65N_LVD1_IRQBASE    RX65N_SCI6_IRQBASE
#endif

#ifdef CONFIG_RX65N_LVD1
#  define RX65N_LVD1_IRQ         RX65N_LVD1_IRQBASE 
#  define RX65N_LVD2_IRQBASE    (RX65N_LVD1_IRQBASE + 1)
#else
#  define RX65N_LVD2_IRQBASE    RX65N_LVD1_IRQBASE
#endif
  
#ifdef CONFIG_RX65N_LVD2
#  define RX65N_LVD2_IRQ           RX65N_LVD2_IRQBASE 
#  define RX65N_USB0_R0_IRQBASE    (RX65N_LVD2_IRQBASE + 1)
#else
#  define RX65N_USB0_R0_IRQBASE    RX65N_LVD2_IRQBASE
#endif

#ifdef CONFIG_RX65N_USB0_R0
#  define RX65N_USBR0_IRQ       (RX65N_USB0_R0_IRQBASE)
#  define RX65N_RTC_IRQBASE     (RX65N_USB0_R0_IRQBASE)
#else
#  define RX65N_RTC_IRQBASE     RX65N_USB0_R0_IRQBASE
#endif

#ifdef CONFIG_RX65N_RTC
#  define RX65N_ALM_IRQ         RX65N_RTC_IRQBASE 
#  define RX65N_PRD_IRQ         (RX65N_RTC_IRQBASE + 1)
#  define RX65N_IWDT_IRQBASE    (RX65N_RTC_IRQBASE + 2)
#else
#  define RX65N_IWDT_IRQBASE    RX65N_RTC_IRQBASE
#endif

#ifdef CONFIG_RX65N_IWDT
#  define RX65N_IWUNI_IRQ        RX65N_IWDT_IRQBASE 
#  define RX65N_WDT_IRQBASE      (RX65N_IWDT_IRQBASE + 1)
#else
#  define RX65N_WDT_IRQBASE      RX65N_IWDT_IRQBASE
#endif

#ifdef CONFIG_RX65N_WDT
#  define RX65N_WUNI_IRQ         RX65N_WDT_IRQBASE 
#  define RX65N_PDC_IRQBASE     (RX65N_WDT_IRQBASE + 1)
#else
#  define RX65N_PDC_IRQBASE      RX65N_WDT_IRQBASE
#endif
  
#ifdef CONFIG_RX65N_PDC
#  define RX65N_PCDFI_IRQ        RX65N_PDC_IRQBASE 
#  define RX65N_SCI7_IRQBASE    (RX65N_PDC_IRQBASE + 1)
#else
#  define RX65N_SCI7_IRQBASE    RX65N_PDC_IRQBASE
#endif

#ifdef CONFIG_RX65N_SCI7
#  define RX65N_RXI7_IRQ        (RX65N_SCI7_IRQBASE + RX_RXI_IRQ_OFFSET)
#  define RX65N_TXI7_IRQ        (RX65N_SCI7_IRQBASE + RX_TXI_IRQ_OFFSET)
#  define RX65N_SCI8_IRQBASE    (RX65N_SCI7_IRQBASE + RX_SCI_NIRQS)
#else
#  define RX65N_SCI8_IRQBASE    RX65N_SCI7_IRQBASE
#endif
  
#ifdef CONFIG_RX65N_SCI8
#  define RX65N_RXI8_IRQ        (RX65N_SCI8_IRQBASE + RX_RXI_IRQ_OFFSET)
#  define RX65N_TXI8_IRQ        (RX65N_SCI8_IRQBASE + RX_TXI_IRQ_OFFSET)
#  define RX65N_SCI9_IRQBASE    (RX65N_SCI8_IRQBASE + RX_SCI_NIRQS)
#else
#  define RX65N_SCI9_IRQBASE    RX65N_SCI8_IRQBASE
#endif
  
#ifdef CONFIG_RX65N_SCI9
#  define RX65N_RXI9_IRQ        (RX65N_SCI9_IRQBASE + RX_RXI_IRQ_OFFSET)
#  define RX65N_TXI9_IRQ        (RX65N_SCI9_IRQBASE + RX_TXI_IRQ_OFFSET)
#  define RX65N_SCI10_IRQBASE   (RX65N_SCI9_IRQBASE + RX_SCI_NIRQS)
#else
#  define RX65N_SCI10_IRQBASE   RX65N_SCI9_IRQBASE
#endif
  
#ifdef CONFIG_RX65N_SCI10
#  define RX65N_RXI10_IRQ        (RX65N_SCI10_IRQBASE + RX_RXI_IRQ_OFFSET)
#  define RX65N_TXI10_IRQ        (RX65N_SCI10_IRQBASE + RX_TXI_IRQ_OFFSET)
#  define RX65N_IRQ_GROUPB_IRQBASE    (RX65N_SCI10_IRQBASE + RX_SCI_NIRQS)
#else
#  define RX65N_IRQ_GROUPB_IRQBASE    RX65N_SCI10_IRQBASE
#endif

#ifdef CONFIG RX65N_IRQ_GROUPB
#  define RX65N_GROUPBE0_IRQ  (RX65N_IRQ_GROUPB_IRQBASE)
#  define RX65N_GROUPBL2_IRQ  (RX65N_IRQ_GROUPB_IRQBASE + 1)
#  define RX65N_RSPI2_IRQBASE (RX65N_IRQ_GROUPB_IRQBASE + 2)
#else
#  define RX65N_RSPI2_IRQBASE (RX65N_IRQ_GROUPB_IRQBASE)
#endif

#ifdef CONFIG_RX65N_RSPI2
#  define RX65N_SPRI2_IRQ               RX65N_RSPI2_IRQBASE 
#  define RX65N_SPTI2_IRQ               (RX65N_RSPI2_IRQBASE + 1)
#  define RX65N_IRQ_GROUPBL_IRQBASE     (RX65N_RSPI2_IRQBASE + 2)
#else
#  define RX65N_IRQ_GROUPBL_IRQBASE     RX65N_RSPI2_IRQBASE
#endif

#ifdef CONFIG RX65N_IRQ_GROUPBL
#  define RX65N_GROUPBL0_IRQ  (RX65N_IRQ_GROUPBL_IRQBASE)
#  define RX65N_GROUPBL1_IRQ  (RX65N_IRQ_GROUPBL_IRQBASE + 1)
#  define RX65N_GROUPAL0_IRQ  (RX65N_IRQ_GROUPBL_IRQBASE + 2)
#  define RX65N_GROUPAL1_IRQ  (RX65N_IRQ_GROUPBL_IRQBASE + 3)
#  define RX65N_SCI11_IRQBASE (RX65N_IRQ_GROUPBL_IRQBASE + 4)
#else
#  define RX65N_SCI11_IRQBASE (RX65N_IRQ_GROUPBL_IRQBASE)
#endif

#ifdef CONFIG_RX65N_SCI11
#  define RX65N_RXI11_IRQ        (RX65N_SCI11_IRQBASE + RX_RXI_IRQ_OFFSET)
#  define RX65N_TXI11_IRQ        (RX65N_SCI11_IRQBASE + RX_TXI_IRQ_OFFSET)
#  define RX65N_SCI12_IRQBASE    (RX65N_SCI11_IRQBASE + RX_SCI_NIRQS)
#else
#  define RX65N_SCI12_IRQBASE    RX65N_SCI11_IRQBASE
#endif
  
#ifdef CONFIG_RX65N_SCI12
#  define RX65N_RXI12_IRQ        RX65N_SCI12_IRQBASE + RX_RXI_IRQ_OFFSET
#  define RX65N_TXI12_IRQ        RX65N_SCI12_IRQBASE + RX_TXI_IRQ_OFFSET
#  define RX65N_DMAC_IRQBASE     RX65N_SCI12_IRQBASE + RX_SCI_NIRQS
#else
#  define RX65N_DMAC_IRQBASE     RX65N_SCI12_IRQBASE
#endif*/
  

#ifdef CONFIG_RX65N_DMAC
#  define RX65N_DMAC0I_IRQ        RX65N_DMAC_IRQBASE 
#  define RX65N_DMAC1I_IRQ        (RX65N_DMAC_IRQBASE + 1)
#  define RX65N_DMAC2I_IRQ        (RX65N_DMAC_IRQBASE + 2)
#  define RX65N_DMAC3I_IRQ        (RX65N_DMAC_IRQBASE + 3)
#  define RX65N_DMAC74I_IRQ       (RX65N_DMAC_IRQBASE + 4)
#  define RX65N_OST_IRQBASE       (RX65N_DMAC_IRQBASE + 5)
#else
#  define RX65N_OST_IRQBASE       RX65N_DMAC_IRQBASE
#endif
  
#ifdef CONFIG_RX65N_OST
#  define RX65N_OSTD1_IRQ         RX65N_OST_IRQBASE 
#  define RX65N_EXDMAC_IRQBASE    (RX65N_OST_IRQBASE + 1)
#else
#  define RX65N_EXDMAC_IRQBASE    RX65N_OST_IRQBASE
#endif
  
#ifdef CONFIG_RX65N_EXDMAC
#  define RX65N_EXDMAC0I_IRQ         RX65N_EXDMAC_IRQBASE 
#  define RX65N_EXDMAC1I_IRQ         (RX65N_EXDMAC_IRQBASE + 1)
#  define RX65N_PERIB_IRQBASE        (RX65N_EXDMAC_IRQBASE + 2)
#else
#  define RX65N_PERIB_IRQBASE        RX65N_EXDMAC_IRQBASE
#endif
  
#  ifdef CONFIG_RX65N_PERIB
#  define RX65N_INTB128_IRQ          RX65N_PERIB_IRQBASE
#  define RX65N_INTB129_IRQ          RX65N_PERIB_IRQBASE + 1
#  define RX65N_INTB130_IRQ          RX65N_PERIB_IRQBASE + 2
#  define RX65N_INTB131_IRQ          RX65N_PERIB_IRQBASE + 3
#  define RX65N_INTB132_IRQ          RX65N_PERIB_IRQBASE + 4
#  define RX65N_INTB133_IRQ          RX65N_PERIB_IRQBASE + 5
#  define RX65N_INTB134_IRQ          RX65N_PERIB_IRQBASE + 6
#  define RX65N_INTB135_IRQ          RX65N_PERIB_IRQBASE + 7
#  define RX65N_INTB136_IRQ          RX65N_PERIB_IRQBASE + 8
#  define RX65N_INTB137_IRQ          RX65N_PERIB_IRQBASE + 9
#  define RX65N_INTB138_IRQ          RX65N_PERIB_IRQBASE + 10
#  define RX65N_INTB139_IRQ          RX65N_PERIB_IRQBASE + 11
#  define RX65N_INTB140_IRQ          RX65N_PERIB_IRQBASE + 12
#  define RX65N_INTB141_IRQ          RX65N_PERIB_IRQBASE + 13
#  define RX65N_INTB142_IRQ          RX65N_PERIB_IRQBASE + 14
#  define RX65N_INTB143_IRQ          RX65N_PERIB_IRQBASE + 15
#  define RX65N_INTB144_IRQ          RX65N_PERIB_IRQBASE + 16
#  define RX65N_INTB145_IRQ          RX65N_PERIB_IRQBASE + 17
#  define RX65N_INTB146_IRQ          RX65N_PERIB_IRQBASE + 18
#  define RX65N_INTB147_IRQ          RX65N_PERIB_IRQBASE + 19
#  define RX65N_INTB148_IRQ          RX65N_PERIB_IRQBASE + 20
#  define RX65N_INTB149_IRQ          RX65N_PERIB_IRQBASE + 21
#  define RX65N_INTB150_IRQ          RX65N_PERIB_IRQBASE + 22
#  define RX65N_INTB151_IRQ          RX65N_PERIB_IRQBASE + 23
#  define RX65N_INTB152_IRQ          RX65N_PERIB_IRQBASE + 24
#  define RX65N_INTB153_IRQ          RX65N_PERIB_IRQBASE + 25
#  define RX65N_INTB154_IRQ          RX65N_PERIB_IRQBASE + 26
#  define RX65N_INTB155_IRQ          RX65N_PERIB_IRQBASE + 27
#  define RX65N_INTB156_IRQ          RX65N_PERIB_IRQBASE + 28
#  define RX65N_INTB157_IRQ          RX65N_PERIB_IRQBASE + 29
#  define RX65N_INTB158_IRQ          RX65N_PERIB_IRQBASE + 30
#  define RX65N_INTB159_IRQ          RX65N_PERIB_IRQBASE + 31
#  define RX65N_INTB160_IRQ          RX65N_PERIB_IRQBASE + 32
#  define RX65N_INTB161_IRQ          RX65N_PERIB_IRQBASE + 33
#  define RX65N_INTB162_IRQ          RX65N_PERIB_IRQBASE + 34
#  define RX65N_INTB163_IRQ          RX65N_PERIB_IRQBASE + 35
#  define RX65N_INTB164_IRQ          RX65N_PERIB_IRQBASE + 36
#  define RX65N_INTB165_IRQ          RX65N_PERIB_IRQBASE + 37
#  define RX65N_INTB166_IRQ          RX65N_PERIB_IRQBASE + 38
#  define RX65N_INTB167_IRQ          RX65N_PERIB_IRQBASE + 39
#  define RX65N_INTB168_IRQ          RX65N_PERIB_IRQBASE + 40
#  define RX65N_INTB169_IRQ          RX65N_PERIB_IRQBASE + 41
#  define RX65N_INTB170_IRQ          RX65N_PERIB_IRQBASE + 42
#  define RX65N_INTB171_IRQ          RX65N_PERIB_IRQBASE + 43
#  define RX65N_INTB172_IRQ          RX65N_PERIB_IRQBASE + 44
#  define RX65N_INTB173_IRQ          RX65N_PERIB_IRQBASE + 45
#  define RX65N_INTB174_IRQ          RX65N_PERIB_IRQBASE + 46
#  define RX65N_INTB175_IRQ          RX65N_PERIB_IRQBASE + 47
#  define RX65N_INTB176_IRQ          RX65N_PERIB_IRQBASE + 48
#  define RX65N_INTB177_IRQ          RX65N_PERIB_IRQBASE + 49
#  define RX65N_INTB178_IRQ          RX65N_PERIB_IRQBASE + 50
#  define RX65N_INTB179_IRQ          RX65N_PERIB_IRQBASE + 51
#  define RX65N_INTB180_IRQ          RX65N_PERIB_IRQBASE + 52
#  define RX65N_INTB181_IRQ          RX65N_PERIB_IRQBASE + 53
#  define RX65N_INTB182_IRQ          RX65N_PERIB_IRQBASE + 54
#  define RX65N_INTB183_IRQ          RX65N_PERIB_IRQBASE + 55
#  define RX65N_INTB184_IRQ          RX65N_PERIB_IRQBASE + 56
#  define RX65N_INTB185_IRQ          RX65N_PERIB_IRQBASE + 57
#  define RX65N_INTB186_IRQ          RX65N_PERIB_IRQBASE + 58
#  define RX65N_INTB187_IRQ          RX65N_PERIB_IRQBASE + 59
#  define RX65N_INTB188_IRQ          RX65N_PERIB_IRQBASE + 60
#  define RX65N_INTB189_IRQ          RX65N_PERIB_IRQBASE + 61
#  define RX65N_INTB190_IRQ          RX65N_PERIB_IRQBASE + 62
#  define RX65N_INTB191_IRQ          RX65N_PERIB_IRQBASE + 63
#  define RX65N_INTB192_IRQ          RX65N_PERIB_IRQBASE + 64
#  define RX65N_INTB193_IRQ          RX65N_PERIB_IRQBASE + 65
#  define RX65N_INTB194_IRQ          RX65N_PERIB_IRQBASE + 66
#  define RX65N_INTB195_IRQ          RX65N_PERIB_IRQBASE + 67
#  define RX65N_INTB196_IRQ          RX65N_PERIB_IRQBASE + 68
#  define RX65N_INTB197_IRQ          RX65N_PERIB_IRQBASE + 69
#  define RX65N_INTB198_IRQ          RX65N_PERIB_IRQBASE + 70
#  define RX65N_INTB199_IRQ          RX65N_PERIB_IRQBASE + 71
#  define RX65N_INTB200_IRQ          RX65N_PERIB_IRQBASE + 72
#  define RX65N_INTB201_IRQ          RX65N_PERIB_IRQBASE + 73
#  define RX65N_INTB202_IRQ          RX65N_PERIB_IRQBASE + 74
#  define RX65N_INTB203_IRQ          RX65N_PERIB_IRQBASE + 75
#  define RX65N_INTB204_IRQ          RX65N_PERIB_IRQBASE + 76
#  define RX65N_INTB205_IRQ          RX65N_PERIB_IRQBASE + 77
#  define RX65N_INTB206_IRQ          RX65N_PERIB_IRQBASE + 78
#  define RX65N_INTB207_IRQ          RX65N_PERIB_IRQBASE + 79
#  define RX65N_PERIA_IRQBASE        RX65N_PERIB_IRQBASE + 80
#else
#  define RX65N_PERIA_IRQBASE        RX65N_PERIB_IRQBASE
#endif
  
#ifdef CONFIG_RX65N_PERIA
#  define RX65N_INTB208_IRQ          RX65N_PERIA_IRQBASE
#  define RX65N_INTB209_IRQ          RX65N_PERIA_IRQBASE + 1
#  define RX65N_INTB210_IRQ          RX65N_PERIA_IRQBASE + 2
#  define RX65N_INTB211_IRQ          RX65N_PERIA_IRQBASE + 3
#  define RX65N_INTB212_IRQ          RX65N_PERIA_IRQBASE + 4
#  define RX65N_INTB213_IRQ          RX65N_PERIA_IRQBASE + 5
#  define RX65N_INTB214_IRQ          RX65N_PERIA_IRQBASE + 6
#  define RX65N_INTB215_IRQ          RX65N_PERIA_IRQBASE + 7
#  define RX65N_INTB216_IRQ          RX65N_PERIA_IRQBASE + 8
#  define RX65N_INTB217_IRQ          RX65N_PERIA_IRQBASE + 9
#  define RX65N_INTB218_IRQ          RX65N_PERIA_IRQBASE + 10
#  define RX65N_INTB219_IRQ          RX65N_PERIA_IRQBASE + 11
#  define RX65N_INTB220_IRQ          RX65N_PERIA_IRQBASE + 12
#  define RX65N_INTB221_IRQ          RX65N_PERIA_IRQBASE + 13
#  define RX65N_INTB222_IRQ          RX65N_PERIA_IRQBASE + 14
#  define RX65N_INTB223_IRQ          RX65N_PERIA_IRQBASE + 15
#  define RX65N_INTB224_IRQ          RX65N_PERIA_IRQBASE + 16
#  define RX65N_INTB225_IRQ          RX65N_PERIA_IRQBASE + 17
#  define RX65N_INTB226_IRQ          RX65N_PERIA_IRQBASE + 18
#  define RX65N_INTB227_IRQ          RX65N_PERIA_IRQBASE + 19
#  define RX65N_INTB228_IRQ          RX65N_PERIA_IRQBASE + 20
#  define RX65N_INTB229_IRQ          RX65N_PERIA_IRQBASE + 21
#  define RX65N_INTB230_IRQ          RX65N_PERIA_IRQBASE + 22
#  define RX65N_INTB231_IRQ          RX65N_PERIA_IRQBASE + 23
#  define RX65N_INTB232_IRQ          RX65N_PERIA_IRQBASE + 24
#  define RX65N_INTB233_IRQ          RX65N_PERIA_IRQBASE + 25
#  define RX65N_INTB234_IRQ          RX65N_PERIA_IRQBASE + 26
#  define RX65N_INTB235_IRQ          RX65N_PERIA_IRQBASE + 27
#  define RX65N_INTB236_IRQ          RX65N_PERIA_IRQBASE + 28
#  define RX65N_INTB237_IRQ          RX65N_PERIA_IRQBASE + 29
#  define RX65N_INTB238_IRQ          RX65N_PERIA_IRQBASE + 30
#  define RX65N_INTB239_IRQ          RX65N_PERIA_IRQBASE + 31
#  define RX65N_INTB240_IRQ          RX65N_PERIA_IRQBASE + 32
#  define RX65N_INTB241_IRQ          RX65N_PERIA_IRQBASE + 33
#  define RX65N_INTB242_IRQ          RX65N_PERIA_IRQBASE + 34
#  define RX65N_INTB243_IRQ          RX65N_PERIA_IRQBASE + 35
#  define RX65N_INTB244_IRQ          RX65N_PERIA_IRQBASE + 36
#  define RX65N_INTB245_IRQ          RX65N_PERIA_IRQBASE + 37
#  define RX65N_INTB246_IRQ          RX65N_PERIA_IRQBASE + 38
#  define RX65N_INTB247_IRQ          RX65N_PERIA_IRQBASE + 39
#  define RX65N_INTB248_IRQ          RX65N_PERIA_IRQBASE + 40
#  define RX65N_INTB249_IRQ          RX65N_PERIA_IRQBASE + 41
#  define RX65N_INTB250_IRQ          RX65N_PERIA_IRQBASE + 42
#  define RX65N_INTB251_IRQ          RX65N_PERIA_IRQBASE + 43
#  define RX65N_INTB252_IRQ          RX65N_PERIA_IRQBASE + 44
#  define RX65N_INTB253_IRQ          RX65N_PERIA_IRQBASE + 45
#  define RX65N_INTB254_IRQ          RX65N_PERIA_IRQBASE + 46
#  define RX65N_INTB255_IRQ          RX65N_PERIA_IRQBASE + 47
//#  define NR_IRQS                    RX65N_PERIA_IRQBASE + 48
#else
//#  define NR_IRQS                    RX65N_PERIA_IRQBASE 
#endif


#endif
/* IRQ Stack Frame Format.  The SH-1 has a push down stack.  The PC
 * and SR are pushed by hardware at the time an IRQ is taken.
 */

/* Saved to the stacked by up_vector */


/* Vector table offets **************************************************************/ 

/* Trap instruction */ 
#  define RX65N_TRAP_VNDX      (0)  
#  define RX65N_TRAP0_VNDX     (0)  
#  define RX65N_TRAP1_VNDX     (1)  
#  define RX65N_TRAP2_VNDX     (2)  
#  define RX65N_TRAP3_VNDX     (3)  
#  define RX65N_TRAP4_VNDX     (4)  
#  define RX65N_TRAP5_VNDX     (5)  
#  define RX65N_TRAP6_VNDX     (6)  
#  define RX65N_TRAP7_VNDX     (7)  
#  define RX65N_TRAP8_VNDX     (8)  
#  define RX65N_TRAP9_VNDX     (9)  
#  define RX65N_TRAP10_VNDX    (10) 
#  define RX65N_TRAP11_VNDX    (11) 
#  define RX65N_TRAP12_VNDX    (12) 
#  define RX65N_TRAP13_VNDX    (13) 
#  define RX65N_TRAP14_VNDX    (14) 
#  define RX65N_TRAP15_VNDX    (15) 
/* Bus Error */ 
#  define RX65N_BUSERR_VNDX    (16) 
                                    /* 17 reserved */ 

/* RAM Error */ 
#  define RX65N_RAMERR_VNDX    (18)
                                   /* 19-20 reserved
 /* FIFERR Error */ 
#  define RX65N_FIFERR_VNDX    (21)	
                                   /* 22 reserved
 /* FRDYI */ 
#  define RX65N_FRDYI_VNDX     (23)
                                   /* 24-25 reserved
 /* ICU Interrupts */ 
#ifdef CONFIG_ARCH_CHIP_R5F565NEDDFC

#  define RX65N_SWINT2_VNDX     (26)
#  define RX65N_SWINT_VNDX      (27)
#  define RX65N_IRQ0_VNDX       (64)
#  define RX65N_IRQ1_VNDX       (65)
#  define RX65N_IRQ2_VNDX       (66)
#  define RX65N_IRQ3_VNDX       (67)
#  define RX65N_IRQ4_VNDX       (68)
#  define RX65N_IRQ5_VNDX       (69)
#  define RX65N_IRQ6_VNDX       (70)
#  define RX65N_IRQ7_VNDX       (71)
#  define RX65N_IRQ8_VNDX       (72)
#  define RX65N_IRQ9_VNDX       (73)
#  define RX65N_IRQ10_VNDX      (74)
#  define RX65N_IRQ11_VNDX      (75)
#  define RX65N_IRQ12_VNDX      (76)
#  define RX65N_IRQ13_VNDX      (77)
#  define RX65N_IRQ14_VNDX      (78)
#  define RX65N_IRQ15_VNDX      (79)
#  define RX65N_GROUPBE0_VNDX   (106)
#  define RX65N_GROUPBL2_VNDX   (107)
#  define RX65N_GROUPBL0_VNDX   (110)
#  define RX65N_GROUPBL1_VNDX   (111)
#  define RX65N_GROUPAL0_VNDX   (112)
#  define RX65N_GROUPAL1_VNDX   (113)
  
/* CMT Interrupts */ 
#  define  RX65N_CMI0_VNDX      (28)
#  define  RX65N_CMI0_VNDX      (29)
#  define  RX65N_CMI0_VNDX      (30)
#  define  RX65N_CMI0_VNDX      (31)
                                      /* 32-33 reserved */ 
  
/* USB Interrupts */ 
#  define RX65N_D0FIFO0_VNDX    (34)
#  define RX65N_D1FIFO0_VNDX    (35)
                                     /* 36-37 reserved */ 
#  define RX65N_USBR0_VNDX      (90)
                                     /* 91 reserved */ 
  
/* RSPI Interrupts */ 
#  define RX65N_SPRI0_VNDX      (38)
#  define RX65N_SPTI0_VNDX      (39)
#  define RX65N_SPRI1_VNDX      (40)
#  define RX65N_SPTI1_VNDX      (41)
#  define RX65N_SPRI2_VNDX      (108)
#  define RX65N_SPTI2_VNDX      (109)

/* QSPI Interrupts */ 
#  define RX65N_SPRI_VNDX       (42)
#  define RX65N_SPTI_VNDX       (43)
  
/* SDHI MMC Interrupts */ 
#  define RX65N_SBFAI_VNDX      (44)
#  define RX65N_MBFAI_VNDX      (45)
                                    /* 46 -49 reserved 
 /* RIIC Interrupts */ 
#  define RX65N_EEI1_VNDX       (111) 
#  define RX65N_RXI1_VNDX       (50)
#  define RX65N_TXI1_VNDX       (51)	
#  define RX65N_TEI1_VNDX       (111)
  
#  define RX65N_EEI0_VNDX       (111) 
#  define RX65N_RXI0_VNDX       (52)
#  define RX65N_TXI0_VNDX       (53)	
#  define RX65N_TEI0_VNDX       (111)
  
#  define RX65N_EEI2_VNDX       (111) 
#  define RX65N_RXI2_VNDX       (54)
#  define RX65N_TXI2_VNDX       (55)	
#  define RX65N_TEI2_VNDX       (111)
  

/* SCI Interrupts */ 
#  define RX65N_ERI0_VNDX       (110) 
#  define RX65N_RXI0_VNDX       (58)
#  define RX65N_TXI0_VNDX       (59)	
#  define RX65N_TEI0_VNDX       (110)
  
#  define RX65N_ERI1_VNDX       (110) 
#  define RX65N_RXI1_VNDX       (60)
#  define RX65N_TXI1_VNDX       (61)	
#  define RX65N_TEI1_VNDX       (110)
  
#  define RX65N_ERI2_VNDX       (110) 
#  define RX65N_RXI2_VNDX       (62)
#  define RX65N_TXI2_VNDX       (63)	
#  define RX65N_TEI2_VNDX       (110)
  
#  define RX65N_ERI3_VNDX       (110) 
#  define RX65N_RXI3_VNDX       (80)
#  define RX65N_TXI3_VNDX       (81)	
#  define RX65N_TEI3_VNDX       (110)	
  
#  define RX65N_ERI4_VNDX       (110) 
#  define RX65N_RXI4_VNDX       (82)
#  define RX65N_TXI4_VNDX       (83)	
#  define RX65N_TEI4_VNDX       (110)
  
#  define RX65N_ERI5_VNDX       (110) 
#  define RX65N_RXI5_VNDX       (84)
#  define RX65N_TXI5_VNDX       (85)	
#  define RX65N_TEI5_VNDX       (110)	
  
#  define RX65N_ERI6_VNDX       (110) 
#  define RX65N_RXI6_VNDX       (86)
#  define RX65N_TXI6_VNDX       (87)	
#  define RX65N_TEI6_VNDX       (110)	
  
#  define RX65N_ERI7_VNDX       (110) 
#  define RX65N_RXI7_VNDX       (98)
#  define RX65N_TXI7_VNDX       (99)	
#  define RX65N_TEI7_VNDX       (110)
  
#  define RX65N_ERI8_VNDX       (111) 
#  define RX65N_RXI8_VNDX       (100)
#  define RX65N_TXI8_VNDX       (101)	
#  define RX65N_TEI8_VNDX       (111)	
  
#  define RX65N_ERI9_VNDX       (111) 
#  define RX65N_RXI9_VNDX       (102)
#  define RX65N_TXI9_VNDX       (103)	
#  define RX65N_TEI9_VNDX       (111)
  
#  define RX65N_ERI10_VNDX       (112) 
#  define RX65N_RXI10_VNDX       (104)
#  define RX65N_TXI10_VNDX       (105)	
#  define RX65N_TEI10_VNDX       (112)
  
#  define RX65N_ERI11_VNDX       (112) 
#  define RX65N_RXI11_VNDX       (114)
#  define RX65N_TXI11_VNDX       (115)	
#  define RX65N_TEI11_VNDX       (112)
  
#  define RX65N_ERI12_VNDX       (110) 
#  define RX65N_RXI12_VNDX       (116)
#  define RX65N_TXI12_VNDX       (117)	
#  define RX65N_TEI12_VNDX       (110)
  

/* LVD Interrupts */ 
#  define RX65N_LVD1_VNDX        (88)
#  define RX65N_LVD2_VNDX        (89)
  

/* RTC Interrupts */ 
#  define RX65N_ALM_VNDX         (92)
#  define RX65N_PRD_VNDX         (93)
                                          /* 94 reserved */ 

/* WDT Interrupts */ 
#  define RX65N_IWUNI_VNDX        (95)
#  define RX65N_WUNI_VNDX         (96)
  

/* PDC Interrupts */ 
#  define RX65N_PCDFI_VNDX        (97)								 
  

/* DMAC Interrupts */ 
#  define RX65N_DMAC0I_VNDX       (120)
#  define RX65N_DMAC1I_VNDX       (121)
#  define RX65N_DMAC2I_VNDX       (122)
#  define RX65N_DMAC3I_VNDX       (123)
#  define RX65N_DMAC74I_VNDX      (124)
  

/*OST Interrupts */ 
#  define RX65N_OSTDI_VNDX        (125)
  

/* EXDMAC Interrupts */ 
#  define RX65N_EXDMAC0I_VNDX        (126)
#  define RX65N_EXDMAC1I_VNDX        (127)
  

/* PERIB Interrupts */ 
#  define RX65N_INTB128_VNDX         (128)
#  define RX65N_INTB129_VNDX         (129)
#  define RX65N_INTB130_VNDX         (130)
#  define RX65N_INTB131_VNDX         (131)
#  define RX65N_INTB132_VNDX         (132)
#  define RX65N_INTB133_VNDX         (133)
#  define RX65N_INTB134_VNDX         (134)
#  define RX65N_INTB135_VNDX         (135)
#  define RX65N_INTB136_VNDX         (136)
#  define RX65N_INTB137_VNDX         (137)
#  define RX65N_INTB138_VNDX         (138)
#  define RX65N_INTB139_VNDX         (139)
#  define RX65N_INTB140_VNDX         (140)
#  define RX65N_INTB141_VNDX         (141)
#  define RX65N_INTB142_VNDX         (142)
#  define RX65N_INTB143_VNDX         (143)
#  define RX65N_INTB144_VNDX         (144)
#  define RX65N_INTB145_VNDX         (145)
#  define RX65N_INTB146_VNDX         (146)
#  define RX65N_INTB147_VNDX         (147)
#  define RX65N_INTB148_VNDX         (148)
#  define RX65N_INTB149_VNDX         (149)
#  define RX65N_INTB150_VNDX         (150)
#  define RX65N_INTB151_VNDX         (151)
#  define RX65N_INTB152_VNDX         (152)
#  define RX65N_INTB153_VNDX         (153)
#  define RX65N_INTB154_VNDX         (154)
#  define RX65N_INTB155_VNDX         (155)
#  define RX65N_INTB156_VNDX         (156)
#  define RX65N_INTB157_VNDX         (157)
#  define RX65N_INTB158_VNDX         (158)
#  define RX65N_INTB159_VNDX         (159)
#  define RX65N_INTB160_VNDX         (160)
#  define RX65N_INTB161_VNDX         (161)
#  define RX65N_INTB162_VNDX         (162)
#  define RX65N_INTB163_VNDX         (163)
#  define RX65N_INTB164_VNDX         (164)
#  define RX65N_INTB165_VNDX         (165)
#  define RX65N_INTB166_VNDX         (166)
#  define RX65N_INTB167_VNDX         (167)
#  define RX65N_INTB168_VNDX         (168)
#  define RX65N_INTB169_VNDX         (169)
#  define RX65N_INTB170_VNDX         (170)
#  define RX65N_INTB171_VNDX         (171)
#  define RX65N_INTB172_VNDX         (172)
#  define RX65N_INTB173_VNDX         (173)
#  define RX65N_INTB174_VNDX         (174)
#  define RX65N_INTB175_VNDX         (175)
#  define RX65N_INTB176_VNDX         (176)
#  define RX65N_INTB177_VNDX         (177)
#  define RX65N_INTB178_VNDX         (178)
#  define RX65N_INTB179_VNDX         (179)
#  define RX65N_INTB180_VNDX         (180)
#  define RX65N_INTB181_VNDX         (181)
#  define RX65N_INTB182_VNDX         (182)
#  define RX65N_INTB183_VNDX         (183)
#  define RX65N_INTB184_VNDX         (184)
#  define RX65N_INTB185_VNDX         (185)
#  define RX65N_INTB186_VNDX         (186)
#  define RX65N_INTB187_VNDX         (187)
#  define RX65N_INTB188_VNDX         (188)
#  define RX65N_INTB189_VNDX         (189)
#  define RX65N_INTB190_VNDX         (190)
#  define RX65N_INTB191_VNDX         (191)
#  define RX65N_INTB192_VNDX         (192)
#  define RX65N_INTB193_VNDX         (193)
#  define RX65N_INTB194_VNDX         (194)
#  define RX65N_INTB195_VNDX         (195)
#  define RX65N_INTB196_VNDX         (196)
#  define RX65N_INTB197_VNDX         (197)
#  define RX65N_INTB198_VNDX         (198)
#  define RX65N_INTB199_VNDX         (199)
#  define RX65N_INTB200_VNDX         (200)
#  define RX65N_INTB201_VNDX         (201)
#  define RX65N_INTB202_VNDX         (202)
#  define RX65N_INTB203_VNDX         (203)
#  define RX65N_INTB204_VNDX         (204)
#  define RX65N_INTB205_VNDX         (205)
#  define RX65N_INTB206_VNDX         (206)
#  define RX65N_INTB207_VNDX         (207)
  

/*PERIA Interrupts */ 
#  define RX65N_INTB208_VNDX         (208)
#  define RX65N_INTB209_VNDX         (209)
#  define RX65N_INTB210_VNDX         (210)
#  define RX65N_INTB211_VNDX         (211)
#  define RX65N_INTB212_VNDX         (212)
#  define RX65N_INTB213_VNDX         (213)
#  define RX65N_INTB214_VNDX         (214)
#  define RX65N_INTB215_VNDX         (215)
#  define RX65N_INTB216_VNDX         (216)
#  define RX65N_INTB217_VNDX         (217)
#  define RX65N_INTB218_VNDX         (218)
#  define RX65N_INTB219_VNDX         (219)
#  define RX65N_INTB220_VNDX         (220)
#  define RX65N_INTB221_VNDX         (221)
#  define RX65N_INTB222_VNDX         (222)
#  define RX65N_INTB223_VNDX         (223)
#  define RX65N_INTB224_VNDX         (224)
#  define RX65N_INTB225_VNDX         (225)
#  define RX65N_INTB226_VNDX         (226)
#  define RX65N_INTB227_VNDX         (227)
#  define RX65N_INTB228_VNDX         (228)
#  define RX65N_INTB229_VNDX         (229)
#  define RX65N_INTB230_VNDX         (230)
#  define RX65N_INTB231_VNDX         (231)
#  define RX65N_INTB232_VNDX         (232)
#  define RX65N_INTB233_VNDX         (233)
#  define RX65N_INTB234_VNDX         (234)
#  define RX65N_INTB235_VNDX         (235)
#  define RX65N_INTB236_VNDX         (236)
#  define RX65N_INTB237_VNDX         (237)
#  define RX65N_INTB238_VNDX         (238)
#  define RX65N_INTB239_VNDX         (239)
#  define RX65N_INTB240_VNDX         (240)
#  define RX65N_INTB241_VNDX         (241)
#  define RX65N_INTB242_VNDX         (242)
#  define RX65N_INTB243_VNDX         (243)
#  define RX65N_INTB244_VNDX         (244)
#  define RX65N_INTB245_VNDX         (245)
#  define RX65N_INTB246_VNDX         (246)
#  define RX65N_INTB247_VNDX         (247)
#  define RX65N_INTB248_VNDX         (248)
#  define RX65N_INTB249_VNDX         (249)
#  define RX65N_INTB250_VNDX         (250)
#  define RX65N_INTB251_VNDX         (251)
#  define RX65N_INTB252_VNDX         (252)
#  define RX65N_INTB253_VNDX         (253)
#  define RX65N_INTB254_VNDX         (254)
#  define RX65N_INTB255_VNDX         (255)
#endif
#define RX65N_NVECTORS               (256)



/* Register information */
 
#  define REG_R8              (0)
#  define REG_R9              (1)
#  define REG_R10             (2)
#  define REG_R11             (3)
#  define REG_R12             (4)
#  define REG_R13             (5)
#  define REG_R14             (6)
#  define REG_R15             (7)
  
 /* The value of the stack pointer *before* the interrupt occurred */ 
  
#  define REG_R0             (8)
#define REG_SP              REG_R0
/* These registers do not need to be preserved by up_saveusercontext */ 
  
//#  define REG_ACC0            (10)
//#  define REG_ACC1            (11)
#  define REG_R1              (9)
#  define REG_R2              (10)
#  define REG_R3              (11)
#  define REG_R5              (12)
#  define REG_R6              (13)
#  define REG_R7              (14)
  

/* Saved to the stack by the trampoline logic */ 
  
#  define REG_R4              (15)
  

/* Pushed by hardware when the exception is taken */ 
  
#  define REG_PC               (16)
#  define REG_PSW              (17)
#  define XCPTCONTEXT_REGS     (18)
#  define XCPTCONTEXT_SIZE     (4 * XCPTCONTEXT_REGS)
#ifndef __ASSEMBLY__
struct xcptcontext
{
  /* The following function pointer is non-zero if there are pending signals
   * to be processed.
   */

  void *sigdeliver; /* Actual type is sig_deliver_t */

  /* These are saved copies of LR and SR used during signal processing. */

  uint32_t saved_pc;
  uint32_t saved_sr;

  /* Register save area */

  uint32_t regs[XCPTCONTEXT_REGS];
};
#endif

#ifndef __ASSEMBLY__

/* Name: up_irq_save, up_irq_restore, and friends.
 *
 * NOTE: This function should never be called from application code and,
 * as a general rule unless you really know what you are doing, this
 * function should not be called directly from operation system code either:
 * Typically, the wrapper functions, enter_critical_section() and
 * leave_critical section(), are probably what you really want.
 */

/* Return the current interrupt enable state and disable IRQs */

/* Get the current value of the SR */

static inline irqstate_t __getsr(void) 
{
  /*irqstate_t flags;
  __asm__ __volatile__("mvfc psw, %0":"=r"(flags));
  return flags;*/
}

/* Set the new value of the SR */

static inline void __setsr(irqstate_t psw) 
{
 /* __asm__ __volatile__("mvtc %0, psw": :"r"(psw));*/
} 

/* Return the current interrupt enable state and disable interrupts */

static inline irqstate_t up_irq_save(void)
{
  /*irqstate_t flags = __getsr();
  __setsr(flags | 0x00010000);
  return flags;*/
}
 
/* Disable interrupts */

static inline void up_irq_disable(void) 
{
  /*uint32_t flags = __getsr();
  __setsr(flags | 0x00010000);*/
}

/* Enable interrupts */

static inline void up_irq_enable(void) 
{
  /*uint32_t flags = __getsr();*/
  /*__setsr(flags & ~0x00010000);*/
}

/* Restore saved interrupt state */

static inline void up_irq_restore(irqstate_t flags) 
{
  /*if ((flags & 0x00010000) != 0x00010000)
    {
      up_irq_enable();
    }
  else
    {
      up_irq_disable();
    }*/
}

#endif

#endif
