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
 * This source file contains the Ext9 packet descriptor.\n
 * It is <b>not</b> to be used directly but via the @ref PacketMacros.
 */

#ifndef DOXYGEN_INTERNAL_ONLY

#ifndef __PKT_DESCR_EXT9_H__
#define __PKT_DESCR_EXT9_H__

// Ensure that the following is packed.
#pragma pack(push, 1)

// Extended descriptor 9 RX
#define _NT_DESCR_EXT9_RX_FIELDS                                                           \
  /* 32bit Word0. */                                                                       \
  uint32_t hash:24;               /* 23:00 - Hash value */                                 \
  uint32_t hashType:5;            /* 28:24 - Hash type */                                  \
  uint32_t innerL3FragmentType:2; /* 30:29 - inner IP frame fragment type */               \
  uint32_t hashValid:1;           /*    31 - Hash valid */                                 \
  /* 32bit Word1. */                                                                       \
  uint32_t jumbo:1;               /*    00 - Jumbo frame */                                \
  uint32_t broadcastDest:1;       /*    01 - Destination MAC address is broadcast */       \
  uint32_t tunnelType:4;          /* 05:02 - Tunnel type */                                \
  uint32_t l4FrameType:4;         /* 09:06 - Layer4 frame type */                          \
  uint32_t l3FrameType:3;         /* 12:10 - Layer3 type */                                \
  uint32_t l2FrameType:2;         /* 14:13 - Layer2 type */                                \
  uint32_t l4Size:4;              /* 18:15 - Layer4 header length (in units of 32 bits) */ \
  uint32_t l3Size:7;              /* 25:19 - Layer3 header length (in units of 32 bits) */ \
  uint32_t mplsCount:3;           /* 28:26 - Number of MPLS shim labels present */         \
  uint32_t vlanCount:2;           /* 30:29 - Number of VLANs present */                    \
  uint32_t islPresent:1;          /*    31 - ISL encapsulation present */                  \
  /* 32bit Word2. */                                                                       \
  uint32_t l3UnmatchedFragFeed:8; /* 07:00 - feed where unmatched fragments are stored */  \
  uint32_t tunnelHdrSize:3;       /* 10:08 - Tunnel header size (in units of 32 bits) */   \
  uint32_t Reserved1:1;           /*    11 - Reserved */                                   \
  uint32_t l3UnmatchedFragFlag:1; /*    12 - L3 Unmatched fragment flag - requires IPF */  \
  uint32_t l3LastFragment:1;      /*    13 - L3 Last Fragment flag */                      \
  uint32_t Reserved2:3;           /* 16:14 - Reserved */                                   \
  uint32_t decodeError:1;         /*    17 - Decode error in Frame. Was "prot. small" */   \
  uint32_t frameLarge:1;          /*    18 - Large frame */                                \
  uint32_t frameSmall:1;          /*    19 - Small frame */                                \
  uint32_t ipv6FragmentHeader:1;  /*    20 - IPv6 fragment header present */               \
  uint32_t ipv6RoutingHeader:1;   /*    21 - IPv6 routing header present */                \
  uint32_t l4ProtocolNumber:8;    /* 29:22 - Layer 4 protocol number */                    \
  uint32_t l3Fragmented:1;        /*    30 - L3 fragmented frame */                        \
  uint32_t l3FirstFragment:1;     /*    31 - L3 First fragment */                          \
  /* 32bit Word3. */                                                                       \
  uint32_t color:6;               /* 05:00 - Color */                                      \
  uint32_t innerDecodeError:1;    /*    06 - Inner decode error */                         \
  uint32_t l5Offset:9;            /* 15:07 - Offset to layer 5 */                          \
  uint32_t l4Offset:9;            /* 24:16 - Offset to layer 4 */                          \
  uint32_t l3Offset:7;            /* 31:25 - Offset to layer 3 */                          \
  /* 32bit Word4. */                                                                       \
  uint32_t dedupCrc:24;           /* 23:00 - Deduplication CRC */                          \
  uint32_t Reserved3:8;           /* 31:24 - Reserved */                                   \
  /* 32bit Word5. */                                                                       \
  uint32_t innerL3Offset:9;       /* 08:00 - Inner offset to layer 3 */                    \
  uint32_t innerL4Offset:9;       /* 17:09 - Inner offset to layer 4 */                    \
  uint32_t innerL5Offset:9;       /* 26:18 - Inner offset to layer 5 */                    \
  uint32_t innerL4FrameType:3;    /* 29:27 - Inner layer 4 frame type */                   \
  uint32_t innerL3FrameType:2;    /* 31:30 - Inner layer 3 frame type */

