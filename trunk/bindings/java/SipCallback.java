/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.40
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package org.doubango.tinyWRAP;

public class SipCallback {
  private long swigCPtr;
  protected boolean swigCMemOwn;

  protected SipCallback(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(SipCallback obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        tinyWRAPJNI.delete_SipCallback(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

  protected void swigDirectorDisconnect() {
    swigCMemOwn = false;
    delete();
  }

  public void swigReleaseOwnership() {
    swigCMemOwn = false;
    tinyWRAPJNI.SipCallback_change_ownership(this, swigCPtr, false);
  }

  public void swigTakeOwnership() {
    swigCMemOwn = true;
    tinyWRAPJNI.SipCallback_change_ownership(this, swigCPtr, true);
  }

  public SipCallback() {
    this(tinyWRAPJNI.new_SipCallback(), true);
    tinyWRAPJNI.SipCallback_director_connect(this, swigCPtr, swigCMemOwn, true);
  }

  public int OnDialogEvent(DialogEvent e) {
    return (getClass() == SipCallback.class) ? tinyWRAPJNI.SipCallback_OnDialogEvent(swigCPtr, this, DialogEvent.getCPtr(e), e) : tinyWRAPJNI.SipCallback_OnDialogEventSwigExplicitSipCallback(swigCPtr, this, DialogEvent.getCPtr(e), e);
  }

  public int OnStackEvent(StackEvent e) {
    return (getClass() == SipCallback.class) ? tinyWRAPJNI.SipCallback_OnStackEvent(swigCPtr, this, StackEvent.getCPtr(e), e) : tinyWRAPJNI.SipCallback_OnStackEventSwigExplicitSipCallback(swigCPtr, this, StackEvent.getCPtr(e), e);
  }

  public int OnMessagingEvent(MessagingEvent e) {
    return (getClass() == SipCallback.class) ? tinyWRAPJNI.SipCallback_OnMessagingEvent(swigCPtr, this, MessagingEvent.getCPtr(e), e) : tinyWRAPJNI.SipCallback_OnMessagingEventSwigExplicitSipCallback(swigCPtr, this, MessagingEvent.getCPtr(e), e);
  }

  public int OnOptionsEvent(OptionsEvent e) {
    return (getClass() == SipCallback.class) ? tinyWRAPJNI.SipCallback_OnOptionsEvent(swigCPtr, this, OptionsEvent.getCPtr(e), e) : tinyWRAPJNI.SipCallback_OnOptionsEventSwigExplicitSipCallback(swigCPtr, this, OptionsEvent.getCPtr(e), e);
  }

  public int OnPublicationEvent(PublicationEvent e) {
    return (getClass() == SipCallback.class) ? tinyWRAPJNI.SipCallback_OnPublicationEvent(swigCPtr, this, PublicationEvent.getCPtr(e), e) : tinyWRAPJNI.SipCallback_OnPublicationEventSwigExplicitSipCallback(swigCPtr, this, PublicationEvent.getCPtr(e), e);
  }

  public int OnRegistrationEvent(RegistrationEvent e) {
    return (getClass() == SipCallback.class) ? tinyWRAPJNI.SipCallback_OnRegistrationEvent(swigCPtr, this, RegistrationEvent.getCPtr(e), e) : tinyWRAPJNI.SipCallback_OnRegistrationEventSwigExplicitSipCallback(swigCPtr, this, RegistrationEvent.getCPtr(e), e);
  }

  public int OnSubscriptionEvent(SubscriptionEvent e) {
    return (getClass() == SipCallback.class) ? tinyWRAPJNI.SipCallback_OnSubscriptionEvent(swigCPtr, this, SubscriptionEvent.getCPtr(e), e) : tinyWRAPJNI.SipCallback_OnSubscriptionEventSwigExplicitSipCallback(swigCPtr, this, SubscriptionEvent.getCPtr(e), e);
  }

}
