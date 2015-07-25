#include <stdio.h>

unsigned invert(unsigned x, int p, int n);

main()
{
    unsigned a = 55;
    int p = 3;
    int n = 2;
    int ans;
    ans = invert(a, p, n);
    printf("%d\n", ans);
}

unsigned invert(unsigned x, int p, int n)
{
    return x ^ (~(~0 << n) << (p+1-n));
}
