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
#include "txc.h"
#include "txc_macros.h"
#include "tsk_macros.h"

#define PANIC_AND_JUMP(code, request)\
	{\
	request->panic = code; \
	goto bail;\
	}

/* get content type */
static const char* get_mime_type(const txc_context_t* context, const txc_request_t* request, txc_selection_type_t sel)
{
	/* return the user provided content type */
	if(request && request->content && request->content->type) return request->content->type;
	
	switch(sel)
	{
	case sl_element:return TXC_MIME_TYPE_ELEMENT;
	case sl_document: 
		{
			const txc_auid_t* auid = txc_auid_findby_name(context->auids, request->auid);
			return auid?auid->content_type:"application/unknown+xml";
		}
	case sl_attribute:return TXC_MIME_TYPE_ATTRIBUTE;
	default: return "application/unknown+xml";
	}/* switch */
}

/* init content */
void txc_content_init(txc_content_t *content)
{
	memset(content, 0, sizeof(txc_content_t));
}

/* set content values */
void txc_content_set(txc_content_t* content, const char *data, size_t size, const char *type)
{
	if(content)
	{
		tsk_strupdate(0, &(content->data), data);
		tsk_strupdate(0, &(content->type), type);
		content->size = size;
	}
}

/* free content */
void txc_content_free(txc_content_t** content)
{
	if(*content)
	{
		TSK_FREE((*content)->data);
		TSK_FREE((*content)->type);
		
		free(*content);
		(*content) = 0;
	}
}

/* init auid */
void txc_auid_init(txc_auid_t *auid)
{
	memset(auid, 0, sizeof(txc_auid_t));
}

/* find auid object by type */
txc_auid_t* txc_auid_findby_type(const txc_auid_L_t* auids, xcap_auid_type_t auid_type)
{
	tsk_list_item_t* item = 0;

	if(!auids) return 0;

	tsk_list_foreach(item, auids)
	{
		txc_auid_t *auid = ((txc_auid_t*)item->data);
		if(auid->type == auid_type)
		{
			return auid;
		}
	}
	return 0;
}

/* find auid object by type */
txc_auid_t* txc_auid_findby_name(const txc_auid_L_t* auids, const char* name)
{
	tsk_list_item_t* item = 0;

	if(!auids) return 0;

	tsk_list_foreach(item, auids)
	{
		txc_auid_t *auid = ((txc_auid_t*)item->data);
		if(!tsk_stricmp(auid->name, name))
		{
			return auid;
		}
	}
	return 0;
}

/* returns 1 if availabe and 0 otherwise */
int txc_auid_is_available(const txc_auid_L_t* auids, xcap_auid_type_t type)
{
	const txc_auid_t *auid = txc_auid_findby_type(auids, type);
	return (auid && auid->available) ? 1 : 0;
}

/* change auid availability */
void txc_auid_set_availability(const txc_auid_L_t* auids, xcap_auid_type_t type, int avail)
{
	txc_auid_t* auid = txc_auid_findby_type(auids, type);
	if(auid)
	{
		auid->available = avail;
	}
}

/* change the document name of the auid with type=@type */
void txc_auid_update(txc_context_t* context, xcap_auid_type_t type, const char* document)
{
	txc_auid_t* auid = txc_auid_findby_type(context->auids, type);
	if(auid)
	{
		tsk_strupdate(0, &(auid->document), document);
	}
}

/* free auid */
void txc_auid_free(void **_auid)
{
	txc_auid_t **auid = (txc_auid_t **)_auid;
	TSK_FREE((*auid)->name);
	TSK_FREE((*auid)->description);
	TSK_FREE((*auid)->content_type);
	TSK_FREE((*auid)->document);

	tsk_free(0, _auid);
}

