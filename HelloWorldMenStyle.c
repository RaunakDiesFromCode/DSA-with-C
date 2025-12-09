#include <stdio.h>
#include <string.h>
#include <unistd.h>

void res(char text[])
{
    char strr[12] = "";
    int i = 0;
    while (i < strlen(text))
    {
        if (text[i] >= 'A' && text[i] <= 'Z')
        {
            char a = 'A';
            while (a < text[i])
            {
                printf("%s%c\n", strr, a);
                a++;
                usleep(100000);
            }
            if (a == text[i])
            {
                strr[strlen(strr)] = a;
                printf("%s\n", strr);
            }
            i++;
        }
        else if (text[i] == ' ')
        {
            char a = ' ';
            while (a < text[i])
            {
                printf("%s%c\n", strr, a);
                a++;
                usleep(100000);
            }
            if (a == text[i])
            {
                strr[strlen(strr)] = a;
                printf("%s\n", strr);
            }
            i++;
        }
        else
        {
            char a = 'a';
            while (a < text[i])
            {
                printf("%s%c\n", strr, a);
                a++;
                usleep(100000);
            }
            if (a == text[i])
            {
                strr[strlen(strr)] = a;
                printf("%s\n", strr);
            }
            i++;
        }
    }
}

int main()
{
    res("Hello World");
    return 0;
}
