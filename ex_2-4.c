#include <stdio.h>
#define MAXLINE 1000
#define  YES 1
#define NO 0

void squeeze(char s1[], char s2[]);
int get_line(char line[], int maxline);

main()
{
    int len;        /* current line length */
    char s1[MAXLINE]; /* current input line */
    char s2[MAXLINE] = "efgo";

    while ((len = get_line(s1, MAXLINE)) > 0) {
        squeeze(s1, s2);
        printf("%s\n", s1);
    }

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

void squeeze(char s1[], char s2[])
{
    int i, j, k;
    int match;

    for(i = j = 0; s1[i] != '\0'; i++) {
        match = NO;
        for(k = 0; s2[k] != '\0'; k++) {
            if(s1[i] == s2[k]) {
                match = YES;
                break;
            }
        }
        if(!match)
            s1[j++] = s1[i];
    }
    s1[j] = '\0';
}