// Extended descriptor 9 TX
#define _NT_DESCR_EXT9_TX_FIELDS                                                           \
  /* 32bit Word0. */                                                                       \
  uint32_t Unused0:32;            /* 31:00 - Unused */                                     \
  /* 32bit Word1. */                                                                       \
  uint32_t Unused1:6;             /* 05:00 - Unused */                                     \
  uint32_t l4FrameType:4;         /* 09:06 - Layer4 frame type */                          \
  uint32_t l3FrameType:3;         /* 12:10 - Layer3 type */                                \
  uint32_t l2FrameType:2;         /* 14:13 - Layer2 type */                                \
  uint32_t l4Size:4;              /* 18:15 - Layer4 header length (in units of 32 bits) */ \
  uint32_t l3Size:7;              /* 25:19 - Layer3 header length (in units of 32 bits) */ \
  uint32_t mplsCount:3;           /* 28:26 - Number of MPLS shim labels present */         \
  uint32_t vlanCount:2;           /* 30:29 - Number of VLANs present */                    \
  uint32_t islPresent:1;          /*    31 - ISL encapsulation present */                  \
  /* 32bit Word2. */                                                                       \
  uint32_t Unused2:14;            /* 13:00 - Unused */                                     \
  uint32_t txTsInject:1;          /*    14 - Inject TX time stamp */                       \
  uint32_t calcUDPTCPChecksum:1;  /*    15 - Recalculate the UDP/TCP checksum */           \
  uint32_t calcIPChecksum:1;      /*    16 - Recalculate the IP checksum */                \
  uint32_t Unused3:15;            /* 31:17 - Unused */                                     \
  /* 32bit Word3. */                                                                       \
  uint32_t Unused4:7;             /* 06:00 - Unused */                                     \
  uint32_t txTsInjectOffset:9;    /* 15:07 - 15:07 - TX time stamp inject offset */        \
  uint32_t Unused5:16;            /* 31:16 - Unused */                                     \
  /* 32bit Word4. */                                                                       \
  uint32_t Unused6;               /* 31:00 - Unused */                                     \
  /* 32bit Word5. */                                                                       \
  uint32_t Unused7;               /* 31:00 - Unused */

typedef struct NtExt9DescrRx_s {
  _NT_DESCR_STD0_FIELDS
  _NT_DESCR_EXT9_RX_FIELDS
} NtExt9DescrRx_t;

typedef struct NtExt9DescrTx_s {
  _NT_DESCR_STD0_FIELDS
  _NT_DESCR_EXT9_TX_FIELDS
} NtExt9DescrTx_t;

typedef union {
  NtExt9DescrRx_t rx;
  NtExt9DescrTx_t tx;
} NtExt9Descr_t;

// Disable 1-byte packing
#pragma pack(pop)

#define _NT_NET_GET_PKT_DESCR_PTR_EXT9(_hNetBuf_)       ((NtExt9Descr_t*)(_hNetBuf_)->hHdr)

