#include <stdio.h>

int main() {
    printf("Starting the program\n");

    int value = 10;
    printf("Value is %d\n", value);

    // Add a flush to ensure output appears immediately
    fflush(stdout);

    printf("Ending the program\n");
    return 0;
}
