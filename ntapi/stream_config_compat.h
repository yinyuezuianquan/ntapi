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
 * This is the header file of the STREAMTYPE_CONFIG interface containing
 * included for backward compatibility structures.
 *
 */
#ifndef __STREAM_CONFIG_COMPAT_H__
#define __STREAM_CONFIG_COMPAT_H__

#if !defined(_NT_NTAPI_NO_COMPAT)

/***********************************************************************************************/
/*                               Port settings version 0                                       */
/***********************************************************************************************/
#define NT_CONFIG_PARM_PORT_SETTINGS NT_CONFIG_PARM_PORT_COMPAT_0 //!< Port settings - version 0

struct NtPortSettings_s {
  int enable;           //!< 0 = Disable interface, 1 = Enable interface. If disabled, the port will still be visible, but has status link down.
#ifndef DOXYGEN_IGNORE
  // Not supported
  int flow;             //!< 0 = No flow control, 1 = Flow control
#endif
  enum NtLinkMDI_e mdi; //!< MDI mode
  enum NtLinkAutoNeg_e autoNegotiation;  //!< Manual speed, Auto (ignored on optical NIM interfaces)
  /**
   * Array of manual port setting parameters
   */
  struct NtPortSettingsManual_s manual; //!< Ignored on optical NIM interfaces
  /**
   * Array of parameters to be advertised when autonegotiation is enabled
   */
  struct NtPortSettingsAdvertise_s advertise; //!< Ignored on optical NIM interfaces

  uint32_t minIFG; //!< The minimum inter-frame gap in steps of 10 ns. A specified value will be rounded up or down to the nearest HW-supported value, which depends on the link speed. The default minimum gap is 0 ns.
  uint32_t maxIFG; //!< The maximum inter-frame gap in steps of 10 ns. A specified value will be rounded up or down to the nearest HW-supported value, which depends on the link speed. The default maximum gap is the maximum HW-supported value. Setting the maximum interframe gap to 0 ns, corresponds to disabling the check for maximum IFG.

  enum NtTxPower_e TxPower; //!< TX power state on read and command on write. Controls laser power on/off on fiber SFP, XFP, SFP+ and QSFP+ modules. Note that not all modules support enable/disable of the laser. An error code is returned if not supported.
  int hostLoopback;  //!< Host loopback position.\n
  //!< Applying host loopback has the effect that data sent from the host is looped
  //!< back to the host on the same port regardless of, if a NIM (Network Interface
  //!< Module) has been plugged in, and if a physical loopback has been applied.
  //!< The link will therefore be reported as up despite that no NIM is present
  //!< or that no physical link is present.\n
  //!< In general simultaneous host and line loopback is not allowed.\n
  //!< The available loopback positions are adapter dependent and applying a loopback
  //!< position that is not supported will result in a returned error code by the API
  //!< function. In general only the following values @ref NtHostLoopback_e should be
  //!< used.\n
  //!< Applying loopback along with settings that require PHY setup changes or
  //!< applying these settings when already in loopback mode represents a conflict
  //!< and will not be carried out. A returned error code will indicate this. In order
  //!< to avoid conflicts, it is in general recommended to enable loopback separately.\n
  //!< When applying loopback special settings are used and for trispeed modules
  //!< this means that the link speed is changed to maximum. The original settings
  //!< are restored when loopback is removed.
};

/***********************************************************************
 * Config read and write port settings - NT_CONFIG_PARM_PORT_SETTINGS *
 ***********************************************************************/
struct NtConfigPort_s {
  uint8_t portNo;                 //!< Port number to read from
  uint8_t Reserved1[3];
  struct NtPortSettings_s data;   //!< Port settings
};

#define NtConfigReadPort_s NtConfigPort_s

/***********************************************************************************************/
/*                               Port settings version 1                                       */
/***********************************************************************************************/
#define NT_CONFIG_PARM_PORT_SETTINGS_V1 NT_CONFIG_PARM_PORT_COMPAT_1 //!< Port settings - version 1

struct NtPortSettings_v1_s {
  int enable;           //!< 0 = Disable interface, 1 = Enable interface. If disabled, the port will still be visible, but has status link down.
#ifndef DOXYGEN_IGNORE
  // Not supported
  int flow;             //!< 0 = No flow control, 1 = Flow control
#endif
  enum NtLinkMDI_e mdi; //!< MDI mode
  enum NtLinkAutoNeg_e autoNegotiation;  //!< Manual speed, Auto (ignored on optical NIM interfaces)
  /**
   * Array of manual port setting parameters
   */
  struct NtPortSettingsManual_s manual; //!< Ignored on optical NIM interfaces
  /**
   * Array of parameters to be advertised when autonegotiation is enabled
   */
  struct NtPortSettingsAdvertise_s advertise; //!< Ignored on optical NIM interfaces

