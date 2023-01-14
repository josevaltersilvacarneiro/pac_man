#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct map {
        char **map;
        unsigned rows, columns;
};

struct man {
        unsigned x, y;
}; 

typedef struct man MAN;
typedef struct map MAP;

#define VERTICAL_WALL   '|'
#define HORIZONTAL_WALL '-'
#define PAC_MAN         '@'
#define GHOST           'F'
#define SPACE           '.'

void go(MAP *pac_man, unsigned *x, unsigned *y, unsigned new_x, unsigned new_y, char symb);
void check_alloc_ptr(bool ptr);
void find_map(MAP *pac_man, MAN *man, char c);
void alloc_map(MAP *pac_man);
void read_map(MAP *pac_man);
void free_map(MAP *pac_man);
void print_map(MAP *pac_man);
