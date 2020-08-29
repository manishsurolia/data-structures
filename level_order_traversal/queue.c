#include <stdio.h>                                                               
#include <stdlib.h>                                                              
#include "queue.h"                                                               
                                                                                 
struct queue * create_queue(void)                                                
{                                                                                
    struct queue * p = NULL;                                                     
    p = (struct queue *) malloc (sizeof(struct queue *));                        
    if(!p) {                                                                     
        printf("\nError: Memory allocation failed.");                            
    } else {                                                                     
        p->front = 0;                                                            
        p->rear = 0;                                                             
    }                                                                            
    return p;                                                                    
}                                                                                
void enqueue(struct queue * p, void * data)                                      
{                                                                                
    if(!p) {                                                                     
        printf("\nError : Passed queue is NULL.");                               
    } else {                                                                     
        if(((p->rear + 1) % QUEUE_SIZE) == p->front) {                           
            printf("\nError : queue saturated. Can't add anymore data");         
            return;                                                              
        }                                                                        
        p->array[p->rear] = data;                                                
        p->rear = (p->rear + 1) % QUEUE_SIZE;                                    
    }                                                                            
}

void * dequeue(struct queue *p)                                                  
{                                                                                
    void * temp = NULL;                                                          
    if(!p) {                                                                     
        printf("\nError: Passed queue is NULL.");                                
    } else {                                                                     
        if(p->front == p->rear) {                                                
            return NULL;                                                         
        }                                                                        
        temp = p->array[p->front];                                               
        p->front = (p->front + 1)%QUEUE_SIZE;                                    
    }                                                                            
    return temp;                                                                 
}                                                                                
                                                                                 
uchar is_queue_empty(struct queue *p)                                            
{                                                                                
    return (p->front == p->rear) ? TRUE : FALSE;                                 
}
