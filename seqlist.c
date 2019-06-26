#include "seqlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <malloc.h>

static int full(pSeqList seq)
{
	if( seq->count == LENGTH ) return 1;
	else return 0;
}

static int empty(pSeqList seq)
{
	if( seq->count == 0) return 1;
	else return 0;
}

static int expand(pSeqList seq)
{
	if(seq == NULL ) return 0;
	ElemType* tem = (ElemType*) malloc(sizeof(ElemType) * seq->count * 2);
	if( tem == NULL ) return 0;
	int i = 0;
	for(i; i < seq->count ; ++i )
	{
		tem[i] = seq->data[i];
	}
	free(seq->data);
	seq->data = tem;
	seq->length *= 2;
	return 1;
}
int init_seq(pSeqList seq)
{
	assert(seq != NULL);
	if( seq == NULL ) return 0;
	seq->data = (ElemType*)malloc(sizeof(ElemType) * LENGTH);
	if( seq->data == NULL ) return 0;
	seq->count = 0;
	return 1;
}

void insert_seq_head(pSeqList seq, ElemType val)
{
	assert(seq != NULL ) ;
	if(seq == NULL ) return;
	if( full(seq) )
	{
		if( expand(seq) == 0 ) return;
	}

	int i = seq->count;
	for(i; i > 0; i--)
	{
		seq->data[i] = seq->data[i-1];
	}
	seq->data[0] = val;
	seq->count++;
}

void insert_seq_tail(pSeqList seq, ElemType val)
{
	assert(seq != NULL ) ;
	if(seq == NULL ) return;
	if( full(seq) )
	{
		if( expand(seq) == 0 ) return;
	}

	seq->data[seq->count++] = val;
}

void insert_seq_pos(pSeqList seq, ElemType val, int pos)
{
	assert(seq != NULL ) ;
	if(seq == NULL ) return;
	if( full(seq) )
	{
		if( expand(seq) == 0 ) return;
	}

	if(!( pos > -1 && pos <= seq->count )) return;
	if( pos == seq->count ) 
	{
		seq->data[seq->count++] = val;
		return;
	} 

	int i = seq->count;
	for(i; i > pos; i--)
	{
		seq->data[i] = seq->data[i-1];
	}
	seq->data[pos] = val;
	seq->count++;
}

void delete_seq_head(pSeqList seq)
{
	assert(seq != NULL);
	if(seq == NULL || empty(seq)) return;

	int i = 0;
	for(i; i < seq->count - 1; i++)
	{
		seq->data[i] = seq->data[i+1];
	}
	seq->count--;
}

void delete_seq_tail(pSeqList seq)
{
	assert(seq != NULL);
	if(seq == NULL || empty(seq)) return;
	seq->count--;

}

void delete_seq_pos(pSeqList seq, int pos)
{
	assert(seq != NULL);
	if(seq == NULL || empty(seq)) return;
	if(!( pos > -1 && pos < seq->count )) return;
	for(pos; pos < seq->count - 2; pos++)
	{
		seq->data[pos] = seq->data[pos+1];
	}
	seq->count--;
}

void clear_seq(pSeqList seq)
{
	assert(seq != NULL);
	if(seq == NULL) return;
	seq->count = 0;
}

int find_seq(pSeqList seq, ElemType val)
{
	assert(seq != NULL);
	if(seq == NULL) return -1;
	int i = 0;
	for( i; i < seq->count; i++)
	{
		if(seq->data[i] == val )
		{
			return i;
		}
	}
}

void show_seq(pSeqList seq)
{	
	assert(seq != NULL);
	if(seq == NULL) return;
	int i = 0;
	for(i; i < seq->count; i++)
	{
		printf("%d ",seq->data[i]);
	}
	printf("\n");
}

void destroy_seq(pSeqList seq)
{
	assert(seq != NULL);
	if(seq == NULL) return;

	free(seq->data);
	seq->count = 0;
	seq->length = 0;
}

int count_seq(pSeqList seq)
{
	assert(seq != NULL);
	if(seq == NULL) return 0;
	return seq->count;
}

ElemType find_seq_pos(pSeqList seq, int pos)
{
	assert(seq != NULL);
	ElemType out;
	if(seq == NULL ) return out;
	if( pos >=  seq->count && pos < 0) return out;
	return seq->data[pos];
}
