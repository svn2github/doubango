
/* #line 1 "./ragel/tsip_parser_header_P_Preferred_Identity.rl" */
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

/**@file tsip_header_P_Preferred_Identity.c
 * @brief SIP P-Preferred-Identity header as per RFC 3325.
 *     Header field         where   proxy   ACK  BYE  CAN  INV  OPT  REG
 *     ------------         -----   -----   ---  ---  ---  ---  ---  ---
 *     P-Preferred-Identity          adr     -    o    -    o    o    -
 *
 *
 *                                          SUB  NOT  REF  INF  UPD  PRA
 *                                          ---  ---  ---  ---  ---  ---
 *                                           o    o    o    -    -    -
 *
 * @author Mamadou Diop <diopmamadou(at)doubango.org>
 *
 * @date Created: Sat Nov 8 16:54:58 2009 mdiop
 */
#include "tinySIP/headers/tsip_header_P_Preferred_Identity.h"

#include "tinySIP/parsers/tsip_parser_uri.h"

#include "tsk_debug.h"
#include "tsk_memory.h"

/**@defgroup tsip_header_P_Preferred_Identity_group SIP P_Preferred_Identity header.
*/

/***********************************
*	Ragel state machine.
*/

/* #line 90 "./ragel/tsip_parser_header_P_Preferred_Identity.rl" */



tsip_header_P_Preferred_Identity_t* tsip_header_P_Preferred_Identity_create(const tsip_uri_t* uri)
{
	return tsk_object_new(TSIP_HEADER_P_PREFERRED_IDENTITY_VA_ARGS(uri));
}

tsip_header_P_Preferred_Identity_t* tsip_header_P_Preferred_Identity_create_null()
{
	return tsip_header_P_Preferred_Identity_create(tsk_null);
}

int tsip_header_Preferred_Identity_tostring(const void* header, tsk_buffer_t* output)
{
	if(header){
		int ret;
		const tsip_header_P_Preferred_Identity_t *P_Preferred_Identity = header;

		if((ret = tsip_uri_serialize(P_Preferred_Identity->uri, 1, 1, output))){
			return ret;
		}
		return ret;
	}
	return -1;
}

