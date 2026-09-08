#ifndef SCAS_QUEUE_H
#define SCAS_QUEUE_H

#include <stdlib.h>

/**
 * @brief - Defines a queue.
 */
typedef struct scas_queue {
    void                *item;
    struct scas_queue  *next;
} scas_queue_t;

/**
 * @brief - Defines queue implementation.
 */
typedef struct scas_queue_impl {
    scas_queue_t   *head;
    scas_queue_t   *tail;
    uint32_t        length;
} scas_queue_impl_t;

scas_queue_impl_t *scas_queue_init();

void scas_queue_push(scas_queue_impl_t *impl, void *item);

void *scas_queue_pop(scas_queue_impl_t *impl);

#endif
