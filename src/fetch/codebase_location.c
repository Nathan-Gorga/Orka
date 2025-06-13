#include "fetch.h"

#ifdef _WIN32

#define FILE_EXISTS_FUNC(filepath) GetFileAttributes(filepath)

#else

#define FILE_EXISTS_FUNC(filepath) access(filepath, F_OK)

#endif

bool file_exists(const char * filepath){

    #ifdef _WIN32

    DWORD file_attributes = FILE_EXISTS_FUNC(filepath);

    if(file_attributes == INVALID_FILE_ATTRIBUTES) return false;

    #else

    if(FILE_EXISTS_FUNC(filepath) == 0) return false;

    #endif

    return true;
}


enum EXCEPTIONS _get_codebase_location(char **location){

    if(!file_exists(CODEBASE_LOCATION_FILEPATH)){

        
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

        case FILE_DOES_NOT_EXIST://TODO : provide a fallback function 
            fprintf(stderr,"ERROR: file containing codebase location does not exist | expecting '%s'\n", CODEBASE_LOCATION_FILEPATH);
            return false;
        
            case FILE_DOES_NOT_CONTAIN_CODEBASE_LOCATION: //TODO : provide a fallback function
            fprintf(stderr, "ERROR : file %s does not contain codebase location\n", CODEBASE_LOCATION_FILEPATH);
            return false;

        case CODEBASE_LOCATION_INVALID: //TODO : provide a fallback function
        
        case UNRESOVED_EXCEPTION: //TODO : provide a fallback function
        
        default:
            return false;
    }
}


enum EXCEPTIONS set_codebase_location(const char *location){
    
    if(!file_exists(location)){
        fprintf(stderr, "ERROR : %s does not exist\n", location);
        return CODEBASE_LOCATION_INVALID;
    }

    FILE *codebase_location_file = fopen(CODEBASE_LOCATION_FILEPATH, "w");

    if(codebase_location_file == NULL){
        fprintf(stderr, "ERROR : unable to create file %s\n", CODEBASE_LOCATION_FILEPATH_NAME);
        return UNRESOVED_EXCEPTION;
    }


    printf("successfully set codebase location to %s\n", location);
    fprintf(codebase_location_file  , "%s", location);

    return 0;
}

