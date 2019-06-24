#include "cirlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <malloc.h>

static struct _Cir* create_node(struct _Cir *next, ElemType val)
{
	struct _Cir *node = (struct _Cir*)malloc(sizeof(struct _Cir));
	if( node != NULL)
	{
		node->next = next;
		node->data = val;
	}
	return node;
}

int init_cir(struct _Cir *head)
{
	assert(head != NULL );
	if(head == NULL ) return 0;

	head->next = NULL;
	return 1;
}

void insert_cir_head(struct _Cir  *head, ElemType val)
{
	assert(head != NULL);
	if( head == NULL ) return;

	struct _Cir* node = create_node(head->next, val);
	if( node == NULL) return;
	if( head->next == NULL)
	{	
		head->next = node;
		node->next = node;
	}
	else
	{

		struct _Cir* ptem = head->next;
		while( ptem->next != head->next )
		{
			ptem = ptem->next;
		}
		ptem->next = node;
		head->next = node;
	}
}

void insert_cir_tail(struct _Cir* head, ElemType val)
{
	assert(head != NULL);
	if( head == NULL ) return;

	struct _Cir* node = create_node(head->next, val);
	if( node == NULL) return;
	if( head->next == NULL)
	{	
		head->next = node;
		node->next = node;
	}
	else
	{
		struct _Cir* ptem = head->next;
		while( ptem->next != head->next )
		{
			ptem = ptem->next;
		}
		ptem->next = node;
	}
}

void delete_cir_head(struct _Cir* head)
{
	assert(head != NULL);
	if( head == NULL ) return;

	if(head->next == NULL ) 
	{
		return;
	}
	else
	{
		struct _Cir* ptem = head->next;
		if(ptem == ptem->next )
		{
			free( ptem );
			head->next = NULL;
		}
		else
		{
			struct _Cir* tail = ptem;
			while( tail-> next != head->next)
			{
				tail = tail->next;
			}

			head->next = ptem->next;
			tail->next = head->next;
			free( ptem );
		}
	}

}

void delete_cir_tail(struct _Cir* head)
{
	assert(head != NULL);
	if( head == NULL ) return;

	if(head->next == NULL ) 
	{
		return;
	}
	else
	{
		struct _Cir* fptr = NULL;
		struct _Cir* ptem = head->next;
		while( ptem->next != head->next )
		{
			fptr = ptem;
			ptem = ptem->next;
		}
		free(ptem);
		if( fptr == NULL )
		{
			head->next = NULL;
		}
		else
		{
			fptr->next = head->next;
		}
	}
}

void clear_cir(struct _Cir* head)
{
	assert(head != NULL);
	if( head == NULL ) return;

	if(head->next == NULL ) 
	{
		return;
	}
	else
	{
		struct _Cir* ptem = head->next;
		struct _Cir* fptr = NULL;
		while( ptem->next != head->next)
		{
			fptr = ptem;
			ptem = ptem->next;
			free( fptr );
		}
		free( ptem);
		head->next = NULL;
	}

}

struct _list*  find_cir(struct _Cir* head, ElemType val)
{
	return NULL;
}

void show_cir(struct _Cir* head)
{
	printf("Cir->");
	assert(head != NULL);
	if( head == NULL || head->next == NULL )
	{
		printf("\n");
		return;
	}
	else
	{
		struct _Cir* ptem = head->next;
		while( ptem->next != head->next )
		{
			printf("%d ",ptem->data);
			ptem = ptem->next;
		}
			printf("%d \n",ptem->data);
	}
}

