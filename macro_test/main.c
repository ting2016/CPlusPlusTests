#include <stdio.h>

#define BLURT printf ("This is line %d of file %s (function %s)\n",\
                      __LINE__, __FILE__, __func__)

void silly_function ()
{
    BLURT;
}

int main ()
{
    BLURT;
    silly_function ();
    return 0;
}
