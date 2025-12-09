#include <stdio.h>
#include <string.h>
int countVowels(const char* str) {
    int count = 0;
    int length = strlen(str);
    
    for (int i = 0; i < length; i++) {
        // char c = tolower(str[i]);
        
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
            count++;
        }
    }
    
    return count;
}
int main() {
    const char* str = "Hello, World!";
    int vowelCount = countVowels(str);
    
    printf("Number of vowels: %d\n", vowelCount);
    
    return 0;
}