/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 2.0.6
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */


using System;
using System.Runtime.InteropServices;

public class roomstruct : IDisposable {
  private HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal roomstruct(IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new HandleRef(this, cPtr);
  }

  internal static HandleRef getCPtr(roomstruct obj) {
    return (obj == null) ? new HandleRef(null, IntPtr.Zero) : obj.swigCPtr;
  }

  ~roomstruct() {
    Dispose();
  }

  public virtual void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          acswigPINVOKE.delete_roomstruct(swigCPtr);
        }
        swigCPtr = new HandleRef(null, IntPtr.Zero);
      }
      GC.SuppressFinalize(this);
    }
  }

  public SWIGTYPE_p_p_BITMAP ebscene {
    set {
      acswigPINVOKE.roomstruct_ebscene_set(swigCPtr, SWIGTYPE_p_p_BITMAP.getCPtr(value));
    } 
    get {
      IntPtr cPtr = acswigPINVOKE.roomstruct_ebscene_get(swigCPtr);
      SWIGTYPE_p_p_BITMAP ret = (cPtr == IntPtr.Zero) ? null : new SWIGTYPE_p_p_BITMAP(cPtr, false);
      return ret;
    } 
  }

  public BITMAP GetEbScene(int index) {
    IntPtr cPtr = acswigPINVOKE.roomstruct_GetEbScene(swigCPtr, index);
    BITMAP ret = (cPtr == IntPtr.Zero) ? null : new BITMAP(cPtr, false);
    return ret;
  }

  public roomstruct() : this(acswigPINVOKE.new_roomstruct(), true) {
  }

}
