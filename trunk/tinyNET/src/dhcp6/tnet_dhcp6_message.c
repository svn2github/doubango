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
/**@file tnet_dhcp6_message.c
 * @brief DHCPv6 (RFC 3315) Messages.
 *
 * @author Mamadou Diop <diopmamadou(at)yahoo.fr>
 *
 * @date Created: Sat Nov 8 16:54:58 2009 mdiop
 */
#include "tnet_dhcp6_message.h"
#include "tnet_dhcp6.h"

#include "tsk_debug.h"

#include <string.h>

tsk_buffer_t* tnet_dhcp6_message_serialize(const tnet_dhcp6_ctx_t *ctx, const tnet_dhcp6_message_t *self)
{
	tsk_buffer_t* output = 0;
	//uint8_t _1byte;
	uint16_t _2bytes;
	uint32_t _4bytes;
	
	/* Check message validity */
	if(!self){
		goto bail;
	}

	output = TSK_BUFFER_CREATE_NULL();

	/*== msg-type + transaction-id */
	_4bytes = (((uint32_t)(self->type)) << 24) | (self->transaction_id & 0xFFFFFF);
	_4bytes = ntohl(_4bytes);
	tsk_buffer_append(output, &(_4bytes), 4);

	/*== Vendor class
	*/
	{
		_2bytes = htons(dhcp6_code_vendor_class);
		tsk_buffer_append(output, &(_2bytes), 2);
		_2bytes = htons(4 + strlen(ctx->vendor_class_data));
		tsk_buffer_append(output, &(_2bytes), 2);
		_4bytes = ntohl(ctx->enterprise_number);
		tsk_buffer_append(output, &(_4bytes), 4);
		tsk_buffer_append(output, ctx->vendor_class_data, strlen(ctx->vendor_class_data));
	}

	/*== DHCP Options
	*/
	{
		tsk_list_item_t *item;
		tnet_dhcp6_option_t* option;
		tsk_list_foreach(item, self->options)
		{
			option = (tnet_dhcp6_option_t*)item->data;
			if(tnet_dhcp6_option_serialize(option, output)){
				TSK_DEBUG_WARN("Failed to serialize DHCPv6 OPTION (%u)", option->code);
			}
		}
	}
bail:
	return output;
}

tnet_dhcp6_message_t* tnet_dhcp6_message_deserialize(const tnet_dhcp6_ctx_t *ctx, const uint8_t *data, size_t size)
{
	return 0;
}



//=================================================================================================
//	[[DHCPv6 MESSAGE]] object definition
//
static void* tnet_dhcp6_message_create(void * self, va_list * app)
{
	tnet_dhcp6_message_t *message = self;
	if(message)
	{
		static uint16_t __dhcp6message_unique_tid = 0;//(uint32_t)tsk_time_epoch();

		message->type = va_arg(*app, tnet_dhcp6_message_type_t);
		message->transaction_id = ++__dhcp6message_unique_tid;
		message->options = TSK_LIST_CREATE();
	}
	return self;
}

static void* tnet_dhcp6_message_destroy(void * self) 
{ 
	tnet_dhcp6_message_t *message = self;
	if(message)
	{
		TSK_OBJECT_SAFE_FREE(message->options);
	}
	return self;
}

static const tsk_object_def_t tnet_dhcp6_message_def_s =
{
	sizeof(tnet_dhcp6_message_t),
	tnet_dhcp6_message_create,
	tnet_dhcp6_message_destroy,
	0,
};
const void *tnet_dhcp6_message_def_t = &tnet_dhcp6_message_def_s;