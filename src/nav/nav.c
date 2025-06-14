#include "nav.h"

void listFolderContents(const char const* folderpath){
    WIN32_FIND_DATA findFileData;
    HANDLE hFind;

    // Build search pattern like: "C:\\path\\to\\folder\\*"
    char searchPath[MAX_PATH];
    snprintf(searchPath, MAX_PATH, "%s\\*", folderpath);

    hFind = FindFirstFile(searchPath, &findFileData);

    if (hFind == INVALID_HANDLE_VALUE) {
        printf("No files found in %s\n", folderpath);
        return;
    }

    do {
        const char *name = findFileData.cFileName;

        // Skip "." and ".."
        if (strcmp(name, ".") != 0 && strcmp(name, "..") != 0) {
            if (findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
                printf("[DIR]  %s\n", name);
            } else {
                printf("       %s\n", name);
            }
        }
    } while (FindNextFile(hFind, &findFileData));

    FindClose(hFind);
}



void start_nav(const char const* codebase_location){
    
}