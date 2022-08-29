#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include "colors.h"
#include <time.h>
#include <stdlib.h>


void* roll_dice()
{
	int value = (rand() % 6) + 1;
	int *num = malloc(sizeof(int));
	*num = value;
	return (void *) num;
}

int main(void)
{
	pthread_t th;
	int* res;
	srand(time(NULL));
	if (pthread_create(&th, NULL, roll_dice, NULL) != 0)
		return 1;
	if (pthread_join(th, (void **)&res) != 0)
		return 2;
	printf("Dice rolled value is %d", *res);
	free(res);
	return 0;
}
