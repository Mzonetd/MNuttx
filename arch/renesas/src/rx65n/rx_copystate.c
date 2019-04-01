/****************************************************************************
 * arch/renesas/src/rx65n/up_copystate.c
 *
 *   
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

#include <stdint.h>
#include <string.h>

#include <arch/irq.h>

#include "up_internal.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/****************************************************************************
 * Private Data
 ****************************************************************************/

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: up_copystate
 ****************************************************************************/

/* A little faster than most memcpy's */

void up_copystate(uint32_t *dest, uint32_t *src)
{
  memcpy(dest, src, XCPTCONTEXT_SIZE);
}

