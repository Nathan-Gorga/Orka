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


enum EXCEPTIONS _get_codebase_location(char **location){

    if(!codebase_location_exists()){

        
        return FILE_DOES_NOT_EXIST;
    }

    FILE *codebase_location_file = fopen(CODEBASE_LOCATION_FILEPATH, "r");

    if(codebase_location_file == NULL){
        fprintf(stderr, "ERROR : unable to open file %s\n", CODEBASE_LOCATION_FILEPATH);
        return UNRESOVED_EXCEPTION;
    }

    #define BUFFER_SIZE 1024

    char buffer[BUFFER_SIZE];

    if(fgets(buffer, BUFFER_SIZE, codebase_location_file) == NULL){
        return FILE_DOES_NOT_CONTAIN_CODEBASE_LOCATION;
    }

    fclose(codebase_location_file);

    strcpy(*location,buffer);

    return 0;
}


bool get_codebase_location(char **location){

    enum EXCEPTIONS ret = _get_codebase_location(location);
    switch(ret){
        case 0: return true;
        case FILE_DOES_NOT_EXIST: 
            fprintf(stderr,"ERROR: file containing codebase location does not exist | expecting '%s'\n", CODEBASE_LOCATION_FILEPATH);
            return false;
        case FILE_DOES_NOT_CONTAIN_CODEBASE_LOCATION: 
            fprintf(stderr, "ERROR : file %s does not contain codebase location\n", CODEBASE_LOCATION_FILEPATH);
            return false;

        case CODEBASE_LOCATION_INVALID:
        case UNRESOVED_EXCEPTION:
        default:
            fprintf(stderr, "ERROR : unresolved exception\n");
            return false;
    }
}
