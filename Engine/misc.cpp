/*
  Copyright (c) 2003, Shawn R. Walker
  All rights reserved.
  
  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions
  are met:
  
      * Redistributions of source code must retain the above copyright notice,
        this list of conditions and the following disclaimer.
      * Redistributions in binary form must reproduce the above copyright
        notice, this list of conditions and the following disclaimer in the
        documentation and/or other materials provided with the distribution.
      * Neither the name of Shawn R. Walker nor names of contributors
        may be used to endorse or promote products derived from this software
        without specific prior written permission.
  
  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE
  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include "allegro.h"

#include "misc.h"

#if !defined(LINUX_VERSION) && !defined(MAC_VERSION)
#include <string.h>
/* File Name Concatenator basically on Windows / DOS */
char *ci_find_file(const char *dir_name, const char *file_name)
{
  char  *diamond = NULL;

  if (dir_name == NULL && file_name == NULL)
      return NULL;

  if (dir_name == NULL) {
    diamond = (char *)malloc(strlen(file_name) + 3);
    strcpy(diamond, file_name);
  } else {
    diamond = (char *)malloc(strlen(dir_name) + strlen(file_name) + 2);
    alw_append_filename(diamond, dir_name, file_name, strlen(dir_name) + strlen(file_name) + 2);
  }
  alw_fix_filename_case(diamond);
  alw_fix_filename_slashes(diamond);
  return diamond;
}

#else
/* Case Insensitive File Find */
char *ci_find_file(const char *dir_name_in, const char *file_name_in)
{
  struct stat   statbuf;
  struct dirent *entry = NULL;
  DIR           *rough = NULL;
  DIR           *prevdir = NULL;
  char          *diamond = NULL;
  char          *directory = NULL;
  char          *filename = NULL;

  if (dir_name_in == NULL && file_name_in == NULL)
      return NULL;

  char *dir_name = 0;
  char *file_name = 0;
  
  if (dir_name_in) {
    dir_name = (char*)alloca(strlen(dir_name_in)+1);
    strcpy(dir_name, dir_name_in);
  }
  if (file_name_in) {
    file_name = (char*)alloca(strlen(file_name_in)+1);  
    strcpy(file_name, file_name_in);
  }
    
  if (!(dir_name == NULL)) {
    alw_fix_filename_case(dir_name);
    alw_fix_filename_slashes(dir_name);
  }

  alw_fix_filename_case(file_name);
  alw_fix_filename_slashes(file_name);

  if (dir_name == NULL) {
    const char  *match = NULL;
    int   match_len = NULL;
    int   dir_len = NULL;

    match = alw_get_filename(file_name);
    if (match == NULL)
      return NULL;

    match_len = strlen(match);
    dir_len = (match - file_name);

    if (dir_len == 0) {
      directory = (char *)malloc(2);
      strcpy(directory,".");
    } else {
      directory = (char *)malloc(dir_len + 1);
      strncpy(directory, file_name, dir_len);
      directory[dir_len] = '\0';
    }

    filename = (char *)malloc(match_len + 1);
    strncpy(filename, match, match_len);
    filename[match_len] = '\0';
  } else {
    directory = (char *)malloc(strlen(dir_name) + 1);
    strcpy(directory, dir_name);
    
    filename = (char *)malloc(strlen(file_name) + 1);
    strcpy(filename, file_name);
  }

  if ((prevdir = opendir(".")) == NULL) {
    fprintf(stderr, "ci_find_file: cannot open current working directory\n");
    return NULL;
  }

  if (chdir(directory) == -1) {
    fprintf(stderr, "ci_find_file: cannot change to directory: %s\n", directory);
    return NULL;
  }
  
  if ((rough = opendir(directory)) == NULL) {
    fprintf(stderr, "ci_find_file: cannot open directory: %s\n", directory);
    return NULL;
  }

  while ((entry = readdir(rough)) != NULL) {
    lstat(entry->d_name, &statbuf);
    if (S_ISREG(statbuf.st_mode) || S_ISLNK(statbuf.st_mode)) {
      if (strcasecmp(filename, entry->d_name) == 0) {
#ifdef _DEBUG
        fprintf(stderr, "ci_find_file: Looked for %s in rough %s, found diamond %s.\n", filename, directory, entry->d_name);
#endif _DEBUG
        diamond = (char *)malloc(strlen(directory) + strlen(entry->d_name) + 2);
        alw_append_filename(diamond, directory, entry->d_name, strlen(directory) + strlen(entry->d_name) + 2);
        break;
      }
    }
  }
  closedir(rough);

  fchdir(dirfd(prevdir));
  closedir(prevdir);

  free(directory);
  free(filename);
  return diamond;
}

/* Case Insensitive fopen */
FILE *ci_fopen(const char *file_name, const char *mode)
{
  FILE *fd;
  
  char *tmp = ac_getcwd(0, -1);
  
  char *fullpath = ci_find_file(NULL, file_name);

  /* If I didn't find a file, this could be writing a new file,
      so use whatever file_name they passed */
  if (fullpath == NULL) {
    return fopen(file_name, mode);
  } else {
    fd = fopen(fullpath, mode);
    free(fullpath);
  }

  return fd;
}
#endif
