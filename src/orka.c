#include "./definitions.h"
#include "./fetch/fetch.h"

int main(const int argc, const char *argv[]) {

    bool codebase_filelocation_exists = file_exists();

    if(!codebase_filelocation_exists) fprintf(stderr, "ERROR: codebase location does not exist\n");
    else printf("Codebase location exists\n");

    return 0;
}