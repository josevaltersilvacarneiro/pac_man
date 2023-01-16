#include "pac_man.h"

void
move_ghosts(void)
{
	for (register unsigned i = 0; i < 2; i++) {
		unsigned x = ghosts[i].x;
		unsigned y = ghosts[i].y;

		for (register unsigned j = 0; j < 10; j++) {
			unsigned seconds = time(0);
			unsigned rand_num;

			srand(seconds);
			rand_num = rand() % 4 + 1;

			switch (rand_num) {
				case 1:
					x++;
					break;
				case 2:
					y++;
					break;
				case 3:
					x--;
					break;
				case 4:
					y--;
					break;
			}

			if (is_position_valid(&pac_man, x, y))
				break;
			
			x = ghosts[i].x;
			y = ghosts[i].y;
		}

		go(&pac_man, &ghosts[i], x, y);
	}
}

int
end(void)
{
	for (register unsigned i = 0; i < 2; i++)
		if (are_characters_close(&man.man, &ghosts[i]))
			return 1;

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
	unsigned x = man.man.x, y = man.man.y;

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
		case 'b':
			break;
	}

	if (is_position_valid(&pac_man, x, y))
		go(&pac_man, &man.man, x, y);
}

int
main(void)
{
	read_map(&pac_man);

	find_map(0, 0, &pac_man, &man.man, PAC_MAN);
	find_map(0, 0, &pac_man, &bomb, BOMB);

	man.bomb = false;

	for (register int i = 0; i < 2; i++) {
		unsigned x, y;
		
		x = i == 0 ? 0 : ghosts[i-1].x;
		y = i == 0 ? 0 : ghosts[i-1].y + 1;

		find_map(x, y, &pac_man, &ghosts[i], GHOST);
	}

	do {
		char command;

		print_map(&pac_man);

		move_ghosts();
		do {
			scanf(" %c", &command);
		} while (command != 'a' && command != 'w' && command != 's' && command != 'd' && command != 'b');

		move(command);
		if (!man.bomb && are_characters_close(&man.man, &bomb)) {
			pac_man.map[bomb.x][bomb.y] = SPACE;
			man.bomb = true;
		}
	} while (!end());

	print_map(&pac_man);

	free_map(&pac_man);

	return 0;
}
