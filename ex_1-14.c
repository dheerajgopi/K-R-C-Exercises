/* program to print the histogram of words */

#include <stdio.h>

main()
{
        int c, i, freq;
        int alpha_len[26];

        i = freq = 0;
        for (i = 0; i < 26; ++i)
                alpha_len[i] = 0;

        while ((c = getchar()) != EOF)
        {
                if (c >= 'a' && c <= 'z')
                {
                        ++alpha_len[c - 97];
                }
        }
        /* horizontal histogram */
        printf("\nHORIZONTAL HISTOGRAM\n");
        for (i = 0; i < 26; ++i)
        {
                putchar(97 + i);
                for (freq = 0; freq < alpha_len[i]; ++freq)
                {
                        putchar('%');
                }
                putchar('\n');
        }

}
