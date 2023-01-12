#include "map.h"

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

