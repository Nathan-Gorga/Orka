#include "cli.h"



void interpret_flag(char flag){
    switch(flag){
        case 'h':
            help();
            break;
        default:
            printf(RED"ERROR : %c is not a valid flag\n"RESET, flag);
            break;
    }
}

void parse_argvs(const int argc, const char *argv[]){

    for(int i = 0; i < argc; i++){

        char shouldBeDash = argv[i][0];

        if(shouldBeDash == '-'){

            for(int j = 1; j < strlen(argv[i]); j++){
                interpret_flag(argv[i][j]);
            }
        }
    }
}


