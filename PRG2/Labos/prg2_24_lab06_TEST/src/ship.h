/*
===============================================================================
File:                   ship.h
Course:                 PRG2
Year:                   2024
Author:                 Basile Cuneo
Creation Date:          03.04.2024
Modification Author:    Esteban Giorgis
Modification Date:      03.05.2024
Version:                1.0
Description:            This is the file in which all common ships functions
must be declared. The The struct / enum for the common part of all the ship's
datas must also be declared here.
===============================================================================
*/

#ifndef SHIP_H

#define SHIP_H

// forward declaration
struct ship;
struct fleet;

#include "cargo_ship.h"
#include "combat_ship.h"
#include "command_ship.h"

enum ship_type { COMBAT = 1, CARGO, COMMAND };

struct ship {
  char *name;
  char *model;
  enum ship_type type;
  union {
    struct cargo_ship cargo;
    struct combat_ship combat;
    struct command_ship command;
  };
};

struct fleet {
  int nb_ships;
  int ship_capacity;
  struct ship *ships;
};

void display_ship_infos(struct ship *ship);
int add_ship_to_fleet(struct fleet *fleet);
void cleanup_ship(struct ship *ship);

void cleanup_fleet(struct fleet *fleet);

#endif