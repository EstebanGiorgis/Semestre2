/*
===============================================================================
File:                   combat_ship.h
Course:                 PRG2
Year:                   2024
Author:                 Basile Cuneo
Creation Date:          03.04.2024
Modification Author:    ROCHA FERREIRA Mário André
Modification Date:      03.05.2024
Version:                1.0
Description:            This is the file in which functions specific to combat
                        ships must be declared. The struct for combat ships
                        specific datas must also be declared here.
===============================================================================
*/

#ifndef COMBAT_SHIP_H

#define COMBAT_SHIP_H

enum AstromechSeries { R1, R2, R3, BB };

struct combat_ship {
  char *pilot;
  enum AstromechSeries astromech_series;
};

#include "ship.h"

int read_astromech_series(struct combat_ship *combat_ship);
int add_combat_ship(struct fleet *fleet);
void cleanup_combat_ship(struct ship *ship);

#endif