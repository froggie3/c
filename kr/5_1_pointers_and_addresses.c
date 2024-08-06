#include <stdio.h>

int main(void)
{
    int x = 1;
    int y = 2;
    int z[10];

    // ip = a pointer to int
    int *ip;

    // assigns the address of x to the var ip. 
    ip = &x; // ip points to x
    y = *ip; // y is now 1
    *ip = 0; // x is now 0
    printf("x=%d y=%d\n", x, y);

    ip = &z[0]; // ip now points to z[0]

    return 0;
}
