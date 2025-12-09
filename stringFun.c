#include <stdio.h>

int stringLength(char *str)
{
    int length = 0;
    while (*str != '\0')
    {
        length++;
        str++;
    }
    return length;
}

int stringCompare(char *str1, char *str2)
{
    while (*str1 == *str2)
    {
        if (*str1 == '\0')
            return 0;
        str1++;
        str2++;
    }
    return *str1 - *str2;
}

void stringCopy(char *src, char *dest)
{
    while (*src != '\0')
    {
        *dest = *src;
        src++;
        dest++;
    }
    *dest = '\0';
}

void stringConcatenate(char *str1, char *str2)
{
    while (*str1 != '\0')
    {
        str1++;
    }
    while (*str2 != '\0')
    {
        *str1 = *str2;
        str1++;
        str2++;
    }
    *str1 = '\0';
}

int main()
{
    char str[] = "Hello";
    int length = stringLength(str);
    printf("Length of the string: %d\n", length);

    char str1[] = "Hello";
    char str2[] = "World";
    int result = stringCompare(str1, str2);
    if (result == 0)
        printf("Strings are equal\n");
    else if (result < 0)
        printf("String 1 is smaller than String 2\n");
    else
        printf("String 1 is larger than String 2\n");

    char src[] = "Hello";
    char dest[10];
    stringCopy(src, dest);
    printf("Copied string: %s\n", dest);

    stringConcatenate(str1, str2);
    printf("Concatenated string: %s\n", str1);

    return 0;
}