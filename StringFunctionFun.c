#include <stdio.h>
#include <string.h>

int main() {
    char str1[100] = "Hello, world!";
    char str2[100];
    char str3[100] = " Copilot";
    char str4[100] = "Hello, world!";
    
    // Find the length of a string
    int length = strlen(str1);
    printf("Length of str1: %d\n", length);
    
    // Copy a string
    strcpy(str2, str1);
    printf("Copied string: %s\n", str2);
    
    // Concatenate two strings
    strcat(str1, str3);
    printf("Concatenated string: %s\n", str1);
    
    // Compare two strings
    int result = strcmp(str1, str4);
    if (result == 0) {
        printf("Strings are equal\n");
    } else {
        printf("Strings are not equal\n");
    }
}