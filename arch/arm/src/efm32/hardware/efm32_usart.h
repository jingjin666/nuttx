/****************************************************************************
 * arch/arm/src/efm32/hardware/efm32_usart.h
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: 2014 Silicon Laboratories, Inc.
 * SPDX-FileCopyrightText: 2014 Pierre-noel Bouteville . All rights reserved.
 * SPDX-FileCopyrightText: 2014 Gregory Nutt. All rights reserved.
 * SPDX-FileContributor: Pierre-noel Bouteville <pnb990@gmail.com>
 * SPDX-FileContributor: Gregory Nutt <gnutt@nuttx.org>
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 *
 * DISCLAIMER OF WARRANTY/LIMITATION OF REMEDIES: Silicon Labs has no
 * obligation to support this Software. Silicon Labs is providing the
 * Software "AS IS", with no express or implied warranties of any kind,
 * including, but not limited to, any implied warranties of merchantability
 * or fitness for any particular purpose or warranties against infringement
 * of any proprietary rights of a third party.
 *
 * Silicon Labs will not be liable for any consequential, incidental, or
 * special damages, or any other relief, or for any claim by any third party,
 * arising from your use of this Software.
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
 ****************************************************************************/

#ifndef __ARCH_ARM_SRC_EFM32_HARDWARE_EFM32_USART_H
#define __ARCH_ARM_SRC_EFM32_HARDWARE_EFM32_USART_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>
#include "hardware/efm32_memorymap.h"

#if !defined(CONFIG_EFM32_EFM32GG) && !defined(CONFIG_EFM32_EFM32G)
#  warning This is the EFM32GG/G header file; Review/modification needed for this architecture
#endif

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* The UART is functionally equivalent to the USART with the following
 * exceptions.  The register map and register descriptions are equal to
 * those of the USART.
 *
 *   - Synchronous operation   Not available. SYNC, CSMA, CSINV, CPOL and
 *                             CPHA in USARTn_CTRL, and MASTEREN in
 *                             USARTn_STATUS are always 0.
 *   - Transmission direction  Always LSB first.
 *                             MSBF in USARTn_CTRL is always 0.
 *   - Chip-select             Not available.
 *                             AUTOCS in USARTn_CTRL is always 0.
 *   - SmartCard mode          Not available.
 *                             SCMODE in USARTn_CTRL is always 0.
 *   - Frame size              Limited to 8-9 databits.
 *                             Other configurations of DATABITS in
 *                             USARTn_FRAME are not possible.
 *   - IrDA Not available.     IREN in USARTn_IRCTRL is always 0.
 */

/* USART Register Offsets ***************************************************/

#define EFM32_USART_CTRL_OFFSET              0x0000 /* Control Register */
#define EFM32_USART_FRAME_OFFSET             0x0004 /* USART Frame Format Register */
#define EFM32_USART_TRIGCTRL_OFFSET          0x0008 /* USART Trigger Control register */
#define EFM32_USART_CMD_OFFSET               0x000c /* Command Register */
#define EFM32_USART_STATUS_OFFSET            0x0010 /* USART Status Register */
#define EFM32_USART_CLKDIV_OFFSET            0x0014 /* Clock Control Register */
#define EFM32_USART_RXDATAX_OFFSET           0x0018 /* RX Buffer Data Extended Register */
#define EFM32_USART_RXDATA_OFFSET            0x001c /* RX Buffer Data Register */
#define EFM32_USART_RXDOUBLEX_OFFSET         0x0020 /* RX Buffer Double Data Extended Register */
#define EFM32_USART_RXDOUBLE_OFFSET          0x0024 /* RX Double Data Register */
#define EFM32_USART_RXDATAXP_OFFSET          0x0028 /* RX Buffer Data Extended Peek Register */
#define EFM32_USART_RXDOUBLEXP_OFFSET        0x002c /* RX Buffer Double Data Extended Peek Register */
#define EFM32_USART_TXDATAX_OFFSET           0x0030 /* TX Buffer Data Extended Register */
#define EFM32_USART_TXDATA_OFFSET            0x0034 /* TX Buffer Data Register */
#define EFM32_USART_TXDOUBLEX_OFFSET         0x0038 /* TX Buffer Double Data Extended Register */
#define EFM32_USART_TXDOUBLE_OFFSET          0x003c /* TX Buffer Double Data Register */
#define EFM32_USART_IF_OFFSET                0x0040 /* Interrupt Flag Register */
#define EFM32_USART_IFS_OFFSET               0x0044 /* Interrupt Flag Set Register */
#define EFM32_USART_IFC_OFFSET               0x0048 /* Interrupt Flag Clear Register */
#define EFM32_USART_IEN_OFFSET               0x004c /* Interrupt Enable Register */
#define EFM32_USART_IRCTRL_OFFSET            0x0050 /* IrDA Control Register */
#define EFM32_USART_ROUTE_OFFSET             0x0054 /* I/O Routing Register */
#ifdef CONFIG_EFM32_EFM32GG
#  define EFM32_USART_INPUT_OFFSET           0x0058 /* USART Input Register */
#  define EFM32_USART_I2SCTRL_OFFSET         0x005c /* I2S Control Register */
#endif

/* USART Register Addresses *************************************************/

#define EFM32_USART0_CTRL                    (EFM32_USART0_BASE+EFM32_USART_CTRL_OFFSET)
#define EFM32_USART0_FRAME                   (EFM32_USART0_BASE+EFM32_USART_FRAME_OFFSET)
#define EFM32_USART0_TRIGCTRL                (EFM32_USART0_BASE+EFM32_USART_TRIGCTRL_OFFSET)
#define EFM32_USART0_CMD                     (EFM32_USART0_BASE+EFM32_USART_CMD_OFFSET)
#define EFM32_USART0_STATUS                  (EFM32_USART0_BASE+EFM32_USART_STATUS_OFFSET)
#define EFM32_USART0_CLKDIV                  (EFM32_USART0_BASE+EFM32_USART_CLKDIV_OFFSET)
#define EFM32_USART0_RXDATAX                 (EFM32_USART0_BASE+EFM32_USART_RXDATAX_OFFSET)
#define EFM32_USART0_RXDATA                  (EFM32_USART0_BASE+EFM32_USART_RXDATA_OFFSET)
#define EFM32_USART0_RXDOUBLEX               (EFM32_USART0_BASE+EFM32_USART_RXDOUBLEX_OFFSET)
#define EFM32_USART0_RXDOUBLE                (EFM32_USART0_BASE+EFM32_USART_RXDOUBLE_OFFSET)
#define EFM32_USART0_RXDATAXP                (EFM32_USART0_BASE+EFM32_USART_RXDATAXP_OFFSET)
#define EFM32_USART0_RXDOUBLEXP              (EFM32_USART0_BASE+EFM32_USART_RXDOUBLEXP_OFFSET)
#define EFM32_USART0_TXDATAX                 (EFM32_USART0_BASE+EFM32_USART_TXDATAX_OFFSET)
#define EFM32_USART0_TXDATA                  (EFM32_USART0_BASE+EFM32_USART_TXDATA_OFFSET)
#define EFM32_USART0_TXDOUBLEX               (EFM32_USART0_BASE+EFM32_USART_TXDOUBLEX_OFFSET)
#define EFM32_USART0_TXDOUBLE                (EFM32_USART0_BASE+EFM32_USART_TXDOUBLE_OFFSET)
#define EFM32_USART0_IF                      (EFM32_USART0_BASE+EFM32_USART_IF_OFFSET)
#define EFM32_USART0_IFS                     (EFM32_USART0_BASE+EFM32_USART_IFS_OFFSET)
#define EFM32_USART0_IFC                     (EFM32_USART0_BASE+EFM32_USART_IFC_OFFSET)
#define EFM32_USART0_IEN                     (EFM32_USART0_BASE+EFM32_USART_IEN_OFFSET)
#define EFM32_USART0_IRCTRL                  (EFM32_USART0_BASE+EFM32_USART_IRCTRL_OFFSET)
#define EFM32_USART0_ROUTE                   (EFM32_USART0_BASE+EFM32_USART_ROUTE_OFFSET)
#ifdef CONFIG_EFM32_EFM32GG
#  define EFM32_USART0_INPUT                 (EFM32_USART0_BASE+EFM32_USART_INPUT_OFFSET)
#  define EFM32_USART0_I2SCTRL               (EFM32_USART0_BASE+EFM32_USART_I2SCTRL_OFFSET)
#endif

#define EFM32_USART1_CTRL                    (EFM32_USART1_BASE+EFM32_USART_CTRL_OFFSET)
#define EFM32_USART1_FRAME                   (EFM32_USART1_BASE+EFM32_USART_FRAME_OFFSET)
#define EFM32_USART1_TRIGCTRL                (EFM32_USART1_BASE+EFM32_USART_TRIGCTRL_OFFSET)
#define EFM32_USART1_CMD                     (EFM32_USART1_BASE+EFM32_USART_CMD_OFFSET)
#define EFM32_USART1_STATUS                  (EFM32_USART1_BASE+EFM32_USART_STATUS_OFFSET)
#define EFM32_USART1_CLKDIV                  (EFM32_USART1_BASE+EFM32_USART_CLKDIV_OFFSET)
#define EFM32_USART1_RXDATAX                 (EFM32_USART1_BASE+EFM32_USART_RXDATAX_OFFSET)
#define EFM32_USART1_RXDATA                  (EFM32_USART1_BASE+EFM32_USART_RXDATA_OFFSET)
#define EFM32_USART1_RXDOUBLEX               (EFM32_USART1_BASE+EFM32_USART_RXDOUBLEX_OFFSET)
#define EFM32_USART1_RXDOUBLE                (EFM32_USART1_BASE+EFM32_USART_RXDOUBLE_OFFSET)
#define EFM32_USART1_RXDATAXP                (EFM32_USART1_BASE+EFM32_USART_RXDATAXP_OFFSET)
#define EFM32_USART1_RXDOUBLEXP              (EFM32_USART1_BASE+EFM32_USART_RXDOUBLEXP_OFFSET)
#define EFM32_USART1_TXDATAX                 (EFM32_USART1_BASE+EFM32_USART_TXDATAX_OFFSET)
#define EFM32_USART1_TXDATA                  (EFM32_USART1_BASE+EFM32_USART_TXDATA_OFFSET)
#define EFM32_USART1_TXDOUBLEX               (EFM32_USART1_BASE+EFM32_USART_TXDOUBLEX_OFFSET)
#define EFM32_USART1_TXDOUBLE                (EFM32_USART1_BASE+EFM32_USART_TXDOUBLE_OFFSET)
#define EFM32_USART1_IF                      (EFM32_USART1_BASE+EFM32_USART_IF_OFFSET)
#define EFM32_USART1_IFS                     (EFM32_USART1_BASE+EFM32_USART_IFS_OFFSET)
#define EFM32_USART1_IFC                     (EFM32_USART1_BASE+EFM32_USART_IFC_OFFSET)
#define EFM32_USART1_IEN                     (EFM32_USART1_BASE+EFM32_USART_IEN_OFFSET)
#define EFM32_USART1_IRCTRL                  (EFM32_USART1_BASE+EFM32_USART_IRCTRL_OFFSET)
#define EFM32_USART1_ROUTE                   (EFM32_USART1_BASE+EFM32_USART_ROUTE_OFFSET)
#ifdef CONFIG_EFM32_EFM32GG
#  define EFM32_USART1_INPUT                 (EFM32_USART1_BASE+EFM32_USART_INPUT_OFFSET)
#  define EFM32_USART1_I2SCTRL               (EFM32_USART1_BASE+EFM32_USART_I2SCTRL_OFFSET)
#endif

#define EFM32_USART2_CTRL                    (EFM32_USART2_BASE+EFM32_USART_CTRL_OFFSET)
#define EFM32_USART2_FRAME                   (EFM32_USART2_BASE+EFM32_USART_FRAME_OFFSET)
#define EFM32_USART2_TRIGCTRL                (EFM32_USART2_BASE+EFM32_USART_TRIGCTRL_OFFSET)
#define EFM32_USART2_CMD                     (EFM32_USART2_BASE+EFM32_USART_CMD_OFFSET)
#define EFM32_USART2_STATUS                  (EFM32_USART2_BASE+EFM32_USART_STATUS_OFFSET)
#define EFM32_USART2_CLKDIV                  (EFM32_USART2_BASE+EFM32_USART_CLKDIV_OFFSET)
#define EFM32_USART2_RXDATAX                 (EFM32_USART2_BASE+EFM32_USART_RXDATAX_OFFSET)
#define EFM32_USART2_RXDATA                  (EFM32_USART2_BASE+EFM32_USART_RXDATA_OFFSET)
#define EFM32_USART2_RXDOUBLEX               (EFM32_USART2_BASE+EFM32_USART_RXDOUBLEX_OFFSET)
#define EFM32_USART2_RXDOUBLE                (EFM32_USART2_BASE+EFM32_USART_RXDOUBLE_OFFSET)
#define EFM32_USART2_RXDATAXP                (EFM32_USART2_BASE+EFM32_USART_RXDATAXP_OFFSET)
#define EFM32_USART2_RXDOUBLEXP              (EFM32_USART2_BASE+EFM32_USART_RXDOUBLEXP_OFFSET)
#define EFM32_USART2_TXDATAX                 (EFM32_USART2_BASE+EFM32_USART_TXDATAX_OFFSET)
#define EFM32_USART2_TXDATA                  (EFM32_USART2_BASE+EFM32_USART_TXDATA_OFFSET)
#define EFM32_USART2_TXDOUBLEX               (EFM32_USART2_BASE+EFM32_USART_TXDOUBLEX_OFFSET)
#define EFM32_USART2_TXDOUBLE                (EFM32_USART2_BASE+EFM32_USART_TXDOUBLE_OFFSET)
#define EFM32_USART2_IF                      (EFM32_USART2_BASE+EFM32_USART_IF_OFFSET)
#define EFM32_USART2_IFS                     (EFM32_USART2_BASE+EFM32_USART_IFS_OFFSET)
#define EFM32_USART2_IFC                     (EFM32_USART2_BASE+EFM32_USART_IFC_OFFSET)
#define EFM32_USART2_IEN                     (EFM32_USART2_BASE+EFM32_USART_IEN_OFFSET)
#define EFM32_USART2_IRCTRL                  (EFM32_USART2_BASE+EFM32_USART_IRCTRL_OFFSET)
#define EFM32_USART2_ROUTE                   (EFM32_USART2_BASE+EFM32_USART_ROUTE_OFFSET)
#ifdef CONFIG_EFM32_EFM32GG
#  define EFM32_USART2_INPUT                 (EFM32_USART2_BASE+EFM32_USART_INPUT_OFFSET)
#  define EFM32_USART2_I2SCTRL               (EFM32_USART2_BASE+EFM32_USART_I2SCTRL_OFFSET)
#endif

#define EFM32_UART0_CTRL                     (EFM32_UART0_BASE+EFM32_USART_CTRL_OFFSET)
#define EFM32_UART0_FRAME                    (EFM32_UART0_BASE+EFM32_USART_FRAME_OFFSET)
#define EFM32_UART0_TRIGCTRL                 (EFM32_UART0_BASE+EFM32_USART_TRIGCTRL_OFFSET)
#define EFM32_UART0_CMD                      (EFM32_UART0_BASE+EFM32_USART_CMD_OFFSET)
#define EFM32_UART0_STATUS                   (EFM32_UART0_BASE+EFM32_USART_STATUS_OFFSET)
#define EFM32_UART0_CLKDIV                   (EFM32_UART0_BASE+EFM32_USART_CLKDIV_OFFSET)
#define EFM32_UART0_RXDATAX                  (EFM32_UART0_BASE+EFM32_USART_RXDATAX_OFFSET)
#define EFM32_UART0_RXDATA                   (EFM32_UART0_BASE+EFM32_USART_RXDATA_OFFSET)
#define EFM32_UART0_RXDOUBLEX                (EFM32_UART0_BASE+EFM32_USART_RXDOUBLEX_OFFSET)
#define EFM32_UART0_RXDOUBLE                 (EFM32_UART0_BASE+EFM32_USART_RXDOUBLE_OFFSET)
#define EFM32_UART0_RXDATAXP                 (EFM32_UART0_BASE+EFM32_USART_RXDATAXP_OFFSET)
#define EFM32_UART0_RXDOUBLEXP               (EFM32_UART0_BASE+EFM32_USART_RXDOUBLEXP_OFFSET)
#define EFM32_UART0_TXDATAX                  (EFM32_UART0_BASE+EFM32_USART_TXDATAX_OFFSET)
#define EFM32_UART0_TXDATA                   (EFM32_UART0_BASE+EFM32_USART_TXDATA_OFFSET)
#define EFM32_UART0_TXDOUBLEX                (EFM32_UART0_BASE+EFM32_USART_TXDOUBLEX_OFFSET)
#define EFM32_UART0_TXDOUBLE                 (EFM32_UART0_BASE+EFM32_USART_TXDOUBLE_OFFSET)
#define EFM32_UART0_IF                       (EFM32_UART0_BASE+EFM32_USART_IF_OFFSET)
#define EFM32_UART0_IFS                      (EFM32_UART0_BASE+EFM32_USART_IFS_OFFSET)
#define EFM32_UART0_IFC                      (EFM32_UART0_BASE+EFM32_USART_IFC_OFFSET)
#define EFM32_UART0_IEN                      (EFM32_UART0_BASE+EFM32_USART_IEN_OFFSET)
#define EFM32_UART0_IRCTRL                   (EFM32_UART0_BASE+EFM32_USART_IRCTRL_OFFSET)
#define EFM32_UART0_ROUTE                    (EFM32_UART0_BASE+EFM32_USART_ROUTE_OFFSET)
#ifdef CONFIG_EFM32_EFM32GG
#  define EFM32_UART0_INPUT                  (EFM32_UART0_BASE+EFM32_USART_INPUT_OFFSET)
#  define EFM32_UART0_I2SCTRL                (EFM32_UART0_BASE+EFM32_USART_I2SCTRL_OFFSET)
#endif

#define EFM32_UART1_CTRL                     (EFM32_UART1_BASE+EFM32_USART_CTRL_OFFSET)
#define EFM32_UART1_FRAME                    (EFM32_UART1_BASE+EFM32_USART_FRAME_OFFSET)
#define EFM32_UART1_TRIGCTRL                 (EFM32_UART1_BASE+EFM32_USART_TRIGCTRL_OFFSET)
#define EFM32_UART1_CMD                      (EFM32_UART1_BASE+EFM32_USART_CMD_OFFSET)
#define EFM32_UART1_STATUS                   (EFM32_UART1_BASE+EFM32_USART_STATUS_OFFSET)
#define EFM32_UART1_CLKDIV                   (EFM32_UART1_BASE+EFM32_USART_CLKDIV_OFFSET)
#define EFM32_UART1_RXDATAX                  (EFM32_UART1_BASE+EFM32_USART_RXDATAX_OFFSET)
#define EFM32_UART1_RXDATA                   (EFM32_UART1_BASE+EFM32_USART_RXDATA_OFFSET)
#define EFM32_UART1_RXDOUBLEX                (EFM32_UART1_BASE+EFM32_USART_RXDOUBLEX_OFFSET)
#define EFM32_UART1_RXDOUBLE                 (EFM32_UART1_BASE+EFM32_USART_RXDOUBLE_OFFSET)
#define EFM32_UART1_RXDATAXP                 (EFM32_UART1_BASE+EFM32_USART_RXDATAXP_OFFSET)
#define EFM32_UART1_RXDOUBLEXP               (EFM32_UART1_BASE+EFM32_USART_RXDOUBLEXP_OFFSET)
#define EFM32_UART1_TXDATAX                  (EFM32_UART1_BASE+EFM32_USART_TXDATAX_OFFSET)
#define EFM32_UART1_TXDATA                   (EFM32_UART1_BASE+EFM32_USART_TXDATA_OFFSET)
#define EFM32_UART1_TXDOUBLEX                (EFM32_UART1_BASE+EFM32_USART_TXDOUBLEX_OFFSET)
#define EFM32_UART1_TXDOUBLE                 (EFM32_UART1_BASE+EFM32_USART_TXDOUBLE_OFFSET)
#define EFM32_UART1_IF                       (EFM32_UART1_BASE+EFM32_USART_IF_OFFSET)
#define EFM32_UART1_IFS                      (EFM32_UART1_BASE+EFM32_USART_IFS_OFFSET)
#define EFM32_UART1_IFC                      (EFM32_UART1_BASE+EFM32_USART_IFC_OFFSET)
#define EFM32_UART1_IEN                      (EFM32_UART1_BASE+EFM32_USART_IEN_OFFSET)
#define EFM32_UART1_IRCTRL                   (EFM32_UART1_BASE+EFM32_USART_IRCTRL_OFFSET)
#define EFM32_UART1_ROUTE                    (EFM32_UART1_BASE+EFM32_USART_ROUTE_OFFSET)
#ifdef CONFIG_EFM32_EFM32GG
#  define EFM32_UART1_INPUT                  (EFM32_UART1_BASE+EFM32_USART_INPUT_OFFSET)
#  define EFM32_UART1_I2SCTRL                (EFM32_UART1_BASE+EFM32_USART_I2SCTRL_OFFSET)
#endif