  uint32_t minIFG; //!< Depending on the IfgMode parameter in ntservice.ini the minimum interframe-gap is either interpreted as 10 ns steps or bytes. If IfgMode is set to NS the value will be rounded up or down to the nearest HW-supported value, which depends on the link speed. The default minimum gap is 0 ns. If the IfgMode is set to BYTE the value is written directly to the HW.
  uint32_t maxIFG; //!< Depending on the IfgMode parameter in ntservice.ini the maximum interframe-gap is either interpreted as 10 ns steps or bytes. If the IfgMode is set to NS the value will be rounded up or down to the nearest HW-supported value, which depends on the link speed. The default maximum gap is the maximum HW-supported value. If the IfgMode is set to BYTE the value will be  written directly to the HW. Setting the maximum interframe gap to 0, corresponds to disabling the check for maximum IFG.

  enum NtTxPower_e TxPower; //!< TX power state on read and command on write. Controls laser power on/off on fiber SFP, XFP, SFP+ and QSFP+ modules. Note that not all modules support enable/disable of the laser. An error code is returned if not supported.
  int hostLoopback;  //!< Host loopback position.\n
  //!< Applying host loopback has the effect that data sent from the host is looped
  //!< back to the host on the same port regardless of, if a NIM (Network Interface
  //!< Module) has been plugged in, and if a physical loopback has been applied.
  //!< The link will therefore be reported as up despite that no NIM is present
  //!< or that no physical link is present.\n
  //!< In general simultaneous host and line loopback is not allowed.\n
  //!< The available loopback positions are adapter dependent and applying a loopback
  //!< position that is not supported will result in a returned error code by the API
  //!< function. In general only the following values @ref NtHostLoopback_e should be
  //!< used.\n
  //!< Applying loopback along with settings that require PHY setup changes or
  //!< applying these settings when already in loopback mode represents a conflict
  //!< and will not be carried out. A returned error code will indicate this. In order
  //!< to avoid conflicts, it is in general recommended to enable loopback separately.\n
  //!< When applying loopback special settings are used and for trispeed modules
  //!< this means that the link speed is changed to maximum. The original settings
  //!< are restored when loopback is removed.

  int lineLoopback;  //!< Line loopback position.\n
  //!< Applying line loopback has the effect that data sent from the line is looped
  //!< back to the line on the same port. This requires that a NIM (Network Interface
  //!< Module) has been plugged in.
  //!< The link will in general be reported as up and traffic can be received by
  //!< the host but any traffic transmitted by the host will be replaced by the
  //!< traffic looped back.
  //!< In general simultaneous host and line loopback is NOT allowed.\n
  //!< The available loopback positions are adapter dependent and applying a loopback
  //!< position that is not supported will result in a returned error code by the API
  //!< function. In general only the following values @ref NtLineLoopback_e should be
  //!< used.\n
  //!< Applying loopback along with settings that require PHY setup changes or
  //!< applying these settings when already in loopback mode represents a conflict
  //!< and will not be carried out. A returned error code will indicate this. In order
  //!< to avoid conflicts, it is in general recommended to enable loopback separately.\n
  //!< When applying loopback special settings are used and for trispeed modules
  //!< this means that the link speed is changed to maximum. The original settings
  //!< are restored when loopback is removed.
  enum NtPortId_e PortId; //!< Port identification state.
  //!< Turns the port identification feature on/off. An error code is returned if
  //!< not supported.
  //!< When enabled the port led will start to blink regardless if the link is up
  //!< or the port receives data or not.
  int wisModeEnable; //!< 0 = Wismode disabled on port, 1 = Enable Wismode enabled on port.
};

/***********************************************************************
 * Config read and write port settings - NT_CONFIG_PARM_PORT_SETTINGS_V1 *
 ***********************************************************************/
struct NtConfigPort_v1_s {
  uint8_t portNo;                 //!< Port number to read from
  uint8_t Reserved1[3];
  struct NtPortSettings_v1_s data;   //!< Port settings
};

#define NT_TIMESYNC_RESET_PTP_SYNC_STAT NT_TIMESYNC_RESET_COMPAT_0 //!< Deprecated. Use NT_TIMESYNC_RESET_TS_STATISTICS instead

#endif /* _NT_NTAPI_NO_COMPAT */
#endif /* __STREAM_INFO_COMPAT_H__ */
