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

/**@file tsms_tpdu_deliver.c
 * @brief SMS TPDU SMS-DELIVER message as per 3GPP TS 23.040 section 9.2.2.1.
 *
 * @author Mamadou Diop <diopmamadou(at)doubango.org>
 *
 * @date Created: Sat Nov 8 16:54:58 2009 mdiop
 */
#include "tinySMS/tpdu/tsms_tpdu_deliver.h"

#include "tsk_string.h"
#include "tsk_memory.h"
#include "tsk_debug.h"

tsms_tpdu_message_t* _tsms_tpdu_deliver_deserialize(const void* data, size_t size)
{
	return tsk_null;
}

int _tsms_tpdu_deliver_serialize(const tsms_tpdu_deliver_t* self, tsk_buffer_t* output)
{
	uint8_t _1byte;

	if(!self){
		return -1;
	}

/* SMSC address */
#if TSMS_TPDU_APPEND_SMSC
	tsms_address_serialize(self->smsc, output);
#endif

	/* SMS-DELIVER first Octect:
		- TP-Message-Type-Indicator(2b)
		- TP-More-Messages-to-Send(1b)
		- TP-Loop-Prevention(1b)
		- TP-Reply-Path(1b)
		- TP-User-Data-Header-Indicator(1b)
		- TP-Status-Report-Indication(1b)
		+----+----+----+----+----+----+----+----+
		|  RP|UDHI|SRI |	|LP	 |MMS | MTI	    |
		+----+----+----+----+----+----+----+----+
	*/
	_1byte = (TSMS_TPDU_MESSAGE(self)->mti & 0xF3); /*2b*/
	_1byte |= ((uint8_t)self->mms) << 2 /*1b*/
	 | ((uint8_t)self->lp) << 3 /*1b*/
	/*1b (unused)*/
	 | ((uint8_t)self->sri) << 5 /*1b*/
	 | ((uint8_t)self->udhi) << 6 /*1b*/
	 | ((uint8_t)self->rp) << 7; /*1b*/
	tsk_buffer_append(output, &_1byte, 1);

	/* 3GPP TS 23.040 ==> TP-Originating-Address (TP-OA)*/
	tsms_address_serialize(self->oa, output);

	/* 3GPP TS 23.040 ==> TP-Protocol-Identifier (TP-PI)*/
	tsk_buffer_append(output, &TSMS_TPDU_MESSAGE(self)->pid, 1); /*1o*/
	
	/* 3GPP TS 23.040 ==> TP-Data-Coding-Scheme (TP-DCS)*/
	tsk_buffer_append(output, &TSMS_TPDU_MESSAGE(self)->dcs, 1); /*1o*/

	/* 3GPP TS 23.040 ==> TP-Service-Centre-Time-Stamp  (TP-SCTS)*/
	tsk_buffer_append(output, self->scts, sizeof(self->scts)); /*7o*/

	/* 3GPP TS 23.040 ==> 9.2.3.16 TP-User-Data-Length (TP-UDL) */
	tsk_buffer_append(output, &TSMS_TPDU_MESSAGE(self)->udl, 1); /*1o*/

	/* 3GPP TS 23.040 ==> 9.2.3.24 TP-User Data (TP-UD) */
	tsk_buffer_append(output, TSK_BUFFER_DATA(TSMS_TPDU_MESSAGE(self)->ud), TSK_BUFFER_SIZE(TSMS_TPDU_MESSAGE(self)->ud));

	return 0;
}


tsms_tpdu_deliver_handle_t* tsms_tpdu_deliver_create(tsms_address_string_t smsc, tsms_address_string_t orig)
{
	tsms_tpdu_deliver_t* ret = tsk_null;
	
	if(!(ret = tsk_object_new(tsms_tpdu_deliver_def_t, smsc, orig))){
		goto bail;
	}
	
bail:
	return ret;
}

//=================================================================================================
//	SMS TPDU SMS-DELIVER object definition
//
static tsk_object_t* _tsms_tpdu_deliver_create(tsk_object_t * self, va_list * app)
{
	tsms_tpdu_deliver_t *deliver = self;
	if(deliver){
		const char* smsc, *orig;

		smsc = va_arg(*app, const char*);
		orig = va_arg(*app, const char*);
		
		/* init base*/
		tsms_tpdu_message_init(TSMS_TPDU_MESSAGE(deliver), tsms_tpdu_mti_deliver_mt);
		/* init self */
		deliver->mms = TSMS_TPDU_DEFAULT_MMS;
		deliver->smsc = TSMS_ADDRESS_SMSC_CREATE(smsc);
		deliver->oa = TSMS_ADDRESS_DA_CREATE(orig);
	}
	return self;
}

static tsk_object_t* tsms_tpdu_deliver_destroy(tsk_object_t * self)
{ 
	tsms_tpdu_deliver_t *deliver = self;
	if(deliver){
		/*deinit base*/
		tsms_tpdu_message_deinit(TSMS_TPDU_MESSAGE(deliver));
		/*deinit self*/
		TSK_OBJECT_SAFE_FREE(deliver->oa);
		TSK_OBJECT_SAFE_FREE(deliver->smsc);
	}
	return self;
}

static const tsk_object_def_t tsms_tpdu_deliver_def_s = 
{
	sizeof(tsms_tpdu_deliver_t),
	_tsms_tpdu_deliver_create, 
	tsms_tpdu_deliver_destroy,
	tsk_null, 
};
const tsk_object_def_t *tsms_tpdu_deliver_def_t = &tsms_tpdu_deliver_def_s;
