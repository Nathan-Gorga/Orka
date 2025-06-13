#include "./definitions.h"
#include "./fetch/fetch.h"

int main(const int argc, const char *argv[]) {

    char *codebase_location;
    if(!get_codebase_location(&codebase_location) != 0){
        fprintf(stderr,"Terminating ORKA\n");
        return 1;
    }
    printf(codebase_location);
    return 0;
}