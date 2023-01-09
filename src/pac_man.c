#include <stdio.h>
#include <stdlib.h>

int
main(void)
{
	FILE *f;
	char map[5][11];

	f = fopen("map.txt", "r");
	if (f == 0)
	{
		printf("There was an error\n");
		exit(1);
	}
	
	for(register int i = 0; i < 4; i++)
		fscanf(f, "%s", map[i]);

	for(register int i = 0; i < 4; i++)
		printf("%s\n", map[i]);

	return 0;
}
