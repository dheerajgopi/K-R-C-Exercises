#include <stdio.h>
#define TAB_WIDTH 4
#define MAXLINE 1000

int get_line(char line[], int maxline);
void detab(char s[]);

main()
{
    int len;
    char line[MAXLINE];

    while ((len = get_line(line, MAXLINE)) > 0) {
        if (len > 0) {
            detab(line);
        }
    }
}

/* get_line: read a line into s, return length */
int get_line(char s[], int lim)     /* use get_line instead of getline */
{
    int c, i;

    for (i=0; i < lim-2 && (c=getchar()) != EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void detab(char s[])
{
    int i, pos;

    i = 0;
    while(s[i] != '\0') {
        if (s[i] == '\t'){
            pos = TAB_WIDTH - (i%TAB_WIDTH);
            while(pos > 0) {
                putchar(' ');
                --pos;
            }
            ++i;
        }
        else {
            putchar(s[i]);
            ++i;
        }
    }
}
