#include "stack.h"
#include <malloc.h>
#include <assert.h>

void init_stack(pstack sta)
{
	assert(sta != NULL);
	if( sta == NULL ) return;
	sta->data = (pSeqList)malloc(sizeof(SeqList));
	assert( sta->data != NULL);
	init_seq(sta->data);
}

void destroy_stack(pstack sta)
{
	assert(sta != NULL);
	if( sta == NULL ) return;
	destroy_seq(sta->data);
	free(sta->data);
}

void clear_stack(pstack sta)
{	
	assert(sta != NULL);
	if( sta == NULL || sta->data == NULL ) return;
	clear_seq( sta->data);
}

int isempty_stack(pstack sta)
{
	assert(sta != NULL);
	if( sta == NULL || sta->data == NULL ) return -1;
	if( count_seq(sta->data ) == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int length_stack(pstack sta)
{
	assert(sta != NULL);
	if( sta == NULL || sta->data == NULL ) return -1;
	return count_seq(sta->data );


}

ElemType stack_top(pstack sta)
{
	assert(sta != NULL);
	if( sta == NULL || sta->data == NULL ) return -1;
	return find_seq_pos(sta->data, count_seq(sta->data) - 1);
}

void push_stack(pstack sta, ElemType val)
{
	assert(sta != NULL);
	if( sta == NULL || sta->data == NULL ) return;
	insert_seq_tail(sta->data, val);
}

void pop_stack(pstack sta)
{
	assert(sta != NULL);
	if( sta == NULL || sta->data == NULL ) return;
	delete_seq_tail(sta->data);
}