/* USART Register Register Bit Definitions **********************************/

/* Bit fields for USART CTRL */

#define _USART_CTRL_RESETVALUE                0x00000000UL                             /* Default value for USART_CTRL */
#define _USART_CTRL_MASK                      0x7DFFFF7FUL                             /* Mask for USART_CTRL */

#define USART_CTRL_SYNC                       (0x1UL << 0)                             /* USART Synchronous Mode */
#define _USART_CTRL_SYNC_SHIFT                0                                        /* Shift value for USART_SYNC */
#define _USART_CTRL_SYNC_MASK                 0x1UL                                    /* Bit mask for USART_SYNC */
#define _USART_CTRL_SYNC_DEFAULT              0x00000000UL                             /* Mode DEFAULT for USART_CTRL */
#define USART_CTRL_SYNC_DEFAULT               (_USART_CTRL_SYNC_DEFAULT << 0)          /* Shifted mode DEFAULT for USART_CTRL */
#define USART_CTRL_LOOPBK                     (0x1UL << 1)                             /* Loopback Enable */
#define _USART_CTRL_LOOPBK_SHIFT              1                                        /* Shift value for USART_LOOPBK */
#define _USART_CTRL_LOOPBK_MASK               0x2UL                                    /* Bit mask for USART_LOOPBK */
#define _USART_CTRL_LOOPBK_DEFAULT            0x00000000UL                             /* Mode DEFAULT for USART_CTRL */
#define USART_CTRL_LOOPBK_DEFAULT             (_USART_CTRL_LOOPBK_DEFAULT << 1)        /* Shifted mode DEFAULT for USART_CTRL */
#define USART_CTRL_CCEN                       (0x1UL << 2)                             /* Collision Check Enable */
#define _USART_CTRL_CCEN_SHIFT                2                                        /* Shift value for USART_CCEN */
#define _USART_CTRL_CCEN_MASK                 0x4UL                                    /* Bit mask for USART_CCEN */
#define _USART_CTRL_CCEN_DEFAULT              0x00000000UL                             /* Mode DEFAULT for USART_CTRL */
#define USART_CTRL_CCEN_DEFAULT               (_USART_CTRL_CCEN_DEFAULT << 2)          /* Shifted mode DEFAULT for USART_CTRL */
#define USART_CTRL_MPM                        (0x1UL << 3)                             /* Multi-Processor Mode */
#define _USART_CTRL_MPM_SHIFT                 3                                        /* Shift value for USART_MPM */
#define _USART_CTRL_MPM_MASK                  0x8UL                                    /* Bit mask for USART_MPM */
#define _USART_CTRL_MPM_DEFAULT               0x00000000UL                             /* Mode DEFAULT for USART_CTRL */
#define USART_CTRL_MPM_DEFAULT                (_USART_CTRL_MPM_DEFAULT << 3)           /* Shifted mode DEFAULT for USART_CTRL */
#define USART_CTRL_MPAB                       (0x1UL << 4)                             /* Multi-Processor Address-Bit */
#define _USART_CTRL_MPAB_SHIFT                4                                        /* Shift value for USART_MPAB */
#define _USART_CTRL_MPAB_MASK                 0x10UL                                   /* Bit mask for USART_MPAB */
#define _USART_CTRL_MPAB_DEFAULT              0x00000000UL                             /* Mode DEFAULT for USART_CTRL */
#define USART_CTRL_MPAB_DEFAULT               (_USART_CTRL_MPAB_DEFAULT << 4)          /* Shifted mode DEFAULT for USART_CTRL */
#define _USART_CTRL_OVS_SHIFT                 5                                        /* Shift value for USART_OVS */
#define _USART_CTRL_OVS_MASK                  0x60UL                                   /* Bit mask for USART_OVS */
#define _USART_CTRL_OVS_DEFAULT               0x00000000UL                             /* Mode DEFAULT for USART_CTRL */
#define _USART_CTRL_OVS_X16                   0x00000000UL                             /* Mode X16 for USART_CTRL */
#define _USART_CTRL_OVS_X8                    0x00000001UL                             /* Mode X8 for USART_CTRL */
#define _USART_CTRL_OVS_X6                    0x00000002UL                             /* Mode X6 for USART_CTRL */
#define _USART_CTRL_OVS_X4                    0x00000003UL                             /* Mode X4 for USART_CTRL */
#define USART_CTRL_OVS_DEFAULT                (_USART_CTRL_OVS_DEFAULT << 5)           /* Shifted mode DEFAULT for USART_CTRL */
#define USART_CTRL_OVS_X16                    (_USART_CTRL_OVS_X16 << 5)               /* Shifted mode X16 for USART_CTRL */
#define USART_CTRL_OVS_X8                     (_USART_CTRL_OVS_X8 << 5)                /* Shifted mode X8 for USART_CTRL */
#define USART_CTRL_OVS_X6                     (_USART_CTRL_OVS_X6 << 5)                /* Shifted mode X6 for USART_CTRL */
#define USART_CTRL_OVS_X4                     (_USART_CTRL_OVS_X4 << 5)                /* Shifted mode X4 for USART_CTRL */
#define USART_CTRL_CLKPOL                     (0x1UL << 8)                             /* Clock Polarity */
#define _USART_CTRL_CLKPOL_SHIFT              8                                        /* Shift value for USART_CLKPOL */
#define _USART_CTRL_CLKPOL_MASK               0x100UL                                  /* Bit mask for USART_CLKPOL */
#define _USART_CTRL_CLKPOL_DEFAULT            0x00000000UL                             /* Mode DEFAULT for USART_CTRL */
#define _USART_CTRL_CLKPOL_IDLELOW            0x00000000UL                             /* Mode IDLELOW for USART_CTRL */
#define _USART_CTRL_CLKPOL_IDLEHIGH           0x00000001UL                             /* Mode IDLEHIGH for USART_CTRL */
#define USART_CTRL_CLKPOL_DEFAULT             (_USART_CTRL_CLKPOL_DEFAULT << 8)        /* Shifted mode DEFAULT for USART_CTRL */
#define USART_CTRL_CLKPOL_IDLELOW             (_USART_CTRL_CLKPOL_IDLELOW << 8)        /* Shifted mode IDLELOW for USART_CTRL */
#define USART_CTRL_CLKPOL_IDLEHIGH            (_USART_CTRL_CLKPOL_IDLEHIGH << 8)       /* Shifted mode IDLEHIGH for USART_CTRL */
#define USART_CTRL_CLKPHA                     (0x1UL << 9)                             /* Clock Edge For Setup/Sample */
#define _USART_CTRL_CLKPHA_SHIFT              9                                        /* Shift value for USART_CLKPHA */
#define _USART_CTRL_CLKPHA_MASK               0x200UL                                  /* Bit mask for USART_CLKPHA */
#define _USART_CTRL_CLKPHA_DEFAULT            0x00000000UL                             /* Mode DEFAULT for USART_CTRL */
#define _USART_CTRL_CLKPHA_SAMPLELEADING      0x00000000UL                             /* Mode SAMPLELEADING for USART_CTRL */
#define _USART_CTRL_CLKPHA_SAMPLETRAILING     0x00000001UL                             /* Mode SAMPLETRAILING for USART_CTRL */
#define USART_CTRL_CLKPHA_DEFAULT             (_USART_CTRL_CLKPHA_DEFAULT << 9)        /* Shifted mode DEFAULT for USART_CTRL */
#define USART_CTRL_CLKPHA_SAMPLELEADING       (_USART_CTRL_CLKPHA_SAMPLELEADING << 9)  /* Shifted mode SAMPLELEADING for USART_CTRL */
#define USART_CTRL_CLKPHA_SAMPLETRAILING      (_USART_CTRL_CLKPHA_SAMPLETRAILING << 9) /* Shifted mode SAMPLETRAILING for USART_CTRL */
#define USART_CTRL_MSBF                       (0x1UL << 10)                            /* Most Significant Bit First */
#define _USART_CTRL_MSBF_SHIFT                10                                       /* Shift value for USART_MSBF */
#define _USART_CTRL_MSBF_MASK                 0x400UL                                  /* Bit mask for USART_MSBF */
#define _USART_CTRL_MSBF_DEFAULT              0x00000000UL                             /* Mode DEFAULT for USART_CTRL */
#define USART_CTRL_MSBF_DEFAULT               (_USART_CTRL_MSBF_DEFAULT << 10)         /* Shifted mode DEFAULT for USART_CTRL */
#define USART_CTRL_CSMA                       (0x1UL << 11)                            /* Action On Slave-Select In Master Mode */
#define _USART_CTRL_CSMA_SHIFT                11                                       /* Shift value for USART_CSMA */
#define _USART_CTRL_CSMA_MASK                 0x800UL                                  /* Bit mask for USART_CSMA */
#define _USART_CTRL_CSMA_DEFAULT              0x00000000UL                             /* Mode DEFAULT for USART_CTRL */
#define _USART_CTRL_CSMA_NOACTION             0x00000000UL                             /* Mode NOACTION for USART_CTRL */
#define _USART_CTRL_CSMA_GOTOSLAVEMODE        0x00000001UL                             /* Mode GOTOSLAVEMODE for USART_CTRL */
#define USART_CTRL_CSMA_DEFAULT               (_USART_CTRL_CSMA_DEFAULT << 11)         /* Shifted mode DEFAULT for USART_CTRL */
#define USART_CTRL_CSMA_NOACTION              (_USART_CTRL_CSMA_NOACTION << 11)        /* Shifted mode NOACTION for USART_CTRL */
#define USART_CTRL_CSMA_GOTOSLAVEMODE         (_USART_CTRL_CSMA_GOTOSLAVEMODE << 11)   /* Shifted mode GOTOSLAVEMODE for USART_CTRL */
#define USART_CTRL_TXBIL                      (0x1UL << 12)                            /* TX Buffer Interrupt Level */
#define _USART_CTRL_TXBIL_SHIFT               12                                       /* Shift value for USART_TXBIL */
#define _USART_CTRL_TXBIL_MASK                0x1000UL                                 /* Bit mask for USART_TXBIL */
#define _USART_CTRL_TXBIL_DEFAULT             0x00000000UL                             /* Mode DEFAULT for USART_CTRL */
#define _USART_CTRL_TXBIL_EMPTY               0x00000000UL                             /* Mode EMPTY for USART_CTRL */
#define _USART_CTRL_TXBIL_HALFFULL            0x00000001UL                             /* Mode HALFFULL for USART_CTRL */
#define USART_CTRL_TXBIL_DEFAULT              (_USART_CTRL_TXBIL_DEFAULT << 12)        /* Shifted mode DEFAULT for USART_CTRL */
#define USART_CTRL_TXBIL_EMPTY                (_USART_CTRL_TXBIL_EMPTY << 12)          /* Shifted mode EMPTY for USART_CTRL */
#define USART_CTRL_TXBIL_HALFFULL             (_USART_CTRL_TXBIL_HALFFULL << 12)       /* Shifted mode HALFFULL for USART_CTRL */
#define USART_CTRL_RXINV                      (0x1UL << 13)                            /* Receiver Input Invert */
#define _USART_CTRL_RXINV_SHIFT               13                                       /* Shift value for USART_RXINV */
#define _USART_CTRL_RXINV_MASK                0x2000UL                                 /* Bit mask for USART_RXINV */
#define _USART_CTRL_RXINV_DEFAULT             0x00000000UL                             /* Mode DEFAULT for USART_CTRL */
#define USART_CTRL_RXINV_DEFAULT              (_USART_CTRL_RXINV_DEFAULT << 13)        /* Shifted mode DEFAULT for USART_CTRL */
#define USART_CTRL_TXINV                      (0x1UL << 14)                            /* Transmitter output Invert */
#define _USART_CTRL_TXINV_SHIFT               14                                       /* Shift value for USART_TXINV */
#define _USART_CTRL_TXINV_MASK                0x4000UL                                 /* Bit mask for USART_TXINV */
#define _USART_CTRL_TXINV_DEFAULT             0x00000000UL                             /* Mode DEFAULT for USART_CTRL */
#define USART_CTRL_TXINV_DEFAULT              (_USART_CTRL_TXINV_DEFAULT << 14)        /* Shifted mode DEFAULT for USART_CTRL */
#define USART_CTRL_CSINV                      (0x1UL << 15)                            /* Chip Select Invert */
#define _USART_CTRL_CSINV_SHIFT               15                                       /* Shift value for USART_CSINV */
#define _USART_CTRL_CSINV_MASK                0x8000UL                                 /* Bit mask for USART_CSINV */
#define _USART_CTRL_CSINV_DEFAULT             0x00000000UL                             /* Mode DEFAULT for USART_CTRL */
#define USART_CTRL_CSINV_DEFAULT              (_USART_CTRL_CSINV_DEFAULT << 15)        /* Shifted mode DEFAULT for USART_CTRL */
#define USART_CTRL_AUTOCS                     (0x1UL << 16)                            /* Automatic Chip Select */
#define _USART_CTRL_AUTOCS_SHIFT              16                                       /* Shift value for USART_AUTOCS */
#define _USART_CTRL_AUTOCS_MASK               0x10000UL                                /* Bit mask for USART_AUTOCS */
#define _USART_CTRL_AUTOCS_DEFAULT            0x00000000UL                             /* Mode DEFAULT for USART_CTRL */
#define USART_CTRL_AUTOCS_DEFAULT             (_USART_CTRL_AUTOCS_DEFAULT << 16)       /* Shifted mode DEFAULT for USART_CTRL */
#define USART_CTRL_AUTOTRI                    (0x1UL << 17)                            /* Automatic TX Tristate */
#define _USART_CTRL_AUTOTRI_SHIFT             17                                       /* Shift value for USART_AUTOTRI */
#define _USART_CTRL_AUTOTRI_MASK              0x20000UL                                /* Bit mask for USART_AUTOTRI */
#define _USART_CTRL_AUTOTRI_DEFAULT           0x00000000UL                             /* Mode DEFAULT for USART_CTRL */
#define USART_CTRL_AUTOTRI_DEFAULT            (_USART_CTRL_AUTOTRI_DEFAULT << 17)      /* Shifted mode DEFAULT for USART_CTRL */
#define USART_CTRL_SCMODE                     (0x1UL << 18)                            /* SmartCard Mode */
#define _USART_CTRL_SCMODE_SHIFT              18                                       /* Shift value for USART_SCMODE */
#define _USART_CTRL_SCMODE_MASK               0x40000UL                                /* Bit mask for USART_SCMODE */
#define _USART_CTRL_SCMODE_DEFAULT            0x00000000UL                             /* Mode DEFAULT for USART_CTRL */
#define USART_CTRL_SCMODE_DEFAULT             (_USART_CTRL_SCMODE_DEFAULT << 18)       /* Shifted mode DEFAULT for USART_CTRL */
#define USART_CTRL_SCRETRANS                  (0x1UL << 19)                            /* SmartCard Retransmit */
#define _USART_CTRL_SCRETRANS_SHIFT           19                                       /* Shift value for USART_SCRETRANS */
#define _USART_CTRL_SCRETRANS_MASK            0x80000UL                                /* Bit mask for USART_SCRETRANS */
#define _USART_CTRL_SCRETRANS_DEFAULT         0x00000000UL                             /* Mode DEFAULT for USART_CTRL */
#define USART_CTRL_SCRETRANS_DEFAULT          (_USART_CTRL_SCRETRANS_DEFAULT << 19)    /* Shifted mode DEFAULT for USART_CTRL */
#define USART_CTRL_SKIPPERRF                  (0x1UL << 20)                            /* Skip Parity Error Frames */
#define _USART_CTRL_SKIPPERRF_SHIFT           20                                       /* Shift value for USART_SKIPPERRF */
#define _USART_CTRL_SKIPPERRF_MASK            0x100000UL                               /* Bit mask for USART_SKIPPERRF */
#define _USART_CTRL_SKIPPERRF_DEFAULT         0x00000000UL                             /* Mode DEFAULT for USART_CTRL */
#define USART_CTRL_SKIPPERRF_DEFAULT          (_USART_CTRL_SKIPPERRF_DEFAULT << 20)    /* Shifted mode DEFAULT for USART_CTRL */
#define USART_CTRL_BIT8DV                     (0x1UL << 21)                            /* Bit 8 Default Value */
#define _USART_CTRL_BIT8DV_SHIFT              21                                       /* Shift value for USART_BIT8DV */
#define _USART_CTRL_BIT8DV_MASK               0x200000UL                               /* Bit mask for USART_BIT8DV */
#define _USART_CTRL_BIT8DV_DEFAULT            0x00000000UL                             /* Mode DEFAULT for USART_CTRL */
#define USART_CTRL_BIT8DV_DEFAULT             (_USART_CTRL_BIT8DV_DEFAULT << 21)       /* Shifted mode DEFAULT for USART_CTRL */
#define USART_CTRL_ERRSDMA                    (0x1UL << 22)                            /* Halt DMA On Error */
#define _USART_CTRL_ERRSDMA_SHIFT             22                                       /* Shift value for USART_ERRSDMA */
#define _USART_CTRL_ERRSDMA_MASK              0x400000UL                               /* Bit mask for USART_ERRSDMA */
#define _USART_CTRL_ERRSDMA_DEFAULT           0x00000000UL                             /* Mode DEFAULT for USART_CTRL */
#define USART_CTRL_ERRSDMA_DEFAULT            (_USART_CTRL_ERRSDMA_DEFAULT << 22)      /* Shifted mode DEFAULT for USART_CTRL */
#define USART_CTRL_ERRSRX                     (0x1UL << 23)                            /* Disable RX On Error */
#define _USART_CTRL_ERRSRX_SHIFT              23                                       /* Shift value for USART_ERRSRX */
#define _USART_CTRL_ERRSRX_MASK               0x800000UL                               /* Bit mask for USART_ERRSRX */
#define _USART_CTRL_ERRSRX_DEFAULT            0x00000000UL                             /* Mode DEFAULT for USART_CTRL */
#define USART_CTRL_ERRSRX_DEFAULT             (_USART_CTRL_ERRSRX_DEFAULT << 23)       /* Shifted mode DEFAULT for USART_CTRL */
#define USART_CTRL_ERRSTX                     (0x1UL << 24)                            /* Disable TX On Error */
#define _USART_CTRL_ERRSTX_SHIFT              24                                       /* Shift value for USART_ERRSTX */
#define _USART_CTRL_ERRSTX_MASK               0x1000000UL                              /* Bit mask for USART_ERRSTX */
#define _USART_CTRL_ERRSTX_DEFAULT            0x00000000UL                             /* Mode DEFAULT for USART_CTRL */
#define USART_CTRL_ERRSTX_DEFAULT             (_USART_CTRL_ERRSTX_DEFAULT << 24)       /* Shifted mode DEFAULT for USART_CTRL */
#define _USART_CTRL_TXDELAY_SHIFT             26                                       /* Shift value for USART_TXDELAY */
#define _USART_CTRL_TXDELAY_MASK              0xC000000UL                              /* Bit mask for USART_TXDELAY */
#define _USART_CTRL_TXDELAY_DEFAULT           0x00000000UL                             /* Mode DEFAULT for USART_CTRL */
#define _USART_CTRL_TXDELAY_NONE              0x00000000UL                             /* Mode NONE for USART_CTRL */
#define _USART_CTRL_TXDELAY_SINGLE            0x00000001UL                             /* Mode SINGLE for USART_CTRL */
#define _USART_CTRL_TXDELAY_DOUBLE            0x00000002UL                             /* Mode DOUBLE for USART_CTRL */
#define _USART_CTRL_TXDELAY_TRIPLE            0x00000003UL                             /* Mode TRIPLE for USART_CTRL */
#define USART_CTRL_TXDELAY_DEFAULT            (_USART_CTRL_TXDELAY_DEFAULT << 26)      /* Shifted mode DEFAULT for USART_CTRL */
#define USART_CTRL_TXDELAY_NONE               (_USART_CTRL_TXDELAY_NONE << 26)         /* Shifted mode NONE for USART_CTRL */
#define USART_CTRL_TXDELAY_SINGLE             (_USART_CTRL_TXDELAY_SINGLE << 26)       /* Shifted mode SINGLE for USART_CTRL */
#define USART_CTRL_TXDELAY_DOUBLE             (_USART_CTRL_TXDELAY_DOUBLE << 26)       /* Shifted mode DOUBLE for USART_CTRL */
#define USART_CTRL_TXDELAY_TRIPLE             (_USART_CTRL_TXDELAY_TRIPLE << 26)       /* Shifted mode TRIPLE for USART_CTRL */
#define USART_CTRL_BYTESWAP                   (0x1UL << 28)                            /* Byteswap In Double Accesses */
#define _USART_CTRL_BYTESWAP_SHIFT            28                                       /* Shift value for USART_BYTESWAP */
#define _USART_CTRL_BYTESWAP_MASK             0x10000000UL                             /* Bit mask for USART_BYTESWAP */
#define _USART_CTRL_BYTESWAP_DEFAULT          0x00000000UL                             /* Mode DEFAULT for USART_CTRL */
#define USART_CTRL_BYTESWAP_DEFAULT           (_USART_CTRL_BYTESWAP_DEFAULT << 28)     /* Shifted mode DEFAULT for USART_CTRL */
#define USART_CTRL_AUTOTX                     (0x1UL << 29)                            /* Always Transmit When RX Not Full */
#define _USART_CTRL_AUTOTX_SHIFT              29                                       /* Shift value for USART_AUTOTX */
#define _USART_CTRL_AUTOTX_MASK               0x20000000UL                             /* Bit mask for USART_AUTOTX */
#define _USART_CTRL_AUTOTX_DEFAULT            0x00000000UL                             /* Mode DEFAULT for USART_CTRL */
#define USART_CTRL_AUTOTX_DEFAULT             (_USART_CTRL_AUTOTX_DEFAULT << 29)       /* Shifted mode DEFAULT for USART_CTRL */
#define USART_CTRL_MVDIS                      (0x1UL << 30)                            /* Majority Vote Disable */
#define _USART_CTRL_MVDIS_SHIFT               30                                       /* Shift value for USART_MVDIS */
#define _USART_CTRL_MVDIS_MASK                0x40000000UL                             /* Bit mask for USART_MVDIS */
#define _USART_CTRL_MVDIS_DEFAULT             0x00000000UL                             /* Mode DEFAULT for USART_CTRL */
#define USART_CTRL_MVDIS_DEFAULT              (_USART_CTRL_MVDIS_DEFAULT << 30)        /* Shifted mode DEFAULT for USART_CTRL */

