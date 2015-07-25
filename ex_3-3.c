#include <stdio.h>
#define MAXLINE 1000    /* max input line length */
#define ZERO 48         /* digit 0 */
#define NINE 57         /* digit 9 */
#define UP_A 65         /* uppercase A */
#define UP_Z 90         /* uppercase Z */
#define LO_A 97         /* lowercase a */
#define LO_Z 122        /* lowercase z */

int get_line(char line[], int maxline);
void expand(char s1[], char s2[]);

/* print the longest input line */
main()
{
    int len;        /* current line length */
    char s1[MAXLINE]; /* current input line */
    char s2[MAXLINE];  /* line with escape sequence printed */

    while ((len = get_line(s1, MAXLINE)) > 0) {
        expand(s1, s2);
        printf("%s", s2);
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

void expand(char s1[], char s2[])
{
    int i, j;
    int k;

    for (i = j = 0; s1[i] != '\0'; i++) {
        if (s1[i] != '-')       /* print chars until '-' is found*/
            s2[j++] = s1[i];
        else {
            if (s1[i-1] == ' ' || s1[i+1] == ' ')
                s2[j++] = '-';
            /* if the char before '-' is a digit */
            else if (s1[i-1] >= ZERO && s1[i-1] <= NINE) {
                if (s1[i+1] >= s1[i-1] && s1[i+1] <= NINE) {
                    for (k = s1[i-1]+1; k <= s1[i+1]; k++)
                        s2[j++] = k;
                    i++;
                }
            }
            /* if it is an upper case alphabet */
            else if (s1[i-1] >= UP_A && s1[i-1] <= UP_Z) {
                if (s1[i+1] >= s1[i-1] && s1[i+1] <= UP_Z) {
                    for (k = s1[i-1]+1; k <= s1[i+1]; k++)
                        s2[j++] = k;
                    i++;
                }
            }
            /* if it is a lower case alphabet */
            else if (s1[i-1] >= LO_A && s1[i-1] <= LO_Z) {
                if (s1[i+1] >= s1[i-1] && s1[i+1] <= LO_Z) {
                    for (k = s1[i-1]+1; k <= s1[i+1]; k++)
                        s2[j++] = k;
                    i++;
                }
            }
            else {
                /* invalid shorthand notation */
                s2[j++] = '-';
            }
        }
    }
    s2[j] = '\0';
}