tsip_header_P_Preferred_Identity_t *tsip_header_P_Preferred_Identity_parse(const char *data, size_t size)
{
	int cs = 0;
	const char *p = data;
	const char *pe = p + size;
	const char *eof = pe;
	tsip_header_P_Preferred_Identity_t *hdr_pi = tsip_header_P_Preferred_Identity_create_null();
	
	const char *tag_start;

	
/* #line 94 "./src/headers/tsip_header_P_Preferred_Identity.c" */
static const char _tsip_machine_parser_header_P_Preferred_Identity_actions[] = {
	0, 1, 0, 1, 1, 1, 2, 1, 
	3, 2, 1, 2, 2, 2, 1
};

static const short _tsip_machine_parser_header_P_Preferred_Identity_key_offsets[] = {
	0, 0, 2, 3, 5, 7, 9, 11, 
	13, 15, 17, 19, 21, 22, 24, 26, 
	28, 30, 32, 34, 36, 38, 41, 62, 
	63, 65, 86, 87, 89, 92, 96, 108, 
	111, 111, 112, 116, 117, 138, 139, 141, 
	162, 179, 197, 201, 202, 204, 212, 213, 
	215, 219, 225, 237, 240, 240, 244, 264, 
	280, 297, 302, 310, 323, 328, 332, 337, 
	358, 375, 393, 399, 408, 418, 424, 449, 
	471, 494, 503, 514, 533, 544, 554, 563, 
	568, 592, 613, 635, 643, 653, 665, 668, 
	668, 672, 692, 708, 725, 730, 738, 751, 
	756, 760, 765, 786, 803, 821, 827, 836, 
	846, 852, 877, 899, 922, 931, 942, 961, 
	972, 982, 992, 1017, 1039, 1062, 1067, 1075, 
	1088, 1093, 1097, 1102, 1123, 1140, 1158, 1164, 
	1173, 1177, 1197, 1213, 1230, 1239, 1244, 1268, 
	1289, 1311, 1319, 1332, 1337, 1341, 1361, 1370, 
	1394, 1415, 1437, 1445, 1455, 1461, 1486, 1508, 
	1531, 1536, 1538, 1541, 1545, 1550, 1559, 1570, 
	1589, 1600, 1610, 1619, 1638, 1649, 1659, 1684, 
	1705, 1719, 1725, 1730, 1741, 1766, 1788, 1811, 
	1820, 1825, 1849, 1870, 1892, 1900, 1910, 1928, 
	1938, 1947, 1956, 1980, 2001, 2023, 2031, 2049, 
	2059, 2068, 2092, 2112, 2125, 2130, 2134, 2144, 
	2168, 2189, 2211
};

static const char _tsip_machine_parser_header_P_Preferred_Identity_trans_keys[] = {
	80, 112, 45, 80, 112, 82, 114, 69, 
	101, 70, 102, 69, 101, 82, 114, 82, 
	114, 69, 101, 68, 100, 45, 73, 105, 
	68, 100, 69, 101, 78, 110, 84, 116, 
	73, 105, 84, 116, 89, 121, 9, 32, 
	58, 9, 13, 32, 33, 34, 37, 39, 
	60, 126, 42, 43, 45, 46, 48, 57, 
	65, 90, 95, 96, 97, 122, 10, 9, 
	32, 9, 13, 32, 33, 34, 37, 39, 
	60, 126, 42, 43, 45, 46, 48, 57, 
	65, 90, 95, 96, 97, 122, 10, 9, 
	32, 9, 32, 60, 65, 90, 97, 122, 
	9, 32, 43, 58, 45, 46, 48, 57, 
	65, 90, 97, 122, 9, 32, 58, 62, 
	9, 13, 32, 44, 10, 9, 13, 32, 
	33, 34, 37, 39, 60, 126, 42, 43, 
	45, 46, 48, 57, 65, 90, 95, 96, 
	97, 122, 10, 9, 32, 9, 13, 32, 
	33, 34, 37, 39, 60, 126, 42, 43, 
	45, 46, 48, 57, 65, 90, 95, 96, 
	97, 122, 9, 13, 32, 33, 37, 39, 
	126, 42, 43, 45, 46, 48, 57, 65, 
	90, 95, 122, 9, 13, 32, 33, 37, 
	39, 60, 126, 42, 43, 45, 46, 48, 
	57, 65, 90, 95, 122, 9, 13, 32, 
	60, 10, 9, 32, 13, 34, 92, 127, 
	0, 8, 10, 31, 10, 9, 32, 9, 
	13, 32, 60, 0, 9, 11, 12, 14, 
	127, 9, 32, 43, 58, 45, 46, 48, 
	57, 65, 90, 97, 122, 9, 32, 58, 
	9, 13, 32, 44, 9, 13, 32, 33, 
	34, 37, 39, 44, 60, 126, 42, 46, 
	48, 57, 65, 90, 95, 96, 97, 122, 
	9, 13, 32, 33, 37, 39, 44, 126, 
	42, 46, 48, 57, 65, 90, 95, 122, 
	9, 13, 32, 33, 37, 39, 44, 60, 
	126, 42, 46, 48, 57, 65, 90, 95, 
	122, 9, 13, 32, 44, 60, 9, 13, 
	32, 44, 65, 90, 97, 122, 9, 13, 
	32, 44, 58, 43, 46, 48, 57, 65, 
	90, 97, 122, 9, 13, 32, 44, 58, 
	9, 13, 32, 44, 9, 13, 32, 44, 
	62, 9, 13, 32, 33, 34, 37, 39, 
	44, 60, 62, 126, 42, 46, 48, 57, 
	65, 90, 95, 96, 97, 122, 9, 13, 
	32, 33, 37, 39, 44, 62, 126, 42, 
	46, 48, 57, 65, 90, 95, 122, 9, 
	13, 32, 33, 37, 39, 44, 60, 62, 
	126, 42, 46, 48, 57, 65, 90, 95, 
	122, 9, 13, 32, 44, 60, 62, 9, 
	13, 32, 44, 62, 65, 90, 97, 122, 
	9, 13, 32, 34, 44, 62, 92, 127, 
	0, 31, 9, 13, 32, 44, 60, 62, 
	9, 13, 32, 33, 34, 37, 39, 44, 
	60, 62, 92, 126, 127, 0, 31, 42, 
	46, 48, 57, 65, 90, 95, 96, 97, 
	122, 9, 13, 32, 33, 34, 37, 39, 
	44, 62, 92, 126, 127, 0, 31, 42, 
	46, 48, 57, 65, 90, 95, 122, 9, 
	13, 32, 33, 34, 37, 39, 44, 60, 
	62, 92, 126, 127, 0, 31, 42, 46, 
	48, 57, 65, 90, 95, 122, 9, 13, 
	32, 44, 62, 0, 8, 11, 127, 9, 
	13, 32, 34, 44, 60, 62, 92, 127, 
	0, 31, 9, 13, 32, 34, 44, 58, 
	62, 92, 127, 0, 31, 43, 46, 48, 
	57, 65, 90, 97, 122, 9, 13, 32, 
	34, 44, 58, 62, 92, 127, 0, 31, 
	9, 13, 32, 34, 44, 62, 92, 127, 
	0, 31, 9, 13, 32, 34, 44, 92, 
	127, 0, 31, 9, 13, 32, 44, 60, 
	9, 13, 32, 33, 34, 37, 39, 44, 
	60, 92, 126, 127, 0, 31, 42, 46, 
	48, 57, 65, 90, 95, 96, 97, 122, 
	9, 13, 32, 33, 34, 37, 39, 44, 
	92, 126, 127, 0, 31, 42, 46, 48, 
	57, 65, 90, 95, 122, 9, 13, 32, 
	33, 34, 37, 39, 44, 60, 92, 126, 
	127, 0, 31, 42, 46, 48, 57, 65, 
	90, 95, 122, 9, 13, 32, 44, 0, 
	8, 11, 127, 9, 13, 32, 34, 44, 
	60, 92, 127, 0, 31, 9, 32, 43, 
	58, 45, 46, 48, 57, 65, 90, 97, 
	122, 9, 32, 58, 9, 13, 32, 44, 
	9, 13, 32, 33, 34, 37, 39, 44, 
	60, 126, 42, 46, 48, 57, 65, 90, 
	95, 96, 97, 122, 9, 13, 32, 33, 
	37, 39, 44, 126, 42, 46, 48, 57, 
	65, 90, 95, 122, 9, 13, 32, 33, 
	37, 39, 44, 60, 126, 42, 46, 48, 
	57, 65, 90, 95, 122, 9, 13, 32, 
	44, 60, 9, 13, 32, 44, 65, 90, 
	97, 122, 9, 13, 32, 44, 58, 43, 
	46, 48, 57, 65, 90, 97, 122, 9, 
	13, 32, 44, 58, 9, 13, 32, 44, 
	9, 13, 32, 44, 62, 9, 13, 32, 
	33, 34, 37, 39, 44, 60, 62, 126, 
	42, 46, 48, 57, 65, 90, 95, 96, 
	97, 122, 9, 13, 32, 33, 37, 39, 
	44, 62, 126, 42, 46, 48, 57, 65, 
	90, 95, 122, 9, 13, 32, 33, 37, 
	39, 44, 60, 62, 126, 42, 46, 48, 
	57, 65, 90, 95, 122, 9, 13, 32, 
	44, 60, 62, 9, 13, 32, 44, 62, 
	65, 90, 97, 122, 9, 13, 32, 34, 
	44, 62, 92, 127, 0, 31, 9, 13, 
	32, 44, 60, 62, 9, 13, 32, 33, 
	34, 37, 39, 44, 60, 62, 92, 126, 
	127, 0, 31, 42, 46, 48, 57, 65, 
	90, 95, 96, 97, 122, 9, 13, 32, 
	33, 34, 37, 39, 44, 62, 92, 126, 
	127, 0, 31, 42, 46, 48, 57, 65, 
	90, 95, 122, 9, 13, 32, 33, 34, 
	37, 39, 44, 60, 62, 92, 126, 127, 
	0, 31, 42, 46, 48, 57, 65, 90, 
	95, 122, 9, 13, 32, 44, 62, 0, 
	8, 11, 127, 9, 13, 32, 34, 44, 
	60, 62, 92, 127, 0, 31, 9, 13, 
	32, 34, 44, 58, 62, 92, 127, 0, 
	31, 43, 46, 48, 57, 65, 90, 97, 
	122, 9, 13, 32, 34, 44, 58, 62, 
	92, 127, 0, 31, 9, 13, 32, 34, 
	44, 62, 92, 127, 0, 31, 9, 13, 
	32, 34, 44, 62, 92, 127, 0, 31, 
	9, 13, 32, 33, 34, 37, 39, 44, 
	60, 62, 92, 126, 127, 0, 31, 42, 
	46, 48, 57, 65, 90, 95, 96, 97, 
	122, 9, 13, 32, 33, 34, 37, 39, 
	44, 62, 92, 126, 127, 0, 31, 42, 
	46, 48, 57, 65, 90, 95, 122, 9, 
	13, 32, 33, 34, 37, 39, 44, 60, 
	62, 92, 126, 127, 0, 31, 42, 46, 
	48, 57, 65, 90, 95, 122, 9, 13, 
	32, 44, 60, 9, 13, 32, 44, 65, 
	90, 97, 122, 9, 13, 32, 44, 58, 
	43, 46, 48, 57, 65, 90, 97, 122, 
	9, 13, 32, 44, 58, 9, 13, 32, 
	44, 9, 13, 32, 44, 62, 9, 13, 
	32, 33, 34, 37, 39, 44, 60, 62, 
	126, 42, 46, 48, 57, 65, 90, 95, 
	96, 97, 122, 9, 13, 32, 33, 37, 
	39, 44, 62, 126, 42, 46, 48, 57, 
	65, 90, 95, 122, 9, 13, 32, 33, 
	37, 39, 44, 60, 62, 126, 42, 46, 
	48, 57, 65, 90, 95, 122, 9, 13, 
	32, 44, 60, 62, 9, 13, 32, 44, 
	62, 65, 90, 97, 122, 9, 13, 32, 
	44, 9, 13, 32, 33, 34, 37, 39, 
	44, 60, 126, 42, 46, 48, 57, 65, 
	90, 95, 96, 97, 122, 9, 13, 32, 
	33, 37, 39, 44, 126, 42, 46, 48, 
	57, 65, 90, 95, 122, 9, 13, 32, 
	33, 37, 39, 44, 60, 126, 42, 46, 
	48, 57, 65, 90, 95, 122, 9, 13, 
	32, 34, 44, 92, 127, 0, 31, 9, 
	13, 32, 44, 60, 9, 13, 32, 33, 
	34, 37, 39, 44, 60, 92, 126, 127, 
	0, 31, 42, 46, 48, 57, 65, 90, 
	95, 96, 97, 122, 9, 13, 32, 33, 
	34, 37, 39, 44, 92, 126, 127, 0, 
	31, 42, 46, 48, 57, 65, 90, 95, 
	122, 9, 13, 32, 33, 34, 37, 39, 
	44, 60, 92, 126, 127, 0, 31, 42, 
	46, 48, 57, 65, 90, 95, 122, 9, 
	13, 32, 44, 0, 8, 11, 127, 9, 
	13, 32, 44, 58, 43, 46, 48, 57, 
	65, 90, 97, 122, 9, 13, 32, 44, 
	58, 9, 13, 32, 44, 9, 13, 32, 
	33, 34, 37, 39, 44, 60, 126, 42, 
	46, 48, 57, 65, 90, 95, 96, 97, 
	122, 9, 13, 32, 34, 44, 92, 127, 
	0, 31, 9, 13, 32, 33, 34, 37, 
	39, 44, 60, 92, 126, 127, 0, 31, 
	42, 46, 48, 57, 65, 90, 95, 96, 
	97, 122, 9, 13, 32, 33, 34, 37, 
	39, 44, 92, 126, 127, 0, 31, 42, 
	46, 48, 57, 65, 90, 95, 122, 9, 
	13, 32, 33, 34, 37, 39, 44, 60, 
	92, 126, 127, 0, 31, 42, 46, 48, 
	57, 65, 90, 95, 122, 9, 13, 32, 
	44, 0, 8, 11, 127, 9, 13, 32, 
	34, 44, 62, 92, 127, 0, 31, 9, 
	13, 32, 44, 60, 62, 9, 13, 32, 
	33, 34, 37, 39, 44, 60, 62, 92, 
	126, 127, 0, 31, 42, 46, 48, 57, 
	65, 90, 95, 96, 97, 122, 9, 13, 
	32, 33, 34, 37, 39, 44, 62, 92, 
	126, 127, 0, 31, 42, 46, 48, 57, 
	65, 90, 95, 122, 9, 13, 32, 33, 
	34, 37, 39, 44, 60, 62, 92, 126, 
	127, 0, 31, 42, 46, 48, 57, 65, 
	90, 95, 122, 9, 13, 32, 60, 62, 
	10, 62, 9, 32, 62, 9, 32, 60, 
	62, 62, 65, 90, 97, 122, 9, 13, 
	32, 44, 62, 0, 8, 11, 127, 9, 
	13, 32, 34, 44, 60, 62, 92, 127, 
	0, 31, 9, 13, 32, 34, 44, 58, 
	62, 92, 127, 0, 31, 43, 46, 48, 
	57, 65, 90, 97, 122, 9, 13, 32, 
	34, 44, 58, 62, 92, 127, 0, 31, 
	9, 13, 32, 34, 44, 62, 92, 127, 
	0, 31, 9, 13, 32, 44, 62, 0, 
	8, 11, 127, 9, 13, 32, 34, 44, 
	58, 62, 92, 127, 0, 31, 43, 46, 
	48, 57, 65, 90, 97, 122, 9, 13, 
	32, 34, 44, 58, 62, 92, 127, 0, 
	31, 9, 13, 32, 34, 44, 62, 92, 
	127, 0, 31, 9, 13, 32, 33, 34, 
	37, 39, 44, 60, 62, 92, 126, 127, 
	0, 31, 42, 46, 48, 57, 65, 90, 
	95, 96, 97, 122, 9, 13, 32, 33, 
	34, 37, 39, 44, 60, 62, 126, 42, 
	46, 48, 57, 65, 90, 95, 96, 97, 
	122, 9, 13, 32, 44, 58, 62, 43, 
	46, 48, 57, 65, 90, 97, 122, 9, 
	13, 32, 44, 58, 62, 9, 13, 32, 
	44, 62, 9, 13, 32, 34, 44, 60, 
	62, 92, 127, 0, 31, 9, 13, 32, 
	33, 34, 37, 39, 44, 60, 62, 92, 
	126, 127, 0, 31, 42, 46, 48, 57, 
	65, 90, 95, 96, 97, 122, 9, 13, 
	32, 33, 34, 37, 39, 44, 62, 92, 
	126, 127, 0, 31, 42, 46, 48, 57, 
	65, 90, 95, 122, 9, 13, 32, 33, 
	34, 37, 39, 44, 60, 62, 92, 126, 
	127, 0, 31, 42, 46, 48, 57, 65, 
	90, 95, 122, 9, 13, 32, 34, 44, 
	92, 127, 0, 31, 9, 13, 32, 44, 
	60, 9, 13, 32, 33, 34, 37, 39, 
	44, 60, 92, 126, 127, 0, 31, 42, 
	46, 48, 57, 65, 90, 95, 96, 97, 
	122, 9, 13, 32, 33, 34, 37, 39, 
	44, 92, 126, 127, 0, 31, 42, 46, 
	48, 57, 65, 90, 95, 122, 9, 13, 
	32, 33, 34, 37, 39, 44, 60, 92, 
	126, 127, 0, 31, 42, 46, 48, 57, 
	65, 90, 95, 122, 9, 13, 32, 44, 
	0, 8, 11, 127, 9, 13, 32, 34, 
	44, 60, 92, 127, 0, 31, 9, 13, 
	32, 34, 44, 58, 92, 127, 0, 31, 
	43, 46, 48, 57, 65, 90, 97, 122, 
	9, 13, 32, 34, 44, 58, 92, 127, 
	0, 31, 9, 13, 32, 34, 44, 92, 
	127, 0, 31, 9, 13, 32, 34, 44, 
	92, 127, 0, 31, 9, 13, 32, 33, 
	34, 37, 39, 44, 60, 92, 126, 127, 
	0, 31, 42, 46, 48, 57, 65, 90, 
	95, 96, 97, 122, 9, 13, 32, 33, 
	34, 37, 39, 44, 92, 126, 127, 0, 
	31, 42, 46, 48, 57, 65, 90, 95, 
	122, 9, 13, 32, 33, 34, 37, 39, 
	44, 60, 92, 126, 127, 0, 31, 42, 
	46, 48, 57, 65, 90, 95, 122, 9, 
	13, 32, 44, 0, 8, 11, 127, 9, 
	13, 32, 34, 44, 58, 92, 127, 0, 
	31, 43, 46, 48, 57, 65, 90, 97, 
	122, 9, 13, 32, 34, 44, 58, 92, 
	127, 0, 31, 9, 13, 32, 34, 44, 
	92, 127, 0, 31, 9, 13, 32, 33, 
	34, 37, 39, 44, 60, 92, 126, 127, 
	0, 31, 42, 46, 48, 57, 65, 90, 
	95, 96, 97, 122, 9, 13, 32, 33, 
	34, 37, 39, 44, 60, 126, 42, 46, 
	48, 57, 65, 90, 95, 96, 97, 122, 
	9, 13, 32, 44, 58, 43, 46, 48, 
	57, 65, 90, 97, 122, 9, 13, 32, 
	44, 58, 9, 13, 32, 44, 9, 13, 
	32, 34, 44, 60, 92, 127, 0, 31, 
	9, 13, 32, 33, 34, 37, 39, 44, 
	60, 92, 126, 127, 0, 31, 42, 46, 
	48, 57, 65, 90, 95, 96, 97, 122, 
	9, 13, 32, 33, 34, 37, 39, 44, 
	92, 126, 127, 0, 31, 42, 46, 48, 
	57, 65, 90, 95, 122, 9, 13, 32, 
	33, 34, 37, 39, 44, 60, 92, 126, 
	127, 0, 31, 42, 46, 48, 57, 65, 
	90, 95, 122, 0
};

static const char _tsip_machine_parser_header_P_Preferred_Identity_single_lengths[] = {
	0, 2, 1, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 1, 2, 2, 2, 
	2, 2, 2, 2, 2, 3, 9, 1, 
	2, 9, 1, 2, 3, 0, 4, 3, 
	0, 1, 4, 1, 9, 1, 2, 9, 
	7, 8, 4, 1, 2, 4, 1, 2, 
	4, 0, 4, 3, 0, 4, 10, 8, 
	9, 5, 4, 5, 5, 4, 5, 11, 
	9, 10, 6, 5, 8, 6, 13, 12, 
	13, 5, 9, 9, 9, 8, 7, 5, 
	12, 11, 12, 4, 8, 4, 3, 0, 
	4, 10, 8, 9, 5, 4, 5, 5, 
	4, 5, 11, 9, 10, 6, 5, 8, 
	6, 13, 12, 13, 5, 9, 9, 9, 
	8, 8, 13, 12, 13, 5, 4, 5, 
	5, 4, 5, 11, 9, 10, 6, 5, 
	4, 10, 8, 9, 7, 5, 12, 11, 
	12, 4, 5, 5, 4, 10, 7, 12, 
	11, 12, 4, 8, 6, 13, 12, 13, 
	5, 2, 3, 4, 1, 5, 9, 9, 
	9, 8, 5, 9, 9, 8, 13, 11, 
	6, 6, 5, 9, 13, 12, 13, 7, 
	5, 12, 11, 12, 4, 8, 8, 8, 
	7, 7, 12, 11, 12, 4, 8, 8, 
	7, 12, 10, 5, 5, 4, 8, 12, 
	11, 12, 0
};

static const char _tsip_machine_parser_header_P_Preferred_Identity_range_lengths[] = {
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 6, 0, 
	0, 6, 0, 0, 0, 2, 4, 0, 
	0, 0, 0, 0, 6, 0, 0, 6, 
	5, 5, 0, 0, 0, 2, 0, 0, 
	0, 3, 4, 0, 0, 0, 5, 4, 
	4, 0, 2, 4, 0, 0, 0, 5, 
	4, 4, 0, 2, 1, 0, 6, 5, 
	5, 2, 1, 5, 1, 1, 1, 0, 
	6, 5, 5, 2, 1, 4, 0, 0, 
	0, 5, 4, 4, 0, 2, 4, 0, 
	0, 0, 5, 4, 4, 0, 2, 1, 
	0, 6, 5, 5, 2, 1, 5, 1, 
	1, 1, 6, 5, 5, 0, 2, 4, 
	0, 0, 0, 5, 4, 4, 0, 2, 
	0, 5, 4, 4, 1, 0, 6, 5, 
	5, 2, 4, 0, 0, 5, 1, 6, 
	5, 5, 2, 1, 0, 6, 5, 5, 
	0, 0, 0, 0, 2, 2, 1, 5, 
	1, 1, 2, 5, 1, 1, 6, 5, 
	4, 0, 0, 1, 6, 5, 5, 1, 
	0, 6, 5, 5, 2, 1, 5, 1, 
	1, 1, 6, 5, 5, 2, 5, 1, 
	1, 6, 5, 4, 0, 0, 1, 6, 
	5, 5, 0
};

static const short _tsip_machine_parser_header_P_Preferred_Identity_index_offsets[] = {
	0, 0, 3, 5, 8, 11, 14, 17, 
	20, 23, 26, 29, 32, 34, 37, 40, 
	43, 46, 49, 52, 55, 58, 62, 78, 
	80, 83, 99, 101, 104, 108, 111, 120, 
	124, 125, 127, 132, 134, 150, 152, 155, 
	171, 184, 198, 203, 205, 208, 215, 217, 
	220, 225, 229, 238, 242, 243, 248, 264, 
	277, 291, 297, 304, 314, 320, 325, 331, 
	348, 362, 377, 384, 392, 402, 409, 429, 
	447, 466, 474, 485, 500, 511, 521, 530, 
	536, 555, 572, 590, 597, 607, 616, 620, 
	621, 626, 642, 655, 669, 675, 682, 692, 
	698, 703, 709, 726, 740, 755, 762, 770, 
	780, 787, 807, 825, 844, 852, 863, 878, 
	889, 899, 909, 929, 947, 966, 972, 979, 
	989, 995, 1000, 1006, 1023, 1037, 1052, 1059, 
	1067, 1072, 1088, 1101, 1115, 1124, 1130, 1149, 
	1166, 1184, 1191, 1201, 1207, 1212, 1228, 1237, 
	1256, 1273, 1291, 1298, 1308, 1315, 1335, 1353, 
	1372, 1378, 1381, 1385, 1390, 1394, 1402, 1413, 
	1428, 1439, 1449, 1457, 1472, 1483, 1493, 1513, 
	1530, 1541, 1548, 1554, 1565, 1585, 1603, 1622, 
	1631, 1637, 1656, 1673, 1691, 1698, 1708, 1722, 
	1732, 1741, 1750, 1769, 1786, 1804, 1811, 1825, 
	1835, 1844, 1863, 1879, 1889, 1895, 1900, 1910, 
	1929, 1946, 1964
};

static const unsigned char _tsip_machine_parser_header_P_Preferred_Identity_trans_targs[] = {
	2, 2, 0, 3, 0, 4, 4, 0, 
	5, 5, 0, 6, 6, 0, 7, 7, 
	0, 8, 8, 0, 9, 9, 0, 10, 
	10, 0, 11, 11, 0, 12, 12, 0, 
	13, 0, 14, 14, 0, 15, 15, 0, 
	16, 16, 0, 17, 17, 0, 18, 18, 
	0, 19, 19, 0, 20, 20, 0, 21, 
	21, 0, 21, 21, 22, 0, 22, 23, 
	22, 40, 45, 40, 40, 29, 40, 40, 
	40, 40, 85, 40, 85, 0, 24, 0, 
	25, 25, 0, 25, 26, 25, 40, 45, 
	40, 40, 29, 40, 40, 40, 40, 85, 
	40, 85, 0, 27, 0, 28, 28, 0, 
	28, 28, 29, 0, 30, 30, 0, 31, 
	31, 30, 32, 30, 30, 30, 30, 0, 
	31, 31, 32, 0, 33, 34, 33, 34, 
	35, 34, 36, 0, 202, 0, 36, 37, 
	36, 40, 45, 40, 40, 29, 40, 40, 
	40, 40, 50, 40, 50, 0, 38, 0, 
	39, 39, 0, 39, 26, 39, 40, 45, 
	40, 40, 29, 40, 40, 40, 40, 50, 
	40, 50, 0, 41, 43, 41, 40, 40, 
	40, 40, 40, 40, 40, 40, 40, 0, 
	42, 26, 42, 40, 40, 40, 29, 40, 
	40, 40, 40, 40, 40, 0, 42, 26, 
	42, 29, 0, 44, 0, 41, 41, 0, 
	46, 48, 49, 0, 0, 0, 45, 47, 
	0, 45, 45, 0, 42, 26, 42, 29, 
	0, 45, 45, 45, 0, 51, 51, 50, 
	52, 50, 50, 50, 50, 0, 51, 51, 
	52, 0, 53, 53, 35, 53, 54, 53, 
	54, 35, 54, 55, 78, 55, 55, 54, 
	58, 55, 55, 55, 53, 55, 53, 53, 
	56, 35, 56, 55, 55, 55, 54, 55, 
	55, 55, 55, 55, 53, 57, 35, 57, 
	55, 55, 55, 54, 58, 55, 55, 55, 
	55, 55, 53, 57, 35, 57, 54, 58, 
	53, 53, 35, 53, 54, 59, 59, 53, 
	60, 35, 60, 54, 61, 59, 59, 59, 
	59, 53, 60, 35, 60, 54, 61, 53, 
	62, 35, 62, 63, 62, 62, 35, 62, 
	63, 53, 62, 63, 35, 63, 64, 68, 
	64, 64, 63, 67, 53, 64, 64, 64, 
	62, 64, 62, 62, 65, 35, 65, 64, 
	64, 64, 63, 53, 64, 64, 64, 64, 
	64, 62, 66, 35, 66, 64, 64, 64, 
	63, 67, 53, 64, 64, 64, 64, 64, 
	62, 66, 35, 66, 63, 67, 53, 62, 
	62, 35, 62, 63, 53, 62, 62, 62, 
	68, 35, 68, 69, 70, 34, 73, 62, 
	62, 68, 66, 35, 66, 63, 67, 53, 
	62, 63, 35, 63, 71, 74, 71, 71, 
	70, 67, 34, 73, 71, 62, 62, 71, 
	71, 75, 71, 75, 68, 72, 35, 72, 
	71, 69, 71, 71, 70, 34, 73, 71, 
	62, 62, 71, 71, 71, 71, 68, 42, 
	35, 42, 71, 69, 71, 71, 70, 29, 
	34, 73, 71, 62, 62, 71, 71, 71, 
	71, 68, 68, 35, 68, 70, 53, 68, 
	68, 62, 42, 35, 42, 69, 70, 29, 
	34, 73, 62, 62, 68, 76, 35, 76, 
	69, 70, 77, 34, 73, 62, 62, 75, 
	75, 75, 75, 68, 76, 35, 76, 69, 
	70, 77, 34, 73, 62, 62, 68, 68, 
	35, 68, 69, 70, 53, 73, 62, 62, 
	68, 78, 35, 78, 79, 80, 83, 53, 
	53, 78, 57, 35, 57, 54, 58, 53, 
	54, 35, 54, 81, 84, 81, 81, 80, 
	58, 83, 81, 53, 53, 81, 81, 78, 
	81, 78, 78, 82, 35, 82, 81, 79, 
	81, 81, 80, 83, 81, 53, 53, 81, 
	81, 81, 81, 78, 42, 35, 42, 81, 
	79, 81, 81, 80, 29, 83, 81, 53, 
	53, 81, 81, 81, 81, 78, 78, 35, 
	78, 80, 78, 78, 53, 42, 35, 42, 
	79, 80, 29, 83, 53, 53, 78, 86, 
	86, 85, 87, 85, 85, 85, 85, 0, 
	86, 86, 87, 0, 88, 88, 35, 88, 
	89, 88, 89, 35, 89, 90, 175, 90, 
	90, 89, 93, 90, 90, 90, 195, 90, 
	195, 88, 91, 35, 91, 90, 90, 90, 
	89, 90, 90, 90, 90, 90, 88, 92, 
	35, 92, 90, 90, 90, 89, 93, 90, 
	90, 90, 90, 90, 88, 92, 35, 92, 
	89, 93, 88, 88, 35, 88, 89, 94, 
	94, 88, 95, 35, 95, 89, 96, 94, 
	94, 94, 94, 88, 95, 35, 95, 89, 
	96, 88, 97, 35, 97, 98, 97, 97, 
	35, 97, 98, 88, 97, 98, 35, 98, 
	99, 103, 99, 99, 98, 102, 88, 99, 
	99, 99, 168, 99, 168, 97, 100, 35, 
	100, 99, 99, 99, 98, 88, 99, 99, 
	99, 99, 99, 97, 101, 35, 101, 99, 
	99, 99, 98, 102, 88, 99, 99, 99, 
	99, 99, 97, 101, 35, 101, 98, 102, 
	88, 97, 97, 35, 97, 98, 88, 97, 
	97, 97, 103, 35, 103, 104, 105, 34, 
	108, 97, 97, 103, 101, 35, 101, 98, 
	102, 88, 97, 98, 35, 98, 106, 109, 
	106, 106, 105, 102, 34, 108, 106, 97, 
	97, 106, 106, 110, 106, 110, 103, 107, 
	35, 107, 106, 104, 106, 106, 105, 34, 
	108, 106, 97, 97, 106, 106, 106, 106, 
	103, 42, 35, 42, 106, 104, 106, 106, 
	105, 29, 34, 108, 106, 97, 97, 106, 
	106, 106, 106, 103, 103, 35, 103, 105, 
	88, 103, 103, 97, 42, 35, 42, 104, 
	105, 29, 34, 108, 97, 97, 103, 111, 
	35, 111, 104, 105, 112, 34, 108, 97, 
	97, 110, 110, 110, 110, 103, 111, 35, 
	111, 104, 105, 112, 34, 108, 97, 97, 
	103, 113, 35, 113, 104, 172, 128, 162, 
	97, 97, 113, 113, 35, 113, 104, 114, 
	34, 162, 97, 97, 113, 98, 35, 98, 
	115, 109, 115, 115, 114, 102, 34, 162, 
	115, 97, 97, 115, 115, 163, 115, 163, 
	113, 116, 35, 116, 115, 104, 115, 115, 
	114, 128, 162, 115, 97, 97, 115, 115, 
	115, 115, 113, 117, 35, 117, 115, 104, 
	115, 115, 114, 118, 128, 162, 115, 97, 
	97, 115, 115, 115, 115, 113, 117, 35, 
	117, 54, 118, 53, 53, 35, 53, 54, 
	119, 119, 53, 120, 35, 120, 54, 121, 
	119, 119, 119, 119, 53, 120, 35, 120, 
	54, 121, 53, 122, 35, 122, 123, 122, 
	122, 35, 122, 123, 128, 122, 123, 35, 
	123, 124, 147, 124, 124, 123, 127, 128, 
	124, 124, 124, 122, 124, 122, 122, 125, 
	35, 125, 124, 124, 124, 123, 128, 124, 
	124, 124, 124, 124, 122, 126, 35, 126, 
	124, 124, 124, 123, 127, 128, 124, 124, 
	124, 124, 124, 122, 126, 35, 126, 123, 
	127, 128, 122, 122, 35, 122, 123, 128, 
	122, 122, 122, 128, 35, 128, 129, 53, 
	129, 35, 129, 130, 132, 130, 130, 54, 
	118, 130, 130, 130, 138, 130, 138, 53, 
	131, 35, 131, 130, 130, 130, 54, 130, 
	130, 130, 130, 130, 53, 117, 35, 117, 
	130, 130, 130, 54, 118, 130, 130, 130, 
	130, 130, 53, 132, 35, 132, 133, 134, 
	137, 53, 53, 132, 117, 35, 117, 54, 
	118, 53, 54, 35, 54, 135, 84, 135, 
	135, 134, 58, 137, 135, 53, 53, 135, 
	135, 132, 135, 132, 132, 136, 35, 136, 
	135, 133, 135, 135, 134, 137, 135, 53, 
	53, 135, 135, 135, 135, 132, 42, 35, 
	42, 135, 133, 135, 135, 134, 29, 137, 
	135, 53, 53, 135, 135, 135, 135, 132, 
	132, 35, 132, 134, 132, 132, 53, 139, 
	35, 139, 54, 140, 138, 138, 138, 138, 
	53, 139, 35, 139, 54, 140, 53, 53, 
	35, 53, 141, 53, 141, 35, 141, 55, 
	142, 55, 55, 54, 58, 55, 55, 55, 
	53, 55, 53, 53, 142, 35, 142, 79, 
	143, 146, 53, 53, 142, 54, 35, 54, 
	144, 84, 144, 144, 143, 58, 146, 144, 
	53, 53, 144, 144, 142, 144, 142, 142, 
	145, 35, 145, 144, 79, 144, 144, 143, 
	146, 144, 53, 53, 144, 144, 144, 144, 
	142, 117, 35, 117, 144, 79, 144, 144, 
	143, 118, 146, 144, 53, 53, 144, 144, 
	144, 144, 142, 142, 35, 142, 143, 142, 
	142, 53, 147, 35, 147, 148, 149, 34, 
	157, 122, 122, 147, 126, 35, 126, 123, 
	127, 128, 122, 123, 35, 123, 150, 158, 
	150, 150, 149, 127, 34, 157, 150, 122, 
	122, 150, 150, 159, 150, 159, 147, 151, 
	35, 151, 150, 148, 150, 150, 149, 34, 
	157, 150, 122, 122, 150, 150, 150, 150, 
	147, 152, 35, 152, 150, 148, 150, 150, 
	149, 156, 34, 157, 150, 122, 122, 150, 
	150, 150, 150, 147, 152, 153, 152, 156, 
	34, 33, 154, 34, 33, 155, 155, 34, 
	33, 155, 155, 156, 34, 33, 34, 33, 
	33, 33, 147, 35, 147, 149, 128, 147, 
	147, 122, 152, 35, 152, 148, 149, 156, 
	34, 157, 122, 122, 147, 160, 35, 160, 
	148, 149, 161, 34, 157, 122, 122, 159, 
	159, 159, 159, 147, 160, 35, 160, 148, 
	149, 161, 34, 157, 122, 122, 147, 147, 
	35, 147, 148, 149, 128, 157, 122, 122, 
	147, 113, 35, 113, 114, 88, 113, 113, 
	97, 164, 35, 164, 104, 114, 165, 34, 
	162, 97, 97, 163, 163, 163, 163, 113, 
	164, 35, 164, 104, 114, 165, 34, 162, 
	97, 97, 113, 113, 35, 113, 104, 166, 
	128, 162, 97, 97, 113, 167, 35, 167, 
	115, 171, 115, 115, 114, 102, 34, 162, 
	115, 97, 97, 115, 115, 163, 115, 163, 
	113, 167, 35, 167, 99, 113, 99, 99, 
	98, 102, 88, 99, 99, 99, 168, 99, 
	168, 97, 169, 35, 169, 98, 170, 88, 
	168, 168, 168, 168, 97, 169, 35, 169, 
	98, 170, 88, 97, 97, 35, 97, 167, 
	88, 97, 42, 35, 42, 104, 114, 29, 
	34, 162, 97, 97, 113, 167, 35, 167, 
	173, 171, 173, 173, 114, 102, 34, 162, 
	173, 97, 97, 173, 173, 163, 173, 163, 
	113, 174, 35, 174, 173, 104, 173, 173, 
	114, 34, 162, 173, 97, 97, 173, 173, 
	173, 173, 113, 42, 35, 42, 173, 104, 
	173, 173, 114, 29, 34, 162, 173, 97, 
	97, 173, 173, 173, 173, 113, 175, 35, 
	175, 176, 177, 180, 88, 88, 175, 92, 
	35, 92, 89, 93, 88, 89, 35, 89, 
	178, 181, 178, 178, 177, 93, 180, 178, 
	88, 88, 178, 178, 182, 178, 182, 175, 
	179, 35, 179, 178, 176, 178, 178, 177, 
	180, 178, 88, 88, 178, 178, 178, 178, 
	175, 42, 35, 42, 178, 176, 178, 178, 
	177, 29, 180, 178, 88, 88, 178, 178, 
	178, 178, 175, 175, 35, 175, 177, 175, 
	175, 88, 42, 35, 42, 176, 177, 29, 
	180, 88, 88, 175, 183, 35, 183, 176, 
	177, 184, 180, 88, 88, 182, 182, 182, 
	182, 175, 183, 35, 183, 176, 177, 184, 
	180, 88, 88, 175, 185, 35, 185, 176, 
	199, 189, 88, 88, 185, 185, 35, 185, 
	176, 186, 189, 88, 88, 185, 89, 35, 
	89, 187, 181, 187, 187, 186, 93, 189, 
	187, 88, 88, 187, 187, 190, 187, 190, 
	185, 188, 35, 188, 187, 176, 187, 187, 
	186, 189, 187, 88, 88, 187, 187, 187, 
	187, 185, 117, 35, 117, 187, 176, 187, 
	187, 186, 118, 189, 187, 88, 88, 187, 
	187, 187, 187, 185, 185, 35, 185, 186, 
	185, 185, 88, 191, 35, 191, 176, 186, 
	192, 189, 88, 88, 190, 190, 190, 190, 
	185, 191, 35, 191, 176, 186, 192, 189, 
	88, 88, 185, 185, 35, 185, 176, 193, 
	189, 88, 88, 185, 194, 35, 194, 187, 
	198, 187, 187, 186, 93, 189, 187, 88, 
	88, 187, 187, 190, 187, 190, 185, 194, 
	35, 194, 90, 185, 90, 90, 89, 93, 
	90, 90, 90, 195, 90, 195, 88, 196, 
	35, 196, 89, 197, 195, 195, 195, 195, 
	88, 196, 35, 196, 89, 197, 88, 88, 
	35, 88, 194, 88, 42, 35, 42, 176, 
	186, 29, 189, 88, 88, 185, 194, 35, 
	194, 200, 198, 200, 200, 186, 93, 189, 
	200, 88, 88, 200, 200, 190, 200, 190, 
	185, 201, 35, 201, 200, 176, 200, 200, 
	186, 189, 200, 88, 88, 200, 200, 200, 
	200, 185, 42, 35, 42, 200, 176, 200, 
	200, 186, 29, 189, 200, 88, 88, 200, 
	200, 200, 200, 185, 0, 0
};

static const char _tsip_machine_parser_header_P_Preferred_Identity_trans_actions[] = {
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 1, 1, 1, 1, 0, 1, 1, 
	1, 1, 1, 1, 1, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 1, 1, 
	1, 1, 0, 1, 1, 1, 1, 1, 
	1, 1, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 1, 1, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 3, 0, 0, 
	0, 0, 0, 0, 7, 0, 0, 0, 
	0, 1, 1, 1, 1, 0, 1, 1, 
	1, 1, 1, 1, 1, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 1, 1, 
	1, 1, 0, 1, 1, 1, 1, 1, 
	1, 1, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	5, 5, 5, 0, 0, 0, 5, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 5, 5, 5, 5, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 3, 3, 3, 3, 0, 
	3, 3, 3, 1, 1, 1, 1, 3, 
	0, 1, 1, 1, 1, 1, 1, 0, 
	3, 3, 3, 0, 0, 0, 3, 0, 
	0, 0, 0, 0, 0, 12, 3, 12, 
	0, 0, 0, 3, 5, 0, 0, 0, 
	0, 0, 0, 3, 3, 3, 3, 0, 
	0, 3, 3, 3, 3, 1, 1, 0, 
	3, 3, 3, 3, 0, 0, 0, 0, 
	0, 0, 3, 3, 3, 3, 0, 0, 
	3, 3, 3, 3, 0, 3, 3, 3, 
	3, 3, 0, 3, 3, 3, 1, 1, 
	1, 1, 3, 0, 3, 1, 1, 1, 
	1, 1, 1, 0, 3, 3, 3, 0, 
	0, 0, 3, 3, 0, 0, 0, 0, 
	0, 0, 12, 3, 12, 0, 0, 0, 
	3, 5, 3, 0, 0, 0, 0, 0, 
	0, 3, 3, 3, 3, 0, 3, 0, 
	3, 3, 3, 3, 3, 1, 1, 0, 
	3, 3, 3, 0, 3, 3, 0, 0, 
	0, 0, 12, 3, 12, 3, 5, 3, 
	0, 3, 3, 3, 1, 1, 1, 1, 
	3, 0, 3, 0, 1, 0, 0, 1, 
	1, 1, 1, 1, 0, 3, 3, 3, 
	0, 0, 0, 0, 3, 3, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 5, 
	3, 5, 0, 0, 0, 0, 3, 5, 
	3, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 3, 3, 3, 3, 3, 0, 
	0, 0, 5, 3, 5, 0, 3, 5, 
	3, 0, 0, 0, 0, 3, 3, 3, 
	0, 3, 0, 3, 0, 0, 0, 0, 
	0, 0, 0, 0, 3, 3, 3, 0, 
	3, 0, 3, 0, 0, 0, 0, 3, 
	3, 3, 0, 3, 3, 0, 0, 0, 
	0, 3, 3, 3, 0, 3, 0, 0, 
	0, 0, 12, 3, 12, 3, 5, 0, 
	3, 3, 3, 1, 1, 1, 1, 3, 
	0, 0, 1, 0, 0, 1, 1, 1, 
	1, 1, 0, 3, 3, 3, 0, 0, 
	0, 0, 3, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 5, 3, 5, 0, 
	0, 0, 0, 3, 5, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 3, 3, 
	3, 3, 0, 0, 0, 5, 3, 5, 
	0, 3, 5, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 3, 3, 3, 
	3, 0, 3, 3, 3, 1, 1, 1, 
	1, 3, 0, 1, 1, 1, 1, 1, 
	1, 0, 3, 3, 3, 0, 0, 0, 
	3, 0, 0, 0, 0, 0, 0, 9, 
	3, 9, 0, 0, 0, 3, 5, 0, 
	0, 0, 0, 0, 0, 3, 3, 3, 
	3, 0, 0, 3, 3, 3, 3, 1, 
	1, 0, 3, 3, 3, 3, 0, 0, 
	0, 0, 0, 0, 3, 3, 3, 3, 
	0, 0, 3, 3, 3, 3, 0, 3, 
	3, 3, 3, 3, 0, 3, 3, 3, 
	1, 1, 1, 1, 3, 0, 3, 1, 
	1, 1, 1, 1, 1, 0, 3, 3, 
	3, 0, 0, 0, 3, 3, 0, 0, 
	0, 0, 0, 0, 9, 3, 9, 0, 
	0, 0, 3, 5, 3, 0, 0, 0, 
	0, 0, 0, 3, 3, 3, 3, 0, 
	3, 0, 3, 3, 3, 3, 3, 1, 
	1, 0, 3, 3, 3, 0, 3, 3, 
	0, 0, 0, 0, 9, 3, 9, 3, 
	5, 3, 0, 3, 3, 3, 1, 1, 
	1, 1, 3, 0, 3, 0, 1, 0, 
	0, 1, 1, 1, 1, 1, 0, 3, 
	3, 3, 0, 0, 0, 0, 3, 3, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 5, 3, 5, 0, 0, 0, 0, 
	3, 5, 3, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 3, 3, 3, 3, 
	3, 0, 0, 0, 5, 3, 5, 0, 
	3, 5, 3, 0, 0, 0, 0, 3, 
	3, 3, 0, 3, 0, 3, 0, 0, 
	0, 0, 0, 0, 0, 0, 3, 3, 
	3, 0, 3, 0, 3, 0, 0, 0, 
	0, 3, 3, 3, 0, 3, 3, 0, 
	0, 0, 0, 3, 3, 3, 0, 3, 
	3, 0, 0, 0, 0, 3, 3, 3, 
	1, 1, 1, 1, 3, 0, 3, 0, 
	1, 0, 0, 1, 1, 1, 1, 1, 
	0, 3, 3, 3, 0, 0, 0, 0, 
	3, 3, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 12, 3, 12, 0, 0, 
	0, 0, 3, 5, 3, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 3, 3, 
	3, 3, 0, 0, 3, 3, 3, 3, 
	1, 1, 0, 3, 3, 3, 3, 0, 
	0, 0, 0, 0, 0, 3, 3, 3, 
	3, 0, 0, 3, 3, 3, 3, 0, 
	3, 3, 3, 3, 3, 0, 3, 3, 
	3, 1, 1, 1, 1, 3, 0, 3, 
	1, 1, 1, 1, 1, 1, 0, 3, 
	3, 3, 0, 0, 0, 3, 3, 0, 
	0, 0, 0, 0, 0, 12, 3, 12, 
	0, 0, 0, 3, 5, 3, 0, 0, 
	0, 0, 0, 0, 3, 3, 3, 3, 
	0, 3, 0, 3, 3, 3, 3, 3, 
	1, 1, 0, 3, 3, 3, 3, 0, 
	3, 3, 3, 1, 1, 1, 1, 3, 
	0, 1, 1, 1, 1, 1, 1, 0, 
	3, 3, 3, 0, 0, 0, 3, 0, 
	0, 0, 0, 0, 0, 12, 3, 12, 
	0, 0, 0, 3, 5, 0, 0, 0, 
	0, 0, 0, 3, 3, 3, 0, 3, 
	0, 0, 0, 0, 12, 3, 12, 3, 
	5, 0, 3, 3, 3, 1, 1, 1, 
	1, 3, 0, 0, 1, 0, 0, 1, 
	1, 1, 1, 1, 0, 3, 3, 3, 
	0, 0, 0, 0, 3, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 5, 3, 
	5, 0, 0, 0, 0, 3, 5, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	3, 3, 3, 3, 0, 0, 0, 3, 
	3, 3, 3, 0, 0, 0, 0, 0, 
	0, 3, 3, 3, 3, 0, 0, 3, 
	3, 3, 3, 0, 3, 3, 3, 1, 
	1, 1, 1, 3, 0, 1, 1, 1, 
	1, 1, 1, 0, 3, 3, 3, 0, 
	3, 0, 0, 0, 0, 3, 3, 3, 
	1, 1, 1, 1, 3, 0, 0, 1, 
	0, 0, 1, 1, 1, 1, 1, 0, 
	3, 3, 3, 0, 0, 0, 0, 3, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 12, 3, 12, 0, 0, 0, 0, 
	3, 5, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 3, 3, 3, 3, 0, 
	0, 0, 3, 3, 3, 0, 3, 3, 
	0, 0, 0, 0, 12, 3, 12, 3, 
	5, 3, 0, 3, 3, 3, 1, 1, 
	1, 1, 3, 0, 3, 0, 1, 0, 
	0, 1, 1, 1, 1, 1, 0, 3, 
	3, 3, 0, 0, 0, 0, 3, 3, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 5, 3, 5, 0, 0, 0, 0, 
	3, 5, 3, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	3, 0, 0, 3, 0, 0, 0, 3, 
	0, 0, 0, 0, 3, 0, 3, 1, 
	1, 0, 3, 3, 3, 3, 3, 0, 
	0, 0, 5, 3, 5, 0, 3, 5, 
	3, 0, 0, 0, 0, 3, 3, 3, 
	0, 3, 0, 3, 0, 0, 0, 0, 
	0, 0, 0, 0, 3, 3, 3, 0, 
	3, 0, 3, 0, 0, 0, 0, 3, 
	3, 3, 0, 3, 3, 0, 0, 0, 
	0, 3, 3, 3, 3, 3, 0, 0, 
	0, 3, 3, 3, 0, 3, 0, 3, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	3, 3, 3, 0, 3, 0, 3, 0, 
	0, 0, 0, 3, 3, 3, 0, 3, 
	3, 0, 0, 0, 0, 3, 3, 3, 
	1, 1, 1, 1, 3, 0, 3, 0, 
	1, 0, 0, 1, 1, 1, 1, 1, 
	0, 3, 3, 3, 1, 1, 1, 1, 
	3, 0, 3, 1, 1, 1, 1, 1, 
	1, 0, 3, 3, 3, 3, 0, 3, 
	0, 0, 0, 0, 0, 3, 3, 3, 
	3, 0, 3, 0, 3, 3, 3, 3, 
	3, 0, 5, 3, 5, 0, 3, 5, 
	3, 0, 0, 0, 0, 3, 3, 3, 
	1, 1, 1, 1, 3, 0, 3, 0, 
	1, 0, 0, 1, 1, 1, 1, 1, 
	0, 3, 3, 3, 0, 0, 0, 0, 
	3, 3, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 5, 3, 5, 0, 0, 
	0, 0, 3, 5, 3, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 3, 3, 
	3, 0, 3, 0, 0, 0, 0, 9, 
	3, 9, 3, 5, 0, 3, 3, 3, 
	1, 1, 1, 1, 3, 0, 0, 1, 
	0, 0, 1, 1, 1, 1, 1, 0, 
	3, 3, 3, 0, 0, 0, 0, 3, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 5, 3, 5, 0, 0, 0, 0, 
	3, 5, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 3, 3, 3, 3, 0, 
	0, 0, 5, 3, 5, 0, 3, 5, 
	0, 0, 0, 0, 3, 3, 3, 0, 
	3, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 3, 3, 3, 0, 3, 0, 
	0, 0, 0, 0, 3, 3, 3, 0, 
	3, 0, 0, 0, 0, 3, 3, 3, 
	0, 3, 0, 0, 0, 0, 3, 3, 
	3, 1, 1, 1, 1, 3, 0, 0, 
	1, 0, 0, 1, 1, 1, 1, 1, 
	0, 3, 3, 3, 0, 0, 0, 0, 
	3, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 12, 3, 12, 0, 0, 0, 
	0, 3, 5, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 3, 3, 3, 3, 
	0, 0, 0, 3, 3, 3, 0, 3, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 3, 3, 3, 0, 3, 0, 0, 
	0, 0, 0, 3, 3, 3, 0, 3, 
	0, 0, 0, 0, 3, 3, 3, 1, 
	1, 1, 1, 3, 0, 0, 1, 0, 
	0, 1, 1, 1, 1, 1, 0, 3, 
	3, 3, 1, 1, 1, 1, 3, 0, 
	1, 1, 1, 1, 1, 1, 0, 3, 
	3, 3, 3, 0, 0, 0, 0, 0, 
	0, 3, 3, 3, 3, 0, 0, 3, 
	3, 3, 3, 0, 5, 3, 5, 0, 
	3, 5, 0, 0, 0, 0, 3, 3, 
	3, 1, 1, 1, 1, 3, 0, 0, 
	1, 0, 0, 1, 1, 1, 1, 1, 
	0, 3, 3, 3, 0, 0, 0, 0, 
	3, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 5, 3, 5, 0, 0, 0, 
	0, 3, 5, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0
};

static const int tsip_machine_parser_header_P_Preferred_Identity_start = 1;
static const int tsip_machine_parser_header_P_Preferred_Identity_first_final = 202;
static const int tsip_machine_parser_header_P_Preferred_Identity_error = 0;

static const int tsip_machine_parser_header_P_Preferred_Identity_en_main = 1;


/* #line 128 "./ragel/tsip_parser_header_P_Preferred_Identity.rl" */
	
/* #line 1003 "./src/headers/tsip_header_P_Preferred_Identity.c" */
	{
	cs = tsip_machine_parser_header_P_Preferred_Identity_start;
	}

/* #line 129 "./ragel/tsip_parser_header_P_Preferred_Identity.rl" */
	
/* #line 1010 "./src/headers/tsip_header_P_Preferred_Identity.c" */
	{
	int _klen;
	unsigned int _trans;
	const char *_acts;
	unsigned int _nacts;
	const char *_keys;

	if ( p == pe )
		goto _test_eof;
	if ( cs == 0 )
		goto _out;
_resume:
	_keys = _tsip_machine_parser_header_P_Preferred_Identity_trans_keys + _tsip_machine_parser_header_P_Preferred_Identity_key_offsets[cs];
	_trans = _tsip_machine_parser_header_P_Preferred_Identity_index_offsets[cs];

	_klen = _tsip_machine_parser_header_P_Preferred_Identity_single_lengths[cs];
	if ( _klen > 0 ) {
		const char *_lower = _keys;
		const char *_mid;
		const char *_upper = _keys + _klen - 1;
		while (1) {
			if ( _upper < _lower )
				break;

			_mid = _lower + ((_upper-_lower) >> 1);
			if ( (*p) < *_mid )
				_upper = _mid - 1;
			else if ( (*p) > *_mid )
				_lower = _mid + 1;
			else {
				_trans += (_mid - _keys);
				goto _match;
			}
		}
		_keys += _klen;
		_trans += _klen;
	}

	_klen = _tsip_machine_parser_header_P_Preferred_Identity_range_lengths[cs];
	if ( _klen > 0 ) {
		const char *_lower = _keys;
		const char *_mid;
		const char *_upper = _keys + (_klen<<1) - 2;
		while (1) {
			if ( _upper < _lower )
				break;

			_mid = _lower + (((_upper-_lower) >> 1) & ~1);
			if ( (*p) < _mid[0] )
				_upper = _mid - 2;
			else if ( (*p) > _mid[1] )
				_lower = _mid + 2;
			else {
				_trans += ((_mid - _keys)>>1);
				goto _match;
			}
		}
		_trans += _klen;
	}

_match:
	cs = _tsip_machine_parser_header_P_Preferred_Identity_trans_targs[_trans];

	if ( _tsip_machine_parser_header_P_Preferred_Identity_trans_actions[_trans] == 0 )
		goto _again;

	_acts = _tsip_machine_parser_header_P_Preferred_Identity_actions + _tsip_machine_parser_header_P_Preferred_Identity_trans_actions[_trans];
	_nacts = (unsigned int) *_acts++;
	while ( _nacts-- > 0 )
	{
		switch ( *_acts++ )
		{
	case 0:
/* #line 57 "./ragel/tsip_parser_header_P_Preferred_Identity.rl" */
	{
		tag_start = p;
	}
	break;
	case 1:
/* #line 61 "./ragel/tsip_parser_header_P_Preferred_Identity.rl" */
	{	
		if(!hdr_pi->uri) /* Only one URI */{
			int len = (int)(p  - tag_start);
			hdr_pi->uri = tsip_uri_parse(tag_start, (size_t)len);
		}
	}
	break;
	case 2:
/* #line 68 "./ragel/tsip_parser_header_P_Preferred_Identity.rl" */
	{
		if(!hdr_pi->display_name){
			TSK_PARSER_SET_STRING(hdr_pi->display_name);
		}

	}
	break;
	case 3:
/* #line 75 "./ragel/tsip_parser_header_P_Preferred_Identity.rl" */
	{
	}
	break;
/* #line 1112 "./src/headers/tsip_header_P_Preferred_Identity.c" */
		}
	}

_again:
	if ( cs == 0 )
		goto _out;
	if ( ++p != pe )
		goto _resume;
	_test_eof: {}
	_out: {}
	}

/* #line 130 "./ragel/tsip_parser_header_P_Preferred_Identity.rl" */
	
	if( cs < 
/* #line 1128 "./src/headers/tsip_header_P_Preferred_Identity.c" */
202
/* #line 131 "./ragel/tsip_parser_header_P_Preferred_Identity.rl" */
 ){
		TSK_DEBUG_ERROR("Failed to parse 'P-Preferred-Identity' header.");
		TSK_OBJECT_SAFE_FREE(hdr_pi);
	}
	
	return hdr_pi;
}







