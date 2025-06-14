#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>
#include <assert.h>
#include <stdarg.h>


    #ifdef _WIN32

    #include <windows.h>
    #include <io.h>

    #else

    #include <unistd.h>

    #endif


//TEXT COLORS
#define RESET "\033[0m"
#define RED "\033[31m"
#define BLACK "\033[30m"
#define GREEN "\033[32m"      
#define YELLOW "\033[33m"      
#define BLUE "\033[34m"      
#define MAGENTA "\033[35m"      
#define CYAN "\033[36m"      
#define WHITE "\033[37m"

#endif