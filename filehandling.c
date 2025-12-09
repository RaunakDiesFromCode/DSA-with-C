#include <stdio.h>

int main() {
    FILE *file;
    char filename[100];
    char content[1000];

    printf("Enter the filename: ");
    scanf("%s", filename);

    // Open the file in write mode
    file = fopen(filename, "w");

    if (file == NULL) {
        printf("Unable to open the file.\n");
        return 1;
    }

    printf("Enter the content (max 1000 characters):\n");
    scanf(" %[^\n]", content);

    // Write the content to the file
    fprintf(file, "%s", content);

    // Close the file
    fclose(file);

    // Open the file in read mode
    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Unable to open the file.\n");
        return 1;
    }

    printf("Contents of the file:\n");

    // Read and display the contents of the file
    while (fgets(content, sizeof(content), file) != NULL) {
        printf("%s", content);
    }

    // Close the file
    fclose(file);

    return 0;
}

