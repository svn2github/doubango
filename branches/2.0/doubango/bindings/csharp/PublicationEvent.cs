/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.40
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

namespace org.doubango.tinyWRAP {

using System;
using System.Runtime.InteropServices;

public class PublicationEvent : SipEvent {
  private HandleRef swigCPtr;

  internal PublicationEvent(IntPtr cPtr, bool cMemoryOwn) : base(tinyWRAPPINVOKE.PublicationEventUpcast(cPtr), cMemoryOwn) {
    swigCPtr = new HandleRef(this, cPtr);
  }

  internal static HandleRef getCPtr(PublicationEvent obj) {
    return (obj == null) ? new HandleRef(null, IntPtr.Zero) : obj.swigCPtr;
  }

  ~PublicationEvent() {
    Dispose();
  }

  public override void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          tinyWRAPPINVOKE.delete_PublicationEvent(swigCPtr);
        }
        swigCPtr = new HandleRef(null, IntPtr.Zero);
      }
      GC.SuppressFinalize(this);
      base.Dispose();
    }
  }

  public tsip_publish_event_type_t getType() {
    tsip_publish_event_type_t ret = (tsip_publish_event_type_t)tinyWRAPPINVOKE.PublicationEvent_getType(swigCPtr);
    return ret;
  }

  public PublicationSession getSession() {
    IntPtr cPtr = tinyWRAPPINVOKE.PublicationEvent_getSession(swigCPtr);
    PublicationSession ret = (cPtr == IntPtr.Zero) ? null : new PublicationSession(cPtr, false);
    return ret;
  }

  public PublicationSession takeSessionOwnership() {
    IntPtr cPtr = tinyWRAPPINVOKE.PublicationEvent_takeSessionOwnership(swigCPtr);
    PublicationSession ret = (cPtr == IntPtr.Zero) ? null : new PublicationSession(cPtr, false);
    return ret;
  }

}

}
