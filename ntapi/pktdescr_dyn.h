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
 * This source file contains the NT_DYN dynamic packet descriptor base.\n
 * It is <b>not</b> to be used directly but via the @ref PacketMacros.
 */

#ifndef DOXYGEN_INTERNAL_ONLY

#ifndef __PKT_DESCR_DYN_H__
#define __PKT_DESCR_DYN_H__

// Ensure that the following is packed.
#pragma pack(push, 1)

// NT Dynamic base descriptor
#define _NT_DESCR_DYN_FIELDS                                                                    \
  uint64_t capLength:14;    /*  0: The length of the packet incl. descriptor.                */\
  uint64_t unused0:34;      /* 14: To be used for acceleration fields.                       */\
  uint64_t descrFormat:8;   /* 48: The variable descriptor format.                           */\
  uint64_t descrLength:6;   /* 56: The length of the descriptor in bytes.                    */\
  uint64_t unused1:1;       /* 62: To be used for acceleration fields.                       */\
  uint64_t ntDynDescr:1;    /* 63: Set to 1 to identify this descriptor as a dynamic         */\
                            /*     descriptor.                                               */


typedef struct NtDynDescr_s {
  _NT_DESCR_DYN_FIELDS
} NtDynDescr_t;

// Disable 1-byte packing
#pragma pack(pop)

#define _NT_NET_GET_PKT_DESCR_PTR_DYN(_hNetBuf_)     ((NtDynDescr_t*)(_hNetBuf_)->hHdr)

#define _NT_NET_GET_PKT_DESCR_FORMAT_DYN(_hNetBuf_)  (_NT_NET_GET_PKT_DESCR_PTR_DYN(_hNetBuf_)->descrFormat)
// descrLength == 0 means descriptor length is 64
#define _NT_NET_GET_PKT_DESCR_LENGTH_DYN(_hNetBuf_)  ((64&(_NT_NET_GET_PKT_DESCR_PTR_DYN(_hNetBuf_)->descrLength-1)) + _NT_NET_GET_PKT_DESCR_PTR_DYN(_hNetBuf_)->descrLength)
#define _NT_NET_GET_PKT_CAP_LENGTH_DYN(_hNetBuf_)    (_NT_NET_GET_PKT_DESCR_PTR_DYN(_hNetBuf_)->capLength)
#define _NT_NET_GET_PKT_WIRE_LENGTH_DYN(_hNetBuf_)   (uint16_t)(_NT_NET_GET_PKT_CAP_LENGTH_DYN(_hNetBuf_) - _NT_NET_GET_PKT_DESCR_LENGTH_DYN(_hNetBuf_))

#endif // __PKT_DESCR_VAR_H__
#endif // DOXYGEN_INTERNAL_ONLY
