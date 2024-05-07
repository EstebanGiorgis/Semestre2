/*
===============================================================================
File:                   cargo_ship.c
Course:                 PRG2
Year:                   2024
Author:                 Basile Cuneo
Creation Date:          03.04.2024
Modification Author:    Esteban Giorgis
Modification Date:      03.05.2024
Version:                1.0
Description:            This is the file in which functions specific to cargo
                        ships must be implemented
===============================================================================
*/

#include "cargo_ship.h"
#include "config.h"
#include "ship.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Add a cargo ship to the fleet
 * @param fleet the fleet to add the ship to
 * @return int the return code
 */
int add_cargo_ship(struct fleet *fleet) {
    char buffer[MAX_BUFFER_SIZE];
    struct cargo_ship ship;

    printf("Please enter the maximum cargo's weight that the ship can transport!%s", NEWLINE);
    fgets(buffer, MAX_BUFFER_SIZE, stdin);
    ship.max_weight = atoi(buffer);

    fleet->ships[fleet->nb_ships].type = CARGO;
    fleet->ships[fleet->nb_ships].cargo = ship;

    return SUCCESS;
}
