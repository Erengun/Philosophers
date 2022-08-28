#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include "colors.h"

int main(void)
{
	int id = fork();
	fork();
	printf(GRN"Hi Guys from id: %d\n"RST, id);
	// 0 means it is a child process -1 for the error
	if (id == 0)
		printf(CYN"It seems i am a child process\n"RST);
	else
		printf(RED"Main process is ready for service\n"RST);
	return 0;
}

//(BEBOP ÇÖP İZLEME XDDDD)
// (SANNE LAN)