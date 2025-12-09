// frequancy of character in a string without using library function
#include <stdio.h>
#include <string.h>
int main()
{
    char str[100];
    int i, j, freq;
    printf("Enter a string: ");
    scanf("%s", &str);
    for (i = 0; i < strlen(str); i++)
    {
        freq = 1;
        for (j = i + 1; j < strlen(str); j++)
        {
            if (str[i] == str[j])
            {
                freq++;
                // Set str[j] to 0 to avoid printing visited character
                str[j] = '0';
            }
        }
        // If frequency of character str[i] is not 0
        if (str[i] != '0')
        {
            printf("%c occurs %d times\n", str[i], freq);
        }
    }
    return 0;
}