/* Bit fields for USART FRAME */

#define _USART_FRAME_RESETVALUE               0x00001005UL                              /* Default value for USART_FRAME */
#define _USART_FRAME_MASK                     0x0000330FUL                              /* Mask for USART_FRAME */

#define _USART_FRAME_DATABITS_SHIFT           0                                         /* Shift value for USART_DATABITS */
#define _USART_FRAME_DATABITS_MASK            0xFUL                                     /* Bit mask for USART_DATABITS */
#define _USART_FRAME_DATABITS_FOUR            0x00000001UL                              /* Mode FOUR for USART_FRAME */
#define _USART_FRAME_DATABITS_FIVE            0x00000002UL                              /* Mode FIVE for USART_FRAME */
#define _USART_FRAME_DATABITS_SIX             0x00000003UL                              /* Mode SIX for USART_FRAME */
#define _USART_FRAME_DATABITS_SEVEN           0x00000004UL                              /* Mode SEVEN for USART_FRAME */
#define _USART_FRAME_DATABITS_DEFAULT         0x00000005UL                              /* Mode DEFAULT for USART_FRAME */
#define _USART_FRAME_DATABITS_EIGHT           0x00000005UL                              /* Mode EIGHT for USART_FRAME */
#define _USART_FRAME_DATABITS_NINE            0x00000006UL                              /* Mode NINE for USART_FRAME */
#define _USART_FRAME_DATABITS_TEN             0x00000007UL                              /* Mode TEN for USART_FRAME */
#define _USART_FRAME_DATABITS_ELEVEN          0x00000008UL                              /* Mode ELEVEN for USART_FRAME */
#define _USART_FRAME_DATABITS_TWELVE          0x00000009UL                              /* Mode TWELVE for USART_FRAME */
#define _USART_FRAME_DATABITS_THIRTEEN        0x0000000AUL                              /* Mode THIRTEEN for USART_FRAME */
#define _USART_FRAME_DATABITS_FOURTEEN        0x0000000BUL                              /* Mode FOURTEEN for USART_FRAME */
#define _USART_FRAME_DATABITS_FIFTEEN         0x0000000CUL                              /* Mode FIFTEEN for USART_FRAME */
#define _USART_FRAME_DATABITS_SIXTEEN         0x0000000DUL                              /* Mode SIXTEEN for USART_FRAME */
#define USART_FRAME_DATABITS_FOUR             (_USART_FRAME_DATABITS_FOUR << 0)         /* Shifted mode FOUR for USART_FRAME */
#define USART_FRAME_DATABITS_FIVE             (_USART_FRAME_DATABITS_FIVE << 0)         /* Shifted mode FIVE for USART_FRAME */
#define USART_FRAME_DATABITS_SIX              (_USART_FRAME_DATABITS_SIX << 0)          /* Shifted mode SIX for USART_FRAME */
#define USART_FRAME_DATABITS_SEVEN            (_USART_FRAME_DATABITS_SEVEN << 0)        /* Shifted mode SEVEN for USART_FRAME */
#define USART_FRAME_DATABITS_DEFAULT          (_USART_FRAME_DATABITS_DEFAULT << 0)      /* Shifted mode DEFAULT for USART_FRAME */
#define USART_FRAME_DATABITS_EIGHT            (_USART_FRAME_DATABITS_EIGHT << 0)        /* Shifted mode EIGHT for USART_FRAME */
#define USART_FRAME_DATABITS_NINE             (_USART_FRAME_DATABITS_NINE << 0)         /* Shifted mode NINE for USART_FRAME */
#define USART_FRAME_DATABITS_TEN              (_USART_FRAME_DATABITS_TEN << 0)          /* Shifted mode TEN for USART_FRAME */
#define USART_FRAME_DATABITS_ELEVEN           (_USART_FRAME_DATABITS_ELEVEN << 0)       /* Shifted mode ELEVEN for USART_FRAME */
#define USART_FRAME_DATABITS_TWELVE           (_USART_FRAME_DATABITS_TWELVE << 0)       /* Shifted mode TWELVE for USART_FRAME */
#define USART_FRAME_DATABITS_THIRTEEN         (_USART_FRAME_DATABITS_THIRTEEN << 0)     /* Shifted mode THIRTEEN for USART_FRAME */
#define USART_FRAME_DATABITS_FOURTEEN         (_USART_FRAME_DATABITS_FOURTEEN << 0)     /* Shifted mode FOURTEEN for USART_FRAME */
#define USART_FRAME_DATABITS_FIFTEEN          (_USART_FRAME_DATABITS_FIFTEEN << 0)      /* Shifted mode FIFTEEN for USART_FRAME */
#define USART_FRAME_DATABITS_SIXTEEN          (_USART_FRAME_DATABITS_SIXTEEN << 0)      /* Shifted mode SIXTEEN for USART_FRAME */
#define _USART_FRAME_PARITY_SHIFT             8                                         /* Shift value for USART_PARITY */
#define _USART_FRAME_PARITY_MASK              0x300UL                                   /* Bit mask for USART_PARITY */
#define _USART_FRAME_PARITY_DEFAULT           0x00000000UL                              /* Mode DEFAULT for USART_FRAME */
#define _USART_FRAME_PARITY_NONE              0x00000000UL                              /* Mode NONE for USART_FRAME */
#define _USART_FRAME_PARITY_EVEN              0x00000002UL                              /* Mode EVEN for USART_FRAME */
#define _USART_FRAME_PARITY_ODD               0x00000003UL                              /* Mode ODD for USART_FRAME */
#define USART_FRAME_PARITY_DEFAULT            (_USART_FRAME_PARITY_DEFAULT << 8)        /* Shifted mode DEFAULT for USART_FRAME */
#define USART_FRAME_PARITY_NONE               (_USART_FRAME_PARITY_NONE << 8)           /* Shifted mode NONE for USART_FRAME */
#define USART_FRAME_PARITY_EVEN               (_USART_FRAME_PARITY_EVEN << 8)           /* Shifted mode EVEN for USART_FRAME */
#define USART_FRAME_PARITY_ODD                (_USART_FRAME_PARITY_ODD << 8)            /* Shifted mode ODD for USART_FRAME */
#define _USART_FRAME_STOPBITS_SHIFT           12                                        /* Shift value for USART_STOPBITS */
#define _USART_FRAME_STOPBITS_MASK            0x3000UL                                  /* Bit mask for USART_STOPBITS */
#define _USART_FRAME_STOPBITS_HALF            0x00000000UL                              /* Mode HALF for USART_FRAME */
#define _USART_FRAME_STOPBITS_DEFAULT         0x00000001UL                              /* Mode DEFAULT for USART_FRAME */
#define _USART_FRAME_STOPBITS_ONE             0x00000001UL                              /* Mode ONE for USART_FRAME */
#define _USART_FRAME_STOPBITS_ONEANDAHALF     0x00000002UL                              /* Mode ONEANDAHALF for USART_FRAME */
#define _USART_FRAME_STOPBITS_TWO             0x00000003UL                              /* Mode TWO for USART_FRAME */
#define USART_FRAME_STOPBITS_HALF             (_USART_FRAME_STOPBITS_HALF << 12)        /* Shifted mode HALF for USART_FRAME */
#define USART_FRAME_STOPBITS_DEFAULT          (_USART_FRAME_STOPBITS_DEFAULT << 12)     /* Shifted mode DEFAULT for USART_FRAME */
#define USART_FRAME_STOPBITS_ONE              (_USART_FRAME_STOPBITS_ONE << 12)         /* Shifted mode ONE for USART_FRAME */
#define USART_FRAME_STOPBITS_ONEANDAHALF      (_USART_FRAME_STOPBITS_ONEANDAHALF << 12) /* Shifted mode ONEANDAHALF for USART_FRAME */
#define USART_FRAME_STOPBITS_TWO              (_USART_FRAME_STOPBITS_TWO << 12)         /* Shifted mode TWO for USART_FRAME */

/* Bit fields for USART TRIGCTRL */

#define _USART_TRIGCTRL_RESETVALUE            0x00000000UL                             /* Default value for USART_TRIGCTRL */
#define _USART_TRIGCTRL_MASK                  0x00000077UL                             /* Mask for USART_TRIGCTRL */

#define _USART_TRIGCTRL_TSEL_SHIFT            0                                        /* Shift value for USART_TSEL */
#define _USART_TRIGCTRL_TSEL_MASK             0x7UL                                    /* Bit mask for USART_TSEL */
#define _USART_TRIGCTRL_TSEL_DEFAULT          0x00000000UL                             /* Mode DEFAULT for USART_TRIGCTRL */
#define _USART_TRIGCTRL_TSEL_PRSCH0           0x00000000UL                             /* Mode PRSCH0 for USART_TRIGCTRL */
#define _USART_TRIGCTRL_TSEL_PRSCH1           0x00000001UL                             /* Mode PRSCH1 for USART_TRIGCTRL */
#define _USART_TRIGCTRL_TSEL_PRSCH2           0x00000002UL                             /* Mode PRSCH2 for USART_TRIGCTRL */
#define _USART_TRIGCTRL_TSEL_PRSCH3           0x00000003UL                             /* Mode PRSCH3 for USART_TRIGCTRL */
#define _USART_TRIGCTRL_TSEL_PRSCH4           0x00000004UL                             /* Mode PRSCH4 for USART_TRIGCTRL */
#define _USART_TRIGCTRL_TSEL_PRSCH5           0x00000005UL                             /* Mode PRSCH5 for USART_TRIGCTRL */
#define _USART_TRIGCTRL_TSEL_PRSCH6           0x00000006UL                             /* Mode PRSCH6 for USART_TRIGCTRL */
#define _USART_TRIGCTRL_TSEL_PRSCH7           0x00000007UL                             /* Mode PRSCH7 for USART_TRIGCTRL */
#define USART_TRIGCTRL_TSEL_DEFAULT           (_USART_TRIGCTRL_TSEL_DEFAULT << 0)      /* Shifted mode DEFAULT for USART_TRIGCTRL */
#define USART_TRIGCTRL_TSEL_PRSCH0            (_USART_TRIGCTRL_TSEL_PRSCH0 << 0)       /* Shifted mode PRSCH0 for USART_TRIGCTRL */
#define USART_TRIGCTRL_TSEL_PRSCH1            (_USART_TRIGCTRL_TSEL_PRSCH1 << 0)       /* Shifted mode PRSCH1 for USART_TRIGCTRL */
#define USART_TRIGCTRL_TSEL_PRSCH2            (_USART_TRIGCTRL_TSEL_PRSCH2 << 0)       /* Shifted mode PRSCH2 for USART_TRIGCTRL */
#define USART_TRIGCTRL_TSEL_PRSCH3            (_USART_TRIGCTRL_TSEL_PRSCH3 << 0)       /* Shifted mode PRSCH3 for USART_TRIGCTRL */
#define USART_TRIGCTRL_TSEL_PRSCH4            (_USART_TRIGCTRL_TSEL_PRSCH4 << 0)       /* Shifted mode PRSCH4 for USART_TRIGCTRL */
#define USART_TRIGCTRL_TSEL_PRSCH5            (_USART_TRIGCTRL_TSEL_PRSCH5 << 0)       /* Shifted mode PRSCH5 for USART_TRIGCTRL */
#define USART_TRIGCTRL_TSEL_PRSCH6            (_USART_TRIGCTRL_TSEL_PRSCH6 << 0)       /* Shifted mode PRSCH6 for USART_TRIGCTRL */
#define USART_TRIGCTRL_TSEL_PRSCH7            (_USART_TRIGCTRL_TSEL_PRSCH7 << 0)       /* Shifted mode PRSCH7 for USART_TRIGCTRL */
#define USART_TRIGCTRL_RXTEN                  (0x1UL << 4)                             /* Receive Trigger Enable */
#define _USART_TRIGCTRL_RXTEN_SHIFT           4                                        /* Shift value for USART_RXTEN */
#define _USART_TRIGCTRL_RXTEN_MASK            0x10UL                                   /* Bit mask for USART_RXTEN */
#define _USART_TRIGCTRL_RXTEN_DEFAULT         0x00000000UL                             /* Mode DEFAULT for USART_TRIGCTRL */
#define USART_TRIGCTRL_RXTEN_DEFAULT          (_USART_TRIGCTRL_RXTEN_DEFAULT << 4)     /* Shifted mode DEFAULT for USART_TRIGCTRL */
#define USART_TRIGCTRL_TXTEN                  (0x1UL << 5)                             /* Transmit Trigger Enable */
#define _USART_TRIGCTRL_TXTEN_SHIFT           5                                        /* Shift value for USART_TXTEN */
#define _USART_TRIGCTRL_TXTEN_MASK            0x20UL                                   /* Bit mask for USART_TXTEN */
#define _USART_TRIGCTRL_TXTEN_DEFAULT         0x00000000UL                             /* Mode DEFAULT for USART_TRIGCTRL */
#define USART_TRIGCTRL_TXTEN_DEFAULT          (_USART_TRIGCTRL_TXTEN_DEFAULT << 5)     /* Shifted mode DEFAULT for USART_TRIGCTRL */
#define USART_TRIGCTRL_AUTOTXTEN              (0x1UL << 6)                             /* AUTOTX Trigger Enable */
#define _USART_TRIGCTRL_AUTOTXTEN_SHIFT       6                                        /* Shift value for USART_AUTOTXTEN */
#define _USART_TRIGCTRL_AUTOTXTEN_MASK        0x40UL                                   /* Bit mask for USART_AUTOTXTEN */
#define _USART_TRIGCTRL_AUTOTXTEN_DEFAULT     0x00000000UL                             /* Mode DEFAULT for USART_TRIGCTRL */
#define USART_TRIGCTRL_AUTOTXTEN_DEFAULT      (_USART_TRIGCTRL_AUTOTXTEN_DEFAULT << 6) /* Shifted mode DEFAULT for USART_TRIGCTRL */

/* Bit fields for USART CMD */

#define _USART_CMD_RESETVALUE                 0x00000000UL                         /* Default value for USART_CMD */
#define _USART_CMD_MASK                       0x00000FFFUL                         /* Mask for USART_CMD */

