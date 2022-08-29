#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include "colors.h"

int mails = 0;
pthread_mutex_t mutex;

void* routine()
{
	for (int i = 0; i < 100000; i++) {
		pthread_mutex_lock(&mutex);
		mails++;
		pthread_mutex_unlock(&mutex);
	}
	// When we lock mutexes we get the true value of 200k
	return NULL;
}

int main(void)
{
	pthread_t p1, p2;
	pthread_mutex_init(&mutex, NULL);
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
	pthread_mutex_destroy(&mutex);
	printf(CYN"You have "RED"%d"CYN" mails"RST, mails);

	return 0;
}
