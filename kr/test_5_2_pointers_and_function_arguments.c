#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define BUFSIZE 100
#define MAXVAL 100

void push(double);

double pop(void);


/* next free stack position */
int sp = 0;

/* value stack */
double val[MAXVAL]; 



/* reverse Polish calculator */
int main(void) 
{
    char c;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\n' || c == '\t')
        {
            continue;
        }
        else if ( c == 'p' ) {
            pop();
        }
        else if ( isdigit(c) )
        {
            push( atof( &c ) );
        }
    }

    return 0;
}

/* push: push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL)
    {
        val[sp++] = f;
    }
    else
    {
        printf("error: stack full, cannot push %g\n", f);
    }
    printf("current stack position at: %d\n", sp);
}


/* pop: pop and return top value from stack */
double pop(void)
{
    if (sp > 0)
    {
        --sp;
        printf("current stack position at: %d\n", sp);
        return val[sp];
    }
    else
    {
        printf("error: stack empty\n");

        return 0.0;
    }
}

