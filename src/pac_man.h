#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "map.h"

MAP pac_man;
MAN man;
CHARACTER bomb;

GHOST ghosts[2];

void move_ghosts(void);
int end(void);
bool is_position_valid(MAP *pac_man, unsigned x, unsigned y);
void move(char direction);
void explode_bomb(void);
int main(void);
