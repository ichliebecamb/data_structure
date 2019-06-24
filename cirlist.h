#ifndef __CIRLIST_H
#define __CIRLIST_H
typedef int ElemType;
typedef struct _Cir
{
	ElemType data;
	struct _Cir *next;
}CNode, *CirList;

int init_cir(struct _Cir *head);

void insert_cir__head(struct _Cir  *head, ElemType val);

void insert_cir_tail(struct _Cir* head, ElemType val);

void delete_cir_head(struct _Cir* head);

void delete_cir_tail(struct _Cir* head);

void clear_cir(struct _Cir* head);

struct _list*  find_cir(struct _Cir* head, ElemType val);

void show_cir(struct _Cir* head);

#endif 
