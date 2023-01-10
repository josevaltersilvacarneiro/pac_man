#include "pac_man.h"

void
check_alloc_ptr(bool ptr)
{
	if (ptr)
	{
		printf("The amount of memory available isn't enough to run this program\n");
		exit(1);
	}
}

void
alloc_map(unsigned int *rows, unsigned int *columns)
{
	unsigned int num_of_rows = *rows;
	unsigned int num_of_columns = *columns;

	map = malloc(sizeof(char *) * num_of_rows);
	check_alloc_ptr(map == NULL);

	for(register int i = 0; i < num_of_rows; i++)
	{
		map[i] = malloc(sizeof(char) * num_of_columns);
		check_alloc_ptr(map[i] == NULL);
	}
}

void
read_map(unsigned int *rows, unsigned int *columns)
{
	FILE *f;
	int i;

	f = fopen("map.txt", "r");
	if (f == 0)
	{
		printf("There was an error\n");
		exit(1);
	}

	fscanf(f, "%d %d", rows, columns);

	alloc_map(rows, columns);

	for(i = 0; i < *rows; i++)
		fscanf(f, "%s", map[i]);

	fclose(f);
}

void
free_map(unsigned int *rows, unsigned int *columns)
{
	for(register int i = 0; i < *rows; i++)
		free(*(map + i));
	free(map);
}

int
main(void)
{
	unsigned int rows, columns;

	read_map(&rows, &columns);

	for(register int i = 0; i < rows; i++)
		printf("%s\n", map[i]);
	
	free_map(&rows, &columns);

	return 0;
}
