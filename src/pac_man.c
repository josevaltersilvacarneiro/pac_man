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
	pac_man.map = malloc(sizeof(char *) * pac_man.rows);
	check_alloc_ptr(pac_man.map == NULL);

	for(register int i = 0; i < pac_man.rows; i++)
	{
	pac_man.map[i] = malloc(sizeof(char) * pac_man.columns);
		check_alloc_ptr(pac_man.map[i] == NULL);
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

	fscanf(f, "%d %d", &pac_man.rows, &pac_man.columns);

	alloc_map();

	for(i = 0; i < pac_man.rows; i++)
		fscanf(f, "%s", pac_man.map[i]);

	fclose(f);
}

void
free_map()
{
	for(register int i = 0; i < pac_man.rows; i++)
		free(*(pac_man.map + i));
	free(pac_man.map);
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

	for(register int i = 0; i < pac_man.rows; i++)
		for(register int j = 0; j < pac_man.columns; j++)
			if (pac_man.map[i][j] == '@') {
				x = i, y = j;
				break;
			}

	switch (direction)
	{
		case 'a':
		pac_man.map[x][y-1] = '@';
			break;
		case 'w':
		pac_man.map[x-1][y] = '@';
			break;
		case 's':
		pac_man.map[x+1][y] = '@';
			break;
		case 'd':
		pac_man.map[x][y+1] = '@';
			break;
	}

pac_man.map[x][y] = '.';
}

void
print_map()
{

	for(register int i = 0; i < pac_man.rows; i++)
		printf("%s\n", pac_man.map[i]);
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
