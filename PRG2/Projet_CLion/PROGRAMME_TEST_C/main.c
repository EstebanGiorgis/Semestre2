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


// Fonction pour vérifier si une chaîne contient le motif "subcmd"
int contientMotif(const char *chaine, const char *motif) {
    return strstr(chaine, motif) != NULL;
}

// Fonction principale
int main() {
    // Tableau de chaînes de caractères
    const char const *chaines[4] = {
        "commande1 subcmd",
        "autre commande",
        "encore subcmd ici",
        "dernière chaîne"
    };

    const char *motif = "subcmd";
    int i;

    // Parcours du tableau
    for (i = 0; i < sizeof(chaines) / sizeof(chaines[0]); ++i) {
        if (contientMotif(chaines[i], motif)) {
            printf("La chaîne \"%s\" contient le motif \"%s\".\n", chaines[i], motif);
        }
    }

    return 0;
}