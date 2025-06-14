#ifndef NAV_H
#define NAV_H

#include "../definitions.h"


typedef struct folderContent{
    WIN32_FIND_DATA content;
    struct folderContent *next;
}folderContent;

void listFolderContents(const char const* folderpath);

void getFolderContents(const char const* folderpath, folderContent * head);

#endif