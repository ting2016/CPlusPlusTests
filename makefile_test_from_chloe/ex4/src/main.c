#include <ex_math.h>

#include <stdio.h>

int main(void) {
    double a = 10;
    double b = 5;
    printf("%f, %f\n+ = %f\n- = %f\n* = %f\n/ = %f\n",
            a, b,
            add(a,b),
            sub(a,b),
            mul(a,b),
            div(a,b));
}
