#include <stdio.h>
#include "cb_lib.h"

int my2handler(void)
{
	puts("Now got number 2");
	return 0;
}
int main(void)
{
	cb_handler(2, my2handler);
	return 0;
}
