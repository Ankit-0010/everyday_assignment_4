#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char generateRandomChar() {
    int choice = rand() % 2;
    if (choice == 0) {
        return '0' + rand() % 10;
    } else {
        return 'X' + rand() % 6;
    }
}

int main() {
    srand(time(0)); // Seed the random number generator with current time
    int i, j;

    for (i = 0; i < 50; i++) {
        int length = 3 + rand() % 8; // here we are generating random character of lenth 3 to 10 characters.
        char alphanumericString[11]; // 10 + 1 for null terminator

        // Generate random alphanumeric string
        for (j = 0; j < length; j++) {
            alphanumericString[j] = generateRandomChar();
        }
        alphanumericString[length] = '\0'; // Null-terminate

        // Calculating the highest base
        int highestBase = 0;
        for (j = 0; j < length; j++) {
            int base;
            if (alphanumericString[j] >= '0' && alphanumericString[j] <= '9') {
                base = alphanumericString[j] - '0';
            } else {
                base = alphanumericString[j] - 'A' + 10;
            }
            if (base > highestBase) {
                highestBase = base;
            }
        }

        // Print the result
        printf("The Highest Base of %s is %d\n", alphanumericString, highestBase + 1);
    }

    return 0;
}
