#include "fetch.h"

#define CODEBASE_LOCATION_FILEPATH "C:/Users/gorga/CodeProjects/Orka/ressources/codebase_location.txt"

#ifdef _WIN32

#define FILE_EXISTS_FUNC(filepath) GetFileAttributes(filepath)

#else

#define FILE_EXISTS_FUNC(filepath) access(filepath, F_OK)

#endif

bool file_exists(void){

    #ifdef _WIN32

    DWORD file_attributes = FILE_EXISTS_FUNC(CODEBASE_LOCATION_FILEPATH);

    if(file_attributes == INVALID_FILE_ATTRIBUTES) return false;

    #else

    if(FILE_EXISTS_FUNC(CODEBASE_LOCATION_FILEPATH) == 0) return false;

    #endif

    return true;
}


