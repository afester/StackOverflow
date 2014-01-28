/**
 * This work is licensed under the Creative Commons Attribution 3.0 Unported 
 * License. To view a copy of this license, visit 
 * http://creativecommons.org/licenses/by/3.0/ or send a letter to Creative 
 * Commons, 444 Castro Street, Suite 900, Mountain View, California, 94041, USA.
 */

/* StackOverflow reference:
 * http://stackoverflow.com/questions/12911723/qt-qstringtodouble-produces-inexact-results
 */

#include <stdio.h>


main() {
    int integ = 294;
    int fraction = 4;	// assumption: one fractional digit

    int i = integ * 100 + (fraction * 100) / 10;
   printf("(29440) %d\n", i);

#if 0
   double d = 294.4;
   int i = (double) (d * 10.0);
   int i2 = (double) (d * 100.0);
   int i3 = (double) (d * 1000.0);

   printf("%lf * 10 = %d\n", d, i);
   printf("%lf * 100 = %d\n", d, i2);
   printf("%lf * 1000 = %d\n", d, i3);
#endif
}
