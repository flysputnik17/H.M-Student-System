#ifndef UNIVERSITY_H
#define UNIVERSITY_H
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"Course.h"


typedef struct {
    char *name;
    int num_courses;
    Course *courses;
    Student *students;
}University;

typedef struct {
    int course_id;
    struct Course* currentCourse;
    float grade;
    struct CourseGrade* next;
}CourseGrade;

typedef struct {
    int id;
    char *name;
    int num_courses;
    CourseGrade *grades;
    struct Student* next;
}Student;

Student* Add_student(int id, char* name, int num_courses, CourseGrade* grades, Course* course_name, Student* head);
Student* remove_student(int id, Student* head);
Student* edit_student(int id, Student* head);
void Print_students(University* university);
void Calculate_average_score(University* university);
void Exit_system();

#endif