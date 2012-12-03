/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 2.0.9
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

namespace org.doubango.tinyWRAP {

using System;
using System.Runtime.InteropServices;

public class SipStack : SafeObject {
  private HandleRef swigCPtr;

  internal SipStack(IntPtr cPtr, bool cMemoryOwn) : base(tinyWRAPPINVOKE.SipStack_SWIGUpcast(cPtr), cMemoryOwn) {
    swigCPtr = new HandleRef(this, cPtr);
  }

  internal static HandleRef getCPtr(SipStack obj) {
    return (obj == null) ? new HandleRef(null, IntPtr.Zero) : obj.swigCPtr;
  }

  ~SipStack() {
    Dispose();
  }

  public override void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          tinyWRAPPINVOKE.delete_SipStack(swigCPtr);
        }
        swigCPtr = new HandleRef(null, IntPtr.Zero);
      }
      GC.SuppressFinalize(this);
      base.Dispose();
    }
  }

  public SipStack(SipCallback pCallback, string realm_uri, string impi_uri, string impu_uri) : this(tinyWRAPPINVOKE.new_SipStack(SipCallback.getCPtr(pCallback), realm_uri, impi_uri, impu_uri), true) {
  }

  public bool start() {
    bool ret = tinyWRAPPINVOKE.SipStack_start(swigCPtr);
    return ret;
  }

  public bool setDebugCallback(DDebugCallback pCallback) {
    bool ret = tinyWRAPPINVOKE.SipStack_setDebugCallback(swigCPtr, DDebugCallback.getCPtr(pCallback));
    return ret;
  }

  public bool setRealm(string realm_uri) {
    bool ret = tinyWRAPPINVOKE.SipStack_setRealm(swigCPtr, realm_uri);
    return ret;
  }

  public bool setIMPI(string impi) {
    bool ret = tinyWRAPPINVOKE.SipStack_setIMPI(swigCPtr, impi);
    return ret;
  }

  public bool setIMPU(string impu_uri) {
    bool ret = tinyWRAPPINVOKE.SipStack_setIMPU(swigCPtr, impu_uri);
    return ret;
  }

  public bool setPassword(string password) {
    bool ret = tinyWRAPPINVOKE.SipStack_setPassword(swigCPtr, password);
    return ret;
  }

  public bool setAMF(string amf) {
    bool ret = tinyWRAPPINVOKE.SipStack_setAMF(swigCPtr, amf);
    return ret;
  }

  public bool setOperatorId(string opid) {
    bool ret = tinyWRAPPINVOKE.SipStack_setOperatorId(swigCPtr, opid);
    return ret;
  }

  public bool setProxyCSCF(string fqdn, ushort port, string transport, string ipversion) {
    bool ret = tinyWRAPPINVOKE.SipStack_setProxyCSCF(swigCPtr, fqdn, port, transport, ipversion);
    return ret;
  }

  public bool setLocalIP(string ip, string transport) {
    bool ret = tinyWRAPPINVOKE.SipStack_setLocalIP__SWIG_0(swigCPtr, ip, transport);
    return ret;
  }

  public bool setLocalIP(string ip) {
    bool ret = tinyWRAPPINVOKE.SipStack_setLocalIP__SWIG_1(swigCPtr, ip);
    return ret;
  }

  public bool setLocalPort(ushort port, string transport) {
    bool ret = tinyWRAPPINVOKE.SipStack_setLocalPort__SWIG_0(swigCPtr, port, transport);
    return ret;
  }

  public bool setLocalPort(ushort port) {
    bool ret = tinyWRAPPINVOKE.SipStack_setLocalPort__SWIG_1(swigCPtr, port);
    return ret;
  }

  public bool setEarlyIMS(bool enabled) {
    bool ret = tinyWRAPPINVOKE.SipStack_setEarlyIMS(swigCPtr, enabled);
    return ret;
  }

  public bool addHeader(string name, string value) {
    bool ret = tinyWRAPPINVOKE.SipStack_addHeader(swigCPtr, name, value);
    return ret;
  }

  public bool removeHeader(string name) {
    bool ret = tinyWRAPPINVOKE.SipStack_removeHeader(swigCPtr, name);
    return ret;
  }

  public bool addDnsServer(string ip) {
    bool ret = tinyWRAPPINVOKE.SipStack_addDnsServer(swigCPtr, ip);
    return ret;
  }

  public bool setDnsDiscovery(bool enabled) {
    bool ret = tinyWRAPPINVOKE.SipStack_setDnsDiscovery(swigCPtr, enabled);
    return ret;
  }

  public bool setAoR(string ip, int port) {
    bool ret = tinyWRAPPINVOKE.SipStack_setAoR(swigCPtr, ip, port);
    return ret;
  }

  public bool setSigCompParams(uint dms, uint sms, uint cpb, bool enablePresDict) {
    bool ret = tinyWRAPPINVOKE.SipStack_setSigCompParams(swigCPtr, dms, sms, cpb, enablePresDict);
    return ret;
  }

  public bool addSigCompCompartment(string compId) {
    bool ret = tinyWRAPPINVOKE.SipStack_addSigCompCompartment(swigCPtr, compId);
    return ret;
  }

  public bool removeSigCompCompartment(string compId) {
    bool ret = tinyWRAPPINVOKE.SipStack_removeSigCompCompartment(swigCPtr, compId);
    return ret;
  }

  public bool setSTUNServer(string ip, ushort port) {
    bool ret = tinyWRAPPINVOKE.SipStack_setSTUNServer(swigCPtr, ip, port);
    return ret;
  }

  public bool setSTUNCred(string login, string password) {
    bool ret = tinyWRAPPINVOKE.SipStack_setSTUNCred(swigCPtr, login, password);
    return ret;
  }

  public bool setTLSSecAgree(bool enabled) {
    bool ret = tinyWRAPPINVOKE.SipStack_setTLSSecAgree(swigCPtr, enabled);
    return ret;
  }

  public bool setSSLCretificates(string privKey, string pubKey, string caKey) {
    bool ret = tinyWRAPPINVOKE.SipStack_setSSLCretificates(swigCPtr, privKey, pubKey, caKey);
    return ret;
  }

  public bool setIPSecSecAgree(bool enabled) {
    bool ret = tinyWRAPPINVOKE.SipStack_setIPSecSecAgree(swigCPtr, enabled);
    return ret;
  }

  public bool setIPSecParameters(string algo, string ealgo, string mode, string proto) {
    bool ret = tinyWRAPPINVOKE.SipStack_setIPSecParameters(swigCPtr, algo, ealgo, mode, proto);
    return ret;
  }

  public string dnsENUM(string service, string e164num, string domain) {
    string ret = tinyWRAPPINVOKE.SipStack_dnsENUM(swigCPtr, service, e164num, domain);
    return ret;
  }

  public string dnsNaptrSrv(string domain, string service, out ushort OUTPUT) {
    string ret = tinyWRAPPINVOKE.SipStack_dnsNaptrSrv(swigCPtr, domain, service, out OUTPUT);
    return ret;
  }

  public string dnsSrv(string service, out ushort OUTPUT) {
    string ret = tinyWRAPPINVOKE.SipStack_dnsSrv(swigCPtr, service, out OUTPUT);
    return ret;
  }

  public string getLocalIPnPort(string protocol, out ushort OUTPUT) {
    string ret = tinyWRAPPINVOKE.SipStack_getLocalIPnPort(swigCPtr, protocol, out OUTPUT);
    return ret;
  }

  public string getPreferredIdentity() {
    string ret = tinyWRAPPINVOKE.SipStack_getPreferredIdentity(swigCPtr);
    return ret;
  }

  public bool isValid() {
    bool ret = tinyWRAPPINVOKE.SipStack_isValid(swigCPtr);
    return ret;
  }

  public bool stop() {
    bool ret = tinyWRAPPINVOKE.SipStack_stop(swigCPtr);
    return ret;
  }

  public static bool initialize() {
    bool ret = tinyWRAPPINVOKE.SipStack_initialize();
    return ret;
  }

  public static bool deInitialize() {
    bool ret = tinyWRAPPINVOKE.SipStack_deInitialize();
    return ret;
  }

  public static void setCodecs(tdav_codec_id_t codecs) {
    tinyWRAPPINVOKE.SipStack_setCodecs((int)codecs);
  }

  public static void setCodecs_2(long codecs) {
    tinyWRAPPINVOKE.SipStack_setCodecs_2(codecs);
  }

  public static bool setCodecPriority(tdav_codec_id_t codec_id, int priority) {
    bool ret = tinyWRAPPINVOKE.SipStack_setCodecPriority((int)codec_id, priority);
    return ret;
  }

  public static bool setCodecPriority_2(int codec, int priority) {
    bool ret = tinyWRAPPINVOKE.SipStack_setCodecPriority_2(codec, priority);
    return ret;
  }

  public static bool isCodecSupported(tdav_codec_id_t codec_id) {
    bool ret = tinyWRAPPINVOKE.SipStack_isCodecSupported((int)codec_id);
    return ret;
  }

}

}
