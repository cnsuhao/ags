#ifndef _AC_TYPES_H_HEADER
#define _AC_TYPES_H_HEADER

// forward declarations:
struct GUIMain; // acgui.h

#define MAX_SCRIPT_MODULES 50

// **** TYPES ****

enum WalkBehindMethodEnum
{
  DrawOverCharSprite,
  DrawAsSeparateSprite,
  DrawAsSeparateCharSprite
};

struct ScriptGUI {
  int id;
  GUIMain *gui;
};

struct ScriptHotspot {
  int id;
  int reserved;
};

struct ScriptRegion {
  int id;
  int reserved;
};

struct TempEip {
  int oldval;
  TempEip::TempEip (int newval) ;
  TempEip::~TempEip () ;
};

struct DebugConsoleText {
  char text[100];
  char script[12];
};

struct CachedActSpsData {
  int xWas, yWas;
  int baselineWas;
  int isWalkBehindHere;
  int valid;
};

struct NonBlockingScriptFunction
{
  const char* functionName;
  int numParameters;
  void* param1;
  void* param2;
  bool roomHasFunction;
  bool globalScriptHasFunction;
  bool moduleHasFunction[MAX_SCRIPT_MODULES];
  bool atLeastOneImplementationExists;

  NonBlockingScriptFunction(const char*funcName, int numParams);
};

struct TopBarSettings {
  int wantIt;
  int height;
  int font;
  char text[200];

  TopBarSettings() {
    wantIt = 0;
    height = 0;
    font = 0;
    text[0] = 0;
  }
};

// Windows Vista Rich Save Games, modified to be platform-agnostic
#define RM_MAXLENGTH    1024
#define RM_MAGICNUMBER  "RGMH"

#pragma pack(push)
#pragma pack(1)
typedef struct _RICH_GAME_MEDIA_HEADER
{
    long       dwMagicNumber;
    long       dwHeaderVersion;
    long       dwHeaderSize;
    long       dwThumbnailOffsetLowerDword;
    long       dwThumbnailOffsetHigherDword;
    long       dwThumbnailSize;
    unsigned char guidGameId[16];
    unsigned short szGameName[RM_MAXLENGTH];
    unsigned short szSaveName[RM_MAXLENGTH];
    unsigned short szLevelName[RM_MAXLENGTH];
    unsigned short szComments[RM_MAXLENGTH];
} RICH_GAME_MEDIA_HEADER;
#pragma pack(pop)



#endif