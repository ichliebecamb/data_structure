#ifndef __LIST_H
#define __LIST_H
typedef int ElemType;
typedef struct _list
{
	ElemType data;
	struct _list *next;
}list;

int init_list(struct _list *head);

void insert_list_head(struct _list *head, ElemType val);

void insert_list_tail(struct _list* head, ElemType val);

void delete_list_head(struct _list* head);

void delete_list_tail(struct _list* head);

void clear_list(struct _list* head);

struct _list*  find_list(struct _list* head, ElemType val);

void show_list(struct _list* head);

#endif 