/* initialize xdm context */
/* ATTENTION: context MUST be initialized before use*/
void txc_context_init(txc_context_t* context)
{
	int i;

	memset(context, 0, sizeof(txc_context_t));

	/* copy all default auids */
	TSK_LIST_CREATE(context->auids);
	for(i = 0; i< (sizeof(txc_auids)/sizeof(txc_auid_t)); i++)
	{
		txc_auid_t* auid = 0;
		TXC_AUID_CREATE(auid);

		auid->type = txc_auids[i].type;
		auid->available = txc_auids[i].available;
		auid->content_type = tsk_strdup(0, txc_auids[i].content_type);
		auid->description = tsk_strdup(0, txc_auids[i].description);
		auid->document = tsk_strdup(0, txc_auids[i].document);
		auid->name = tsk_strdup(0, txc_auids[i].name);
		
		tsk_list_add_data((context->auids), ((void**)&auid), txc_auid_free);
	}

	/* initialize libcurl */
#ifdef WIN32
	curl_global_init(CURL_GLOBAL_WIN32);
#else
	curl_global_init();
#endif
}

/* update available auids using those provided by the xdms */
void txc_conttext_update_available_auids(txc_context_t *context, const tsk_list_t* avail_auids)
{
	tsk_list_item_t *item = 0;
	
	if(!context || !avail_auids) return;

	/* avail auids */
	tsk_list_foreach(item, avail_auids)
	{
		/* context auids */
		txc_auid_t* auid = txc_auid_findby_name(context->auids, ((const char*)item->data));
		if(auid && !(auid->available)) auid->available = 1;
	}
}

/* free a previously initialized context */
void txc_context_free(txc_context_t** context)
{
	TSK_FREE((*context)->txc_root);
	TSK_FREE((*context)->xui);
	TSK_FREE((*context)->password);
	TSK_FREE((*context)->proxy_host);
	TSK_FREE((*context)->proxy_usr);
	TSK_FREE((*context)->proxy_pwd);
	TSK_FREE((*context)->user_agent);
	TSK_FREE((*context)->pragma);
	TSK_LIST_SAFE_FREE((*context)->auids);
	TXC_EASYHANDLE_SAFE_FREE((*context)->easyhandle);

	tsk_free(0, context);

	/* cleanup libcurl */
	curl_global_cleanup();
}

/* initialize xdm request */
/* ATTENTION: request MUST be initialized before use*/
void txc_request_init(txc_request_t* request)
{
	memset(request, 0, sizeof(txc_request_t));
	TXC_CONTENT_CREATE(request->content);

	request->status = 0;
	request->panic = xpa_success;
	request->timeout = TXC_HTTP_DEFAULT_TIMEOUT;
}

/* free a previously initialized request */
void txc_request_free(txc_request_t** request)
{
	TSK_FREE((*request)->auid);
	TSK_FREE((*request)->url);
	TSK_FREE((*request)->http_accept);
	TSK_FREE((*request)->http_expect);
	TXC_CONTENT_SAFE_FREE((*request)->content);
	
	tsk_free(0, request);
}

/* libcurl write callback */
size_t write_data(void *buffer, size_t size, size_t nmemb, txc_content_t *userp)
{
	size_t total_size = (size * nmemb);
	if(!userp) return -1;
	
	/* new chinck ==> realloc */
	userp->data = (char *)realloc(userp->data, (1 + userp->size + total_size));
	if (userp->data)
	{	/* append new chunck */
		memcpy(userp->data + userp->size, buffer, total_size);
		userp->size += total_size;
		userp->data[userp->size] = '\0';
	}
	return total_size;
}

/* libcurl read callback */
size_t read_data(void *buffer, size_t size, size_t nmemb, txc_content_t *userp)
{
	size_t bytes_to_copy = 0;
    if(!userp) return -1;
	
	if(userp->cursor >= userp->size) return 0;

    bytes_to_copy = nmemb < userp->size ? nmemb : userp->size;
    memcpy(buffer, userp->data, bytes_to_copy);
    userp->cursor += bytes_to_copy;
    return bytes_to_copy;
}

/* ioctl function to handle HTTP PUT or POST with a multi-pass authentication method */
curlioerr ioctl_callback(CURL *handle, int cmd, txc_content_t *userp)
{
    switch (cmd) 
	{
    case CURLIOCMD_NOP: return CURLIOE_OK;
    case CURLIOCMD_RESTARTREAD:
		{
			userp->cursor = 0;
			return CURLIOE_OK;
		}
    default: return CURLIOE_UNKNOWNCMD;
    }
}

