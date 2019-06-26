#ifndef __STACK_H
#define __STACK_H

#include "seqlist.h"
typedef struct stack
{
	pSeqList data;
}stack,*pstack;

void init_stack(pstack sta);

void destroy_stack(pstack sta);

void clear_stack(pstack sta);

int isempty_stack(pstack sta);

int length_stack(pstack sta);

ElemType stack_top(pstack sta);

void push_stack(pstack sta, ElemType val);

void pop_stack(pstack sta);
#endif
