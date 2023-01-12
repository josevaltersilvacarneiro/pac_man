#include "pac_man.h"

int
end(void)
{
	return 0;
}

void
move(char direction)
{
	pac_man.map[man.x][man.y] = '.';

	switch (direction)
	{
		case 'a':
			pac_man.map[man.x][man.y-1] = '@';
			man.y--;
			break;
		case 'w':
			pac_man.map[man.x-1][man.y] = '@';
			man.x--;
			break;
		case 's':
			pac_man.map[man.x+1][man.y] = '@';
			man.x++;
			break;
		case 'd':
			pac_man.map[man.x][man.y+1] = '@';
			man.y++;
			break;
	}
}

int
main(void)
{
	read_map(&pac_man);
	find_map(&pac_man, &man, '@');

	do {
		char command;

		print_map(&pac_man);

		scanf(" %c", &command);
		move(command);
	} while (!end());

	free_map(&pac_man);

	return 0;
}
