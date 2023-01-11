#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char **map;
unsigned rows, columns;

void check_alloc_ptr(bool ptr);
void alloc_map(void);
void read_map(void);
void free_map(void);
int end(void);
void move(char direction);
void print_map(void);
int main(void);
