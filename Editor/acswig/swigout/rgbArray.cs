/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 2.0.6
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */


using System;
using System.Runtime.InteropServices;

public class RgbArray : IDisposable {
  private HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal RgbArray(IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new HandleRef(this, cPtr);
  }

  internal static HandleRef getCPtr(RgbArray obj) {
    return (obj == null) ? new HandleRef(null, IntPtr.Zero) : obj.swigCPtr;
  }

  ~RgbArray() {
    Dispose();
  }

  public virtual void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          acswigPINVOKE.delete_RgbArray(swigCPtr);
        }
        swigCPtr = new HandleRef(null, IntPtr.Zero);
      }
      GC.SuppressFinalize(this);
    }
  }

  public RgbArray(int nelements) : this(acswigPINVOKE.new_RgbArray(nelements), true) {
  }

  public RGB getitem(int index) {
    RGB ret = new RGB(acswigPINVOKE.RgbArray_getitem(swigCPtr, index), true);
    return ret;
  }

  public void setitem(int index, RGB value) {
    acswigPINVOKE.RgbArray_setitem(swigCPtr, index, RGB.getCPtr(value));
    if (acswigPINVOKE.SWIGPendingException.Pending) throw acswigPINVOKE.SWIGPendingException.Retrieve();
  }

  public RGB cast() {
    IntPtr cPtr = acswigPINVOKE.RgbArray_cast(swigCPtr);
    RGB ret = (cPtr == IntPtr.Zero) ? null : new RGB(cPtr, false);
    return ret;
  }

  public static RgbArray frompointer(RGB t) {
    IntPtr cPtr = acswigPINVOKE.RgbArray_frompointer(RGB.getCPtr(t));
    RgbArray ret = (cPtr == IntPtr.Zero) ? null : new RgbArray(cPtr, false);
    return ret;
  }

}