// RX
#define _NT_NET_GET_PKT_HASH_EXT9(_hNetBuf_)                   (_NT_NET_GET_PKT_DESCR_PTR_EXT9(_hNetBuf_)->rx.hash)
#define _NT_NET_GET_PKT_HASH_TYPE_EXT9(_hNetBuf_)              (_NT_NET_GET_PKT_DESCR_PTR_EXT9(_hNetBuf_)->rx.hashType)
#define _NT_NET_GET_PKT_HASH_VALID_EXT9(_hNetBuf_)             (_NT_NET_GET_PKT_DESCR_PTR_EXT9(_hNetBuf_)->rx.hashValid)
#define _NT_NET_GET_PKT_JUMBO_EXT9(_hNetBuf_)                  (_NT_NET_GET_PKT_DESCR_PTR_EXT9(_hNetBuf_)->rx.jumbo)
#define _NT_NET_GET_PKT_BROADCAST_EXT9(_hNetBuf_)              (_NT_NET_GET_PKT_DESCR_PTR_EXT9(_hNetBuf_)->rx.broadcastDest)
#define _NT_NET_GET_PKT_L4_PORT_TYPE_EXT9(_hNetBuf_)                    \
  ((_NT_NET_GET_PKT_DESCR_PTR_EXT9(_hNetBuf_)->rx.tunnelType < 3) ?     \
   (_NT_NET_GET_PKT_DESCR_PTR_EXT9(_hNetBuf_)->rx.tunnelType) :         \
   (((_NT_NET_GET_PKT_DESCR_PTR_EXT9(_hNetBuf_)->rx.tunnelType) == 3 || \
     (_NT_NET_GET_PKT_DESCR_PTR_EXT9(_hNetBuf_)->rx.tunnelType) == 4) ? 3 : 0))
#define _NT_NET_GET_PKT_L4_FRAME_TYPE_EXT9(_hNetBuf_)          (_NT_NET_GET_PKT_DESCR_PTR_EXT9(_hNetBuf_)->rx.l4FrameType)
#define _NT_NET_GET_PKT_L3_FRAME_TYPE_EXT9(_hNetBuf_)          (_NT_NET_GET_PKT_DESCR_PTR_EXT9(_hNetBuf_)->rx.l3FrameType)
#define _NT_NET_GET_PKT_L2_FRAME_TYPE_EXT9(_hNetBuf_)          (_NT_NET_GET_PKT_DESCR_PTR_EXT9(_hNetBuf_)->rx.l2FrameType)
#define _NT_NET_GET_PKT_L4_LENGTH_EXT9(_hNetBuf_)              (_NT_NET_GET_PKT_DESCR_PTR_EXT9(_hNetBuf_)->rx.l4Size)
#define _NT_NET_GET_PKT_L3_LENGTH_EXT9(_hNetBuf_)              (_NT_NET_GET_PKT_DESCR_PTR_EXT9(_hNetBuf_)->rx.l3Size)
#define _NT_NET_GET_PKT_MPLS_COUNT_EXT9(_hNetBuf_)             (_NT_NET_GET_PKT_DESCR_PTR_EXT9(_hNetBuf_)->rx.mplsCount)
#define _NT_NET_GET_PKT_VLAN_COUNT_EXT9(_hNetBuf_)             (_NT_NET_GET_PKT_DESCR_PTR_EXT9(_hNetBuf_)->rx.vlanCount)
#define _NT_NET_GET_PKT_ISL_EXT9(_hNetBuf_)                    (_NT_NET_GET_PKT_DESCR_PTR_EXT9(_hNetBuf_)->rx.islPresent)
#define _NT_NET_GET_PKT_DECODE_ERROR_EXT9(_hNetBuf_)           (_NT_NET_GET_PKT_DESCR_PTR_EXT9(_hNetBuf_)->rx.decodeError)
#define _NT_NET_GET_PKT_FRAME_LARGE_EXT9(_hNetBuf_)            (_NT_NET_GET_PKT_DESCR_PTR_EXT9(_hNetBuf_)->rx.frameLarge)
#define _NT_NET_GET_PKT_FRAME_SMALL_EXT9(_hNetBuf_)            (_NT_NET_GET_PKT_DESCR_PTR_EXT9(_hNetBuf_)->rx.frameSmall)
#define _NT_NET_GET_PKT_IPV6_FR_HEADER_EXT9(_hNetBuf_)         (_NT_NET_GET_PKT_DESCR_PTR_EXT9(_hNetBuf_)->rx.ipv6FragmentHeader)
#define _NT_NET_GET_PKT_IPV6_RT_HEADER_EXT9(_hNetBuf_)         (_NT_NET_GET_PKT_DESCR_PTR_EXT9(_hNetBuf_)->rx.ipv6RoutingHeader)
#define _NT_NET_GET_PKT_L4_PROTOCOL_NUM_EXT9(_hNetBuf_)        (_NT_NET_GET_PKT_DESCR_PTR_EXT9(_hNetBuf_)->rx.l4ProtocolNumber)
#define _NT_NET_GET_PKT_L3_FRAGMENTED_EXT9(_hNetBuf_)          (_NT_NET_GET_PKT_DESCR_PTR_EXT9(_hNetBuf_)->rx.l3Fragmented)
#define _NT_NET_GET_PKT_L3_FIRST_FRAG_EXT9(_hNetBuf_)          (_NT_NET_GET_PKT_DESCR_PTR_EXT9(_hNetBuf_)->rx.l3FirstFragment)
#define _NT_NET_GET_PKT_COLOR_EXT9(_hNetBuf_)                  ((_hNetBuf_)->colorMap[_NT_NET_GET_PKT_DESCR_PTR_EXT9(_hNetBuf_)->rx.color])
#define _NT_NET_GET_PKT_L5_OFFSET_EXT9(_hNetBuf_)              (_NT_NET_GET_PKT_DESCR_PTR_EXT9(_hNetBuf_)->rx.l5Offset)
#define _NT_NET_GET_PKT_L4_OFFSET_EXT9(_hNetBuf_)              (_NT_NET_GET_PKT_DESCR_PTR_EXT9(_hNetBuf_)->rx.l4Offset)
#define _NT_NET_GET_PKT_L3_OFFSET_EXT9(_hNetBuf_)              (_NT_NET_GET_PKT_DESCR_PTR_EXT9(_hNetBuf_)->rx.l3Offset)

