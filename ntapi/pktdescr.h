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
 * This source file contains the packet macros available.\n
 * See the @ref PacketMacros for details.
 */

#ifndef __PKT_DESCR_H__
#define __PKT_DESCR_H__

#ifndef DOXYGEN_INTERNAL_ONLY

/* In debug mode add assert to all general RX macros */
#ifdef NDEBUG
#define _NT_NET_ASSERT(x) (x)
#define _NT_NET_DESCR_CAST_ASSERT(x) (x)
#else
#define _NT_NET_ASSERT(x) (assert(0 && "macro argument: unsupported descriptor type"), x)
#define _NT_NET_DESCR_CAST_ASSERT(x) (assert(0 && "descriptor cast error."), x)
#endif

#include "pktdescr_std0.h"
#include "pktdescr_ext7.h"
#include "pktdescr_ext8.h"
#include "pktdescr_ext9.h"
#include "pktdescr_dyn.h"
#include "pktdescr_dyn1.h"
#include "pktdescr_dyn2.h"
#include "pktdescr_dyn3.h"

// Ensure that the following is packed.
#pragma pack(push, 1)

typedef union {
  NtStd0Descr_t std0; //!< Standard descriptor v0
  NtExt7Descr_t ext7; //!< Only valid for extended descriptor format 7
  NtExt8Descr_t ext8; //!< Only valid for extended descriptor format 8
  NtExt9Descr_t ext9; //!< Only valid for extended descriptor format 9
} NtPktDescr_t;

// Disable 1-byte packing
#pragma pack(pop)

#endif // DOXYGEN_INTERNAL_ONLY

/** @addtogroup DataMacros
 * @{
 */

/** @defgroup PacketMacros Packet macros
 * @{
 * The following is only possible on packet-based streams.
 *
 * Unless specified otherwise, the NT_NET_GET_PKT_XYZ macros will return
 * integer type values.
 *
 * In debug mode all packet macros contain an assert which asserts
 * that the macros is supported for a given macro. Define the macro
 * NDEBUG to remove the assert or use the build option -DNDEBUG. When
 * the assert is removed the unsupported macros returns -1.
 */

/** @defgroup BasicDescriptorMacros Basic descriptor macros
 * @{
 * The following macros are always available.
 */

/** @def NT_NET_GET_PKT_DESCRIPTOR_TYPE
 *  @brief Get the packet descriptor type.
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @return Returns the packet descriptor type. See @ref NtPacketDescriptorType_e for values.
 *  @hideinitializer
 */
#define NT_NET_GET_PKT_DESCRIPTOR_TYPE(_hNetBuf_)       _NT_NET_GET_PKT_DESCRIPTOR_TYPE(_hNetBuf_)

/** @def NT_NET_GET_PKT_DESCR_PTR
 *  @brief Get packet descriptor pointer
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @return Returns a pointer to the packet descriptor of the received frame.
 *  @hideinitializer
 */
#define NT_NET_GET_PKT_DESCR_PTR(_hNetBuf_)             _NT_NET_GET_PKT_DESCR_PTR(_hNetBuf_)
#if !defined(_NT_NTAPI_NO_COMPAT)
#define NT_NET_GET_PKT_DESCR(_hNetBuf_)                 _NT_NET_GET_PKT_DESCR_PTR(_hNetBuf_)
#endif

/** @def NT_NET_GET_PKT_L2_PTR
 *  @brief A pointer to the L2 packet data. If an ISL header is present it will point to the ISL header.
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @return Returns a void pointer to L2 packet data.
 *  @hideinitializer
 */
#define NT_NET_GET_PKT_L2_PTR(_hNetBuf_)                _NT_NET_GET_PKT_L2_PTR(_hNetBuf_)

/** @def NT_NET_UPDATE_PKT_L2_PTR
 *  @brief When creating packets within a segment it is required to update the L2 pointer using this macro after applying the descriptor info
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @hideinitializer
 */
#define NT_NET_UPDATE_PKT_L2_PTR(_hNetBuf_)             _NT_NET_UPDATE_PKT_L2_PTR(_hNetBuf_)


/** @def NT_NET_GET_PKT_DESCR_LENGTH
 *  @brief Get the length of the packet descriptor
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @return Return the length of the packet descriptor in bytes
 *  @hideinitializer
 */
#define NT_NET_GET_PKT_DESCR_LENGTH(_hNetBuf_)          _NT_NET_GET_PKT_DESCR_LENGTH(_hNetBuf_)

/** @def NT_NET_GET_PKT_DESCRIPTOR_FORMAT
 *  @brief Indicates if extended packet descriptor 7, 8 or 9 is used, if only the
 *  standard packet descriptor is used, or what dynamic packet descriptor type is used.
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @return Returns the packet descriptor format used
 *  @hideinitializer
 */
#define NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)     _NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)

/** @} */

/** @defgroup NtDescriptorMacros NT descriptor macros
 * @{

 * The following is only available if "PacketDescriptor = NT or Ext7 or Ext8 or Ext9" has been selected in the ntservice.ini file
 * and if @ref NT_NET_GET_PKT_DESCRIPTOR_TYPE returns @ref NT_PACKET_DESCRIPTOR_TYPE_NT || @ref NT_PACKET_DESCRIPTOR_TYPE_NT_EXTENDED.
 * The following macros constitute the collection extracting data from the "NT" descriptor.
 */

/** @def NT_NET_GET_PKT_TIMESTAMP
 *  @brief Get the packet timestamp
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @return Returns the time when the packet was captured as an 64bit unsigned value
 *  @hideinitializer
 */
#define NT_NET_GET_PKT_TIMESTAMP(_hNetBuf_)             _NT_NET_GET_PKT_TIMESTAMP(_hNetBuf_)

/** @def NT_NET_GET_PKT_TIMESTAMP_TYPE
 *  @brief Get the packet time stamp type. See @ref NtTimestampType_e
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @return Returns the packet time stamp type. See @ref NtTimestampType_e for values
 *  @hideinitializer
 */
#define NT_NET_GET_PKT_TIMESTAMP_TYPE(_hNetBuf_)        _NT_NET_GET_PKT_TIMESTAMP_TYPE(_hNetBuf_)

/** @def NT_NET_GET_PKT_CAP_LENGTH
 *  @brief Returns the total stored length of the received frame including
 *  packet descriptors, in bytes, after any slicing. The value is always a
 *  multiple of 8, and is rounded up for unsliced frames with wire lengths
 *  that are not multiples of 8 bytes
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @return Returns the total stored length of the received frame
 *  @hideinitializer
 */
#define NT_NET_GET_PKT_CAP_LENGTH(_hNetBuf_)            _NT_NET_GET_PKT_CAP_LENGTH(_hNetBuf_)

/** @def NT_NET_GET_PKT_WIRE_LENGTH
 *  @brief Returns the wire length of the received frame, in bytes, with the
 *  value saturated at 16,383 for longer frames
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @return Returns the packet wire length
 *  @hideinitializer
 */
#define NT_NET_GET_PKT_WIRE_LENGTH(_hNetBuf_)           _NT_NET_GET_PKT_WIRE_LENGTH(_hNetBuf_)

/** @def NT_DESCR_NT_LENGTH
 *  @brief Get length of the NT standard descriptor
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @return Returns the length of the NT standard descriptor
 *  @hideinitializer
 */
#define NT_DESCR_NT_LENGTH    (sizeof(NtStd0Descr_t))

/** @def NT_DESCR_EXT7_LENGTH
 *  @brief Length of the NT Extended 7 descriptor
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @return Returns the length of the NT Extended 7 descriptor
 *  @hideinitializer
 */
