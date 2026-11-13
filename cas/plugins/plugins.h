#ifndef PLUGINS_H
#define PLUGINS_H

#include <hash_map/hash_map.h>

struct plugin {
    char *name;
    char *helpmsg;
    int (*run)(char *args[]);
};

struct hash_map *plugins;

int load(void);

#endif /* ! PLUGIN_H */
