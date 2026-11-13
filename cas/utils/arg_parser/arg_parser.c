#include "arg_parser.h"

#include <stdlib.h>
#include <stdio.h>

struct arg_parser *arg_parser_init(char *description) {
    struct arg_parser *parser = calloc(1, sizeof(struct arg_parser));
    parser->description = description;

    parser->arguments = dlist_init();

    return parser;
}

void add_argument(struct arg_parser *parser, char *name, char c, //int (*action)(char *args[]), 
char **choices) {
    struct argument *argument = calloc(1, sizeof(struct argument));
    argument->name = name;
    if (c) argument->c = c;
    //argument->action = action;
    if (choices) argument->choices = choices;

    dlist_push_back(parser->arguments, argument);
}

struct arg_parser *add_subparsers(struct arg_parser *parser, char *description) {
    struct arg_parser *subparser = calloc(1, sizeof(struct arg_parser));
    subparser->description = description;
    
    parser->subparser = subparser;

    return subparser;
}

void usage(struct arg_parser *parser) {
    //TODO: implement
    printf("%s\n", parser->description);
}

int parse(struct arg_parser *parser, int argc, char *argv[]) {
    //TODO: implement
    (void)parser;
    (void)argc;
    (void)argv; 

    return 0;
}

void arg_parser_destroy(struct arg_parser *parser) {
    if (!parser) return;

    dlist_destroy(parser->arguments);
    arg_parser_destroy(parser->subparser);

    free(parser);
}
