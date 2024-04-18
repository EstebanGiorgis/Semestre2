#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <getopt.h>
#include <ctype.h>
#include <unistd.h>

#define MAX_VIES 5
#define MAX_TAILLE_MOT 20

int main() {
    char mot_secret[MAX_TAILLE_MOT];
    char mot_cache[MAX_TAILLE_MOT];
    char lettre;
    int vies = MAX_VIES;
    int longueur_mot;
    int i, trouve;

    // Demander au joueur de saisir le mot à deviner
    printf("Entrez le mot a deviner : ");
    scanf("%s", mot_secret);

    // Cacher le mot à deviner avec des tirets
    longueur_mot = strlen(mot_secret);
    for (i = 0; i < longueur_mot; i++) {
        mot_cache[i] = '-';
    }
    mot_cache[longueur_mot] = '\0';

    // Boucle principale du jeu
    while (vies > 0 && strcmp(mot_secret, mot_cache) != 0) {
        printf("\nMot a deviner : %s\n", mot_cache);
        printf("Vies restantes : %d\n", vies);
        printf("Entrez une lettre : ");
        scanf(" %c", &lettre); // Notez l'espace avant %c pour consommer les caractères blancs

        // Vérifier si la lettre est dans le mot secret
        trouve = 0;
        for (i = 0; i < longueur_mot; i++) {
            if (mot_secret[i] == lettre) {
                mot_cache[i] = lettre;
                trouve = 1;
            }
        }

        // Si la lettre n'est pas trouvée, réduire le nombre de vies
        if (!trouve) {
            vies--;
            printf("Incorrect !\n");
        }
    }

    // Afficher le résultat du jeu
    if (strcmp(mot_secret, mot_cache) == 0) {
        printf("Felicitation ! Vous avez devine le mot : %s\n", mot_secret);
    } else {
        printf("Desole, vous avez perdu. Le mot etait : %s\n", mot_secret);
    }

    return 0;
}