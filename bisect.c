#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20 

// seq 10 99 | shuf | xargs -n 10 | sort | sed -E 's/ /, /g'

int solve(int, int);
int upper_bound(int *, int, int);
int lower_bound(int *, int, int);

int main(void)
{
    int target[ARRAY_SIZE] = {  5, 10, 11, 13, 17, 20, 21, 24, 30, 39, 
                               40, 41, 46, 53, 54, 64, 75, 76, 93, 99 };
    int x = 9;

    printf("x = %d\n", x);
    printf("arr =");

    for (int i = 0; i < ARRAY_SIZE; ++i)
    {
        printf(" %d", target[i]);
    }

    printf("\nfound = %d\n", upper_bound(target, ARRAY_SIZE, x));

    return 0;
}


int lower_bound(int target[], int length, int x)
{
    int lower = 0;
    int upper = length - 1;

    while (abs(upper - lower) > 1)
    {
        int mid = lower + upper / 2;

        if (solve(target[mid], x))
        {
            lower = mid;
        }
        else
        {
            upper = mid;
        }
    }

    return lower;
}


int upper_bound(int target[], int length, int x)
{
    int lower = 0;
    int upper = length - 1;

    while (abs(upper - lower) > 1)
    {
        int mid = lower + upper / 2;

        if (solve(target[mid], x))
        {
            lower = mid;
        }
        else
        {
            upper = mid;
        }
    }

    return upper;
}


int solve(int compared, int x)
{
    return compared == x;
}

