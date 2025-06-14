#include "cli.h"


void interpret_flag(const int num_args, const char flag, ... ){

    va_list arguments;

    va_start(arguments, num_args);

    switch(flag){
        case 'h':
            help();
            break;
        case 'B':
            set_codebase_location();
            break;
        default:
            printf(RED"ERROR : -%c is not a valid flag\n"RESET, flag);
            break;
    }
}

void parse_argvs(const int argc, const char *argv[]){

    for(int i = 0; i < argc; i++){

        char shouldBeDash = argv[i][0];

        if(shouldBeDash == '-'){

            for(int j = 1; j < strlen(argv[i]); j++){
                interpret_flag(0,argv[i][j]);
            }
        }
    }
}


