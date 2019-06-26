#ifndef __SEQLIST_H
#define __SEQLIST_H

#define LENGTH 10
typedef int ElemType;

typedef struct _SeqList
{
	ElemType* data;
	int count;
	int length;
}SeqList, *pSeqList;

int init_seq(pSeqList seq);

void insert_seq_head(pSeqList seq, ElemType val);

void insert_seq_tail(pSeqList seq, ElemType val);

void insert_seq_pos(pSeqList seq, ElemType val, int pos);

void delete_seq_head(pSeqList seq);

void delete_seq_tail(pSeqList seq);

void delete_seq_pos(pSeqList seq, int pos);

void clear_seq(pSeqList seq);

int find_seq(pSeqList seq, ElemType val);

ElemType find_seq_pos(pSeqList seq, int pos);

void show_seq(pSeqList seq);

void destroy_seq(pSeqList seq);

int count_seq(pSeqList seq);
#endif
