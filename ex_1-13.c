/* program to print the histogram of words */

#include <stdio.h>

#define IN 1
#define OUT 0

main()
{
        int c, i, j, state, wlength, freq;
        int nlength[20];
        int vhistogram[20];

        i = j = freq = wlength = 0;
        state = OUT;
        for (i = 0; i < 20; ++i)
                nlength[i] = 0;

        while ((c = getchar()) != EOF)
        {
                if (c == ' ' || c == '\t' || c == '\n')
                /* increment frequency when white space is encountered */
                {
                        if (state == IN)
                        {
                                state = OUT;
                                ++nlength[wlength];
                                wlength = 0;
                        }
                }
                else
                /* count wordlength until white space is encountered */
                {
                        state = IN;
                        ++wlength;
                }
        }
        /* horizontal histogram */
        printf("\nHORIZONTAL HISTOGRAM\n");
        for (i = 1; i < 20; ++i)
        {
                printf("%2d - ", i);
                for (freq = 0; freq < nlength[i]; ++freq)
                {
                        putchar('%');
                }
                putchar('\n');
        }

        /* vertical histogram (word length vs frequency bar graph)*/
        printf("\nVERTICAL HISTOGRAM\n");
        for (i = 0; i < 20; ++i)    /* initialising array for graph */
                vhistogram[i] = ' ';

        for (i = 1; i < 20; ++i)    /* frequencys */
        {
                printf("%2d", (20 - i)); /* printing number on y axis */
                for (j = 1; j < 20; ++j)    /* word lengths */
                {
                        if (nlength[j] >= (20 - i))
                        {
                                vhistogram[j] = '%';
                                putchar(' ');
                                putchar(vhistogram[j]);
                                putchar(' ');
                        }
                        else
                        {
                                vhistogram[j] = ' ';
                                putchar(' ');
                                putchar(vhistogram[j]);
                                putchar(' ');
                        }
                }
                putchar('\n');
        }
        printf(" 0");
        for (j = 1; j < 20; ++j)    /* printing number on x axis */
        {
                printf("%2d",j);
                putchar(' ');
        }
        putchar('\n');
        printf("        word length vs frequency\n");
}
