#include <stdio.h>
#include <stdlib.h>

char **map;

void alloc_map(unsigned int *rows, unsigned int *columns);
void read_map(unsigned int *rows, unsigned int *columns);
void free_map(unsigned int *rows, unsigned int *columns);
int main(void);
