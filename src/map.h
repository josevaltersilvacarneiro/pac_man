#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct map {
        unsigned rows, columns;
        char **map;
};

typedef struct map MAP;

struct character {
        unsigned x, y;
	char symb;
}; 

typedef struct character CHARACTER;

struct man {
	CHARACTER man;
	bool bomb;
};

typedef struct man MAN;

struct ghost {
	CHARACTER ghost;
	bool status;
};

typedef struct ghost GHOST;

#define VERTICAL_WALL   '|'
#define HORIZONTAL_WALL '-'
#define PAC_MAN         '@'
#define SYMB_GHOST      'F'
#define SPACE           '.'
#define BOMB		'B'

bool are_characters_close(const CHARACTER *first, const CHARACTER *last);
void go(MAP *pac_man, CHARACTER *character, unsigned new_x, unsigned new_y);
void check_alloc_ptr(bool ptr);
void find_map(unsigned x, unsigned y, MAP *pac_man, CHARACTER *character, const char symb);
void alloc_map(MAP *pac_man);
void read_map(MAP *pac_man);
void free_map(MAP *pac_man);
void print_map(MAP *pac_man);