#define NT_DESCR_EXT7_LENGTH  (sizeof(NtExt7Descr_t))

/** @def NT_DESCR_EXT8_LENGTH
 *  @brief Length of the NT Extended 8 descriptor
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @return Returns the length of the NT Extended 8 descriptor
 *  @hideinitializer
 */
#define NT_DESCR_EXT8_LENGTH  (sizeof(NtExt8Descr_t))

/** @def NT_DESCR_EXT9_LENGTH
 *  @brief Length of the NT Extended 9 descriptor
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @return Returns the length of the NT Extended 9 descriptor
 *  @hideinitializer
 */
#define NT_DESCR_EXT9_LENGTH  (sizeof(NtExt9Descr_t))

/** @def NT_NET_GET_PKT_CRC_ERROR
 *  @brief Indicates if the received frame has a layer 2 CRC error.
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @return Returns 1 if the packet has a L2 CRC error - If no L2 CRC error this is 0.
 *  @hideinitializer
 */
#define NT_NET_GET_PKT_CRC_ERROR(_hNetBuf_)             _NT_NET_GET_PKT_CRC_ERROR(_hNetBuf_)

/** @def NT_NET_GET_PKT_TCP_CSUM_OK
 *  @brief Indicates if the received TCP checksum is correct
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @return Returns 1 if the packet has a valid TCP checksum - if not a TCP packet this is 0
 *  @hideinitializer
 */
#define NT_NET_GET_PKT_TCP_CSUM_OK(_hNetBuf_)           _NT_NET_GET_PKT_TCP_CSUM_OK(_hNetBuf_)

/** @def NT_NET_GET_PKT_UDP_CSUM_OK
 *  @brief Indicates if the received UDP checksum is correct
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @return Returns 1 if the packet has a valid UDP checksum - if not a UDP packet this is 0
 *  @hideinitializer
 */
#define NT_NET_GET_PKT_UDP_CSUM_OK(_hNetBuf_)           _NT_NET_GET_PKT_UDP_CSUM_OK(_hNetBuf_)

/** @def NT_NET_GET_PKT_IP_CSUM_OK
 *  @brief Indicates if the received IP checksum is correct
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @return Returns 1 if the packet has a valid IP checksum - if not an IP packet this is 0
 *  @hideinitializer
 */
#define NT_NET_GET_PKT_IP_CSUM_OK(_hNetBuf_)            _NT_NET_GET_PKT_IP_CSUM_OK(_hNetBuf_)

/** @def NT_NET_GET_PKT_CV_ERROR
 *  @brief Indicates if the frame has any coding violations errors.
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @return Returns 1 if the packet has coding violations - If no coding violations this is 0.
 *  @hideinitializer
 */
#define NT_NET_GET_PKT_CV_ERROR(_hNetBuf_)              _NT_NET_GET_PKT_CV_ERROR(_hNetBuf_)

/** @def NT_NET_GET_PKT_SLICED
 *  @brief Indicates if the frame has been sliced
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @return Returns 1 if the packet has been sliced - If no slicing has occured this is 0
 *  @hideinitializer
 */
#define NT_NET_GET_PKT_SLICED(_hNetBuf_)                _NT_NET_GET_PKT_SLICED(_hNetBuf_)

/** @def NT_NET_GET_PKT_HARD_SLICED
 *  @brief Indicates if the frame has been hard sliced.
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @return Returns 1 if the packet has been hard sliced - If no hard slicing has occured this is 0
 *  @hideinitializer
 */
#define NT_NET_GET_PKT_HARD_SLICED(_hNetBuf_)           _NT_NET_GET_PKT_HARD_SLICED(_hNetBuf_)

/** @def NT_NET_GET_PKT_RXPORT
 *  @brief Specifies the port number where the frame was received.
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @return Returns the port that received this packet
 *  @hideinitializer
 */
#define NT_NET_GET_PKT_RXPORT(_hNetBuf_)                _NT_NET_GET_PKT_RXPORT(_hNetBuf_)

/** @def NT_NET_GET_PKT_IS_TCP
 *  @brief Indicates if the received frame is a TCP frame.
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @return Returns 1 if the packet has a TCP header - returns 0 if the packet does not have a TCP header
 *  @hideinitializer
 */
#define NT_NET_GET_PKT_IS_TCP(_hNetBuf_)                _NT_NET_GET_PKT_IS_TCP(_hNetBuf_)

/** @def NT_NET_GET_PKT_IS_UDP
 *  @brief Indicates if the received frame is a UDP frame.
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @return Returns 1 if the packet has an UDP header - returns 0 if the packet does not have an UDP header
 *  @hideinitializer
 */
#define NT_NET_GET_PKT_IS_UDP(_hNetBuf_)                _NT_NET_GET_PKT_IS_UDP(_hNetBuf_)

/** @def NT_NET_GET_PKT_IS_IP
 *  @brief Indicates if the received frame is an IP frame
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @return Returns 1 if the packet has an IP header - returns 0 if the packet does not have an IP header
 *  @hideinitializer
 */
#define NT_NET_GET_PKT_IS_IP(_hNetBuf_)                 _NT_NET_GET_PKT_IS_IP(_hNetBuf_)

/** @def NT_NET_GET_PKT_TXPORT
 *  @brief Get TX port
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @return Returns the port number where the frame is to be transmitted.
 *  @hideinitializer
 */
#define NT_NET_GET_PKT_TXPORT(_hNetBuf_)                _NT_NET_GET_PKT_TXPORT(_hNetBuf_)

/** @def NT_NET_GET_PKT_RECALC_L2_CRC
 *  @brief Indicates if the original CRC in the received frame will be recalculated and overwritten in the transmitted frame.
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @return Returns 1 if the packet has L2 CRC recalc/override set - Returns 0 if L2 CRC recalc/override is not set
 *  @hideinitializer
 */
#define NT_NET_GET_PKT_RECALC_L2_CRC(_hNetBuf_)         _NT_NET_GET_PKT_RECALC_L2_CRC(_hNetBuf_)
#if !defined(_NT_NTAPI_NO_COMPAT)
#define NT_NET_GET_PKT_CALC_L2_CRC(_hNetBuf_)           _NT_NET_GET_PKT_RECALC_L2_CRC(_hNetBuf_)
#endif

/** @def NT_NET_GET_PKT_TXNOW
 *  @brief Indicates if the frame is to be transmitted according to time stamp or as fast as possible.
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @return Returns 1 if the packet has TxNow set - Returns 0 if TxNow is not set
 *  @hideinitializer
 */
#define NT_NET_GET_PKT_TXNOW(_hNetBuf_)                 _NT_NET_GET_PKT_TXNOW(_hNetBuf_)

/** @def NT_NET_GET_PKT_TXIGNORE
 *  @brief Indicates if the frame is to be transmitted or not.
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @return Returns 1 if the packet has TxIgnore set - Returns 0 if TxIgnore is not set
 *  @hideinitializer
 */
#define NT_NET_GET_PKT_TXIGNORE(_hNetBuf_)              _NT_NET_GET_PKT_TXIGNORE(_hNetBuf_)

/** @} */

#if !defined(_NTAPI_EXTDESCR_7_) && !defined(_NTAPI_EXTDESCR_8_) && !defined(_NTAPI_EXTDESCR_9_)

/** @defgroup ExtendedNtDescriptorMacros Extended NT descriptor macros
 * @{
 * The following is only available if "PacketDescriptor = Ext7, Ext8 or Ext9" has been set in the ntservice.ini
 * file and if @ref NT_NET_GET_PKT_DESCRIPTOR_TYPE returns @ref NT_PACKET_DESCRIPTOR_TYPE_NT_EXTENDED
 */

