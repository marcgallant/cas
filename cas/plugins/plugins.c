#include "plugins.h"

#include "clean.h"


int load() {
    plugins = hash_map_init(20);

    struct plugin clean = { "clean", "Clean build artifacts, keep sstate cache and downloads.", run_clean};
    hash_map_insert(plugins, clean.name, &clean, NULL);
    return 1;
}
