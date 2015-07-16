#include <stdio.h>
#define MAXLINE 1000 /* max input line length */

int get_line(char line[], int maxline);
void trunc_line(char to[], char from[]);

/* print the longest input line */
main()
{
    int len;        /* current line length */
    char line[MAXLINE]; /* current input line */
    char trunc_result[MAXLINE];

    while ((len = get_line(line, MAXLINE)) > 0) {
        if (len > 0) {
            trunc_line(trunc_result, line);
            printf("%s", trunc_result);
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

/* trunc_line: truncate ' ' and '\t' */
void trunc_line(char to[], char from[])
{
    int i;
    int j;

    i = 0;
    j = 0;
    while ((to[j] = from[i]) != '\0') {
        if (from[i] == ' ' || from[i] == '\t') {
            ++i;
        }
        else {
            ++i;
            ++j;
        }
    }
}
