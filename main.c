#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include "colors.h"

int mails = 0;

void* routine()
{
	for (int i = 0; i < 100000; i++) {
		mails++;
	}
	// In this example the excepted output is 200k but we get a output around 103k
	return NULL;
}

int main(void)
{
	pthread_t p1, p2;
	if (pthread_create(&p1, NULL, &routine, NULL) != 0) {
		return 1;
	}
	if (pthread_create(&p2, NULL, &routine, NULL) != 0) {
		return 2;
	}
	if (pthread_join(p1, NULL) != 0) {
		return 3;
	}
	if (pthread_join(p2, NULL) != 0) {
		return 4;
	}
	printf(CYN"You have "RED"%d"CYN" mails"RST, mails);
	return 0;
}
