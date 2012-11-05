/**
 * This work is licensed under the Creative Commons Attribution 3.0 Unported 
 * License. To view a copy of this license, visit 
 * http://creativecommons.org/licenses/by/3.0/ or send a letter to Creative 
 * Commons, 444 Castro Street, Suite 900, Mountain View, California, 94041, USA.
 */

/* StackOverflow reference:
 * http://stackoverflow.com/questions/12530996/struct-attribute-inheritance-in-c
 */


/* offsetof example */
#include <stdio.h>
#include <stddef.h>

struct mystruct {
  char singlechar;
  char arraymember[10];
  char anotherchar;
}__attribute__((__packed__));

struct B : mystruct {
   int x;
};

int main ()
{
  printf ("offsetof(mystruct,singlechar) is %ld\n",offsetof(B,singlechar));
  printf ("offsetof(mystruct,arraymember) is %ld\n",offsetof(mystruct,arraymember));
  printf ("offsetof(mystruct,anotherchar) is %ld\n",offsetof(mystruct,anotherchar));
  
  return 0;
}

#if 0
#include <stdio.h>
#include <stddef.h>

#include <list>
using std::list;

struct A {
    char a;
    unsigned short b;
}__attribute__((__packed__));

struct B : A {
    list<int>c;
};

/*
struct C : A {
    list<int>c;
}__attribute__((__packed__));
*/

int main() {
   printf("sizeof(B): %lu\n", sizeof(B)); 
//   printf("sizeof(C): %lu\n", sizeof(C)); 

   printf("%lu\n", offsetof(A, b));
   printf("%lu\n", offsetof(B, b));
//   printf("%lu\n", offsetof(C, b));

   return 0;
}

#endif
