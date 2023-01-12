#include "pac_man.h"

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

int
main(void)
{
	read_map(&pac_man);

	do {
		char command;

		print_map(&pac_man);

		scanf(" %c", &command);
		move(command);
	} while (!end());

	free_map(&pac_man);

	return 0;
}
