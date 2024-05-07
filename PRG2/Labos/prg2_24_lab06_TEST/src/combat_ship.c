/*
===============================================================================
File:                   combat_ship.c
Course:                 PRG2
Year:                   2024
Author:                 Basile Cuneo
Creation Date:          03.04.2024
Modification Author:    ROCHA FERREIRA Mário André
Modification Date:      03.05.2024
Version:                1.0
Description:            This is the file in which functions specific to combat
                        ships must be implemented
===============================================================================
*/

#include "combat_ship.h"
#include "config.h"
#include "ship.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/**
 * @brief check astromech series entered by user
 * @param buffer astromech series user input
 * @return bool the return code
 */
bool astromech_serie_check(char *buffer) {
    printf("Please choose an astromech serie from the following list: R1 R2 R3 BB\n");
    fgets(buffer, MAX_BUFFER_SIZE, stdin);

    if(strcmp(buffer, "R1") == 1 && strcmp(buffer, "R2") == 1 && strcmp(buffer, "R3") == 1 && strcmp(buffer, "BB") == 1){
        return false;
    }
    return true;
}

/**
 * @brief Read the astromech serie from the user
 * @param combat_ship the combat ship to store the astromech serie
 * @return int the return code
 */
int read_astromech_series(struct combat_ship *combat_ship) {
  char buffer[MAX_BUFFER_SIZE]; // = {0};

  while (astromech_serie_check(buffer) != 1){
      printf("Invalid astromech serie\n");
  }
  // remove extra newline character
  buffer[strcspn(buffer, NEWLINE)] = 0;

  if (strcmp(buffer, "R1") == 0) {
    combat_ship->astromech_series = R1;
  } else if (strcmp(buffer, "R2") == 0) {
    combat_ship->astromech_series = R2;
  } else if (strcmp(buffer, "R3") == 0) {
    combat_ship->astromech_series = R3;
  } else if (strcmp(buffer, "BB") == 0) {
    combat_ship->astromech_series = BB;
  } else {
    printf("Invalid astromech serie%s", NEWLINE);
    return UNKNOWN_ASTROMECH_TYPE;
  }

  return SUCCESS;
}

/**
 * @brief Add a combat ship to the fleet
 * @param fleet the fleet to add the ship to
 * @return int the return code
 */
int add_combat_ship(struct fleet *fleet) {
  printf("Please enter the pilot's name\n");
  // create temporary combat ship and store
  struct combat_ship combat_ship;

  combat_ship.pilot = malloc(MAX_BUFFER_SIZE * sizeof(char));
  if (combat_ship.pilot == NULL) {
    return MALLOC_ERROR;
  }
  fgets(combat_ship.pilot, MAX_BUFFER_SIZE, stdin);
  // remove extra newline character
  combat_ship.pilot[strcspn(combat_ship.pilot, NEWLINE)] = 0;

  int rc = 0;
  if ((rc = read_astromech_series(&combat_ship))) {
    return rc;
  }

  fleet->ships[fleet->nb_ships].combat = combat_ship;
  fleet->ships[fleet->nb_ships].type = COMBAT;

  return SUCCESS;
}

/**
 * @brief Cleanup the combat ship
 * @param ship the ship to cleanup
 * @return void
 */
void cleanup_combat_ship(struct ship *ship) {
  if (ship->combat.pilot != NULL) {
    free(ship->combat.pilot);
    ship->combat.pilot = NULL;
  }
}