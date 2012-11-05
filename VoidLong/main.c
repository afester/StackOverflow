/**
 * This work is licensed under the Creative Commons Attribution 3.0 Unported 
 * License. To view a copy of this license, visit 
 * http://creativecommons.org/licenses/by/3.0/ or send a letter to Creative 
 * Commons, 444 Castro Street, Suite 900, Mountain View, California, 94041, USA.
 */

/* StackOverflow reference:
 * http://stackoverflow.com/questions/12819087/how-to-force-c-compiler-to-define-function-with-argument-long-when-declared-with
 */


int funct(int var1, int var2, void* usr_arg1);

int funct(int var1, int var2, void* usr_arg1) {
    long usr_arg = (long) usr_arg1;
    /* code goes here;*/
    return usr_arg / 1234;
}


int main() {
    int* ptr = (int*) 0x123456;
    funct(1, 2, ptr);
    return 42;
}

