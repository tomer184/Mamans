#include <stdio.h>

/* This helper function calculates for us the number of bits of an unsigned integer. */
int int_len(void)
{
    /* x now full of unes. */
    unsigned int x = ~0;

    /* i will hold the length.*/
    int i;

    /* We loop over x, each time 'adding one zero from the left', and stoping when x is full of zeros. */
    for (i = 0; x != 0; i++)
        x = x >> 1;

    /* Returning the length. */
    return i;
}

/* This function takes an unsinged integer a and an integer b
   and perporms the rotation of b places in a. */
unsigned int my_rottate(unsigned int a, int b) {


    /* Making a right shift to a by b, then a left shift of (original) a
       by (length of int - b) and do the 'or' operator on the above two results. */ 
    return ((a >> b) | (a << (int_len() - b)));
}

/* This helper function takes an unsined integer and prints it in a binary format (base 2). */
void print_in_binary(unsigned int n)
{
    unsigned int i;
    for (i = 1 << (int_len() - 1); i > 0; i = i / 2)
        (n & i) ? printf("1") : printf("0");
}


/*
    This program performs a bit rottation on an unsingned integer from the user.
    It will print its value before and after the rotation in bases 2,8,10 and 16.
*/
int main() {

    unsigned int a;
    int b;

    /* Asking the user for input. */
    printf("Enter the decimal number to be rotated: \n");
    scanf("%u", &a);

    printf("Enter the rotation nubmer: \n");
    scanf("%d", &b);

    /* Printing before the rottation. */
    printf("Before rottation, base 2: ");
    print_in_binary(a);
    printf("\n");
    printf("Before rottation, base 8: %o\n", a);
    printf("Before rottation, base 10: %u\n", a);
    printf("Before rottation, base 16: %X\n", a);

    /* Performing the rottation. */
    a = my_rottate(a, b);

    /* Printing after the rottation. */
    printf("After rottation, base 2: ");
    print_in_binary(a);
    printf("\n");
    printf("After rottation, base 8: %o\n", a);
    printf("After rottation, base 10: %u\n", a);
    printf("After rottation, base 16: %X\n", a); 
    
	return 0;
}