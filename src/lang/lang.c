#include "lang.h"

void addFolder(const char const* folderpath, const char const* foldername){

    size_t len = strlen(folderpath) + strlen(foldername) + 2;

    char * absolutePath = (char*)malloc(len * sizeof(char));

    if (!absolutePath) {
        perror("ERROR : failed to allocate memory");
        return;
    }

    snprintf(absolutePath, len, "%s\\%s", folderpath, foldername);


    if (CreateDirectory(absolutePath, NULL)) {
        printf(GREEN"lang folder %s created succesfully\n"RESET, absolutePath);
    } else if (GetLastError() == ERROR_ALREADY_EXISTS){
        printf(YELLOW"lang folder %s already exists\n"RESET, foldername);

    } else {
        printf(RED"ERROR : failed to create lang folder - Error code: %lu\n"RESET, GetLastError());
    }

    free(absolutePath);


} 