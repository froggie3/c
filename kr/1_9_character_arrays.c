#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

#define MAXLINE 1000

int my_get_line(char *, int);

void copy(char *, char *);

/* print the longest input line */
int main(void)
{
    size_t n = 0;
    //ssize_t lineptr = NULL; 
    char *lineptr = NULL; 

    int len, max = 0;
    char line[MAXLINE];
    char longest[MAXLINE];

    while ((len = getline(&lineptr, &n, stdout)) != -1)
    {
        printf("%s", lineptr);
        if (len > max) {
            max = len;
            memcpy(longest, line, len);
            // copy(longest, line);
        }
    }

    if (max > 0) {
        printf("%s", longest);
    }

    free(lineptr);

    return 0;
}

// returns the number of characters at current line
int my_get_line(char s[], int lim)
{
    int i, c;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        s[i] = c;
    }

    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';

    return i;
}

void copy(char to[], char from[])
{
    for (int i = 0; (to[i] = from[i]) != '\0'; ++i)
        ;
}