// Introduced in descriptor 8
#define _NT_NET_GET_PKT_IPF_UNMATCHED_STREAMID_EXT9(_hNetBuf_) \
  ((_hNetBuf_)->streamInfo[(_NT_NET_GET_PKT_DESCR_PTR_EXT9(_hNetBuf_)->rx.l3UnmatchedFragFeed<<_FEED2STREAM_SHL_)+(_hNetBuf_)->adapterNo])
#define _NT_NET_GET_PKT_IPF_UNMATCHED_FLAG_EXT9(_hNetBuf_)     (_NT_NET_GET_PKT_DESCR_PTR_EXT9(_hNetBuf_)->rx.l3UnmatchedFragFlag)
#define _NT_NET_GET_PKT_IPF_LAST_FRAGMENT_EXT9(_hNetBuf_)      (_NT_NET_GET_PKT_DESCR_PTR_EXT9(_hNetBuf_)->rx.l3LastFragment)

// Introduced in descriptor 9
#define _NT_NET_GET_PKT_INNER_L3_OFFSET_EXT9(_hNetBuf_)        (_NT_NET_GET_PKT_DESCR_PTR_EXT9(_hNetBuf_)->rx.innerL3Offset)
#define _NT_NET_GET_PKT_INNER_L4_OFFSET_EXT9(_hNetBuf_)        (_NT_NET_GET_PKT_DESCR_PTR_EXT9(_hNetBuf_)->rx.innerL4Offset)
#define _NT_NET_GET_PKT_INNER_L5_OFFSET_EXT9(_hNetBuf_)        (_NT_NET_GET_PKT_DESCR_PTR_EXT9(_hNetBuf_)->rx.innerL5Offset)
#define _NT_NET_GET_PKT_INNER_L3_FRAME_TYPE_EXT9(_hNetBuf_)    (_NT_NET_GET_PKT_DESCR_PTR_EXT9(_hNetBuf_)->rx.innerL3FrameType)
#define _NT_NET_GET_PKT_INNER_L4_FRAME_TYPE_EXT9(_hNetBuf_)    (_NT_NET_GET_PKT_DESCR_PTR_EXT9(_hNetBuf_)->rx.innerL4FrameType)
#define _NT_NET_GET_PKT_INNER_L3_FRAGMENT_TYPE_EXT9(_hNetBuf_) (_NT_NET_GET_PKT_DESCR_PTR_EXT9(_hNetBuf_)->rx.innerL3FragmentType)
#define _NT_NET_GET_PKT_TUNNEL_TYPE_EXT9(_hNetBuf_)            (_NT_NET_GET_PKT_DESCR_PTR_EXT9(_hNetBuf_)->rx.tunnelType)
#define _NT_NET_GET_PKT_TUNNEL_HDR_LENGTH_EXT9(_hNetBuf_)      (_NT_NET_GET_PKT_DESCR_PTR_EXT9(_hNetBuf_)->rx.tunnelHdrSize)
#define _NT_NET_GET_PKT_INNER_DECODE_ERROR_EXT9(_hNetBuf_)     (_NT_NET_GET_PKT_DESCR_PTR_EXT9(_hNetBuf_)->rx.innerDecodeError)
#define _NT_NET_GET_PKT_DEDUPLICATION_CRC_EXT9(_hNetBuf_)      (_NT_NET_GET_PKT_DESCR_PTR_EXT9(_hNetBuf_)->rx.dedupCrc)

