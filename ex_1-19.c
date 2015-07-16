#include <stdio.h>
#define MAXLINE 1000 /* max input line length */

int get_line(char line[], int maxline);
void reverse(char s[]);

/* print the longest input line */
main()
{
    int len;        /* current line length */
    char line[MAXLINE]; /* current input line */

    while ((len = get_line(line, MAXLINE)) > 0) {
        if (len > 0) {
            reverse(line);
            printf("%s", line);
        }
    }
    return 0;
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

/* reverse: reverse input string */
void reverse(char s[])
{
    int i, j;
    char temp;

    i = j = 0;

    while(s[i] != '\0')         /* find end of string */
        ++i;
    --i;                        /* omit '\0' */
    if (s[i] == '\n')           /* '\n' to be placed at end */
        --i;

    while(j < i) {
        temp = s[j];
        s[j] = s[i];
        s[i] = temp;
        --i;
        ++j;
    }
}
