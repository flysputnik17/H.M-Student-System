#include<stdio.h>
#include <string.h>
#include<stdlib.h>
#include"Student.h"
#include"CourseGrade.h"

typedef struct {
    int id;
    char *name;
    struct Course* next;
} Course;








int main()
{
    printf("Welcome to the University Management System!\nPlease select an option: ");
    printf("1. Add a student\n");
    printf("2. Remove a student\n");
    printf("3. Edit a student\n");
    printf("4. Display all students\n");
    printf("5. Add a course\n");
    printf("6. Remove a course\n");
    printf("7. Edit a course\n");
    printf("8. Display all courses\n");
    printf("9. Calculate a student's average grade\n");
    printf("10. Quit\n");
    int user_menu_input = 0;
    scanf("%d",&user_menu_input);
    return 0;

}