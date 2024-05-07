/*
===============================================================================
File:                   config.h
Course:                 PRG2
Year:                   2024
Author:                 Basile Cuneo
Creation Date:          03.04.2024
Modification Author:    ROCHA FERREIRA Mário André
Modification Date:      03.05.2024
Version:                1.0
Description:            In this file the display format configuration is done
                        through the YAML macro (0 for text, 1 for YAML)
===============================================================================
*/

#ifndef CONFIG_H

#define CONFIG_H

#include "ship.h"
#include <stdio.h>

#if defined(_WIN32) || defined(_WIN64)
#define NEWLINE "\r\n"
#else
#define NEWLINE "\n"
#endif

#define MAX_BUFFER_SIZE 256

#define SUCCESS 0
#define MALLOC_ERROR -1
#define UNKNOWN_ASTROMECH_TYPE -2
#define UNKNOWN_SHIP_TYPE -3

#endif