/** @def NT_NET_GET_PKT_HASH
 *  @brief Get the packet hash value
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @return Returns the packet hash value. If the hash calculation is invalid, the value is 0x00.
 *  @hideinitializer
 */
#define NT_NET_GET_PKT_HASH(_hNetBuf_)                                  \
  ((_NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==7 ||                  \
    _NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==8 ||                  \
    _NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==9) ?                  \
   _NT_NET_GET_PKT_HASH_EXT7(_hNetBuf_) : _NT_NET_ASSERT(~0))

/** @def NT_NET_GET_PKT_HASH_TYPE
 *  @brief Get the number of the used hash key type
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @return Returns the number of the used hash key type.
 *  @hideinitializer
 */
#define NT_NET_GET_PKT_HASH_TYPE(_hNetBuf_)                             \
  ((_NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==7 ||                  \
    _NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==8 ||                  \
    _NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==9) ?                  \
   _NT_NET_GET_PKT_HASH_TYPE_EXT7(_hNetBuf_) : _NT_NET_ASSERT(~0))

/** @def NT_NET_GET_PKT_HASH_VALID
 *  @brief Indicates if the hash calculation is valid.
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @return Returns 1 if the hash value/type is valid - Returns 0 if the hash value/type is invalid
 *  @hideinitializer
 */
#define NT_NET_GET_PKT_HASH_VALID(_hNetBuf_)                            \
  ((_NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==7 ||                  \
    _NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==8 ||                  \
    _NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==9) ?                  \
   _NT_NET_GET_PKT_HASH_VALID_EXT7(_hNetBuf_) : _NT_NET_ASSERT(~0))

/** @def NT_NET_GET_PKT_JUMBO
 *  @brief Indicates if the frame is a jumbo frame.
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @return Returns 1 if the packet has a jumbo frame - Returns 0 if the packet does not have a jumbo frame
 *  @hideinitializer
 */
#define NT_NET_GET_PKT_JUMBO(_hNetBuf_)                                 \
  ((_NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==7 ||                  \
    _NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==8 ||                  \
    _NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==9) ?                  \
   _NT_NET_GET_PKT_JUMBO_EXT7(_hNetBuf_) : _NT_NET_ASSERT(~0))

/** @def NT_NET_GET_PKT_BROADCAST
 *  @brief Indicates if the destination MAC address is broadcast.
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @return Returns 1 if the destination MAC is a broadcast address - Returns 0 if the destination MAC is not a broadcast address
 *  @hideinitializer
 */
#define NT_NET_GET_PKT_BROADCAST(_hNetBuf_)                             \
  ((_NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==7 ||                  \
    _NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==8 ||                  \
    _NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==9) ?                  \
   _NT_NET_GET_PKT_BROADCAST_EXT7(_hNetBuf_) : _NT_NET_ASSERT(~0))

/** @def NT_NET_GET_PKT_L4_PORT_TYPE
 *  @brief Get the layer 4 port type
 *  When using extended descriptor 9 it is advised to use @ref NT_NET_GET_PKT_TUNNEL_TYPE instead.
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @return Return the layer 4 port type - see @ref NtL4PortType_e for values
 *  @hideinitializer
 */
#define NT_NET_GET_PKT_L4_PORT_TYPE(_hNetBuf_)                          \
  ((_NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==7 ||                  \
    _NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==8) ? _NT_NET_GET_PKT_L4_PORT_TYPE_EXT7(_hNetBuf_) : \
   ((_NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==9) ? _NT_NET_GET_PKT_L4_PORT_TYPE_EXT9(_hNetBuf_) : _NT_NET_ASSERT(~0)))

/** @def NT_NET_GET_PKT_L4_FRAME_TYPE
 *  @brief Get layer 4 frame type
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @return Returns layer 4 frame type - see @ref NtL4FrameType_e for values
 *  @hideinitializer
 */
#define NT_NET_GET_PKT_L4_FRAME_TYPE(_hNetBuf_)                         \
  ((_NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==7 ||                  \
    _NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==8 ||                  \
    _NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==9) ?                  \
   _NT_NET_GET_PKT_L4_FRAME_TYPE_EXT7(_hNetBuf_) : _NT_NET_ASSERT(~0))

/** @def NT_NET_GET_PKT_L3_FRAME_TYPE
 *  @brief Get layer 3 frame type
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @return Returns layer 3 frame type - see @ref NtL3FrameType_e for values
 *  @hideinitializer
 */
#define NT_NET_GET_PKT_L3_FRAME_TYPE(_hNetBuf_)                         \
  ((_NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==7 ||                  \
    _NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==8 ||                  \
    _NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==9) ?                  \
   _NT_NET_GET_PKT_L3_FRAME_TYPE_EXT7(_hNetBuf_) : _NT_NET_ASSERT(~0))

/** @def NT_NET_GET_PKT_L2_FRAME_TYPE
 *  @brief Get layer 2 frame type
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @return Returns layer 2 frame type - see @ref NtL2FrameType_e for values
 *  @hideinitializer
 */
#define NT_NET_GET_PKT_L2_FRAME_TYPE(_hNetBuf_)                         \
  ((_NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==7 ||                  \
    _NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==8 ||                  \
    _NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==9) ?                  \
   _NT_NET_GET_PKT_L2_FRAME_TYPE_EXT7(_hNetBuf_) : _NT_NET_ASSERT(~0))

/** @def NT_NET_GET_PKT_L4_LENGTH
 *  @brief Get layer 4 header length (valid for L4 = UDP/TCP only)
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @return Returns layer 4 header length in units of 32 bits
 *  @hideinitializer
 */
#define NT_NET_GET_PKT_L4_LENGTH(_hNetBuf_)                             \
  ((_NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==7 ||                  \
    _NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==8 ||                  \
    _NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==9) ?                  \
   _NT_NET_GET_PKT_L4_LENGTH_EXT7(_hNetBuf_) : _NT_NET_ASSERT(~0))

/** @def NT_NET_GET_PKT_L3_LENGTH
 *  @brief Get layer 3 header length (valid for L3 = IPv4/IPv6 only)
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @return Returns layer 3 header length in units of 32 bits
 *  @hideinitializer
 */
#define NT_NET_GET_PKT_L3_LENGTH(_hNetBuf_)                             \
  ((_NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==7 ||                  \
    _NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==8 ||                  \
    _NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==9) ?                  \
   _NT_NET_GET_PKT_L3_LENGTH_EXT7(_hNetBuf_) : _NT_NET_ASSERT(~0))

/** @def NT_NET_GET_PKT_MPLS_COUNT
 *  @brief Get the number of MPLS shim labels present
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @return Returns the number of MPLS shim labels present
 *  @hideinitializer
 */
#define NT_NET_GET_PKT_MPLS_COUNT(_hNetBuf_)                            \
  ((_NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==7 ||                  \
    _NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==8 ||                  \
    _NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==9) ?                  \
   _NT_NET_GET_PKT_MPLS_COUNT_EXT7(_hNetBuf_) : _NT_NET_ASSERT(~0))

/** @def NT_NET_GET_PKT_VLAN_COUNT
 *  @brief Get the number of VLANs present
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @return Returns the number of VLANs present
 *  @hideinitializer
 */
#define NT_NET_GET_PKT_VLAN_COUNT(_hNetBuf_)                            \
  ((_NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==7 ||                  \
    _NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==8 ||                  \
    _NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==9) ?                  \
   _NT_NET_GET_PKT_VLAN_COUNT_EXT7(_hNetBuf_) : _NT_NET_ASSERT(~0))

