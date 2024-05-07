/*
===============================================================================
File:                   command_ship.c
Course:                 PRG2
Year:                   2024
Author:                 Basile Cuneo
Creation Date:          03.04.2024
Modification Author:    ROCHA FERREIRA Mário André
Modification Date:      03.05.2024
Version:                1.0
Description:            This is the file in which functions specific to command
                        ships must be implemented
===============================================================================
*/

#include "command_ship.h"
#include "config.h"
#include "ship.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Add a command ship to the fleet
 * @param fleet the fleet to add the ship to
 * @return int the return code
 */
int add_command_ship(struct fleet *fleet) {
  char buffer[MAX_BUFFER_SIZE];
  struct command_ship ship;

  ship.commander = malloc(MAX_BUFFER_SIZE * sizeof(char));
  if (ship.commander == NULL) {
    return MALLOC_ERROR;
  }

  printf("Please enter the commander's name%s", NEWLINE);
  fgets(buffer, MAX_BUFFER_SIZE, stdin);
  buffer[strcspn(buffer, NEWLINE)] = 0;
  strncpy(ship.commander, buffer, MAX_BUFFER_SIZE);

  printf("Please enter the number of passengers%s", NEWLINE);
  fgets(buffer, MAX_BUFFER_SIZE, stdin);
  ship.nb_passengers = atoi(buffer);

  fleet->ships[fleet->nb_ships].type = COMMAND;
  fleet->ships[fleet->nb_ships].command = ship;

  return SUCCESS;
}

/**
 * @brief Cleanup the command ship
 * @param ship the ship to cleanup
 * @return void
 */
void cleanup_command_ship(struct ship *ship) {
  if (ship->command.commander != NULL) {
    free(ship->command.commander);
    ship->command.commander = NULL;
  }
}