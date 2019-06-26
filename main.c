#include <stdio.h>
#include <stdlib.h>
//#include "seqlist.h"
//#include "list.h"
//#include "cirlist.h"
#include "stack.h"
int main()
{
	/*
	struct _SeqList data;
	init_seq(&data);
	int i = 0;
	for(i; i < 5; i++)
	{
		insert_seq_head(&data, i);
	}

	show_seq(&data);
	for(i = 0; i < 6 ; i++)
	{
		insert_seq_tail(&data, i);
	}
	show_seq(&data);
	for(i = 0; i < 4; i++)
	{
		insert_seq_pos(&data, i, 5);
	}
	show_seq(&data);
	delete_seq_head(&data);
	show_seq(&data);
	delete_seq_tail(&data);
	show_seq(&data);
	delete_seq_pos(&data, 1);
	show_seq(&data);
	clear_seq(&data);
	show_seq(&data);
	destroy_seq(&data);
	*/
	/*
	list data;
	init_list(&data);
	int i = 0;
	for(; i < 5; i++)
	{
		insert_list_head(&data, i);
	}
	show_list(&data);
	for( i = 0; i < 5; i++)
	{
		insert_list_tail(&data, i);
	}
	show_list(&data);

	delete_list_head(&data);
	delete_list_tail(&data);
	show_list(&data);
	clear_list(&data);
	*/

/*	CNode head;
	init_cir( &head );
	int i = 0;
	for(; i < 5; i++)
	{
		insert_cir_tail(&head, i);
	}
	show_cir( &head );
	delete_cir_head( &head );
	show_cir( &head );
	delete_cir_tail( &head );
	show_cir( &head );
	clear_cir( &head );
	show_cir( &head );
	*/

	struct stack data;
	init_stack(&data);
	int i = 0;
	for(; i < 20 ; i++)
	{
		push_stack(&data, i);
	}

	while( isempty_stack(&data) == 0)
	{
		printf("%d ", stack_top(&data));
		pop_stack(&data);
	}
	printf("\n");
	clear_stack(&data);
	destroy_stack(&data);
	exit(0);
}
