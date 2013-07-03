/* Copyright (C) 2013 Mamadou DIOP
* Copyright (C) 2013 Doubango Telecom <http://www.doubango.org>
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
*/
#ifndef PLUGIN_WIN_MF_UTILS_H
#define PLUGIN_WIN_MF_UTILS_H

#include "../plugin_win_mf_config.h"

#include <new>
#include <mfapi.h>
#include <mfidl.h>
#include <Mferror.h>
#include <shlwapi.h>

#undef SafeRelease
#define SafeRelease(ppT) \
{ \
    if (*ppT) \
    { \
        (*ppT)->Release(); \
        *ppT = NULL; \
    } \
} 

#undef CHECK_HR
#define CHECK_HR(x) if (FAILED(x)) { TSK_DEBUG_ERROR("Operation Failed"); goto bail; }

typedef struct VideoSubTypeGuidPair
{
    enum tmedia_chroma_e chroma;
    const GUID& fourcc;
}
VideoSubTypeGuidPair;

class MFUtils
{
public:

static HRESULT Startup();
static HRESULT Shutdown();

static HRESULT CreatePCMAudioType(
    UINT32 sampleRate,        // Samples per second
    UINT32 bitsPerSample,     // Bits per sample
    UINT32 cChannels,         // Number of channels
    IMFMediaType **ppType     // Receives a pointer to the media type.
    );
static HRESULT CreateVideoType(
		const GUID* subType, // video subType
		IMFMediaType **ppType,     // Receives a pointer to the media type.
		UINT32 unWidth = 0, // Video width (0 to ignore)
		UINT32 unHeight = 0 // Video height (0 to ignore)
	);
static HRESULT CreateMediaSample(
	DWORD cbData, // Maximum buffer size
	IMFSample **ppSample // Receives the sample
	);
static HRESULT ValidateVideoFormat(
	IMFMediaType *pmt
	);
static HRESULT GetBestVideoProcessor(
	const GUID& inputFormat, // The input MediaFormat (e.g. MFVideoFormat_I420)
	const GUID& outputFormat, // The output MediaFormat (e.g. MFVideoFormat_NV12)
	IMFTransform **ppProcessor // Receives the video processor
	);
static HRESULT GetBestCodec(
	bool bEncoder, // Whether we request an encoder or not (TRUE=encoder, FALSE=decoder)
	const GUID& mediaType, // The MediaType
	const GUID& inputFormat, // The input MediaFormat (e.g. MFVideoFormat_NV12)
	const GUID& outputFormat, // The output MediaFormat (e.g. MFVideoFormat_H264)
	IMFTransform **ppMFT // Receives the decoder/encoder transform
	);
static HRESULT BindOutputNode(
	IMFTopologyNode *pNode // The Node
	);
static HRESULT AddOutputNode(
    IMFTopology *pTopology,     // Topology.
    IMFActivate *pActivate,     // Media sink activation object.
    DWORD dwId,                 // Identifier of the stream sink.
    IMFTopologyNode **ppNode   // Receives the node pointer.
	);
static HRESULT AddTransformNode(
    IMFTopology *pTopology,     // Topology.
    IMFTransform *pMFT,     // MFT.
    DWORD dwId,                 // Identifier of the stream sink.
    IMFTopologyNode **ppNode   // Receives the node pointer.
	);
static HRESULT AddSourceNode(
    IMFTopology *pTopology,           // Topology.
    IMFMediaSource *pSource,          // Media source.
    IMFPresentationDescriptor *pPD,   // Presentation descriptor.
    IMFStreamDescriptor *pSD,         // Stream descriptor.
    IMFTopologyNode **ppNode          // Receives the node pointer.
	);
static HRESULT CreateTopology(
	IMFMediaSource *pSource, // Media source
	IMFTransform *pTransform, // Transform filter (e.g. encoder or decoder) to insert between the source and Sink. NULL is valid.
	IMFActivate *pSinkActivate, // Activation object.
	const GUID& mediaType, // The MediaType
	IMFTopology **ppTopo // Receives the newly created topology
	);
static HRESULT ResolveTopology(
	IMFTopology *pInputTopo, // A pointer to the IMFTopology interface of the partial topology to be resolved.
	IMFTopology **ppOutputTopo, // Receives a pointer to the IMFTopology interface of the completed topology. The caller must release the interface.
	IMFTopology *pCurrentTopo = NULL // A pointer to the IMFTopology interface of the previous full topology. The topology loader can re-use objects from this topology in the new topology. This parameter can be NULL.
	);
static HRESULT CreateMediaSinkActivate(
    IMFStreamDescriptor *pSourceSD,     // Pointer to the stream descriptor.
    HWND hVideoWindow,                  // Handle to the video clipping window.
    IMFActivate **ppActivate
);
static HRESULT SetMediaType(
    IMFMediaSource *pSource,        // Media source.
	IMFMediaType* pMediaType // Media Type.
	);
static HRESULT SetVideoWindow(
    IMFTopology *pTopology,         // Topology.
    IMFMediaSource *pSource,        // Media source.
    HWND hVideoWnd                 // Window for video playback.
	);
static HRESULT RunSession(
	IMFMediaSession *pSession, // Session to run
	IMFTopology *pTopology // The toppology
	);
static HRESULT ShutdownSession(
	IMFMediaSession *pSession, // The Session
	IMFMediaSource *pSource = NULL // Source to shutdown (optional)
	);
static HRESULT PauseSession(
	IMFMediaSession *pSession, // The session
	IMFMediaSource *pSource = NULL// Source to pause (optional)
	);
static INT GetSupportedSubTypeIndex(
	IMFMediaSource *pSource, // The source
	const GUID& mediaType, // The MediaType
	const VideoSubTypeGuidPair* subTypes, UINT subTypesCount // List of preferred subtypes (in ascending order)
	);
static HWND GetConsoleHwnd(void);

private:
	static bool g_bStarted;
};

#endif /* PLUGIN_WIN_MF_UTILS_H */
