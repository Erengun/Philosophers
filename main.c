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
	// Create threads in loop
	pthread_t p[4];
	pthread_mutex_init(&mutex, NULL);
	int i = 0;
	while (i < 4)
	{
		if (pthread_create(&p[i], NULL, &routine, NULL) != 0)
			return i;
		if (pthread_join(p[i], NULL) != 0)
			return i + 4;
		i++;
	}
	pthread_mutex_destroy(&mutex);
	printf(CYN"You have "RED"%d"CYN" mails"RST, mails);
	return 0;
}
