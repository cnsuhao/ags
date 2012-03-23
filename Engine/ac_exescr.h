#ifndef _AC_EXESCR_H_HEADER
#define _AC_EXESCR_H_HEADER

struct ccInstance;    // cscomp.h

enum PostScriptAction {
  ePSANewRoom,
  ePSAInvScreen,
  ePSARestoreGame,
  ePSARestoreGameDialog,
  ePSARunAGSGame,
  ePSARunDialog,
  ePSARestartGame,
  ePSASaveGame,
  ePSASaveGameDialog
};

#define MAX_QUEUED_SCRIPTS 4
#define MAX_QUEUED_ACTIONS 5
struct ExecutingScript {
  ccInstance *inst;
  PostScriptAction postScriptActions[MAX_QUEUED_ACTIONS];
  const char *postScriptActionNames[MAX_QUEUED_ACTIONS];
  char postScriptSaveSlotDescription[MAX_QUEUED_ACTIONS][100];
  int  postScriptActionData[MAX_QUEUED_ACTIONS];
  int  numPostScriptActions;
  char script_run_another[MAX_QUEUED_SCRIPTS][30];
  int  run_another_p1[MAX_QUEUED_SCRIPTS];
  int  run_another_p2[MAX_QUEUED_SCRIPTS];
  int  numanother;
  char forked;

  int queue_action(PostScriptAction act, int data, const char *aname);
  void run_another (char *namm, int p1, int p2);
  void init();
  ExecutingScript();
};

#endif
