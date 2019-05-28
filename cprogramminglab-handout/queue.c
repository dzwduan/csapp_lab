/* 
 * Code for basic C skills diagnostic.
 * Developed for courses 15-213/18-213/15-513 by R. E. Bryant, 2017
 * Modified to store strings, 2018
 */

/*
 * This program implements a queue supporting both FIFO and LIFO
 * operations.
 *
 * It uses a singly-linked list to represent the set of queue elements
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "harness.h"
#include "queue.h"

/*
  Create empty queue.
  Return NULL if could not allocate space.
*/
queue_t *q_new()
{
    queue_t *q =  malloc(sizeof(queue_t));
    /* What if malloc returned NULL? */

    if(q==NULL){
      fprintf(stderr,"allocation failed\n");
      abort();  //中止程序执行，直接从调用的地方跳出。
    }
    q->head = NULL;
    q->tail = NULL;
    q->size = 0;
    return q;
}

/* Free all storage used by queue */
void q_free(queue_t *q)
{
    /* How about freeing the list elements and the strings? */
    /* Free queue structure */
    list_ele_t * point = q->head;
    while(point != q->tail){
      free(point->value);
      point =  point->next;
    }
    free(q->tail->value);
    free(q);
}

/*
  Attempt to insert element at head of queue.
  Return true if successful.
  Return false if q is NULL or could not allocate space.
  Argument s points to the string to be stored.
  The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_head(queue_t *q, char *s)
{   
    if(q == NULL){
      return false;
    }

    list_ele_t *newh;
    /* What should you do if the q is NULL? */
    newh = malloc(sizeof(list_ele_t));
    /* Don't forget to allocate space for the string and copy it */
    /* What if either call to malloc returns NULL? */
    
    if(newh == NULL){
      fprintf(stderr,"allocation failed\n");
      return false;
    }
    newh ->value = s;
    newh->next = q->head;
    q->head = newh;
    return true;
}



list_ele_t* get_tail(queue_t *q){
  list_ele_t *last = q->head;
  while(last->next){
    last = last->next;
  }
  return last;
}


/*
  Attempt to insert element at tail of queue.
  Return true if successful.
  Return false if q is NULL or could not allocate space.
  Argument s points to the string to be stored.
  The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_tail(queue_t *q, char *s)
{
    if(q == NULL){
      return false;
    }

    /* Remember: It should operate in O(1) time */
    list_ele_t *newh = malloc(sizeof(list_ele_t));
    if(newh == NULL){
      fprintf(stderr,"allocation failed\n");
      return false;
    }

    newh->value = s;
    list_ele_t *tail = get_tail(q);
    tail->next = newh;
    tail = newh;
    return ;
}

/*
  Attempt to remove element from head of queue.
  Return true if successful.
  Return false if queue is NULL or empty.
  If sp is non-NULL and an element is removed, copy the removed string to *sp
  (up to a maximum of bufsize-1 characters, plus a null terminator.)
  The space used by the list element and the string should be freed.
*/
bool q_remove_head(queue_t *q, char *sp, size_t bufsize)
{
    /* You need to fix up this code. */
    if(q == NULL)
      return false;

    list_ele_t *first = q->head;
    q->head = first->next;
    first->next = NULL;
    for(int i=0;first->value[i];++i){
      sp[i] = first->value[i];
    }
    free(first);
    return true;
}

/*
  Return number of elements in queue.
  Return 0 if q is NULL or empty
 */
int q_size(queue_t *q)
{
    /* You need to write the code for this function */
    /* Remember: It should operate in O(1) time */
    if (q==NULL)
      return 0;
    return q->size;
}

/*
  Reverse elements in queue
  No effect if q is NULL or empty
  This function should not allocate or free any list elements
  (e.g., by calling q_insert_head, q_insert_tail, or q_remove_head).
  It should rearrange the existing ones.
 */
void q_reverse(queue_t *q)
{
    /* You need to write the code for this function */
    if (q==NULL || q->head->next==NULL)
      return q;
    list_ele_t * p = q->tail;
    p->next = q->head;

}

