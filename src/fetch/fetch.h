#ifndef FETCH_H
#define FETCH_H

#include "../definitions.h"

#define CODEBASE_LOCATION_FILEPATH "C:/Users/gorga/CodeProjects/Orka/ressources/codebase_location.txt"


enum EXCEPTIONS {
    FILE_DOES_NOT_EXIST = 1,
    FILE_DOES_NOT_CONTAIN_CODEBASE_LOCATION,
    CODEBASE_LOCATION_INVALID,
    UNRESOVED_EXCEPTION
};


bool codebase_location_exists(void);

bool get_codebase_location(char **location);


#endif