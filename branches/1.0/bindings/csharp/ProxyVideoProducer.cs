/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.39
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

namespace org.doubango.tinyWRAP {

using System;
using System.Runtime.InteropServices;

public class ProxyVideoProducer : ProxyPlugin {
  private HandleRef swigCPtr;

  internal ProxyVideoProducer(IntPtr cPtr, bool cMemoryOwn) : base(tinyWRAPPINVOKE.ProxyVideoProducerUpcast(cPtr), cMemoryOwn) {
    swigCPtr = new HandleRef(this, cPtr);
  }

  internal static HandleRef getCPtr(ProxyVideoProducer obj) {
    return (obj == null) ? new HandleRef(null, IntPtr.Zero) : obj.swigCPtr;
  }

  ~ProxyVideoProducer() {
    Dispose();
  }

  public override void Dispose() {
    lock(this) {
      if(swigCPtr.Handle != IntPtr.Zero && swigCMemOwn) {
        swigCMemOwn = false;
        tinyWRAPPINVOKE.delete_ProxyVideoProducer(swigCPtr);
      }
      swigCPtr = new HandleRef(null, IntPtr.Zero);
      GC.SuppressFinalize(this);
      base.Dispose();
    }
  }

  public int getRotation() {
    int ret = tinyWRAPPINVOKE.ProxyVideoProducer_getRotation(swigCPtr);
    return ret;
  }

  public void setRotation(int rot) {
    tinyWRAPPINVOKE.ProxyVideoProducer_setRotation(swigCPtr, rot);
  }

  public int push(byte[] buffer, uint size) {
    int ret = tinyWRAPPINVOKE.ProxyVideoProducer_push(swigCPtr, buffer, size);
    return ret;
  }

  public int send(byte[] buffer, uint size, uint duration, bool marker) {
    int ret = tinyWRAPPINVOKE.ProxyVideoProducer_send(swigCPtr, buffer, size, duration, marker);
    return ret;
  }

  public void setCallback(ProxyVideoProducerCallback _callback) {
    tinyWRAPPINVOKE.ProxyVideoProducer_setCallback(swigCPtr, ProxyVideoProducerCallback.getCPtr(_callback));
  }

  public virtual ulong getMediaSessionId() {
    ulong ret = tinyWRAPPINVOKE.ProxyVideoProducer_getMediaSessionId(swigCPtr);
    return ret;
  }

  public static bool registerPlugin() {
    bool ret = tinyWRAPPINVOKE.ProxyVideoProducer_registerPlugin();
    return ret;
  }

  public static void setDefaultChroma(tmedia_chroma_t chroma) {
    tinyWRAPPINVOKE.ProxyVideoProducer_setDefaultChroma((int)chroma);
  }

}

}
