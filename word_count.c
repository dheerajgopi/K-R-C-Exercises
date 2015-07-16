/* a bare-bones version of UNIX program wc */
/* counts the number of lines, words, characters */

#include <stdio.h>

/* symbolic constants */

#define IN 1    /* inside a word */
#define OUT 0   /* outside a word */

main()
{
        int c, nl, nw, nc, state;

        state = OUT;
        nl = nw = nc = 0;

        while ((c = getchar()) != EOF)
        {
                ++nc;
                if (c == '\n')
                {
                        ++nl;
                }
                if (c == ' ' || c == '\n' || c == '\t')
                {
                        state = OUT;
                }
                else if (state == OUT)
                {
                        state = IN;
                        ++nw;
                }
        }
        printf("\nNumber of lines : %d\n", nl);
        printf("Number of words : %d\n", nw);
        printf("Number of characters : %d\n\n", nc);
}
