/****************************************************************************
			 _             _                             
			| |           | |                            
		  _ | | ___  _   _| | _   ____ ____   ____  ___  
		 / || |/ _ \| | | | || \ / _  |  _ \ / _  |/ _ \ 
		( (_| | |_| | |_| | |_) | ( | | | | ( ( | | |_| |
		 \____|\___/ \____|____/ \_||_|_| |_|\_|| |\___/ 
											(_____|   
	
	Copyright (C) 2009 xxxyyyzzz <imsframework(at)gmail.com>

	This file is part of Open Source Doubango IMS Client Framework project.

    DOUBANGO is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
	
    DOUBANGO is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.
	
    You should have received a copy of the GNU General Public License
    along with DOUBANGO.
****************************************************************************/

#include "xdm_api.h" 

#ifndef TEST_XCAP_CAPS
#define TEST_XCAP_CAPS
const char* xcap_caps_str0 = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
								"<xcap-caps xmlns=\"urn:ietf:params:xml:ns:xcap-caps\""
								"		xmlns:xsi=\"htt//www.w3.org/2001/XMLSchema-instance\""
								"		xsi:schemaLocation=\"urn:ietf:params:xml:ns:xcap-caps xcap-caps.xsd \">"
								"	<auids>"
								"		<auid>xcap-caps</auid>"
								"		<auid>resource-lists</auid>"
								"		<auid>rls-services</auid>"
								"		<auid>org.openmobilealliance.xcap-directory</auid>"
								 "  </auids>"
								  "<extensions>"
								"	  <!-- No extensions defined -->"
								 " </extensions>"
								  "<namespaces>"
								"	  <namespace>urn:ietf:params:xml:ns:xcap-caps</namespace>"
								"	  <namespace>urn:ietf:params:xml:ns:xcap-error</namespace>"
								"	  <namespace>urn:ietf:params:xml:ns:resource-lists</namespace>"
								"	  <namespace>urn:ietf:params:xml:ns:rls-services</namespace>"
								"	  <namespace>urn:oma:params:ns:resource-list:oma-uriusage</namespace>"
								 " </namespaces>"
								"</xcap-caps>";

/* test xcap-caps */
void test_xcap_caps(const char* buffer, size_t size)
{
	xcap_caps_t* xcap_caps = 0;
	xdm_list_item_t* item = 0;
	printf("\n---\nTEST XCAP-CAPS\n---\n");
	{
		xcap_caps = xdm_xcap_caps_create(buffer, size);

		/* dump namespaces */
		xdm_list_foreach(item, xcap_caps->namespaces)
			printf("namespace: %s\n", ((char*)item->data));
		/* dump extensions */
		xdm_list_foreach(item, xcap_caps->extensions)
			printf("extension: %s\n", ((char*)item->data));
		/* dump auids */
		xdm_list_foreach(item, xcap_caps->auids)
			printf("auid: %s\n", ((char*)item->data));

		xdm_xcap_caps_free(&xcap_caps);
	}
}
#endif