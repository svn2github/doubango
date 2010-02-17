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

/**@file thttp_header_Content_Length.h
 * @brief HTTP header 'Content-Length'.
 *
 * @author Mamadou Diop <diopmamadou(at)yahoo.fr>
 *
 * @date Created: Sat Nov 8 16:54:58 2009 mdiop
 */
#ifndef _THTTP_HEADER_CONTENT_LENGTH_H_
#define _THTTP_HEADER_CONTENT_LENGTH_H_

#include "tinyhttp_config.h"
#include "tinyhttp/headers/thttp_header.h"

THTTP_BEGIN_DECLS

/**@def THTTP_HEADER_CONTENT_LENGTH_CREATE
* Creates new http 'Content-Length' header.  You must call @ref TSK_OBJECT_SAFE_FREE to free the header.
* @sa TSK_OBJECT_SAFE_FREE.
*/

#define THTTP_HEADER_CONTENT_LENGTH_VA_ARGS(length)	thttp_header_Content_Length_def_t, (uint32_t)length
#define THTTP_HEADER_CONTENT_LENGTH_CREATE(length)	tsk_object_new(THTTP_HEADER_CONTENT_LENGTH_VA_ARGS(length))

////////////////////////////////////////////////////////////////////////////////////////////////////
/// @struct	
///
/// @brief	HTTP header 'Content-Length'.
/// @author	Mamadou
/// @date	12/3/2009
///
/// @par ABNF: Content-Length / l
/// Content-Length	= 	"Content-Length" HCOLON 1*DIGIT
/// 	
////////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct thttp_header_Content_Length_s
{	
	THTTP_DECLARE_HEADER;

	uint32_t length;
}
thttp_header_Content_Length_t;

thttp_header_Content_Length_t *thttp_header_Content_Length_parse(const char *data, size_t size);

TINYHTTP_GEXTERN const void *thttp_header_Content_Length_def_t;

THTTP_END_DECLS

#endif /* _THTTP_HEADER_CONTENT_LENGTH_H_ */

