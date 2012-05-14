/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 2.0.6
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */


using System;
using System.Runtime.InteropServices;

public class GameSetupStructBase : IDisposable {
  private HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal GameSetupStructBase(IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new HandleRef(this, cPtr);
  }

  internal static HandleRef getCPtr(GameSetupStructBase obj) {
    return (obj == null) ? new HandleRef(null, IntPtr.Zero) : obj.swigCPtr;
  }

  ~GameSetupStructBase() {
    Dispose();
  }

  public virtual void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          acswigPINVOKE.delete_GameSetupStructBase(swigCPtr);
        }
        swigCPtr = new HandleRef(null, IntPtr.Zero);
      }
      GC.SuppressFinalize(this);
    }
  }

  public string gamename {
    set {
      acswigPINVOKE.GameSetupStructBase_gamename_set(swigCPtr, value);
    } 
    get {
      string ret = acswigPINVOKE.GameSetupStructBase_gamename_get(swigCPtr);
      return ret;
    } 
  }

  public SWIGTYPE_p_int options {
    set {
      acswigPINVOKE.GameSetupStructBase_options_set(swigCPtr, SWIGTYPE_p_int.getCPtr(value));
    } 
    get {
      IntPtr cPtr = acswigPINVOKE.GameSetupStructBase_options_get(swigCPtr);
      SWIGTYPE_p_int ret = (cPtr == IntPtr.Zero) ? null : new SWIGTYPE_p_int(cPtr, false);
      return ret;
    } 
  }

  public SWIGTYPE_p_unsigned_char paluses {
    set {
      acswigPINVOKE.GameSetupStructBase_paluses_set(swigCPtr, SWIGTYPE_p_unsigned_char.getCPtr(value));
    } 
    get {
      IntPtr cPtr = acswigPINVOKE.GameSetupStructBase_paluses_get(swigCPtr);
      SWIGTYPE_p_unsigned_char ret = (cPtr == IntPtr.Zero) ? null : new SWIGTYPE_p_unsigned_char(cPtr, false);
      return ret;
    } 
  }

  public SWIGTYPE_p_color defpal {
    set {
      acswigPINVOKE.GameSetupStructBase_defpal_set(swigCPtr, SWIGTYPE_p_color.getCPtr(value));
    } 
    get {
      IntPtr cPtr = acswigPINVOKE.GameSetupStructBase_defpal_get(swigCPtr);
      SWIGTYPE_p_color ret = (cPtr == IntPtr.Zero) ? null : new SWIGTYPE_p_color(cPtr, false);
      return ret;
    } 
  }

  public int numviews {
    set {
      acswigPINVOKE.GameSetupStructBase_numviews_set(swigCPtr, value);
    } 
    get {
      int ret = acswigPINVOKE.GameSetupStructBase_numviews_get(swigCPtr);
      return ret;
    } 
  }

  public int numcharacters {
    set {
      acswigPINVOKE.GameSetupStructBase_numcharacters_set(swigCPtr, value);
    } 
    get {
      int ret = acswigPINVOKE.GameSetupStructBase_numcharacters_get(swigCPtr);
      return ret;
    } 
  }

  public int playercharacter {
    set {
      acswigPINVOKE.GameSetupStructBase_playercharacter_set(swigCPtr, value);
    } 
    get {
      int ret = acswigPINVOKE.GameSetupStructBase_playercharacter_get(swigCPtr);
      return ret;
    } 
  }

  public int totalscore {
    set {
      acswigPINVOKE.GameSetupStructBase_totalscore_set(swigCPtr, value);
    } 
    get {
      int ret = acswigPINVOKE.GameSetupStructBase_totalscore_get(swigCPtr);
      return ret;
    } 
  }

  public short numinvitems {
    set {
      acswigPINVOKE.GameSetupStructBase_numinvitems_set(swigCPtr, value);
    } 
    get {
      short ret = acswigPINVOKE.GameSetupStructBase_numinvitems_get(swigCPtr);
      return ret;
    } 
  }

  public int numdialog {
    set {
      acswigPINVOKE.GameSetupStructBase_numdialog_set(swigCPtr, value);
    } 
    get {
      int ret = acswigPINVOKE.GameSetupStructBase_numdialog_get(swigCPtr);
      return ret;
    } 
  }

  public int numdlgmessage {
    set {
      acswigPINVOKE.GameSetupStructBase_numdlgmessage_set(swigCPtr, value);
    } 
    get {
      int ret = acswigPINVOKE.GameSetupStructBase_numdlgmessage_get(swigCPtr);
      return ret;
    } 
  }

  public int numfonts {
    set {
      acswigPINVOKE.GameSetupStructBase_numfonts_set(swigCPtr, value);
    } 
    get {
      int ret = acswigPINVOKE.GameSetupStructBase_numfonts_get(swigCPtr);
      return ret;
    } 
  }

  public int color_depth {
    set {
      acswigPINVOKE.GameSetupStructBase_color_depth_set(swigCPtr, value);
    } 
    get {
      int ret = acswigPINVOKE.GameSetupStructBase_color_depth_get(swigCPtr);
      return ret;
    } 
  }

  public int target_win {
    set {
      acswigPINVOKE.GameSetupStructBase_target_win_set(swigCPtr, value);
    } 
    get {
      int ret = acswigPINVOKE.GameSetupStructBase_target_win_get(swigCPtr);
      return ret;
    } 
  }

  public int dialog_bullet {
    set {
      acswigPINVOKE.GameSetupStructBase_dialog_bullet_set(swigCPtr, value);
    } 
    get {
      int ret = acswigPINVOKE.GameSetupStructBase_dialog_bullet_get(swigCPtr);
      return ret;
    } 
  }

  public ushort hotdot {
    set {
      acswigPINVOKE.GameSetupStructBase_hotdot_set(swigCPtr, value);
    } 
    get {
      ushort ret = acswigPINVOKE.GameSetupStructBase_hotdot_get(swigCPtr);
      return ret;
    } 
  }

  public ushort hotdotouter {
    set {
      acswigPINVOKE.GameSetupStructBase_hotdotouter_set(swigCPtr, value);
    } 
    get {
      ushort ret = acswigPINVOKE.GameSetupStructBase_hotdotouter_get(swigCPtr);
      return ret;
    } 
  }

  public int uniqueid {
    set {
      acswigPINVOKE.GameSetupStructBase_uniqueid_set(swigCPtr, value);
    } 
    get {
      int ret = acswigPINVOKE.GameSetupStructBase_uniqueid_get(swigCPtr);
      return ret;
    } 
  }

  public int numgui {
    set {
      acswigPINVOKE.GameSetupStructBase_numgui_set(swigCPtr, value);
    } 
    get {
      int ret = acswigPINVOKE.GameSetupStructBase_numgui_get(swigCPtr);
      return ret;
    } 
  }

  public int numcursors {
    set {
      acswigPINVOKE.GameSetupStructBase_numcursors_set(swigCPtr, value);
    } 
    get {
      int ret = acswigPINVOKE.GameSetupStructBase_numcursors_get(swigCPtr);
      return ret;
    } 
  }

  public int default_resolution {
    set {
      acswigPINVOKE.GameSetupStructBase_default_resolution_set(swigCPtr, value);
    } 
    get {
      int ret = acswigPINVOKE.GameSetupStructBase_default_resolution_get(swigCPtr);
      return ret;
    } 
  }

  public int default_lipsync_frame {
    set {
      acswigPINVOKE.GameSetupStructBase_default_lipsync_frame_set(swigCPtr, value);
    } 
    get {
      int ret = acswigPINVOKE.GameSetupStructBase_default_lipsync_frame_get(swigCPtr);
      return ret;
    } 
  }

  public int invhotdotsprite {
    set {
      acswigPINVOKE.GameSetupStructBase_invhotdotsprite_set(swigCPtr, value);
    } 
    get {
      int ret = acswigPINVOKE.GameSetupStructBase_invhotdotsprite_get(swigCPtr);
      return ret;
    } 
  }

  public SWIGTYPE_p_int reserved {
    set {
      acswigPINVOKE.GameSetupStructBase_reserved_set(swigCPtr, SWIGTYPE_p_int.getCPtr(value));
    } 
    get {
      IntPtr cPtr = acswigPINVOKE.GameSetupStructBase_reserved_get(swigCPtr);
      SWIGTYPE_p_int ret = (cPtr == IntPtr.Zero) ? null : new SWIGTYPE_p_int(cPtr, false);
      return ret;
    } 
  }

  public SWIGTYPE_p_p_char messages {
    set {
      acswigPINVOKE.GameSetupStructBase_messages_set(swigCPtr, SWIGTYPE_p_p_char.getCPtr(value));
    } 
    get {
      IntPtr cPtr = acswigPINVOKE.GameSetupStructBase_messages_get(swigCPtr);
      SWIGTYPE_p_p_char ret = (cPtr == IntPtr.Zero) ? null : new SWIGTYPE_p_p_char(cPtr, false);
      return ret;
    } 
  }

  public SWIGTYPE_p_WordsDictionary dict {
    set {
      acswigPINVOKE.GameSetupStructBase_dict_set(swigCPtr, SWIGTYPE_p_WordsDictionary.getCPtr(value));
    } 
    get {
      IntPtr cPtr = acswigPINVOKE.GameSetupStructBase_dict_get(swigCPtr);
      SWIGTYPE_p_WordsDictionary ret = (cPtr == IntPtr.Zero) ? null : new SWIGTYPE_p_WordsDictionary(cPtr, false);
      return ret;
    } 
  }

  public string globalscript {
    set {
      acswigPINVOKE.GameSetupStructBase_globalscript_set(swigCPtr, value);
    } 
    get {
      string ret = acswigPINVOKE.GameSetupStructBase_globalscript_get(swigCPtr);
      return ret;
    } 
  }

  public SWIGTYPE_p_CharacterInfo chars {
    set {
      acswigPINVOKE.GameSetupStructBase_chars_set(swigCPtr, SWIGTYPE_p_CharacterInfo.getCPtr(value));
    } 
    get {
      IntPtr cPtr = acswigPINVOKE.GameSetupStructBase_chars_get(swigCPtr);
      SWIGTYPE_p_CharacterInfo ret = (cPtr == IntPtr.Zero) ? null : new SWIGTYPE_p_CharacterInfo(cPtr, false);
      return ret;
    } 
  }

  public SWIGTYPE_p_ccScript compiled_script {
    set {
      acswigPINVOKE.GameSetupStructBase_compiled_script_set(swigCPtr, SWIGTYPE_p_ccScript.getCPtr(value));
    } 
    get {
      IntPtr cPtr = acswigPINVOKE.GameSetupStructBase_compiled_script_get(swigCPtr);
      SWIGTYPE_p_ccScript ret = (cPtr == IntPtr.Zero) ? null : new SWIGTYPE_p_ccScript(cPtr, false);
      return ret;
    } 
  }

  public GameSetupStructBase() : this(acswigPINVOKE.new_GameSetupStructBase(), true) {
  }

}
