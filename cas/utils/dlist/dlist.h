#ifndef DLIST_H
#define DLIST_H

#include <stddef.h>

struct dlist;

struct dlist *dlist_init(void);

int dlist_push_front(struct dlist *list, void *element);

int dlist_push_back(struct dlist *list, void *element);

size_t dlist_size(const struct dlist *list);

void dlist_destroy(struct dlist *list);

#endif // DLIST_H