#define USART_CMD_RXEN                        (0x1UL << 0)                         /* Receiver Enable */
#define _USART_CMD_RXEN_SHIFT                 0                                    /* Shift value for USART_RXEN */
#define _USART_CMD_RXEN_MASK                  0x1UL                                /* Bit mask for USART_RXEN */
#define _USART_CMD_RXEN_DEFAULT               0x00000000UL                         /* Mode DEFAULT for USART_CMD */
#define USART_CMD_RXEN_DEFAULT                (_USART_CMD_RXEN_DEFAULT << 0)       /* Shifted mode DEFAULT for USART_CMD */
#define USART_CMD_RXDIS                       (0x1UL << 1)                         /* Receiver Disable */
#define _USART_CMD_RXDIS_SHIFT                1                                    /* Shift value for USART_RXDIS */
#define _USART_CMD_RXDIS_MASK                 0x2UL                                /* Bit mask for USART_RXDIS */
#define _USART_CMD_RXDIS_DEFAULT              0x00000000UL                         /* Mode DEFAULT for USART_CMD */
#define USART_CMD_RXDIS_DEFAULT               (_USART_CMD_RXDIS_DEFAULT << 1)      /* Shifted mode DEFAULT for USART_CMD */
#define USART_CMD_TXEN                        (0x1UL << 2)                         /* Transmitter Enable */
#define _USART_CMD_TXEN_SHIFT                 2                                    /* Shift value for USART_TXEN */
#define _USART_CMD_TXEN_MASK                  0x4UL                                /* Bit mask for USART_TXEN */
#define _USART_CMD_TXEN_DEFAULT               0x00000000UL                         /* Mode DEFAULT for USART_CMD */
#define USART_CMD_TXEN_DEFAULT                (_USART_CMD_TXEN_DEFAULT << 2)       /* Shifted mode DEFAULT for USART_CMD */
#define USART_CMD_TXDIS                       (0x1UL << 3)                         /* Transmitter Disable */
#define _USART_CMD_TXDIS_SHIFT                3                                    /* Shift value for USART_TXDIS */
#define _USART_CMD_TXDIS_MASK                 0x8UL                                /* Bit mask for USART_TXDIS */
#define _USART_CMD_TXDIS_DEFAULT              0x00000000UL                         /* Mode DEFAULT for USART_CMD */
#define USART_CMD_TXDIS_DEFAULT               (_USART_CMD_TXDIS_DEFAULT << 3)      /* Shifted mode DEFAULT for USART_CMD */
#define USART_CMD_MASTEREN                    (0x1UL << 4)                         /* Master Enable */
#define _USART_CMD_MASTEREN_SHIFT             4                                    /* Shift value for USART_MASTEREN */
#define _USART_CMD_MASTEREN_MASK              0x10UL                               /* Bit mask for USART_MASTEREN */
#define _USART_CMD_MASTEREN_DEFAULT           0x00000000UL                         /* Mode DEFAULT for USART_CMD */
#define USART_CMD_MASTEREN_DEFAULT            (_USART_CMD_MASTEREN_DEFAULT << 4)   /* Shifted mode DEFAULT for USART_CMD */
#define USART_CMD_MASTERDIS                   (0x1UL << 5)                         /* Master Disable */
#define _USART_CMD_MASTERDIS_SHIFT            5                                    /* Shift value for USART_MASTERDIS */
#define _USART_CMD_MASTERDIS_MASK             0x20UL                               /* Bit mask for USART_MASTERDIS */
#define _USART_CMD_MASTERDIS_DEFAULT          0x00000000UL                         /* Mode DEFAULT for USART_CMD */
#define USART_CMD_MASTERDIS_DEFAULT           (_USART_CMD_MASTERDIS_DEFAULT << 5)  /* Shifted mode DEFAULT for USART_CMD */
#define USART_CMD_RXBLOCKEN                   (0x1UL << 6)                         /* Receiver Block Enable */
#define _USART_CMD_RXBLOCKEN_SHIFT            6                                    /* Shift value for USART_RXBLOCKEN */
#define _USART_CMD_RXBLOCKEN_MASK             0x40UL                               /* Bit mask for USART_RXBLOCKEN */
#define _USART_CMD_RXBLOCKEN_DEFAULT          0x00000000UL                         /* Mode DEFAULT for USART_CMD */
#define USART_CMD_RXBLOCKEN_DEFAULT           (_USART_CMD_RXBLOCKEN_DEFAULT << 6)  /* Shifted mode DEFAULT for USART_CMD */
#define USART_CMD_RXBLOCKDIS                  (0x1UL << 7)                         /* Receiver Block Disable */
#define _USART_CMD_RXBLOCKDIS_SHIFT           7                                    /* Shift value for USART_RXBLOCKDIS */
#define _USART_CMD_RXBLOCKDIS_MASK            0x80UL                               /* Bit mask for USART_RXBLOCKDIS */
#define _USART_CMD_RXBLOCKDIS_DEFAULT         0x00000000UL                         /* Mode DEFAULT for USART_CMD */
#define USART_CMD_RXBLOCKDIS_DEFAULT          (_USART_CMD_RXBLOCKDIS_DEFAULT << 7) /* Shifted mode DEFAULT for USART_CMD */
#define USART_CMD_TXTRIEN                     (0x1UL << 8)                         /* Transmitter Tristate Enable */
#define _USART_CMD_TXTRIEN_SHIFT              8                                    /* Shift value for USART_TXTRIEN */
#define _USART_CMD_TXTRIEN_MASK               0x100UL                              /* Bit mask for USART_TXTRIEN */
#define _USART_CMD_TXTRIEN_DEFAULT            0x00000000UL                         /* Mode DEFAULT for USART_CMD */
#define USART_CMD_TXTRIEN_DEFAULT             (_USART_CMD_TXTRIEN_DEFAULT << 8)    /* Shifted mode DEFAULT for USART_CMD */
#define USART_CMD_TXTRIDIS                    (0x1UL << 9)                         /* Transmitter Tristate Disable */
#define _USART_CMD_TXTRIDIS_SHIFT             9                                    /* Shift value for USART_TXTRIDIS */
#define _USART_CMD_TXTRIDIS_MASK              0x200UL                              /* Bit mask for USART_TXTRIDIS */
#define _USART_CMD_TXTRIDIS_DEFAULT           0x00000000UL                         /* Mode DEFAULT for USART_CMD */
#define USART_CMD_TXTRIDIS_DEFAULT            (_USART_CMD_TXTRIDIS_DEFAULT << 9)   /* Shifted mode DEFAULT for USART_CMD */
#define USART_CMD_CLEARTX                     (0x1UL << 10)                        /* Clear TX */
#define _USART_CMD_CLEARTX_SHIFT              10                                   /* Shift value for USART_CLEARTX */
#define _USART_CMD_CLEARTX_MASK               0x400UL                              /* Bit mask for USART_CLEARTX */
#define _USART_CMD_CLEARTX_DEFAULT            0x00000000UL                         /* Mode DEFAULT for USART_CMD */
#define USART_CMD_CLEARTX_DEFAULT             (_USART_CMD_CLEARTX_DEFAULT << 10)   /* Shifted mode DEFAULT for USART_CMD */
#define USART_CMD_CLEARRX                     (0x1UL << 11)                        /* Clear RX */
#define _USART_CMD_CLEARRX_SHIFT              11                                   /* Shift value for USART_CLEARRX */
#define _USART_CMD_CLEARRX_MASK               0x800UL                              /* Bit mask for USART_CLEARRX */
#define _USART_CMD_CLEARRX_DEFAULT            0x00000000UL                         /* Mode DEFAULT for USART_CMD */
#define USART_CMD_CLEARRX_DEFAULT             (_USART_CMD_CLEARRX_DEFAULT << 11)   /* Shifted mode DEFAULT for USART_CMD */

/* Bit fields for USART STATUS */

#define _USART_STATUS_RESETVALUE              0x00000040UL                               /* Default value for USART_STATUS */
#define _USART_STATUS_MASK                    0x00001FFFUL                               /* Mask for USART_STATUS */

#define USART_STATUS_RXENS                    (0x1UL << 0)                               /* Receiver Enable Status */
#define _USART_STATUS_RXENS_SHIFT             0                                          /* Shift value for USART_RXENS */
#define _USART_STATUS_RXENS_MASK              0x1UL                                      /* Bit mask for USART_RXENS */
#define _USART_STATUS_RXENS_DEFAULT           0x00000000UL                               /* Mode DEFAULT for USART_STATUS */
#define USART_STATUS_RXENS_DEFAULT            (_USART_STATUS_RXENS_DEFAULT << 0)         /* Shifted mode DEFAULT for USART_STATUS */
#define USART_STATUS_TXENS                    (0x1UL << 1)                               /* Transmitter Enable Status */
#define _USART_STATUS_TXENS_SHIFT             1                                          /* Shift value for USART_TXENS */
#define _USART_STATUS_TXENS_MASK              0x2UL                                      /* Bit mask for USART_TXENS */
#define _USART_STATUS_TXENS_DEFAULT           0x00000000UL                               /* Mode DEFAULT for USART_STATUS */
#define USART_STATUS_TXENS_DEFAULT            (_USART_STATUS_TXENS_DEFAULT << 1)         /* Shifted mode DEFAULT for USART_STATUS */
#define USART_STATUS_MASTER                   (0x1UL << 2)                               /* SPI Master Mode */
#define _USART_STATUS_MASTER_SHIFT            2                                          /* Shift value for USART_MASTER */
#define _USART_STATUS_MASTER_MASK             0x4UL                                      /* Bit mask for USART_MASTER */
#define _USART_STATUS_MASTER_DEFAULT          0x00000000UL                               /* Mode DEFAULT for USART_STATUS */
#define USART_STATUS_MASTER_DEFAULT           (_USART_STATUS_MASTER_DEFAULT << 2)        /* Shifted mode DEFAULT for USART_STATUS */
#define USART_STATUS_RXBLOCK                  (0x1UL << 3)                               /* Block Incoming Data */
#define _USART_STATUS_RXBLOCK_SHIFT           3                                          /* Shift value for USART_RXBLOCK */
#define _USART_STATUS_RXBLOCK_MASK            0x8UL                                      /* Bit mask for USART_RXBLOCK */
#define _USART_STATUS_RXBLOCK_DEFAULT         0x00000000UL                               /* Mode DEFAULT for USART_STATUS */
#define USART_STATUS_RXBLOCK_DEFAULT          (_USART_STATUS_RXBLOCK_DEFAULT << 3)       /* Shifted mode DEFAULT for USART_STATUS */
#define USART_STATUS_TXTRI                    (0x1UL << 4)                               /* Transmitter Tristated */
#define _USART_STATUS_TXTRI_SHIFT             4                                          /* Shift value for USART_TXTRI */
#define _USART_STATUS_TXTRI_MASK              0x10UL                                     /* Bit mask for USART_TXTRI */
#define _USART_STATUS_TXTRI_DEFAULT           0x00000000UL                               /* Mode DEFAULT for USART_STATUS */
#define USART_STATUS_TXTRI_DEFAULT            (_USART_STATUS_TXTRI_DEFAULT << 4)         /* Shifted mode DEFAULT for USART_STATUS */
#define USART_STATUS_TXC                      (0x1UL << 5)                               /* TX Complete */
#define _USART_STATUS_TXC_SHIFT               5                                          /* Shift value for USART_TXC */
#define _USART_STATUS_TXC_MASK                0x20UL                                     /* Bit mask for USART_TXC */
#define _USART_STATUS_TXC_DEFAULT             0x00000000UL                               /* Mode DEFAULT for USART_STATUS */
#define USART_STATUS_TXC_DEFAULT              (_USART_STATUS_TXC_DEFAULT << 5)           /* Shifted mode DEFAULT for USART_STATUS */
#define USART_STATUS_TXBL                     (0x1UL << 6)                               /* TX Buffer Level */
#define _USART_STATUS_TXBL_SHIFT              6                                          /* Shift value for USART_TXBL */
#define _USART_STATUS_TXBL_MASK               0x40UL                                     /* Bit mask for USART_TXBL */
#define _USART_STATUS_TXBL_DEFAULT            0x00000001UL                               /* Mode DEFAULT for USART_STATUS */
#define USART_STATUS_TXBL_DEFAULT             (_USART_STATUS_TXBL_DEFAULT << 6)          /* Shifted mode DEFAULT for USART_STATUS */
#define USART_STATUS_RXDATAV                  (0x1UL << 7)                               /* RX Data Valid */
#define _USART_STATUS_RXDATAV_SHIFT           7                                          /* Shift value for USART_RXDATAV */
#define _USART_STATUS_RXDATAV_MASK            0x80UL                                     /* Bit mask for USART_RXDATAV */
#define _USART_STATUS_RXDATAV_DEFAULT         0x00000000UL                               /* Mode DEFAULT for USART_STATUS */
#define USART_STATUS_RXDATAV_DEFAULT          (_USART_STATUS_RXDATAV_DEFAULT << 7)       /* Shifted mode DEFAULT for USART_STATUS */
#define USART_STATUS_RXFULL                   (0x1UL << 8)                               /* RX FIFO Full */
#define _USART_STATUS_RXFULL_SHIFT            8                                          /* Shift value for USART_RXFULL */
#define _USART_STATUS_RXFULL_MASK             0x100UL                                    /* Bit mask for USART_RXFULL */
#define _USART_STATUS_RXFULL_DEFAULT          0x00000000UL                               /* Mode DEFAULT for USART_STATUS */
#define USART_STATUS_RXFULL_DEFAULT           (_USART_STATUS_RXFULL_DEFAULT << 8)        /* Shifted mode DEFAULT for USART_STATUS */
#define USART_STATUS_TXBDRIGHT                (0x1UL << 9)                               /* TX Buffer Expects Double Right Data */
#define _USART_STATUS_TXBDRIGHT_SHIFT         9                                          /* Shift value for USART_TXBDRIGHT */
#define _USART_STATUS_TXBDRIGHT_MASK          0x200UL                                    /* Bit mask for USART_TXBDRIGHT */
#define _USART_STATUS_TXBDRIGHT_DEFAULT       0x00000000UL                               /* Mode DEFAULT for USART_STATUS */
#define USART_STATUS_TXBDRIGHT_DEFAULT        (_USART_STATUS_TXBDRIGHT_DEFAULT << 9)     /* Shifted mode DEFAULT for USART_STATUS */
#define USART_STATUS_TXBSRIGHT                (0x1UL << 10)                              /* TX Buffer Expects Single Right Data */
#define _USART_STATUS_TXBSRIGHT_SHIFT         10                                         /* Shift value for USART_TXBSRIGHT */
#define _USART_STATUS_TXBSRIGHT_MASK          0x400UL                                    /* Bit mask for USART_TXBSRIGHT */
#define _USART_STATUS_TXBSRIGHT_DEFAULT       0x00000000UL                               /* Mode DEFAULT for USART_STATUS */
#define USART_STATUS_TXBSRIGHT_DEFAULT        (_USART_STATUS_TXBSRIGHT_DEFAULT << 10)    /* Shifted mode DEFAULT for USART_STATUS */
#define USART_STATUS_RXDATAVRIGHT             (0x1UL << 11)                              /* RX Data Right */
#define _USART_STATUS_RXDATAVRIGHT_SHIFT      11                                         /* Shift value for USART_RXDATAVRIGHT */
#define _USART_STATUS_RXDATAVRIGHT_MASK       0x800UL                                    /* Bit mask for USART_RXDATAVRIGHT */
#define _USART_STATUS_RXDATAVRIGHT_DEFAULT    0x00000000UL                               /* Mode DEFAULT for USART_STATUS */
#define USART_STATUS_RXDATAVRIGHT_DEFAULT     (_USART_STATUS_RXDATAVRIGHT_DEFAULT << 11) /* Shifted mode DEFAULT for USART_STATUS */
#define USART_STATUS_RXFULLRIGHT              (0x1UL << 12)                              /* RX Full of Right Data */
#define _USART_STATUS_RXFULLRIGHT_SHIFT       12                                         /* Shift value for USART_RXFULLRIGHT */
#define _USART_STATUS_RXFULLRIGHT_MASK        0x1000UL                                   /* Bit mask for USART_RXFULLRIGHT */
#define _USART_STATUS_RXFULLRIGHT_DEFAULT     0x00000000UL                               /* Mode DEFAULT for USART_STATUS */
#define USART_STATUS_RXFULLRIGHT_DEFAULT      (_USART_STATUS_RXFULLRIGHT_DEFAULT << 12)  /* Shifted mode DEFAULT for USART_STATUS */

/* Bit fields for USART CLKDIV */

#define _USART_CLKDIV_RESETVALUE              0x00000000UL                         /* Default value for USART_CLKDIV */
#define _USART_CLKDIV_MASK                    0x001FFFC0UL                         /* Mask for USART_CLKDIV */

#define _USART_CLKDIV_DIV_SHIFT               6                                    /* Shift value for USART_DIV */
#define _USART_CLKDIV_DIV_MASK                0x1FFFC0UL                           /* Bit mask for USART_DIV */
#define _USART_CLKDIV_DIV_DEFAULT             0x00000000UL                         /* Mode DEFAULT for USART_CLKDIV */
#define USART_CLKDIV_DIV_DEFAULT              (_USART_CLKDIV_DIV_DEFAULT << 6)     /* Shifted mode DEFAULT for USART_CLKDIV */

/* Bit fields for USART RXDATAX */

#define _USART_RXDATAX_RESETVALUE             0x00000000UL                         /* Default value for USART_RXDATAX */
#define _USART_RXDATAX_MASK                   0x0000C1FFUL                         /* Mask for USART_RXDATAX */

#define _USART_RXDATAX_RXDATA_SHIFT           0                                    /* Shift value for USART_RXDATA */
#define _USART_RXDATAX_RXDATA_MASK            0x1FFUL                              /* Bit mask for USART_RXDATA */
#define _USART_RXDATAX_RXDATA_DEFAULT         0x00000000UL                         /* Mode DEFAULT for USART_RXDATAX */
#define USART_RXDATAX_RXDATA_DEFAULT          (_USART_RXDATAX_RXDATA_DEFAULT << 0) /* Shifted mode DEFAULT for USART_RXDATAX */
#define USART_RXDATAX_PERR                    (0x1UL << 14)                        /* Data Parity Error */
#define _USART_RXDATAX_PERR_SHIFT             14                                   /* Shift value for USART_PERR */
#define _USART_RXDATAX_PERR_MASK              0x4000UL                             /* Bit mask for USART_PERR */
#define _USART_RXDATAX_PERR_DEFAULT           0x00000000UL                         /* Mode DEFAULT for USART_RXDATAX */
#define USART_RXDATAX_PERR_DEFAULT            (_USART_RXDATAX_PERR_DEFAULT << 14)  /* Shifted mode DEFAULT for USART_RXDATAX */
#define USART_RXDATAX_FERR                    (0x1UL << 15)                        /* Data Framing Error */
#define _USART_RXDATAX_FERR_SHIFT             15                                   /* Shift value for USART_FERR */
#define _USART_RXDATAX_FERR_MASK              0x8000UL                             /* Bit mask for USART_FERR */
#define _USART_RXDATAX_FERR_DEFAULT           0x00000000UL                         /* Mode DEFAULT for USART_RXDATAX */
#define USART_RXDATAX_FERR_DEFAULT            (_USART_RXDATAX_FERR_DEFAULT << 15)  /* Shifted mode DEFAULT for USART_RXDATAX */

/* Bit fields for USART RXDATA */

#define _USART_RXDATA_RESETVALUE              0x00000000UL                         /* Default value for USART_RXDATA */
#define _USART_RXDATA_MASK                    0x000000FFUL                         /* Mask for USART_RXDATA */

#define _USART_RXDATA_RXDATA_SHIFT            0                                    /* Shift value for USART_RXDATA */
#define _USART_RXDATA_RXDATA_MASK             0xFFUL                               /* Bit mask for USART_RXDATA */
#define _USART_RXDATA_RXDATA_DEFAULT          0x00000000UL                         /* Mode DEFAULT for USART_RXDATA */
#define USART_RXDATA_RXDATA_DEFAULT           (_USART_RXDATA_RXDATA_DEFAULT << 0)  /* Shifted mode DEFAULT for USART_RXDATA */

/* Bit fields for USART RXDOUBLEX */

#define _USART_RXDOUBLEX_RESETVALUE           0x00000000UL                             /* Default value for USART_RXDOUBLEX */
#define _USART_RXDOUBLEX_MASK                 0xC1FFC1FFUL                             /* Mask for USART_RXDOUBLEX */

#define _USART_RXDOUBLEX_RXDATA0_SHIFT        0                                        /* Shift value for USART_RXDATA0 */
#define _USART_RXDOUBLEX_RXDATA0_MASK         0x1FFUL                                  /* Bit mask for USART_RXDATA0 */
#define _USART_RXDOUBLEX_RXDATA0_DEFAULT      0x00000000UL                             /* Mode DEFAULT for USART_RXDOUBLEX */
#define USART_RXDOUBLEX_RXDATA0_DEFAULT       (_USART_RXDOUBLEX_RXDATA0_DEFAULT << 0)  /* Shifted mode DEFAULT for USART_RXDOUBLEX */
#define USART_RXDOUBLEX_PERR0                 (0x1UL << 14)                            /* Data Parity Error 0 */
#define _USART_RXDOUBLEX_PERR0_SHIFT          14                                       /* Shift value for USART_PERR0 */
#define _USART_RXDOUBLEX_PERR0_MASK           0x4000UL                                 /* Bit mask for USART_PERR0 */
#define _USART_RXDOUBLEX_PERR0_DEFAULT        0x00000000UL                             /* Mode DEFAULT for USART_RXDOUBLEX */
#define USART_RXDOUBLEX_PERR0_DEFAULT         (_USART_RXDOUBLEX_PERR0_DEFAULT << 14)   /* Shifted mode DEFAULT for USART_RXDOUBLEX */
#define USART_RXDOUBLEX_FERR0                 (0x1UL << 15)                            /* Data Framing Error 0 */
#define _USART_RXDOUBLEX_FERR0_SHIFT          15                                       /* Shift value for USART_FERR0 */
#define _USART_RXDOUBLEX_FERR0_MASK           0x8000UL                                 /* Bit mask for USART_FERR0 */
#define _USART_RXDOUBLEX_FERR0_DEFAULT        0x00000000UL                             /* Mode DEFAULT for USART_RXDOUBLEX */
#define USART_RXDOUBLEX_FERR0_DEFAULT         (_USART_RXDOUBLEX_FERR0_DEFAULT << 15)   /* Shifted mode DEFAULT for USART_RXDOUBLEX */
#define _USART_RXDOUBLEX_RXDATA1_SHIFT        16                                       /* Shift value for USART_RXDATA1 */
#define _USART_RXDOUBLEX_RXDATA1_MASK         0x1FF0000UL                              /* Bit mask for USART_RXDATA1 */
#define _USART_RXDOUBLEX_RXDATA1_DEFAULT      0x00000000UL                             /* Mode DEFAULT for USART_RXDOUBLEX */
#define USART_RXDOUBLEX_RXDATA1_DEFAULT       (_USART_RXDOUBLEX_RXDATA1_DEFAULT << 16) /* Shifted mode DEFAULT for USART_RXDOUBLEX */
#define USART_RXDOUBLEX_PERR1                 (0x1UL << 30)                            /* Data Parity Error 1 */
#define _USART_RXDOUBLEX_PERR1_SHIFT          30                                       /* Shift value for USART_PERR1 */
#define _USART_RXDOUBLEX_PERR1_MASK           0x40000000UL                             /* Bit mask for USART_PERR1 */
#define _USART_RXDOUBLEX_PERR1_DEFAULT        0x00000000UL                             /* Mode DEFAULT for USART_RXDOUBLEX */
#define USART_RXDOUBLEX_PERR1_DEFAULT         (_USART_RXDOUBLEX_PERR1_DEFAULT << 30)   /* Shifted mode DEFAULT for USART_RXDOUBLEX */
#define USART_RXDOUBLEX_FERR1                 (0x1UL << 31)                            /* Data Framing Error 1 */
#define _USART_RXDOUBLEX_FERR1_SHIFT          31                                       /* Shift value for USART_FERR1 */
#define _USART_RXDOUBLEX_FERR1_MASK           0x80000000UL                             /* Bit mask for USART_FERR1 */
#define _USART_RXDOUBLEX_FERR1_DEFAULT        0x00000000UL                             /* Mode DEFAULT for USART_RXDOUBLEX */
#define USART_RXDOUBLEX_FERR1_DEFAULT         (_USART_RXDOUBLEX_FERR1_DEFAULT << 31)   /* Shifted mode DEFAULT for USART_RXDOUBLEX */

