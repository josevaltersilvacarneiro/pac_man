#include <stdio.h>
#include <stdlib.h>

int
main(void)
{
	FILE *f;
	unsigned int rows, columns;
	char **map;

	f = fopen("map.txt", "r");
	if (f == 0)
	{
		printf("There was an error\n");
		exit(1);
	}

	fscanf(f, "%d %d", &rows, &columns);
	map = malloc(sizeof(char *) * rows);
	
	for(register int i = 0; i < 5; i++)
		*(map + i) = malloc(sizeof(char) * columns);

	for(register int i = 0; i < 5; i++)
		fscanf(f, "%s", map[i]);

	fclose(f);

	for(register int i = 0; i < 5; i++)
		printf("%s\n", map[i]);

	for(register int i = 0; i < 5; i++)
		free(*(map + i));
	free(map);

	return 0;
}
