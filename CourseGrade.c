#include<stdio.h>
#include <string.h>
#include<stdlib.h>
#include"Course.h"
#include"University.h"



void Calculate_average_score(University* university)
{
    printf("Enter student ID to calculate average score: ");
    int student_id;
    scanf("%d", &student_id);

    // Find the student with the given ID
    Student* current_student = university->students;
    while (current_student != NULL)
    {
        if (current_student->id == student_id)
        {
            // Calculate the average score
            CourseGrade* current_grade = current_student->grades;
            float total_score = 0;
            int num_grades = 0;

            while (current_grade != NULL)
            {
                total_score += current_grade->grade;
                num_grades++;
                current_grade = current_grade->next;
            }

            if (num_grades > 0)
            {
                float average_score = total_score / num_grades;
                printf("Average score for student ID %d: %.2f\n", student_id, average_score);
            }
            else
            {
                printf("No grades available for student ID %d\n", student_id);
            }

            return;
        }

        current_student = current_student->next;
    }

    printf("Student with ID %d not found\n", student_id);
}
