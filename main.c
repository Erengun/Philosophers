#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include "colors.h"

void *th_fun(void *asd)
{

	printf("Greetings from 42\n");
	sleep(2);
	printf("End test\n");
	return NULL;
}

int main(void)
{
	pthread_t id1, id2;
	printf(RED"Before Thread\n"RST);
	th_fun(NULL);
	th_fun(NULL);
	printf(CYN"After Thread\n"RST);
	pthread_create(&id1, NULL, &th_fun, NULL);
	pthread_create(&id2, NULL, &th_fun, NULL);
	pthread_join(id1, NULL);
	pthread_join(id2, NULL);
	return 0;
}