/* Bit fields for USART RXDOUBLE */

#define _USART_RXDOUBLE_RESETVALUE            0x00000000UL                           /* Default value for USART_RXDOUBLE */
#define _USART_RXDOUBLE_MASK                  0x0000FFFFUL                           /* Mask for USART_RXDOUBLE */

#define _USART_RXDOUBLE_RXDATA0_SHIFT         0                                      /* Shift value for USART_RXDATA0 */
#define _USART_RXDOUBLE_RXDATA0_MASK          0xFFUL                                 /* Bit mask for USART_RXDATA0 */
#define _USART_RXDOUBLE_RXDATA0_DEFAULT       0x00000000UL                           /* Mode DEFAULT for USART_RXDOUBLE */
#define USART_RXDOUBLE_RXDATA0_DEFAULT        (_USART_RXDOUBLE_RXDATA0_DEFAULT << 0) /* Shifted mode DEFAULT for USART_RXDOUBLE */
#define _USART_RXDOUBLE_RXDATA1_SHIFT         8                                      /* Shift value for USART_RXDATA1 */
#define _USART_RXDOUBLE_RXDATA1_MASK          0xFF00UL                               /* Bit mask for USART_RXDATA1 */
#define _USART_RXDOUBLE_RXDATA1_DEFAULT       0x00000000UL                           /* Mode DEFAULT for USART_RXDOUBLE */
#define USART_RXDOUBLE_RXDATA1_DEFAULT        (_USART_RXDOUBLE_RXDATA1_DEFAULT << 8) /* Shifted mode DEFAULT for USART_RXDOUBLE */

/* Bit fields for USART RXDATAXP */

#define _USART_RXDATAXP_RESETVALUE            0x00000000UL                           /* Default value for USART_RXDATAXP */
#define _USART_RXDATAXP_MASK                  0x0000C1FFUL                           /* Mask for USART_RXDATAXP */

#define _USART_RXDATAXP_RXDATAP_SHIFT         0                                      /* Shift value for USART_RXDATAP */
#define _USART_RXDATAXP_RXDATAP_MASK          0x1FFUL                                /* Bit mask for USART_RXDATAP */
#define _USART_RXDATAXP_RXDATAP_DEFAULT       0x00000000UL                           /* Mode DEFAULT for USART_RXDATAXP */
#define USART_RXDATAXP_RXDATAP_DEFAULT        (_USART_RXDATAXP_RXDATAP_DEFAULT << 0) /* Shifted mode DEFAULT for USART_RXDATAXP */
#define USART_RXDATAXP_PERRP                  (0x1UL << 14)                          /* Data Parity Error Peek */
#define _USART_RXDATAXP_PERRP_SHIFT           14                                     /* Shift value for USART_PERRP */
#define _USART_RXDATAXP_PERRP_MASK            0x4000UL                               /* Bit mask for USART_PERRP */
#define _USART_RXDATAXP_PERRP_DEFAULT         0x00000000UL                           /* Mode DEFAULT for USART_RXDATAXP */
#define USART_RXDATAXP_PERRP_DEFAULT          (_USART_RXDATAXP_PERRP_DEFAULT << 14)  /* Shifted mode DEFAULT for USART_RXDATAXP */
#define USART_RXDATAXP_FERRP                  (0x1UL << 15)                          /* Data Framing Error Peek */
#define _USART_RXDATAXP_FERRP_SHIFT           15                                     /* Shift value for USART_FERRP */
#define _USART_RXDATAXP_FERRP_MASK            0x8000UL                               /* Bit mask for USART_FERRP */
#define _USART_RXDATAXP_FERRP_DEFAULT         0x00000000UL                           /* Mode DEFAULT for USART_RXDATAXP */
#define USART_RXDATAXP_FERRP_DEFAULT          (_USART_RXDATAXP_FERRP_DEFAULT << 15)  /* Shifted mode DEFAULT for USART_RXDATAXP */

/* Bit fields for USART RXDOUBLEXP */

#define _USART_RXDOUBLEXP_RESETVALUE          0x00000000UL                               /* Default value for USART_RXDOUBLEXP */
#define _USART_RXDOUBLEXP_MASK                0xC1FFC1FFUL                               /* Mask for USART_RXDOUBLEXP */

#define _USART_RXDOUBLEXP_RXDATAP0_SHIFT      0                                          /* Shift value for USART_RXDATAP0 */
#define _USART_RXDOUBLEXP_RXDATAP0_MASK       0x1FFUL                                    /* Bit mask for USART_RXDATAP0 */
#define _USART_RXDOUBLEXP_RXDATAP0_DEFAULT    0x00000000UL                               /* Mode DEFAULT for USART_RXDOUBLEXP */
#define USART_RXDOUBLEXP_RXDATAP0_DEFAULT     (_USART_RXDOUBLEXP_RXDATAP0_DEFAULT << 0)  /* Shifted mode DEFAULT for USART_RXDOUBLEXP */
#define USART_RXDOUBLEXP_PERRP0               (0x1UL << 14)                              /* Data Parity Error 0 Peek */
#define _USART_RXDOUBLEXP_PERRP0_SHIFT        14                                         /* Shift value for USART_PERRP0 */
#define _USART_RXDOUBLEXP_PERRP0_MASK         0x4000UL                                   /* Bit mask for USART_PERRP0 */
#define _USART_RXDOUBLEXP_PERRP0_DEFAULT      0x00000000UL                               /* Mode DEFAULT for USART_RXDOUBLEXP */
#define USART_RXDOUBLEXP_PERRP0_DEFAULT       (_USART_RXDOUBLEXP_PERRP0_DEFAULT << 14)   /* Shifted mode DEFAULT for USART_RXDOUBLEXP */
#define USART_RXDOUBLEXP_FERRP0               (0x1UL << 15)                              /* Data Framing Error 0 Peek */
#define _USART_RXDOUBLEXP_FERRP0_SHIFT        15                                         /* Shift value for USART_FERRP0 */
#define _USART_RXDOUBLEXP_FERRP0_MASK         0x8000UL                                   /* Bit mask for USART_FERRP0 */
#define _USART_RXDOUBLEXP_FERRP0_DEFAULT      0x00000000UL                               /* Mode DEFAULT for USART_RXDOUBLEXP */
#define USART_RXDOUBLEXP_FERRP0_DEFAULT       (_USART_RXDOUBLEXP_FERRP0_DEFAULT << 15)   /* Shifted mode DEFAULT for USART_RXDOUBLEXP */
#define _USART_RXDOUBLEXP_RXDATAP1_SHIFT      16                                         /* Shift value for USART_RXDATAP1 */
#define _USART_RXDOUBLEXP_RXDATAP1_MASK       0x1FF0000UL                                /* Bit mask for USART_RXDATAP1 */
#define _USART_RXDOUBLEXP_RXDATAP1_DEFAULT    0x00000000UL                               /* Mode DEFAULT for USART_RXDOUBLEXP */
#define USART_RXDOUBLEXP_RXDATAP1_DEFAULT     (_USART_RXDOUBLEXP_RXDATAP1_DEFAULT << 16) /* Shifted mode DEFAULT for USART_RXDOUBLEXP */
#define USART_RXDOUBLEXP_PERRP1               (0x1UL << 30)                              /* Data Parity Error 1 Peek */
#define _USART_RXDOUBLEXP_PERRP1_SHIFT        30                                         /* Shift value for USART_PERRP1 */
#define _USART_RXDOUBLEXP_PERRP1_MASK         0x40000000UL                               /* Bit mask for USART_PERRP1 */
#define _USART_RXDOUBLEXP_PERRP1_DEFAULT      0x00000000UL                               /* Mode DEFAULT for USART_RXDOUBLEXP */
#define USART_RXDOUBLEXP_PERRP1_DEFAULT       (_USART_RXDOUBLEXP_PERRP1_DEFAULT << 30)   /* Shifted mode DEFAULT for USART_RXDOUBLEXP */
#define USART_RXDOUBLEXP_FERRP1               (0x1UL << 31)                              /* Data Framing Error 1 Peek */
#define _USART_RXDOUBLEXP_FERRP1_SHIFT        31                                         /* Shift value for USART_FERRP1 */
#define _USART_RXDOUBLEXP_FERRP1_MASK         0x80000000UL                               /* Bit mask for USART_FERRP1 */
#define _USART_RXDOUBLEXP_FERRP1_DEFAULT      0x00000000UL                               /* Mode DEFAULT for USART_RXDOUBLEXP */
#define USART_RXDOUBLEXP_FERRP1_DEFAULT       (_USART_RXDOUBLEXP_FERRP1_DEFAULT << 31)   /* Shifted mode DEFAULT for USART_RXDOUBLEXP */

/* Bit fields for USART TXDATAX */

#define _USART_TXDATAX_RESETVALUE             0x00000000UL                           /* Default value for USART_TXDATAX */
#define _USART_TXDATAX_MASK                   0x0000F9FFUL                           /* Mask for USART_TXDATAX */

#define _USART_TXDATAX_TXDATAX_SHIFT          0                                      /* Shift value for USART_TXDATAX */
#define _USART_TXDATAX_TXDATAX_MASK           0x1FFUL                                /* Bit mask for USART_TXDATAX */
#define _USART_TXDATAX_TXDATAX_DEFAULT        0x00000000UL                           /* Mode DEFAULT for USART_TXDATAX */
#define USART_TXDATAX_TXDATAX_DEFAULT         (_USART_TXDATAX_TXDATAX_DEFAULT << 0)  /* Shifted mode DEFAULT for USART_TXDATAX */
#define USART_TXDATAX_UBRXAT                  (0x1UL << 11)                          /* Unblock RX After Transmission */
#define _USART_TXDATAX_UBRXAT_SHIFT           11                                     /* Shift value for USART_UBRXAT */
#define _USART_TXDATAX_UBRXAT_MASK            0x800UL                                /* Bit mask for USART_UBRXAT */
#define _USART_TXDATAX_UBRXAT_DEFAULT         0x00000000UL                           /* Mode DEFAULT for USART_TXDATAX */
#define USART_TXDATAX_UBRXAT_DEFAULT          (_USART_TXDATAX_UBRXAT_DEFAULT << 11)  /* Shifted mode DEFAULT for USART_TXDATAX */
#define USART_TXDATAX_TXTRIAT                 (0x1UL << 12)                          /* Set TXTRI After Transmission */
#define _USART_TXDATAX_TXTRIAT_SHIFT          12                                     /* Shift value for USART_TXTRIAT */
#define _USART_TXDATAX_TXTRIAT_MASK           0x1000UL                               /* Bit mask for USART_TXTRIAT */
#define _USART_TXDATAX_TXTRIAT_DEFAULT        0x00000000UL                           /* Mode DEFAULT for USART_TXDATAX */
#define USART_TXDATAX_TXTRIAT_DEFAULT         (_USART_TXDATAX_TXTRIAT_DEFAULT << 12) /* Shifted mode DEFAULT for USART_TXDATAX */
#define USART_TXDATAX_TXBREAK                 (0x1UL << 13)                          /* Transmit Data As Break */
#define _USART_TXDATAX_TXBREAK_SHIFT          13                                     /* Shift value for USART_TXBREAK */
#define _USART_TXDATAX_TXBREAK_MASK           0x2000UL                               /* Bit mask for USART_TXBREAK */
#define _USART_TXDATAX_TXBREAK_DEFAULT        0x00000000UL                           /* Mode DEFAULT for USART_TXDATAX */
#define USART_TXDATAX_TXBREAK_DEFAULT         (_USART_TXDATAX_TXBREAK_DEFAULT << 13) /* Shifted mode DEFAULT for USART_TXDATAX */
#define USART_TXDATAX_TXDISAT                 (0x1UL << 14)                          /* Clear TXEN After Transmission */
#define _USART_TXDATAX_TXDISAT_SHIFT          14                                     /* Shift value for USART_TXDISAT */
#define _USART_TXDATAX_TXDISAT_MASK           0x4000UL                               /* Bit mask for USART_TXDISAT */
#define _USART_TXDATAX_TXDISAT_DEFAULT        0x00000000UL                           /* Mode DEFAULT for USART_TXDATAX */
#define USART_TXDATAX_TXDISAT_DEFAULT         (_USART_TXDATAX_TXDISAT_DEFAULT << 14) /* Shifted mode DEFAULT for USART_TXDATAX */
#define USART_TXDATAX_RXENAT                  (0x1UL << 15)                          /* Enable RX After Transmission */
#define _USART_TXDATAX_RXENAT_SHIFT           15                                     /* Shift value for USART_RXENAT */
#define _USART_TXDATAX_RXENAT_MASK            0x8000UL                               /* Bit mask for USART_RXENAT */
#define _USART_TXDATAX_RXENAT_DEFAULT         0x00000000UL                           /* Mode DEFAULT for USART_TXDATAX */
#define USART_TXDATAX_RXENAT_DEFAULT          (_USART_TXDATAX_RXENAT_DEFAULT << 15)  /* Shifted mode DEFAULT for USART_TXDATAX */

/* Bit fields for USART TXDATA */

#define _USART_TXDATA_RESETVALUE              0x00000000UL                           /* Default value for USART_TXDATA */
#define _USART_TXDATA_MASK                    0x000000FFUL                           /* Mask for USART_TXDATA */

#define _USART_TXDATA_TXDATA_SHIFT            0                                      /* Shift value for USART_TXDATA */
#define _USART_TXDATA_TXDATA_MASK             0xFFUL                                 /* Bit mask for USART_TXDATA */
#define _USART_TXDATA_TXDATA_DEFAULT          0x00000000UL                           /* Mode DEFAULT for USART_TXDATA */
#define USART_TXDATA_TXDATA_DEFAULT           (_USART_TXDATA_TXDATA_DEFAULT << 0)    /* Shifted mode DEFAULT for USART_TXDATA */

/* Bit fields for USART TXDOUBLEX */

#define _USART_TXDOUBLEX_RESETVALUE           0x00000000UL                              /* Default value for USART_TXDOUBLEX */
#define _USART_TXDOUBLEX_MASK                 0xF9FFF9FFUL                              /* Mask for USART_TXDOUBLEX */

#define _USART_TXDOUBLEX_TXDATA0_SHIFT        0                                         /* Shift value for USART_TXDATA0 */
#define _USART_TXDOUBLEX_TXDATA0_MASK         0x1FFUL                                   /* Bit mask for USART_TXDATA0 */
#define _USART_TXDOUBLEX_TXDATA0_DEFAULT      0x00000000UL                              /* Mode DEFAULT for USART_TXDOUBLEX */
#define USART_TXDOUBLEX_TXDATA0_DEFAULT       (_USART_TXDOUBLEX_TXDATA0_DEFAULT << 0)   /* Shifted mode DEFAULT for USART_TXDOUBLEX */
#define USART_TXDOUBLEX_UBRXAT0               (0x1UL << 11)                             /* Unblock RX After Transmission */
#define _USART_TXDOUBLEX_UBRXAT0_SHIFT        11                                        /* Shift value for USART_UBRXAT0 */
#define _USART_TXDOUBLEX_UBRXAT0_MASK         0x800UL                                   /* Bit mask for USART_UBRXAT0 */
#define _USART_TXDOUBLEX_UBRXAT0_DEFAULT      0x00000000UL                              /* Mode DEFAULT for USART_TXDOUBLEX */
#define USART_TXDOUBLEX_UBRXAT0_DEFAULT       (_USART_TXDOUBLEX_UBRXAT0_DEFAULT << 11)  /* Shifted mode DEFAULT for USART_TXDOUBLEX */
#define USART_TXDOUBLEX_TXTRIAT0              (0x1UL << 12)                             /* Set TXTRI After Transmission */
#define _USART_TXDOUBLEX_TXTRIAT0_SHIFT       12                                        /* Shift value for USART_TXTRIAT0 */
#define _USART_TXDOUBLEX_TXTRIAT0_MASK        0x1000UL                                  /* Bit mask for USART_TXTRIAT0 */
#define _USART_TXDOUBLEX_TXTRIAT0_DEFAULT     0x00000000UL                              /* Mode DEFAULT for USART_TXDOUBLEX */
#define USART_TXDOUBLEX_TXTRIAT0_DEFAULT      (_USART_TXDOUBLEX_TXTRIAT0_DEFAULT << 12) /* Shifted mode DEFAULT for USART_TXDOUBLEX */
#define USART_TXDOUBLEX_TXBREAK0              (0x1UL << 13)                             /* Transmit Data As Break */
#define _USART_TXDOUBLEX_TXBREAK0_SHIFT       13                                        /* Shift value for USART_TXBREAK0 */
#define _USART_TXDOUBLEX_TXBREAK0_MASK        0x2000UL                                  /* Bit mask for USART_TXBREAK0 */
#define _USART_TXDOUBLEX_TXBREAK0_DEFAULT     0x00000000UL                              /* Mode DEFAULT for USART_TXDOUBLEX */
#define USART_TXDOUBLEX_TXBREAK0_DEFAULT      (_USART_TXDOUBLEX_TXBREAK0_DEFAULT << 13) /* Shifted mode DEFAULT for USART_TXDOUBLEX */
#define USART_TXDOUBLEX_TXDISAT0              (0x1UL << 14)                             /* Clear TXEN After Transmission */
#define _USART_TXDOUBLEX_TXDISAT0_SHIFT       14                                        /* Shift value for USART_TXDISAT0 */
#define _USART_TXDOUBLEX_TXDISAT0_MASK        0x4000UL                                  /* Bit mask for USART_TXDISAT0 */
#define _USART_TXDOUBLEX_TXDISAT0_DEFAULT     0x00000000UL                              /* Mode DEFAULT for USART_TXDOUBLEX */
#define USART_TXDOUBLEX_TXDISAT0_DEFAULT      (_USART_TXDOUBLEX_TXDISAT0_DEFAULT << 14) /* Shifted mode DEFAULT for USART_TXDOUBLEX */
#define USART_TXDOUBLEX_RXENAT0               (0x1UL << 15)                             /* Enable RX After Transmission */
#define _USART_TXDOUBLEX_RXENAT0_SHIFT        15                                        /* Shift value for USART_RXENAT0 */
#define _USART_TXDOUBLEX_RXENAT0_MASK         0x8000UL                                  /* Bit mask for USART_RXENAT0 */
#define _USART_TXDOUBLEX_RXENAT0_DEFAULT      0x00000000UL                              /* Mode DEFAULT for USART_TXDOUBLEX */
#define USART_TXDOUBLEX_RXENAT0_DEFAULT       (_USART_TXDOUBLEX_RXENAT0_DEFAULT << 15)  /* Shifted mode DEFAULT for USART_TXDOUBLEX */
#define _USART_TXDOUBLEX_TXDATA1_SHIFT        16                                        /* Shift value for USART_TXDATA1 */
#define _USART_TXDOUBLEX_TXDATA1_MASK         0x1FF0000UL                               /* Bit mask for USART_TXDATA1 */
#define _USART_TXDOUBLEX_TXDATA1_DEFAULT      0x00000000UL                              /* Mode DEFAULT for USART_TXDOUBLEX */
#define USART_TXDOUBLEX_TXDATA1_DEFAULT       (_USART_TXDOUBLEX_TXDATA1_DEFAULT << 16)  /* Shifted mode DEFAULT for USART_TXDOUBLEX */
#define USART_TXDOUBLEX_UBRXAT1               (0x1UL << 27)                             /* Unblock RX After Transmission */
#define _USART_TXDOUBLEX_UBRXAT1_SHIFT        27                                        /* Shift value for USART_UBRXAT1 */
#define _USART_TXDOUBLEX_UBRXAT1_MASK         0x8000000UL                               /* Bit mask for USART_UBRXAT1 */
#define _USART_TXDOUBLEX_UBRXAT1_DEFAULT      0x00000000UL                              /* Mode DEFAULT for USART_TXDOUBLEX */
#define USART_TXDOUBLEX_UBRXAT1_DEFAULT       (_USART_TXDOUBLEX_UBRXAT1_DEFAULT << 27)  /* Shifted mode DEFAULT for USART_TXDOUBLEX */
#define USART_TXDOUBLEX_TXTRIAT1              (0x1UL << 28)                             /* Set TXTRI After Transmission */
#define _USART_TXDOUBLEX_TXTRIAT1_SHIFT       28                                        /* Shift value for USART_TXTRIAT1 */
#define _USART_TXDOUBLEX_TXTRIAT1_MASK        0x10000000UL                              /* Bit mask for USART_TXTRIAT1 */
#define _USART_TXDOUBLEX_TXTRIAT1_DEFAULT     0x00000000UL                              /* Mode DEFAULT for USART_TXDOUBLEX */
#define USART_TXDOUBLEX_TXTRIAT1_DEFAULT      (_USART_TXDOUBLEX_TXTRIAT1_DEFAULT << 28) /* Shifted mode DEFAULT for USART_TXDOUBLEX */
#define USART_TXDOUBLEX_TXBREAK1              (0x1UL << 29)                             /* Transmit Data As Break */
#define _USART_TXDOUBLEX_TXBREAK1_SHIFT       29                                        /* Shift value for USART_TXBREAK1 */
#define _USART_TXDOUBLEX_TXBREAK1_MASK        0x20000000UL                              /* Bit mask for USART_TXBREAK1 */
#define _USART_TXDOUBLEX_TXBREAK1_DEFAULT     0x00000000UL                              /* Mode DEFAULT for USART_TXDOUBLEX */
#define USART_TXDOUBLEX_TXBREAK1_DEFAULT      (_USART_TXDOUBLEX_TXBREAK1_DEFAULT << 29) /* Shifted mode DEFAULT for USART_TXDOUBLEX */
#define USART_TXDOUBLEX_TXDISAT1              (0x1UL << 30)                             /* Clear TXEN After Transmission */
#define _USART_TXDOUBLEX_TXDISAT1_SHIFT       30                                        /* Shift value for USART_TXDISAT1 */
#define _USART_TXDOUBLEX_TXDISAT1_MASK        0x40000000UL                              /* Bit mask for USART_TXDISAT1 */
#define _USART_TXDOUBLEX_TXDISAT1_DEFAULT     0x00000000UL                              /* Mode DEFAULT for USART_TXDOUBLEX */
#define USART_TXDOUBLEX_TXDISAT1_DEFAULT      (_USART_TXDOUBLEX_TXDISAT1_DEFAULT << 30) /* Shifted mode DEFAULT for USART_TXDOUBLEX */
#define USART_TXDOUBLEX_RXENAT1               (0x1UL << 31)                             /* Enable RX After Transmission */
#define _USART_TXDOUBLEX_RXENAT1_SHIFT        31                                        /* Shift value for USART_RXENAT1 */
#define _USART_TXDOUBLEX_RXENAT1_MASK         0x80000000UL                              /* Bit mask for USART_RXENAT1 */
#define _USART_TXDOUBLEX_RXENAT1_DEFAULT      0x00000000UL                              /* Mode DEFAULT for USART_TXDOUBLEX */
#define USART_TXDOUBLEX_RXENAT1_DEFAULT       (_USART_TXDOUBLEX_RXENAT1_DEFAULT << 31)  /* Shifted mode DEFAULT for USART_TXDOUBLEX */

