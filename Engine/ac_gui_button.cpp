#include "ac_gui_button.h"

#include "allegro_wrapper.h"

#include "ac.h"
#include "ac_context.h"
#include "acgui.h"
#include "ac_string.h"

// ** start animating buttons code

// returns 1 if animation finished
int UpdateAnimatingButton(int bu) {
  if (animbuts[bu].wait > 0) {
    animbuts[bu].wait--;
    return 0;
  }
  ViewStruct *tview = &views[animbuts[bu].view];

  animbuts[bu].frame++;

  if (animbuts[bu].frame >= tview->loops[animbuts[bu].loop].numFrames) 
  {
    if (tview->loops[animbuts[bu].loop].RunNextLoop()) {
      // go to next loop
      animbuts[bu].loop++;
      animbuts[bu].frame = 0;
    }
    else if (animbuts[bu].repeat) {
      animbuts[bu].frame = 0;
      // multi-loop anim, go back
      while ((animbuts[bu].loop > 0) && 
             (tview->loops[animbuts[bu].loop - 1].RunNextLoop()))
        animbuts[bu].loop--;
    }
    else
      return 1;
  }

  CheckViewFrame(animbuts[bu].view, animbuts[bu].loop, animbuts[bu].frame);

  // update the button's image
  guibuts[animbuts[bu].buttonid].pic = tview->loops[animbuts[bu].loop].frames[animbuts[bu].frame].pic;
  guibuts[animbuts[bu].buttonid].usepic = guibuts[animbuts[bu].buttonid].pic;
  guibuts[animbuts[bu].buttonid].pushedpic = 0;
  guibuts[animbuts[bu].buttonid].overpic = 0;
  guis_need_update = 1;

  animbuts[bu].wait = animbuts[bu].speed + tview->loops[animbuts[bu].loop].frames[animbuts[bu].frame].speed;
  return 0;
}

void StopButtonAnimation(int idxn) {
  numAnimButs--;
  for (int aa = idxn; aa < numAnimButs; aa++) {
    animbuts[aa] = animbuts[aa + 1];
  }
}

void FindAndRemoveButtonAnimation(int guin, int objn) {

  for (int ii = 0; ii < numAnimButs; ii++) {
    if ((animbuts[ii].ongui == guin) && (animbuts[ii].onguibut == objn)) {
      StopButtonAnimation(ii);
      ii--;
    }

  }
}
// ** end animating buttons code


// *** BUTTON FUNCTIONS


/* *** SCRIPT SYMBOL: [Button] Button::Animate^4 *** */
void Button_Animate(GUIButton *butt, int view, int loop, int speed, int repeat) {
  int guin = butt->guin;
  int objn = butt->objn;
  
  if ((view < 1) || (view > game.numviews))
    quit("!AnimateButton: invalid view specified");
  view--;

  if ((loop < 0) || (loop >= views[view].numLoops))
    quit("!AnimateButton: invalid loop specified for view");

  // if it's already animating, stop it
  FindAndRemoveButtonAnimation(guin, objn);

  if (numAnimButs >= MAX_ANIMATING_BUTTONS)
    quit("!AnimateButton: too many animating GUI buttons at once");

  int buttonId = guis[guin].objrefptr[objn] & 0x000ffff;

  guibuts[buttonId].pushedpic = 0;
  guibuts[buttonId].overpic = 0;

  animbuts[numAnimButs].ongui = guin;
  animbuts[numAnimButs].onguibut = objn;
  animbuts[numAnimButs].buttonid = buttonId;
  animbuts[numAnimButs].view = view;
  animbuts[numAnimButs].loop = loop;
  animbuts[numAnimButs].speed = speed;
  animbuts[numAnimButs].repeat = repeat;
  animbuts[numAnimButs].frame = -1;
  animbuts[numAnimButs].wait = 0;
  numAnimButs++;
  // launch into the first frame
  if (UpdateAnimatingButton(numAnimButs - 1))
    quit("!AnimateButton: no frames to animate");
}

/* *** SCRIPT SYMBOL: [Button] Button::get_Text *** */
const char* Button_GetText_New(GUIButton *butt) {
  return CreateNewScriptString(butt->text);
}

/* *** SCRIPT SYMBOL: [Button] Button::GetText^1 *** */
void Button_GetText(GUIButton *butt, char *buffer) {
  strcpy(buffer, butt->text);
}

/* *** SCRIPT SYMBOL: [Button] Button::SetText^1 *** */
/* *** SCRIPT SYMBOL: [Button] Button::set_Text *** */
void Button_SetText(GUIButton *butt, const char *newtx) {
  newtx = get_translation(newtx);
  if (strlen(newtx) > 49) quit("!SetButtonText: text too long, button has 50 chars max");

  if (strcmp(butt->text, newtx)) {
    guis_need_update = 1;
    strcpy(butt->text,newtx);
  }
}

