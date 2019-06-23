#include <stdio.h>
#include <stdlib.h>
#include "seqlist.h"
int main()
{
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
	exit(0);
}
