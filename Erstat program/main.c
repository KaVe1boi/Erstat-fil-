#include <stdio.h>
#include <string.h>

int main() {
    char input[1000];  // Antager en maksimal input strenglængde på 1000 tegn
    char search[100];
    char replace[100];

    // Indtast strengen
    printf("Indtast en streng: ");
    fgets(input, sizeof(input), stdin);

    // Fjern newline-tegnet fra fgets
    input[strcspn(input, "\n")] = '\0';

    // Søg og erstat strenger
    printf("Indtast strengen, du vil søge efter: ");
    scanf("%s", search);
    printf("Indtast erstatningsstrengen: ");
    scanf("%s", replace);

    int inputLen = strlen(input);
    int searchLen = strlen(search);
    int replaceLen = strlen(replace);

    char output[1000];  // Antager den samme maksimale længde for output

    int i = 0;
    int j = 0;
    int k = 0;

    while (i < inputLen) {
        if (strncmp(&input[i], search, searchLen) == 0) {
            strcpy(&output[k], replace);
            k += replaceLen;
            i += searchLen;
        } else
            output[k++] = input[i++];
    }

    output[k] = '\0';

    // Udskriv den ændrede streng
    printf("Ændret streng: %s\n", output);

    return 0;
}
