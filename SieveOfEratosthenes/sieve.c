/**
 * This work is licensed under the Creative Commons Attribution 3.0 Unported 
 * License. To view a copy of this license, visit 
 * http://creativecommons.org/licenses/by/3.0/ or send a letter to Creative 
 * Commons, 444 Castro Street, Suite 900, Mountain View, California, 94041, USA.
 */

 /* StackOverflow reference:
  * http://stackoverflow.com/questions/16185910/programm-crash-case-of-too-large-max-value
  */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define MAX 100

int Sieb_des_Eratosthenes() {
    unsigned int i, j;
    char *array;

    array = calloc((MAX + 1) * sizeof(*array), 1);
    if (array==NULL) {
       printf("Error allocating memory!\n");
       return -1; /* return with failure */
    }

    for(i = 2; i <= sqrt(MAX); i++) {
       if(array[i] == 0) { /* "true" */
	   /* all multiples of the current value are not prime numbers */
           for(j = i*i; j <= MAX; j += i) { /* i must be <= 65535 in order to avoid overflow on i^2 */
                 array[j] = 1;	/* "false" */
           }      
       }
    }

    for(i = 2; i <= MAX; i++) {
	if (array[i] == 0) {
		printf("Is prime: %d\n", i);
	}
    }

    return 0;
}

int main() {
    Sieb_des_Eratosthenes();
    return 0;
}