/** @def NT_NET_GET_PKT_ISL
 *  @brief Indicates if ISL encapsulation is present.
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @return Returns 1 if ISL encapsulation is present - Returns 0 if ISL encapsulation is not present
 *  @hideinitializer
 */
#define NT_NET_GET_PKT_ISL(_hNetBuf_)                                   \
  ((_NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==7 ||                  \
    _NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==8 ||                  \
    _NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==9) ?                  \
   _NT_NET_GET_PKT_ISL_EXT7(_hNetBuf_) : _NT_NET_ASSERT(~0))

/** @def NT_NET_GET_PKT_DECODE_ERROR
 *  @brief Indicates if a frame decoding error is present.
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @return Returns 1 if the frame could not be decoded correctly - Returns 0 otherwise
 *  @hideinitializer
 */
#define NT_NET_GET_PKT_DECODE_ERROR(_hNetBuf_)                          \
  ((_NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==7 ||                  \
    _NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==8 ||                  \
    _NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==9) ?                  \
   _NT_NET_GET_PKT_DECODE_ERROR_EXT7(_hNetBuf_) : _NT_NET_ASSERT(~0))
#if !defined(_NT_NTAPI_NO_COMPAT)
#define NT_NET_GET_PKT_PROT_SMALL(_hNetBuf_) NT_NET_GET_PKT_DECODE_ERROR(_hNetBuf_)
#endif


/** @def NT_NET_GET_PKT_FRAME_LARGE
 *  @brief Indicates if the frame is a large frame.
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @return - Returns 1 when FrameSize > MaxFrameSize. MaxFrameSize is set in ntservice.ini. Returns 0 when FrameSize <= MaxFrameSize
 *  @hideinitializer
 */
#define NT_NET_GET_PKT_FRAME_LARGE(_hNetBuf_)                           \
  ((_NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==7 ||                  \
    _NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==8 ||                  \
    _NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==9) ?                  \
   _NT_NET_GET_PKT_FRAME_LARGE_EXT7(_hNetBuf_) : _NT_NET_ASSERT(~0))

/** @def NT_NET_GET_PKT_FRAME_SMALL
 *  @brief Indicates if the frame is a small frame.
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @return Returns 1 when PktSz < 64 (+ISL and/or VLAN) - Returns 0 when PktSz >= 64
 *  @hideinitializer
 */
#define NT_NET_GET_PKT_FRAME_SMALL(_hNetBuf_)                           \
  ((_NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==7 ||                  \
    _NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==8 ||                  \
    _NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==9) ?                  \
   _NT_NET_GET_PKT_FRAME_SMALL_EXT7(_hNetBuf_) : _NT_NET_ASSERT(~0))

/** @def NT_NET_GET_PKT_IPV6_FR_HEADER
 *  @brief Indicates if an IPv6 fragment header is present.
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @return Returns 1 if IPv6 fragment header is present - Returns 0 if no IPv6 fragment header is present
 *  @hideinitializer
 */
#define NT_NET_GET_PKT_IPV6_FR_HEADER(_hNetBuf_)                        \
  ((_NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==7 ||                  \
    _NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==8 ||                  \
    _NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==9) ?                  \
   _NT_NET_GET_PKT_IPV6_FR_HEADER_EXT7(_hNetBuf_) : _NT_NET_ASSERT(~0))

/** @def NT_NET_GET_PKT_IPV6_RT_HEADER
 *  @brief Indicates if an IPv6 routing header is present.
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @return Returns 1 if IPv6 routing header is present - Returns 0 if no IPv6 routing header is present
 *  @hideinitializer
 */
#define NT_NET_GET_PKT_IPV6_RT_HEADER(_hNetBuf_)                        \
  ((_NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==7 ||                  \
    _NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==8 ||                  \
    _NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==9) ?                  \
   _NT_NET_GET_PKT_IPV6_RT_HEADER_EXT7(_hNetBuf_) : _NT_NET_ASSERT(~0))

/** @def NT_NET_GET_PKT_L4_PROTOCOL_NUM
 *  @brief Get layer 4 protocol number (TCP, UDP, SCTP etc.) - if not an IP packet this is 0
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @return Returns the layer 4 protocol number / next header.
 *  @hideinitializer
 */
#define NT_NET_GET_PKT_L4_PROTOCOL_NUM(_hNetBuf_)                       \
  ((_NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==7 ||                  \
    _NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==8 ||                  \
    _NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==9) ?                  \
   _NT_NET_GET_PKT_L4_PROTOCOL_NUM_EXT7(_hNetBuf_) : _NT_NET_ASSERT(~0))

/** @def NT_NET_GET_PKT_L3_FRAGMENTED
 *  @brief Indicates if the packet is part of a layer 3 fragmented datagram. Only valid for IPv4 if more fragments bit = 1 or fragment offset not equal to 0
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @return Returns 1 if fragmented layer 3 - Returns 0 otherwise
 *  @hideinitializer
 */
#define NT_NET_GET_PKT_L3_FRAGMENTED(_hNetBuf_)                         \
  ((_NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==7 ||                  \
    _NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==8 ||                  \
    _NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==9) ?                  \
   _NT_NET_GET_PKT_L3_FRAGMENTED_EXT7(_hNetBuf_) : _NT_NET_ASSERT(~0))

/** @def NT_NET_GET_PKT_L3_FIRST_FRAG
 *  @brief Layer 3 First fragment (offset = 0) Note: Only valid for IPv4 - always set on IPv6 so use IPV6_FR_HEADER instead
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @return Returns 1 if first fragment or not fragmented - Returns 0 otherwise
 *  @hideinitializer
 */
#define NT_NET_GET_PKT_L3_FIRST_FRAG(_hNetBuf_)                         \
  ((_NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==7 ||                  \
    _NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==8 ||                  \
    _NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==9) ?                  \
   _NT_NET_GET_PKT_L3_FIRST_FRAG_EXT7(_hNetBuf_) : _NT_NET_ASSERT(~0))

/** @def NT_NET_GET_PKT_COLOR
 *  @brief Returns the packet color of the frame, if the frame matches a
 *  filter. The color is automatically assigned as a 6bit color ID when the
 *  filter is defined. If the frame matches more than one filter, the packet
 *  color of the frame is the one from the filter with the highest priority.
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @return Returns the color of the packet as an integer value
 *  @hideinitializer
 */
#define NT_NET_GET_PKT_COLOR(_hNetBuf_)                                 \
  ((_NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==7 ||                  \
    _NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==8 ||                  \
    _NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==9) ?                  \
   _NT_NET_GET_PKT_COLOR_EXT7(_hNetBuf_) : _NT_NET_ASSERT(~0))

/** @def NT_NET_GET_PKT_L5_OFFSET
 *  @brief Returns the offset in bytes (0x00 - 0x1FF) from the start of the
 *  frame to the start of layer 5. The value 0x00 indicates an invalid offset.
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @return Returns layer 5 offset as an integer value
 *  @hideinitializer
 */
#define NT_NET_GET_PKT_L5_OFFSET(_hNetBuf_)                             \
  ((_NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==7 ||                  \
    _NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==8 ||                  \
    _NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==9) ?                  \
   _NT_NET_GET_PKT_L5_OFFSET_EXT7(_hNetBuf_) : _NT_NET_ASSERT(~0))

/** @def NT_NET_GET_PKT_L4_OFFSET
 *  @brief Returns the offset in bytes (0x00 - 0x1FF) from the start of the
 *  frame to the start of layer 4. The value 0x00 indicates an invalid offset.
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @return Returns layer 4 offset as an integer value
 *  @hideinitializer
 */
