#include <stdio.h>

/* counting number of chars */

main()
{
        double nc;

        for (nc = 0; getchar() != EOF; ++nc)
                ;   /* for loop body is empty */
        printf("%.0f\n", nc);

}        
