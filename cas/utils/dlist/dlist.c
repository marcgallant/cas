#include <stdlib.h>

#include "dlist.h"

struct dlist_item
{
    struct dlist_item *next;
    struct dlist_item *prev;
    void *data;
};

struct dlist
{
    size_t size;
    struct dlist_item *head;
    struct dlist_item *tail;
};

struct dlist *dlist_init(void)
{
    struct dlist *res = calloc(1, sizeof(struct dlist));
    return res;
}

int dlist_push_front(struct dlist *list, void *element)
{
    if (!element)
        return 0;

    struct dlist_item *tmp = calloc(1, sizeof(struct dlist_item));
    tmp->data = element;
    tmp->next = list->head;

    if (list->size == 0)
    {
        list->tail = tmp;
    }
    else
    {
        list->head->prev = tmp;
    }

    list->head = tmp;
    list->size++;
    return 1;
}

int dlist_push_back(struct dlist *list, void *element)
{
    if (!element)
        return 0;

    struct dlist_item *tmp = calloc(1, sizeof(struct dlist_item));
    tmp->data = element;
    tmp->prev = list->tail;

    if (list->size == 0)
    {
        list->head = tmp;
    }
    else
    {
        list->tail->next = tmp;
    }

    list->tail = tmp;
    list->size++;
    return 1;
}

size_t dlist_size(const struct dlist *list)
{
    return list->size;
}

void dlist_destroy(struct dlist *list)
{
    while (list->head)
    {
        struct dlist_item *tmp = list->head;
        list->head = list->head->next;
        free(tmp->data);
        free(tmp);
    }
    free(list);
}
