#include <stdio.h> 
#define MAXLINE 1000

int my_get_line(char *, int);

void copy(char *, char *);

/* print the longest input line */
int main(int argc, char **argv)
{
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while ((len = my_get_line(line, MAXLINE)) > 0)
    {
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }

    if (max > 0) {
        printf("%s", longest);
    }

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
