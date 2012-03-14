/*
* Copyright (C) 2010-2011 Mamadou Diop.
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
#include "MediaSessionMgr.h"

extern tmedia_type_t _get_media_type(twrap_media_type_t type);
#if ANDROID
static void *__droid_destroy_mgr(void *mgr){	
	TSK_OBJECT_SAFE_FREE(mgr);
	return tsk_null;
}
#endif


MediaSessionMgr::MediaSessionMgr(tmedia_session_mgr_t* pWrappedMgr)
{
	m_pWrappedMgr = (tmedia_session_mgr_t*)tsk_object_ref(pWrappedMgr);
}

MediaSessionMgr::~MediaSessionMgr()
{
#if ANDROID
	// On Android, deleting the manager from the managed code will trigger OnPluginDestroyed() event
	// for each plugin associated to this manager (audio,video,...consumers/producers)
	void* tid[1] = { tsk_null };
	if(tsk_thread_create(tid, __droid_destroy_mgr, m_pWrappedMgr) == 0){
		tsk_thread_join(tid);
	}
	else{
		TSK_DEBUG_ERROR("Failed to start the thread");
	}
#else
	TSK_OBJECT_SAFE_FREE(m_pWrappedMgr);
#endif
}

bool MediaSessionMgr::sessionSetInt32(twrap_media_type_t media, const char* key, int32_t value)
{
	tmedia_type_t _media = _get_media_type(media);
	return (tmedia_session_mgr_set(m_pWrappedMgr,
		TMEDIA_SESSION_SET_INT32(_media, key, value),
		TMEDIA_SESSION_SET_NULL()) == 0);
}

int32_t MediaSessionMgr::sessionGetInt32(twrap_media_type_t media, const char* key)
{
	int32_t value = 0;
	tmedia_type_t _media = _get_media_type(media);
	(tmedia_session_mgr_get(m_pWrappedMgr,
		TMEDIA_SESSION_GET_INT32(_media, key, &value),
		TMEDIA_SESSION_GET_NULL()));
	return value;
}

bool MediaSessionMgr::consumerSetInt32(twrap_media_type_t media, const char* key, int32_t value)
{
	tmedia_type_t _media = _get_media_type(media);
	return (tmedia_session_mgr_set(m_pWrappedMgr,
		TMEDIA_SESSION_CONSUMER_SET_INT32(_media, key, value),
		TMEDIA_SESSION_SET_NULL()) == 0);
}

bool MediaSessionMgr::consumerSetInt64(twrap_media_type_t media, const char* key, int64_t value)
{
	tmedia_type_t _media = _get_media_type(media);
	return (tmedia_session_mgr_set(m_pWrappedMgr,
		TMEDIA_SESSION_CONSUMER_SET_INT64(_media, key, value),
		TMEDIA_SESSION_SET_NULL()) == 0);
}

bool MediaSessionMgr::producerSetInt32(twrap_media_type_t media, const char* key, int32_t value)
{
	tmedia_type_t _media = _get_media_type(media);
	return (tmedia_session_mgr_set(m_pWrappedMgr,
		TMEDIA_SESSION_PRODUCER_SET_INT32(_media, key, value),
		TMEDIA_SESSION_SET_NULL()) == 0);
}

bool MediaSessionMgr::producerSetInt64(twrap_media_type_t media, const char* key, int64_t value)
{
	tmedia_type_t _media = _get_media_type(media);
	return (tmedia_session_mgr_set(m_pWrappedMgr,
		TMEDIA_SESSION_PRODUCER_SET_INT64(_media, key, value),
		TMEDIA_SESSION_SET_NULL()) == 0);
}

#include "tinydav/audio/tdav_session_audio.h"
#include "tinydav/video/tdav_session_video.h"
#include "ProxyPluginMgr.h"


const ProxyPlugin* MediaSessionMgr::findProxyPlugin(twrap_media_type_t media, bool consumer)const
{
	const ProxyPlugin* plugin = tsk_null;
	ProxyPluginMgr* manager = ProxyPluginMgr::getInstance();

	if(media != twrap_media_audio && media != twrap_media_video){
		TSK_DEBUG_ERROR("Invalid media type");
		return tsk_null;
	}

	if(manager && m_pWrappedMgr){
		tmedia_type_t _media = _get_media_type(media);
		tmedia_session_t* session = tmedia_session_mgr_find(m_pWrappedMgr, _media);
		if(session){
			if(session->plugin == tdav_session_audio_plugin_def_t){
				if(consumer){
					plugin = manager->findPlugin(TDAV_SESSION_AUDIO(session)->consumer);
				}
				else{
					plugin = manager->findPlugin(TDAV_SESSION_AUDIO(session)->producer);
				}
			}
			else if(session->plugin == tdav_session_video_plugin_def_t){
				if(consumer){
					plugin = manager->findPlugin(TDAV_SESSION_VIDEO(session)->consumer);
				}
				else{
					plugin = manager->findPlugin(TDAV_SESSION_VIDEO(session)->producer);
				}
			}
			else{
				TSK_DEBUG_ERROR("Unknown session with media type = %d", _media);
			}
			tsk_object_unref(session);
		}
	}
	else{
		TSK_DEBUG_ERROR("Invalid state");
	}

	return plugin;
}

uint64_t MediaSessionMgr::getSessionId(twrap_media_type_t media)const
{
	//const ProxyPlugin* plugin = tsk_null;
	ProxyPluginMgr* manager = ProxyPluginMgr::getInstance();
	uint64_t id = 0;

	if(media != twrap_media_audio && media != twrap_media_video){
		TSK_DEBUG_ERROR("Invalid media type");
		return tsk_null;
	}

	if(manager && m_pWrappedMgr){
		tmedia_type_t _media = _get_media_type(media);
		tmedia_session_t* session = tmedia_session_mgr_find(m_pWrappedMgr, _media);
		if(session){
			id = session->id;
		}
		tsk_object_unref(session);
	}
	else{
		TSK_DEBUG_ERROR("Invalid state");
	}

	return id;
}

bool MediaSessionMgr::defaultsSetBandwidthLevel(tmedia_bandwidth_level_t bl)
{
	return tmedia_defaults_set_bl(bl) == 0;
}

tmedia_bandwidth_level_t MediaSessionMgr::defaultsGetBandwidthLevel()
{
	return tmedia_defaults_get_bl();
}

bool MediaSessionMgr::defaultsSetJbMargin(uint32_t jb_margin_ms)
{
	return tmedia_defaults_set_jb_margin(jb_margin_ms) == 0;
}

bool MediaSessionMgr::defaultsSetJbMaxLateRate(uint32_t jb_late_rate_percent)
{
	return tmedia_defaults_set_jb_max_late_rate(jb_late_rate_percent) == 0;
}

bool MediaSessionMgr::defaultsSetEchoTail(uint32_t echo_tail)
{
	return tmedia_defaults_set_echo_tail(echo_tail) == 0;
}

uint32_t MediaSessionMgr::defaultsGetEchoTail()
{
	return tmedia_defaults_get_echo_tail();
}

bool MediaSessionMgr::defaultsSetEchoSkew(uint32_t echo_skew)
{
	return tmedia_defaults_set_echo_skew(echo_skew) == 0;
}

bool MediaSessionMgr::defaultsSetEchoSuppEnabled(bool echo_supp_enabled)
{
	return tmedia_defaults_set_echo_supp_enabled(echo_supp_enabled) == 0;
}

bool MediaSessionMgr::defaultsGetEchoSuppEnabled()
{
	return tmedia_defaults_get_echo_supp_enabled() ? true : false;
}

bool MediaSessionMgr::defaultsSetAgcEnabled(bool agc_enabled)
{
	return tmedia_defaults_set_agc_enabled(agc_enabled ? tsk_true : tsk_false) == 0;
}

bool MediaSessionMgr::defaultsGetAgcEnabled()
{
	return tmedia_defaults_get_agc_enabled() ? true : false;
}

bool MediaSessionMgr::defaultsSetAgcLevel(float agc_level)
{
	return tmedia_defaults_set_agc_level(agc_level) == 0;
}

float MediaSessionMgr::defaultsGetAgcLevel()
{
	return tmedia_defaults_get_agc_level();
}

bool MediaSessionMgr::defaultsSetVadEnabled(bool vad_enabled)
{
	return tmedia_defaults_set_vad_enabled(vad_enabled ? tsk_true : tsk_false) == 0;
}

bool MediaSessionMgr::defaultsGetGetVadEnabled()
{
	return tmedia_defaults_get_vad_enabled() ? true : false;
}

bool MediaSessionMgr::defaultsSetNoiseSuppEnabled(bool noise_supp_enabled)
{
	return tmedia_defaults_set_noise_supp_enabled(noise_supp_enabled ? tsk_true : tsk_false) == 0;
}

bool MediaSessionMgr::defaultsGetNoiseSuppEnabled()
{
	return tmedia_defaults_get_noise_supp_enabled() ? true : false;
}

bool MediaSessionMgr::defaultsSetNoiseSuppLevel(int32_t noise_supp_level)
{
	return tmedia_defaults_set_noise_supp_level(noise_supp_level) == 0;
}

int32_t MediaSessionMgr::defaultsGetNoiseSuppLevel()
{
	return tmedia_defaults_get_noise_supp_level();
}

bool MediaSessionMgr::defaultsSet100relEnabled(bool _100rel_enabled){
	return tmedia_defaults_set_100rel_enabled(_100rel_enabled ? tsk_true : tsk_false) == 0;
}

bool MediaSessionMgr::defaultsGet100relEnabled(){
	return tmedia_defaults_get_100rel_enabled() == 0;
}

bool MediaSessionMgr::defaultsSetScreenSize(int32_t sx, int32_t sy){
	return tmedia_defaults_set_screen_size(sx, sy) == 0;
}

bool MediaSessionMgr::defaultsSetAudioGain(int32_t producer_gain, int32_t consumer_gain){
	return tmedia_defaults_set_audio_gain(producer_gain, consumer_gain) == 0;
}

bool MediaSessionMgr::defaultsSetRtpPortRange(uint16_t range_start, uint16_t range_stop){
	return tmedia_defaults_set_rtp_port_range(range_start, range_stop) == 0;
}

bool MediaSessionMgr::defaultsSetMediaType(twrap_media_type_t media_type)
{
	return (tmedia_defaults_set_media_type(_get_media_type(media_type)) == 0);
}

bool MediaSessionMgr::defaultsSetVolume(int32_t volume)
{
	return (tmedia_defaults_set_volume(volume) == 0);
}

int32_t MediaSessionMgr::defaultsGetVolume()
{
	return tmedia_defaults_get_volume();
}

bool MediaSessionMgr::defaultsSetInviteSessionTimers(int32_t timeout, const char* refresher)
{
	int ret = tmedia_defaults_set_inv_session_expires(timeout);
	ret &= tmedia_defaults_set_inv_session_refresher(refresher);
	return (ret == 0);
}

bool MediaSessionMgr::defaultsSetSRtpMode(tmedia_srtp_mode_t mode){
	return (tmedia_defaults_set_srtp_mode(mode) == 0);
}