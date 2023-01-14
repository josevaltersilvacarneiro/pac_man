#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct map {
        unsigned rows, columns;
        char **map;
};

struct character {
        unsigned x, y;
	char symb;
}; 

typedef struct character CHARACTER;
typedef struct map MAP;

#define VERTICAL_WALL   '|'
#define HORIZONTAL_WALL '-'
#define PAC_MAN         '@'
#define GHOST           'F'
#define SPACE           '.'

void go(MAP *pac_man, CHARACTER *character, unsigned new_x, unsigned new_y);
void check_alloc_ptr(bool ptr);
void find_map(unsigned x, unsigned y, MAP *pac_man, CHARACTER *character, const char symb);
void alloc_map(MAP *pac_man);
void read_map(MAP *pac_man);
void free_map(MAP *pac_man);
void print_map(MAP *pac_man);
