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


#pragma pack(push, 1)
struct MyStruct {
    char a;
    int b;
};
#pragma pack(pop)


int main(){

    struct MyStruct m;

    m.b=256;

    printf("%d", m.b);
    return 0;
}