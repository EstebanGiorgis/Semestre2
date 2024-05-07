/*
===============================================================================
File:                   command_ship.h
Course:                 PRG2
Year:                   2024
Author:                 Basile Cuneo
Creation Date:          03.04.2024
Modification Author:    ROCHA FERREIRA Mário André
Modification Date:      03.05.2024
Version:                1.0
Description:            This is the file in which functions specific to command
                        ships must be declared. The struct for command ships
                        specific datas must also be declared here.
===============================================================================
*/

#ifndef COMMAND_SHIP_H

#define COMMAND_SHIP_H

struct command_ship {
  char *commander;
  int nb_passengers;
};

#include "ship.h"

int add_command_ship(struct fleet *fleet);
void cleanup_command_ship(struct ship *ship);

#endif