// TX
#define _NT_NET_SET_PKT_INJECT_TIMESTAMP_EXT9(_hNetBuf_, _offset_) do{_NT_NET_GET_PKT_DESCR_PTR_EXT9(_hNetBuf_)->tx.txTsInject=1; \
    _NT_NET_GET_PKT_DESCR_PTR_EXT9(_hNetBuf_)->tx.txTsInjectOffset=(_offset_);}while(0)
#define _NT_NET_SET_PKT_ISL_EXT9(_hNetBuf_, _bval_)                do{_NT_NET_GET_PKT_DESCR_PTR_EXT9(_hNetBuf_)->tx.islPresent=(_bval_);}while(0)
#define _NT_NET_SET_PKT_VLAN_COUNT_EXT9(_hNetBuf_, _count_)        do{_NT_NET_GET_PKT_DESCR_PTR_EXT9(_hNetBuf_)->tx.vlanCount=(_count_);}while(0)
#define _NT_NET_SET_PKT_MPLS_COUNT_EXT9(_hNetBuf_, _count_)        do{_NT_NET_GET_PKT_DESCR_PTR_EXT9(_hNetBuf_)->tx.mplsCount=(_count_);}while(0)
#define _NT_NET_SET_PKT_L2_FRAME_TYPE_EXT9(_hNetBuf_, _type_)      do{_NT_NET_GET_PKT_DESCR_PTR_EXT9(_hNetBuf_)->tx.l2FrameType=(_type_);}while(0)
#define _NT_NET_SET_PKT_L3_FRAME_TYPE_EXT9(_hNetBuf_, _type_)      do{_NT_NET_GET_PKT_DESCR_PTR_EXT9(_hNetBuf_)->tx.l3FrameType=(_type_);}while(0)
#define _NT_NET_SET_PKT_L4_FRAME_TYPE_EXT9(_hNetBuf_, _type_)      do{_NT_NET_GET_PKT_DESCR_PTR_EXT9(_hNetBuf_)->tx.l4FrameType=(_type_);}while(0)
#define _NT_NET_SET_PKT_L3_LENGTH_EXT9(_hNetBuf_, _u32len_)        do{_NT_NET_GET_PKT_DESCR_PTR_EXT9(_hNetBuf_)->tx.l3Size=(_u32len_);}while(0)
#define _NT_NET_SET_PKT_L4_LENGTH_EXT9(_hNetBuf_, _u32len_)        do{_NT_NET_GET_PKT_DESCR_PTR_EXT9(_hNetBuf_)->tx.l4Size=(_u32len_);}while(0)
#define _NT_NET_SET_PKT_CALC_L3_CHECKSUM_EXT9(_hNetBuf_, _bval_)   do{_NT_NET_GET_PKT_DESCR_PTR_EXT9(_hNetBuf_)->tx.calcIPChecksum=(_bval_);}while(0)
#define _NT_NET_SET_PKT_CALC_L4_CHECKSUM_EXT9(_hNetBuf_, _bval_)   do{_NT_NET_GET_PKT_DESCR_PTR_EXT9(_hNetBuf_)->tx.calcUDPTCPChecksum=(_bval_);}while(0)

