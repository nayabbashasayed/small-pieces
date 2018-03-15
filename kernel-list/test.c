#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include <time.h>

struct mystruct {
	int a;
	struct list_head mylist;
};

int i = 1;

/* This is the initialization of list_head structue.
This can be used as head to any structure for linked list implementation.
Other structure must have struct list_head list as a member.
This is independent head for any linked list */
LIST_HEAD(head);

void add(void) {
	struct mystruct *mem;
	mem = malloc(sizeof(struct mystruct));
	int random_x;
	random_x = rand() % 100;
	printf("Rand %d\n", random_x);
	mem->a = random_x;
	list_add_tail(&(mem->mylist), &head);
}

void print1(void) {
	struct list_head *pos = NULL;
	struct mystruct *dataptr = NULL;
	list_for_each(pos, &head) {
		dataptr = list_entry(pos, struct mystruct, mylist);
		printf("Integer = %d\n", dataptr->a);
	}
}

void print2(void) {
	struct list_head *pos = NULL;
	struct mystruct *dataptr = NULL;
	list_for_each_entry(dataptr, &head, mylist) {
		printf("Integer = %d\n", dataptr->a);
	}
}

void del_first_entry(void)
{
	struct list_head *del = &head;
	del = del->next;
	__list_del_entry(del);
}

int main(void)
{
	srand ( time(NULL) );
	printf("Adding three random numbers\n");
	add();
	add();
	add();
	printf("Printing using two different methods\n");
	print1();
	print2();
	puts("");
	printf("Deleted first entry\n");
	del_first_entry();
	print2();
}
