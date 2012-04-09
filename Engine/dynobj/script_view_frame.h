#ifndef _SCRIPT_VIEW_FRAME_H_HEADER
#define _SCRIPT_VIEW_FRAME_H_HEADER

#include "ags_cc_dynamic_object.h" 


struct ScriptViewFrame : AGSCCDynamicObject {
  int view, loop, frame;

  virtual int Dispose(const char *address, bool force);
  virtual const char *GetType();
  virtual int Serialize(const char *address, char *buffer, int bufsize);
  virtual void Unserialize(int index, const char *serializedData, int dataSize);

  ScriptViewFrame(int p_view, int p_loop, int p_frame);
  ScriptViewFrame();
};

#endif
