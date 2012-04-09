#include "script_dynamic_sprite.h"

#include "allegro.h"

#include "ac.h"
#include "ac_context.h"
#include "cscomp.h"




// ** SCRIPT DYNAMIC SPRITE

int ScriptDynamicSprite::Dispose(const char *address, bool force) {
  // always dispose
  if ((slot) && (!force))
    free_dynamic_sprite(slot);

  delete this;
  return 1;
}

const char *ScriptDynamicSprite::GetType() {
  return "DynamicSprite";
}

int ScriptDynamicSprite::Serialize(const char *address, char *buffer, int bufsize) {
  StartSerialize(buffer);
  SerializeInt(slot);
  return EndSerialize();
}

void ScriptDynamicSprite::Unserialize(int index, const char *serializedData, int dataSize) {
  StartUnserialize(serializedData, dataSize);
  slot = UnserializeInt();
  ccRegisterUnserializedObject(index, this, this);
}

ScriptDynamicSprite::ScriptDynamicSprite(int theSlot) {
  slot = theSlot;
  ccRegisterManagedObject(this, this);
}

ScriptDynamicSprite::ScriptDynamicSprite() {
  slot = 0;
}