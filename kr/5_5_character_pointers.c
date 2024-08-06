#include <stdio.h>
#include <string.h>
#define MAX_SIZE 1000


/* copt t to s (array subscript version) */
void strcpy(char *s, char* t)
{
    int i;

    i = 0;
    while ((s[i] = t[i]) != '\0')
    {
        i++;
    }
}

/* copt t to s (pointer version) */
void strcpy(char *s, char* t)
{
    int i;

    i = 0;
    while ((*s = *t) != '\0')
    {
        s++;
        t++;
    }
}

int main(void)
{
    /*
    char dst[MAX_SIZE] = { 0 };
    char src[] = "I am a string";
    memcpy(&dst, &src, MAX_SIZE);
    printf("%s\n", dst);
    */

    char amessage[] = "now is the time";
    char *pmessage[] = "now is the time";

    return 0;

