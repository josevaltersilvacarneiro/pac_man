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
alloc_map()
{
	map = malloc(sizeof(char *) * rows);
	check_alloc_ptr(map == NULL);

	for(register int i = 0; i < rows; i++)
	{
		map[i] = malloc(sizeof(char) * columns);
		check_alloc_ptr(map[i] == NULL);
	}
}

void
read_map()
{
	FILE *f;
	int i;

	f = fopen("map.txt", "r");
	if (f == 0)
	{
		printf("There was an error\n");
		exit(1);
	}

	fscanf(f, "%d %d", &rows, &columns);

	alloc_map();

	for(i = 0; i < rows; i++)
		fscanf(f, "%s", map[i]);

	fclose(f);
}

void
free_map()
{
	for(register int i = 0; i < rows; i++)
		free(*(map + i));
	free(map);
}

int
end(void)
{
	return 0;
}

void
move(char direction)
{
	int x, y;

	for(register int i = 0; i < rows; i++)
		for(register int j = 0; j < columns; j++)
			if (map[i][j] == '@') {
				x = i, y = j;
				break;
			}

	switch (direction)
	{
		case 'a':
			map[x][y-1] = '@';
			break;
		case 'w':
			map[x-1][y] = '@';
			break;
		case 's':
			map[x+1][y] = '@';
			break;
		case 'd':
			map[x][y+1] = '@';
			break;
	}

	map[x][y] = '.';
}

void
print_map()
{

	for(register int i = 0; i < rows; i++)
		printf("%s\n", map[i]);
}

int
main(void)
{
	read_map();

	do {
		char command;

		print_map();

		scanf(" %c", &command);
		move(command);
	} while (!end());

	free_map();

	return 0;
}
