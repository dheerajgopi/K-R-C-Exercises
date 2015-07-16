#include <stdio.h>
#define MAXLINE 1000 /* max input line length */

int get_line(char line[], int maxline);

/* print the longest input line */
main()
{
    int len;        /* current line length */
    char line[MAXLINE]; /* current input line */
    char longest[MAXLINE];  /* longest line saved here */

    while ((len = get_line(line, MAXLINE)) > 0) {
        if (len > 80) {
            printf("%d, %s", len, line);
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