#define NT_NET_GET_PKT_L4_OFFSET(_hNetBuf_)                             \
  ((_NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==7 ||                  \
    _NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==8 ||                  \
    _NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==9) ?                  \
   _NT_NET_GET_PKT_L4_OFFSET_EXT7(_hNetBuf_) : _NT_NET_ASSERT(~0))

/** @def NT_NET_GET_PKT_L3_OFFSET
 *  @brief Returns the offset in bytes (0x00 - 0x1FF) from the start of the
 *  frame to the start of layer 3. The value 0x00 indicates an invalid offset.
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @return Returns layer 3 offset as an integer value
 *  @hideinitializer
 */
#define NT_NET_GET_PKT_L3_OFFSET(_hNetBuf_)                             \
  ((_NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==7 ||                  \
    _NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==8 ||                  \
    _NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==9) ?                  \
   _NT_NET_GET_PKT_L3_OFFSET_EXT7(_hNetBuf_) : _NT_NET_ASSERT(~0))

/** @def NT_NET_GET_PKT_DEDUPLICATION_CRC
 *  @brief The packet deduplication CRC value. Only available on extended descriptor 9.
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @return Returns the 24bit packet deduplication CRC value.
 *  @hideinitializer
 */
#define NT_NET_GET_PKT_DEDUPLICATION_CRC(_hNetBuf_)                     \
  ((_NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==9) ?                  \
   _NT_NET_GET_PKT_DEDUPLICATION_CRC_EXT9(_hNetBuf_) : _NT_NET_ASSERT(~0))

/** @} */

/** @defgroup ExtendedNtDescriptorIPFMacros Extended NT descriptor IPF macros
 * @{
 * The following are used to help collect IP fragmented data. With theses
 * macros it is possible to de-fragment IP fragmented data in a
 * multi-processing application using 5-tuple hashing. It is only available if
 * "PacketDescriptor" in the ntservice.ini file has been set to "Ext8" or
 * "Ext9" and if @ref NT_NET_GET_PKT_DESCRIPTOR_TYPE returns @ref
 * NT_PACKET_DESCRIPTOR_TYPE_NT_EXTENDED @note: These macros do not return
 * valid values if the IPF engine is not turned on see @ref NtplIPFMode
 */

/** @def NT_NET_GET_PKT_IPF_UNMATCHED_STREAMID
 *  @brief Stream ID where unmatched fragments are stored
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @return Returns the stream ID where unmatched fragments are stored
 *  @hideinitializer
 */
#define NT_NET_GET_PKT_IPF_UNMATCHED_STREAMID(_hNetBuf_)                \
  ((_NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==8 ||                  \
    _NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==9) ?                  \
   _NT_NET_GET_PKT_IPF_UNMATCHED_STREAMID_EXT8(_hNetBuf_) : _NT_NET_ASSERT(~0))

/** @def NT_NET_GET_PKT_IPF_UNMATCHED_FLAG
 *  @brief Indicates if no entry corresponding to the packet was allocated or
 *  found in the datagram lookup table.
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @return Returns 1 if unmatched - Returns 0 otherwise
 *  @hideinitializer
 */
#define NT_NET_GET_PKT_IPF_UNMATCHED_FLAG(_hNetBuf_)                    \
  ((_NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==8 ||                  \
    _NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==9) ?                  \
   _NT_NET_GET_PKT_IPF_UNMATCHED_FLAG_EXT8(_hNetBuf_) : _NT_NET_ASSERT(~0))

/** @def NT_NET_GET_PKT_IPF_LAST_FRAGMENT
 *  @brief Indicates if the packet is the last fragment of a layer 3
 *  fragmented datagram. (More fragment bit = 0 && offset != 0)
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @return Returns 1 if last fragment - Returns 0 otherwise
 *  @hideinitializer
 */
#define NT_NET_GET_PKT_IPF_LAST_FRAGMENT(_hNetBuf_)                     \
  ((_NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==8 ||                  \
    _NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==9) ?                  \
   _NT_NET_GET_PKT_IPF_LAST_FRAGMENT_EXT8(_hNetBuf_) : _NT_NET_ASSERT(~0))

/** @} */

/** @defgroup ExtendedNtDescriptorTunnelMacros Extended NT descriptor Tunneling macros
 * @{
 *
 * The following are used to help accessing GTPv1 and IP-in-IP tunneled
 * data. With theses macros it is possible to determine the tunnel type,
 * retrieve the frame types and get direct offsets to the layers 3, 4 and 5
 * inside the tunnel. Only the first tunnel is decoded, hence a tunnel inside
 * a tunnel is not decoded. The following macros are only available if
 * "PacketDescriptor" in the ntservice.ini file has been set to "Ext9" or if
 * "Ext9" is configured as the descriptor type in the NTPL "assign" statement
 * matching the received packet.
 */

/** @def NT_NET_GET_PKT_INNER_L3_OFFSET
 *  @brief Returns the offset in bytes (0x00 - 0x1FF) from the start of the
 *  frame to the start of inner layer 3. The value 0x00 indicates an invalid
 *  offset.
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @return Returns inner layer 3 offset as an integer value
 *  @hideinitializer
 */
#define NT_NET_GET_PKT_INNER_L3_OFFSET(_hNetBuf_)                       \
  ((_NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==9) ?                  \
   _NT_NET_GET_PKT_INNER_L3_OFFSET_EXT9(_hNetBuf_) : _NT_NET_ASSERT(~0))

/** @def NT_NET_GET_PKT_INNER_L4_OFFSET
 *  @brief Returns the offset in bytes (0x00 - 0x1FF) from the start of the
 *  frame to the start of inner layer 4. The value 0x00 indicates an invalid
 *  offset.
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @return Returns inner layer 4 offset as an integer value
 *  @hideinitializer
 */
#define NT_NET_GET_PKT_INNER_L4_OFFSET(_hNetBuf_)                       \
  ((_NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==9) ?                  \
   _NT_NET_GET_PKT_INNER_L4_OFFSET_EXT9(_hNetBuf_) : _NT_NET_ASSERT(~0))

/** @def NT_NET_GET_PKT_INNER_L5_OFFSET
 *  @brief Returns the offset in bytes (0x00 - 0x1FF) from the start of the
 *  frame to the start of inner layer 5. The value 0x00 indicates an invalid
 *  offset.
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @return Returns inner layer 5 offset as an integer value
 *  @hideinitializer
 */
#define NT_NET_GET_PKT_INNER_L5_OFFSET(_hNetBuf_)                       \
  ((_NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==9) ?                  \
   _NT_NET_GET_PKT_INNER_L5_OFFSET_EXT9(_hNetBuf_) : _NT_NET_ASSERT(~0))

/** @def NT_NET_GET_PKT_INNER_L3_FRAME_TYPE
 *  @brief Get the inner tunnel layer 3 frame type
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @return Returns the inner tunnel layer 3 frame type - see @ref NtL3FrameType_e for values
 *  @hideinitializer
 */
#define NT_NET_GET_PKT_INNER_L3_FRAME_TYPE(_hNetBuf_)                   \
  ((_NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==9) ?                  \
   _NT_NET_GET_PKT_INNER_L3_FRAME_TYPE_EXT9(_hNetBuf_) : _NT_NET_ASSERT(~0))

/** @def NT_NET_GET_PKT_INNER_L4_FRAME_TYPE
 *  @brief Get the inner tunnel layer 4 frame type
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @return Returns the inner tunnel layer 4 frame type - see @ref NtL4FrameType_e for values
 *  @hideinitializer
 */
