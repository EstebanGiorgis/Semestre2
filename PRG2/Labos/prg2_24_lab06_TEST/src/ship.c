/*
===============================================================================
File:                   ship.c
Course:                 PRG2
Year:                   2024
Author:                 Basile Cuneo
Creation Date:          03.04.2024
Modification Author:    Esteban Giorgis
Modification Date:      03.05.2024
Version:                1.0
Description:            This is the file in which all common ships functions
must be implemented.
===============================================================================
*/

#include "ship.h"
#include "combat_ship.h"
#include "config.h"
#include "ship.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/**
 * @brief Display the ship information
 * @details Display the ship information in YAML or text format depending on the
 * YAML_SUPPORT compile time flag
 * @param ship the ship to display
 * @return void
 */
void display_ship_infos(struct ship *ship) {
#if YAML_SUPPORT

  printf("- name: %s%s", ship->name, NEWLINE);
  printf("  model: %s%s", ship->model, NEWLINE);

  printf("  type: ");
  switch (ship->type) {
        case COMMAND:
    printf("command%s", NEWLINE);
    printf("  commander_name: %s%s", ship->command.commander, NEWLINE);
    printf("  nb_passengers: %d%s", ship->command.nb_passengers, NEWLINE);
    break;
      case CARGO:
    printf("cargo%s", NEWLINE);
    printf("  max_cargo_weight [kg]: %d%s", ship->cargo.max_weight, NEWLINE);
    break;
  case COMBAT:
    printf("combat%s", NEWLINE);
    printf("  pilot_name: %s%s", ship->combat.pilot, NEWLINE);
    printf("  droid_serie: %u%s", ship->combat.astromech_series, NEWLINE);
    break;


  }
#else
  printf("Ship name: %s%s", ship->name, NEWLINE);
  printf("Ship model: %s%s", ship->model, NEWLINE);

  printf("Ship type: ");
  switch (ship->type) {
  case COMMAND:
      printf("Command%s", NEWLINE);
    printf("Commander's name: %s%s", ship->command.commander, NEWLINE);
    printf("Number of passengers: %d%s", ship->command.nb_passengers, NEWLINE);
    break;
  case CARGO:
      printf("Cargo%s", NEWLINE);
    printf("Max cargo weight [kg]: %d%s", ship->cargo.max_weight, NEWLINE);
    break;

  case COMBAT:
      printf("Combat%s", NEWLINE);
    printf("Pilot's name: %s%s", ship->combat.pilot, NEWLINE);
    printf("Droid serie: ");
    switch (ship->combat.astromech_series) {
    case R1:
      printf("R1");
      break;
    case R2:
      printf("R2");
      break;
    case R3:
      printf("R3");
      break;
    case BB:
      printf("BB");
      break;
    default:
      break;
    }
    printf(" series%s", NEWLINE);
  }
#endif
}

/**
 * @brief Fetch the ship type from the user
 * @return int the ship type
 */
int fetch_ship_type() {
  char buffer[MAX_BUFFER_SIZE]; // = {0};
  int type = 0;

  printf("Please choose the ship type:\n");
  printf("1. Combat ship\n");
  printf("2. Cargo ship\n");
  printf("3. Command ship\n");

  fgets(buffer, MAX_BUFFER_SIZE, stdin);
  type = atoi(buffer);
  return type;
}

/**
 * @brief Add a combat ship to the fleet
 * @param fleet the fleet to add the ship to
 * @return int the return code
 */
int add_ship_to_fleet(struct fleet *fleet) {
  char buffer[MAX_BUFFER_SIZE]; // = {0};
  char *model = NULL;
  char *name = NULL;
  int rc = 0;

  printf("Please enter a name for your ship\n");
  // do not use a temporary buffer to store the name. malloc the exact size
  // of the name and store it directly in the ship structure
  name = malloc(MAX_BUFFER_SIZE * sizeof(char));
  // check if malloc failed
  if (name == NULL) {
    return MALLOC_ERROR;
  }
  fgets(name, MAX_BUFFER_SIZE, stdin);
  name[strcspn(name, NEWLINE)] = 0;

  printf("Please enter a model for your ship\n");
  model = malloc(MAX_BUFFER_SIZE * sizeof(char));
  // check if malloc failed
  if (model == NULL) {
    return MALLOC_ERROR;
  }
  fgets(model, MAX_BUFFER_SIZE, stdin);
  // remove extra newline character
  model[strcspn(model, NEWLINE)] = 0;

  int ship_type = 0;
  ship_type = fetch_ship_type();

  switch (ship_type) {
  case COMBAT:
    if ((rc = add_combat_ship(fleet))) {
      return rc;
    }
    break;
  case CARGO:
      if ((rc = add_cargo_ship(fleet))) {
          return rc;
      }
    break;
  case COMMAND:
    if ((rc = add_command_ship(fleet))) {
      return rc;
    }
    break;
  default:
    return UNKNOWN_SHIP_TYPE;
  }

  // add common fields
  fleet->ships[fleet->nb_ships].name = name;
  fleet->ships[fleet->nb_ships].model = model;

  ++fleet->nb_ships;
  name = NULL;
  model = NULL;

  return SUCCESS;
}

/**
 * @brief Cleanup the combat ship and the command ship by freeing all the allocated memory
 * @param ship to cleanup
 * @return void
 */
void cleanup_ship(struct ship *ship) {
  if (ship->name != NULL) {
    free(ship->name);
    ship->name = NULL;
  }

  if (ship->model != NULL) {
    free(ship->model);
    ship->model = NULL;
  }

  switch (ship->type) {
  case COMBAT:
    cleanup_combat_ship(ship);
    break;
  case COMMAND:
    cleanup_command_ship(ship);
    break;
  default:
    break;
  }
}

/**
 * @brief Cleanup the fleet by freeing all the allocated memory
 * @param fleet the fleet to cleanup
 * @return void
 */
void cleanup_fleet(struct fleet *fleet) {
  if (fleet->ships != NULL) {
    for (int i = 0; i < fleet->nb_ships; i++) {
      cleanup_ship(&fleet->ships[i]);
    }
    free(fleet->ships);
    fleet->ships = NULL;
  }
}