#if defined(_NTAPI_EXTDESCR_9_)
#define NT_NET_GET_PKT_HASH(_hNetBuf_)                   _NT_NET_GET_PKT_HASH_EXT9(_hNetBuf_)
#define NT_NET_GET_PKT_HASH_TYPE(_hNetBuf_)              _NT_NET_GET_PKT_HASH_TYPE_EXT9(_hNetBuf_)
#define NT_NET_GET_PKT_HASH_VALID(_hNetBuf_)             _NT_NET_GET_PKT_HASH_VALID_EXT9(_hNetBuf_)
#define NT_NET_GET_PKT_JUMBO(_hNetBuf_)                  _NT_NET_GET_PKT_JUMBO_EXT9(_hNetBuf_)
#define NT_NET_GET_PKT_BROADCAST(_hNetBuf_)              _NT_NET_GET_PKT_BROADCAST_EXT9(_hNetBuf_)
#define NT_NET_GET_PKT_L4_PORT_TYPE(_hNetBuf_)           _NT_NET_GET_PKT_L4_PORT_TYPE_EXT9(_hNetBuf_)
#define NT_NET_GET_PKT_L4_FRAME_TYPE(_hNetBuf_)          _NT_NET_GET_PKT_L4_FRAME_TYPE_EXT9(_hNetBuf_)
#define NT_NET_GET_PKT_L3_FRAME_TYPE(_hNetBuf_)          _NT_NET_GET_PKT_L3_FRAME_TYPE_EXT9(_hNetBuf_)
#define NT_NET_GET_PKT_L2_FRAME_TYPE(_hNetBuf_)          _NT_NET_GET_PKT_L2_FRAME_TYPE_EXT9(_hNetBuf_)
#define NT_NET_GET_PKT_L4_LENGTH(_hNetBuf_)              _NT_NET_GET_PKT_L4_LENGTH_EXT9(_hNetBuf_)
#define NT_NET_GET_PKT_L3_LENGTH(_hNetBuf_)              _NT_NET_GET_PKT_L3_LENGTH_EXT9(_hNetBuf_)
#define NT_NET_GET_PKT_MPLS_COUNT(_hNetBuf_)             _NT_NET_GET_PKT_MPLS_COUNT_EXT9(_hNetBuf_)
#define NT_NET_GET_PKT_VLAN_COUNT(_hNetBuf_)             _NT_NET_GET_PKT_VLAN_COUNT_EXT9(_hNetBuf_)
#define NT_NET_GET_PKT_ISL(_hNetBuf_)                    _NT_NET_GET_PKT_ISL_EXT9(_hNetBuf_)
#define NT_NET_GET_PKT_DECODE_ERROR(_hNetBuf_)           _NT_NET_GET_PKT_DECODE_ERROR_EXT9(_hNetBuf_)
#define NT_NET_GET_PKT_PROT_SMALL(_hNetBuf_)             _NT_NET_GET_PKT_DECODE_ERROR_EXT9(_hNetBuf_) // Deprecated - use NT_NET_GET_PKT_DECODE_ERROR
#define NT_NET_GET_PKT_FRAME_LARGE(_hNetBuf_)            _NT_NET_GET_PKT_FRAME_LARGE_EXT9(_hNetBuf_)
#define NT_NET_GET_PKT_FRAME_SMALL(_hNetBuf_)            _NT_NET_GET_PKT_FRAME_SMALL_EXT9(_hNetBuf_)
#define NT_NET_GET_PKT_IPV6_FR_HEADER(_hNetBuf_)         _NT_NET_GET_PKT_IPV6_FR_HEADER_EXT9(_hNetBuf_)
#define NT_NET_GET_PKT_IPV6_RT_HEADER(_hNetBuf_)         _NT_NET_GET_PKT_IPV6_RT_HEADER_EXT9(_hNetBuf_)
#define NT_NET_GET_PKT_L4_PROTOCOL_NUM(_hNetBuf_)        _NT_NET_GET_PKT_L4_PROTOCOL_NUM_EXT9(_hNetBuf_)
#define NT_NET_GET_PKT_L3_FRAGMENTED(_hNetBuf_)          _NT_NET_GET_PKT_L3_FRAGMENTED_EXT9(_hNetBuf_)
#define NT_NET_GET_PKT_L3_FIRST_FRAG(_hNetBuf_)          _NT_NET_GET_PKT_L3_FIRST_FRAG_EXT9(_hNetBuf_)
#define NT_NET_GET_PKT_COLOR(_hNetBuf_)                  _NT_NET_GET_PKT_COLOR_EXT9(_hNetBuf_)
#define NT_NET_GET_PKT_L5_OFFSET(_hNetBuf_)              _NT_NET_GET_PKT_L5_OFFSET_EXT9(_hNetBuf_)
#define NT_NET_GET_PKT_L4_OFFSET(_hNetBuf_)              _NT_NET_GET_PKT_L4_OFFSET_EXT9(_hNetBuf_)
#define NT_NET_GET_PKT_L3_OFFSET(_hNetBuf_)              _NT_NET_GET_PKT_L3_OFFSET_EXT9(_hNetBuf_)

