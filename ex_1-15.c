#include <stdio.h>

float convert_temp(float fahr);

/* testing convert_temp function */
main()
{
    float i;

    for(i = 0; i <= 300; i = i + 20)
        printf("%3.0f %6.1f\n", i, convert_temp(i));
    return 0;
}

/* temperature conversion function */
float convert_temp(float fahr)
{
    float celsius;

    celsius = 5.0 * (fahr - 32) / 9.0;
    return celsius;
}
