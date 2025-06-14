#include "cli.h"



void print_handle(void){
    printf(
        "\n"
        "\n"
        GREEN"     OOOOOOOOO     "RED"                    "CYAN"kkkkkkkk\n"
        GREEN"   OO:::::::::OO   "RED"                    "CYAN"k::::::k\n"
        GREEN" OO:::::::::::::OO "RED"                    "CYAN"k::::::k\n"
        GREEN"O:::::::OOO:::::::O"RED"                    "CYAN"k::::::k\n"
        GREEN"O::::::O   O::::::O"RED" rrrrr   rrrrrrrrr   "CYAN"k:::::k    kkkkkkk "YELLOW"aaaaaaaaaaaaa\n"
        GREEN"O:::::O     O:::::O"RED" r::::rrr:::::::::r  "CYAN"k:::::k   k:::::k  "YELLOW"a::::::::::::a\n"
        GREEN"O:::::O     O:::::O"RED" r:::::::::::::::::r "CYAN"k:::::k  k:::::k   "YELLOW"aaaaaaaaa:::::a\n"
        GREEN"O:::::O     O:::::O"RED" rr::::::rrrrr::::::r "CYAN"k:::::k k:::::k           "YELLOW" a::::a\n"
        GREEN"O:::::O     O:::::O"RED"  r:::::r     r:::::r "CYAN"k::::::k:::::k      "YELLOW"aaaaaaa:::::a\n"
        GREEN"O:::::O     O:::::O"RED"  r:::::r     rrrrrrr "CYAN"k:::::::::::k     "YELLOW"aa::::::::::::a\n"
        GREEN"O:::::O     O:::::O"RED"  r:::::r             "CYAN"k:::::::::::k    "YELLOW"a::::aaaa::::::a\n"
        GREEN"O::::::O   O::::::O"RED"  r:::::r            "CYAN"k::::::k:::::k   "YELLOW"a::::a    a:::::a\n"
        GREEN"O:::::::OOO:::::::O"RED"  r:::::r           "CYAN"k::::::k k:::::k  "YELLOW"a::::a    a:::::a\n"
        GREEN" OO:::::::::::::OO "RED"  r:::::r           "CYAN"k::::::k  k:::::k "YELLOW"a:::::aaaa::::::a\n"
        GREEN"   OO:::::::::OO   "RED"  r:::::r           "CYAN"k::::::k   k:::::k "YELLOW"a::::::::::aa:::a\n"
        GREEN"     OOOOOOOOO     "RED"  rrrrrrr           "CYAN"kkkkkkkk    kkkkkkk "YELLOW"aaaaaaaaaa  aaaa\n"
        "\n"RESET);
}


void help(void){
    print_handle();
    printf("-- HELP PAGE --\n\n");
    printf(" -h : help - prints this help page\n\n");
    printf(" -B : modify codebase location - specify the path to your codebase, or leave empty to be prompted for it\n\n");
}


void modify_codebase_location(void){
    
}