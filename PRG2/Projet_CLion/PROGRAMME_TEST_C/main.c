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
#include <stdio.h>
#include <stdint.h>


int main(){

    char *tab;

    tab = (char *) malloc(4*sizeof(char));

    if(tab == NULL){
        printf("Erreur nim %d", errno);
        perror("Erreur nim ");
    }
}