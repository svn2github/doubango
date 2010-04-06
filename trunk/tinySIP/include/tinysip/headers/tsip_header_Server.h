/*
* Copyright (C) 2009 Mamadou Diop.
*
* Contact: Mamadou Diop <diopmamadou(at)doubango.org>
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

/**@file tsip_header_Server.h
 * @brief SIP header 'Server'.
 *
 * @author Mamadou Diop <diopmamadou(at)doubango.org>
 *
 * @date Created: Sat Nov 8 16:54:58 2009 mdiop
 */
#ifndef _TSIP_HEADER_SERVER_H_
#define _TSIP_HEADER_SERVER_H_

#include "tinySIP_config.h"
#include "tinySIP/headers/tsip_header.h"

TSIP_BEGIN_DECLS

/**@def TSIP_HEADER_SERVER_CREATE
* Creates new sip 'Server' header.  You must call @ref TSK_OBJECT_SAFE_FREE to free the header.
* @sa TSK_OBJECT_SAFE_FREE.
*/
#define TSIP_HEADER_SERVER_VA_ARGS(server)		tsip_header_Server_def_t, (const char*)server
#define TSIP_HEADER_SERVER_CREATE(server)		tsk_object_new(TSIP_HEADER_SERVER_VA_ARGS(server))

////////////////////////////////////////////////////////////////////////////////////////////////////
/// @struct	
///
/// @brief	SIP header 'Server'.
/// @author	Mamadou
/// @date	12/3/2009
///
/// @par ABNF: Server	= 	"Server" HCOLON server-val *(LWS server-val)
/// server-val	= 	product / comment
/// product	= 	token [SLASH product-version]
/// product-version	= 	token
/// 	
////////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct tsip_header_Server_s
{	
	TSIP_DECLARE_HEADER;
	char* value;
}
tsip_header_Server_t;

tsip_header_Server_t *tsip_header_Server_parse(const char *data, size_t size);

TINYSIP_GEXTERN const void *tsip_header_Server_def_t;

TSIP_END_DECLS

#endif /* _TSIP_HEADER_SERVER_H_ */

