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

unsigned int get_hexadecimal_digit(unsigned int ui, int n) {

    // VOTRE CODE VIENT ICI.
    int res=0;
    unsigned int mask = 0xF;//0b1111

    for(int i = n; i>=0; --i){
        res = ui & (mask<<i);
    }

    return res;

}

int main() {

    unsigned int ui = 1234567890;
    scanf("%u", &ui);

    for(int i = 7; i >= 0; --i)
        printf("%u ", get_hexadecimal_digit(ui, i));
    printf("\n");

    return 0;
}
