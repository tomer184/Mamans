#include <stdio.h>

/* The maximum string size. */
#define MAXSIZE 80

/* This function gets a string as an argument and shortens ascending sequences of the alphabet in that string. */
void sequences(char string[]) {

    /* Calulating the length of the string */
    int string_length = 0;
    while (string[string_length] != '\0')
        string_length++;

    /* Iterating over the string. */
    int i;
    for (i = 0; i < string_length - 2; i++) {

        /* If we found a ascending sequence of 3 aplhabethic characters. */
        if (string[i + 1] - string[i] == 1 && string[i + 2] - string[i + 1] == 1 &&
            ((string[i] >= 65 && string[i] <= 98) || (string[i] >= 97 && string[i] <= 122))) {

            /* Will be out iterator and will help us in the removing and shifting of the characters. */
            int j = i + 1;

            /* Holds the number of characters removed from the sequence. */
            int number_of_removes = 0;

            /* Removing the non-edges characters in the sequence. */
            while (string[j + 1] - string[j] == 1)
            {
                string[i + 2] = string[j + 1];
                j++;
                number_of_removes++;
            }

            /*Adding the dash. */
            string[i + 1] = '-';

            /* Updating I. */
            i = j;

            /* j in now at the first character after the sequnece. */
            j++;

            /* Shifting the whole string to fill up the space after removing. */
            while (string[j])
            {
                string[j - number_of_removes + 1] = string[j];
                j++;
            }

            /* Updating the length. */
            string_length -= (number_of_removes - 1);

            /* Terminating the string. */
            string[string_length] = '\0';
        }
    }
}


/*
    This program asks the user for input and gets a string of maximum 80 letters from the abc (upper and lower case).
    Then, the program finds ascending sequences of three of more letter of the abc,
    and shortenes them to three characters: the first letter in the sequence, a dash, and the last letter in the sequence.
    Then the program will print the string after the changes and exit.
*/
int main() {
    char string[MAXSIZE];

    /* Asking the user for input. */
    printf("Enter a string with a maximum of %d characters: ", MAXSIZE);
    scanf("%s", string);

    printf("Your before string: %s\n", string);
    sequences(string);
    printf("Your after string: %s", string);
    return 0;
}