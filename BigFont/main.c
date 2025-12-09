#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void printAlphabet(const char letter[])
{
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%c", letter[i * 5 + j] == '1' ? '*' : ' ');
        }
        printf("\n");
    }
    printf("\n");
}

char *substrr(int start, int len, const char *str)
{
    char *result = (char *)malloc((len + 1) * sizeof(char));
    strncpy(result, str + start, len);
    result[len] = '\0';
    return result;
}

int main()
{
    const char *alphabet[26] = {
        "01110100011000111111100011000110001", // A
        "11110100011000111110100011000111110", // B
        "01111100011000010000100001000001111", // C
        "11110100011000110001100011000111110", // D
        "11111100001000011110100001000011111", // E
        "11111100001000011110100001000010000", // F
        "01111100011000010111100011000101111", // G
        "10001100011000111111100011000110001", // H
        "01110001000010000100001000010001110", // I
        "00001000010000100001000011000101110", // J
        "10001100011001011100100101000110001", // K
        "10000100001000010000100001000011111", // L
        "10001110111010110001100011000110001", // M
        "10001110011010110011100011000110001", // N
        "01110100011000110001100011000101110", // O
        "11110100011000111110100001000010000", // P
        "01110100011000110001101011001001101", // Q
        "11110100011000111110101001001010001", // R
        "01111100001000001110000010000111110", // S
        "11111001000010000100001000010000100", // T
        "10001100011000110001100011000101110", // U
        "10001100011000110001100010101000100", // V
        "10001100011000110101101011101110001", // W
        "10001100010101000100010101000110001", // X
        "10001100010101000100001000010000100", // Y
        "11111000010001000100010001000011111"  // Z
    };

    printf("Enter a word: ");
    char word[100];
    // scanf("%s", word);
    scanf("%s", word);

    int arr[100];
    for (int i = 0; i < 100; i++)
    {
        arr[i] = 999;
    }

    for (int i = 0; i < strlen(word); i++)
    {
        // printAlphabet(alphabet[toupper(word[i]) - 'A']);    // print the letter in vertical format
        arr[i] = toupper(word[i]) - 'A';
    }

    int f = 0;

    for (int i = 0; (i < 7) ; i++)
    {
        for (int j = 0; j < strlen(word); j++)
        {
            char *lttrline = substrr(f, 5, alphabet[arr[j]]);
            for (int k = 0; k < 5; k++)
            {
                printf("%c", lttrline[k] == '1' ? '*' : ' ');
            }
            printf("   ");
            free(lttrline);
        }
        f += 5;
        printf("\n");
    }
    printf("\n");

    return 0;
}
