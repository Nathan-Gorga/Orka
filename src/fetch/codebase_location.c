#include "fetch.h"

#ifdef _WIN32

#define FILE_EXISTS_FUNC(filepath) GetFileAttributes(filepath)

#else

#define FILE_EXISTS_FUNC(filepath) access(filepath, F_OK)

#endif

bool codebase_location_exists(void){

    #ifdef _WIN32

    DWORD file_attributes = FILE_EXISTS_FUNC(CODEBASE_LOCATION_FILEPATH);

    if(file_attributes == INVALID_FILE_ATTRIBUTES) return false;

    #else

    if(FILE_EXISTS_FUNC(CODEBASE_LOCATION_FILEPATH) == 0) return false;

    #endif

    return true;
}


bool get_codebase_location(char **location){

    if(!codebase_location_exists()){

        fprintf(stderr,"ERROR: file containing codebase location does not exist | expecting '%s'\n", CODEBASE_LOCATION_FILEPATH);
        return false;
    }

    FILE *codebase_location_file = fopen(CODEBASE_LOCATION_FILEPATH, "r");

    if(codebase_location_file == NULL){
        fprintf(stderr, "ERROR : unable to open file %s\n", CODEBASE_LOCATION_FILEPATH);
        return false;
    }

    #define BUFFER_SIZE 1024

    char buffer[BUFFER_SIZE];

    if(fgets(buffer, BUFFER_SIZE, codebase_location_file) == NULL){
        fprintf(stderr, "ERROR : unable to read file %s\n", CODEBASE_LOCATION_FILEPATH);
        return false;
    }

    fclose(codebase_location_file);

    strcpy(*location,buffer);

    return true;
}