/* Bit fields for USART TXDOUBLE */

#define _USART_TXDOUBLE_RESETVALUE            0x00000000UL                              /* Default value for USART_TXDOUBLE */
#define _USART_TXDOUBLE_MASK                  0x0000FFFFUL                              /* Mask for USART_TXDOUBLE */

#define _USART_TXDOUBLE_TXDATA0_SHIFT         0                                         /* Shift value for USART_TXDATA0 */
#define _USART_TXDOUBLE_TXDATA0_MASK          0xFFUL                                    /* Bit mask for USART_TXDATA0 */
#define _USART_TXDOUBLE_TXDATA0_DEFAULT       0x00000000UL                              /* Mode DEFAULT for USART_TXDOUBLE */
#define USART_TXDOUBLE_TXDATA0_DEFAULT        (_USART_TXDOUBLE_TXDATA0_DEFAULT << 0)    /* Shifted mode DEFAULT for USART_TXDOUBLE */
#define _USART_TXDOUBLE_TXDATA1_SHIFT         8                                         /* Shift value for USART_TXDATA1 */
#define _USART_TXDOUBLE_TXDATA1_MASK          0xFF00UL                                  /* Bit mask for USART_TXDATA1 */
#define _USART_TXDOUBLE_TXDATA1_DEFAULT       0x00000000UL                              /* Mode DEFAULT for USART_TXDOUBLE */
#define USART_TXDOUBLE_TXDATA1_DEFAULT        (_USART_TXDOUBLE_TXDATA1_DEFAULT << 8)    /* Shifted mode DEFAULT for USART_TXDOUBLE */

/* Bit fields for USART IF */

#define _USART_IF_RESETVALUE                  0x00000002UL                     /* Default value for USART_IF */
#define _USART_IF_MASK                        0x00001FFFUL                     /* Mask for USART_IF */

#define USART_IF_TXC                          (0x1UL << 0)                     /* TX Complete Interrupt Flag */
#define _USART_IF_TXC_SHIFT                   0                                /* Shift value for USART_TXC */
#define _USART_IF_TXC_MASK                    0x1UL                            /* Bit mask for USART_TXC */
#define _USART_IF_TXC_DEFAULT                 0x00000000UL                     /* Mode DEFAULT for USART_IF */
#define USART_IF_TXC_DEFAULT                  (_USART_IF_TXC_DEFAULT << 0)     /* Shifted mode DEFAULT for USART_IF */
#define USART_IF_TXBL                         (0x1UL << 1)                     /* TX Buffer Level Interrupt Flag */
#define _USART_IF_TXBL_SHIFT                  1                                /* Shift value for USART_TXBL */
#define _USART_IF_TXBL_MASK                   0x2UL                            /* Bit mask for USART_TXBL */
#define _USART_IF_TXBL_DEFAULT                0x00000001UL                     /* Mode DEFAULT for USART_IF */
#define USART_IF_TXBL_DEFAULT                 (_USART_IF_TXBL_DEFAULT << 1)    /* Shifted mode DEFAULT for USART_IF */
#define USART_IF_RXDATAV                      (0x1UL << 2)                     /* RX Data Valid Interrupt Flag */
#define _USART_IF_RXDATAV_SHIFT               2                                /* Shift value for USART_RXDATAV */
#define _USART_IF_RXDATAV_MASK                0x4UL                            /* Bit mask for USART_RXDATAV */
#define _USART_IF_RXDATAV_DEFAULT             0x00000000UL                     /* Mode DEFAULT for USART_IF */
#define USART_IF_RXDATAV_DEFAULT              (_USART_IF_RXDATAV_DEFAULT << 2) /* Shifted mode DEFAULT for USART_IF */
#define USART_IF_RXFULL                       (0x1UL << 3)                     /* RX Buffer Full Interrupt Flag */
#define _USART_IF_RXFULL_SHIFT                3                                /* Shift value for USART_RXFULL */
#define _USART_IF_RXFULL_MASK                 0x8UL                            /* Bit mask for USART_RXFULL */
#define _USART_IF_RXFULL_DEFAULT              0x00000000UL                     /* Mode DEFAULT for USART_IF */
#define USART_IF_RXFULL_DEFAULT               (_USART_IF_RXFULL_DEFAULT << 3)  /* Shifted mode DEFAULT for USART_IF */
#define USART_IF_RXOF                         (0x1UL << 4)                     /* RX Overflow Interrupt Flag */
#define _USART_IF_RXOF_SHIFT                  4                                /* Shift value for USART_RXOF */
#define _USART_IF_RXOF_MASK                   0x10UL                           /* Bit mask for USART_RXOF */
#define _USART_IF_RXOF_DEFAULT                0x00000000UL                     /* Mode DEFAULT for USART_IF */
#define USART_IF_RXOF_DEFAULT                 (_USART_IF_RXOF_DEFAULT << 4)    /* Shifted mode DEFAULT for USART_IF */
#define USART_IF_RXUF                         (0x1UL << 5)                     /* RX Underflow Interrupt Flag */
#define _USART_IF_RXUF_SHIFT                  5                                /* Shift value for USART_RXUF */
#define _USART_IF_RXUF_MASK                   0x20UL                           /* Bit mask for USART_RXUF */
#define _USART_IF_RXUF_DEFAULT                0x00000000UL                     /* Mode DEFAULT for USART_IF */
#define USART_IF_RXUF_DEFAULT                 (_USART_IF_RXUF_DEFAULT << 5)    /* Shifted mode DEFAULT for USART_IF */
#define USART_IF_TXOF                         (0x1UL << 6)                     /* TX Overflow Interrupt Flag */
#define _USART_IF_TXOF_SHIFT                  6                                /* Shift value for USART_TXOF */
#define _USART_IF_TXOF_MASK                   0x40UL                           /* Bit mask for USART_TXOF */
#define _USART_IF_TXOF_DEFAULT                0x00000000UL                     /* Mode DEFAULT for USART_IF */
#define USART_IF_TXOF_DEFAULT                 (_USART_IF_TXOF_DEFAULT << 6)    /* Shifted mode DEFAULT for USART_IF */
#define USART_IF_TXUF                         (0x1UL << 7)                     /* TX Underflow Interrupt Flag */
#define _USART_IF_TXUF_SHIFT                  7                                /* Shift value for USART_TXUF */
#define _USART_IF_TXUF_MASK                   0x80UL                           /* Bit mask for USART_TXUF */
#define _USART_IF_TXUF_DEFAULT                0x00000000UL                     /* Mode DEFAULT for USART_IF */
#define USART_IF_TXUF_DEFAULT                 (_USART_IF_TXUF_DEFAULT << 7)    /* Shifted mode DEFAULT for USART_IF */
#define USART_IF_PERR                         (0x1UL << 8)                     /* Parity Error Interrupt Flag */
#define _USART_IF_PERR_SHIFT                  8                                /* Shift value for USART_PERR */
#define _USART_IF_PERR_MASK                   0x100UL                          /* Bit mask for USART_PERR */
#define _USART_IF_PERR_DEFAULT                0x00000000UL                     /* Mode DEFAULT for USART_IF */
#define USART_IF_PERR_DEFAULT                 (_USART_IF_PERR_DEFAULT << 8)    /* Shifted mode DEFAULT for USART_IF */
#define USART_IF_FERR                         (0x1UL << 9)                     /* Framing Error Interrupt Flag */
#define _USART_IF_FERR_SHIFT                  9                                /* Shift value for USART_FERR */
#define _USART_IF_FERR_MASK                   0x200UL                          /* Bit mask for USART_FERR */
#define _USART_IF_FERR_DEFAULT                0x00000000UL                     /* Mode DEFAULT for USART_IF */
#define USART_IF_FERR_DEFAULT                 (_USART_IF_FERR_DEFAULT << 9)    /* Shifted mode DEFAULT for USART_IF */
#define USART_IF_MPAF                         (0x1UL << 10)                    /* Multi-Processor Address Frame Interrupt Flag */
#define _USART_IF_MPAF_SHIFT                  10                               /* Shift value for USART_MPAF */
#define _USART_IF_MPAF_MASK                   0x400UL                          /* Bit mask for USART_MPAF */
#define _USART_IF_MPAF_DEFAULT                0x00000000UL                     /* Mode DEFAULT for USART_IF */
#define USART_IF_MPAF_DEFAULT                 (_USART_IF_MPAF_DEFAULT << 10)   /* Shifted mode DEFAULT for USART_IF */
#define USART_IF_SSM                          (0x1UL << 11)                    /* Slave-Select In Master Mode Interrupt Flag */
#define _USART_IF_SSM_SHIFT                   11                               /* Shift value for USART_SSM */
#define _USART_IF_SSM_MASK                    0x800UL                          /* Bit mask for USART_SSM */
#define _USART_IF_SSM_DEFAULT                 0x00000000UL                     /* Mode DEFAULT for USART_IF */
#define USART_IF_SSM_DEFAULT                  (_USART_IF_SSM_DEFAULT << 11)    /* Shifted mode DEFAULT for USART_IF */
#define USART_IF_CCF                          (0x1UL << 12)                    /* Collision Check Fail Interrupt Flag */
#define _USART_IF_CCF_SHIFT                   12                               /* Shift value for USART_CCF */
#define _USART_IF_CCF_MASK                    0x1000UL                         /* Bit mask for USART_CCF */
#define _USART_IF_CCF_DEFAULT                 0x00000000UL                     /* Mode DEFAULT for USART_IF */
#define USART_IF_CCF_DEFAULT                  (_USART_IF_CCF_DEFAULT << 12)    /* Shifted mode DEFAULT for USART_IF */

/* Bit fields for USART IFS */

#define _USART_IFS_RESETVALUE                 0x00000000UL                     /* Default value for USART_IFS */
#define _USART_IFS_MASK                       0x00001FF9UL                     /* Mask for USART_IFS */

#define USART_IFS_TXC                         (0x1UL << 0)                     /* Set TX Complete Interrupt Flag */
#define _USART_IFS_TXC_SHIFT                  0                                /* Shift value for USART_TXC */
#define _USART_IFS_TXC_MASK                   0x1UL                            /* Bit mask for USART_TXC */
#define _USART_IFS_TXC_DEFAULT                0x00000000UL                     /* Mode DEFAULT for USART_IFS */
#define USART_IFS_TXC_DEFAULT                 (_USART_IFS_TXC_DEFAULT << 0)    /* Shifted mode DEFAULT for USART_IFS */
#define USART_IFS_RXFULL                      (0x1UL << 3)                     /* Set RX Buffer Full Interrupt Flag */
#define _USART_IFS_RXFULL_SHIFT               3                                /* Shift value for USART_RXFULL */
#define _USART_IFS_RXFULL_MASK                0x8UL                            /* Bit mask for USART_RXFULL */
#define _USART_IFS_RXFULL_DEFAULT             0x00000000UL                     /* Mode DEFAULT for USART_IFS */
#define USART_IFS_RXFULL_DEFAULT              (_USART_IFS_RXFULL_DEFAULT << 3) /* Shifted mode DEFAULT for USART_IFS */
#define USART_IFS_RXOF                        (0x1UL << 4)                     /* Set RX Overflow Interrupt Flag */
#define _USART_IFS_RXOF_SHIFT                 4                                /* Shift value for USART_RXOF */
#define _USART_IFS_RXOF_MASK                  0x10UL                           /* Bit mask for USART_RXOF */
#define _USART_IFS_RXOF_DEFAULT               0x00000000UL                     /* Mode DEFAULT for USART_IFS */
#define USART_IFS_RXOF_DEFAULT                (_USART_IFS_RXOF_DEFAULT << 4)   /* Shifted mode DEFAULT for USART_IFS */
#define USART_IFS_RXUF                        (0x1UL << 5)                     /* Set RX Underflow Interrupt Flag */
#define _USART_IFS_RXUF_SHIFT                 5                                /* Shift value for USART_RXUF */
#define _USART_IFS_RXUF_MASK                  0x20UL                           /* Bit mask for USART_RXUF */
#define _USART_IFS_RXUF_DEFAULT               0x00000000UL                     /* Mode DEFAULT for USART_IFS */
#define USART_IFS_RXUF_DEFAULT                (_USART_IFS_RXUF_DEFAULT << 5)   /* Shifted mode DEFAULT for USART_IFS */
#define USART_IFS_TXOF                        (0x1UL << 6)                     /* Set TX Overflow Interrupt Flag */
#define _USART_IFS_TXOF_SHIFT                 6                                /* Shift value for USART_TXOF */
#define _USART_IFS_TXOF_MASK                  0x40UL                           /* Bit mask for USART_TXOF */
#define _USART_IFS_TXOF_DEFAULT               0x00000000UL                     /* Mode DEFAULT for USART_IFS */
#define USART_IFS_TXOF_DEFAULT                (_USART_IFS_TXOF_DEFAULT << 6)   /* Shifted mode DEFAULT for USART_IFS */
#define USART_IFS_TXUF                        (0x1UL << 7)                     /* Set TX Underflow Interrupt Flag */
#define _USART_IFS_TXUF_SHIFT                 7                                /* Shift value for USART_TXUF */
#define _USART_IFS_TXUF_MASK                  0x80UL                           /* Bit mask for USART_TXUF */
#define _USART_IFS_TXUF_DEFAULT               0x00000000UL                     /* Mode DEFAULT for USART_IFS */
#define USART_IFS_TXUF_DEFAULT                (_USART_IFS_TXUF_DEFAULT << 7)   /* Shifted mode DEFAULT for USART_IFS */
#define USART_IFS_PERR                        (0x1UL << 8)                     /* Set Parity Error Interrupt Flag */
#define _USART_IFS_PERR_SHIFT                 8                                /* Shift value for USART_PERR */
#define _USART_IFS_PERR_MASK                  0x100UL                          /* Bit mask for USART_PERR */
#define _USART_IFS_PERR_DEFAULT               0x00000000UL                     /* Mode DEFAULT for USART_IFS */
#define USART_IFS_PERR_DEFAULT                (_USART_IFS_PERR_DEFAULT << 8)   /* Shifted mode DEFAULT for USART_IFS */
#define USART_IFS_FERR                        (0x1UL << 9)                     /* Set Framing Error Interrupt Flag */
#define _USART_IFS_FERR_SHIFT                 9                                /* Shift value for USART_FERR */
#define _USART_IFS_FERR_MASK                  0x200UL                          /* Bit mask for USART_FERR */
#define _USART_IFS_FERR_DEFAULT               0x00000000UL                     /* Mode DEFAULT for USART_IFS */
#define USART_IFS_FERR_DEFAULT                (_USART_IFS_FERR_DEFAULT << 9)   /* Shifted mode DEFAULT for USART_IFS */
#define USART_IFS_MPAF                        (0x1UL << 10)                    /* Set Multi-Processor Address Frame Interrupt Flag */
#define _USART_IFS_MPAF_SHIFT                 10                               /* Shift value for USART_MPAF */
#define _USART_IFS_MPAF_MASK                  0x400UL                          /* Bit mask for USART_MPAF */
#define _USART_IFS_MPAF_DEFAULT               0x00000000UL                     /* Mode DEFAULT for USART_IFS */
#define USART_IFS_MPAF_DEFAULT                (_USART_IFS_MPAF_DEFAULT << 10)  /* Shifted mode DEFAULT for USART_IFS */
#define USART_IFS_SSM                         (0x1UL << 11)                    /* Set Slave-Select in Master mode Interrupt Flag */
#define _USART_IFS_SSM_SHIFT                  11                               /* Shift value for USART_SSM */
#define _USART_IFS_SSM_MASK                   0x800UL                          /* Bit mask for USART_SSM */
#define _USART_IFS_SSM_DEFAULT                0x00000000UL                     /* Mode DEFAULT for USART_IFS */
#define USART_IFS_SSM_DEFAULT                 (_USART_IFS_SSM_DEFAULT << 11)   /* Shifted mode DEFAULT for USART_IFS */
#define USART_IFS_CCF                         (0x1UL << 12)                    /* Set Collision Check Fail Interrupt Flag */
#define _USART_IFS_CCF_SHIFT                  12                               /* Shift value for USART_CCF */
#define _USART_IFS_CCF_MASK                   0x1000UL                         /* Bit mask for USART_CCF */
#define _USART_IFS_CCF_DEFAULT                0x00000000UL                     /* Mode DEFAULT for USART_IFS */
#define USART_IFS_CCF_DEFAULT                 (_USART_IFS_CCF_DEFAULT << 12)   /* Shifted mode DEFAULT for USART_IFS */

/* Bit fields for USART IFC */

#define _USART_IFC_RESETVALUE                 0x00000000UL                     /* Default value for USART_IFC */
#define _USART_IFC_MASK                       0x00001FF9UL                     /* Mask for USART_IFC */