/* *** SCRIPT SYMBOL: [Button] Button::set_Font *** */
void Button_SetFont(GUIButton *butt, int newFont) {
  if ((newFont < 0) || (newFont >= game.numfonts))
    quit("!Button.Font: invalid font number.");

  if (butt->font != newFont) {
    butt->font = newFont;
    guis_need_update = 1;
  }
}

/* *** SCRIPT SYMBOL: [Button] Button::get_Font *** */
int Button_GetFont(GUIButton *butt) {
  return butt->font;
}

/* *** SCRIPT SYMBOL: [Button] Button::get_ClipImage *** */
int Button_GetClipImage(GUIButton *butt) {
  if (butt->flags & GUIF_CLIP)
    return 1;
  return 0;
}

/* *** SCRIPT SYMBOL: [Button] Button::set_ClipImage *** */
void Button_SetClipImage(GUIButton *butt, int newval) {
  butt->flags &= ~GUIF_CLIP;
  if (newval)
    butt->flags |= GUIF_CLIP;

  guis_need_update = 1;
}

/* *** SCRIPT SYMBOL: [Button] Button::get_Graphic *** */
int Button_GetGraphic(GUIButton *butt) {
  // return currently displayed pic
  if (butt->usepic < 0)
    return butt->pic;
  return butt->usepic;
}

/* *** SCRIPT SYMBOL: [Button] Button::get_MouseOverGraphic *** */
int Button_GetMouseOverGraphic(GUIButton *butt) {
  return butt->overpic;
}

/* *** SCRIPT SYMBOL: [Button] Button::set_MouseOverGraphic *** */
void Button_SetMouseOverGraphic(GUIButton *guil, int slotn) {
  DEBUG_CONSOLE("GUI %d Button %d mouseover set to slot %d", guil->guin, guil->objn, slotn);

  if ((guil->isover != 0) && (guil->ispushed == 0))
    guil->usepic = slotn;
  guil->overpic = slotn;

  guis_need_update = 1;
  FindAndRemoveButtonAnimation(guil->guin, guil->objn);
}

/* *** SCRIPT SYMBOL: [Button] Button::get_NormalGraphic *** */
int Button_GetNormalGraphic(GUIButton *butt) {
  return butt->pic;
}

/* *** SCRIPT SYMBOL: [Button] Button::set_NormalGraphic *** */
void Button_SetNormalGraphic(GUIButton *guil, int slotn) {
  DEBUG_CONSOLE("GUI %d Button %d normal set to slot %d", guil->guin, guil->objn, slotn);
  // normal pic - update if mouse is not over, or if there's no overpic
  if (((guil->isover == 0) || (guil->overpic < 1)) && (guil->ispushed == 0))
    guil->usepic = slotn;
  guil->pic = slotn;
  // update the clickable area to the same size as the graphic
  guil->wid = spritewidth[slotn];
  guil->hit = spriteheight[slotn];

  guis_need_update = 1;
  FindAndRemoveButtonAnimation(guil->guin, guil->objn);
}

/* *** SCRIPT SYMBOL: [Button] Button::get_PushedGraphic *** */
int Button_GetPushedGraphic(GUIButton *butt) {
  return butt->pushedpic;
}

/* *** SCRIPT SYMBOL: [Button] Button::set_PushedGraphic *** */
void Button_SetPushedGraphic(GUIButton *guil, int slotn) {
  DEBUG_CONSOLE("GUI %d Button %d pushed set to slot %d", guil->guin, guil->objn, slotn);

  if (guil->ispushed)
    guil->usepic = slotn;
  guil->pushedpic = slotn;

  guis_need_update = 1;
  FindAndRemoveButtonAnimation(guil->guin, guil->objn);
}

/* *** SCRIPT SYMBOL: [Button] Button::get_TextColor *** */
int Button_GetTextColor(GUIButton *butt) {
  return butt->textcol;
}

/* *** SCRIPT SYMBOL: [Button] Button::set_TextColor *** */
void Button_SetTextColor(GUIButton *butt, int newcol) {
  if (butt->textcol != newcol) {
    butt->textcol = newcol;
    guis_need_update = 1;
  }
}

/* *** SCRIPT SYMBOL: [Button] SetButtonText *** */
void SetButtonText(int guin,int objn,char*newtx) {
  VALIDATE_STRING(newtx);
  if ((guin<0) | (guin>=game.numgui))
    quit("!SetButtonText: invalid GUI number");
  if ((objn<0) | (objn>=guis[guin].numobjs))
    quit("!SetButtonText: invalid object number");
  if (guis[guin].get_control_type(objn)!=GOBJ_BUTTON)
    quit("!SetButtonText: specified control is not a button");

  GUIButton*guil=(GUIButton*)guis[guin].objs[objn];
  Button_SetText(guil, newtx);
}


