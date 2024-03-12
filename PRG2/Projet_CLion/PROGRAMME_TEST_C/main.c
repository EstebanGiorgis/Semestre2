/*
===============================================================================
File:                   battleship.c
Course:                 PRG2
Year:                   2024
Author:                 Basile Cuneo
Creation Date:          15.01.2024
Modification Author:    Esteban Giorgis
Modification Date:      05.04.24
Version:                1.0
Description:            This is the file in which exercice 1 must be implemented
                        User should be able to play a simplified battleship game
===============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE  10
#define MAX_LIFES_NBR  5
#define MAX_SHIPS_NBR  3

#define MAX_POSITION  9
#define MIN_POSITION  0

#define NO_BOAT 0
#define ALREADY_ATTACKED 1
#define HIT 2



void action_to_do(int *array_board, int *ptr_lifes_remaining, int *ptr_ships_remaining){
    switch(*array_board){
        case 0: printf("MISS\n");*array_board=ALREADY_ATTACKED;--*ptr_lifes_remaining;break;
        case 1: printf("Already attacked this position\n");break;
        case 2: printf("HIT\n");--*ptr_ships_remaining;*array_board=ALREADY_ATTACKED;break;
        default: printf("Nothing to do");
    }
}


int main(int argc, char *argv[]) {
    int array_board[BOARD_SIZE] = {NO_BOAT};
    int lifes_remaining = MAX_LIFES_NBR;
    int ships_remaining = MAX_SHIPS_NBR;
    int chosen_position = 0;

    srand(time(NULL));


    int last_random=0;
    int random_pos =0;
    for(size_t i = 0; i<MAX_SHIPS_NBR;++i){
        last_random = random_pos;
        do{
            random_pos = rand() % BOARD_SIZE;
        }while(last_random==random_pos || array_board[random_pos] == HIT);
        array_board[random_pos]=HIT;
    }

    while(lifes_remaining > 0 && ships_remaining > 0){
        do{
            printf("%d lifes remaining, %d ships remaining\n", lifes_remaining, ships_remaining);
            printf("Please select a position to attack between %d and %d!\n", MIN_POSITION, MAX_POSITION);
            scanf("%d", &chosen_position);
        }while(chosen_position < MIN_POSITION || chosen_position > MAX_POSITION);


        switch(chosen_position){
            case 0:
                action_to_do(&array_board[0], &lifes_remaining, &ships_remaining);break;

            case 1:
                action_to_do(&array_board[1], &lifes_remaining, &ships_remaining);break;

            case 2:
                action_to_do(&array_board[2], &lifes_remaining, &ships_remaining);break;

            case 3:
                action_to_do(&array_board[3], &lifes_remaining, &ships_remaining);break;

            case 4:
                action_to_do(&array_board[4], &lifes_remaining, &ships_remaining);break;

            case 5:
                action_to_do(&array_board[5], &lifes_remaining, &ships_remaining);break;

            case 6:
                action_to_do(&array_board[6], &lifes_remaining, &ships_remaining);break;

            case 7:
                action_to_do(&array_board[7], &lifes_remaining, &ships_remaining);break;

            case 8:
                action_to_do(&array_board[8], &lifes_remaining, &ships_remaining);break;

            case 9:
                action_to_do(&array_board[9], &lifes_remaining, &ships_remaining);break;

            default: printf("NOTHING");
        }

    }

    if(lifes_remaining <= 0){
        printf("YOU LOST");
    }else{
        printf("YOU WON");
    }


    return EXIT_SUCCESS;
}