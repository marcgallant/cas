#define _GNU_SOURCE

#include <getopt.h>
#include <stddef.h>


#include "configschema.h"

int main(int argc, char *argv[]) {
    //TODO
    int opt;
    static struct option long_options[] = { 
        { "log-level", required_argument, NULL, 'l' },
        { "help",      no_argument,       NULL, 'h' },
        {"version",    no_argument,       NULL, 'v' },
    };
    int option_index = 0;

    while ((opt = getopt_long(argc, argv, "lh", long_options, &option_index)) != -1) {
        switch (opt) {
            case 0:
                break;
            case 'h':
                //TODO
                break;
            case 'l':
                //TODO
                break;
            case 'v':
                //TODO
                break;
            default:
                //TODO
                break;
        }
    } 

    load_schema();
        
    return 0;
}
