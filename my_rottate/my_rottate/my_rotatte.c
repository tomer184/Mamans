#include <stdio.h>

/* This helper function calculates for us the number of bits of an unsigned integer. */
int int_len(void)
{
    // x now full of unes.
    unsigned int x = ~0;

    // i will hold the length.
    int i;

    // We loop over x, each time 'adding one zero from the left', and stoping when x is full of zeros.
    for (i = 0; x != 0; i++)
        x = x >> 1;

    // Returning the length.
    return i;
}

unsigned int my_rottate(unsigned int a, int b) {
    return ((a >> b) | (a << (int_len() - b)));
}

/* This helper function takes an unsined integer and prints it in a binary format (base 2) */
void print_in_binary(unsigned int n)
{
    unsigned int i;
    for (i = 1 << int_len() - 1; i > 0; i = i / 2)
        (n & i) ? printf("1") : printf("0");
}

int main() {

    unsigned int x;

    // Asking the user for input.
    printf("Enter decimal number: \n");
    scanf_s("%u", &x);

    // Printing before the rottation.
    printf("Before rottation, base 2: ");
    print_in_binary(x);
    printf("\n");
    printf("Before rottation, base 8: %o\n", x);
    printf("Before rottation, base 10: %u\n", x);
    printf("Before rottation, base 16: %02hhX\n", x);

    // Performing the rottation.
    x = my_rottate(x, 1);

    // Printing after the rottation.
    printf("After rottation, base 2: ");
    print_in_binary(x);
    printf("\n");
    printf("After rottation, base 8: %o\n", x);
    printf("After rottation, base 10: %u\n", x);
    printf("After rottation, base 16: %02hhX\n", x); 
    
	return 0;
}