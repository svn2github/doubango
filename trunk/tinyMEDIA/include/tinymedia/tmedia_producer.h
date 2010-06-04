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

/**@file tmedia_producer.h
 * @brief Base producer object.
 *
 * @author Mamadou Diop <diopmamadou(at)doubango.org>
 *
 * @date Created: Sat Nov 8 16:54:58 2009 mdiop
 */
#ifndef TINYMEDIA_PRODUCER_H
#define TINYMEDIA_PRODUCER_H

#include "tinymedia_config.h"

#include "tmedia_common.h"

/**Max number of plugins (producer types) we can create */
#define TMED_PRODUCER_MAX_PLUGINS			0x0F

/** cast any pointer to @ref tmedia_producer_t* object */
#define TMEDIA_PRODUCER(self)		((tmedia_producer_t*)(self))

typedef int (*tmedia_producer_cb_f)(const void* callback_data, const void* buffer, tsk_size_t size);

/** Base object for all Producers */
typedef struct tmedia_producer_s
{
	TSK_DECLARE_OBJECT;

	//! the type of the producer
	tmedia_type_t type;
	const char* desc;

	const struct tmedia_producer_plugin_def_s* plugin;

	tmedia_producer_cb_f callback;
	const void* callback_data;
}
tmedia_producer_t;

/** Virtual table used to define a producer plugin */
typedef struct tmedia_producer_plugin_def_s
{
	//! object definition used to create an instance of the producer
	const tsk_object_def_t* objdef;
	
	//! the type of the producer
	tmedia_type_t type;
	//! full description (usefull for debugging)
	const char* desc;

	int (* prepare) (tmedia_producer_t* );
	int (* start) (tmedia_producer_t* );
	int (* pause) (tmedia_producer_t* );
	int (* stop) (tmedia_producer_t* );
}
tmedia_producer_plugin_def_t;


TINYMEDIA_API tmedia_producer_t* tmedia_producer_create(tmedia_type_t type);
TINYMEDIA_API int tmedia_producer_init(tmedia_producer_t* self);
TINYMEDIA_API int tmedia_producer_set_callback(tmedia_producer_t *self, tmedia_producer_cb_f callback, const void* callback_data);
TINYMEDIA_API int tmedia_producer_prepare(tmedia_producer_t *self);
TINYMEDIA_API int tmedia_producer_start(tmedia_producer_t *self);
TINYMEDIA_API int tmedia_producer_pause(tmedia_producer_t *self);
TINYMEDIA_API int tmedia_producer_stop(tmedia_producer_t *self);

TINYMEDIA_API int tmedia_producer_deinit(tmedia_producer_t* self);

#endif /* TINYMEDIA_PRODUCER_H */
