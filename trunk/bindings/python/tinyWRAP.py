# This file was automatically generated by SWIG (http://www.swig.org).
# Version 1.3.39
#
# Do not make changes to this file unless you know what you are doing--modify
# the SWIG interface file instead.
# This file is compatible with both classic and new-style classes.

from sys import version_info
if version_info >= (2,6,0):
    def swig_import_helper():
        from os.path import dirname
        import imp
        try:
            fp, pathname, description = imp.find_module('_tinyWRAP', [dirname(__file__)])
            _mod = imp.load_module('_tinyWRAP', fp, pathname, description)
        finally:
            if fp is not None: fp.close()
        return _mod
    _tinyWRAP = swig_import_helper()
    del swig_import_helper
else:
    import _tinyWRAP
del version_info
try:
    _swig_property = property
except NameError:
    pass # Python < 2.2 doesn't have 'property'.
def _swig_setattr_nondynamic(self,class_type,name,value,static=1):
    if (name == "thisown"): return self.this.own(value)
    if (name == "this"):
        if type(value).__name__ == 'SwigPyObject':
            self.__dict__[name] = value
            return
    method = class_type.__swig_setmethods__.get(name,None)
    if method: return method(self,value)
    if (not static) or hasattr(self,name):
        self.__dict__[name] = value
    else:
        raise AttributeError("You cannot add attributes to %s" % self)

def _swig_setattr(self,class_type,name,value):
    return _swig_setattr_nondynamic(self,class_type,name,value,0)

def _swig_getattr(self,class_type,name):
    if (name == "thisown"): return self.this.own()
    method = class_type.__swig_getmethods__.get(name,None)
    if method: return method(self)
    raise AttributeError(name)

def _swig_repr(self):
    try: strthis = "proxy of " + self.this.__repr__()
    except: strthis = ""
    return "<%s.%s; %s >" % (self.__class__.__module__, self.__class__.__name__, strthis,)

try:
    _object = object
    _newclass = 1
except AttributeError:
    class _object : pass
    _newclass = 0


try:
    import weakref
    weakref_proxy = weakref.proxy
except:
    weakref_proxy = lambda x: x


class DDebugCallback(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, DDebugCallback, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, DDebugCallback, name)
    __repr__ = _swig_repr
    def __init__(self): 
        this = _tinyWRAP.new_DDebugCallback()
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _tinyWRAP.delete_DDebugCallback
    __del__ = lambda self : None;
    def OnDebugInfo(self, *args): return _tinyWRAP.DDebugCallback_OnDebugInfo(self, *args)
    def OnDebugWarn(self, *args): return _tinyWRAP.DDebugCallback_OnDebugWarn(self, *args)
    def OnDebugError(self, *args): return _tinyWRAP.DDebugCallback_OnDebugError(self, *args)
    def OnDebugFatal(self, *args): return _tinyWRAP.DDebugCallback_OnDebugFatal(self, *args)
DDebugCallback_swigregister = _tinyWRAP.DDebugCallback_swigregister
DDebugCallback_swigregister(DDebugCallback)

