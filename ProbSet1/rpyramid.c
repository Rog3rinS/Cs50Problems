#include <stdio.h>

int main(void) 
{
	int size = 8;
	int count = 0;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < count + 1; j++)
		{
			printf("#");
		}
		printf("\n");
		count += 1;
	}
}
