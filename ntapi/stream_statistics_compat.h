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
 *
 * This is the header file of the statistics stream interface containing
 * included for backward compatibility structures.
 *
 */

#ifndef __STREAM_STATISTICS_COMPAT_H__
#define __STREAM_STATISTICS_COMPAT_H__

#if !defined(_NT_NTAPI_NO_COMPAT)

/********************************************************************************/
/*       Statistics data defines for NT_STATISTICS_READ_CMD_QUERY               */
/********************************************************************************/
#define NT_STATISTICS_READ_CMD_QUERY  NT_STATISTICS_READ_CMD_COMPAT_0

/**
 * Statistics for each port
 */
struct NtPortStatistics_s {
  /**
   * Valid indicators. These indicate which counters are supported by the port.
   */
  struct NtPortStatisticsValid_s {
    int RMON1;   //!< Is set if RMON1 counters are supported
    int extRMON; //!< Is set if extended RMON counters are supported
    int chksum;  //!< Is set if IP/TCP/UDP checksum counters are supported
    int decode;  //!< Is set if packet decode counters are supported
    int extDrop; //!< Is set if extended drop counters are supported
  } valid;

  struct NtRMON1Counters_s RMON1;          //!< RMON1 counters
  struct NtExtendedRMONCounters_s extRMON; //!< Extended RMON counters
  struct NtCheckSumCounters_s chksum;      //!< Checksum error counters
  struct NtDecodeCounters_s decode;        //!< Packets decoded by onboard packet decoder
  struct NtExtendedDropCounters_s extDrop; //!< Extended drop counters
};

/**
 * Statistics info group for port statistics
 */
struct NtStatGroupPort_s {
  struct NtPortStatistics_s rx;   //!< Counters based on RX ports
  struct NtPortStatistics_s tx;   //!< Counters based on TX ports
  uint64_t linkDownCounter;       //!< Counts number of link downs

  uint64_t ts;                    //!< Port counter sample time stamp
  enum NtTimestampType_e tsType;  //!< Time stamp type
};

struct NtStatisticsQuery_s {
  int poll; //!< Gets the current statistical information or waits for a new update
  int clear; //!< Clears the statistical information after it has been read. All statistics counters for the current stream will be cleared. Other statistics streams will remain untouched.
  /**
   * Data section holding the statistic counters
   */
  struct NtStatisticsQueryResult_s {
    /**
     * Port specific statistics
     */
    struct NtStatisticsQueryPortResult_s {
      uint8_t numPorts;                     //!< Number of ports in @ref aPorts
      uint8_t Reserved1[3];
      struct NtStatGroupPort_s aPorts[64];  //!< Array of port statistic structures in the system
    } port;
    /**
     * Adapter specific statistics
     */
    struct NtStatisticsQueryAdapterResult_s {
      uint8_t numAdapters;                        //!< Number of adapters in @ref aAdapters
      uint8_t Reserved1[3];
      struct NtStatGroupAdapter_s aAdapters[10];  //!< Array of adapter statistic structures
    } adapter;
  } data;                               //!< Structure for statistic results
};

/********************************************************************************/
/*       Statistics data defines for NT_STATISTICS_READ_CMD_QUERY_V1            */
/********************************************************************************/
#define NT_STATISTICS_READ_CMD_QUERY_V1 NT_STATISTICS_READ_CMD_COMPAT_1

struct NtStatisticsQuery_v1_s {
  int poll; //!< Gets the current statistical information or waits for a new update
  int clear; //!< Clears the statistical information after it has been read. All statistics counters for the current stream will be cleared. Other statistics streams will remain untouched.
  /**
   * Data section holding the statistic counters
   */
  struct NtStatisticsQueryResult_v1_s {
    /**
     * Port specific statistics
     */
    struct NtStatisticsQueryPortResult_v1_s {
      uint8_t numPorts;                    //!< Number of ports in @ref aPorts
      uint8_t Reserved1[3];
      struct NtStatGroupport_v1_s aPorts[64];  //!< Array of port statistic structures in the system
    } port;
    /**
     * Adapter specific statistics
     */
    struct NtStatisticsQueryAdapterResult_v1_s {
      uint8_t numAdapters;                       //!< Number of adapters in @ref aAdapters
      uint8_t Reserved1[3];
      struct NtStatGroupAdapter_s aAdapters[10];  //!< Array of adapter statistic structures
    } adapter;
  } data;                               //!< Structure for statistic results
};


#endif /* _NT_NTAPI_NO_COMPAT */
#endif /* __STREAM_STATISTICS_COMPAT_H__ */
