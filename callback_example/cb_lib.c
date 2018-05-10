#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "cb_lib.h"

#define MAX 9
#define MIN 0

void cb_handler(int data, int (*mycb)(void))
{
	srand(time(NULL));
	while (1) {
		int rd = (rand() %
				(MAX - MIN + 1)) + MIN;
		printf("%d\n", rd);
		if (data == rd) {
			mycb();
			break;
		}
		sleep(1);
	}
}
