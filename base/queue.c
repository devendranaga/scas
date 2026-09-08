#include <stdint.h>

#include "queue.h"

scas_queue_impl_t *scas_queue_init()
{
    scas_queue_impl_t *impl;

    impl = calloc(1, sizeof(scas_queue_impl_t));
    if (!impl) {
        return NULL;
    }

    impl->head = NULL;
    impl->tail = NULL;
    impl->length = 0;

    return impl;
}

void scas_queue_push(scas_queue_impl_t *impl, void *item)
{
    scas_queue_t *node;

    node = calloc(1, sizeof(scas_queue_t));
    if (!node) {
        return;
    }

    node->item = item;
    node->next = NULL;

    if (!impl->head) {
        impl->head = node;
        impl->tail = node;
    } else {
        impl->tail->next = node;
        impl->tail = node;
    }

    impl->length ++;
}

void *scas_queue_pop(scas_queue_impl_t *impl)
{
    scas_queue_t *node;
    void *item;

    node = impl->head;
    if (!node) {
        return NULL;
    }

    item = node->item;
    impl->head = impl->head->next;
    free(node);

    impl->length --;

    return item;
}
