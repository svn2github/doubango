/* Copyright (C) 2014 Mamadou DIOP.
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

/**@file tdav_session_bfcp.h
 * @brief The The Binary Floor Control Protocol (BFCP, rfc4582) session.
 */

#ifndef TINYDAV_SESSION_BFCP_H
#define TINYDAV_SESSION_BFCP_H

#include "tinydav_config.h"

#if !defined(HAVE_TINYBFCP) || HAVE_TINYBFCP
#include "tinymedia/tmedia_session.h"

TDAV_BEGIN_DECLS

TINYDAV_GEXTERN const tmedia_session_plugin_def_t *tdav_session_bfcp_plugin_def_t;

TDAV_END_DECLS

#endif /* !defined(HAVE_TINYBFCP)  || HAVE_TINYBFCP */

#endif /* TINYDAV_SESSION_BFCP_H */
