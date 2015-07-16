#include <stdio.h>
#include <math.h>
#define YES 1
#define NO 0

int htoi(char s[]);

main()
{
    char i[] = "afd";
    int x;
    x = htoi(i);
    printf("%d\n", x);
}

int htoi(char s[])
{
    int hexdigit, i, n;
    int invalid;

    i = 0;
    invalid = NO;
    n = 0;
    for(i = 0; s[i] != '\0'; ++i) {
        if (s[i] >= '0' && s[i] <= '9')
            hexdigit = s[i] - '0';
        else if (s[i] >= 'a' && s[i] <= 'f')
            hexdigit = s[i] - 'a' + 10;
        else if (s[i] >= 'A' && s[i] <= 'F')
            hexdigit = s[i] - 'A' + 10;
        else {
            printf("Invalid HEX!!!");
            invalid = YES;
            break;
        }
        n = 16 * n + hexdigit;
    }
    if (!invalid)
        return n;
    else
        return 0;
}
