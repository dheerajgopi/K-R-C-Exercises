#include <stdio.h>

int bitcount(unsigned n);

main()
{
    unsigned n = 7;
    int ans;
    ans = bitcount(n);
    printf("%d\n", ans);
}

int bitcount(unsigned n)
{
    int b;

    for (b = 0; n != 0; n &= (n-1))
        ++b;
    return b;
}
