#include <stdio.h>

/*convert temperature from
 * fahrenheit to celsius
 * for F = 0, 20, 40 ... 300*/

main()
{
  /* variable declarations */
  float fahr, celsius;
  float lower, upper, step;

  /* assigning values to vars */
  lower = 0;
  upper = 300;
  step = 20;

  fahr = lower;
  printf("\nFahrenheit \t Celsius\n\n"); /* heading for table */

  while (fahr <= upper) {
    celsius = 5.0*(fahr - 32.0)/9.0;
    printf("%4.0f \t\t %6.1f \n", fahr, celsius);
    fahr = fahr + step;
  }
  printf("\n");
}