#define NT_NET_GET_PKT_INNER_L4_FRAME_TYPE(_hNetBuf_)                   \
  ((_NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==9) ?                  \
   _NT_NET_GET_PKT_INNER_L4_FRAME_TYPE_EXT9(_hNetBuf_) : _NT_NET_ASSERT(~0))

/** @def NT_NET_GET_PKT_INNER_L3_FRAGMENT_TYPE
 *  @brief Get inner layer 3 fragment type
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @return Returns inner layer 3 fragment type - see @ref NtL3FragmentType_e for values
 *  @hideinitializer
 */
#define NT_NET_GET_PKT_INNER_L3_FRAGMENT_TYPE(_hNetBuf_)                \
  ((_NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==9) ?                  \
   _NT_NET_GET_PKT_INNER_L3_FRAGMENT_TYPE_EXT9(_hNetBuf_) : _NT_NET_ASSERT(~0))

/** @def NT_NET_GET_PKT_TUNNEL_TYPE
 *  @brief Get the tunnel type
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @return Returns the tunnel type - see @ref NtTunnelType_e for values
 *  @hideinitializer
 */
#define NT_NET_GET_PKT_TUNNEL_TYPE(_hNetBuf_)                           \
  ((_NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==9) ?                  \
   _NT_NET_GET_PKT_TUNNEL_TYPE_EXT9(_hNetBuf_) : _NT_NET_ASSERT(~0))

/** @def NT_NET_GET_PKT_TUNNEL_HDR_LENGTH
 *  @brief Get the tunnel header length
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @return Returns the tunnel header length in units of 32 bits
 *  @hideinitializer
 */
#define NT_NET_GET_PKT_TUNNEL_HDR_LENGTH(_hNetBuf_)                     \
  ((_NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==9) ?                  \
   _NT_NET_GET_PKT_TUNNEL_HDR_LENGTH_EXT9(_hNetBuf_) : _NT_NET_ASSERT(~0))

/** @def NT_NET_GET_PKT_INNER_DECODE_ERROR
 *  @brief Indicates if a inner tunnel frame decoding error is present.
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @return Returns 1 if the inner tunnel frame could not be decoded correctly - Returns 0 otherwise
 *  @hideinitializer
 */
#define NT_NET_GET_PKT_INNER_DECODE_ERROR(_hNetBuf_)                    \
  ((_NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==9) ?                  \
   _NT_NET_GET_PKT_INNER_DECODE_ERROR_EXT9(_hNetBuf_) : _NT_NET_ASSERT(~0))

/** @} */

#endif /* !defined(_NTAPI_EXTDESCR_7_) && !defined(_NTAPI_EXTDESCR_8_) && !defined(_NTAPI_EXTDESCR_9_) */

/** @defgroup TxMacros TX macros
 * @{
 * The following can only be used on TX or in-line based streams
 *
 */

/** @def NT_NET_SET_PKT_CLEAR_DESCR_NT
 *  @brief Clears the NT descriptor
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @hideinitializer
 */
#define NT_NET_SET_PKT_CLEAR_DESCR_NT(_hNetBuf_)       do{ memset((_hNetBuf_)->hHdr, 0, sizeof(NtStd0Descr_t)); } while(0)

/** @def NT_NET_SET_PKT_DESCR_TYPE_NT
 *  @brief Sets the packet descriptor type to NT
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @hideinitializer
 */
#define NT_NET_SET_PKT_DESCR_TYPE_NT(_hNetBuf_)        do{ _NT_NET_GET_PKT_DESCR_PTR_STD0(_hNetBuf_)->descriptorType = 1; } while(0)

/** @def NT_NET_SET_PKT_CLEAR_DESCR_EXT7
 *  @brief Clears the EXT7 descriptor
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @hideinitializer
 */
#define NT_NET_SET_PKT_CLEAR_DESCR_EXT7(_hNetBuf_)     do{ memset((_hNetBuf_)->hHdr, 0, sizeof(NtExt7Descr_t)); } while(0)

/** @def NT_NET_SET_PKT_DESCR_TYPE_EXT7
 *  @brief Sets the packet descriptor type to EXT7
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @hideinitializer
 */
#ifndef DOXYGEN_INTERNAL_ONLY
#define NT_EXTENDED_DESCRIPTOR_07_LENGTH 2
#define NT_EXTENDED_DESCRIPTOR_07_TYPE   7
#endif // DOXYGEN_INTERNAL_ONLY
#define NT_NET_SET_PKT_DESCR_TYPE_EXT7(_hNetBuf_) \
  do{ _NT_NET_GET_PKT_DESCR_PTR_STD0(_hNetBuf_)->descriptorType = 1;    \
    _NT_NET_GET_PKT_DESCR_PTR_STD0(_hNetBuf_)->extensionFormat = NT_EXTENDED_DESCRIPTOR_07_TYPE; \
    _NT_NET_GET_PKT_DESCR_PTR_STD0(_hNetBuf_)->extensionLength = NT_EXTENDED_DESCRIPTOR_07_LENGTH; } while(0)

/** @def NT_NET_SET_PKT_CLEAR_DESCR_EXT8
 *  @brief Clears the EXT8 descriptor
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @hideinitializer
 */
#define NT_NET_SET_PKT_CLEAR_DESCR_EXT8(_hNetBuf_)     do{ memset((_hNetBuf_)->hHdr, 0, sizeof(NtExt8Descr_t)); } while(0)

/** @def NT_NET_SET_PKT_DESCR_TYPE_EXT8
 *  @brief Sets the packet descriptor type to EXT8
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @hideinitializer
 */
#ifndef DOXYGEN_INTERNAL_ONLY
#define NT_EXTENDED_DESCRIPTOR_08_LENGTH 2
#define NT_EXTENDED_DESCRIPTOR_08_TYPE   8
#endif // DOXYGEN_INTERNAL_ONLY
#define NT_NET_SET_PKT_DESCR_TYPE_EXT8(_hNetBuf_) \
  do{ _NT_NET_GET_PKT_DESCR_PTR_STD0(_hNetBuf_)->descriptorType = 1;    \
    _NT_NET_GET_PKT_DESCR_PTR_STD0(_hNetBuf_)->extensionFormat = NT_EXTENDED_DESCRIPTOR_08_TYPE; \
    _NT_NET_GET_PKT_DESCR_PTR_STD0(_hNetBuf_)->extensionLength = NT_EXTENDED_DESCRIPTOR_08_LENGTH; } while(0)

/** @def NT_NET_SET_PKT_CLEAR_DESCR_EXT9
 *  @brief Clears the EXT9 descriptor
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @hideinitializer
 */
#define NT_NET_SET_PKT_CLEAR_DESCR_EXT9(_hNetBuf_)     do{ memset((_hNetBuf_)->hHdr, 0, sizeof(NtExt9Descr_t)); } while(0)

/** @def NT_NET_SET_PKT_DESCR_TYPE_EXT9
 *  @brief Sets the packet descriptor type to EXT9
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @hideinitializer
 */
#ifndef DOXYGEN_INTERNAL_ONLY
#define NT_EXTENDED_DESCRIPTOR_09_LENGTH 3
#define NT_EXTENDED_DESCRIPTOR_09_TYPE   9
#endif // DOXYGEN_INTERNAL_ONLY
#define NT_NET_SET_PKT_DESCR_TYPE_EXT9(_hNetBuf_) \
  do{ _NT_NET_GET_PKT_DESCR_PTR_STD0(_hNetBuf_)->descriptorType = 1;    \
    _NT_NET_GET_PKT_DESCR_PTR_STD0(_hNetBuf_)->extensionFormat = NT_EXTENDED_DESCRIPTOR_09_TYPE; \
    _NT_NET_GET_PKT_DESCR_PTR_STD0(_hNetBuf_)->extensionLength = NT_EXTENDED_DESCRIPTOR_09_LENGTH; } while(0)

