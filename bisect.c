#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 16

// seq 10 99 | shuf | xargs -n 10 | sort | sed -E 's/ /, /g'

int solve(int, int);
int bisect_upper_bound(int *, int, int);
int bisect_lower_bound(int *, int, int);

int main(void)
{
    int x, result;
    int target[ARRAY_SIZE] = {  5, 10, 11, 17, 33, 39, 40, 41, 46, 53, 
                               54, 64, 75, 76, 93, 99 };
    x = 9;
    result = bisect_upper_bound(target, ARRAY_SIZE, x);

    printf("x = %d\n", x);
    printf("arr =");

    for (int i = 0; i < ARRAY_SIZE; ++i)
        printf(" %d", target[i]);

    printf("\nresult = %d\n", result);

    return 0;
}


int bisect_lower_bound(int target[], int length, int x)
{
    int lower = 0;
    int upper = length - 1;

    while (abs(upper - lower) > 1) {
        int mid = lower + upper / 2;
        if (solve(target[mid], x)) {
            lower = mid;
        } else {
            upper = mid;
        }
    }
    return lower;
}


int bisect_upper_bound(int target[], int length, int x)
{
    int lower = 0;
    int upper = length - 1;

    while (abs(upper - lower) > 1) {
        int mid = lower + upper / 2;
        if (solve(target[mid], x)) {
            lower = mid;
        } else {
            upper = mid;
        }
    }
    return upper;
}


int solve(int compared, int x)
{
    return compared == x;
}
