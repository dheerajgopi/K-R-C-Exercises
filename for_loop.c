#include <stdio.h>

/*defining symbolic constants for upper and lower limits*/
#define LOWER   0
#define UPPER   300
#define STEP    20

/*temperature convertion using for loop*/
main()
{
  int fahr;

  for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
    printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr - 32));
}
