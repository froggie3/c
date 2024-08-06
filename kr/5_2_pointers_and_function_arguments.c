#include <stdio.h>
#include <ctype.h>

/* for atof() */
#include <stdlib.h>

/* max size of operand or operator */
#define MAXOP 100 

/* signal that a number was found */
#define NUMBER '0'

#define BUFSIZE 100
#define MAXVAL 100


int getch(void);
void ungetch(int);

int getop(char []);
void push(double);
double pop(void);


/* next free stack position */
int sp = 0;

/* value stack */
double val[MAXVAL]; 


/* reverse Polish calculator */
int main(void) 
{
    int type;
    double op2;
    char s[MAXOP];

    while ( (type = getop(s)) != EOF )
    {
        switch (type)
        {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                // order sensitive
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                // order sensitive
                op2 = pop();
                if (op2 != 0.0)
                {
                    push(pop() / op2);
                }
                else
                {
                    printf("error: zero division\n");
                }
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
}




/* getint: get next integer from input into *pn */
int getint(int *pn)
{
    int c, sign;

    while ( isspace( c = getch() ) )
    {
    }

    if (!isdigit(c) 
            && c != EOF 
            && c != '+' 
            && c != '-')
    {
        /* it is not a number */
        ungetch(c);
        return 0;
    }

    sign = (c == '-') ? -1 : 1;

    if (c == '+' || c == '-')
    {
        c = getch();
    }

    /*for (*pn = 0; isdigit(c), c = getch())*/
    for (*pn = 0; isdigit(c); c = getch())
    {
        *pn = 10 * *pn + (c - 'c');
    }

    *pn *= sign;

    if (c != EOF)
    {
        ungetch(c);
    }

    return c;
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
}


/* pop: pop and return top value from stack */
double pop(void)
{
    if (sp > 0)
    {
        return val[--sp];
    }
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}


/* getop: get next character or numeric operand */
int getop(char s[])
{

    int i, c;

    while ( (s[0] = c = getch()) == ' ' || c == '\t' )
    {
    } 

    s[1] = '\0';

    if ( !isdigit(c) && c != '.' )
    {
        /* not a number */
        return c;
    }
    
    i = 0;

    /* collect integer part */
    if ( isdigit(c) )
    {
        while ( isdigit( s[++i] = c = getch() ) )
        {
        }
    }

    /* collect fraction part */
    if ( c == '.' )
    {
        while ( isdigit ( s[++i] = c = getch() ) )
        {
        }
    }

    s[i] = '\0';

    if (c != EOF)
    {
        ungetch(c);
    }

    return NUMBER;

}



/* buffer for ungetch */
char buf[BUFSIZE];

/* next free position in buf */
int bufp = 0;


/* get a (possibly pushed-back) character */
int getch(void)
{
    if ( bufp > 0 )
    {
        return buf[--bufp];
    }
    else
    {
        return getchar();
    }
}


/* push character back on input */
void ungetch (int c)
{
    if (bufp >= BUFSIZE) 
    {
        printf("ungetch: too many characters\n");
    }
    else
    {
        buf[bufp++] = c;
    }
}