#define NT_NET_GET_PKT_IPF_UNMATCHED_STREAMID(_hNetBuf_) _NT_NET_GET_PKT_IPF_UNMATCHED_STREAMID_EXT9(_hNetBuf_)
#define NT_NET_GET_PKT_IPF_UNMATCHED_FLAG(_hNetBuf_)     _NT_NET_GET_PKT_IPF_UNMATCHED_FLAG_EXT9(_hNetBuf_)
#define NT_NET_GET_PKT_IPF_LAST_FRAGMENT(_hNetBuf_)      _NT_NET_GET_PKT_IPF_LAST_FRAGMENT_EXT9(_hNetBuf_)

#define NT_NET_GET_PKT_INNER_L3_OFFSET(_hNetBuf_)        _NT_NET_GET_PKT_INNER_L3_OFFSET_EXT9(_hNetBuf_)
#define NT_NET_GET_PKT_INNER_L4_OFFSET(_hNetBuf_)        _NT_NET_GET_PKT_INNER_L4_OFFSET_EXT9(_hNetBuf_)
#define NT_NET_GET_PKT_INNER_L5_OFFSET(_hNetBuf_)        _NT_NET_GET_PKT_INNER_L5_OFFSET_EXT9(_hNetBuf_)
#define NT_NET_GET_PKT_INNER_L3_FRAME_TYPE(_hNetBuf_)    _NT_NET_GET_PKT_INNER_L3_FRAME_TYPE_EXT9(_hNetBuf_)
#define NT_NET_GET_PKT_INNER_L4_FRAME_TYPE(_hNetBuf_)    _NT_NET_GET_PKT_INNER_L4_FRAME_TYPE_EXT9(_hNetBuf_)
#define NT_NET_GET_PKT_INNER_L3_FRAGMENT_TYPE(_hNetBuf_) _NT_NET_GET_PKT_INNER_L3_FRAGMENT_TYPE_EXT9(_hNetBuf_)
#define NT_NET_GET_PKT_TUNNEL_TYPE(_hNetBuf_)            _NT_NET_GET_PKT_TUNNEL_TYPE_EXT9(_hNetBuf_)
#define NT_NET_GET_PKT_TUNNEL_HDR_LENGTH(_hNetBuf_)      _NT_NET_GET_PKT_TUNNEL_HDR_LENGTH_EXT9(_hNetBuf_)
#define NT_NET_GET_PKT_INNER_DECODE_ERROR(_hNetBuf_)     _NT_NET_GET_PKT_INNER_DECODE_ERROR_EXT9(_hNetBuf_)
#define NT_NET_GET_PKT_DEDUPLICATION_CRC(_hNetBuf_)      _NT_NET_GET_PKT_DEDUPLICATION_CRC_EXT9(_hNetBuf_)

