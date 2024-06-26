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

int main(int argc, char** argv){

    int cap = 5;

    int* tab = NULL;
    tab = (int *) malloc(cap * sizeof(int));
    if(!tab){
        return -1;
    }

    int nbr;

    printf("entre \n");
    scanf("%d", &nbr);
    int i=-1;
    while(i!=9){
        i++;
        tab[i] = nbr;
        scanf("%d", &nbr);

    }
    printf("\n");
    printf("\n");
    printf("\n");
    for(int j=0; j<i;j++){
        printf("%d\n", tab[j]);
    }


    out:
    free(tab);

}