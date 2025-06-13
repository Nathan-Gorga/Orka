#include "cli.h"



void print_handle(void){
    printf(
        "\n"
        "\n"
        "     OOOOOOOOO                       kkkkkkkk\n"
        "   OO:::::::::OO                     k::::::k\n"
        " OO:::::::::::::OO                   k::::::k\n"
        "O:::::::OOO:::::::O                  k::::::k\n"
        "O::::::O   O::::::Orrrrr   rrrrrrrrr  k:::::k    kkkkkkkaaaaaaaaaaaaa\n"
        "O:::::O     O:::::Or::::rrr:::::::::r k:::::k   k:::::k a::::::::::::a\n"
        "O:::::O     O:::::Or:::::::::::::::::rk:::::k  k:::::k  aaaaaaaaa:::::a\n"
        "O:::::O     O:::::Orr::::::rrrrr::::::rk:::::k k:::::k           a::::a\n"
        "O:::::O     O:::::O r:::::r     r:::::rk::::::k:::::k     aaaaaaa:::::a\n"
        "O:::::O     O:::::O r:::::r     rrrrrrrk:::::::::::k    aa::::::::::::a\n"
        "O:::::O     O:::::O r:::::r            k:::::::::::k   a::::aaaa::::::a\n"
        "O::::::O   O::::::O r:::::r           k::::::k:::::k  a::::a    a:::::a\n"
        "O:::::::OOO:::::::O r:::::r          k::::::k k:::::k a::::a    a:::::a\n"
        " OO:::::::::::::OO  r:::::r          k::::::k  k:::::ka:::::aaaa::::::a\n"
        "   OO:::::::::OO    r:::::r          k::::::k   k:::::ka::::::::::aa:::a\n"
        "     OOOOOOOOO      rrrrrrr          kkkkkkkk    kkkkkkkaaaaaaaaaa  aaaa\n"
        "\n"
        "\n");
}


void help(void){
    print_handle();
    printf("=== HELP PAGE ===\n\n");
    printf(" - h : help - prints this help page\n\n");
}