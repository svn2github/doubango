/*
* Copyright (C) 2009 Mamadou Diop.
*
* Contact: Mamadou Diop <diopmamadou@yahoo.fr>
*	
* This file is part of Open Source Doubango Framework.
*
* DOUBANGO is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*	
* DOUBANGO is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*	
* You should have received a copy of the GNU General Public License
* along with DOUBANGO.
*
*/
/**@file tnet_dhcp_option_sip.h
 * @brief  Dynamic Host Configuration Protocol (DHCP-for-IPv4) Option for 
 *			Session Initiation Protocol (SIP) Servers as per RFC 3361.
 *
 * @author Mamadou Diop <diopmamadou(at)yahoo.fr>
 *
 * @date Created: Sat Nov 8 16:54:58 2009 mdiop
 */

#ifndef tnet_dhcp_option_sip_H
#define tnet_dhcp_option_sip_H

#include "tinyNET_config.h"

#include "tnet_dhcp_option.h"

#include "tsk_string.h"

TNET_BEGIN_DECLS

#define TNET_DHCP_OPTION_SIP_CREATE(payload, payload_size)			tsk_object_new(tnet_dhcp_option_sip_def_t, (const void*)payload, (size_t)payload_size)

typedef struct tnet_dhcp_option_sip_s
{
	TNET_DECLARE_DHCP_OPTION;

	/* RFC 3361 subclause 3.1
	Code  Len   enc   DNS name of SIP server
	+-----+-----+-----+-----+-----+-----+-----+-----+--
	| 120 |  n  |  0  |  s1 |  s2 |  s3 |  s4 | s5  |  ...
	+-----+-----+-----+-----+-----+-----+-----+-----+--
	*/
	tsk_strings_L_t *servers;
}
tnet_dhcp_option_sip_t;

TINYNET_GEXTERN const void *tnet_dhcp_option_sip_def_t;

TNET_END_DECLS

#endif /* #define tnet_dhcp_option_sip_H */
