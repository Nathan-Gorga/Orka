#include "./definitions.h"
#include "./fetch/fetch.h"
#include "./cli/cli.h"
#include "./lang/lang.h"
#include "./nav/nav.h"

int main(const int argc, const char *argv[]) {

    const size_t bufferSize= 1024;
    char * codebase = (char *)malloc(bufferSize * sizeof(char));


    if(!get_codebase_location(&codebase)){
        printf(RED"TERMINATING ORKA\n"RESET);
        return 1;
    }

    start_nav(codebase);

    free(codebase);
    return 0;
}