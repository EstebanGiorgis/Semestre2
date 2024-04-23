#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <getopt.h>
#include <ctype.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>



#define MAX_VIES 5
#define MAX_LETTRES 26

int main() {
    char mot[] = "Carambar";
    char motCache[strlen(mot) + 1];
    int vies = MAX_VIES;
    char triedLetters[MAX_LETTRES] = {0};
    int i, j, trouve;
    char guess[20];

    // Initialisation du mot caché avec des tirets
    for (i = 0; i < strlen(mot); i++) {
        motCache[i] = '-';
    }
    motCache[i] = '\0';

    while (vies > 0) {
        printf("Tried letters: ");
        for (i = 0; i < MAX_LETTRES; i++) {
            if (triedLetters[i] != 0) {
                printf("%c", triedLetters[i]);
            }
        }
        printf("\n");

        printf("%s\n", motCache);
        printf("Lifes: %d\n", vies);
        printf("Guess a letter or a word: ");
        scanf("%20s", guess);

        if (strlen(guess) == 1 && isalpha(guess[0])) {
            char lettre = toupper(guess[0]);

            if (strchr(triedLetters, lettre) != NULL) {
                printf("%c has already been tried.\n", lettre);
                continue;
            }

            triedLetters[strlen(triedLetters)] = lettre;
            trouve = 0;
            // Vérification si la lettre est présente dans le mot
            for (i = 0; i < strlen(mot); i++) {
                if (toupper(mot[i]) == lettre) {
                    motCache[i] = mot[i];
                    trouve = 1;
                }
            }
            if (trouve) {
                int occurences = 0;
                for (i = 0; i < strlen(mot); i++) {
                    if (toupper(mot[i]) == lettre) {
                        occurences++;
                    }
                }
                printf("There is %d occurrence(s) of %c in the word!\n", occurences, lettre);

                // Vérification si le mot a été deviné entièrement
                if (strcmp(mot, motCache) == 0) {
                    printf("GG !! You win \\o/\n");
                    return 0;
                }
            } else {
                printf("%c is not in the word...\n", lettre);
                vies--;
            }
        } else if (strlen(guess) == strlen(mot) && isalpha(guess[0])) {
            if (strcmp(guess, mot) == 0) {
                printf("GG !! You win \\o/\n");
                return 0;
            } else {
                printf("%s isn't the word !\n", guess);
                vies -= 2;
            }
        } else {
            printf("%s is not a valid guess.\n", guess);
            vies -= 2;
            continue;
        }

        if (vies <= 0) {
            printf("You loose... The word was %s.\n", mot);
            return 0;
        }

        // Nettoyage du buffer d'entrée
        while (getchar() != '\n');
    }

    return 0;
}
