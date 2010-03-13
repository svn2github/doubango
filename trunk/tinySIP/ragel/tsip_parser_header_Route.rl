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

/**@file tsip_header_Route.c
 * @brief SIP Route header.
 *
 * @author Mamadou Diop <diopmamadou(at)yahoo.fr>
 *
 * @date Created: Sat Nov 8 16:54:58 2009 mdiop
 */
#include "tinySIP/headers/tsip_header_Route.h"

#include "tinySIP/parsers/tsip_parser_uri.h"

#include "tsk_debug.h"
#include "tsk_memory.h"
#include "tsk_time.h"

#include <string.h>

/**@defgroup tsip_header_Route_group SIP Route header.
*/

/***********************************
*	Ragel state machine.
*/
%%{
	machine tsip_machine_parser_header_Route;

	# Includes
	include tsip_machine_utils "./tsip_machine_utils.rl";
	
	action tag
	{
		tag_start = p;
	}
	
	action create_route
	{
		if(!curr_route)
		{
			curr_route = TSIP_HEADER_ROUTE_CREATE_NULL();
		}
	}

	action parse_display_name
	{
		if(curr_route)
		{
			TSK_PARSER_SET_STRING(curr_route->display_name);
		}
	}

	action parse_uri
	{
		if(curr_route && !curr_route->uri)
		{
			int len = (int)(p  - tag_start);
			curr_route->uri = tsip_uri_parse(tag_start, (size_t)len);
		}
	}

	action parse_param
	{
		if(curr_route)
		{
			TSK_PARSER_ADD_PARAM(TSIP_HEADER_PARAMS(curr_route));
		}
	}

	action add_route
	{
		if(curr_route)
		{
			tsk_list_push_back_data(hdr_routes, ((void**) &curr_route));
		}
	}

	action eob
	{
	}

	
	URI = (scheme HCOLON any+)>tag %parse_uri;
	display_name = (( token LWS )+ | quoted_string)>tag %parse_display_name;
	my_name_addr = display_name? :>LAQUOT<: URI :>RAQUOT;

	rr_param = (generic_param)>tag %parse_param;
	
	#route_param	= 	(my_name_addr ( SEMI rr_param )*)>create_route %add_route;
	#Route	= 	"Route" HCOLON route_param (COMMA route_param)*;

	route_value	= 	(my_name_addr ( SEMI rr_param )*) >create_route %add_route;
	Route	= 		"Route" HCOLON route_value (COMMA route_value)*;

	# Entry point
	main := Route :>CRLF @eob;

}%%

int tsip_header_Route_tostring(const void* header, tsk_buffer_t* output)
{
	if(header)
	{
		const tsip_header_Route_t *Route = header;
		int ret = 0;
		
		if(Route->display_name){ /* Display Name */
			tsk_buffer_appendEx(output, "\"%s\"", Route->display_name);
		}

		if(ret=tsip_uri_serialize(Route->uri, 1, 1, output)){ /* Route */
			return ret;
		}
		
		return ret;
	}

	return -1;
}

tsip_header_Routes_L_t *tsip_header_Route_parse(const char *data, size_t size)
{
	int cs = 0;
	const char *p = data;
	const char *pe = p + size;
	const char *eof = pe;
	tsip_header_Routes_L_t *hdr_routes = TSK_LIST_CREATE();
	
	const char *tag_start;
	tsip_header_Route_t *curr_route = 0;

	%%write data;
	%%write init;
	%%write exec;
	
	if( cs < %%{ write first_final; }%% )
	{
		TSK_OBJECT_SAFE_FREE(curr_route);
		TSK_OBJECT_SAFE_FREE(hdr_routes);
	}
	
	return hdr_routes;
}





//========================================================
//	Route header object definition
//

static void* tsip_header_Route_create(void *self, va_list * app)
{
	tsip_header_Route_t *Route = self;
	if(Route)
	{
		const tsip_uri_t* uri = va_arg(*app, const tsip_uri_t*);

		TSIP_HEADER(Route)->type = tsip_htype_Route;
		TSIP_HEADER(Route)->tostring = tsip_header_Route_tostring;

		if(uri){
			Route->uri = tsk_object_ref((void*)uri);
		}
	}
	else
	{
		TSK_DEBUG_ERROR("Failed to create new Route header.");
	}
	return self;
}

static void* tsip_header_Route_destroy(void *self)
{
	tsip_header_Route_t *Route = self;
	if(Route)
	{
		TSK_FREE(Route->display_name);
		TSK_OBJECT_SAFE_FREE(Route->uri);

		TSK_OBJECT_SAFE_FREE(TSIP_HEADER_PARAMS(Route));
	}
	else TSK_DEBUG_ERROR("Null Route header.");

	return self;
}

static const tsk_object_def_t tsip_header_Route_def_s = 
{
	sizeof(tsip_header_Route_t),
	tsip_header_Route_create,
	tsip_header_Route_destroy,
	0
};
const void *tsip_header_Route_def_t = &tsip_header_Route_def_s;
