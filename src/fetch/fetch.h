#ifndef FETCH_H
#define FETCH_H

#include "../definitions.h"

#define CODEBASE_LOCATION_FILEPATH "C:/Users/gorga/CodeProjects/Orka/ressources/codebase_location.txt"

bool codebase_location_exists(void);

bool get_codebase_location(char **location);

#endif