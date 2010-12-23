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

public class ProxyVideoConsumer : ProxyPlugin {
  private HandleRef swigCPtr;

  internal ProxyVideoConsumer(IntPtr cPtr, bool cMemoryOwn) : base(tinyWRAPPINVOKE.ProxyVideoConsumerUpcast(cPtr), cMemoryOwn) {
    swigCPtr = new HandleRef(this, cPtr);
  }

  internal static HandleRef getCPtr(ProxyVideoConsumer obj) {
    return (obj == null) ? new HandleRef(null, IntPtr.Zero) : obj.swigCPtr;
  }

  ~ProxyVideoConsumer() {
    Dispose();
  }

  public override void Dispose() {
    lock(this) {
      if(swigCPtr.Handle != IntPtr.Zero && swigCMemOwn) {
        swigCMemOwn = false;
        tinyWRAPPINVOKE.delete_ProxyVideoConsumer(swigCPtr);
      }
      swigCPtr = new HandleRef(null, IntPtr.Zero);
      GC.SuppressFinalize(this);
      base.Dispose();
    }
  }

  public bool setDisplaySize(int width, int height) {
    bool ret = tinyWRAPPINVOKE.ProxyVideoConsumer_setDisplaySize(swigCPtr, width, height);
    return ret;
  }

  public void setCallback(ProxyVideoConsumerCallback _callback) {
    tinyWRAPPINVOKE.ProxyVideoConsumer_setCallback(swigCPtr, ProxyVideoConsumerCallback.getCPtr(_callback));
  }

  public static bool registerPlugin() {
    bool ret = tinyWRAPPINVOKE.ProxyVideoConsumer_registerPlugin();
    return ret;
  }

  public static void setDefaultChroma(tmedia_chroma_t chroma) {
    tinyWRAPPINVOKE.ProxyVideoConsumer_setDefaultChroma((int)chroma);
  }

}

}
