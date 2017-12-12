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
 * This header file contains NTAPI function prototypes
 */
#ifndef __NTAPI_H__
#define __NTAPI_H__

/**
 * @brief Initializes the NTAPI library
 *
 * This function <em>must</em> be called prior to any other
 * NTAPI function. It will initialize the NTAPI library and perform
 * compatibility checks based on the version applied.
 * The version is used to indicate to NTAPI what version of the API the
 * application supports and will enable NTAPI to act on this and adapt to that
 * version of the API if possible. This means that if the application is compiled
 * to e.g. version 1 of the API and the current API is version 9, NT_Init will
 * check if it is possible to enable backward compatibility to version 1 and
 * thereby allow the application to run on a version 9 library with version 1 API.
 *
 * @param[in] version  The version that the calling application supports
 *
 * @retval  NT_SUCCESS     Success
 * @retval  !=0            Error
 */
int NT_Init(uint32_t version);

/**
 * @brief Closes down the NTAPI library
 *
 * @retval  NT_SUCCESS     Success
 */
int NT_Done(void);

/**
 * @brief Explains an error code returned by NTAPI functions
 *
 * This function will convert the error code to text
 *
 * @param[in]     error  The error code to explain
 * @param[in,out] buf    Location of the explanation
 * @param[in]     buflen The buffer length to prevent buffer overrun. The define @ref NT_ERRBUF_SIZE "NT_ERRBUF_SIZE" should be used as buflen.
 *
 * @retval  A pointer to buf
 */
char *NT_ExplainError(int error, char *buf, uint32_t buflen);

#endif // __NTAPI_H__
