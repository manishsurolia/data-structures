#include <stdio.h>                                                               
#include <stdlib.h>                                                              
#include "queue.h"                                                               
                                                                                 
struct tree                                                                      
{                                                                                
    struct tree * left;                                                          
    struct tree * right;                                                         
    int data;                                                                    
};                                                                               
                                                                                 
/*                                                                               
 * add_node : add a new node in tree by comparing data. Lesser value data goes   
 * in left, and bigger value data goes to right of the tree.                     
 */                                                                              
struct tree * add_node(struct tree *p, int data)                                 
{                                                                                
    if(p == NULL) {                                                              
        p = (struct tree *) malloc (sizeof(struct tree));                        
        p->data = data;                                                          
        p->left = NULL;                                                          
        p->right = NULL;                                                         
    } else if(data < p->data) {                                                  
        p->left = add_node(p->left, data);                                       
    } else {                                                                     
        p->right = add_node(p->right, data);                                     
    }                                                                            
    return p;                                                                    
} 

/*                                                                               
 * print_level_by_level : prints data of a tree level by level(from left to      
 * right). It uses queue data structure, which has been implemented in other     
 * file queue.c.                                                                 
 *                                                                               
 * I have tried to keep queue code implementation more generic and               
 * abstract from this tree implementation.                                       
 *                                                                               
 * All queue declarations are present in queue.h and definitions are present in  
 * queue.c file                                                                  
 */                                                                              
                                                                                 
void print_level_by_level(struct tree *p)                                        
{                                                                                
    struct queue * q = create_queue();                                           
                                                                                 
    if(!p) {                                                                     
        printf("Error: Passed queue is NULL");                                   
    } else {                                                                     
        while(1) {                                                               
            if(p !=NULL) {                                                       
                printf("%d ",p->data);                                           
                if(p->left) {                                                    
                    enqueue(q, p->left);                                         
                }                                                                
                                                                                 
                if(p->right) {                                                   
                    enqueue(q, p->right);                                        
                }                                                                
            }                                                                    
            if(!is_queue_empty(q)) {                                             
                p = (struct tree *) dequeue(q);                                  
            } else {                                                             
                break;                                                           
            }                                                                    
        }                                                                        
    }                                                                            
    printf("\n");                                                                
    return;
}

int main()                                                                       
{                                                                                
    struct tree * first = NULL;                                                  
    first = add_node(first, 40);                                                 
    first = add_node(first, 45);                                                 
    first = add_node(first, 35);                                                 
    first = add_node(first, 20);                                                 
    first = add_node(first, 90);                                                 
    first = add_node(first, 10);                                                 
    first = add_node(first, 95);                                                 
    first = add_node(first, 5);                                                  
    first = add_node(first, 7);                                                  
    first = add_node(first, 88);                                                 
                                                                                 
    print_level_by_level(first);                                                 
                                                                                 
    return 0;                                                                    
}