#define USART_IFC_TXC                         (0x1UL << 0)                     /* Clear TX Complete Interrupt Flag */
#define _USART_IFC_TXC_SHIFT                  0                                /* Shift value for USART_TXC */
#define _USART_IFC_TXC_MASK                   0x1UL                            /* Bit mask for USART_TXC */
#define _USART_IFC_TXC_DEFAULT                0x00000000UL                     /* Mode DEFAULT for USART_IFC */
#define USART_IFC_TXC_DEFAULT                 (_USART_IFC_TXC_DEFAULT << 0)    /* Shifted mode DEFAULT for USART_IFC */
#define USART_IFC_RXFULL                      (0x1UL << 3)                     /* Clear RX Buffer Full Interrupt Flag */
#define _USART_IFC_RXFULL_SHIFT               3                                /* Shift value for USART_RXFULL */
#define _USART_IFC_RXFULL_MASK                0x8UL                            /* Bit mask for USART_RXFULL */
#define _USART_IFC_RXFULL_DEFAULT             0x00000000UL                     /* Mode DEFAULT for USART_IFC */
#define USART_IFC_RXFULL_DEFAULT              (_USART_IFC_RXFULL_DEFAULT << 3) /* Shifted mode DEFAULT for USART_IFC */
#define USART_IFC_RXOF                        (0x1UL << 4)                     /* Clear RX Overflow Interrupt Flag */
#define _USART_IFC_RXOF_SHIFT                 4                                /* Shift value for USART_RXOF */
#define _USART_IFC_RXOF_MASK                  0x10UL                           /* Bit mask for USART_RXOF */
#define _USART_IFC_RXOF_DEFAULT               0x00000000UL                     /* Mode DEFAULT for USART_IFC */
#define USART_IFC_RXOF_DEFAULT                (_USART_IFC_RXOF_DEFAULT << 4)   /* Shifted mode DEFAULT for USART_IFC */
#define USART_IFC_RXUF                        (0x1UL << 5)                     /* Clear RX Underflow Interrupt Flag */
#define _USART_IFC_RXUF_SHIFT                 5                                /* Shift value for USART_RXUF */
#define _USART_IFC_RXUF_MASK                  0x20UL                           /* Bit mask for USART_RXUF */
#define _USART_IFC_RXUF_DEFAULT               0x00000000UL                     /* Mode DEFAULT for USART_IFC */
#define USART_IFC_RXUF_DEFAULT                (_USART_IFC_RXUF_DEFAULT << 5)   /* Shifted mode DEFAULT for USART_IFC */
#define USART_IFC_TXOF                        (0x1UL << 6)                     /* Clear TX Overflow Interrupt Flag */
#define _USART_IFC_TXOF_SHIFT                 6                                /* Shift value for USART_TXOF */
#define _USART_IFC_TXOF_MASK                  0x40UL                           /* Bit mask for USART_TXOF */
#define _USART_IFC_TXOF_DEFAULT               0x00000000UL                     /* Mode DEFAULT for USART_IFC */
#define USART_IFC_TXOF_DEFAULT                (_USART_IFC_TXOF_DEFAULT << 6)   /* Shifted mode DEFAULT for USART_IFC */
#define USART_IFC_TXUF                        (0x1UL << 7)                     /* Clear TX Underflow Interrupt Flag */
#define _USART_IFC_TXUF_SHIFT                 7                                /* Shift value for USART_TXUF */
#define _USART_IFC_TXUF_MASK                  0x80UL                           /* Bit mask for USART_TXUF */
#define _USART_IFC_TXUF_DEFAULT               0x00000000UL                     /* Mode DEFAULT for USART_IFC */
#define USART_IFC_TXUF_DEFAULT                (_USART_IFC_TXUF_DEFAULT << 7)   /* Shifted mode DEFAULT for USART_IFC */
#define USART_IFC_PERR                        (0x1UL << 8)                     /* Clear Parity Error Interrupt Flag */
#define _USART_IFC_PERR_SHIFT                 8                                /* Shift value for USART_PERR */
#define _USART_IFC_PERR_MASK                  0x100UL                          /* Bit mask for USART_PERR */
#define _USART_IFC_PERR_DEFAULT               0x00000000UL                     /* Mode DEFAULT for USART_IFC */
#define USART_IFC_PERR_DEFAULT                (_USART_IFC_PERR_DEFAULT << 8)   /* Shifted mode DEFAULT for USART_IFC */
#define USART_IFC_FERR                        (0x1UL << 9)                     /* Clear Framing Error Interrupt Flag */
#define _USART_IFC_FERR_SHIFT                 9                                /* Shift value for USART_FERR */
#define _USART_IFC_FERR_MASK                  0x200UL                          /* Bit mask for USART_FERR */
#define _USART_IFC_FERR_DEFAULT               0x00000000UL                     /* Mode DEFAULT for USART_IFC */
#define USART_IFC_FERR_DEFAULT                (_USART_IFC_FERR_DEFAULT << 9)   /* Shifted mode DEFAULT for USART_IFC */
#define USART_IFC_MPAF                        (0x1UL << 10)                    /* Clear Multi-Processor Address Frame Interrupt Flag */
#define _USART_IFC_MPAF_SHIFT                 10                               /* Shift value for USART_MPAF */
#define _USART_IFC_MPAF_MASK                  0x400UL                          /* Bit mask for USART_MPAF */
#define _USART_IFC_MPAF_DEFAULT               0x00000000UL                     /* Mode DEFAULT for USART_IFC */
#define USART_IFC_MPAF_DEFAULT                (_USART_IFC_MPAF_DEFAULT << 10)  /* Shifted mode DEFAULT for USART_IFC */
#define USART_IFC_SSM                         (0x1UL << 11)                    /* Clear Slave-Select In Master Mode Interrupt Flag */
#define _USART_IFC_SSM_SHIFT                  11                               /* Shift value for USART_SSM */
#define _USART_IFC_SSM_MASK                   0x800UL                          /* Bit mask for USART_SSM */
#define _USART_IFC_SSM_DEFAULT                0x00000000UL                     /* Mode DEFAULT for USART_IFC */
#define USART_IFC_SSM_DEFAULT                 (_USART_IFC_SSM_DEFAULT << 11)   /* Shifted mode DEFAULT for USART_IFC */
#define USART_IFC_CCF                         (0x1UL << 12)                    /* Clear Collision Check Fail Interrupt Flag */
#define _USART_IFC_CCF_SHIFT                  12                               /* Shift value for USART_CCF */
#define _USART_IFC_CCF_MASK                   0x1000UL                         /* Bit mask for USART_CCF */
#define _USART_IFC_CCF_DEFAULT                0x00000000UL                     /* Mode DEFAULT for USART_IFC */
#define USART_IFC_CCF_DEFAULT                 (_USART_IFC_CCF_DEFAULT << 12)   /* Shifted mode DEFAULT for USART_IFC */

/* Bit fields for USART IEN */

#define _USART_IEN_RESETVALUE                 0x00000000UL                      /* Default value for USART_IEN */
#define _USART_IEN_MASK                       0x00001FFFUL                      /* Mask for USART_IEN */

#define USART_IEN_TXC                         (0x1UL << 0)                      /* TX Complete Interrupt Enable */
#define _USART_IEN_TXC_SHIFT                  0                                 /* Shift value for USART_TXC */
#define _USART_IEN_TXC_MASK                   0x1UL                             /* Bit mask for USART_TXC */
#define _USART_IEN_TXC_DEFAULT                0x00000000UL                      /* Mode DEFAULT for USART_IEN */
#define USART_IEN_TXC_DEFAULT                 (_USART_IEN_TXC_DEFAULT << 0)     /* Shifted mode DEFAULT for USART_IEN */
#define USART_IEN_TXBL                        (0x1UL << 1)                      /* TX Buffer Level Interrupt Enable */
#define _USART_IEN_TXBL_SHIFT                 1                                 /* Shift value for USART_TXBL */
#define _USART_IEN_TXBL_MASK                  0x2UL                             /* Bit mask for USART_TXBL */
#define _USART_IEN_TXBL_DEFAULT               0x00000000UL                      /* Mode DEFAULT for USART_IEN */
#define USART_IEN_TXBL_DEFAULT                (_USART_IEN_TXBL_DEFAULT << 1)    /* Shifted mode DEFAULT for USART_IEN */
#define USART_IEN_RXDATAV                     (0x1UL << 2)                      /* RX Data Valid Interrupt Enable */
#define _USART_IEN_RXDATAV_SHIFT              2                                 /* Shift value for USART_RXDATAV */
#define _USART_IEN_RXDATAV_MASK               0x4UL                             /* Bit mask for USART_RXDATAV */
#define _USART_IEN_RXDATAV_DEFAULT            0x00000000UL                      /* Mode DEFAULT for USART_IEN */
#define USART_IEN_RXDATAV_DEFAULT             (_USART_IEN_RXDATAV_DEFAULT << 2) /* Shifted mode DEFAULT for USART_IEN */
#define USART_IEN_RXFULL                      (0x1UL << 3)                      /* RX Buffer Full Interrupt Enable */
#define _USART_IEN_RXFULL_SHIFT               3                                 /* Shift value for USART_RXFULL */
#define _USART_IEN_RXFULL_MASK                0x8UL                             /* Bit mask for USART_RXFULL */
#define _USART_IEN_RXFULL_DEFAULT             0x00000000UL                      /* Mode DEFAULT for USART_IEN */
#define USART_IEN_RXFULL_DEFAULT              (_USART_IEN_RXFULL_DEFAULT << 3)  /* Shifted mode DEFAULT for USART_IEN */
#define USART_IEN_RXOF                        (0x1UL << 4)                      /* RX Overflow Interrupt Enable */
#define _USART_IEN_RXOF_SHIFT                 4                                 /* Shift value for USART_RXOF */
#define _USART_IEN_RXOF_MASK                  0x10UL                            /* Bit mask for USART_RXOF */
#define _USART_IEN_RXOF_DEFAULT               0x00000000UL                      /* Mode DEFAULT for USART_IEN */
#define USART_IEN_RXOF_DEFAULT                (_USART_IEN_RXOF_DEFAULT << 4)    /* Shifted mode DEFAULT for USART_IEN */
#define USART_IEN_RXUF                        (0x1UL << 5)                      /* RX Underflow Interrupt Enable */
#define _USART_IEN_RXUF_SHIFT                 5                                 /* Shift value for USART_RXUF */
#define _USART_IEN_RXUF_MASK                  0x20UL                            /* Bit mask for USART_RXUF */
#define _USART_IEN_RXUF_DEFAULT               0x00000000UL                      /* Mode DEFAULT for USART_IEN */
#define USART_IEN_RXUF_DEFAULT                (_USART_IEN_RXUF_DEFAULT << 5)    /* Shifted mode DEFAULT for USART_IEN */
#define USART_IEN_TXOF                        (0x1UL << 6)                      /* TX Overflow Interrupt Enable */
#define _USART_IEN_TXOF_SHIFT                 6                                 /* Shift value for USART_TXOF */
#define _USART_IEN_TXOF_MASK                  0x40UL                            /* Bit mask for USART_TXOF */
#define _USART_IEN_TXOF_DEFAULT               0x00000000UL                      /* Mode DEFAULT for USART_IEN */
#define USART_IEN_TXOF_DEFAULT                (_USART_IEN_TXOF_DEFAULT << 6)    /* Shifted mode DEFAULT for USART_IEN */
#define USART_IEN_TXUF                        (0x1UL << 7)                      /* TX Underflow Interrupt Enable */
#define _USART_IEN_TXUF_SHIFT                 7                                 /* Shift value for USART_TXUF */
#define _USART_IEN_TXUF_MASK                  0x80UL                            /* Bit mask for USART_TXUF */
#define _USART_IEN_TXUF_DEFAULT               0x00000000UL                      /* Mode DEFAULT for USART_IEN */
#define USART_IEN_TXUF_DEFAULT                (_USART_IEN_TXUF_DEFAULT << 7)    /* Shifted mode DEFAULT for USART_IEN */
#define USART_IEN_PERR                        (0x1UL << 8)                      /* Parity Error Interrupt Enable */
#define _USART_IEN_PERR_SHIFT                 8                                 /* Shift value for USART_PERR */
#define _USART_IEN_PERR_MASK                  0x100UL                           /* Bit mask for USART_PERR */
#define _USART_IEN_PERR_DEFAULT               0x00000000UL                      /* Mode DEFAULT for USART_IEN */
#define USART_IEN_PERR_DEFAULT                (_USART_IEN_PERR_DEFAULT << 8)    /* Shifted mode DEFAULT for USART_IEN */
#define USART_IEN_FERR                        (0x1UL << 9)                      /* Framing Error Interrupt Enable */
#define _USART_IEN_FERR_SHIFT                 9                                 /* Shift value for USART_FERR */
#define _USART_IEN_FERR_MASK                  0x200UL                           /* Bit mask for USART_FERR */
#define _USART_IEN_FERR_DEFAULT               0x00000000UL                      /* Mode DEFAULT for USART_IEN */
#define USART_IEN_FERR_DEFAULT                (_USART_IEN_FERR_DEFAULT << 9)    /* Shifted mode DEFAULT for USART_IEN */
#define USART_IEN_MPAF                        (0x1UL << 10)                     /* Multi-Processor Address Frame Interrupt Enable */
#define _USART_IEN_MPAF_SHIFT                 10                                /* Shift value for USART_MPAF */
#define _USART_IEN_MPAF_MASK                  0x400UL                           /* Bit mask for USART_MPAF */
#define _USART_IEN_MPAF_DEFAULT               0x00000000UL                      /* Mode DEFAULT for USART_IEN */
#define USART_IEN_MPAF_DEFAULT                (_USART_IEN_MPAF_DEFAULT << 10)   /* Shifted mode DEFAULT for USART_IEN */
#define USART_IEN_SSM                         (0x1UL << 11)                     /* Slave-Select In Master Mode Interrupt Enable */
#define _USART_IEN_SSM_SHIFT                  11                                /* Shift value for USART_SSM */
#define _USART_IEN_SSM_MASK                   0x800UL                           /* Bit mask for USART_SSM */
#define _USART_IEN_SSM_DEFAULT                0x00000000UL                      /* Mode DEFAULT for USART_IEN */
#define USART_IEN_SSM_DEFAULT                 (_USART_IEN_SSM_DEFAULT << 11)    /* Shifted mode DEFAULT for USART_IEN */
#define USART_IEN_CCF                         (0x1UL << 12)                     /* Collision Check Fail Interrupt Enable */
#define _USART_IEN_CCF_SHIFT                  12                                /* Shift value for USART_CCF */
#define _USART_IEN_CCF_MASK                   0x1000UL                          /* Bit mask for USART_CCF */
#define _USART_IEN_CCF_DEFAULT                0x00000000UL                      /* Mode DEFAULT for USART_IEN */
#define USART_IEN_CCF_DEFAULT                 (_USART_IEN_CCF_DEFAULT << 12)    /* Shifted mode DEFAULT for USART_IEN */

/* Bit fields for USART IRCTRL */

#define _USART_IRCTRL_RESETVALUE              0x00000000UL                          /* Default value for USART_IRCTRL */
#define _USART_IRCTRL_MASK                    0x000000FFUL                          /* Mask for USART_IRCTRL */

#define USART_IRCTRL_IREN                     (0x1UL << 0)                          /* Enable IrDA Module */
#define _USART_IRCTRL_IREN_SHIFT              0                                     /* Shift value for USART_IREN */
#define _USART_IRCTRL_IREN_MASK               0x1UL                                 /* Bit mask for USART_IREN */
#define _USART_IRCTRL_IREN_DEFAULT            0x00000000UL                          /* Mode DEFAULT for USART_IRCTRL */
#define USART_IRCTRL_IREN_DEFAULT             (_USART_IRCTRL_IREN_DEFAULT << 0)     /* Shifted mode DEFAULT for USART_IRCTRL */
#define _USART_IRCTRL_IRPW_SHIFT              1                                     /* Shift value for USART_IRPW */
#define _USART_IRCTRL_IRPW_MASK               0x6UL                                 /* Bit mask for USART_IRPW */
#define _USART_IRCTRL_IRPW_DEFAULT            0x00000000UL                          /* Mode DEFAULT for USART_IRCTRL */
#define _USART_IRCTRL_IRPW_ONE                0x00000000UL                          /* Mode ONE for USART_IRCTRL */
#define _USART_IRCTRL_IRPW_TWO                0x00000001UL                          /* Mode TWO for USART_IRCTRL */
#define _USART_IRCTRL_IRPW_THREE              0x00000002UL                          /* Mode THREE for USART_IRCTRL */
#define _USART_IRCTRL_IRPW_FOUR               0x00000003UL                          /* Mode FOUR for USART_IRCTRL */
#define USART_IRCTRL_IRPW_DEFAULT             (_USART_IRCTRL_IRPW_DEFAULT << 1)     /* Shifted mode DEFAULT for USART_IRCTRL */
#define USART_IRCTRL_IRPW_ONE                 (_USART_IRCTRL_IRPW_ONE << 1)         /* Shifted mode ONE for USART_IRCTRL */
#define USART_IRCTRL_IRPW_TWO                 (_USART_IRCTRL_IRPW_TWO << 1)         /* Shifted mode TWO for USART_IRCTRL */
#define USART_IRCTRL_IRPW_THREE               (_USART_IRCTRL_IRPW_THREE << 1)       /* Shifted mode THREE for USART_IRCTRL */
#define USART_IRCTRL_IRPW_FOUR                (_USART_IRCTRL_IRPW_FOUR << 1)        /* Shifted mode FOUR for USART_IRCTRL */
#define USART_IRCTRL_IRFILT                   (0x1UL << 3)                          /* IrDA RX Filter */
#define _USART_IRCTRL_IRFILT_SHIFT            3                                     /* Shift value for USART_IRFILT */
#define _USART_IRCTRL_IRFILT_MASK             0x8UL                                 /* Bit mask for USART_IRFILT */
#define _USART_IRCTRL_IRFILT_DEFAULT          0x00000000UL                          /* Mode DEFAULT for USART_IRCTRL */
#define USART_IRCTRL_IRFILT_DEFAULT           (_USART_IRCTRL_IRFILT_DEFAULT << 3)   /* Shifted mode DEFAULT for USART_IRCTRL */
#define _USART_IRCTRL_IRPRSSEL_SHIFT          4                                     /* Shift value for USART_IRPRSSEL */
#define _USART_IRCTRL_IRPRSSEL_MASK           0x70UL                                /* Bit mask for USART_IRPRSSEL */
#define _USART_IRCTRL_IRPRSSEL_DEFAULT        0x00000000UL                          /* Mode DEFAULT for USART_IRCTRL */
#define _USART_IRCTRL_IRPRSSEL_PRSCH0         0x00000000UL                          /* Mode PRSCH0 for USART_IRCTRL */
#define _USART_IRCTRL_IRPRSSEL_PRSCH1         0x00000001UL                          /* Mode PRSCH1 for USART_IRCTRL */
#define _USART_IRCTRL_IRPRSSEL_PRSCH2         0x00000002UL                          /* Mode PRSCH2 for USART_IRCTRL */
#define _USART_IRCTRL_IRPRSSEL_PRSCH3         0x00000003UL                          /* Mode PRSCH3 for USART_IRCTRL */
#define _USART_IRCTRL_IRPRSSEL_PRSCH4         0x00000004UL                          /* Mode PRSCH4 for USART_IRCTRL */
#define _USART_IRCTRL_IRPRSSEL_PRSCH5         0x00000005UL                          /* Mode PRSCH5 for USART_IRCTRL */
#define _USART_IRCTRL_IRPRSSEL_PRSCH6         0x00000006UL                          /* Mode PRSCH6 for USART_IRCTRL */
#define _USART_IRCTRL_IRPRSSEL_PRSCH7         0x00000007UL                          /* Mode PRSCH7 for USART_IRCTRL */
#define USART_IRCTRL_IRPRSSEL_DEFAULT         (_USART_IRCTRL_IRPRSSEL_DEFAULT << 4) /* Shifted mode DEFAULT for USART_IRCTRL */
#define USART_IRCTRL_IRPRSSEL_PRSCH0          (_USART_IRCTRL_IRPRSSEL_PRSCH0 << 4)  /* Shifted mode PRSCH0 for USART_IRCTRL */
#define USART_IRCTRL_IRPRSSEL_PRSCH1          (_USART_IRCTRL_IRPRSSEL_PRSCH1 << 4)  /* Shifted mode PRSCH1 for USART_IRCTRL */
#define USART_IRCTRL_IRPRSSEL_PRSCH2          (_USART_IRCTRL_IRPRSSEL_PRSCH2 << 4)  /* Shifted mode PRSCH2 for USART_IRCTRL */
#define USART_IRCTRL_IRPRSSEL_PRSCH3          (_USART_IRCTRL_IRPRSSEL_PRSCH3 << 4)  /* Shifted mode PRSCH3 for USART_IRCTRL */
#define USART_IRCTRL_IRPRSSEL_PRSCH4          (_USART_IRCTRL_IRPRSSEL_PRSCH4 << 4)  /* Shifted mode PRSCH4 for USART_IRCTRL */
#define USART_IRCTRL_IRPRSSEL_PRSCH5          (_USART_IRCTRL_IRPRSSEL_PRSCH5 << 4)  /* Shifted mode PRSCH5 for USART_IRCTRL */
#define USART_IRCTRL_IRPRSSEL_PRSCH6          (_USART_IRCTRL_IRPRSSEL_PRSCH6 << 4)  /* Shifted mode PRSCH6 for USART_IRCTRL */
#define USART_IRCTRL_IRPRSSEL_PRSCH7          (_USART_IRCTRL_IRPRSSEL_PRSCH7 << 4)  /* Shifted mode PRSCH7 for USART_IRCTRL */
#define USART_IRCTRL_IRPRSEN                  (0x1UL << 7)                          /* IrDA PRS Channel Enable */
#define _USART_IRCTRL_IRPRSEN_SHIFT           7                                     /* Shift value for USART_IRPRSEN */
#define _USART_IRCTRL_IRPRSEN_MASK            0x80UL                                /* Bit mask for USART_IRPRSEN */
#define _USART_IRCTRL_IRPRSEN_DEFAULT         0x00000000UL                          /* Mode DEFAULT for USART_IRCTRL */
#define USART_IRCTRL_IRPRSEN_DEFAULT          (_USART_IRCTRL_IRPRSEN_DEFAULT << 7)  /* Shifted mode DEFAULT for USART_IRCTRL */