/** @def NT_NET_SET_PKT_CAP_LENGTH
 *  @brief Calculates and sets the packet capture length. Input is wire length. Capture length is calculated from the value.
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @param[in] "_Length_" The length value
 *  @hideinitializer
 */
#define NT_NET_SET_PKT_CAP_LENGTH(_hNetBuf_, _Length_)   _NT_NET_SET_PKT_CAP_LENGTH(_hNetBuf_, _Length_)

/** @def NT_NET_SET_PKT_CAP_LENGTH_NOALIGN
 *  @brief Calculates and sets the packet capture length. Input is wire length. Capture length is calculated from the value - no alignment is applied
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @param[in] "_Length_" The length value
 *  @hideinitializer
 */
#define NT_NET_SET_PKT_CAP_LENGTH_NOALIGN(_hNetBuf_, _Length_)   _NT_NET_SET_PKT_CAP_LENGTH_NOALIGN(_hNetBuf_, _Length_)

/** @def NT_NET_SET_PKT_WIRE_LENGTH
 *  @brief Sets the packet wire length
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @param[in] "_Length_" The length value
 *  @hideinitializer
 */
#define NT_NET_SET_PKT_WIRE_LENGTH(_hNetBuf_, _Length_)  _NT_NET_SET_PKT_WIRE_LENGTH(_hNetBuf_, _Length_)

/** @def NT_NET_SET_PKT_RECALC_L2_CRC
 *  @brief Asks the adapter to re-generate the CRC
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @param[in] "_bval_" Set to 1 if CRC should be re-generated, 0 otherwise
 *  @hideinitializer
 */
#define NT_NET_SET_PKT_RECALC_L2_CRC(_hNetBuf_, _bval_)  _NT_NET_SET_PKT_RECALC_L2_CRC(_hNetBuf_, _bval_)
#if !defined(_NT_NTAPI_NO_COMPAT)
#define NT_NET_SET_PKT_CALC_L2_CRC(_hNetBuf_, _bval_)    NT_NET_SET_PKT_RECALC_L2_CRC(_hNetBuf_, _bval_)
#endif

/** @def NT_NET_SET_PKT_TIMESTAMP
 *  @brief Sets the packet time stamp - useful when controlling the traffic rate
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @param[in] "_ts_" The timestamp value in 10ns resolution NATIVE format
 *  @hideinitializer
 */
#define NT_NET_SET_PKT_TIMESTAMP(_hNetBuf_, _ts_)      _NT_NET_SET_PKT_TIMESTAMP(_hNetBuf_, _ts_)

/** @def NT_NET_SET_PKT_TXNOW
 *  @brief If set the IPG is ignored - this will result in line rate TX
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @param[in] "_bval_" Set to 1 if line rate, 0 otherwise
 *  @hideinitializer
 */
#define NT_NET_SET_PKT_TXNOW(_hNetBuf_, _bval_)        _NT_NET_SET_PKT_TXNOW(_hNetBuf_, _bval_)

/** @def NT_NET_SET_PKT_TXSETCLOCK
 *  @brief Sets the FPGA transmission clock equal to the time stamp of this packet
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @param[in] "_bval_" Set to 1 if the FPGA transmission clock should equal to the time stamp of this packet, 0 otherwise
 *  @hideinitializer
 */
#define NT_NET_SET_PKT_TXSETCLOCK(_hNetBuf_, _bval_)   _NT_NET_SET_PKT_TXSETCLOCK(_hNetBuf_, _bval_)

/** @def NT_NET_SET_PKT_TXIGNORE
 *  @brief Marks the packet not to be sent - useful in in-line scenarios where some packets should not be retransmitted
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @param[in] "_bval_" Set to 1 to not transmit the packet, 0 otherwise
 *  @hideinitializer
 */
#define NT_NET_SET_PKT_TXIGNORE(_hNetBuf_, _bval_)     _NT_NET_SET_PKT_TXIGNORE(_hNetBuf_, _bval_)

/** @def NT_NET_SET_PKT_IS_IP
 *  @brief Sets if the packet is IP
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @param[in] "_bval_" Set to 1 if IP packet, 0 otherwise
 *  @hideinitializer
 */
#define NT_NET_SET_PKT_IS_IP(_hNetBuf_, _bval_)        _NT_NET_SET_PKT_IS_IP(_hNetBuf_, _bval_)

/** @def NT_NET_SET_PKT_IS_UDP
 *  @brief Sets if the packet is UDP
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @param[in] "_bval_" Set to 1 if UDP packet, 0 otherwise
 *  @hideinitializer
 */
#define NT_NET_SET_PKT_IS_UDP(_hNetBuf_, _bval_)       _NT_NET_SET_PKT_IS_UDP(_hNetBuf_, _bval_)

/** @def NT_NET_SET_PKT_IS_TCP
 *  @brief Sets if the packet is TCP
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @param[in] "_bval_" Set to 1 if TCP packet, 0 otherwise
 *  @hideinitializer
 */
#define NT_NET_SET_PKT_IS_TCP(_hNetBuf_, _bval_)       _NT_NET_SET_PKT_IS_TCP(_hNetBuf_, _bval_)

/** @def NT_NET_SET_PKT_CRC_ERROR
 *  @brief Sets if the packet has a CRC error
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @param[in] "_bval_" Set to 1 if packet has a CRC error, 0 otherwise
 *  @hideinitializer
 */
#define NT_NET_SET_PKT_CRC_ERROR(_hNetBuf_, _bval_)    _NT_NET_SET_PKT_CRC_ERROR(_hNetBuf_, _bval_)

/** @def NT_NET_SET_PKT_IP_CSUM_OK
 *  @brief Sets if the packet has an OK IP checksum
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @param[in] "_bval_" Set to 1 if packet packet has an OK IP checksum, 0 otherwise
 *  @hideinitializer
 */
#define NT_NET_SET_PKT_IP_CSUM_OK(_hNetBuf_, _bval_)   _NT_NET_SET_PKT_IP_CSUM_OK(_hNetBuf_, _bval_)

/** @def NT_NET_SET_PKT_TCP_CSUM_OK
 *  @brief Sets if the packet has an OK TCP checksum
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @param[in] "_bval_" Set to 1 if packet packet has an OK TCP checksum, 0 otherwise
 *  @hideinitializer
 */
#define NT_NET_SET_PKT_TCP_CSUM_OK(_hNetBuf_, _bval_)  _NT_NET_SET_PKT_TCP_CSUM_OK(_hNetBuf_, _bval_)

/** @def NT_NET_SET_PKT_UDP_CSUM_OK
 *  @brief Sets if the packet has an OK UDP checksum
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @param[in] "_bval_" Set to 1 if packet packet has an OK UDP checksum, 0 otherwise
 *  @hideinitializer
 */
#define NT_NET_SET_PKT_UDP_CSUM_OK(_hNetBuf_, _bval_)  _NT_NET_SET_PKT_UDP_CSUM_OK(_hNetBuf_, _bval_)

/** @def NT_NET_SET_PKT_TXPORT
 *  @brief Sets the packet port where the packets should be transmitted @note This feature only works on the CaptureReplay profile and the TX port can only be within the range of one adapter
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @param[in] "_Port_" Port number
 *  @hideinitializer
 */
#define NT_NET_SET_PKT_TXPORT(_hNetBuf_, _Port_)        _NT_NET_SET_PKT_TXPORT(_hNetBuf_, _Port_)

#if !defined(_NTAPI_EXTDESCR_7_) && !defined(_NTAPI_EXTDESCR_8_) && !defined(_NTAPI_EXTDESCR_9_)

