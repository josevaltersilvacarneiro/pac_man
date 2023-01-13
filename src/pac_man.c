#include "pac_man.h"

int
end(void)
{
	return 0;
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

	if (
			x < pac_man.rows &&
			y < pac_man.columns &&
			pac_man.map[x][y] == SPACE
	   ) {
		pac_man.map[x][y] = PAC_MAN;
		pac_man.map[man.x][man.y] = SPACE;
		man.x = x; man.y = y;
	}
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
	} while (!end());

	free_map(&pac_man);

	return 0;
}
