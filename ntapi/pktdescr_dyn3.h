/*
 *
 * Copyright 2017 Napatech A/S. All Rights Reserved.
 *
 * 1. Copying, modification, and distribution of this file, or executable
 * versions of this file, is governed by the terms of the Napatech Software
 * license agreement under which this file was made available. If you do not
 * agree to the terms of the license do not install, copy, access or
 * otherwise use this file.
 *
 * 2. Under the Napatech Software license agreement you are granted a
 * limited, non-exclusive, non-assignable, copyright license to copy, modify
 * and distribute this file in conjunction with Napatech SmartNIC's and
 * similar hardware manufactured or supplied by Napatech A/S.
 *
 * 3. The full Napatech Software license agreement is included in this
 * distribution, please see "NP-0405 Napatech Software license
 * agreement.pdf"
 *
 * 4. Redistributions of source code must retain this copyright notice,
 * list of conditions and the following disclaimer.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS" WITHOUT ANY WARRANTIES, EXPRESS OR
 * IMPLIED, AND NAPATECH DISCLAIMS ALL IMPLIED WARRANTIES INCLUDING ANY
 * IMPLIED WARRANTY OF TITLE, MERCHANTABILITY, NONINFRINGEMENT, OR OF
 * FITNESS FOR A PARTICULAR PURPOSE. TO THE EXTENT NOT PROHIBITED BY
 * APPLICABLE LAW, IN NO EVENT SHALL NAPATECH BE LIABLE FOR PERSONAL INJURY,
 * OR ANY INCIDENTAL, SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES WHATSOEVER,
 * INCLUDING, WITHOUT LIMITATION, DAMAGES FOR LOSS OF PROFITS, CORRUPTION OR
 * LOSS OF DATA, FAILURE TO TRANSMIT OR RECEIVE ANY DATA OR INFORMATION,
 * BUSINESS INTERRUPTION OR ANY OTHER COMMERCIAL DAMAGES OR LOSSES, ARISING
 * OUT OF OR RELATED TO YOUR USE OR INABILITY TO USE NAPATECH SOFTWARE OR
 * SERVICES OR ANY THIRD PARTY SOFTWARE OR APPLICATIONS IN CONJUNCTION WITH
 * THE NAPATECH SOFTWARE OR SERVICES, HOWEVER CAUSED, REGARDLESS OF THE THEORY
 * OF LIABILITY (CONTRACT, TORT OR OTHERWISE) AND EVEN IF NAPATECH HAS BEEN
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGES. SOME JURISDICTIONS DO NOT ALLOW
 * THE EXCLUSION OR LIMITATION OF LIABILITY FOR PERSONAL INJURY, OR OF
 * INCIDENTAL OR CONSEQUENTIAL DAMAGES, SO THIS LIMITATION MAY NOT APPLY TO YOU.
 *
 *

 */

/**
 * @file
 * This source file contains the NT_DYN3 variable packet descriptor.\n
 */

#ifndef __PKT_DESCR_DYN3_H__
#define __PKT_DESCR_DYN3_H__

/** @addtogroup PacketDescriptorDyn3
 * @{
 *
 * This descriptor is suited for TX and includes the wire length as well as color bits 
 * in the first 8 bytes of the descriptor. This allows SW to reduce the frame size before
 * TX by modifying the wire length and it allows reduction of the descriptor length down
 * to only 8 bytes while retaining the possibility to encode TX flags such as txIgnore in
 * the color. The default values for the dynamic parts are:
 * 
 *    offset0 = outer L3
 *    offset1 = outer L4
 * 
 *    descrFormat = 3
 *    descrLength = 22
 * 
 */

// Ensure that the following is packed.
#pragma pack(push, 1)

/**
 *  @brief NT Variable descriptor 3
 */
typedef struct NtDyn3Descr_s {
  uint64_t capLength:14;    /**< The length of the packet incl. descriptor.                             */ /*  0*/
  uint64_t wireLength:14;   /**< The wire length of the packet.                                         */ /* 14*/
  uint64_t color_lo:14;     /**< Programmable packet color[13:0].                                       */ /* 28*/
  uint64_t rxPort:6;        /**< The port that received the frame.                                      */ /* 42*/
  uint64_t descrFormat:8;   /**< The descriptor type.                                                   */ /* 48*/
  uint64_t descrLength:6;   /**< The length of the descriptor in bytes.                                 */ /* 56*/
  uint64_t tsColor:1;       /**< Timestamp color.                                                       */ /* 62*/
  uint64_t ntDynDescr:1;    /**< Set to 1 to identify this descriptor as a                              */ /* 63*/
                            /**< dynamic descriptor.                                                    */
  uint64_t timestamp;       /**< The time of arrival of the packet.                                     */ /* 64*/
  uint64_t color_hi:28;     /**< Programmable packet color[41:14].                                      */ /*128*/
  uint16_t offset0:10;      /**< Programmable offset into the packet.                                   */ /*156*/
  uint16_t offset1:10;      /**< Programmable offset into the packet.                                   */ /*166*/
} NtDyn3Descr_t; // descrFormat = 3, descrLength = 22

// Disable 1-byte packing
#pragma pack(pop)

#ifndef DOXYGEN_INTERNAL_ONLY
#define _NT_NET_GET_PKT_DESCR_PTR_DYN3(_hNetBuf_)       ((NtDyn3Descr_t*)(_hNetBuf_)->hHdr)
#endif // DOXYGEN_INTERNAL_ONLY

/** @def NT_NET_DESCR_PTR_DYN3
 *  @brief Get a pointer to the packet descriptor
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @return Returns a pointer of type NtDyn3Descr_t*
 *  @hideinitializer
 */
#define NT_NET_DESCR_PTR_DYN3(_hNetBuf_)                ((_NT_NET_GET_PKT_DESCR_PTR_DYN3(_hNetBuf_)->descrFormat==3 ? \
                                                          (NtDyn3Descr_t*)(_hNetBuf_->hHdr) : (NtDyn3Descr_t*)_NT_NET_DESCR_CAST_ASSERT(NULL)))


#ifdef DEBUG
//Guards against misconfigurations
#ifdef _MSC_VER
static void __nt_dyn3_check__(void);
#else
static void __nt_dyn3_check__(void) __attribute__ ((unused));
#endif
static void __nt_dyn3_check__(void) {
  //Compile-time check to avoid sizeof(NtDyn3Descr_t) != 22
#ifndef WIN32
  switch (0) { case 0: case sizeof (NtDyn3Descr_t) == 22: ; }
#endif
}
#endif // DEBUG

/** @} */

#endif // __PKT_DESCR_DYN3_H__

