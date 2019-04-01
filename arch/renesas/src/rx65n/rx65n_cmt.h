#ifndef CMT_H
#define CMT_H

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/
/*
    Compare Match Timer Control Register (CMCR)
*/
/* Clock Select (CKS[1:0]) */
#define _0000_CMT_CMCR_CKS_PCLK8                (0x0000U) /* PCLK/8 */
#define _0001_CMT_CMCR_CKS_PCLK32               (0x0001U) /* PCLK/32 */
#define _0002_CMT_CMCR_CKS_PCLK128              (0x0002U) /* PCLK/128 */
#define _0003_CMT_CMCR_CKS_PCLK512              (0x0003U) /* PCLK/512 */
/* Compare Match Interrupt Enable (CMIE) */
#define _0000_CMT_CMCR_CMIE_DISABLE             (0x0000U) /* Compare match interrupt (CMIn) disabled */
#define _0040_CMT_CMCR_CMIE_ENABLE              (0x0040U) /* Compare match interrupt (CMIn) enabled */
#define _0080_CMT_CMCR_DEFAULT                  (0x0080U) /* Write default value of CMCR */

/*
    Interrupt Source Priority Register n (IPRn)
*/
/* Interrupt Priority Level Select (IPR[3:0]) */
#define _00_CMT_PRIORITY_LEVEL0                 (0x00U) /* Level 0 (interrupt disabled) */
#define _01_CMT_PRIORITY_LEVEL1                 (0x01U) /* Level 1 */
#define _02_CMT_PRIORITY_LEVEL2                 (0x02U) /* Level 2 */
#define _03_CMT_PRIORITY_LEVEL3                 (0x03U) /* Level 3 */
#define _04_CMT_PRIORITY_LEVEL4                 (0x04U) /* Level 4 */
#define _05_CMT_PRIORITY_LEVEL5                 (0x05U) /* Level 5 */
#define _06_CMT_PRIORITY_LEVEL6                 (0x06U) /* Level 6 */
#define _07_CMT_PRIORITY_LEVEL7                 (0x07U) /* Level 7 */
#define _08_CMT_PRIORITY_LEVEL8                 (0x08U) /* Level 8 */
#define _09_CMT_PRIORITY_LEVEL9                 (0x09U) /* Level 9 */
#define _0A_CMT_PRIORITY_LEVEL10                (0x0AU) /* Level 10 */
#define _0B_CMT_PRIORITY_LEVEL11                (0x0BU) /* Level 11 */
#define _0C_CMT_PRIORITY_LEVEL12                (0x0CU) /* Level 12 */
#define _0D_CMT_PRIORITY_LEVEL13                (0x0DU) /* Level 13 */
#define _0E_CMT_PRIORITY_LEVEL14                (0x0EU) /* Level 14 */
#define _0F_CMT_PRIORITY_LEVEL15                (0x0FU) /* Level 15 (highest) */

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
#define _1D4B_CMT0_CMCOR_VALUE                  (0x1D4BU) /* Compare match value */
#define _927B_CMT1_CMCOR_VALUE                  (0x927BU) /* Compare match value */
#define _5B8D_CMT2_CMCOR_VALUE                  (0x5B8DU) /* Compare match value */

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
void R_CMT0_Create(void);
void R_CMT0_Start(void);
void R_CMT0_Stop(void);
void R_CMT1_Create(void);
void R_CMT1_Start(void);
void R_CMT1_Stop(void);
void R_CMT2_Create(void);
void R_CMT2_Start(void);
void R_CMT2_Stop(void);

/* Start user code for function. Do not edit comment generated here */
void R_CMT_MsDelay(const uint16_t millisec);
/* End user code. Do not edit comment generated here */
#endif
