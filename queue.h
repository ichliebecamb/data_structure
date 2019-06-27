#ifndef __QUEUE_H
#define __QUEUE_H

#include "cirlist.h"

typedef struct Queue
{
	int count;
	struct _Cir* head;
}queue,*pqueue;

void init_queue(pqueue que);

void destroy_queue(pqueue que);

void clear_queue(pqueue que);

int queue_length(pqueue que);

ElemType gethead_queue(pqueue que);

void push_queue(pqueue que, ElemType val);

void pop_queue(pqueue que);

#endif
