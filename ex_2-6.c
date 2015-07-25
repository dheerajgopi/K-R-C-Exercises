#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);

main()
{
    unsigned a = 55;
    unsigned b = 60;
    int p = 3;
    int n = 2;
    int ans;
    ans = setbits(a, p, n, b);
    printf("%d\n", ans);
}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    return ((~(~0 << n) & y) << (p+1-n)) |
        (~(~(~0 << n) << (p+1-n)) & x);
}
