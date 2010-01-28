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

/**@file tnet_turn.h
 * @brief Traversal Using Relays around NAT (TURN) implementation as per 'draft-ietf-behave-turn-16', 'draft-ietf-behave-turn-tcp-05'
 *		 and 'draft-ietf-behave-turn-ipv6'.
 *			http://tools.ietf.org/html/draft-ietf-behave-turn-16
 *			http://tools.ietf.org/html/draft-ietf-behave-turn-tcp-05
 *			http://tools.ietf.org/html/draft-ietf-behave-turn-ipv6-07
 *
 * @author Mamadou Diop <diopmamadou(at)yahoo.fr>
 *
 * @date Created: Sat Nov 8 16:54:58 2009 mdiop
 */
#ifndef TNET_TURN_H
#define TNET_TURN_H

#include "tinyNET_config.h"

#include "turn/tnet_turn_attribute.h"

#include "tnet_proto.h"
#include "tnet_socket.h"
#include "tnet_types.h"

#include "tsk_object.h"

TNET_BEGIN_DECLS

#define TNET_TURN_PERMISSION_TIMEOUT_DEFAULT	300 /* draft-ietf-behave-turn-16 subclause 8 */
#define TNET_TURN_CHANBIND_TIMEOUT_DEFAULT		600 /* draft-ietf-behave-turn-16 subclause 11 */

#define TNET_TURN_CHANNEL_BINDING_CREATE(allocation)	\
	tsk_object_new(tnet_turn_channel_binding_def_t, (const tnet_turn_allocation_t *)allocation)

#define TNET_TURN_PERMISSION_CREATE(timeout) \
	tsk_object_new(tnet_turn_permission_def_t, (uint32_t)timeout)

#define TNET_TURN_ALLOCATION_CREATE(fd, socket_type, server_address, server_port, username, password) \
	tsk_object_new(tnet_turn_allocation_def_t, (tnet_fd_t)fd, (tnet_socket_type_t)socket_type, (const char*)server_address, (tnet_port_t)server_port, (const char*)username, (const char*)password)

typedef uint64_t tnet_turn_allocation_id_t;
#define TNET_TURN_INVALID_ALLOCATION_ID				0
#define TNET_TURN_IS_VALID_ALLOCATION_ID(id)		(id != TNET_TURN_INVALID_ALLOCATION_ID)

typedef uint16_t tnet_turn_channel_binding_id_t;
#define TNET_TURN_INVALID_CHANNEL_BINDING_ID			0x00
#define TNET_TURN_IS_VALID_CHANNEL_BINDING_ID(id)		( (0x4000 <= id) && (id <= 0x7FFF) ) /* see draft-ietf-behave-turn-16 subcaluse 11. */

typedef struct tnet_turn_permission_s
{
	TSK_DECLARE_OBJECT;

	tnet_turn_attribute_xpeer_addr_t *xpeer;
	uint32_t timeout; /**< Timeout value in seconds. Default is 300s(5 minutes). */
}
tnet_turn_permission_t;
typedef tsk_list_t tnet_turn_permissions_L_t;

typedef struct tnet_turn_channel_binding_s
{
	TSK_DECLARE_OBJECT;

	tnet_turn_channel_binding_id_t id;
	const struct tnet_turn_allocation_s *allocation;
	tnet_turn_attribute_xpeer_addr_t *xpeer;
	uint32_t timeout; /**< Timeout value in seconds. Default is 600s(10 minutes). */
}
tnet_turn_channel_binding_t;
typedef tsk_list_t tnet_turn_channel_bindings_L_t;

typedef struct tnet_turn_allocation_s
{
	TSK_DECLARE_OBJECT;
	
	tnet_turn_allocation_id_t id; /**< Unique id. */
	
	char* relay_address; /**< the relayed transport address */
	//! Server reflexive address of the local socket(STUN1 as per RFC 3489).
	tnet_stun_attribute_mapped_addr_t *maddr;
	//! XORed server reflexive address (STUN2 as per RFC 5389).
	tnet_stun_attribute_xmapped_addr_t *xmaddr;
	
	/* 5-tuple */
	tnet_fd_t localFD;
	tnet_socket_type_t socket_type;

	struct sockaddr_storage server;

	/*---*/

	/* the authentication information */
	char* username;
	char* password;
	char* realm;
	char* nonce;
	/*---*/

	/* the time-to-expiry */
	uint32_t timeout; /**< Timeout value in seconds. Default is 600s(10 minutes). */
	/*---*/

	/* A list of permissions */
	/* A list of channel to peer bindings */

	char* software;

	tnet_turn_channel_bindings_L_t *channel_bindings;
	tnet_turn_permissions_L_t *permissions;
}
tnet_turn_allocation_t;
typedef tsk_list_t tnet_turn_allocations_L_t;

TINYNET_GEXTERN const void *tnet_turn_permission_def_t;
TINYNET_GEXTERN const void *tnet_turn_channel_binding_def_t;
TINYNET_GEXTERN const void *tnet_turn_allocation_def_t;

//#if defined(__SYMBIAN32__) || ANDROID /* Forward declaration */
struct tnet_nat_context_s;
//#endif

tnet_turn_allocation_id_t tnet_turn_allocate(const struct tnet_nat_context_s* nat_context, const tnet_fd_t localFD, tnet_socket_type_t socket_type);
int tnet_turn_allocation_refresh(const struct tnet_nat_context_s* nat_context, tnet_turn_allocation_t *allocation);
int tnet_turn_unallocate(const struct tnet_nat_context_s* nat_context, tnet_turn_allocation_t *allocation);
tnet_turn_channel_binding_id_t tnet_turn_channel_bind(const struct tnet_nat_context_s* nat_context, tnet_turn_allocation_t *allocation, struct sockaddr_storage *peer);
int tnet_turn_channel_refresh(const struct tnet_nat_context_s* nat_context, const tnet_turn_channel_binding_t * channel_bind);
int tnet_turn_channel_senddata(const struct tnet_nat_context_s* nat_context, const tnet_turn_channel_binding_t * channel_bind, const void* data, size_t size, int indication);
int tnet_turn_add_permission(const struct tnet_nat_context_s* nat_context, tnet_turn_allocation_t *allocation, const char* ipaddress, uint32_t timeout);


TNET_END_DECLS

#endif /* TNET_TURN_H */

