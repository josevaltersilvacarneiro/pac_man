#include "pac_man.h"

void
move_ghosts(void)
{
	for (register unsigned i = 0; i < 2; i++) {
		unsigned x = ghosts[i].x;
		unsigned y = ghosts[i].y;

		for (register unsigned j = 0; j < 10; j++) {
			y++;

			if (is_position_valid(&pac_man, x, y))
				break;
			else if (j + 1 == 10)
				y = ghosts[i].y;
		}

		go(&pac_man, &ghosts[i], x, y);
	}
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
		go(&pac_man, &man, x, y);
}

int
main(void)
{
	read_map(&pac_man);
	find_map(0, 0, &pac_man, &man, PAC_MAN);

	for (register int i = 0; i < 2; i++) {
		unsigned x, y;
		
		x = i == 0 ? 0 : ghosts[i-1].x;
		y = i == 0 ? 0 : ghosts[i-1].y + 1;

		find_map(x, y, &pac_man, &ghosts[i], GHOST);
	}

	do {
		char command;

		print_map(&pac_man);

		do {
			scanf(" %c", &command);
		} while (command != 'a' && command != 'w' && command != 's' && command != 'd');

		move(command);
		move_ghosts();
	} while (!end());

	free_map(&pac_man);

	return 0;
}