/** @defgroup ExtendedTxMacros Extended TX macros
 * @{
 * The following can only be used if the TX buffer has an extended NT descriptor
 */

/** @def NT_NET_SET_PKT_INJECT_TIMESTAMP
 *  @brief Injects a time stamp on TX
 *
 *  The time stamp is injected into the payload at the offset
 *  provided. Offset range: 0-512. See @ref TimeStampInject "Time
 *  Stamp Injection" for further information
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @param[in] "_offset_" Offset to inject timestamp at
 *  @hideinitializer
 */
#define NT_NET_SET_PKT_INJECT_TIMESTAMP(_hNetBuf_, _offset_)            \
    do { if(_NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==7 ||          \
            _NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==8 ||          \
            _NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==9)            \
           _NT_NET_SET_PKT_INJECT_TIMESTAMP_EXT7(_hNetBuf_, _offset_);  \
         else assert(0); } while(0)

/** @def NT_NET_SET_PKT_ISL
 *  @brief Sets if the frame is ISL encapsulated
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @param[in] "_bval_" Set 1 if ISL encapsulated, 0 otherwise
 *  @hideinitializer
 */
#define NT_NET_SET_PKT_ISL(_hNetBuf_, _bval_)                           \
    do { if(_NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==7 ||          \
            _NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==8 ||          \
            _NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==9)            \
           _NT_NET_SET_PKT_ISL_EXT7(_hNetBuf_, _bval_);                 \
         else assert(0); } while(0)

/** @def NT_NET_SET_PKT_VLAN_COUNT
 *  @brief Sets the number of VLAN tags
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @param[in] "_count_" The VLAN tag count
 *  @hideinitializer
 */
#define NT_NET_SET_PKT_VLAN_COUNT(_hNetBuf_, _count_)                   \
  do { if(_NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==7 ||            \
          _NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==8 ||            \
          _NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==9)              \
         _NT_NET_SET_PKT_VLAN_COUNT_EXT7(_hNetBuf_, _count_);           \
       else assert(0); } while(0)

/** @def NT_NET_SET_PKT_MPLS_COUNT
 *  @brief Sets the number of MPLS shim labels
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @param[in] "_count_" The MPLS shim labels count
 *  @hideinitializer
 */
#define NT_NET_SET_PKT_MPLS_COUNT(_hNetBuf_, _count_)                   \
  do { if(_NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==7 ||            \
          _NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==8 ||            \
          _NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==9)              \
         _NT_NET_SET_PKT_MPLS_COUNT_EXT7(_hNetBuf_, _count_);           \
       else assert(0); } while(0)

/** @def NT_NET_SET_PKT_L2_FRAME_TYPE
 *  @brief Sets the L2 frame type, see @ref NtL2FrameType_e
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @param[in] "_type_" The L2 frame type
 *  @hideinitializer
 */
#define NT_NET_SET_PKT_L2_FRAME_TYPE(_hNetBuf_, _type_)                 \
  do { if(_NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==7 ||            \
          _NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==8 ||            \
          _NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==9)              \
         _NT_NET_SET_PKT_L2_FRAME_TYPE_EXT7(_hNetBuf_, _type_);         \
       else assert(0); } while(0)

/** @def NT_NET_SET_PKT_L3_FRAME_TYPE
 *  @brief Sets the L3 frame type, see @ref NtL3FrameType_e
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @param[in] "_type_" The L3 frame type
 *  @hideinitializer
 */
#define NT_NET_SET_PKT_L3_FRAME_TYPE(_hNetBuf_, _type_)                 \
  do { if(_NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==7 ||            \
          _NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==8 ||            \
          _NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==9)              \
         _NT_NET_SET_PKT_L3_FRAME_TYPE_EXT7(_hNetBuf_, _type_);         \
       else assert(0); } while(0)

/** @def NT_NET_SET_PKT_L4_FRAME_TYPE
 *  @brief Sets the L4 frame type, see @ref NtL4FrameType_e
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @param[in] "_type_" The L4 frame type
 *  @hideinitializer
 */
#define NT_NET_SET_PKT_L4_FRAME_TYPE(_hNetBuf_, _type_)                 \
  do { if(_NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==7 ||            \
          _NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==8 ||            \
          _NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==9)              \
         _NT_NET_SET_PKT_L4_FRAME_TYPE_EXT7(_hNetBuf_, _type_);         \
       else assert(0); } while(0)

/** @def NT_NET_SET_PKT_L3_LENGTH
 *  @brief L3 length in 32-bit units
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @param[in] "_u32len_" The L3 length in 32-bit units
 *  @hideinitializer
 */
#define NT_NET_SET_PKT_L3_LENGTH(_hNetBuf_, _u32len_)                   \
  do { if(_NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==7 ||            \
          _NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==8 ||            \
          _NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==9)              \
         _NT_NET_SET_PKT_L3_LENGTH_EXT7(_hNetBuf_, _u32len_);           \
       else assert(0); } while(0)

/** @def NT_NET_SET_PKT_L4_LENGTH
 *  @brief L4 length in 32-bit units
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @param[in] "_u32len_" The L4 length in 32-bit units
 *  @hideinitializer
 */
#define NT_NET_SET_PKT_L4_LENGTH(_hNetBuf_, _u32len_)                   \
  do { if(_NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==7 ||            \
          _NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==8 ||            \
          _NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==9)              \
         _NT_NET_SET_PKT_L4_LENGTH_EXT7(_hNetBuf_, _u32len_);           \
       else assert(0); } while(0)

/** @def NT_NET_SET_PKT_CALC_L3_CHECKSUM
 *  @brief If set, the adapter will calculate an IPv4 checksum on transmit
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @param[in] "_bval_" Set to 1 calculate an IPv4 checksum on transmit, 0 otherwise
 *  @hideinitializer
 */
#define NT_NET_SET_PKT_CALC_L3_CHECKSUM(_hNetBuf_, _bval_)              \
  do { if(_NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==7 ||            \
          _NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==8 ||            \
          _NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==9)              \
         _NT_NET_SET_PKT_CALC_L3_CHECKSUM_EXT7(_hNetBuf_, _bval_);      \
       else assert(0); } while(0)

/** @def NT_NET_SET_PKT_CALC_L4_CHECKSUM
 *  @brief If set, the adapter will calculate an TCP/UDP checksum on transmit
 *  @param[in] "_hNetBuf_" Packet container reference
 *  @param[in] "_bval_" Set to 1 calculate an TCP/UDP checksum on transmit, 0 otherwise
 *  @hideinitializer
 */
#define NT_NET_SET_PKT_CALC_L4_CHECKSUM(_hNetBuf_, _bval_)              \
  do { if(_NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==7 ||            \
          _NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==8 ||            \
          _NT_NET_GET_PKT_DESCRIPTOR_FORMAT(_hNetBuf_)==9)              \
         _NT_NET_SET_PKT_CALC_L4_CHECKSUM_EXT7(_hNetBuf_, _bval_);      \
       else assert(0); } while(0)

#if !defined(_NT_NTAPI_NO_COMPAT)
#define NT_NET_SET_PKT_L3_OFFSET(_hNetBuf_, _offset_)
#define NT_NET_SET_PKT_L4_OFFSET(_hNetBuf_, _offset_)
#endif

/** @} */

#endif /* !defined(_NTAPI_EXTDESCR_7_) && !defined(_NTAPI_EXTDESCR_8_) && !defined(_NTAPI_EXTDESCR_9_) */

/** @} */
/** @} */
/** @} */

#endif /* __PKT_DESCR_H__ */