/* perform xcap operation */
/* returns 0 if success and false otherwise. check request panic code for more information */
/* if request panic code is equal to 'xpa_libcurl_error', then you should check the return code*/
int txc_xcap_perform(txc_context_t* context, txc_request_t* request, txc_oper_type_t oper, txc_selection_type_t sel)
{
	struct curl_slist *headers = 0;
	CURLcode code = CURLE_OK;
	char* temp_str = 0;
	
	/* check context */
	TXC_CONTEXT_CHECK(context, request->panic);

	/* Get an easy handle */
	if(!context->easyhandle) context->easyhandle = curl_easy_init();
	else if(!(context->reuse_http_connection)){
		curl_easy_cleanup(context->easyhandle);
		context->easyhandle = curl_easy_init();
	}
	if(!context->easyhandle) PANIC_AND_JUMP(xpa_libcurl_error, request)

#if DEBUG || _DEBUG
		curl_easy_setopt(context->easyhandle, CURLOPT_VERBOSE, 1);
#endif

	/* set xcap URL */
	if(request->url && (code=curl_easy_setopt(context->easyhandle, CURLOPT_URL, request->url)))
		PANIC_AND_JUMP(xpa_libcurl_error, request)

	/* set request timeout */
	if(code=curl_easy_setopt(context->easyhandle, CURLOPT_TIMEOUT, request->timeout/1000))
		PANIC_AND_JUMP(xpa_libcurl_error, request)

	switch(oper)
	{
		case op_fetch:
			{	/* GET */
				curl_easy_setopt(context->easyhandle, CURLOPT_CUSTOMREQUEST, "GET");

				/* tell libcurl to pass all data to this function */
				if(code=curl_easy_setopt(context->easyhandle, CURLOPT_WRITEFUNCTION, write_data))
					PANIC_AND_JUMP(xpa_libcurl_error, request)
				
				/* set data for our callback  */
				if(code=curl_easy_setopt(context->easyhandle, CURLOPT_WRITEDATA, (request->content)))
					PANIC_AND_JUMP(xpa_libcurl_error, request)
					
				break;
			}

		case op_create:
		case op_replace:
			{	/* PUT */
				curl_easy_setopt(context->easyhandle, CURLOPT_CUSTOMREQUEST, "PUT");

				/* read callback */
				if(code=curl_easy_setopt(context->easyhandle, CURLOPT_READFUNCTION, read_data))
					PANIC_AND_JUMP(xpa_libcurl_error, request)
				if(code=curl_easy_setopt(context->easyhandle, CURLOPT_UPLOAD, 1L))
					PANIC_AND_JUMP(xpa_libcurl_error, request)
				
				/* content */
				if(request->content && request->content->data && request->content->size)
				{
					/* content data*/
					if(code=curl_easy_setopt(context->easyhandle, CURLOPT_READDATA , (request->content)))
						PANIC_AND_JUMP(xpa_libcurl_error, request)

					/* content length */
					tsk_sprintf(0, &temp_str, "Content-Length: %u", request->content->size);
					headers = curl_slist_append(headers, temp_str);
					TSK_SAFE_FREE2(temp_str);
					
					/* ioctl function callback */
					if(code=curl_easy_setopt(context->easyhandle, CURLOPT_IOCTLFUNCTION , ioctl_callback))
						PANIC_AND_JUMP(xpa_libcurl_error, request)
					
					/* ioctl data */
					if(code=curl_easy_setopt(context->easyhandle, CURLOPT_IOCTLDATA , (request->content)))
						PANIC_AND_JUMP(xpa_libcurl_error, request)
				}
				break;
			}

		case op_delete:
			{	/* DELETE */
				 curl_easy_setopt(context->easyhandle, CURLOPT_CUSTOMREQUEST, "DELETE"); 
				break;
			}
	}/* switch */

	/* set user name */
	if(context->xui && (code=curl_easy_setopt(context->easyhandle, CURLOPT_USERNAME, context->xui)))
		PANIC_AND_JUMP(xpa_libcurl_error, request)

	/* set user password */
	if(context->password && (code=curl_easy_setopt(context->easyhandle, CURLOPT_PASSWORD, context->password)))
		PANIC_AND_JUMP(xpa_libcurl_error, request)

	/* authentication type */
	if((code=curl_easy_setopt(context->easyhandle, CURLOPT_HTTPAUTH, CURLAUTH_ANY)) ||
		(code=curl_easy_setopt(context->easyhandle, CURLOPT_PROXYAUTH, CURLAUTH_ANY)))
			PANIC_AND_JUMP(xpa_libcurl_error, request)
	
	/* set user-agent */
	if(context->user_agent && (code=curl_easy_setopt(context->easyhandle, CURLOPT_USERAGENT, context->user_agent)))
		PANIC_AND_JUMP(xpa_libcurl_error, request)

	/* X-3GPP-Intended-Identity */
	tsk_sprintf(0, &temp_str, "X-3GPP-Intended-Identity: \"%s\"", context->xui);
	headers = curl_slist_append(headers, temp_str);
	TSK_SAFE_FREE2(temp_str);

	/* Content-Type */
	tsk_sprintf(0, &temp_str, "Content-Type: %s", get_mime_type(context, request, sel));
	headers = curl_slist_append(headers, temp_str);
	TSK_SAFE_FREE2(temp_str);
	
	/* set proxy host */
	if(context->proxy_host && (code=curl_easy_setopt(context->easyhandle, CURLOPT_PROXY, context->proxy_host)))
		PANIC_AND_JUMP(xpa_libcurl_error, request)

	/* set proxy port */
	if(context->proxy_port && (code=curl_easy_setopt(context->easyhandle, CURLOPT_PROXYPORT, context->proxy_port)))
		PANIC_AND_JUMP(xpa_libcurl_error, request)

	/* set proxy usr*/
	if(context->proxy_usr && (code=curl_easy_setopt(context->easyhandle, CURLOPT_PROXYUSERNAME, context->proxy_usr)))
		PANIC_AND_JUMP(xpa_libcurl_error, request)

	/* set proxy pwd */
	if(context->proxy_pwd && (code=curl_easy_setopt(context->easyhandle, CURLOPT_PROXYPASSWORD, context->proxy_pwd)))
		PANIC_AND_JUMP(xpa_libcurl_error, request)

	/* http proxy tunneling? */
	if(context->proxy_tunneling && (code=curl_easy_setopt(context->easyhandle, CURLOPT_HTTPPROXYTUNNEL, 1L)))
		PANIC_AND_JUMP(xpa_libcurl_error, request)

	/* Pragma */
	if(context->pragma)
	{
		tsk_sprintf(0, &temp_str, "Pragma: %s", context->pragma);
		headers = curl_slist_append(headers, temp_str);
		TSK_SAFE_FREE2(temp_str);
	}

	/* Accept */
	if(request->http_accept)
	{
		tsk_sprintf(0, &temp_str, "Accept: \"%s\"", request->http_accept);
		headers = curl_slist_append(headers, temp_str);
		TSK_SAFE_FREE2(temp_str);
	}
	else headers = curl_slist_append(headers, "Accept:");
	

	/* Expect */
	if(request->http_expect)
	{
		tsk_sprintf(0, &temp_str, "Expect: %s", request->http_expect);
		headers = curl_slist_append(headers, temp_str);
		TSK_SAFE_FREE2(temp_str);
	}
	
	/* pass our list of custom made headers */
	if(code=curl_easy_setopt(context->easyhandle, CURLOPT_HTTPHEADER, headers))
		PANIC_AND_JUMP(xpa_libcurl_error, request)

	/*** perform operation ***/
	if(code=curl_easy_perform(context->easyhandle))
		PANIC_AND_JUMP(xpa_libcurl_error, request)
	
	/* get response code */
	if(code=curl_easy_getinfo(context->easyhandle, CURLINFO_RESPONSE_CODE, &(request->status)))
		PANIC_AND_JUMP(xpa_libcurl_error, request)
	
	/* get response content-type */
	if(code=curl_easy_getinfo(context->easyhandle, CURLINFO_CONTENT_TYPE, (&temp_str)))
		PANIC_AND_JUMP(xpa_libcurl_error, request)
	else request->content->type = tsk_strdup(0, (const char*)temp_str); 
		
bail:

	/* free the header list */
	curl_slist_free_all(headers); 

	/* cleanup libcurl handle if !stateful*/
	if(!(context->reuse_http_connection)) 
		TXC_EASYHANDLE_SAFE_FREE(context->easyhandle);

	return code;
}