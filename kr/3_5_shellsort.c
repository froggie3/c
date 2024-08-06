#include <stdio.h>
#define MAX_SIZE 10

void shellsort(int *, int);

int main(void)
{
    int a[MAX_SIZE] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
    shellsort(a, MAX_SIZE);
    printf("arr =");
    for (int i = 0; i < MAX_SIZE; ++i)
    {
        printf(" %d", a[i]);
    }
    printf("\n");

    return 0;
}

void shellsort(int v[], int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            for (int j = i - gap; (j >= 0) && (v[j] > v[j + gap]); j -= gap)
            {
                int temp = v[j];
                v[j] = v[j + gap];
                v[j + gap] = temp;
            }
        }
    }
}

