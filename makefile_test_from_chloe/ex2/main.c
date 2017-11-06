#include "lib.h"

#include <stdio.h>

int main(void) {
    printf("%d, %d + 2 -> %d\n", lib_1(), 5, lib_2(5));
    return 0;
}
