#include <stdio.h>

/* copy input to output */

main()
{
        int c;
        while ((c = getchar()) != EOF) {
                putchar(c);
        }        
        printf("%d\n", c); /* to print value of EOF */
        return 0;
}
