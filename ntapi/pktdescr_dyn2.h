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
 * This source file contains the NT_DYN2 variable packet descriptor.\n
 */

#ifndef __PKT_DESCR_DYN2_H__
#define __PKT_DESCR_DYN2_H__

/** @addtogroup PacketDescriptorDyn2
 * @{
 *
 * This descriptor offers 3 dynamic offsets, IP protocol field and a 6-bit color field.
 * The packet descriptor is suited for applications doing NetFlow and IDS. This descriptor
 * offers a 38-bit color field, which is useful when identifying billions of flows or
 * alternatively holding the hash value.<br/>
 * Note: The wireLength field has been sacrificed so in case of slicing the
 * original packet length is unknown.
 */

// Ensure that the following is packed.
#pragma pack(push, 1)

/**
 *  @brief NT Variable descriptor 2
 */
typedef struct NtDyn2Descr_s {
  uint64_t capLength:14;    /**< The length of the packet incl. descriptor.                             */ /*  0*/
  uint64_t offset0:10;      /**< Programmable offset into the packet. Default is outer L3.              */ /* 14*/
  uint64_t offset1:10;      /**< Programmable offset into the packet. Default is outer L4.              */ /* 24*/
  uint64_t ipProtocol:8;    /**< Select-able IP protocol. Default is outer IP Protocol field.           */ /* 34*/
  uint64_t rxPort:6;        /**< The port that received the frame.                                      */ /* 42*/
  uint64_t descrFormat:8;   /**< The descriptor type.                                                   */ /* 48*/
  uint64_t descrLength:6;   /**< The length of the descriptor in bytes.                                 */ /* 56*/
  uint64_t tsColor:1;       /**< Timestamp color.                                                       */ /* 62*/
  uint64_t ntDynDescr:1;    /**< Set to 1 to identify this descriptor as a dynamic descriptor.          */ /* 63*/
  uint64_t timestamp;       /**< The time of arrival of the packet.                                     */ /* 64*/
  uint64_t offset2:10;      /**< Programmable offset into the packet. Default is outer L4 payload.      */ /*128*/
  uint64_t color:38;        /**< 24 bit hash and 14 bit traditional color.                              */ /*138*/
} NtDyn2Descr_t; // descrFormat = 2, descrLength = 22

// Disable 1-byte packing
#pragma pack(pop)

#ifndef DOXYGEN_INTERNAL_ONLY
#define _NT_NET_GET_PKT_DESCR_PTR_DYN2(_hNetBuf_)       ((NtDyn2Descr_t*)(_hNetBuf_)->hHdr)
#endif // DOXYGEN_INTERNAL_ONLY

/** @def NT_NET_DESCR_PTR_DYN2
 *  @brief Get a pointer to the packet descriptor
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @return Returns a pointer of type NtDyn2Descr_t*
 *  @hideinitializer
 */
#define NT_NET_DESCR_PTR_DYN2(_hNetBuf_)                ((_NT_NET_GET_PKT_DESCR_PTR_DYN2(_hNetBuf_)->descrFormat==2 ? \
                                                          (NtDyn2Descr_t*)(_hNetBuf_->hHdr) : (NtDyn2Descr_t*)_NT_NET_DESCR_CAST_ASSERT(NULL)))


#ifdef DEBUG
//Guards against misconfigurations
#ifdef _MSC_VER
static void __nt_dyn2_check__(void);
#else
static void __nt_dyn2_check__(void) __attribute__ ((unused));
#endif
static void __nt_dyn2_check__(void) {
  //Compile-time check to avoid sizeof(NtDyn2Descr_t) != 22
#ifdef WIN32
  // Windows will always allocate 3 * 64 bit = 24 bytes
  switch (0) { case 0: case sizeof(NtDyn2Descr_t) == 24:; }
#else
  switch (0) { case 0: case sizeof (NtDyn2Descr_t) == 22: ; }
#endif
}
#endif // DEBUG

/** @} */

#endif // __PKT_DESCR_DYN2_H__

