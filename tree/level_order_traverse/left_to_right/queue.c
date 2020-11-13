#include "common.h"
#include "queue.h"

/*
 * Create a circular queue to store any data.
 * This queue is agnostic of any data we store as the queue contrains array of
 * void pointers.
 *
 * return TRUE if successful, else return FALSE.
 */
boolean
init_queue (queue *q)
{
    boolean ret = TRUE;

    if (!q) {
        printf("\nError : Passed queue pointer is NULL. Can't initialize");
        ret = FALSE;
    } else {
        q->front = 0;
        q->rear = 0;
        for(unsigned long long i=0; i<QUEUE_SIZE; i++) {
            q->data[i] = NULL;
        }
    }
    return ret;
}

/*
 * Find out whether the queue is full or not.
 *
 * Return TRUE if the queue is full. Otherwise, return FALSE.
 */
boolean
is_queue_full (queue *q)
{
    /*
     * If the next element of rear is front, it means queue is saturated.
     */
    return (((q->rear + 1) % QUEUE_SIZE) == q->front) ? TRUE : FALSE;
}

/*
 * Enqueue data element in the queue.
 * It does not check what data you are putting in the queue.
 *
 * Return TRUE if successful, else return FALSE.
 */
boolean
enqueue (queue *q, void *data)
{
    boolean ret = TRUE;
    if (!q) {
        printf("\nError : Passed queue is NULL. Can't enqueue");
        ret = FALSE;
    }

    if (ret && !is_queue_full(q)) {
        q->data[q->rear] = data;
        q->rear = (q->rear + 1) % QUEUE_SIZE;
    } else {
        ret = FALSE;
    }

    return ret;
}

/*
 * Find out whether queue is empty or not.
 *
 * Return TRUE if queue is empty otherwise, return FALSE.
 */
boolean
is_queue_empty (queue *p)
{
    return (p->front == p->rear) ? TRUE : FALSE;
}

/*
 * Dequeue the element from queue.
 *
 * return TRUE if successful, else return FALSE.
 */
boolean
dequeue(queue *q, void **data)
{
    boolean ret = TRUE;
    if(!q) {
        printf("\nError: Passed queue is NULL.");
        ret = FALSE;
    }

    if (ret && !is_queue_empty(q)) {
        *data = q->data[q->front];
        q->front = (q->front + 1)%QUEUE_SIZE;
    } else {
        ret = FALSE;
    }

    return ret;
}
