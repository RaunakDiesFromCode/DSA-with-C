#include <stdio.h>

struct creds
{
    char Fname[50];
    char Lname[50];
    long phno;
    char uid[10];
};

int main()
{
    struct creds c1;
    printf("Enter your first name: ");
    scanf("%s", c1.Fname);
    printf("Enter your last name: ");
    scanf("%s", c1.Lname);
    printf("Enter your phone number: ");
    scanf("%ld", &c1.phno);
    printf("Enter your user id: ");
    scanf("%s", c1.uid);

    printf("\n\nYour details are as follows:\n");
    printf("First name: %s\n", c1.Fname);
    printf("Last name: %s\n", c1.Lname);
    printf("Phone number: %ld\n", c1.phno);
    printf("User id: %s\n", c1.uid);

    return 0;
}