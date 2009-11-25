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
* GNU Lesser General Public License for more details.
*	
* You should have received a copy of the GNU General Public License
* along with DOUBANGO.
*
*/

/**@file tcomp_udvm.nack.c
 * @brief  The machine architecture described in this document.  The UDVM is used to decompress SigComp messages.
 *
 * @author Mamadou Diop <diopmamadou(at)yahoo.fr>
 *
 * @date Created: Sat Nov 8 16:54:58 2009 mdiop
 */
#include "tcomp_udvm.h"

/**@defgroup tcomp_udvm_group SIGCOMP UDVM machine.
* The machine architecture described in this document.  The UDVM is used to decompress SigComp messages.
*/

#define TCOMP_UDVM_MEMORY_REGISTERS_PTR TCOMP_UDVM_GET_BUFFER_AT(UDVM_REGISTERS_START)


/**@ingroup tcomp_udvm_group
RFC3320-Setction_8.4.  Byte copying
From UDVM to UDVM
@param destination
@param source
@param size_tocopy
@returns
*/
int tcomp_udvm_bytecopy_self(tcomp_udvm_t *udvm, uint16_t *destination, uint16_t source, uint16_t size_tocopy)
{
	uint16_t byte_copy_left, byte_copy_right;
	if (*destination == tcomp_buffer_getSize(udvm->memory) || source == tcomp_buffer_getSize(udvm->memory))
	{
		/* SEGFAULT */
		tcomp_udvm_createNackInfo2(udvm, NACK_SEGFAULT);
		return 0;
	}

	/*
	* The string of bytes is copied in ascending order of memory address,
	* respecting the bounds set by byte_copy_left and byte_copy_right.
	*/	
	byte_copy_left = TCOMP_UDVM_GET_2BYTES_VAL(TCOMP_UDVM_HEADER_BYTE_COPY_LEFT_INDEX);
	byte_copy_right = TCOMP_UDVM_GET_2BYTES_VAL(TCOMP_UDVM_HEADER_BYTE_COPY_RIGHT_INDEX);
	
	// string of bytes is copied one byte at a time
	while((size_tocopy--))
	{
		*TCOMP_UDVM_GET_BUFFER_AT(*destination++) = *TCOMP_UDVM_GET_BUFFER_AT(source++);
		
		*destination = (*destination == byte_copy_right)? byte_copy_left : *destination;
		source = (source == byte_copy_right)? byte_copy_left : source;
	}

	return 1;
}

/**@ingroup tcomp_udvm_group
RFC3320-Setction_8.4.  Byte copying
From EXTERNAL to UDVM
@param destination
@param source
@param size_tocopy
@returns
*/
int tcomp_udvm_bytecopy_to(tcomp_udvm_t *udvm, uint16_t destination, const uint8_t* source, uint16_t size_tocopy)
{
	uint16_t byte_copy_left, byte_copy_right;

	if(destination == tcomp_buffer_getSize(udvm->memory))
	{
		/* SEGFAULT */
		tcomp_udvm_createNackInfo2(udvm, NACK_SEGFAULT);
		return 0;
	}

	/*
	* The string of bytes is copied in ascending order of memory address,
	* respecting the bounds set by byte_copy_left and byte_copy_right.
	*/
	byte_copy_left = TCOMP_UDVM_GET_2BYTES_VAL(TCOMP_UDVM_HEADER_BYTE_COPY_LEFT_INDEX);
	byte_copy_right = TCOMP_UDVM_GET_2BYTES_VAL(TCOMP_UDVM_HEADER_BYTE_COPY_RIGHT_INDEX);

	// string of bytes is copied one byte at a time
	while((size_tocopy--))
	{
		*TCOMP_UDVM_GET_BUFFER_AT(destination++) = *(source++);
		
		destination = (destination == byte_copy_right)? byte_copy_left : destination;
	}

	return 1;
}

/**@ingroup tcomp_udvm_group
RFC3320-Setction_8.4.  Byte copying
From UDVM to EXTERNAL
@param destination
@param source
@param size_tocopy
@returns
*/
int tcomp_udvm_bytecopy_from(tcomp_udvm_t *udvm, uint8_t* destination, uint16_t source, uint16_t size_tocopy)
{
	uint16_t byte_copy_left, byte_copy_right;

	if(source == tcomp_buffer_getSize(udvm->memory))
	{
		/* SEGFAULT */
		tcomp_udvm_createNackInfo2(udvm, NACK_SEGFAULT);
		return 0;
	}

	/*
	* The string of bytes is copied in ascending order of memory address,
	* respecting the bounds set by byte_copy_left and byte_copy_right.
	*/
	byte_copy_left = TCOMP_UDVM_GET_2BYTES_VAL(TCOMP_UDVM_HEADER_BYTE_COPY_LEFT_INDEX);
	byte_copy_right = TCOMP_UDVM_GET_2BYTES_VAL(TCOMP_UDVM_HEADER_BYTE_COPY_RIGHT_INDEX);


	// string of bytes is copied one byte at a time
	while((size_tocopy--))
	{
		*(destination++) = *TCOMP_UDVM_GET_BUFFER_AT(source++);

		source = (source == byte_copy_right)? byte_copy_left : source;
	}

	return 1;
}