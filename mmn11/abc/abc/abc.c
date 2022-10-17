#include <stdio.h>
#include <string.h>

#define MAXSIZE 80

void sequences(char string[]) {

    // Calulating the length of the string
    int string_length = 0;
    while (string[string_length] != '\0')
        string_length++;

    // Iterating over the string.
    for (int i = 0; i < string_length - 2; i++) {

        // If we found a sequence of 3
        if (string[i + 1] - string[i] == 1 && string[i + 2] - string[i + 1] == 1) {

            // Will be out iterator and will help us in the removing and shifting of the characters.
            int j = i + 1;

            // Holds the number of characters removed from the sequence.
            int number_of_removes = 0;

            // Removing the non-edges characters in the sequence.
            while (string[j + 1] - string[j] == 1)
            {
                string[i + 2] = string[j + 1];
                j++;
                number_of_removes++;
            }

            //Adding the dash.
            string[i + 1] = '-';

            // Updating I.
            i = j;

            // j in now at the first character after the sequnece.
            j++;

            // Shifting the whole string to fill up the space after removing.
            while (string[j])
            {
                string[j - number_of_removes + 1] = string[j];
                j++;
            }

            // Updating the length.
            string_length -= (number_of_removes - 1);

            // Terminating the string.
            string[string_length] = '\0';
        }
    }
}


/**
    This program asks the user for input and gets a string of maximum 80 letters from the abc (upper and lower case).
    Then, the program finds ascending sequences of three of more letter of the abc,
    and shortenes them to three characters: the first letter in the sequence, a dash, and the last letter in the sequence.
    Then the program will print the string after the changes and exit.
*/
int main() {
    char string[MAXSIZE];
    printf("Enter string of only a-z A-Z with a maximum of 80 characters: ");
    fgets(string, MAXSIZE, stdin);
    printf("Your before string: %s", string);
    sequences(string);
    printf("Your after string: %s", string);
    return 0;
}