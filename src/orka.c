#include "./definitions.h"
#include "./fetch/fetch.h"

int main(const int argc, const char *argv[]) {

    char toSet[] = "test.cb";
    set_codebase_location(toSet);

    char *codebase_location;
    if(!get_codebase_location(&codebase_location) != 0){
        fprintf(stderr,RED"Terminating ORKA\n"RESET);
        return 1;
    }
    printf(codebase_location);
    return 0;
}