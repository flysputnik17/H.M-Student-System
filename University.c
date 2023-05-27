#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"University.h"
#include"Course.h"





Student* Add_student(int id, char* name, int num_courses, CourseGrade* grades, Course* course_name, Student* head)
{
    printf("Enter Student name: ");
    char buffer[100];
    fgets(buffer, sizeof(buffer), stdin);

    Student* student = malloc(sizeof(Student));
    if (student == NULL)
    {
        printf("ERROR allocating memory failed\n");
        return head;
    }
    
    student->name = malloc(strlen(buffer) + 1);
    if (student->name == NULL)
    {
        printf("ERROR allocating memory failed\n");
        free(student);
        return head;
    }
    strcpy(student->name, buffer);

    printf("Enter the ID of the Student: ");
    scanf("%d", &(student->id));
    getchar();  // Consume the newline character

    printf("Enter number of Courses he has: ");
    scanf("%d", &(student->num_courses));
    getchar();  // Consume the newline character

    if (student->num_courses > 10)
    {
        printf("ERROR max number of courses is 10! Input correct number of courses\n");
        free(student->name);
        free(student);
        return head;
    }

    student->grades = malloc(sizeof(CourseGrade) * student->num_courses);
    if (student->grades == NULL)
    {
        printf("ERROR allocating memory failed\n");
        free(student->name);
        free(student);
        return head;
    }

    printf("Enter the grade for each course:\n");
    for (int i = 0; i < student->num_courses; i++)
    {
        printf("Enter the grade for Course %d: ", i + 1);
        scanf("%f", &(student->grades[i].grade));
        getchar();  // Consume the newline character

        // Set the corresponding course for the grade
        Course* current_course = course_name;
        while (current_course != NULL)
        {
            if (current_course->id == grades[i].course_id)
            {
                student->grades[i].currentCourse = current_course;
                break;
            }
            current_course = current_course->next;
        }
    }

    student->next = head;  // Add the new student to the beginning of the list

    printf("New student added\n");
    return student;  // Return the new head of the list
}

Student* remove_student(int id, Student* head)
{
    printf("Enter student ID to remove: ");
    int input_id = 0;
    scanf("%d", &input_id);
    getchar();  // Consume the newline character

    Student* current = head;
    Student* prev = NULL;

    // Traverse the linked list to find the student
    while (current != NULL)
    {
        if (current->id == input_id)
        {
            // Student found, remove the student from the linked list

            // If the student is the head, update the head
            if (prev == NULL)
            {
                head = current->next;
            }
            else
            {
                prev->next = current->next;
            }

            // Free the memory for the student
            free(current->grades);
            free(current->name);
            free(current);

            printf("Student with ID %d has been deleted\n", input_id);
            return head;  // Return the new head of the list
        }

        // Move to the next student
        prev = current;
        current = current->next;
    }

    // Student not found
    printf("No student found with ID %d\n", input_id);
    return head;  // Return the same head of the list
}



Student* edit_student(int id, Student* head)
{
    printf("Enter student ID to edit: ");
    int student_id = 0;
    scanf("%d", &student_id);
    getchar();  // Consume the newline character

    Student* current = head;

    // Traverse the linked list to find the student
    while (current != NULL)
    {
        if (current->id == student_id)
        {
            printf("You may edit the following info:\n");
            printf("1. Student name\n");
            printf("2. Number of courses\n");
            printf("3. Course grades\n");
            printf("Enter 9 to exit\n");

            int choice;
            printf("Enter the number of the info you want to edit: ");
            scanf("%d", &choice);
            getchar();  // Consume the newline character

            switch (choice)
            {
                case 1:
                {
                    printf("Enter new student name: ");
                    char buffer[100];
                    fgets(buffer, sizeof(buffer), stdin);

                    // Reallocate memory for the name
                    char* new_name = malloc(strlen(buffer) + 1);
                    if (new_name == NULL)
                    {
                        printf("ERROR allocating memory\n");
                        return head;
                    }
                    strcpy(new_name, buffer);

                    // Free the previous name and assign the new name
                    free(current->name);
                    current->name = new_name;

                    printf("Student name updated\n");
                    break;
                }
                case 2:
                {
                    printf("Enter new number of courses: ");
                    int new_num_courses;
                    scanf("%d", &new_num_courses);
                    getchar();  // Consume the newline character

                    current->num_courses = new_num_courses;

                    printf("Number of courses updated\n");
                    break;
                }
                case 3:
                {
                    // Handle editing of course grades
                    // You can implement the necessary logic here
                    printf("Editing course grades not implemented\n");
                    break;
                }
                case 9:
                {
                    printf("Exiting student editing\n");
                    return head;  // Return the same head of the list
                }
                default:
                {
                    printf("Invalid choice\n");
                    break;
                }
            }

            return head;  // Return the same head of the list
        }

        current = current->next;
    }

    // Student not found
    printf("No student found with ID %d\n", student_id);
    return head;  // Return the same head of the list
}

void Print_students(University* university)
{
    printf("List of students:\n");

    Student* current_student = university->students;
    while (current_student != NULL)
    {
        printf("Student ID: %d\n", current_student->id);
        printf("Student Name: %s\n", current_student->name);

        // Print grades for each course
        printf("Grades:\n");
        CourseGrade* current_grade = current_student->grades;
        while (current_grade != NULL)
        {
            printf("Course ID: %d, Grade: %.2f\n", current_grade->course_id, current_grade->grade);
            current_grade = current_grade->next;
        }

        printf("\n");
        current_student = current_student->next;
    }
}

void Exit_system()
{
    printf("Exiting the system...\n");
    exit(0);
}




