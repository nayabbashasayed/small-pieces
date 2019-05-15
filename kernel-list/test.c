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

void add_tail(void) {
	struct mystruct *mem;
	mem = malloc(sizeof(struct mystruct));
	int random_x;
	random_x = rand() % 100;
	printf("Rand %d\n", random_x);
	mem->a = random_x;
	list_add_tail(&(mem->mylist), &head);
}

void add_head(void) {
	struct mystruct *mem;
	mem = malloc(sizeof(struct mystruct));
	int random_x;
	random_x = rand() % 100;
	printf("Rand %d\n", random_x);
	mem->a = random_x;
	list_add(&(mem->mylist), &head);
}

void print1(void) {
	struct list_head *pos = NULL;
	struct mystruct *dataptr = NULL;
	if (list_empty(&head)) {
		printf("List empty\n");
	}
	list_for_each(pos, &head) {
		dataptr = list_entry(pos, struct mystruct, mylist);
		printf("Integer = %d\n", dataptr->a);
	}
}

void print2(void) {
	//struct list_head *pos = NULL;
	struct mystruct *dataptr = NULL;
	list_for_each_entry(dataptr, &head, mylist) {
		printf("Integer = %d\n", dataptr->a);
	}
}

void del_first_entry(void)
{
	struct list_head *del = &head;
	del = del->next;
	struct mystruct *dataptr = container_of(del, struct mystruct, mylist);
	__list_del_entry(del);
	free(dataptr);
}

void del_last_entry(void)
{
	struct mystruct *dataptr = NULL;
	struct mystruct *last = NULL;
	struct list_head *last_ptr = NULL;
	list_for_each_entry(dataptr, &head, mylist) {
		last = dataptr;
	}
	last_ptr = &last->mylist;
	__list_del_entry(last_ptr);
	free(last_ptr);
}

void avg_first_n_num(int n)
{
	struct mystruct *dataptr = NULL;
	int iter = 0, avg = 0;
	list_for_each_entry(dataptr, &head, mylist) {
		if (iter == n) {
			break;
		}
		avg += dataptr->a;
		printf("Integer = %d\n", dataptr->a);
		iter ++;
	}
	printf("Total avg %d\n", avg);
}

int main(void)
{
	srand ( time(NULL) );
	printf("Adding three random numbers\n");
	add_tail();
	del_first_entry();
}
