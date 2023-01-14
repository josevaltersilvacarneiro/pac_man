#include "pac_man.h"

void
ghosts(void)
{
	for (unsigned i = 0; i < pac_man.rows; i++)
		for (unsigned int j = 0; j < pac_man.columns; j++)
			if (
					pac_man.map[i][j] == GHOST &&
					is_position_valid(&pac_man, i, j+1)
				) go(&pac_man, &i, &j, i, j+1, GHOST);
}

int
end(void)
{
	return 0;
}

bool
is_position_valid(MAP *pac_man, unsigned x, unsigned y)
{
	return x < pac_man->rows && y < pac_man->columns && pac_man->map[x][y] == SPACE;
}

void
move(char direction)
{
	unsigned x = man.x, y = man.y;

	switch (direction)
	{
		case 'a':
			y--;
			break;
		case 'w':
			x--;
			break;
		case 's':
			x++;
			break;
		case 'd':
			y++;
			break;
	}

	if (is_position_valid(&pac_man, x, y))
		go(&pac_man, &man.x, &man.y, x, y, PAC_MAN);
}

int
main(void)
{
	read_map(&pac_man);
	find_map(&pac_man, &man, PAC_MAN);

	do {
		char command;

		print_map(&pac_man);

		do {
			scanf(" %c", &command);
		} while (command != 'a' && command != 'w' && command != 's' && command != 'd');

		move(command);
		ghosts();
	} while (!end());

	free_map(&pac_man);

	return 0;
}