class SipUri(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, SipUri, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, SipUri, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        this = _tinyWRAP.new_SipUri(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _tinyWRAP.delete_SipUri
    __del__ = lambda self : None;
    def isValid(self, *args): return _tinyWRAP.SipUri_isValid(self, *args)
SipUri_swigregister = _tinyWRAP.SipUri_swigregister
SipUri_swigregister(SipUri)

class SipMessage(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, SipMessage, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, SipMessage, name)
    __repr__ = _swig_repr
    def __init__(self): 
        this = _tinyWRAP.new_SipMessage()
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _tinyWRAP.delete_SipMessage
    __del__ = lambda self : None;
    def getSipHeaderValue(self, *args): return _tinyWRAP.SipMessage_getSipHeaderValue(self, *args)
    def getSipHeaderParamValue(self, *args): return _tinyWRAP.SipMessage_getSipHeaderParamValue(self, *args)
    def getSipContentLength(self): return _tinyWRAP.SipMessage_getSipContentLength(self)
    def getSipContent(self, *args): return _tinyWRAP.SipMessage_getSipContent(self, *args)
SipMessage_swigregister = _tinyWRAP.SipMessage_swigregister
SipMessage_swigregister(SipMessage)

class SipEvent(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, SipEvent, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, SipEvent, name)
    def __init__(self, *args, **kwargs): raise AttributeError("No constructor defined")
    __repr__ = _swig_repr
    __swig_destroy__ = _tinyWRAP.delete_SipEvent
    __del__ = lambda self : None;
    def getCode(self): return _tinyWRAP.SipEvent_getCode(self)
    def getPhrase(self): return _tinyWRAP.SipEvent_getPhrase(self)
    def getBaseSession(self): return _tinyWRAP.SipEvent_getBaseSession(self)
    def getSipMessage(self): return _tinyWRAP.SipEvent_getSipMessage(self)
SipEvent_swigregister = _tinyWRAP.SipEvent_swigregister
SipEvent_swigregister(SipEvent)

class DialogEvent(SipEvent):
    __swig_setmethods__ = {}
    for _s in [SipEvent]: __swig_setmethods__.update(getattr(_s,'__swig_setmethods__',{}))
    __setattr__ = lambda self, name, value: _swig_setattr(self, DialogEvent, name, value)
    __swig_getmethods__ = {}
    for _s in [SipEvent]: __swig_getmethods__.update(getattr(_s,'__swig_getmethods__',{}))
    __getattr__ = lambda self, name: _swig_getattr(self, DialogEvent, name)
    def __init__(self, *args, **kwargs): raise AttributeError("No constructor defined")
    __repr__ = _swig_repr
    __swig_destroy__ = _tinyWRAP.delete_DialogEvent
    __del__ = lambda self : None;
DialogEvent_swigregister = _tinyWRAP.DialogEvent_swigregister
DialogEvent_swigregister(DialogEvent)

class StackEvent(SipEvent):
    __swig_setmethods__ = {}
    for _s in [SipEvent]: __swig_setmethods__.update(getattr(_s,'__swig_setmethods__',{}))
    __setattr__ = lambda self, name, value: _swig_setattr(self, StackEvent, name, value)
    __swig_getmethods__ = {}
    for _s in [SipEvent]: __swig_getmethods__.update(getattr(_s,'__swig_getmethods__',{}))
    __getattr__ = lambda self, name: _swig_getattr(self, StackEvent, name)
    def __init__(self, *args, **kwargs): raise AttributeError("No constructor defined")
    __repr__ = _swig_repr
    __swig_destroy__ = _tinyWRAP.delete_StackEvent
    __del__ = lambda self : None;
StackEvent_swigregister = _tinyWRAP.StackEvent_swigregister
StackEvent_swigregister(StackEvent)

class CallEvent(SipEvent):
    __swig_setmethods__ = {}
    for _s in [SipEvent]: __swig_setmethods__.update(getattr(_s,'__swig_setmethods__',{}))
    __setattr__ = lambda self, name, value: _swig_setattr(self, CallEvent, name, value)
    __swig_getmethods__ = {}
    for _s in [SipEvent]: __swig_getmethods__.update(getattr(_s,'__swig_getmethods__',{}))
    __getattr__ = lambda self, name: _swig_getattr(self, CallEvent, name)
    def __init__(self, *args, **kwargs): raise AttributeError("No constructor defined")
    __repr__ = _swig_repr
    __swig_destroy__ = _tinyWRAP.delete_CallEvent
    __del__ = lambda self : None;
    def getType(self): return _tinyWRAP.CallEvent_getType(self)
    def getSession(self): return _tinyWRAP.CallEvent_getSession(self)
    def takeSessionOwnership(self): return _tinyWRAP.CallEvent_takeSessionOwnership(self)
CallEvent_swigregister = _tinyWRAP.CallEvent_swigregister
CallEvent_swigregister(CallEvent)

class MessagingEvent(SipEvent):
    __swig_setmethods__ = {}
    for _s in [SipEvent]: __swig_setmethods__.update(getattr(_s,'__swig_setmethods__',{}))
    __setattr__ = lambda self, name, value: _swig_setattr(self, MessagingEvent, name, value)
    __swig_getmethods__ = {}
    for _s in [SipEvent]: __swig_getmethods__.update(getattr(_s,'__swig_getmethods__',{}))
    __getattr__ = lambda self, name: _swig_getattr(self, MessagingEvent, name)
    def __init__(self, *args, **kwargs): raise AttributeError("No constructor defined")
    __repr__ = _swig_repr
    __swig_destroy__ = _tinyWRAP.delete_MessagingEvent
    __del__ = lambda self : None;
    def getType(self): return _tinyWRAP.MessagingEvent_getType(self)
    def getSession(self): return _tinyWRAP.MessagingEvent_getSession(self)
    def takeSessionOwnership(self): return _tinyWRAP.MessagingEvent_takeSessionOwnership(self)
MessagingEvent_swigregister = _tinyWRAP.MessagingEvent_swigregister
MessagingEvent_swigregister(MessagingEvent)

class OptionsEvent(SipEvent):
    __swig_setmethods__ = {}
    for _s in [SipEvent]: __swig_setmethods__.update(getattr(_s,'__swig_setmethods__',{}))
    __setattr__ = lambda self, name, value: _swig_setattr(self, OptionsEvent, name, value)
    __swig_getmethods__ = {}
    for _s in [SipEvent]: __swig_getmethods__.update(getattr(_s,'__swig_getmethods__',{}))
    __getattr__ = lambda self, name: _swig_getattr(self, OptionsEvent, name)
    def __init__(self, *args, **kwargs): raise AttributeError("No constructor defined")
    __repr__ = _swig_repr
    __swig_destroy__ = _tinyWRAP.delete_OptionsEvent
    __del__ = lambda self : None;
    def getType(self): return _tinyWRAP.OptionsEvent_getType(self)
    def getSession(self): return _tinyWRAP.OptionsEvent_getSession(self)
OptionsEvent_swigregister = _tinyWRAP.OptionsEvent_swigregister
OptionsEvent_swigregister(OptionsEvent)

class PublicationEvent(SipEvent):
    __swig_setmethods__ = {}
    for _s in [SipEvent]: __swig_setmethods__.update(getattr(_s,'__swig_setmethods__',{}))
    __setattr__ = lambda self, name, value: _swig_setattr(self, PublicationEvent, name, value)
    __swig_getmethods__ = {}
    for _s in [SipEvent]: __swig_getmethods__.update(getattr(_s,'__swig_getmethods__',{}))
    __getattr__ = lambda self, name: _swig_getattr(self, PublicationEvent, name)
    def __init__(self, *args, **kwargs): raise AttributeError("No constructor defined")
    __repr__ = _swig_repr
    __swig_destroy__ = _tinyWRAP.delete_PublicationEvent
    __del__ = lambda self : None;
    def getType(self): return _tinyWRAP.PublicationEvent_getType(self)
    def getSession(self): return _tinyWRAP.PublicationEvent_getSession(self)
PublicationEvent_swigregister = _tinyWRAP.PublicationEvent_swigregister
PublicationEvent_swigregister(PublicationEvent)

class RegistrationEvent(SipEvent):
    __swig_setmethods__ = {}
    for _s in [SipEvent]: __swig_setmethods__.update(getattr(_s,'__swig_setmethods__',{}))
    __setattr__ = lambda self, name, value: _swig_setattr(self, RegistrationEvent, name, value)
    __swig_getmethods__ = {}
    for _s in [SipEvent]: __swig_getmethods__.update(getattr(_s,'__swig_getmethods__',{}))
    __getattr__ = lambda self, name: _swig_getattr(self, RegistrationEvent, name)
    def __init__(self, *args, **kwargs): raise AttributeError("No constructor defined")
    __repr__ = _swig_repr
    __swig_destroy__ = _tinyWRAP.delete_RegistrationEvent
    __del__ = lambda self : None;
    def getType(self): return _tinyWRAP.RegistrationEvent_getType(self)
    def getSession(self): return _tinyWRAP.RegistrationEvent_getSession(self)
RegistrationEvent_swigregister = _tinyWRAP.RegistrationEvent_swigregister
RegistrationEvent_swigregister(RegistrationEvent)

class SubscriptionEvent(SipEvent):
    __swig_setmethods__ = {}
    for _s in [SipEvent]: __swig_setmethods__.update(getattr(_s,'__swig_setmethods__',{}))
    __setattr__ = lambda self, name, value: _swig_setattr(self, SubscriptionEvent, name, value)
    __swig_getmethods__ = {}
    for _s in [SipEvent]: __swig_getmethods__.update(getattr(_s,'__swig_getmethods__',{}))
    __getattr__ = lambda self, name: _swig_getattr(self, SubscriptionEvent, name)
    def __init__(self, *args, **kwargs): raise AttributeError("No constructor defined")
    __repr__ = _swig_repr
    __swig_destroy__ = _tinyWRAP.delete_SubscriptionEvent
    __del__ = lambda self : None;
    def getType(self): return _tinyWRAP.SubscriptionEvent_getType(self)
    def getSession(self): return _tinyWRAP.SubscriptionEvent_getSession(self)
SubscriptionEvent_swigregister = _tinyWRAP.SubscriptionEvent_swigregister
SubscriptionEvent_swigregister(SubscriptionEvent)

class SipSession(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, SipSession, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, SipSession, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        this = _tinyWRAP.new_SipSession(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _tinyWRAP.delete_SipSession
    __del__ = lambda self : None;
    def haveOwnership(self): return _tinyWRAP.SipSession_haveOwnership(self)
    def addHeader(self, *args): return _tinyWRAP.SipSession_addHeader(self, *args)
    def removeHeader(self, *args): return _tinyWRAP.SipSession_removeHeader(self, *args)
    def addCaps(self, *args): return _tinyWRAP.SipSession_addCaps(self, *args)
    def removeCaps(self, *args): return _tinyWRAP.SipSession_removeCaps(self, *args)
    def setExpires(self, *args): return _tinyWRAP.SipSession_setExpires(self, *args)
    def setFromUri(self, *args): return _tinyWRAP.SipSession_setFromUri(self, *args)
    def setToUri(self, *args): return _tinyWRAP.SipSession_setToUri(self, *args)
    def setSilentHangup(self, *args): return _tinyWRAP.SipSession_setSilentHangup(self, *args)
    def getId(self): return _tinyWRAP.SipSession_getId(self)
SipSession_swigregister = _tinyWRAP.SipSession_swigregister
SipSession_swigregister(SipSession)

class CallSession(SipSession):
    __swig_setmethods__ = {}
    for _s in [SipSession]: __swig_setmethods__.update(getattr(_s,'__swig_setmethods__',{}))
    __setattr__ = lambda self, name, value: _swig_setattr(self, CallSession, name, value)
    __swig_getmethods__ = {}
    for _s in [SipSession]: __swig_getmethods__.update(getattr(_s,'__swig_getmethods__',{}))
    __getattr__ = lambda self, name: _swig_getattr(self, CallSession, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        this = _tinyWRAP.new_CallSession(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _tinyWRAP.delete_CallSession
    __del__ = lambda self : None;
    def CallAudio(self, *args): return _tinyWRAP.CallSession_CallAudio(self, *args)
    def CallAudioVideo(self, *args): return _tinyWRAP.CallSession_CallAudioVideo(self, *args)
    def CallVideo(self, *args): return _tinyWRAP.CallSession_CallVideo(self, *args)
    def Accept(self): return _tinyWRAP.CallSession_Accept(self)
    def Hold(self): return _tinyWRAP.CallSession_Hold(self)
    def Resume(self): return _tinyWRAP.CallSession_Resume(self)
    def Hangup(self): return _tinyWRAP.CallSession_Hangup(self)
CallSession_swigregister = _tinyWRAP.CallSession_swigregister
CallSession_swigregister(CallSession)

class MessagingSession(SipSession):
    __swig_setmethods__ = {}
    for _s in [SipSession]: __swig_setmethods__.update(getattr(_s,'__swig_setmethods__',{}))
    __setattr__ = lambda self, name, value: _swig_setattr(self, MessagingSession, name, value)
    __swig_getmethods__ = {}
    for _s in [SipSession]: __swig_getmethods__.update(getattr(_s,'__swig_getmethods__',{}))
    __getattr__ = lambda self, name: _swig_getattr(self, MessagingSession, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        this = _tinyWRAP.new_MessagingSession(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _tinyWRAP.delete_MessagingSession
    __del__ = lambda self : None;
    def Send(self, *args): return _tinyWRAP.MessagingSession_Send(self, *args)
    def Accept(self): return _tinyWRAP.MessagingSession_Accept(self)
    def Reject(self): return _tinyWRAP.MessagingSession_Reject(self)
MessagingSession_swigregister = _tinyWRAP.MessagingSession_swigregister
MessagingSession_swigregister(MessagingSession)

class OptionsSession(SipSession):
    __swig_setmethods__ = {}
    for _s in [SipSession]: __swig_setmethods__.update(getattr(_s,'__swig_setmethods__',{}))
    __setattr__ = lambda self, name, value: _swig_setattr(self, OptionsSession, name, value)
    __swig_getmethods__ = {}
    for _s in [SipSession]: __swig_getmethods__.update(getattr(_s,'__swig_getmethods__',{}))
    __getattr__ = lambda self, name: _swig_getattr(self, OptionsSession, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        this = _tinyWRAP.new_OptionsSession(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _tinyWRAP.delete_OptionsSession
    __del__ = lambda self : None;
    def Send(self): return _tinyWRAP.OptionsSession_Send(self)
OptionsSession_swigregister = _tinyWRAP.OptionsSession_swigregister
OptionsSession_swigregister(OptionsSession)

class PublicationSession(SipSession):
    __swig_setmethods__ = {}
    for _s in [SipSession]: __swig_setmethods__.update(getattr(_s,'__swig_setmethods__',{}))
    __setattr__ = lambda self, name, value: _swig_setattr(self, PublicationSession, name, value)
    __swig_getmethods__ = {}
    for _s in [SipSession]: __swig_getmethods__.update(getattr(_s,'__swig_getmethods__',{}))
    __getattr__ = lambda self, name: _swig_getattr(self, PublicationSession, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        this = _tinyWRAP.new_PublicationSession(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _tinyWRAP.delete_PublicationSession
    __del__ = lambda self : None;
    def Publish(self, *args): return _tinyWRAP.PublicationSession_Publish(self, *args)
    def UnPublish(self): return _tinyWRAP.PublicationSession_UnPublish(self)
PublicationSession_swigregister = _tinyWRAP.PublicationSession_swigregister
PublicationSession_swigregister(PublicationSession)

class RegistrationSession(SipSession):
    __swig_setmethods__ = {}
    for _s in [SipSession]: __swig_setmethods__.update(getattr(_s,'__swig_setmethods__',{}))
    __setattr__ = lambda self, name, value: _swig_setattr(self, RegistrationSession, name, value)
    __swig_getmethods__ = {}
    for _s in [SipSession]: __swig_getmethods__.update(getattr(_s,'__swig_getmethods__',{}))
    __getattr__ = lambda self, name: _swig_getattr(self, RegistrationSession, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        this = _tinyWRAP.new_RegistrationSession(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _tinyWRAP.delete_RegistrationSession
    __del__ = lambda self : None;
    def Register(self): return _tinyWRAP.RegistrationSession_Register(self)
    def UnRegister(self): return _tinyWRAP.RegistrationSession_UnRegister(self)
RegistrationSession_swigregister = _tinyWRAP.RegistrationSession_swigregister
RegistrationSession_swigregister(RegistrationSession)

class SubscriptionSession(SipSession):
    __swig_setmethods__ = {}
    for _s in [SipSession]: __swig_setmethods__.update(getattr(_s,'__swig_setmethods__',{}))
    __setattr__ = lambda self, name, value: _swig_setattr(self, SubscriptionSession, name, value)
    __swig_getmethods__ = {}
    for _s in [SipSession]: __swig_getmethods__.update(getattr(_s,'__swig_getmethods__',{}))
    __getattr__ = lambda self, name: _swig_getattr(self, SubscriptionSession, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        this = _tinyWRAP.new_SubscriptionSession(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _tinyWRAP.delete_SubscriptionSession
    __del__ = lambda self : None;
    def Subscribe(self): return _tinyWRAP.SubscriptionSession_Subscribe(self)
    def UnSubscribe(self): return _tinyWRAP.SubscriptionSession_UnSubscribe(self)
SubscriptionSession_swigregister = _tinyWRAP.SubscriptionSession_swigregister
SubscriptionSession_swigregister(SubscriptionSession)

class ProxyAudioConsumer(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, ProxyAudioConsumer, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, ProxyAudioConsumer, name)
    __repr__ = _swig_repr
    def __init__(self): 
        if self.__class__ == ProxyAudioConsumer:
            _self = None
        else:
            _self = self
        this = _tinyWRAP.new_ProxyAudioConsumer(_self, )
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _tinyWRAP.delete_ProxyAudioConsumer
    __del__ = lambda self : None;
    def prepare(self, *args): return _tinyWRAP.ProxyAudioConsumer_prepare(self, *args)
    def start(self): return _tinyWRAP.ProxyAudioConsumer_start(self)
    def pause(self): return _tinyWRAP.ProxyAudioConsumer_pause(self)
    def stop(self): return _tinyWRAP.ProxyAudioConsumer_stop(self)
    def setActivate(self, *args): return _tinyWRAP.ProxyAudioConsumer_setActivate(self, *args)
    def pull(self, *args): return _tinyWRAP.ProxyAudioConsumer_pull(self, *args)
    __swig_getmethods__["registerPlugin"] = lambda x: _tinyWRAP.ProxyAudioConsumer_registerPlugin
    if _newclass:registerPlugin = staticmethod(_tinyWRAP.ProxyAudioConsumer_registerPlugin)
    def __disown__(self):
        self.this.disown()
        _tinyWRAP.disown_ProxyAudioConsumer(self)
        return weakref_proxy(self)
ProxyAudioConsumer_swigregister = _tinyWRAP.ProxyAudioConsumer_swigregister
ProxyAudioConsumer_swigregister(ProxyAudioConsumer)

def ProxyAudioConsumer_registerPlugin():
  return _tinyWRAP.ProxyAudioConsumer_registerPlugin()
ProxyAudioConsumer_registerPlugin = _tinyWRAP.ProxyAudioConsumer_registerPlugin

class ProxyVideoConsumer(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, ProxyVideoConsumer, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, ProxyVideoConsumer, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        if self.__class__ == ProxyVideoConsumer:
            _self = None
        else:
            _self = self
        this = _tinyWRAP.new_ProxyVideoConsumer(_self, *args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _tinyWRAP.delete_ProxyVideoConsumer
    __del__ = lambda self : None;
    def prepare(self, *args): return _tinyWRAP.ProxyVideoConsumer_prepare(self, *args)
    def consume(self, *args): return _tinyWRAP.ProxyVideoConsumer_consume(self, *args)
    def start(self): return _tinyWRAP.ProxyVideoConsumer_start(self)
    def pause(self): return _tinyWRAP.ProxyVideoConsumer_pause(self)
    def stop(self): return _tinyWRAP.ProxyVideoConsumer_stop(self)
    def setActivate(self, *args): return _tinyWRAP.ProxyVideoConsumer_setActivate(self, *args)
    __swig_getmethods__["registerPlugin"] = lambda x: _tinyWRAP.ProxyVideoConsumer_registerPlugin
    if _newclass:registerPlugin = staticmethod(_tinyWRAP.ProxyVideoConsumer_registerPlugin)
    def __disown__(self):
        self.this.disown()
        _tinyWRAP.disown_ProxyVideoConsumer(self)
        return weakref_proxy(self)
ProxyVideoConsumer_swigregister = _tinyWRAP.ProxyVideoConsumer_swigregister
ProxyVideoConsumer_swigregister(ProxyVideoConsumer)

def ProxyVideoConsumer_registerPlugin():
  return _tinyWRAP.ProxyVideoConsumer_registerPlugin()
ProxyVideoConsumer_registerPlugin = _tinyWRAP.ProxyVideoConsumer_registerPlugin

class ProxyVideoFrame(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, ProxyVideoFrame, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, ProxyVideoFrame, name)
    def __init__(self, *args, **kwargs): raise AttributeError("No constructor defined")
    __repr__ = _swig_repr
    __swig_destroy__ = _tinyWRAP.delete_ProxyVideoFrame
    __del__ = lambda self : None;
    def getSize(self): return _tinyWRAP.ProxyVideoFrame_getSize(self)
    def getContent(self, *args): return _tinyWRAP.ProxyVideoFrame_getContent(self, *args)
ProxyVideoFrame_swigregister = _tinyWRAP.ProxyVideoFrame_swigregister
ProxyVideoFrame_swigregister(ProxyVideoFrame)

class ProxyAudioProducer(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, ProxyAudioProducer, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, ProxyAudioProducer, name)
    __repr__ = _swig_repr
    def __init__(self): 
        if self.__class__ == ProxyAudioProducer:
            _self = None
        else:
            _self = self
        this = _tinyWRAP.new_ProxyAudioProducer(_self, )
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _tinyWRAP.delete_ProxyAudioProducer
    __del__ = lambda self : None;
    def prepare(self, *args): return _tinyWRAP.ProxyAudioProducer_prepare(self, *args)
    def start(self): return _tinyWRAP.ProxyAudioProducer_start(self)
    def pause(self): return _tinyWRAP.ProxyAudioProducer_pause(self)
    def stop(self): return _tinyWRAP.ProxyAudioProducer_stop(self)
    def setActivate(self, *args): return _tinyWRAP.ProxyAudioProducer_setActivate(self, *args)
    def push(self, *args): return _tinyWRAP.ProxyAudioProducer_push(self, *args)
    __swig_getmethods__["registerPlugin"] = lambda x: _tinyWRAP.ProxyAudioProducer_registerPlugin
    if _newclass:registerPlugin = staticmethod(_tinyWRAP.ProxyAudioProducer_registerPlugin)
    def __disown__(self):
        self.this.disown()
        _tinyWRAP.disown_ProxyAudioProducer(self)
        return weakref_proxy(self)
ProxyAudioProducer_swigregister = _tinyWRAP.ProxyAudioProducer_swigregister
ProxyAudioProducer_swigregister(ProxyAudioProducer)

def ProxyAudioProducer_registerPlugin():
  return _tinyWRAP.ProxyAudioProducer_registerPlugin()
ProxyAudioProducer_registerPlugin = _tinyWRAP.ProxyAudioProducer_registerPlugin

class ProxyVideoProducer(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, ProxyVideoProducer, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, ProxyVideoProducer, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        if self.__class__ == ProxyVideoProducer:
            _self = None
        else:
            _self = self
        this = _tinyWRAP.new_ProxyVideoProducer(_self, *args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _tinyWRAP.delete_ProxyVideoProducer
    __del__ = lambda self : None;
    def prepare(self, *args): return _tinyWRAP.ProxyVideoProducer_prepare(self, *args)
    def start(self): return _tinyWRAP.ProxyVideoProducer_start(self)
    def pause(self): return _tinyWRAP.ProxyVideoProducer_pause(self)
    def stop(self): return _tinyWRAP.ProxyVideoProducer_stop(self)
    def setActivate(self, *args): return _tinyWRAP.ProxyVideoProducer_setActivate(self, *args)
    def push(self, *args): return _tinyWRAP.ProxyVideoProducer_push(self, *args)
    __swig_getmethods__["registerPlugin"] = lambda x: _tinyWRAP.ProxyVideoProducer_registerPlugin
    if _newclass:registerPlugin = staticmethod(_tinyWRAP.ProxyVideoProducer_registerPlugin)
    def __disown__(self):
        self.this.disown()
        _tinyWRAP.disown_ProxyVideoProducer(self)
        return weakref_proxy(self)
ProxyVideoProducer_swigregister = _tinyWRAP.ProxyVideoProducer_swigregister
ProxyVideoProducer_swigregister(ProxyVideoProducer)

def ProxyVideoProducer_registerPlugin():
  return _tinyWRAP.ProxyVideoProducer_registerPlugin()
ProxyVideoProducer_registerPlugin = _tinyWRAP.ProxyVideoProducer_registerPlugin

class SipCallback(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, SipCallback, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, SipCallback, name)
    __repr__ = _swig_repr
    def __init__(self): 
        if self.__class__ == SipCallback:
            _self = None
        else:
            _self = self
        this = _tinyWRAP.new_SipCallback(_self, )
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _tinyWRAP.delete_SipCallback
    __del__ = lambda self : None;
    def OnDialogEvent(self, *args): return _tinyWRAP.SipCallback_OnDialogEvent(self, *args)
    def OnStackEvent(self, *args): return _tinyWRAP.SipCallback_OnStackEvent(self, *args)
    def OnCallEvent(self, *args): return _tinyWRAP.SipCallback_OnCallEvent(self, *args)
    def OnMessagingEvent(self, *args): return _tinyWRAP.SipCallback_OnMessagingEvent(self, *args)
    def OnOptionsEvent(self, *args): return _tinyWRAP.SipCallback_OnOptionsEvent(self, *args)
    def OnPublicationEvent(self, *args): return _tinyWRAP.SipCallback_OnPublicationEvent(self, *args)
    def OnRegistrationEvent(self, *args): return _tinyWRAP.SipCallback_OnRegistrationEvent(self, *args)
    def OnSubscriptionEvent(self, *args): return _tinyWRAP.SipCallback_OnSubscriptionEvent(self, *args)
    def __disown__(self):
        self.this.disown()
        _tinyWRAP.disown_SipCallback(self)
        return weakref_proxy(self)
SipCallback_swigregister = _tinyWRAP.SipCallback_swigregister
SipCallback_swigregister(SipCallback)

class SafeObject(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, SafeObject, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, SafeObject, name)
    __repr__ = _swig_repr
    def __init__(self): 
        this = _tinyWRAP.new_SafeObject()
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _tinyWRAP.delete_SafeObject
    __del__ = lambda self : None;
    def Lock(self): return _tinyWRAP.SafeObject_Lock(self)
    def UnLock(self): return _tinyWRAP.SafeObject_UnLock(self)
SafeObject_swigregister = _tinyWRAP.SafeObject_swigregister
SafeObject_swigregister(SafeObject)

class SipStack(SafeObject):
    __swig_setmethods__ = {}
    for _s in [SafeObject]: __swig_setmethods__.update(getattr(_s,'__swig_setmethods__',{}))
    __setattr__ = lambda self, name, value: _swig_setattr(self, SipStack, name, value)
    __swig_getmethods__ = {}
    for _s in [SafeObject]: __swig_getmethods__.update(getattr(_s,'__swig_getmethods__',{}))
    __getattr__ = lambda self, name: _swig_getattr(self, SipStack, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        this = _tinyWRAP.new_SipStack(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _tinyWRAP.delete_SipStack
    __del__ = lambda self : None;
    def start(self): return _tinyWRAP.SipStack_start(self)
    def setDebugCallback(self, *args): return _tinyWRAP.SipStack_setDebugCallback(self, *args)
    def setRealm(self, *args): return _tinyWRAP.SipStack_setRealm(self, *args)
    def setIMPI(self, *args): return _tinyWRAP.SipStack_setIMPI(self, *args)
    def setIMPU(self, *args): return _tinyWRAP.SipStack_setIMPU(self, *args)
    def setPassword(self, *args): return _tinyWRAP.SipStack_setPassword(self, *args)
    def setProxyCSCF(self, *args): return _tinyWRAP.SipStack_setProxyCSCF(self, *args)
    def setLocalIP(self, *args): return _tinyWRAP.SipStack_setLocalIP(self, *args)
    def setLocalPort(self, *args): return _tinyWRAP.SipStack_setLocalPort(self, *args)
    def setEarlyIMS(self, *args): return _tinyWRAP.SipStack_setEarlyIMS(self, *args)
    def addHeader(self, *args): return _tinyWRAP.SipStack_addHeader(self, *args)
    def removeHeader(self, *args): return _tinyWRAP.SipStack_removeHeader(self, *args)
    def addDnsServer(self, *args): return _tinyWRAP.SipStack_addDnsServer(self, *args)
    def setAoR(self, *args): return _tinyWRAP.SipStack_setAoR(self, *args)
    def isValid(self): return _tinyWRAP.SipStack_isValid(self)
    def stop(self): return _tinyWRAP.SipStack_stop(self)
SipStack_swigregister = _tinyWRAP.SipStack_swigregister
SipStack_swigregister(SipStack)

tsip_event_invite = _tinyWRAP.tsip_event_invite
tsip_event_message = _tinyWRAP.tsip_event_message
tsip_event_options = _tinyWRAP.tsip_event_options
tsip_event_publish = _tinyWRAP.tsip_event_publish
tsip_event_register = _tinyWRAP.tsip_event_register
tsip_event_subscribe = _tinyWRAP.tsip_event_subscribe
tsip_event_dialog = _tinyWRAP.tsip_event_dialog
tsip_event_code_dialog_transport_error = _tinyWRAP.tsip_event_code_dialog_transport_error
tsip_event_code_dialog_global_error = _tinyWRAP.tsip_event_code_dialog_global_error
tsip_event_code_dialog_message_error = _tinyWRAP.tsip_event_code_dialog_message_error
tsip_event_code_dialog_request_incoming = _tinyWRAP.tsip_event_code_dialog_request_incoming
tsip_event_code_dialog_request_cancelled = _tinyWRAP.tsip_event_code_dialog_request_cancelled
tsip_event_code_dialog_request_sent = _tinyWRAP.tsip_event_code_dialog_request_sent
tsip_event_code_dialog_connecting = _tinyWRAP.tsip_event_code_dialog_connecting
tsip_event_code_dialog_connected = _tinyWRAP.tsip_event_code_dialog_connected
tsip_event_code_dialog_terminating = _tinyWRAP.tsip_event_code_dialog_terminating
tsip_event_code_dialog_terminated = _tinyWRAP.tsip_event_code_dialog_terminated
tsip_event_code_stack_started = _tinyWRAP.tsip_event_code_stack_started
tsip_event_code_stack_stopped = _tinyWRAP.tsip_event_code_stack_stopped
tsip_event_code_stack_failed_to_start = _tinyWRAP.tsip_event_code_stack_failed_to_start
tsip_event_code_stack_failed_to_stop = _tinyWRAP.tsip_event_code_stack_failed_to_stop
tsip_i_register = _tinyWRAP.tsip_i_register
tsip_ao_register = _tinyWRAP.tsip_ao_register
tsip_i_unregister = _tinyWRAP.tsip_i_unregister
tsip_ao_unregister = _tinyWRAP.tsip_ao_unregister
tsip_i_subscribe = _tinyWRAP.tsip_i_subscribe
tsip_ao_subscribe = _tinyWRAP.tsip_ao_subscribe
tsip_i_unsubscribe = _tinyWRAP.tsip_i_unsubscribe
tsip_ao_unsubscribe = _tinyWRAP.tsip_ao_unsubscribe
tsip_i_notify = _tinyWRAP.tsip_i_notify
tsip_ao_notify = _tinyWRAP.tsip_ao_notify
tsip_i_publish = _tinyWRAP.tsip_i_publish
tsip_ao_publish = _tinyWRAP.tsip_ao_publish
tsip_i_unpublish = _tinyWRAP.tsip_i_unpublish
tsip_ao_unpublish = _tinyWRAP.tsip_ao_unpublish
tsip_i_message = _tinyWRAP.tsip_i_message
tsip_ao_message = _tinyWRAP.tsip_ao_message
tsip_i_options = _tinyWRAP.tsip_i_options
tsip_ao_options = _tinyWRAP.tsip_ao_options
tsip_i_newcall = _tinyWRAP.tsip_i_newcall
tsip_i_request = _tinyWRAP.tsip_i_request
tsip_ao_request = _tinyWRAP.tsip_ao_request
tsip_o_ect_ok = _tinyWRAP.tsip_o_ect_ok
tsip_o_ect_nok = _tinyWRAP.tsip_o_ect_nok
tsip_i_ect = _tinyWRAP.tsip_i_ect
tsip_m_local_hold_ok = _tinyWRAP.tsip_m_local_hold_ok
tsip_m_local_hold_nok = _tinyWRAP.tsip_m_local_hold_nok
tsip_m_local_resume_ok = _tinyWRAP.tsip_m_local_resume_ok
tsip_m_local_resume_nok = _tinyWRAP.tsip_m_local_resume_nok
tsip_m_remote_hold = _tinyWRAP.tsip_m_remote_hold
tsip_m_remote_resume = _tinyWRAP.tsip_m_remote_resume
tmedia_rgb24 = _tinyWRAP.tmedia_rgb24
tmedia_rgb565le = _tinyWRAP.tmedia_rgb565le
tmedia_rgb565be = _tinyWRAP.tmedia_rgb565be
tmedia_nv21 = _tinyWRAP.tmedia_nv21
tmedia_yuv420p = _tinyWRAP.tmedia_yuv420p


