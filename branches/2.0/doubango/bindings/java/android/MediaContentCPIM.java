/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.40
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package org.doubango.tinyWRAP;

public class MediaContentCPIM extends MediaContent {
  private long swigCPtr;

  protected MediaContentCPIM(long cPtr, boolean cMemoryOwn) {
    super(tinyWRAPJNI.SWIGMediaContentCPIMUpcast(cPtr), cMemoryOwn);
    swigCPtr = cPtr;
  }

  protected static long getCPtr(MediaContentCPIM obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        tinyWRAPJNI.delete_MediaContentCPIM(swigCPtr);
      }
      swigCPtr = 0;
    }
    super.delete();
  }

  public long getPayloadLength() {
    return tinyWRAPJNI.MediaContentCPIM_getPayloadLength(swigCPtr, this);
  }

  public long getPayload(java.nio.ByteBuffer pOutput, long nMaxsize) {
    return tinyWRAPJNI.MediaContentCPIM_getPayload(swigCPtr, this, pOutput, nMaxsize);
  }

  public String getHeaderValue(String pName) {
    return tinyWRAPJNI.MediaContentCPIM_getHeaderValue(swigCPtr, this, pName);
  }

}