#define NT_NET_SET_PKT_INJECT_TIMESTAMP(_hNetBuf_, _offset_) _NT_NET_SET_PKT_INJECT_TIMESTAMP_EXT9(_hNetBuf_, _offset_)
#define NT_NET_SET_PKT_ISL(_hNetBuf_, _bval_)                _NT_NET_SET_PKT_ISL_EXT9(_hNetBuf_, _bval_)
#define NT_NET_SET_PKT_VLAN_COUNT(_hNetBuf_, _count_)        _NT_NET_SET_PKT_VLAN_COUNT_EXT9(_hNetBuf_, _count_)
#define NT_NET_SET_PKT_MPLS_COUNT(_hNetBuf_, _count_)        _NT_NET_SET_PKT_MPLS_COUNT_EXT9(_hNetBuf_, _count_)
#define NT_NET_SET_PKT_L2_FRAME_TYPE(_hNetBuf_, _type_)      _NT_NET_SET_PKT_L2_FRAME_TYPE_EXT9(_hNetBuf_, _type_)
#define NT_NET_SET_PKT_L3_FRAME_TYPE(_hNetBuf_, _type_)      _NT_NET_SET_PKT_L3_FRAME_TYPE_EXT9(_hNetBuf_, _type_)
#define NT_NET_SET_PKT_L4_FRAME_TYPE(_hNetBuf_, _type_)      _NT_NET_SET_PKT_L4_FRAME_TYPE_EXT9(_hNetBuf_, _type_)
#define NT_NET_SET_PKT_L3_LENGTH(_hNetBuf_, _u32len_)        _NT_NET_SET_PKT_L3_LENGTH_EXT9(_hNetBuf_, _u32len_)
#define NT_NET_SET_PKT_L4_LENGTH(_hNetBuf_, _u32len_)        _NT_NET_SET_PKT_L4_LENGTH_EXT9(_hNetBuf_, _u32len_)
#define NT_NET_SET_PKT_CALC_L3_CHECKSUM(_hNetBuf_, _bval_)   _NT_NET_SET_PKT_CALC_L3_CHECKSUM_EXT9(_hNetBuf_, _bval_)
#define NT_NET_SET_PKT_CALC_L4_CHECKSUM(_hNetBuf_, _bval_)   _NT_NET_SET_PKT_CALC_L4_CHECKSUM_EXT9(_hNetBuf_, _bval_)
#if !defined(_NT_NTAPI_NO_COMPAT)
#define NT_NET_SET_PKT_L3_OFFSET(_hNetBuf_, _offset_)
#define NT_NET_SET_PKT_L4_OFFSET(_hNetBuf_, _offset_)
#endif
#endif

#endif /* __PKT_DESCR_EXT9_H__ */

#endif // DOXYGEN_INTERNAL_ONLY
