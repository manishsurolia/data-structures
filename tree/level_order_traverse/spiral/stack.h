#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 128                                                           
#define TRUE 1                                                                   
#define FALSE 0                                                                  
                                                                                 
typedef long long longlong;                                                      
typedef unsigned char uchar;                                                     
                                                                                 
struct stack                                                                     
{                                                                                
    longlong top;                                                                
    void * array[STACK_SIZE];                                                    
}; 

struct stack * create_stack();
void push(struct stack *p, void *data);
void * pop(struct stack *p);
uchar is_stack_full(struct stack *p);
uchar is_stack_empty(struct stack *p);
