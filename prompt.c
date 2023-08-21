#include "headers.h"



void display_req()
{
    printf("<");
    // display_req();
    char* username=getenv("USER");
    char hostname[256];
    gethostname(hostname,sizeof(hostname));
    printf("%s@",username);
    printf("%s:",hostname);
    // printf(":~>\n");
}


void prompt() {
    // Do not hardcode the prmopt
        display_req();

    // printf("<Everything is a file> ");    
}
