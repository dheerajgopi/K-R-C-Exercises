#include <stdio.h>
#define MAXLINE 1000 /* max input line length */

int get_line(char line[], int maxline);
void escape(char s[], char t[]);
void unescape(char t[], char s[]);

/* print the longest input line */
main()
{
    int len;        /* current line length */
    char s[MAXLINE]; /* current input line */
    char t[MAXLINE];  /* line with escape sequence printed */

    while ((len = get_line(s, MAXLINE)) > 0) {
        unescape(s, t);
        printf("%s", t);
    }
    printf("\n");
    return 0;
}

/* get_line: read a line into s, return length */
int get_line(char s[], int lim)     /* use get_line instead of getline */
{
    int c, i;

    for (i=0; i < lim-1 && (c=getchar()) != EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void escape(char s[], char t[])
{
    int i;
    int j;

    for (i = j = 0; s[i] != '\0'; ++i) {
        switch (s[i]) {
        case '\t':
            t[j++] = '\\';
            t[j++] = 't';
            break;
        case '\n':
            t[j++] = '\\';
            t[j++] = 'n';
            break;
        default:
            t[j++] = s[i];
            break;
        }
    }
    t[j] = '\0';
}

/* unescape - exact opposite of escape function */
void unescape(char t[], char s[])
{
    int i, j;

    for (i = j = 0; t[i] != '\0'; i++) {
        if (t[i] != '\\')
            s[j++] = t[i];
        else
            switch (t[i++]) {
                case 'n':
                    s[j++] = '\n';
                    break;
                case 't':
                    s[j++] = '\t';
                    break;
                default:
                    s[j++] = '\\';
                    s[j++] = t[i];
                    break;
            }
    }
    s[j] = '\0';
}