//========================================================
//	P_Preferred_Identity header object definition
//

static tsk_object_t* tsip_header_P_Preferred_Identity_ctor(tsk_object_t *self, va_list * app)
{
	tsip_header_P_Preferred_Identity_t *P_Preferred_Identity = self;
	if(P_Preferred_Identity){
		const tsip_uri_t* uri = va_arg(*app, const tsip_uri_t*);

		TSIP_HEADER(P_Preferred_Identity)->type = tsip_htype_P_Preferred_Identity;
		TSIP_HEADER(P_Preferred_Identity)->tostring = tsip_header_Preferred_Identity_tostring;

		if(uri){
			P_Preferred_Identity->uri = tsk_object_ref((void*)uri);
		}
	}
	else{
		TSK_DEBUG_ERROR("Failed to create new P_Preferred_Identity header.");
	}
	return self;
}

static tsk_object_t* tsip_header_P_Preferred_Identity_dtor(tsk_object_t *self)
{
	tsip_header_P_Preferred_Identity_t *P_Preferred_Identity = self;
	if(P_Preferred_Identity){
		TSK_FREE(P_Preferred_Identity->display_name);
		TSK_OBJECT_SAFE_FREE(P_Preferred_Identity->uri);
	}
	else{
		TSK_DEBUG_ERROR("Null P_Preferred_Identity header.");
	}

	return self;
}

static const tsk_object_def_t tsip_header_P_Preferred_Identity_def_s = 
{
	sizeof(tsip_header_P_Preferred_Identity_t),
	tsip_header_P_Preferred_Identity_ctor,
	tsip_header_P_Preferred_Identity_dtor,
	tsk_null
};
const tsk_object_def_t *tsip_header_P_Preferred_Identity_def_t = &tsip_header_P_Preferred_Identity_def_s;
