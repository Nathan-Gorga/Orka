#ifndef FETCH_H
#define FETCH_H

#include "../definitions.h"

#define CODEBASE_LOCATION_FILEPATH_NAME "codebase_location.txt"
#define CODEBASE_LOCATION_FILEPATH "C:/Users/gorga/CodeProjects/Orka/ressources/" CODEBASE_LOCATION_FILEPATH_NAME


enum EXCEPTIONS {
    FILE_DOES_NOT_EXIST = 1,
    FILE_DOES_NOT_CONTAIN_CODEBASE_LOCATION,
    CODEBASE_LOCATION_INVALID,
    UNRESOVED_EXCEPTION
};


bool file_exists(const char * filepath);

bool get_codebase_location(char **location);

enum EXCEPTIONS set_codebase_location(const char *location);


#endif