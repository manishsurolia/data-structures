#include <stdio.h>
#include <stdlib.h>

void fun1(int *p)
{
    int q = 40;
    p = &q;
}

void fun2(int **p)
{
    int q = 40;
    *p = &q;
}

void fun3(int **p)
{
  static int q = 40;
  *p = &q;
}

void fun4(void)
{
    int val = 10; /* int size if 4 */
    int *ptr;     /* pointer size may vary based on platform '4 or 8' */
    int *p[10];   /* Array of pointers. means, "10 * size of a pointer" */
    int (*q)[10]; /* Pointer, which is pointing to an array of 10 integers */
    printf("4 : %ld\n",sizeof(val)); /* size of an interger val */
    printf("4 : %ld\n",sizeof(ptr)); /* size of a pointer */
    printf("4 : %ld\n",sizeof(p));   /* size of the array of pointers */
    printf("4 : %ld\n",sizeof(*q));  /* size of the array, pointed by q */
}

void fun5(void)                                                     
{                                                                                   
    int i;                                                                          
    int *ptr = (int *) malloc(5 * sizeof(int));                                     
                                                                                    
    for (int i = 0; i<5; i++) {                                                     
        *(ptr + i) = i;                                                             
    }                                                                               
                                                                                    
    printf("5 : %d\n", *ptr++); /* return the value at ptr and then increment */         
    printf("5 : %d\n", (*ptr)++); /* return value at ptr and then increment */           
    printf("5 : %d\n", *ptr); /* Just return the value at this address. */               
    printf("5 : %d\n",*++ptr); /* first increment, and then return the value. */         
    printf("5 : %d\n",++*ptr); /* first increment, and then return.Same as above */   
    return;                                                                       
}

int main()
{
  int data;
  int *ptr;

  /*
   * 1.
   */
  data = 27;
  ptr = &data;
  fun1(ptr);
  printf("1 : %d\n", *ptr);

  /*
   * 2.
   */
  data = 27;
  ptr = &data;
  fun2(&ptr);
  printf("2 : %d\n", *ptr);

  /*
   * 3.
   */
                                       
  data = 27;
  ptr = &data;
  fun3(&ptr);
  printf("3 : %d\n", *ptr);

  /*
   * 4.
   */
  fun4();

  /*
   * 5.
   */
  fun5();

  return 0;
}
