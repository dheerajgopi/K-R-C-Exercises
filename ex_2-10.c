#include <stdio.h>

void lower(char s[]);

main()
{
    char s[] = "abcAB";
    lower(s);
}

void lower(char s[])
{
    int i;

    for (i = 0; s[i] != '\0'; ++i)
        printf("%c", (s[i] >= 'A' && s[i] <= 'Z') ? (s[i]-'A'+'a') : s[i]);
    printf("\n");
}
