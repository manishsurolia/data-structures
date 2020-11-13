/*
 * queue.h : queue specific declarations.
 */

#ifndef __QUEUE_H__
#define __QUEUE_H__

#include "common.h"
#define QUEUE_SIZE 128

typedef struct queue
{
    ulonglong front;
    ulonglong rear;
    void * data[QUEUE_SIZE];
} queue;

extern boolean
init_queue (queue *q);

extern boolean
enqueue(queue * p, void *data);

extern boolean
dequeue(queue *p, void **data);

extern uchar
is_queue_empty(struct queue *p);

#endif /* __QUEUE_H__ */
