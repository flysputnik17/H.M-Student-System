#include<stdio.h>
#include <string.h>
#include<stdlib.h>
#include"University.h"



int main()
{
    loop:
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

    while (user_menu_input != 10)
    {
        switch (user_menu_input)
        {
        case 1:
        Student* Add_student(int id, char* name, int num_courses, CourseGrade* grades, Course* course_name, Student* head);
        goto loop;
        break;

        case 2:
        Student* remove_student(int id, Student* head);
        goto loop;
        break;

        case 3:
        Student* edit_student(int id, Student* head);
        goto loop;
        break;

        case 4:
        void Print_students(University* university);
        goto loop;
        break;

        case 5:
        Course* Add_course(int id, char* name, Course* head);
        goto loop;
        break;

        case 6:
        Course* Delete_course(int id, char* name, Course* head);
        goto loop;
        break;

        case 7:
        void Edit_course(int id, Course* head);
        goto loop;
        break;

        case 8:
        void Print_courses(Course* head);
        goto loop;
        break;

        case 9:
        void Calculate_average_score(University* university);
        goto loop;
        break;

        }
    }

    void Exit_system();
    
    
    return 0;

}






