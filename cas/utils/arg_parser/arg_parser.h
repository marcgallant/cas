#ifndef ARG_PARSER_H
#define ARG_PARSER_H

#include <dlist/dlist.h>

struct argument {
    char *name;
    char c;
//    int (*action)(char *args[]);
    char **choices;
};

struct arg_parser {
    char *description;
    struct dlist *arguments;
    struct arg_parser *subparser;
};

struct arg_parser *arg_parser_init(char *description);

void add_argument(struct arg_parser *parser, char *name, char c, 
//int (*action)(char *args[]),
 char **choices);

struct arg_parser *add_subparsers(struct arg_parser *parser, char *description);

void usage(struct arg_parser *parser);

int parse(struct arg_parser *parser, int argc, char *argv[]);

void arg_parser_destroy(struct arg_parser *parser);

#endif /* ! ARG_PARSER_H */
