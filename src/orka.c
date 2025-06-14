#include "./definitions.h"
#include "./fetch/fetch.h"
#include "./cli/cli.h"


int main(const int argc, const char *argv[]) {

    const int bufferSize = 1024;
    char * buffer = (char *)malloc(bufferSize * sizeof(char));


    if(!get_codebase_location(&buffer)){
        printf(RED"TERMINATING ORKA\n"RESET);
        return 1;
    }
    printf("%s\n",buffer);



    free(buffer);
    return 0;
}