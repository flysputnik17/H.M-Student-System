#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"Course.h"


Course* Add_course(int id, char* name, Course* head)
{
    printf("Add new course\n");
    
    // Check if the ID already exists
    Course* current = head;
    while (current != NULL)
    {
        if (current->id == id)
        {
            printf("This course already exists with the same ID\n");
            return head;  // Return the head of the list without adding a new course
        }
        current = current->next;
    }
    
    // Check if the name already exists
    current = head;
    while (current != NULL)
    {
        if (strcmp(current->name, name) == 0)
        {
            printf("This course already exists with the same name\n");
            return head;  // Return the head of the list without adding a new course
        }
        current = current->next;
    }
    
    Course* new_course = malloc(sizeof(Course));
    if (new_course == NULL)
    {
        printf("ERROR allocating memory\n");
        return head;
    }
    
    new_course->id = id;
    new_course->name = malloc(strlen(name) + 1);  // Allocate memory for the name
    strcpy(new_course->name, name);
    new_course->next = head;  // Add the new course to the beginning of the list
    
    printf("New course added\n");
    return new_course;  // Return the new head of the list
}




Course* Delete_course(int id, char* name, Course* head)
{
    printf("Deleting a course\n");

    Course* current = head;
    Course* prev = NULL;

    // Traverse the linked list to find the course
    while (current != NULL)
    {
        // Check if the course matches the ID and name
        if (current->id == id && strcmp(current->name, name) == 0)
        {
            // Found a match, remove the course from the linked list

            // If the course is the head, update the head
            if (prev == NULL)
            {
                head = current->next;
            }
            else
            {
                prev->next = current->next;
            }

            // Free the memory for the course
            free(current->name);
            free(current);

            printf("Course deleted\n");
            return head;  // Return the new head of the list
        }

        // Move to the next course
        prev = current;
        current = current->next;
    }

    // Course not found
    printf("Course not found\n");
    return head;  // Return the same head of the list
}

void Edit_course(int id, Course* head)
{
    printf("Editing a course\n");

    Course* current = head;
    while (current != NULL)
    {
        if (current->id == id)
        {
            // Course found, ask for the information to be edited

            printf("Choose the information to edit:\n");
            printf("1. Course ID\n");
            printf("2. Course Name\n");

            int choice;
            scanf("%d", &choice);
            getchar();  // Consume the newline character

            switch (choice)
            {
                case 1:
                {
                    printf("Enter the new course ID: ");
                    int new_id;
                    scanf("%d", &new_id);
                    getchar();  // Consume the newline character

                    current->id = new_id;
                    printf("Course ID updated\n");
                    break;
                }
                case 2:
                {
                    printf("Enter the new course name: ");
                    char buffer[100];
                    fgets(buffer, sizeof(buffer), stdin);

                    // Reallocate memory for the name
                    char* new_name = malloc(strlen(buffer) + 1);
                    if (new_name == NULL)
                    {
                        printf("ERROR allocating memory\n");
                        return;
                    }
                    strcpy(new_name, buffer);

                    // Free the previous name and assign the new name
                    free(current->name);
                    current->name = new_name;

                    printf("Course name updated\n");
                    break;
                }
                default:
                {
                    printf("Invalid choice\n");
                    return;
                }
            }

            return;
        }

        current = current->next;
    }

    // Course not found
    printf("Course not found\n");
}


void Print_courses(Course* head)
{
    printf("Existing courses:\n");

    Course* current = head;
    while (current != NULL)
    {
        printf("Course ID: %d, Course Name: %s\n", current->id, current->name);
        current = current->next;
    }
}
