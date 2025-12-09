#include <stdio.h>

// Define the Student structure
struct Student
{
    char name[50];
    int roll;
    float marks;
};

int main()
{
    // Create an array of 3 Student structures
    struct Student students[3];
    // Assign values to the students
    for (int i = 0; i < 3; i++)
    {
        printf("Enter information of student %d:\n", i + 1);
        printf("Enter name: ");
        scanf("%s", students[i].name);
        printf("Enter roll number: ");
        scanf("%d", &students[i].roll);
        printf("Enter marks: ");
        scanf("%f", &students[i].marks);
    }
    // Print student information
    printf("Displaying Information:\n");
    for (int i = 0; i < 3; i++)
    {
        printf("Name: %s\n", students[i].name);
        printf("Roll: %d\n", students[i].roll);
        printf("Marks: %.1f\n", students[i].marks);
    }

    // Use pointers to access student information
    struct Student *ptr = students;
    printf("Displaying Information using Pointers:\n");
    for (int i = 0; i < 3; i++)
    {
        printf("Name: %s\n", (ptr + i)->name);
        printf("Roll: %d\n", (ptr + i)->roll);
        printf("Marks: %.1f\n", (ptr + i)->marks);
    }

    return 0;
}

