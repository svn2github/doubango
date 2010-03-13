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


/**@file tsdp_header_P.c
 * @brief SDP "p=" header (Phone Number).
 *
 * @author Mamadou Diop <diopmamadou(at)yahoo.fr>
 *
 * @date Created: Iat Nov 8 16:54:58 2009 mdiop
 */
#include "tinySDP/headers/tsdp_header_P.h"

#include "tsk_debug.h"
#include "tsk_memory.h"
#include "tsk_string.h"

#include <string.h>

/***********************************
*	Ragel state machine.
*/
%%{
	machine tsdp_machine_parser_header_P;

	# Includes
	include tsdp_machine_utils "./tsdp_machine_utils.rl";
	
	action tag{
		tag_start = p;
	}

	action parse_value{
		TSK_PARSER_SET_STRING(hdr_P->value);
	}

	action eob{
	}
		
	P = 'p' SP* "=" SP*<: any*>tag %parse_value;
	
	# Entry point
	main := P :>CRLF @eob;

}%%

int tsdp_header_P_tostring(const tsdp_header_t* header, tsk_buffer_t* output)
{
	if(header)
	{
		const tsdp_header_P_t *P = (const tsdp_header_P_t *)header;
		if(P->value){
			tsk_buffer_append(output, P->value, strlen(P->value));
		}
		return 0;
	}

	return -1;
}

tsdp_header_P_t *tsdp_header_P_parse(const char *data, size_t size)
{
	int cs = 0;
	const char *p = data;
	const char *pe = p + size;
	const char *eof = pe;
	tsdp_header_P_t *hdr_P = TSDP_HEADER_P_CREATE_NULL();
	
	const char *tag_start;

	%%write data;
	%%write init;
	%%write exec;
	
	if( cs < %%{ write first_final; }%% ){
		TSK_DEBUG_ERROR("Failed to parse \"p=\" header.");
		TSK_OBJECT_SAFE_FREE(hdr_P);
	}
	
	return hdr_P;
}







//========================================================
//	P header object definition
//

static void* tsdp_header_P_create(void *self, va_list * app)
{
	tsdp_header_P_t *P = self;
	if(P)
	{
		TSDP_HEADER(P)->type = tsdp_htype_P;
		TSDP_HEADER(P)->tostring = tsdp_header_P_tostring;
		TSDP_HEADER(P)->rank = TSDP_HTYPE_P_RANK;
		
		P->value = tsk_strdup(va_arg(*app, const char*));
	}
	else{
		TSK_DEBUG_ERROR("Failed to create new E header.");
	}
	return self;
}

static void* tsdp_header_P_destroy(void *self)
{
	tsdp_header_P_t *P = self;
	if(P){
		TSK_FREE(P->value);
	}
	else{
		TSK_DEBUG_ERROR("Null P header.");
	}

	return self;
}
static int tsdp_header_P_cmp(const tsk_object_t *obj1, const tsk_object_t *obj2)
{
	if(obj1 && obj2){
		return tsdp_header_rank_cmp(obj1, obj2);
	}
	else{
		return -1;
	}
}

static const tsk_object_def_t tsdp_header_P_def_s = 
{
	sizeof(tsdp_header_P_t),
	tsdp_header_P_create,
	tsdp_header_P_destroy,
	tsdp_header_P_cmp
};

const void *tsdp_header_P_def_t = &tsdp_header_P_def_s;