/* Bit fields for USART ROUTE */

#define _USART_ROUTE_RESETVALUE               0x00000000UL                         /* Default value for USART_ROUTE */
#define _USART_ROUTE_MASK                     0x0000070FUL                         /* Mask for USART_ROUTE */

#define USART_ROUTE_RXPEN                     (0x1UL << 0)                         /* RX Pin Enable */
#define _USART_ROUTE_RXPEN_SHIFT              0                                    /* Shift value for USART_RXPEN */
#define _USART_ROUTE_RXPEN_MASK               0x1UL                                /* Bit mask for USART_RXPEN */
#define _USART_ROUTE_RXPEN_DEFAULT            0x00000000UL                         /* Mode DEFAULT for USART_ROUTE */
#define USART_ROUTE_RXPEN_DEFAULT             (_USART_ROUTE_RXPEN_DEFAULT << 0)    /* Shifted mode DEFAULT for USART_ROUTE */
#define USART_ROUTE_TXPEN                     (0x1UL << 1)                         /* TX Pin Enable */
#define _USART_ROUTE_TXPEN_SHIFT              1                                    /* Shift value for USART_TXPEN */
#define _USART_ROUTE_TXPEN_MASK               0x2UL                                /* Bit mask for USART_TXPEN */
#define _USART_ROUTE_TXPEN_DEFAULT            0x00000000UL                         /* Mode DEFAULT for USART_ROUTE */
#define USART_ROUTE_TXPEN_DEFAULT             (_USART_ROUTE_TXPEN_DEFAULT << 1)    /* Shifted mode DEFAULT for USART_ROUTE */
#define USART_ROUTE_CSPEN                     (0x1UL << 2)                         /* CS Pin Enable */
#define _USART_ROUTE_CSPEN_SHIFT              2                                    /* Shift value for USART_CSPEN */
#define _USART_ROUTE_CSPEN_MASK               0x4UL                                /* Bit mask for USART_CSPEN */
#define _USART_ROUTE_CSPEN_DEFAULT            0x00000000UL                         /* Mode DEFAULT for USART_ROUTE */
#define USART_ROUTE_CSPEN_DEFAULT             (_USART_ROUTE_CSPEN_DEFAULT << 2)    /* Shifted mode DEFAULT for USART_ROUTE */
#define USART_ROUTE_CLKPEN                    (0x1UL << 3)                         /* CLK Pin Enable */
#define _USART_ROUTE_CLKPEN_SHIFT             3                                    /* Shift value for USART_CLKPEN */
#define _USART_ROUTE_CLKPEN_MASK              0x8UL                                /* Bit mask for USART_CLKPEN */
#define _USART_ROUTE_CLKPEN_DEFAULT           0x00000000UL                         /* Mode DEFAULT for USART_ROUTE */
#define USART_ROUTE_CLKPEN_DEFAULT            (_USART_ROUTE_CLKPEN_DEFAULT << 3)   /* Shifted mode DEFAULT for USART_ROUTE */
#define _USART_ROUTE_LOCATION_SHIFT           8                                    /* Shift value for USART_LOCATION */
#define _USART_ROUTE_LOCATION_MASK            0x700UL                              /* Bit mask for USART_LOCATION */
#define _USART_ROUTE_LOCATION_LOC0            0x00000000UL                         /* Mode LOC0 for USART_ROUTE */
#define _USART_ROUTE_LOCATION_DEFAULT         0x00000000UL                         /* Mode DEFAULT for USART_ROUTE */
#define _USART_ROUTE_LOCATION_LOC1            0x00000001UL                         /* Mode LOC1 for USART_ROUTE */
#define _USART_ROUTE_LOCATION_LOC2            0x00000002UL                         /* Mode LOC2 for USART_ROUTE */
#define _USART_ROUTE_LOCATION_LOC3            0x00000003UL                         /* Mode LOC3 for USART_ROUTE */
#define _USART_ROUTE_LOCATION_LOC4            0x00000004UL                         /* Mode LOC4 for USART_ROUTE */
#define _USART_ROUTE_LOCATION_LOC5            0x00000005UL                         /* Mode LOC5 for USART_ROUTE */
#define USART_ROUTE_LOCATION_LOC0             (_USART_ROUTE_LOCATION_LOC0 << 8)    /* Shifted mode LOC0 for USART_ROUTE */
#define USART_ROUTE_LOCATION_DEFAULT          (_USART_ROUTE_LOCATION_DEFAULT << 8) /* Shifted mode DEFAULT for USART_ROUTE */
#define USART_ROUTE_LOCATION_LOC1             (_USART_ROUTE_LOCATION_LOC1 << 8)    /* Shifted mode LOC1 for USART_ROUTE */
#define USART_ROUTE_LOCATION_LOC2             (_USART_ROUTE_LOCATION_LOC2 << 8)    /* Shifted mode LOC2 for USART_ROUTE */
#define USART_ROUTE_LOCATION_LOC3             (_USART_ROUTE_LOCATION_LOC3 << 8)    /* Shifted mode LOC3 for USART_ROUTE */
#define USART_ROUTE_LOCATION_LOC4             (_USART_ROUTE_LOCATION_LOC4 << 8)    /* Shifted mode LOC4 for USART_ROUTE */
#define USART_ROUTE_LOCATION_LOC5             (_USART_ROUTE_LOCATION_LOC5 << 8)    /* Shifted mode LOC5 for USART_ROUTE */

/* Bit fields for USART INPUT */

#define _USART_INPUT_RESETVALUE               0x00000000UL                         /* Default value for USART_INPUT */
#define _USART_INPUT_MASK                     0x0000001FUL                         /* Mask for USART_INPUT */

#define _USART_INPUT_RXPRSSEL_SHIFT           0                                    /* Shift value for USART_RXPRSSEL */
#define _USART_INPUT_RXPRSSEL_MASK            0xFUL                                /* Bit mask for USART_RXPRSSEL */
#define _USART_INPUT_RXPRSSEL_DEFAULT         0x00000000UL                         /* Mode DEFAULT for USART_INPUT */
#define _USART_INPUT_RXPRSSEL_PRSCH0          0x00000000UL                         /* Mode PRSCH0 for USART_INPUT */
#define _USART_INPUT_RXPRSSEL_PRSCH1          0x00000001UL                         /* Mode PRSCH1 for USART_INPUT */
#define _USART_INPUT_RXPRSSEL_PRSCH2          0x00000002UL                         /* Mode PRSCH2 for USART_INPUT */
#define _USART_INPUT_RXPRSSEL_PRSCH3          0x00000003UL                         /* Mode PRSCH3 for USART_INPUT */
#define _USART_INPUT_RXPRSSEL_PRSCH4          0x00000004UL                         /* Mode PRSCH4 for USART_INPUT */
#define _USART_INPUT_RXPRSSEL_PRSCH5          0x00000005UL                         /* Mode PRSCH5 for USART_INPUT */
#define _USART_INPUT_RXPRSSEL_PRSCH6          0x00000006UL                         /* Mode PRSCH6 for USART_INPUT */
#define _USART_INPUT_RXPRSSEL_PRSCH7          0x00000007UL                         /* Mode PRSCH7 for USART_INPUT */
#define _USART_INPUT_RXPRSSEL_PRSCH8          0x00000008UL                         /* Mode PRSCH8 for USART_INPUT */
#define _USART_INPUT_RXPRSSEL_PRSCH9          0x00000009UL                         /* Mode PRSCH9 for USART_INPUT */
#define _USART_INPUT_RXPRSSEL_PRSCH10         0x0000000AUL                         /* Mode PRSCH10 for USART_INPUT */
#define _USART_INPUT_RXPRSSEL_PRSCH11         0x0000000BUL                         /* Mode PRSCH11 for USART_INPUT */
#define USART_INPUT_RXPRSSEL_DEFAULT          (_USART_INPUT_RXPRSSEL_DEFAULT << 0) /* Shifted mode DEFAULT for USART_INPUT */
#define USART_INPUT_RXPRSSEL_PRSCH0           (_USART_INPUT_RXPRSSEL_PRSCH0 << 0)  /* Shifted mode PRSCH0 for USART_INPUT */
#define USART_INPUT_RXPRSSEL_PRSCH1           (_USART_INPUT_RXPRSSEL_PRSCH1 << 0)  /* Shifted mode PRSCH1 for USART_INPUT */
#define USART_INPUT_RXPRSSEL_PRSCH2           (_USART_INPUT_RXPRSSEL_PRSCH2 << 0)  /* Shifted mode PRSCH2 for USART_INPUT */
#define USART_INPUT_RXPRSSEL_PRSCH3           (_USART_INPUT_RXPRSSEL_PRSCH3 << 0)  /* Shifted mode PRSCH3 for USART_INPUT */
#define USART_INPUT_RXPRSSEL_PRSCH4           (_USART_INPUT_RXPRSSEL_PRSCH4 << 0)  /* Shifted mode PRSCH4 for USART_INPUT */
#define USART_INPUT_RXPRSSEL_PRSCH5           (_USART_INPUT_RXPRSSEL_PRSCH5 << 0)  /* Shifted mode PRSCH5 for USART_INPUT */
#define USART_INPUT_RXPRSSEL_PRSCH6           (_USART_INPUT_RXPRSSEL_PRSCH6 << 0)  /* Shifted mode PRSCH6 for USART_INPUT */
#define USART_INPUT_RXPRSSEL_PRSCH7           (_USART_INPUT_RXPRSSEL_PRSCH7 << 0)  /* Shifted mode PRSCH7 for USART_INPUT */
#define USART_INPUT_RXPRSSEL_PRSCH8           (_USART_INPUT_RXPRSSEL_PRSCH8 << 0)  /* Shifted mode PRSCH8 for USART_INPUT */
#define USART_INPUT_RXPRSSEL_PRSCH9           (_USART_INPUT_RXPRSSEL_PRSCH9 << 0)  /* Shifted mode PRSCH9 for USART_INPUT */
#define USART_INPUT_RXPRSSEL_PRSCH10          (_USART_INPUT_RXPRSSEL_PRSCH10 << 0) /* Shifted mode PRSCH10 for USART_INPUT */
#define USART_INPUT_RXPRSSEL_PRSCH11          (_USART_INPUT_RXPRSSEL_PRSCH11 << 0) /* Shifted mode PRSCH11 for USART_INPUT */
#define USART_INPUT_RXPRS                     (0x1UL << 4)                         /* PRS RX Enable */
#define _USART_INPUT_RXPRS_SHIFT              4                                    /* Shift value for USART_RXPRS */
#define _USART_INPUT_RXPRS_MASK               0x10UL                               /* Bit mask for USART_RXPRS */
#define _USART_INPUT_RXPRS_DEFAULT            0x00000000UL                         /* Mode DEFAULT for USART_INPUT */
#define USART_INPUT_RXPRS_DEFAULT             (_USART_INPUT_RXPRS_DEFAULT << 4)    /* Shifted mode DEFAULT for USART_INPUT */

/* Bit fields for USART I2SCTRL */

#define _USART_I2SCTRL_RESETVALUE             0x00000000UL                           /* Default value for USART_I2SCTRL */
#define _USART_I2SCTRL_MASK                   0x0000071FUL                           /* Mask for USART_I2SCTRL */

#define USART_I2SCTRL_EN                      (0x1UL << 0)                           /* Enable I2S Mode */
#define _USART_I2SCTRL_EN_SHIFT               0                                      /* Shift value for USART_EN */
#define _USART_I2SCTRL_EN_MASK                0x1UL                                  /* Bit mask for USART_EN */
#define _USART_I2SCTRL_EN_DEFAULT             0x00000000UL                           /* Mode DEFAULT for USART_I2SCTRL */
#define USART_I2SCTRL_EN_DEFAULT              (_USART_I2SCTRL_EN_DEFAULT << 0)       /* Shifted mode DEFAULT for USART_I2SCTRL */
#define USART_I2SCTRL_MONO                    (0x1UL << 1)                           /* Stero or Mono */
#define _USART_I2SCTRL_MONO_SHIFT             1                                      /* Shift value for USART_MONO */
#define _USART_I2SCTRL_MONO_MASK              0x2UL                                  /* Bit mask for USART_MONO */
#define _USART_I2SCTRL_MONO_DEFAULT           0x00000000UL                           /* Mode DEFAULT for USART_I2SCTRL */
#define USART_I2SCTRL_MONO_DEFAULT            (_USART_I2SCTRL_MONO_DEFAULT << 1)     /* Shifted mode DEFAULT for USART_I2SCTRL */
#define USART_I2SCTRL_JUSTIFY                 (0x1UL << 2)                           /* Justification of I2S Data */
#define _USART_I2SCTRL_JUSTIFY_SHIFT          2                                      /* Shift value for USART_JUSTIFY */
#define _USART_I2SCTRL_JUSTIFY_MASK           0x4UL                                  /* Bit mask for USART_JUSTIFY */
#define _USART_I2SCTRL_JUSTIFY_DEFAULT        0x00000000UL                           /* Mode DEFAULT for USART_I2SCTRL */
#define _USART_I2SCTRL_JUSTIFY_LEFT           0x00000000UL                           /* Mode LEFT for USART_I2SCTRL */
#define _USART_I2SCTRL_JUSTIFY_RIGHT          0x00000001UL                           /* Mode RIGHT for USART_I2SCTRL */
#define USART_I2SCTRL_JUSTIFY_DEFAULT         (_USART_I2SCTRL_JUSTIFY_DEFAULT << 2)  /* Shifted mode DEFAULT for USART_I2SCTRL */
#define USART_I2SCTRL_JUSTIFY_LEFT            (_USART_I2SCTRL_JUSTIFY_LEFT << 2)     /* Shifted mode LEFT for USART_I2SCTRL */
#define USART_I2SCTRL_JUSTIFY_RIGHT           (_USART_I2SCTRL_JUSTIFY_RIGHT << 2)    /* Shifted mode RIGHT for USART_I2SCTRL */
#define USART_I2SCTRL_DMASPLIT                (0x1UL << 3)                           /* Separate DMA Request For Left/Right Data */
#define _USART_I2SCTRL_DMASPLIT_SHIFT         3                                      /* Shift value for USART_DMASPLIT */
#define _USART_I2SCTRL_DMASPLIT_MASK          0x8UL                                  /* Bit mask for USART_DMASPLIT */
#define _USART_I2SCTRL_DMASPLIT_DEFAULT       0x00000000UL                           /* Mode DEFAULT for USART_I2SCTRL */
#define USART_I2SCTRL_DMASPLIT_DEFAULT        (_USART_I2SCTRL_DMASPLIT_DEFAULT << 3) /* Shifted mode DEFAULT for USART_I2SCTRL */
#define USART_I2SCTRL_DELAY                   (0x1UL << 4)                           /* Delay on I2S data */
#define _USART_I2SCTRL_DELAY_SHIFT            4                                      /* Shift value for USART_DELAY */
#define _USART_I2SCTRL_DELAY_MASK             0x10UL                                 /* Bit mask for USART_DELAY */
#define _USART_I2SCTRL_DELAY_DEFAULT          0x00000000UL                           /* Mode DEFAULT for USART_I2SCTRL */
#define USART_I2SCTRL_DELAY_DEFAULT           (_USART_I2SCTRL_DELAY_DEFAULT << 4)    /* Shifted mode DEFAULT for USART_I2SCTRL */
#define _USART_I2SCTRL_FORMAT_SHIFT           8                                      /* Shift value for USART_FORMAT */
#define _USART_I2SCTRL_FORMAT_MASK            0x700UL                                /* Bit mask for USART_FORMAT */
#define _USART_I2SCTRL_FORMAT_DEFAULT         0x00000000UL                           /* Mode DEFAULT for USART_I2SCTRL */
#define _USART_I2SCTRL_FORMAT_W32D32          0x00000000UL                           /* Mode W32D32 for USART_I2SCTRL */
#define _USART_I2SCTRL_FORMAT_W32D24M         0x00000001UL                           /* Mode W32D24M for USART_I2SCTRL */
#define _USART_I2SCTRL_FORMAT_W32D24          0x00000002UL                           /* Mode W32D24 for USART_I2SCTRL */
#define _USART_I2SCTRL_FORMAT_W32D16          0x00000003UL                           /* Mode W32D16 for USART_I2SCTRL */
#define _USART_I2SCTRL_FORMAT_W32D8           0x00000004UL                           /* Mode W32D8 for USART_I2SCTRL */
#define _USART_I2SCTRL_FORMAT_W16D16          0x00000005UL                           /* Mode W16D16 for USART_I2SCTRL */
#define _USART_I2SCTRL_FORMAT_W16D8           0x00000006UL                           /* Mode W16D8 for USART_I2SCTRL */
#define _USART_I2SCTRL_FORMAT_W8D8            0x00000007UL                           /* Mode W8D8 for USART_I2SCTRL */
#define USART_I2SCTRL_FORMAT_DEFAULT          (_USART_I2SCTRL_FORMAT_DEFAULT << 8)   /* Shifted mode DEFAULT for USART_I2SCTRL */
#define USART_I2SCTRL_FORMAT_W32D32           (_USART_I2SCTRL_FORMAT_W32D32 << 8)    /* Shifted mode W32D32 for USART_I2SCTRL */
#define USART_I2SCTRL_FORMAT_W32D24M          (_USART_I2SCTRL_FORMAT_W32D24M << 8)   /* Shifted mode W32D24M for USART_I2SCTRL */
#define USART_I2SCTRL_FORMAT_W32D24           (_USART_I2SCTRL_FORMAT_W32D24 << 8)    /* Shifted mode W32D24 for USART_I2SCTRL */
#define USART_I2SCTRL_FORMAT_W32D16           (_USART_I2SCTRL_FORMAT_W32D16 << 8)    /* Shifted mode W32D16 for USART_I2SCTRL */
#define USART_I2SCTRL_FORMAT_W32D8            (_USART_I2SCTRL_FORMAT_W32D8 << 8)     /* Shifted mode W32D8 for USART_I2SCTRL */
#define USART_I2SCTRL_FORMAT_W16D16           (_USART_I2SCTRL_FORMAT_W16D16 << 8)    /* Shifted mode W16D16 for USART_I2SCTRL */
#define USART_I2SCTRL_FORMAT_W16D8            (_USART_I2SCTRL_FORMAT_W16D8 << 8)     /* Shifted mode W16D8 for USART_I2SCTRL */
#define USART_I2SCTRL_FORMAT_W8D8             (_USART_I2SCTRL_FORMAT_W8D8 << 8)      /* Shifted mode W8D8 for USART_I2SCTRL */

#endif /* __ARCH_ARM_SRC_EFM32_HARDWARE_EFM32_USART_H */
