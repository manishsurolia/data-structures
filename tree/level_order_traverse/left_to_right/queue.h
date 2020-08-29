#include <stdio.h>                                                               
#include <stdlib.h>                                                              
                                                                                 
typedef unsigned long ulonglong;                                                 
typedef unsigned char uchar;                                                     
#define QUEUE_SIZE 128                                                           
#define TRUE 1                                                                   
#define FALSE 0                                                                  
                                                                                 
struct queue                                                                     
{                                                                                
    ulonglong front;                                                             
    ulonglong rear;                                                              
    void * array[QUEUE_SIZE];                                                    
};                                                                               
struct queue * create_queue(void);                                               
void enqueue(struct queue * p, void * data);                                     
void * dequeue(struct queue *p);                                                 
uchar is_queue_empty(struct queue *p);
