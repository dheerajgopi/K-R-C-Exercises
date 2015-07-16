#include <stdio.h>

/* program to count blanks, tabs and newlines */

main()
{
        int c, flag;

        while((c = getchar()) != EOF) {
                flag = 0;
                if (c == '\\'){
                        putchar('\\');
                        putchar('\\');
                        flag = 1;
                }
                if (c == '\t'){
                        putchar('\\');
                        putchar('t');
                        flag = 1;
                }
                if (c == '\b'){
                        putchar('\\');
                        putchar('b');
                        flag = 1;
                }
                if (flag == 0){
                        putchar(c);
                }
        }
}        
