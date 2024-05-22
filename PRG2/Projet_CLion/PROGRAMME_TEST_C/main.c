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


#define CONCAT(a, b) a##b


int my_variable = 10;

int main() {
    int concatenated_variable = CONCAT(my_, variable);
    printf("%d\n", concatenated_variable); // Imprimera 10
    return 0;
}
