#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int i;
	srand((unsigned int)time(NULL));
	for (i = 0; i < 5; i++)
	{
		int r = rand() % 100 + 1;

		printf("%d\n", r);
	}
	return 0;
}