#define _GNU_SOURCE

#include <getopt.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

#include "configschema.h"

#include <arg_parser/arg_parser.h>

typedef enum {
    LOG_DEBUG = 0,
    LOG_INFO,
    LOG_WARNING,
    LOG_ERROR,
    LOG_CRITICAL
} log_level_t;

log_level_t log_level = LOG_INFO;

float version = 5.5;

void print_version() {
    printf("kas %.1f (configuration format version %d, earliest compatible version %d)\n",
        version,
        file_version,
        compatible_file_version);
}

void print_usage() {}

int main(int argc, char *argv[]) {
    //TODO
    /*int opt;
    static struct option long_options[] = { 
        { "log-level", required_argument, NULL, 'l' },
        { "help",      no_argument,       NULL, 'h' },
        {"version",    no_argument,       NULL, 'v' },
    };
    int ret = 0;
    opterr = 0;

    if (!load_schema())
        return 1;

    while ((opt = getopt_long(argc, argv, "l:h", long_options, NULL)) != -1) {
        switch (opt) {
            case 0:
                break;
            case 'l':
                int found = 0;
                char *choices[5] = { "debug", "info", "warning", "error", "critical" };
                for (size_t i = 0; i < sizeof(choices) / sizeof(char *) ; i++) {
                    if (strcmp(optarg, choices[i]) == 0) {
                        log_level = (log_level_t) i;
                        found = 1;
                        break;
                    }
                }

                if (found) {
                    print_usage();
                    break;
                }

                print_usage();
                printf("kas: error: argument -l/--log-level: invalid choice: '%s' (choose from ", optarg);
                for (size_t i = 0; i < sizeof(choices) / sizeof(char *) - 1; i++)
                    printf("%s, ", choices[i]);
                printf("%s)\n", choices[sizeof(choices) /sizeof(char *) - 1]);

                return 2;
            case 'h':
                //TODO
                break;
            case 'v':
                print_version();
                break;
            case '?':
            default:
                //TODO
                print_usage();
                if (optopt)
                    printf("kas: error: unrecognized arguments: -%c\n", optopt);
                else
                    printf("kas: error: unrecognized arguments: %s\n", argv[optind - 1]);
                return 2;
        }
    }*/

    struct arg_parser *parser = arg_parser_init("kas - setup tool for bitbake based project");
    add_argument(parser, "help", 'h', NULL); 
    add_argument(parser, "version", 0, NULL); 
    
    char *choices[] = { "debug", "info", "warning", "error", "critical", NULL };
    add_argument(parser, "log-level", 0,  choices); 
    
    usage(parser);
    parse(parser, argc, argv);

    arg_parser_destroy(parser);
        
    return 0;
}