/* *** SCRIPT SYMBOL: [Button] AnimateButton *** */
void AnimateButton(int guin, int objn, int view, int loop, int speed, int repeat) {
  if ((guin<0) | (guin>=game.numgui)) quit("!AnimateButton: invalid GUI number");
  if ((objn<0) | (objn>=guis[guin].numobjs)) quit("!AnimateButton: invalid object number");
  if (guis[guin].get_control_type(objn)!=GOBJ_BUTTON)
    quit("!AnimateButton: specified control is not a button");

  Button_Animate((GUIButton*)guis[guin].objs[objn], view, loop, speed, repeat);
}


/* *** SCRIPT SYMBOL: [Button] GetButtonPic *** */
int GetButtonPic(int guin, int objn, int ptype) {
  if ((guin<0) | (guin>=game.numgui)) quit("!GetButtonPic: invalid GUI number");
  if ((objn<0) | (objn>=guis[guin].numobjs)) quit("!GetButtonPic: invalid object number");
  if (guis[guin].get_control_type(objn)!=GOBJ_BUTTON)
    quit("!GetButtonPic: specified control is not a button");
  if ((ptype < 0) | (ptype > 3)) quit("!GetButtonPic: invalid pic type");

  GUIButton*guil=(GUIButton*)guis[guin].objs[objn];

  if (ptype == 0) {
    // currently displayed pic
    if (guil->usepic < 0)
      return guil->pic;
    return guil->usepic;
  }
  else if (ptype==1) {
    // nomal pic
    return guil->pic;
  }
  else if (ptype==2) {
    // mouseover pic
    return guil->overpic;
  }
  else { // pushed pic
    return guil->pushedpic;
  }

  quit("internal error in getbuttonpic");
}

/* *** SCRIPT SYMBOL: [Button] SetButtonPic *** */
void SetButtonPic(int guin,int objn,int ptype,int slotn) {
  if ((guin<0) | (guin>=game.numgui)) quit("!SetButtonPic: invalid GUI number");
  if ((objn<0) | (objn>=guis[guin].numobjs)) quit("!SetButtonPic: invalid object number");
  if (guis[guin].get_control_type(objn)!=GOBJ_BUTTON)
    quit("!SetButtonPic: specified control is not a button");
  if ((ptype<1) | (ptype>3)) quit("!SetButtonPic: invalid pic type");

  GUIButton*guil=(GUIButton*)guis[guin].objs[objn];
  if (ptype==1) {
    Button_SetNormalGraphic(guil, slotn);
  }
  else if (ptype==2) {
    // mouseover pic
    Button_SetMouseOverGraphic(guil, slotn);
  }
  else { // pushed pic
    Button_SetPushedGraphic(guil, slotn);
  }
}

void register_button_script_functions() {
  scAdd_External_Symbol("Button::Animate^4", (void *)Button_Animate);
  scAdd_External_Symbol("Button::GetText^1", (void *)Button_GetText);
  scAdd_External_Symbol("Button::SetText^1", (void *)Button_SetText);
  scAdd_External_Symbol("Button::get_ClipImage", (void *)Button_GetClipImage);
  scAdd_External_Symbol("Button::set_ClipImage", (void *)Button_SetClipImage);
  scAdd_External_Symbol("Button::get_Font", (void *)Button_GetFont);
  scAdd_External_Symbol("Button::set_Font", (void *)Button_SetFont);
  scAdd_External_Symbol("Button::get_Graphic", (void *)Button_GetGraphic);
  scAdd_External_Symbol("Button::get_MouseOverGraphic", (void *)Button_GetMouseOverGraphic);
  scAdd_External_Symbol("Button::set_MouseOverGraphic", (void *)Button_SetMouseOverGraphic);
  scAdd_External_Symbol("Button::get_NormalGraphic", (void *)Button_GetNormalGraphic);
  scAdd_External_Symbol("Button::set_NormalGraphic", (void *)Button_SetNormalGraphic);
  scAdd_External_Symbol("Button::get_PushedGraphic", (void *)Button_GetPushedGraphic);
  scAdd_External_Symbol("Button::set_PushedGraphic", (void *)Button_SetPushedGraphic);
  scAdd_External_Symbol("Button::get_Text", (void *)Button_GetText_New);
  scAdd_External_Symbol("Button::set_Text", (void *)Button_SetText);
  scAdd_External_Symbol("Button::get_TextColor", (void *)Button_GetTextColor);
  scAdd_External_Symbol("Button::set_TextColor", (void *)Button_SetTextColor);
  scAdd_External_Symbol("AnimateButton",(void *)AnimateButton);
  scAdd_External_Symbol("GetButtonPic",(void *)GetButtonPic);
  scAdd_External_Symbol("SetButtonPic",(void *)SetButtonPic);
  scAdd_External_Symbol("SetButtonText",(void *)SetButtonText);
}

