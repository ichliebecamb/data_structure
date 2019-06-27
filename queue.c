#include "queue.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void init_queue(pqueue que)
{
	assert( que != NULL);
	if( que == 0) return ;

	que->count = 0;
	que->head = (CirList)malloc( sizeof(CNode));
	init_cir(que->head);
}

void destroy_queue(pqueue que)
{
	assert( que != NULL);
	if( que == 0) return ;

	que->count = 0;
	clear_cir(que->head);
	que->head = NULL;
}

void clear_queue(pqueue que)
{
	assert( que != NULL);
	if( que == 0) return ;

	que->count = 0;
	clear_cir(que->head);
}

int queue_length(pqueue que)
{
	assert( que != NULL);
	if( que == 0) return ;
	return que->count;
}


ElemType gethead_queue(pqueue que)
{
	ElemType out;
	assert( que != NULL);
	if( que == NULL) return out;

	return find_cir_pos( que->head, 0);
}

void push_queue(pqueue que, ElemType val)
{
	assert( que != NULL);
	if( que == NULL) return ;

	insert_cir_tail(que->head, val);
	que->count++;
}

void pop_queue(pqueue que)
{
	assert( que != NULL);
	if( que == NULL) return ;

	delete_cir_head(que->head);
	que->count--;
}


