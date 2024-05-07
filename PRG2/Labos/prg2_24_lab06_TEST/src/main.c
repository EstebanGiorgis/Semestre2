/*
===============================================================================
File:                   main.c
Course:                 PRG2
Year:                   2024
Author:                 Basile Cuneo
Creation Date:          03.04.2024
Modification Author:    ROCHA FERREIRA Mário André
Modification Date:      03.05.2024
Version:                1.0
Description:            This is the file in which the fleet must be created and
                        informations about the fleet must then be displayed in a
                        YAML or text format depending on config.h settings.
===============================================================================
*/

#include "config.h"
#include "ship.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

/**
 * @brief check that the number of ships entered by the user is correct
 * @param buffer number of ships entered by user
 * @return bool the return code
 */
bool ships_nbr_check(char *buffer) {
    printf("Please select the number of ships for your fleet : ");
    fgets(buffer, MAX_BUFFER_SIZE, stdin);

    if (atoi(buffer)<0) {
        return false;
    }
    return true;
}



int main(int argc, char *argv[]) {
  struct fleet fleet;
  int rc = 0;
  char buffer[MAX_BUFFER_SIZE];

  fleet.nb_ships = 0;

  while(ships_nbr_check(buffer) != 1){
      printf("Invalid number\n");
  }

  fleet.ship_capacity = atoi(buffer);

  fleet.ships = malloc(fleet.ship_capacity * sizeof(struct ship));

  if (fleet.ships == NULL) {
    goto CLEANUP;
  }


  for (int i = 0; i < fleet.ship_capacity; i++) {
    printf("Ship number %d:\n", i + 1);

    rc = add_ship_to_fleet(&fleet);
    if (rc < 0) {
      goto CLEANUP;
    }

    printf("\n");
  }

  for (int i = 0; i < fleet.nb_ships; i++) {
#if !YAML_SUPPORT
    printf("Ship number %d: \n", i + 1);
#endif
    display_ship_infos(&fleet.ships[i]);
#if !YAML_SUPPORT
    printf("\n");
#endif
  }

CLEANUP:
  cleanup_fleet(&fleet);

  return EXIT_SUCCESS;
}
