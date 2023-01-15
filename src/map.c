#include "map.h"

bool
are_characters_close(const CHARACTER *first, const CHARACTER *last)
{
	unsigned first_x, first_y;
	unsigned last_x, last_y;

        first_x = first->x, first_y = first->y;
	last_x  = last->x , last_y = last->y ;
                    
	if (
		(last_x - first_x == 0 && abs(last_y - first_y) == 1) ||
		(abs(last_x - first_x) == 1 && last_y - first_y == 0)
	) return true;
	
	return false;
}

void
go(MAP *pac_man, CHARACTER *character,
		unsigned new_x, unsigned new_y)
{
        pac_man->map[character->x][character->y] = SPACE;
	pac_man->map[new_x][new_y] = character->symb;
	character->x = new_x; character->y = new_y;
}

void
check_alloc_ptr(bool show)
{
	if (show)
	{
		printf("The amount of memory available isn't enough to run this program\n");
		exit(1);
	}
}

void
find_map(unsigned x, unsigned y, MAP *pac_man,
		CHARACTER *character, const char symb)
{
	unsigned i, j;
	bool found = false;

	for(i = x; i < pac_man->rows && !found; i++)
                for(j = i == x ? y : 0; j < pac_man->columns; j++)
                        if (pac_man->map[i][j] == symb) {
                                character->x = i, character->y = j;
				character->symb = symb;
				found = true;
                                break;
                        }
}

void
alloc_map(MAP *pac_man)
{
        pac_man->map = malloc(sizeof(char *) * pac_man->rows);
        check_alloc_ptr(pac_man->map == NULL);
        
        for(register int i = 0; i < pac_man->rows; i++)
        {
        	pac_man->map[i] = malloc(sizeof(char) * pac_man->columns);
                check_alloc_ptr(pac_man->map[i] == NULL);
        }
}

void
read_map(MAP *pac_man)
{
        FILE *f;
        int i;

        f = fopen("map.txt", "r");
        if (f == 0)
        {
                printf("There was an error\n");
                exit(1);
        }

        fscanf(f, "%d %d", &pac_man->rows, &pac_man->columns);

        alloc_map(pac_man);

        for(i = 0; i < pac_man->rows; i++)
                fscanf(f, "%s", pac_man->map[i]);

        fclose(f);
}

void
free_map(MAP *pac_man)
{
        for(register int i = 0; i < pac_man->rows; i++)
                free(pac_man->map[i]);
        free(pac_man->map);
}

void
print_map(MAP *pac_man)
{

        for(register int i = 0; i < pac_man->rows; i++)
                printf("%s\n", pac_man->map[i]);
}
