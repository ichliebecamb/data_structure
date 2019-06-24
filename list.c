#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
static struct _list* create_node(struct _list* next, ElemType val)
{
	struct _list* node = (struct _list*)malloc(sizeof(struct _list));
	if( node != NULL ) 
	{
		node->data = val;
		node->next = next;
	}
	return node;
}

int init_list(struct _list *head)
{
	assert( NULL != head);
	if(head == NULL ) return 0;

	head->next = NULL;
	return 1;
}

void insert_list_head(struct _list *head, ElemType val)
{
	assert( NULL != head);
	if(head == NULL ) return ;

	struct _list* node = create_node(head->next, val);
	if(node != NULL ) 
	{
		head->next = node;
	}
}

void insert_list_tail(struct _list* head, ElemType val)
{
	assert( NULL != head);
	if(head == NULL ) return ;

	struct _list* p = head;
	while( p->next != NULL )
	{
		p = p->next;
	}
	p->next = create_node(NULL, val);
}

void delete_list_head(struct _list* head)
{
	assert( NULL != head);
	if(head == NULL ) return ;

	struct _list* next = head->next;
	if( next == NULL ) return;
	head->next = next->next;
	free(next);
}

void delete_list_tail(struct _list* head)
{	
	assert( NULL != head);
	if(head == NULL ) return ;
	struct _list* p = head;
	struct _list* tail = NULL;
	while( p->next != NULL )
	{
		tail = p;
		p = p->next;
	}
	free(tail->next);
	tail->next = NULL;

}

void clear_list(struct _list* head)
{
	assert( NULL != head);
	if(head == NULL ) return ;
	while( head->next != NULL )
	{
		delete_list_head(head);
	}
}

struct _list*  find_list(struct _list* head, ElemType val)
{
	assert( NULL != head);
	if(head == NULL ) return NULL;
	struct _list* node = head->next;
	while( node != NULL)		
	{
		if( node->data == val)
		{
			return node;
		}
	}
	return NULL;
}

void show_list(struct _list* head)
{
	printf("list->");
	assert( NULL != head);
	if(head == NULL ) 
	{
		printf("\n");
		return;
	}
	
	struct _list* node = head->next;
	while( node != NULL)		
	{
		printf("%d ",node->data);
		node = node->next;
	}
	printf("\n");

}


