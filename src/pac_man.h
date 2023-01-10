#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char **map;

void check_alloc_ptr(bool ptr);
void alloc_map(unsigned int *rows, unsigned int *columns);
void read_map(unsigned int *rows, unsigned int *columns);
void free_map(unsigned int *rows, unsigned int *columns);
int main(void);
