#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "map.h"

#define VERTICAL_WALL   '|'
#define HORIZONTAL_WALL '-'
#define PAC_MAN		'@'
#define SPACE		'.'

MAP pac_man;
MAN man;

int end(void);
void move(char direction);
int main(void);
