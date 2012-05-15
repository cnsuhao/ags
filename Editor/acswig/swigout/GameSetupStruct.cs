/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 2.0.6
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */


using System;
using System.Runtime.InteropServices;

public class GameSetupStruct : GameSetupStructBase {
  private HandleRef swigCPtr;

  internal GameSetupStruct(IntPtr cPtr, bool cMemoryOwn) : base(acswigPINVOKE.GameSetupStruct_SWIGUpcast(cPtr), cMemoryOwn) {
    swigCPtr = new HandleRef(this, cPtr);
  }

  internal static HandleRef getCPtr(GameSetupStruct obj) {
    return (obj == null) ? new HandleRef(null, IntPtr.Zero) : obj.swigCPtr;
  }

  ~GameSetupStruct() {
    Dispose();
  }

  public override void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          acswigPINVOKE.delete_GameSetupStruct(swigCPtr);
        }
        swigCPtr = new HandleRef(null, IntPtr.Zero);
      }
      GC.SuppressFinalize(this);
      base.Dispose();
    }
  }

  public SWIGTYPE_p_unsigned_char fontflags {
    set {
      acswigPINVOKE.GameSetupStruct_fontflags_set(swigCPtr, SWIGTYPE_p_unsigned_char.getCPtr(value));
    } 
    get {
      IntPtr cPtr = acswigPINVOKE.GameSetupStruct_fontflags_get(swigCPtr);
      SWIGTYPE_p_unsigned_char ret = (cPtr == IntPtr.Zero) ? null : new SWIGTYPE_p_unsigned_char(cPtr, false);
      return ret;
    } 
  }

  public string fontoutline {
    set {
      acswigPINVOKE.GameSetupStruct_fontoutline_set(swigCPtr, value);
    } 
    get {
      string ret = acswigPINVOKE.GameSetupStruct_fontoutline_get(swigCPtr);
      return ret;
    } 
  }

  public SWIGTYPE_p_unsigned_char spriteflags {
    set {
      acswigPINVOKE.GameSetupStruct_spriteflags_set(swigCPtr, SWIGTYPE_p_unsigned_char.getCPtr(value));
    } 
    get {
      IntPtr cPtr = acswigPINVOKE.GameSetupStruct_spriteflags_get(swigCPtr);
      SWIGTYPE_p_unsigned_char ret = (cPtr == IntPtr.Zero) ? null : new SWIGTYPE_p_unsigned_char(cPtr, false);
      return ret;
    } 
  }

  public SWIGTYPE_p_InventoryItemInfo invinfo {
    set {
      acswigPINVOKE.GameSetupStruct_invinfo_set(swigCPtr, SWIGTYPE_p_InventoryItemInfo.getCPtr(value));
    } 
    get {
      IntPtr cPtr = acswigPINVOKE.GameSetupStruct_invinfo_get(swigCPtr);
      SWIGTYPE_p_InventoryItemInfo ret = (cPtr == IntPtr.Zero) ? null : new SWIGTYPE_p_InventoryItemInfo(cPtr, false);
      return ret;
    } 
  }

  public SWIGTYPE_p_MouseCursor mcurs {
    set {
      acswigPINVOKE.GameSetupStruct_mcurs_set(swigCPtr, SWIGTYPE_p_MouseCursor.getCPtr(value));
    } 
    get {
      IntPtr cPtr = acswigPINVOKE.GameSetupStruct_mcurs_get(swigCPtr);
      SWIGTYPE_p_MouseCursor ret = (cPtr == IntPtr.Zero) ? null : new SWIGTYPE_p_MouseCursor(cPtr, false);
      return ret;
    } 
  }

  public SWIGTYPE_p_p_NewInteraction intrChar {
    set {
      acswigPINVOKE.GameSetupStruct_intrChar_set(swigCPtr, SWIGTYPE_p_p_NewInteraction.getCPtr(value));
    } 
    get {
      IntPtr cPtr = acswigPINVOKE.GameSetupStruct_intrChar_get(swigCPtr);
      SWIGTYPE_p_p_NewInteraction ret = (cPtr == IntPtr.Zero) ? null : new SWIGTYPE_p_p_NewInteraction(cPtr, false);
      return ret;
    } 
  }

  public SWIGTYPE_p_p_NewInteraction intrInv {
    set {
      acswigPINVOKE.GameSetupStruct_intrInv_set(swigCPtr, SWIGTYPE_p_p_NewInteraction.getCPtr(value));
    } 
    get {
      IntPtr cPtr = acswigPINVOKE.GameSetupStruct_intrInv_get(swigCPtr);
      SWIGTYPE_p_p_NewInteraction ret = (cPtr == IntPtr.Zero) ? null : new SWIGTYPE_p_p_NewInteraction(cPtr, false);
      return ret;
    } 
  }

  public SWIGTYPE_p_p_InteractionScripts charScripts {
    set {
      acswigPINVOKE.GameSetupStruct_charScripts_set(swigCPtr, SWIGTYPE_p_p_InteractionScripts.getCPtr(value));
    } 
    get {
      IntPtr cPtr = acswigPINVOKE.GameSetupStruct_charScripts_get(swigCPtr);
      SWIGTYPE_p_p_InteractionScripts ret = (cPtr == IntPtr.Zero) ? null : new SWIGTYPE_p_p_InteractionScripts(cPtr, false);
      return ret;
    } 
  }

  public SWIGTYPE_p_p_InteractionScripts invScripts {
    set {
      acswigPINVOKE.GameSetupStruct_invScripts_set(swigCPtr, SWIGTYPE_p_p_InteractionScripts.getCPtr(value));
    } 
    get {
      IntPtr cPtr = acswigPINVOKE.GameSetupStruct_invScripts_get(swigCPtr);
      SWIGTYPE_p_p_InteractionScripts ret = (cPtr == IntPtr.Zero) ? null : new SWIGTYPE_p_p_InteractionScripts(cPtr, false);
      return ret;
    } 
  }

  public int filever {
    set {
      acswigPINVOKE.GameSetupStruct_filever_set(swigCPtr, value);
    } 
    get {
      int ret = acswigPINVOKE.GameSetupStruct_filever_get(swigCPtr);
      return ret;
    } 
  }

  public SWIGTYPE_p_a_50__char lipSyncFrameLetters {
    set {
      acswigPINVOKE.GameSetupStruct_lipSyncFrameLetters_set(swigCPtr, SWIGTYPE_p_a_50__char.getCPtr(value));
    } 
    get {
      IntPtr cPtr = acswigPINVOKE.GameSetupStruct_lipSyncFrameLetters_get(swigCPtr);
      SWIGTYPE_p_a_50__char ret = (cPtr == IntPtr.Zero) ? null : new SWIGTYPE_p_a_50__char(cPtr, false);
      return ret;
    } 
  }

  public SWIGTYPE_p_CustomPropertySchema propSchema {
    set {
      acswigPINVOKE.GameSetupStruct_propSchema_set(swigCPtr, SWIGTYPE_p_CustomPropertySchema.getCPtr(value));
      if (acswigPINVOKE.SWIGPendingException.Pending) throw acswigPINVOKE.SWIGPendingException.Retrieve();
    } 
    get {
      SWIGTYPE_p_CustomPropertySchema ret = new SWIGTYPE_p_CustomPropertySchema(acswigPINVOKE.GameSetupStruct_propSchema_get(swigCPtr), true);
      if (acswigPINVOKE.SWIGPendingException.Pending) throw acswigPINVOKE.SWIGPendingException.Retrieve();
      return ret;
    } 
  }

  public SWIGTYPE_p_CustomProperties charProps {
    set {
      acswigPINVOKE.GameSetupStruct_charProps_set(swigCPtr, SWIGTYPE_p_CustomProperties.getCPtr(value));
    } 
    get {
      IntPtr cPtr = acswigPINVOKE.GameSetupStruct_charProps_get(swigCPtr);
      SWIGTYPE_p_CustomProperties ret = (cPtr == IntPtr.Zero) ? null : new SWIGTYPE_p_CustomProperties(cPtr, false);
      return ret;
    } 
  }

  public SWIGTYPE_p_CustomProperties invProps {
    set {
      acswigPINVOKE.GameSetupStruct_invProps_set(swigCPtr, SWIGTYPE_p_CustomProperties.getCPtr(value));
    } 
    get {
      IntPtr cPtr = acswigPINVOKE.GameSetupStruct_invProps_get(swigCPtr);
      SWIGTYPE_p_CustomProperties ret = (cPtr == IntPtr.Zero) ? null : new SWIGTYPE_p_CustomProperties(cPtr, false);
      return ret;
    } 
  }

  public SWIGTYPE_p_p_char viewNames {
    set {
      acswigPINVOKE.GameSetupStruct_viewNames_set(swigCPtr, SWIGTYPE_p_p_char.getCPtr(value));
    } 
    get {
      IntPtr cPtr = acswigPINVOKE.GameSetupStruct_viewNames_get(swigCPtr);
      SWIGTYPE_p_p_char ret = (cPtr == IntPtr.Zero) ? null : new SWIGTYPE_p_p_char(cPtr, false);
      return ret;
    } 
  }

  public SWIGTYPE_p_a_20__char invScriptNames {
    set {
      acswigPINVOKE.GameSetupStruct_invScriptNames_set(swigCPtr, SWIGTYPE_p_a_20__char.getCPtr(value));
    } 
    get {
      IntPtr cPtr = acswigPINVOKE.GameSetupStruct_invScriptNames_get(swigCPtr);
      SWIGTYPE_p_a_20__char ret = (cPtr == IntPtr.Zero) ? null : new SWIGTYPE_p_a_20__char(cPtr, false);
      return ret;
    } 
  }

  public SWIGTYPE_p_a_20__char dialogScriptNames {
    set {
      acswigPINVOKE.GameSetupStruct_dialogScriptNames_set(swigCPtr, SWIGTYPE_p_a_20__char.getCPtr(value));
    } 
    get {
      IntPtr cPtr = acswigPINVOKE.GameSetupStruct_dialogScriptNames_get(swigCPtr);
      SWIGTYPE_p_a_20__char ret = (cPtr == IntPtr.Zero) ? null : new SWIGTYPE_p_a_20__char(cPtr, false);
      return ret;
    } 
  }

  public string guid {
    set {
      acswigPINVOKE.GameSetupStruct_guid_set(swigCPtr, value);
    } 
    get {
      string ret = acswigPINVOKE.GameSetupStruct_guid_get(swigCPtr);
      return ret;
    } 
  }

  public string saveGameFileExtension {
    set {
      acswigPINVOKE.GameSetupStruct_saveGameFileExtension_set(swigCPtr, value);
    } 
    get {
      string ret = acswigPINVOKE.GameSetupStruct_saveGameFileExtension_get(swigCPtr);
      return ret;
    } 
  }

  public string saveGameFolderName {
    set {
      acswigPINVOKE.GameSetupStruct_saveGameFolderName_set(swigCPtr, value);
    } 
    get {
      string ret = acswigPINVOKE.GameSetupStruct_saveGameFolderName_get(swigCPtr);
      return ret;
    } 
  }

  public int roomCount {
    set {
      acswigPINVOKE.GameSetupStruct_roomCount_set(swigCPtr, value);
    } 
    get {
      int ret = acswigPINVOKE.GameSetupStruct_roomCount_get(swigCPtr);
      return ret;
    } 
  }

  public SWIGTYPE_p_int roomNumbers {
    set {
      acswigPINVOKE.GameSetupStruct_roomNumbers_set(swigCPtr, SWIGTYPE_p_int.getCPtr(value));
    } 
    get {
      IntPtr cPtr = acswigPINVOKE.GameSetupStruct_roomNumbers_get(swigCPtr);
      SWIGTYPE_p_int ret = (cPtr == IntPtr.Zero) ? null : new SWIGTYPE_p_int(cPtr, false);
      return ret;
    } 
  }

  public SWIGTYPE_p_p_char roomNames {
    set {
      acswigPINVOKE.GameSetupStruct_roomNames_set(swigCPtr, SWIGTYPE_p_p_char.getCPtr(value));
    } 
    get {
      IntPtr cPtr = acswigPINVOKE.GameSetupStruct_roomNames_get(swigCPtr);
      SWIGTYPE_p_p_char ret = (cPtr == IntPtr.Zero) ? null : new SWIGTYPE_p_p_char(cPtr, false);
      return ret;
    } 
  }

  public int audioClipCount {
    set {
      acswigPINVOKE.GameSetupStruct_audioClipCount_set(swigCPtr, value);
    } 
    get {
      int ret = acswigPINVOKE.GameSetupStruct_audioClipCount_get(swigCPtr);
      return ret;
    } 
  }

  public SWIGTYPE_p_ScriptAudioClip audioClips {
    set {
      acswigPINVOKE.GameSetupStruct_audioClips_set(swigCPtr, SWIGTYPE_p_ScriptAudioClip.getCPtr(value));
    } 
    get {
      IntPtr cPtr = acswigPINVOKE.GameSetupStruct_audioClips_get(swigCPtr);
      SWIGTYPE_p_ScriptAudioClip ret = (cPtr == IntPtr.Zero) ? null : new SWIGTYPE_p_ScriptAudioClip(cPtr, false);
      return ret;
    } 
  }

  public int audioClipTypeCount {
    set {
      acswigPINVOKE.GameSetupStruct_audioClipTypeCount_set(swigCPtr, value);
    } 
    get {
      int ret = acswigPINVOKE.GameSetupStruct_audioClipTypeCount_get(swigCPtr);
      return ret;
    } 
  }

  public SWIGTYPE_p_AudioClipType audioClipTypes {
    set {
      acswigPINVOKE.GameSetupStruct_audioClipTypes_set(swigCPtr, SWIGTYPE_p_AudioClipType.getCPtr(value));
    } 
    get {
      IntPtr cPtr = acswigPINVOKE.GameSetupStruct_audioClipTypes_get(swigCPtr);
      SWIGTYPE_p_AudioClipType ret = (cPtr == IntPtr.Zero) ? null : new SWIGTYPE_p_AudioClipType(cPtr, false);
      return ret;
    } 
  }

  public bool GetOption(int index) {
    bool ret = acswigPINVOKE.GameSetupStruct_GetOption(swigCPtr, index);
    return ret;
  }

  public void SetOption(int index, bool value) {
    acswigPINVOKE.GameSetupStruct_SetOption(swigCPtr, index, value);
  }

  public byte GetSpriteFlag(int index) {
    byte ret = acswigPINVOKE.GameSetupStruct_GetSpriteFlag(swigCPtr, index);
    return ret;
  }

  public void SetSpriteFlag(int index, byte value) {
    acswigPINVOKE.GameSetupStruct_SetSpriteFlag(swigCPtr, index, value);
  }

  public byte GetPalUse(int index) {
    byte ret = acswigPINVOKE.GameSetupStruct_GetPalUse(swigCPtr, index);
    return ret;
  }

  public void SetPalUse(int index, byte value) {
    acswigPINVOKE.GameSetupStruct_SetPalUse(swigCPtr, index, value);
  }

  public byte GetFontFlag(int index) {
    byte ret = acswigPINVOKE.GameSetupStruct_GetFontFlag(swigCPtr, index);
    return ret;
  }

  public void SetFontFlag(int index, byte value) {
    acswigPINVOKE.GameSetupStruct_SetFontFlag(swigCPtr, index, value);
  }

  public GameSetupStruct() : this(acswigPINVOKE.new_GameSetupStruct(), true) {
  }

}