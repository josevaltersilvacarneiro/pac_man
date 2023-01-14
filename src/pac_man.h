#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "map.h"

MAP pac_man;
MAN man;

void ghosts(void);
int end(void);
bool is_position_valid(MAP *pac_man, unsigned x, unsigned y);
void move(char direction);
int main(void);
