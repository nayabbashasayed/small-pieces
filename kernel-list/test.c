#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct mystruct {
	int a;
	struct list_head mylist;
};

int i = 1;

void add(struct list_head *head) {
	struct mystruct *mem;
	mem = malloc(sizeof(struct mystruct));
	mem->a = 30*i;
	i++;
	list_add_tail(&(mem->mylist), head);
}
void print(struct list_head *head) {
	struct list_head *pos = NULL;
	struct mystruct *dataptr = NULL;
	list_for_each(pos, head) {
		dataptr = list_entry(pos, struct mystruct, mylist);
		printf("Integer = %d\n", dataptr->a);
	}
}
int main(void)
{
	LIST_HEAD(head);
	add(&head);
	add(&head);
	add(&head);
	print(&head);
}
